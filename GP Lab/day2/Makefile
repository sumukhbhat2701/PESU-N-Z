run: a.out
    ./a.out

a.out: client.o impl.o
    g++ impl.o client.o
    
client.o: client.cpp
    g++ -c client.cpp

impl.o: impl.cpp
    g++ -c impl.cpp







