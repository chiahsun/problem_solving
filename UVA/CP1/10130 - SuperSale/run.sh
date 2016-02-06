 python3.5 generate.py &> LOG
./solve2.out < LOG &> LOG1
./solve1.out < LOG &> LOG2
vimdiff LOG1 LOG2
