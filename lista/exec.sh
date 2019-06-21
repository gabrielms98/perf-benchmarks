# read entry
# sudo perf stat -e L1-dcache-load-misses,l2_rqsts.code_rd_miss,branches,branch-misses,task-clock,cycles,instructions ./a.out tam
    # task-clock,cycles,instructions,cache-references,cache-misses,branches ./a.out

echo 0 > /proc/sys/kernel/nmi_watchdog

# for i in {1..45} ; do
#   sudo perf stat -e L1-dcache-load-misses,l2_rqsts.code_rd_miss,LLC-load-misses,branches,branch-misses,task-clock,cycles,instructions ./a.out $i 2> $i.txt
# done

for t in $(seq 1000 1000 10000);
do
  for m in $(seq 1000 100 2000);
  do
    sudo perf stat -e L1-dcache-load-misses,l2_rqsts.miss,LLC-load-misses,branches,branch-misses,task-clock,cycles,instructions ./a.out $t 50000 $m 2> results/t$t-m$m.txt
  done
done

echo 1 > /proc/sys/kernel/nmi_watchdog

for t in $(seq 1000 1000 10000);
do
  for m in $(seq 1000 100 2000);
  do
    chmod 777 results/t$t-m$m.txt
  done
done
