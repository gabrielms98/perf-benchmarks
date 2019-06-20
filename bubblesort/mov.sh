for i in $(seq 1001 1000 50001);
do
  cat $i.txt | grep "<not counted>"
done