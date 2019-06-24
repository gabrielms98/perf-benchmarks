#!/bin/bash

for c in 1024 2048 4096 8192 16384 32768 65536 131072 262144 524288 1048576 2097152;
do
	cat results/$c.txt | grep "I1  miss rate:" >> I1_misses.txt
	cat results/$c.txt | grep "D1  miss rate:" >> D1_misses.txt
	cat results/$c.txt | grep "LL miss rate:" >> LL_misses.txt
	
done
