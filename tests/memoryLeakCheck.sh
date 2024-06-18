#!/bin/bash


make clean && make

valgrind --leak-check=full ./main.bin<<EOF

1
2 AMZN 3
4
3 AMZN 184.3 3
0
9
EOF