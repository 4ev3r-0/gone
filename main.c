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

// STRING SECT END
// --------------------------

// -----------------------
// MAIN SECTION START

int main(void) {
	print("Hello World!\n");
	println("Hello World BUT println INCLUDED!!!!!!!!!!!!!!");
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
