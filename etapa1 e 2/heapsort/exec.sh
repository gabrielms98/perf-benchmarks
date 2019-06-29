# read entry
# sudo perf stat -e L1-dcache-load-misses,l2_rqsts.code_rd_miss,branches,branch-misses,task-clock,cycles,instructions ./a.out tam
    # task-clock,cycles,instructions,cache-references,cache-misses,branches ./a.out

echo 0 > /proc/sys/kernel/nmi_watchdog

for i in $(seq 20000 10000 500000) ; do
  sudo perf stat -e L1-dcache-load-misses,l2_rqsts.miss,LLC-load-misses,branches,branch-misses,task-clock,cycles,instructions ./a.out $i 2> results/$i.txt
done

echo 1 > /proc/sys/kernel/nmi_watchdog

for i in $(seq 20000 10000 500000) ; do
  chmod 777 results/$i.txt
done
