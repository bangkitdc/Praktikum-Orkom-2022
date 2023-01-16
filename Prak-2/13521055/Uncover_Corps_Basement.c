// Nama : Muhammad Bangkit Dwi C.
// NIM : 13521055

#include <stdio.h>

void Uncover_Corps_Basement(char* input){
    if (input != "Selamat! Kamu menang gacha.") {
        illegal_move();
    } else {
        stage_completed();
    }
}

// Jawaban : "Selamat! Kamu menang gacha."