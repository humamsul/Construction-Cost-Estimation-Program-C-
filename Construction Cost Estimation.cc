#include <stdio.h>

#define MAX 10


void tampilPekerjaan(char pekerjaan[][30], int harga[], int n) {
    printf("\n=== DAFTAR PEKERJAAN KONSTRUKSI ===\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %-20s Rp%d per m2\n", i + 1, pekerjaan[i], harga[i]);
    }
}


int hitungTotal(int luas[], int harga[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += luas[i] * harga[i];
    }
    return total;
}

int main() {
    char pekerjaan[MAX][30] = {
        "Pondasi", "Dinding", "Atap", "Lantai", "Pengecatan"
    };
    int harga[MAX] = {250000, 300000, 400000, 200000, 150000};
    int luas[MAX] = {0};
    int n = 5, pilihan;
    char lanjut;

    printf("=== SISTEM ESTIMASI BIAYA KONSTRUKSI ===\n");

    do {
        tampilPekerjaan(pekerjaan, harga, n);
        printf("\nPilih jenis pekerjaan (1-%d): ", n);
        scanf("%d", &pilihan);

        if (pilihan < 1 || pilihan > n) {
            printf("Pilihan tidak valid!\n");
        } else {
            printf("Masukkan luas area (m2) untuk %s: ", pekerjaan[pilihan - 1]);
            scanf("%d", &luas[pilihan - 1]);
        }

        printf("Apakah ingin menambah pekerjaan lain? (y/n): ");
        scanf(" %c", &lanjut);
    } while (lanjut == 'y' || lanjut == 'Y');

    int total = hitungTotal(luas, harga, n);
    float diskon = (total > 100000000) ? total * 0.05 : 0;
    float bayar = total - diskon;

    printf("\n=== LAPORAN ESTIMASI BIAYA ===\n");
    for (int i = 0; i < n; i++) {
        if (luas[i] > 0)
            printf("%s (%dm2) = Rp%d\n", pekerjaan[i], luas[i], luas[i] * harga[i]);
    }
    printf("---------------------------------\n");
    printf("Total Biaya: Rp%d\n", total);
    if (diskon > 0)
        printf("Diskon 5%%: Rp%.0f\n", diskon);
    printf("Total yang Harus Dibayar: Rp%.0f\n", bayar);
    printf("\nTerima kasih telah menggunakan sistem estimasi konstruksi!\n");

    return 0;
}
