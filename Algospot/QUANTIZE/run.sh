python3.5 generate.py &> LOG
time ./solve1.out < LOG &> LOG1
time ./solve_golden1.out < LOG &> LOG2
vimdiff LOG1 LOG2
