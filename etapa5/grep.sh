#!/bin/bash

for p in a b c; 
do
	for c in 1024 2048 4096 8192 16384 32768 65536 131072 262144 524288 1048576 2097152 4194304;
	do
		cat results/$p-$c.txt | grep "I   refs:" >> $p-I1_misses.txt
		cat results/$p-$c.txt | grep "D   refs:" >> $p-D1_misses.txt
		cat results/$p-$c.txt | grep "LL refs:" >> $p-LL_misses.txt
	done

	for c in 1024 2048 4096 8192 16384 32768 65536 131072 262144 524288 1048576 2097152 4194304;
	do
		cat results/$p-$c.txt | grep "I1  misses:" >> $p-I1_misses.txt
		cat results/$p-$c.txt | grep "D1  misses:" >> $p-D1_misses.txt
		cat results/$p-$c.txt | grep "LL misses:" >> $p-LL_misses.txt	
	done
done

