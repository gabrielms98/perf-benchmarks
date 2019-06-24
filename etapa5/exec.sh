# read entry
# sudo perf stat -e L1-dcache-load-misses,l2_rqsts.code_rd_miss,branches,branch-misses,task-clock,cycles,instructions ./a.out tam
    # task-clock,cycles,instructions,cache-references,cache-misses,branches ./a.out

echo 0 > /proc/sys/kernel/nmi_watchdog

for p in a b c; 
do
  sudo perf stat -e L1-dcache-load-misses,l2_rqsts.miss,LLC-load-misses,branches,branch-misses,task-clock,cycles,instructions ./$p < $p.in 2> results/$p.txt
done

echo 1 > /proc/sys/kernel/nmi_watchdog

for p in a b c;
do
  chmod 777 results/$p.txt
done
