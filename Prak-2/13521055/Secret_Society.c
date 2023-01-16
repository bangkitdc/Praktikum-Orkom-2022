// Nama: Muhammad Bangkit Dwi C.
// NIM: 13521055

#include <stdio.h>

int func4(int x, int y) { // ini intinya GCD(a, b) = GCD(b % a, a)
    if (x > y) {
        return func4(y, x);
    }

    else if (x != 0) {
        return func4(y % x, x);
    }

    // x == 0
    return y;
}

void Secret_Society(char *input) {
    int a , b, count, res;

    count = sscanf(input, "%d %d", &a, &b);

    if (count != 2){
        illegal_move();
    } else {
        if (a - 2 > 0x15) { // input pertama harus <= 23
            illegal_move();
        }

        if (b - 2 > 0x15) { // input kedua harus <= 23
            illegal_move();
        }
    }

    res = func4(a, b); // gcd(a, b)

    if ((a * b) / res != 0x18) { // jadi ini harus (a * b)/ gcd(a,b) hasilnya harus 24
        illegal_move();       
    }

    // karena di awal input harus <= 23
    // hasilnya pengen 24
    // maka cari berapa kali berapa yg hasilnya 24 dan gcdnya 1 biar dibagi 1
    // ketemu deh 3 dan 8
}

// Jawaban: 3 8 Say!Fanfare!