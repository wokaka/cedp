index=2004
echo fi 1 0 -1 -1 $index 0x80000000 > benchmarks/$1/fi_cmd.txt
#./run.sh $1 $2
echo fi 1 0 -1 -1 $index 0x800000 > benchmarks/$1/fi_cmd.txt
#./run.sh $1 $2
echo fi 1 0 -1 -1 $index 0x8000 > benchmarks/$1/fi_cmd.txt
#./run.sh $1 $2
echo fi 1 0 -1 -1 $index 0x80 > benchmarks/$1/fi_cmd.txt
#./run.sh $1 $2
echo fi 1 1 -1 -1 $index 0x80000000 > benchmarks/$1/fi_cmd.txt
#./run.sh $1 $2
echo fi 1 10 -1 -1 $index 0x80000000 > benchmarks/$1/fi_cmd.txt
#./run.sh $1 $2
echo fi 1 0 0 0 $index 0x8 > benchmarks/$1/fi_cmd.txt
./run.sh $1 $2
echo fi 1 0 0 2 $index 0x80000000 > benchmarks/$1/fi_cmd.txt
#./run.sh $1 $2
echo fi 1 0 0 4 $index 0x80000000 > benchmarks/$1/fi_cmd.txt
#./run.sh $1 $2
