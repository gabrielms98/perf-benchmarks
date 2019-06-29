for t in $(seq 1000 1000 10000);
do
  for m in $(seq 1000 100 2000);
  do
    cat results/t$t-m$m.txt | grep "<not counted>"
  done
done
