#!/bin/bash

# for i in 1024 2048 4096 8192 16384 32768 65536 131072 262144 524288 1048576 2097152;
# do
#     for j in 1 2 4 8 16;
#     do
#         valgrind --tool=cachegrind --D1=$i,$j,128 --I1=$i,$j,128 ./bubblesort/a.out 100 2> bubblesort/valgrind/$i-$j.txt
#     done
# done

# echo "bubblesort finished...";

# for i in 1024 2048 4096 8192 16384 32768 65536 131072 262144 524288 1048576 2097152;
# do
#     for j in 1 2 4 8 16;
#     do
#         valgrind --tool=cachegrind --D1=$i,$j,128 --I1=$i,$j,128 ./fibonacci/a.out 10 2> fibonacci/valgrind/$i-$j.txt
#     done
# done

# echo "fibonacci finished...";

# for i in 1024 2048 4096 8192 16384 32768 65536 131072 262144 524288 1048576 2097152;
# do
#     for j in 1 2 4 8 16;
#     do
#         valgrind --tool=cachegrind --D1=$i,$j,128 --I1=$i,$j,128 ./heapsort/a.out 1000 2> heapsort/valgrind/$i-$j.txt
#     done
# done

# echo "heapsort finished...";

# for i in 1024 2048 4096 8192 16384 32768 65536 131072 262144 524288 1048576 2097152;
# do
#     for j in 1 2 4 8 16;
#     do
#         valgrind --tool=cachegrind --D1=$i,$j,128 --I1=$i,$j,128 ./matrix/a.out 1000 2> matrix/valgrind/$i-$j.txt
#     done
# done

# echo "matrix finished...";

for i in 1024 2048 4096 8192 16384 32768 65536 131072 262144 524288 1048576 2097152;
do
    for j in 1 2 4 8 16;
    do
        valgrind --tool=cachegrind --D1=$i,$j,128 --I1=$i,$j,128 ./quicksort/a.out 20 2> quicksort/valgrind/$i-$j.txt
    done
done

echo "quicksort finished...";

rm cachegrind.out.*