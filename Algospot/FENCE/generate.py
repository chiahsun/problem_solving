import random, timeit, subprocess, sys;

random.seed(0);

def generate_case(n_fence_max = 20000, fence_height=10000):
    n_fence = random.randint(1, n_fence_max);
    print(n_fence);
    for _ in range(n_fence):
        print(random.randint(0, fence_height), end=' ', sep='');
    print();

def call_generate_case(n_case=1):
    print(n_case);
    for _ in range(n_case):
   #    generate_case(5, 10);
   #     generate_case(100, 1000);
   #     generate_case(1000, 10000);
        generate_case();

# Reference
#   http://stackoverflow.com/questions/8220801/how-to-use-timeit-module
#   http://stackoverflow.com/questions/89228/calling-an-external-command-in-python
#   http://stackoverflow.com/questions/4675728/redirect-stdout-to-a-file-in-python

def run_shell_cmd(cmd):
    subprocess.call(cmd.split());

sys.stdout = open('LOG', 'w');
call_generate_case(50);
sys.stdout = sys.__stdout__;

def run_executable(exe_name, infile_name, outfile_name):
    with open(infile_name, 'r') as infile:
        with open(outfile_name, 'w') as outfile:
            subprocess.call(exe_name, stdin=infile, stdout=outfile);

print("[Run 1]: ", timeit.timeit('run_executable("./solve1.out", "LOG", "LOG1")', number=1, setup="from __main__ import run_executable"));
print("[Run 2]: ", timeit.timeit('run_executable("./solve_golden1.out", "LOG", "LOG2")', number=1, setup="from __main__ import run_executable"));
run_shell_cmd("vimdiff LOG1 LOG2");

