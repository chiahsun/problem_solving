#!/usr/bin/env python3.5
import sys;
import os;
import subprocess;
import timeit;

all_files = [f for f in os.listdir('.')];
data_files = list(filter(lambda f: f.startswith('data') and f.endswith('.in'), all_files));


def run_executables_with_suffix(suffix='.out'):
    exe_files = list(filter(lambda f: f.startswith('solve') and f.endswith(suffix), all_files));
    for exe in exe_files:
        run_executable(exe)

def run_executable(exe = ''):
    print('[RUN]', exe); 
    for data in data_files:
        run_executable_for_data(exe, data, False);

def run_executable_for_data(exe, data, print_run=True):
    if print_run:
        print('[RUN]', exe); 
    
    exe_suffix = os.path.splitext(exe)[1];
    prev_args = '';
    if exe_suffix == '.py':
        prev_args = '/usr/bin/env python';
    args = ''.join([prev_args, ' ./', exe]);

    data_name = os.path.splitext(data);
    args = ''.join([args, ' < ', data, ' &> LOG', ]);
    start = timeit.default_timer();
    subprocess.call(args, shell=True);
    print('    Run', data,  '( Elapsed time : ', timeit.default_timer() - start, ')', end='');
    args = ''.join(['diff LOG ', data_name[0] , '.out']);
    print(''.join([' Check ', data_name[0], '.out', ' ...']));
    subprocess.call(args, shell=True);

def main():
    if len(sys.argv) == 2:
        print(sys.argv);
        run_executable(sys.argv[1]);
    elif len(sys.argv) == 3:
        run_executable_for_data(sys.argv[1], sys.argv[2]);
    else:
        run_executables_with_suffix();
        run_executables_with_suffix('.py');

main();
