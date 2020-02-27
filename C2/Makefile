
all:
	gcc -O1 rdrand.c -o rdrand.out
	gcc -c minimal.S 
	ld -e foo minimal.o
	mv a.out minimal.out
	gcc -c minimal-with-data.S
	ld -e foo minimal-with-data.o
	mv a.out minimal-with-data.out
clean:
	rm -f *.out *.o
