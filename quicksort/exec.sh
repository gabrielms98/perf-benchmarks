# read entry
# sudo perf stat -e L1-dcache-load-misses,l2_rqsts.code_rd_miss,branches,branch-misses,task-clock,cycles,instructions ./a.out tam
    # task-clock,cycles,instructions,cache-references,cache-misses,branches ./a.out

echo 0 > /proc/sys/kernel/nmi_watchdog

for i in $(seq 1000000 100000 5000000) ; do
  sudo perf stat -e L1-dcache-load-misses,l2_rqsts.code_rd_miss,LLC-load-misses,branches,branch-misses,task-clock,cycles,instructions ./a.out $i 2> results/$i.txt
done

echo 1 > /proc/sys/kernel/nmi_watchdog

for i in $(seq 1000000 100000 5000000) ; do
  chmod 777 results/$i.txt
done
