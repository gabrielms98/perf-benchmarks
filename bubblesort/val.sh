#!/bin/bash

for i in 1024 2048 4096 8192 16384 32768 65536 131072 262144 524288 1048576 2097152;
do
    for j in 1 2 4 8 16;
    do
        valgrind --tool=cachegrind --D1=$i,$j,128 --I1=$i,$j,128 ./a.out 1000 2> valgrind/$i-$j.txt
    done
done
