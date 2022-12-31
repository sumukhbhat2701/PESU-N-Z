gcc sort.c
(time -o merge_sort.txt ./a.out 10000 1) 
(time ./a.out 100000 1) -o merge_sort.txt 
(time ./a.out 1000000 1) -o merge_sort.txt
(time ./a.out 10000000 1) -o merge_sort.txt
(time ./a.out 10000 2) -o quick_sort.txt
(time ./a.out 100000 2) -o quick_sort.txt
(time ./a.out 1000000 2) -o quick_sort.txt
(time ./a.out 10000000 2) -o quick_sort.txt
(time ./a.out 10000 3) -o heap_sort.txt
(time ./a.out 100000 3) -o heap_sort.txt
(time ./a.out 1000000 3) -o heap_sort.txt
(time ./a.out 10000000 3) -o heap_sort.txt