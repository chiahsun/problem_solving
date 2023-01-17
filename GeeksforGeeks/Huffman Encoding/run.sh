#!/usr/bin/env bash
for dataName in data1 data2 data3 data4; do
    python3 solve1.py < $dataName.in > tmp.log && diff tmp.log $dataName.out
done
