typedef unsigned long size_t;

#define NULL ((void *)0)


#define stdout 1

#define SYS_WRITE 1 
#define SYS_EXIT 60

// --------------------------
// System Calls sect

static long syscall(long n, long a, long b, long c, long d, long e, long f) {
	long ret;
	register long r10 __asm__("r10") = d;
	register long r9 __asm__("r9") = e;
	register long r8 __asm__("r8") = f;
	__asm__ volatile("syscall":"=a"(ret):"a"(n),"D"(a),"S"(b),"d"(c):"rcx","r11","memory");
	return ret;
} 

// System Calls sect end
// --------------------------

// --------------------------
// STRING SECT START

size_t strlen(const char *s) {
	size_t n = 0;
	while(s[n]) { n++; }
	return n;
}

void print(const char *s) {
	syscall(SYS_WRITE, stdout, (long)s, (long)strlen(s),0,0,0);
}

void println(const char *s) {
	print(s);
	print("\n");
}

void printf(const char *fmt, ...) {
	__builtin_va_list ap;
	__builtin_va_start(ap,fmt);

	for (; *fmt; fmt++) {
		if (*fmt != '%') {
			syscall(SYS_WRITE, 1, (long)fmt, 1,0,0,0);
			continue;
		}

		if (!++fmt) break;

		bool is_long = false;
		if (*fmt == 'l') is_long = true, fmt++;
		if (!*fmt) break;

		switch (*fmt) {
			case 's': {
				const char *s = __builtin_va_arg(ap, const char *);
				print(s ? s : "(null)");
				break;
			}
			case 'n': {
				print("\n");
			}
		}
	}
}
// STRING SECT END
// --------------------------

// -----------------------
// MAIN SECTION START

int main(void) {
	print("Hello World!\n");
	println("Hello World BUT println INCLUDED!!!!!!!!!!!!!!");
	printf("Hello World %s%n", "but also printf");
	return 0;
}

// MAIN SECTION END
// ----------------------


// -------------------------
// LAUNCH START

void start() { syscall(SYS_EXIT,main(),0,0,0,0,0); }

__asm__(".global _start\n_start:\nxor %rbp, %rbp\ncall start");

// LAUNCH END
// -------------------------
