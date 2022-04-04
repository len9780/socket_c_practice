obj=broadcast.o main.o
par = -std=gnu99  -Wall -g

all: $(obj) main

%.o:%.c
	gcc -c $^
main: main.o broadcast.o
	gcc $(par) $^ -o $@
clean:
	rm *.o main

