poG: poG.o queue.o Graph.o
	gcc -o poG poG.o queue.o Graph.o

poG.o : poG.c Graph.h queue.h
	gcc -Wall -Werror -std=c11 -c poG.c

queue.o: queue.c queue.h 
	gcc -Wall -Werror -std=c11 -c queue.c

Graph.o : Graph.c Graph.h queue.h queue.c
	gcc -Wall -Werror -std=c11 -c Graph.c

clean:
	rm -f poG poG.o queue.o Graph.o core
