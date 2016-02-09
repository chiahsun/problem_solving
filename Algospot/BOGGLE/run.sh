python3.5 generate.py &> data_tmp.in
time ./solve1.out < data_tmp.in &> LOG1
time ./solve_golden1.out < data_tmp.in &> LOG2
vimdiff LOG1 LOG2
