for i in $(seq 100000 10000 300000) ; do
  chmod 777 results/$i.txt
    cat results/$i.txt | grep "<not counted>"
done
