#!/bin/bash

for c in 1024 2048 4096 8192 16384 32768 65536 131072 262144 524288 1048576 2097152 4194304;
do
	valgrind --tool=cachegrind \
		--I1=$c,4,128 \
		--D1=$c,4,128 \
		--LL=$c,4,128 \
		./a.out 10000 100 10000 2> results/$c.txt
	
	echo $c finalizada
done

rm cachegrind.out.*
