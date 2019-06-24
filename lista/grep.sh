#!/bin/bash

for c in 1024 2048 4096 8192 16384 32768 65536 131072 262144 524288 1048576 2097152;
do
	cat results/$c.txt | grep "I   refs:" >> I1_misses.txt
	cat results/$c.txt | grep "D   refs:" >> D1_misses.txt
	cat results/$c.txt | grep "LL refs:" >> LL_misses.txt
done

for c in 1024 2048 4096 8192 16384 32768 65536 131072 262144 524288 1048576 2097152;
do
	cat results/$c.txt | grep "I1  misses:" >> I1_misses.txt
	cat results/$c.txt | grep "D1  misses:" >> D1_misses.txt
	cat results/$c.txt | grep "LL misses:" >> LL_misses.txt	
done
