CC = gcc
C = -std=gnu23 -O3 -ffreestanding -fno-builtin -fno-stack-protector -fno-pie
L = -nostdlib -static -no-pie

main: main.c
	$(CC) $(C) main.c $(L) -o gone

clean:
	rm -rf gone
