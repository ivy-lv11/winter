CFLAGS := -I ..
LDFLAGS := -lpthread
all:
	gcc $(CFLAGS) -O1 stack_probe.c -o stack_probe.out $(LDFLAGS)
	gcc $(CFLAGS) -O1 hello-mt.c -o hello-mt.out $(LDFLAGS)
	gcc $(CFLAGS) -O1 thread-local.c -o thread-local.out $(LDFLAGS)
	gcc $(CFLAGS) -O0 sum.c -o sum0.out $(LDFLAGS)
	gcc $(CFLAGS) -O1 sum.c -o sum1.out $(LDFLAGS)
	gcc $(CFLAGS) -O2 sum.c -o sum2.out $(LDFLAGS)


clean:
	rm -f *.out

