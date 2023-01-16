// Nama : Muhammad Bangkit Dwi C.
// NIM : 13521055

#include <stdio.h>

void read_six_numbers(char* input, int *num) {
    int count;

    count = sscanf(input, "%d %d %d %d %d %d", &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);

    if (count <= 5) {
        illegal_move();
    }
}

void Holoro(char* input) {
    int num[6], a;

    read_six_num(input, num);

    if (num[0] != 0x1) { // input pertama: 1
        illegal_move();
    }
    
    a = 1;

    while (a < 6) {
        if (a % 2 == 0) {
            if (num[a] != num[a - 1] * a) {
                illegal_move();
            }
        } else {
            if (num[a] != num[a - 1] + a) {
                illegal_move();
            }
        }
        a ++;
    }

    // intinya inputnya harus ada pola
    // [1, 2, 4, 7, 28, 33]
    //   +1 *2 +3 *4  +5
}

// Jawaban: 1 2 4 7 28 33