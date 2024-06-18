#!/bin/bash


make clean && make

./main.bin<<EOF > testoutput/soldStocks.txt


2 AMZN 3
4
3 AMZN 184.3 3
0
4
9
EOF