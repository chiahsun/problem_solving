python3.5 generate.py &> LOG
./solve1.out < LOG &> LOG1
./solve_golden1.out < LOG &> LOG2
vimdiff LOG1 LOG2
