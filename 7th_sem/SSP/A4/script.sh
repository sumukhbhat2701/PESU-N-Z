gcc a42.c
perf stat -e cache-misses,cache-references taskset -c 1 ./a.out 100 1 2 2>> res.txt
perf stat -e cache-misses,cache-references taskset -c 1 ./a.out 100 2 2 2>> res.txt
perf stat -e cache-misses,cache-references taskset -c 1 ./a.out 100 1 3 2>> res.txt
perf stat -e cache-misses,cache-references taskset -c 1 ./a.out 100 2 3 2>> res.txt
perf stat -e cache-misses,cache-references taskset -c 1 ./a.out 500 1 2 2>> res.txt
perf stat -e cache-misses,cache-references taskset -c 1 ./a.out 500 2 2 2>> res.txt
perf stat -e cache-misses,cache-references taskset -c 1 ./a.out 500 1 3 2>> res.txt
perf stat -e cache-misses,cache-references taskset -c 1 ./a.out 500 2 3 2>> res.txt
perf stat -e cache-misses,cache-references taskset -c 1 ./a.out 1000 1 2 2>> res.txt
perf stat -e cache-misses,cache-references taskset -c 1 ./a.out 1000 2 2 2>> res.txt
perf stat -e cache-misses,cache-references taskset -c 1 ./a.out 1000 1 3 2>> res.txt
perf stat -e cache-misses,cache-references taskset -c 1 ./a.out 1000 2 3 2>> res.txt
perf stat -e cache-misses,cache-references taskset -c 1 ./a.out 5000 1 2 2>> res.txt
perf stat -e cache-misses,cache-references taskset -c 1 ./a.out 5000 2 2 2>> res.txt
perf stat -e cache-misses,cache-references taskset -c 1 ./a.out 10000 1 2 2>> res.txt
perf stat -e cache-misses,cache-references taskset -c 1 ./a.out 10000 2 2 2>> res.txt

