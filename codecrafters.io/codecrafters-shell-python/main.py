import sys, os, subprocess, contextlib
import tty, termios
from dataclasses import dataclass

SPECIAL_QUOTES = ['"', "'"]

def process_buf(buf):
    res, i = [], 0
    while i < len(buf):
        c = buf[i]
        if c == ' ':
            if res and res[-1] != ' ':
                res.append(' ')
            i += 1
        elif c == '\\':
            if i+1 < len(buf):
                res.append(buf[i+1])
                i += 2
            else:
                i += 1
        else:
            res.append(c)
            i += 1
    return "".join(res)


def echo_command_func(args):
    line, res = "", []
    if args:
        begin_quote, buf, i = None, [], 0
        while i < len(args[0]):
            c = args[0][i]
            if begin_quote:
                if c == begin_quote:
                    res.append("".join(buf))
                    buf = []
                    begin_quote = None
                else:
                    if begin_quote == '"':
                        if c == '\\' and i+1 < len(args[0]) and args[0][i+1] in ['"', "\\", "$"]:
                            buf.append(args[0][i+1])
                            i += 1
                        else:
                            buf.append(c)
                    else:
                        buf.append(c)
            elif c in SPECIAL_QUOTES:
                if buf:
                    previous = process_buf(buf)
                    if previous:
                        res.extend(previous)
                    elif buf:
                        res.append(" ")
                    buf = []

                begin_quote = c
            else:
                if c == "\\":
                    if i+1 < len(args[0]):
                        if buf:
                            res.extend(process_buf(buf))
                            buf = []
                        res.append(args[0][i+1])
                        i += 1
                else:
                    buf.append(c)
            i += 1
        if buf:
            res.extend(process_buf(buf))
            buf = []
    res.append("\n")
    sys.stdout.write("".join(res))

def parse_left_args_separated(left_str, drop_quote=True):
    if not left_str:
        return []
    res = []
    begin_quote, buf = None, []
    for i in range(len(left_str)):
        c = left_str[i]
        # if c in SPECIAL_QUOTES:
        if begin_quote:
            if c == begin_quote:
                cur = []
                if not drop_quote:
                    cur.append(begin_quote)
                cur.append("".join(buf))
                if not drop_quote:
                    cur.append(begin_quote)
                res.append("".join(cur))
                buf = []
                begin_quote = None
            else:
                buf.append(c)
        elif c in SPECIAL_QUOTES:
            if buf:
                res.extend("".join(buf).split())
                buf = []
            begin_quote = c
        else:
            buf.append(c)
    if buf:
        res.extend("".join(buf).split())
    return res

class Command:
    def __init__(self, name, func, left_args_parser=parse_left_args_separated):
        self.name = name
        self.func = func
        self.parse_left_args = left_args_parser

def get_path_for_type_command(command):
    if "/" in command:
        norm_command = os.path.normpath(command)
        if os.path.isfile(norm_command) and os.access(norm_command, os.X_OK):
            return norm_command
        return ""

    path = os.environ['PATH']
    for curpath in map(str.strip, path.split(':')):
        if os.path.isdir(curpath) and os.path.exists(curpath):
            for f in os.listdir(curpath):
                file_path = os.path.join(curpath, f)
                if os.path.isfile(file_path) and os.access(file_path, os.X_OK) and f == command:
                    return file_path
    return ""


def type_command_func(args):
    if not args:
        sys.stdout.write("\n")
    else:
        ok, command = False, args[0]
        for built_in_command in built_in_commands:
            if built_in_command.name == command:
                print(f"{command} is a shell builtin")
                ok = True
                break
        if not ok:
            if path_for_command := get_path_for_type_command(command):
                print(f"{command} is {path_for_command}")
                ok = True

        if not ok:
            print(f"{command}: not found")

def get_wd():
    return os.path.abspath(os.getcwd())


class CurrentWorkingDirectory:
    def __init__(self):
        self.wd = get_wd()
        self.home_path = os.environ['HOME']

    def cd(self, args):
        if args:
            next_wd = args[0]
            if next_wd == '~':
                next_wd = self.home_path
            elif not next_wd.startswith('/'):
                # https://docs.python.org/3.14/library/os.path.html#os.path.normpath
                next_wd = os.path.normpath(os.path.join(self.wd, next_wd))

            if os.path.isdir(next_wd) and os.path.exists(next_wd):
                self.wd = next_wd
            else:
                print(f"cd: {next_wd}: No such file or directory")
        else:
            self.wd = self.home_path

current_working_directory = CurrentWorkingDirectory()

built_in_commands = [
    Command("exit", lambda _: sys.exit(0)),
    Command("echo", lambda left_args: echo_command_func(left_args), left_args_parser=lambda left_str: [left_str]),
    Command("type", type_command_func),
    Command("pwd", lambda _: print(current_working_directory.wd)),
    Command("cd", lambda left_args: current_working_directory.cd(left_args)),
]

def parse_command(input_line):
    res, buf, begin_quote = [], [], None
    for i in range(len(input_line)):
        c = input_line[i]
        if begin_quote:
            if c == begin_quote:
                return "".join(buf), input_line[i+1:]
            else:
                buf.append(c)
        elif c in SPECIAL_QUOTES:
            stripped = "".join(buf).strip()
            if stripped:
                return stripped, input_line[i:]
            begin_quote = c
        else:
            if c == " ":
                stripped = "".join(buf).strip()
                if stripped:
                    return stripped, input_line[i+1:]
            else:
                buf.append(c)
    return "".join(buf).strip(), ""

REDIRECT_STDOUT = [" > ", " 1> ", " 1>> ", " >> "]
REDIRECT_STDERR = [" 2> ", " 2>> "]
REDIRECT_ALL = REDIRECT_STDOUT + REDIRECT_STDERR

# https://docs.python.org/3/library/dataclasses.html
@dataclass
class RedirectItem:
    filename: str
    append: bool

    @property
    def redirect(self):
        return self.filename != ""

def parse_redirect(input_line):
    command_part, stdout_part, stderr_part = input_line, "", ""
    stdout_append, stderr_append = False, False
    found = True
    while found:
        found = False
        for sep in REDIRECT_ALL:
            # https://peps.python.org/pep-0572/
            if (pos := command_part.rfind(sep)) != -1:
                found = True
                if sep in REDIRECT_STDOUT:
                    command_part, stdout_part = command_part[:pos].strip(), command_part[(pos + len(sep)):].strip()
                    if ">>" in sep:
                        stdout_append = True
                else:
                    command_part, stderr_part = command_part[:pos].strip(), command_part[(pos + len(sep)):].strip()
                    if ">>" in sep:
                        stderr_append = True
                break

    return command_part, RedirectItem(stdout_part, stdout_append), RedirectItem(stderr_part, stderr_append)

def execute_command(command_part, stdout_fd=sys.__stdout__, stderr_fd=sys.__stderr__):
    command, left_commands = parse_command(command_part)
    ok = False
    for built_in_command in built_in_commands:
        if built_in_command.name == command:
            parsed_args = built_in_command.parse_left_args(left_commands)
            built_in_command.func(parsed_args)
            ok = True
            break
    if not ok:
        if path_for_command := get_path_for_type_command(command):
            # For cat and others in path
            # https://stackoverflow.com/questions/89228/how-do-i-execute-a-program-or-call-a-system-command
            # https://docs.python.org/3.5/library/subprocess.html#subprocess.run
            subprocess_args = [command]
            subprocess_args.extend(parse_left_args_separated(left_commands, drop_quote=True))
            result = subprocess.run(subprocess_args, stdout=stdout_fd, stderr=stderr_fd)
            ok = True

    if not ok:
        print(f"{command}: command not found")

# https://stackoverflow.com/questions/3774328/implementing-use-of-with-object-as-f-in-custom-class-in-python
# https://docs.python.org/3/library/contextlib.html#contextlib.redirect_stdout
@contextlib.contextmanager
def open_fd(redirect_item, fallback_fd):
    if not redirect_item.redirect:
        yield fallback_fd
        return

    fd = fallback_fd
    try:
        fd = open(redirect_item.filename, "a" if redirect_item.append else "w")
        yield fd
    except:
        sys.stderr.write(f"Fail to open file {redirect_item.filename}, redirect to {fallback_fd}\n")
    finally:
        fd.close()

PROMPT = "\r$ "

EOT = chr(0x04)

def debug_str_repr(s):
    hex_str = ":".join("{:02x}".format(ord(c)) for c in s)
    print(f's is {s} {hex_str} {repr(s)} {len(s)}')


def get_built_in_completion(prefix):
    for command in built_in_commands:
        if command.name.startswith(prefix):
            return command.name
    return ""

def precompute_path_completion_executables():
    res= []
    path = os.environ['PATH']
    for curpath in map(str.strip, path.split(':')):
        if os.path.isdir(curpath) and os.path.exists(curpath):
            for f in os.listdir(curpath):
                file_path = os.path.join(curpath, f)
                if os.path.isfile(file_path) and os.access(file_path, os.X_OK):
                    res.append(f)
    res.sort()
    L = [res[0]] if res else []
    for i in range(1, len(res)):
        if res[i] != L[-1]:
            L.append(res[i])
    return L

PATH_EXECUTABLES = precompute_path_completion_executables()

def get_path_completion_list(prefix):
    executables = []
    for exe in PATH_EXECUTABLES:
        if exe.startswith(prefix):
            executables.append(exe)
    return executables

def is_startswith_previous_for_all(candidates):
    ok = True
    for i in range(1, len(candidates)):
        if not candidates[i].startswith(candidates[i-1]):
            ok = False
            break
    return ok


def beep():
    sys.stdout.write("\a")
    sys.stdout.flush()

def handle_prompt(fd):
    # https://docs.python.org/3/library/tty.html
    tty_attrs = termios.tcgetattr(fd)
    tty.setraw(fd)
    sys.stdout.write(PROMPT)
    sys.stdout.flush()

    input_buffer, last_exe_prefix = [], ""
    while True:
        c = sys.stdin.read(1)
        if c in ["\n", "\r", "\r\n", EOT] or not c:
            sys.stdout.flush()
            break
        elif c in ["\b", "\x7f"]:
            if input_buffer:
                del input_buffer[-1]
                # https://stackoverflow.com/questions/44565704/how-to-clear-only-last-one-line-in-python-output-console
                sys.stdout.write('\r')
                content = "".join(input_buffer)
                sys.stdout.write(" " * (len(PROMPT) + len(content) + 2))
                sys.stdout.write('\r')
                sys.stdout.write(PROMPT)
                sys.stdout.write(content)
                sys.stdout.flush()
        elif c == "\t":
            content = "".join(input_buffer)
            if content:
                if fullname := get_built_in_completion(content):
                    left = fullname[len(content):] + " "
                    sys.stdout.write(left)
                    input_buffer.append(left)
                    sys.stdout.flush()
                elif candidates := get_path_completion_list(content):
                    if candidates:
                        if len(candidates) == 1 or is_startswith_previous_for_all(candidates):
                            fullname = candidates[0]
                            left = fullname[len(content):] + (" " if len(candidates) == 1 else "")
                            sys.stdout.write(left)
                            input_buffer.append(left)
                            sys.stdout.flush()
                        #elif is_startswith_previous_for_all(candidates):
                         #   pass
                        elif not last_exe_prefix:
                            last_exe_prefix = content
                            beep()
                        elif last_exe_prefix == content:
                            sys.stdout.write("\n\r")
                            candidates_content = "  ".join(candidates)
                            sys.stdout.write(candidates_content)
                            sys.stdout.write("\n")
                            sys.stdout.write(PROMPT)
                            sys.stdout.write(content)
                            sys.stdout.flush()
                        else:
                            last_exe_prefix = ""
                else:
                    beep()

        else:
            input_buffer.append(c)
            sys.stdout.write(c)
            sys.stdout.flush()

    sys.stdout.flush()
    termios.tcsetattr(fd, termios.TCSAFLUSH, tty_attrs)

    return "".join(input_buffer)


def main():
    fd = sys.stdin.fileno()
    while input := handle_prompt(fd):

        sys.stdout.write("\n\r")
        sys.stdout.flush()

        command_part, stdout_part, stderr_part = parse_redirect(input)
        # https://stackoverflow.com/questions/7152762/how-to-redirect-print-output-to-a-file
        with open_fd(stdout_part, sys.__stdout__) as stdout_fd, open_fd(stderr_part, sys.__stderr__) as stderr_fd:
            with contextlib.redirect_stdout(stdout_fd), contextlib.redirect_stderr(stderr_fd):
                execute_command(command_part, stdout_fd=stdout_fd, stderr_fd=stderr_fd)


if __name__ == "__main__":
    main()
