#python3.5 generate.py &> LOG
# time ./solve1.out < LOG &> LOG1
../compile.sh solve4.cc
time ./solve2.out < LOG &> LOG1
time ./solve4.out < LOG &> LOG2
vimdiff LOG1 LOG2
