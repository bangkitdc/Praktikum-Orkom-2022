// Nama : Muhammad Bangkit Dwi C.
// NIM : 13521055

#include <stdio.h>

void Holoh3ro(char* input) {
    int a, b, count;
    char c;

    count = sscanf(input, "%d %c %d", &a, &c, &b);

    if (count <= 2){
        illegal_move();
    }

    if (a > 7) {
        illegal_move();
    } else {
        switch (c) {
            // case lainnya

            case 115: // huruf s

            if (b != 947) { // jawaban 2
                illegal_move();
            }

            // aku gangerti ini codenya gimana tapi intinya gini kak
            // di akhir ada compare 0x3(%esp)
            // karena little endian dan harus dimake sure juga
            // %esp tu isinya 0x73......
            // nah 0x73 tuh 115 kalo dalam ASCII 's' berarti bener hehe :D

            break;

            // case lainnya
        }
    }
}

// Jawaban: 1 s 947