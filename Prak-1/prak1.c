#include <stdio.h>

int gura(int x, int y) {
	// gura(6, 5) = 7
	// 110 101 -> 111
	
	// ~7 = -8 (1000)
	// ~6 = 001
	// ~5 = 010
	// ~6 & ~5 -> 000 (terus di inverse lagi)

	return ~(~x & ~y);
}

int rushia(void) {
	// smallest 2sc = Tmin (1000....)
	// idenya ngegese 1 (...0001) ke kiri 31 kali
	return 1 << 31;
}

unsigned int kobokan(unsigned int x, unsigned int n) {
	// *khusus untuk x mod n, dengan n 2^(p)
	// x mod n = x & (n - 1)

	// negative in binary: ~(x) + 1
	// karena disini mau -1 doang makanya bisa lansung + ~0
	// jadi overflow unsigned jadi bisa negatif

	return x & ((1 << n) + ~0);
}

int fauna(int x, int n) {
	// 0x78 -> (7 x 16^1) + (8 x 16^0)
	// 0x12345678
	// byte ke 0 = 0x78 (dari kanan)
	// mau shift right setiap 8 bit untuk next byte karena
	// tiap angka/ huruf dalam hex itu 4 bit

	// 0x12345678, 1 -> 0x56 = (5 x 16) + 6
	return (x >> (n << 3)) & 0xFF;
}

int yamada(int x) {
	int p = ((134 + (~x + 1)) >> 31) & 1; // 134 - x < 0 
	int q = ((x + (~183 + 1)) >> 31) & 1; // x - 183 < 0

	// idenya misal punya greaterThan(a, b)
	// ngecek bener apa nggak nya dengan b - a < 0
	// kalo negatif (brarti true)
	// pake >> 31 biar keliatan kalo negatif utk 2sc bit paling kiri menyatakan (-)

	return p & q;
}

int pekora(int x) {
	// brute force :D
	// 0x1122 >> 16 = 0
	// 0xaabb << 8 = 0xaabb00
	// 0xaabb << 24 = 0xbb000000 (overflow)
	// *edge-cases 0x01020304 >> 8 = 0x1020304 >> 8 = 0x10203
	// 			   0x01020304 << 8 = 0x2030400

	// misal punya 0x01020304
	// kebaca 0x1020304

	// 0x300 = 0x00000300
	printf("%x %x %x %x\n", x << 24, ((x & (0xff << 8)) << 8), ((x >> 8) & (0xff << 8)), (x >> 24) & 0xff);


	return ((x << 24) | ((x & (0xff << 8)) << 8) | ((x >> 8) & (0xff << 8)) | ((x >> 24) & 0xff));
	//    *0x4000000       0x300     *0x30000            0x10203    *0x200      *0x1

	// harus perhatikan kalau ada >> dan paling kiri itu 1, karena arithmetic shift
	// makanya manfaatin 0xff untuk ngehilangan 1111... di awal
	// 0x4000000
	// 0x00030000
	// 0x00000200
	// 0x00000001
}

int mumei(int x, int n) {
	// logical shift right in c: arithmetic, jadi kalau negatif 1 nya ngikut
	// 1000 >> 1 -> 1100
	
	// idenya adalah
	// 0x1 << 31
	// 1000 .... 0000

	// ((0x1 << 31) >> n) << 1
	// misal n = 4
	// 1111 .... 0000
	// 0000 .... 1111 (ngilangin 1 hex di depan biar jadi 0)

	// ~(((0x1 << 31) >> n) << 1)
	// biar hex depan jadi 0 (logical shift)

	return (x >> n) & ~(((0x1 << 31) >> n) << 1);
}

int moona(int x) {
	int count = 32;
	x = x & (~x + 1);

	count = ~(!(!x) & 1) + 1 + count;
	count = ~(!(!(x & 0xFFFF)) << 4) + 1 + count;
	count = ~(!(!(x & 0xFF00FF)) << 3) + 1 + count;
	count = ~(!(!(x & 0xF0F0F0F)) << 2) + 1 + count;
	count = ~(!(!(x & 0x33333333)) << 1) + 1 + count;
	count = ~(!(!(x & 0x55555555))) + 1 + count;

	return count;
}

// unsigned int ollie(unsigned int a) {
// 	// idenya dari mod 9
// 	// 123 mod 9 = 1 + 2 + 3 = 6
// 	// pake base 16 (hex)

// 	// gabungin mod 15 sama mod 2

// 	// mod 15
// 	// misal 0x8811aabc
// 	// karena unsigned jadi right shift (logical)
// 	// a mod 30 = a mod 2 + 2 * (a/2 mod 15)
	
// 	// mod 2
// 	int z = a & 1;

// 	// a/2
// 	a = a >> 1;

// 	unsigned int p = (a >> 28); // 8
// 	p += (a << 4) >> 28; // 8
// 	p += (a << 8) >> 28; // 1
// 	p += (a << 12) >> 28; // 1
// 	p += (a << 16) >> 28; // a
// 	p += (a << 20) >> 28; // a
// 	p += (a << 24) >> 28; // b
//  	p += (a << 28) >> 28; // c

//  	// p = 0x3d
//  	// hasil maksimal (f * 8) = 120
//  	// jadi tinggal tinjau 2 bit belakang
//  	// diulang sampe hasilnya 1 - 15
//  	unsigned int x = (p << 24) >> 28;
//  	x += ((p << 28) >> 28);

//  	unsigned int y = (x << 24) >> 28;
//  	y += (x << 28) >> 28;
 
//  	int add = ((y + ~15 + 1) >> 31) & 1; // kalau negatif
//  	// add=1 (y < 15)
//  	// add=0 (y = 15)
//  	y = (((add << 31) >>31) & y) | (((!add << 31) >> 31) & 0);

//  	// handle mod 15 = 0
//  	// if else bitwise
 	
//  	return (z + (y << 1));
// }

unsigned int ollie(unsigned int a) {
	// idenya dari mod 9
	// 123 mod 9 = 1 + 2 + 3 = 6
	// pake base 16 (hex)

	// gabungin mod 15 sama mod 2

	// mod 15
	// misal 0x8811aabc
	// karena unsigned jadi right shift (logical)
	// a mod 30 = a mod 2 + 2 * (a/2 mod 15)
	
	// mod 2
	int z = a & 1;
	int limit = 14;
	int subs = 15;

	// a/2
	a = a >> 1;

	// bagi 2 terus sampe 0 - 15
	a = (a >> 16) + (a & 0xFFFF);
	a = (a >> 8) + (a & 0xFF);
	a = (a >> 4) + (a & 0xF);
	
	// kurang 15
	limit = ~a + 1 + 14;
	limit = limit >> 31;
	subs = 15 & limit;
	a = ~subs + 1 + a;

	limit = ~a + 1 + 14;
	limit = limit >> 31;
	subs = 15 & limit;
	a = ~subs + 1 + a;

	limit = ~a + 1 + 14;
	limit = limit >> 31;
	subs = 15 & limit;
	a = ~subs + 1 + a;

 	return (z + (a << 1));
}

unsigned coco(unsigned uf) {
	// intinya kalo *2 -> exp + 1
	// pisah 3 ada [s | exp | frac]
	//              1    8     23
	unsigned s = uf & 0x80000000;
	unsigned exp = uf & 0x7f800000;
	unsigned frac = uf & 0x007fffff;
	unsigned limit = 0xfe; //limit: exp max karena kalau 1 semua nan/inf

	exp = exp >> 23;

	if (!exp) { //expnya 0 semua (denorm)
		frac = frac << 1;
		if (frac & 0x00800000) { //frac depannya 1
			exp += 1;
			frac = frac & 0x007fffff;
		}
	} else {
		limit = limit + ~exp + 1; // limit - 1
		limit = limit >> 31;

		if (!limit) { // kalo limit > exp (kondisi awal)
			exp += 1;
			limit = limit + ~exp + 1;
			limit = limit >> 31;

			if (limit) { // kondisi setelah dikali 2
				frac = 0;
			}
		}
	}

	exp = exp << 23;

	return s | exp | frac;
}

int main() {
	// printf("%x\n", (((x << 16) >> 24) << 16));
	// printf("%x\n", (((x >> 8) << 24) >> 8));
	// printf("%x\n", pekora(0x819922aa));
	// printf("%x\n", mumei(0x87654321, 4));
	// printf("%x\n", (0x87654321 >> 4));
	// int X = 0x1020304;
	// printf("%x\n", X | 0x00000000);

	// printf("%d\n", ollie(4294967295));
	// for (int i = 0; i < 150; i ++) {
	// 	printf("%d\n", ollie(i));
	// }

	printf("%x\n", moona(8));

	// printf("%d\n", 0xf & 15);
    return 0;

}