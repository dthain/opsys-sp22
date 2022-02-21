all: sem-pc sem-rw monitor-bank monitor-pc

sem-pc: sem-pc.c
	gcc -Wall -g sem-pc.c -o sem-pc -pthread

sem-rw: sem-rw.c
	gcc -Wall -g sem-rw.c -o sem-rw -pthread

monitor-bank: monitor-bank.c
	gcc -Wall -g monitor-bank.c -o monitor-bank -pthread

monitor-pc: monitor-pc.c
	gcc -Wall -g monitor-pc.c -o monitor-pc -pthread

clean:
	rm -f sem-pc sem-rw monitor-bank monitor-pc
