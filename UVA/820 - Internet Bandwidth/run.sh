#!/bin/bash
for i in {1..100}
do
    echo "run $i ..."
    python3.5 generate.py &> LOG
    ./solve1.out < LOG &> LOG1
    ./solve_golden1.out < LOG &> LOG2
    diff LOG1 LOG2
done
