gcc sort.c -pg
./a.out 10000 1
gprof a.out gmon.out > 10k_1.txt
./a.out 100000 1
gprof a.out gmon.out > 100k_1.txt
./a.out 1000000 1
gprof a.out gmon.out > 1000k_1.txt
./a.out 10000000 1
gprof a.out gmon.out > 10000k_1.txt
./a.out 10000 2
gprof a.out gmon.out > 10k_2.txt
./a.out 100000 2
gprof a.out gmon.out > 100k_2.txt
./a.out 1000000 2
gprof a.out gmon.out > 1000k_2.txt
./a.out 10000000 2
gprof a.out gmon.out > 10000k_2.txt
./a.out 10000 3
gprof a.out gmon.out > 10k_3.txt
./a.out 100000 3
gprof a.out gmon.out > 100k_3.txt
./a.out 1000000 3
gprof a.out gmon.out > 1000k_3.txt
./a.out 10000000 3
gprof a.out gmon.out > 10000k_3.txt
