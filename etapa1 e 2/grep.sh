#!/bin/bash

for prog in bubblesort fibonacci heapsort matrix quicksort;
do
	for c in 1024 2048 4096 8192 16384 32768 65536 131072 262144 524288 1048576 2097152;
	do
	    for j in 1 2 4 8 16;
	    do
			cat $prog/valgrind/$c-$j.txt | grep "I   refs:" >> $prog-misses.txt
		done
	done

	for c in 1024 2048 4096 8192 16384 32768 65536 131072 262144 524288 1048576 2097152;
	do
	    for j in 1 2 4 8 16;
	    do
			cat $prog/valgrind/$c-$j.txt | grep "I1  misses:" >> $prog-refs.txt	
	    done
	done
done
