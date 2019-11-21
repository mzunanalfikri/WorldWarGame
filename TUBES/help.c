#include <stdio.h>

void Help() {
    printf("COMMANDS : \n\n");
    printf("ATTACK - Memulai serangan ke bangunan lain\n\n");
    printf("LEVEL_UP - Menaikan level suatu bangunan dari pemain\n\n");
    printf("SKILL - Memakai skill yang dimiliki oleh pemain\n\n");
    printf("UNDO - Membatalkan perintah terakhir(sampai command End Turn/Skill)\n\n");
    printf("END_TURN - Mengakhiri giliran seorang pemain\n\n");
    printf("MOVE - Memindahkan pasukan dari bangunan yang terhubung\n\n");
    printf("SAVE - Menyimpan status permainan ke file eksternal\n\n");
    printf("EXIT - Keluar dari permainan\n\n");

}

int main() {
    Help();
    return 0;
}

