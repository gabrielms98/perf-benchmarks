#!/bin/bash

declare -A entrada=(
    ["bubblesort"]=100
    ["fibonacci"]=15
    ["heapsort"]=1000
    ["matrix"]=1000
    ["quicksort"]=20
)

for prog in bubblesort fibonacci heapsort matrix quicksort;
do
	for c in 1024 2048 4096 8192 16384 32768 65536 131072 262144 524288 1048576 2097152;
	do
	    for b in 1 2 4 8 16;
	    do
			cat $prog/valgrind/$c-$b.txt | grep "I   refs:" >> $prog-misses.txt
            valgrind --tool=cachegrind --I1=$c,$b,128 ./$prog/$prog ${entrada[$prog]} 2> $prog/valgrind/$c-$b.txt
		done
	done

    echo "$prog finished..."
done

rm cachegrind.out.*