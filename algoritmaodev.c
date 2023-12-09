#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000 //Maksimum Dosya Uzunlu�u.

int main() {
    FILE *dosya;
    char metin[MAX_LENGTH], sifreliMetin[MAX_LENGTH], cozulmusMetin[MAX_LENGTH]; //De�i�ken Atamalar�.
    int anahtar, secim;
    char dosyaAdi[MAX_LENGTH];

    printf("******************VERILEN INPUT DOSYASINI KAYDETTIGINIZ VARSAYILMAKTADIR.******************\n"); // Ba�l�k.
	printf("******Input Dosyasini, Proje Ile Ayni Dizine Kaydediniz.******\n\n");
    printf("Dosya adini girin: "); // Kullan�c�dan Dosya Ad� Al�n�yor.
    scanf("%s", dosyaAdi);

    dosya = fopen(dosyaAdi, "r");
    if (dosya == NULL) {
        printf("Dosya acilamadi!"); //Hatal� Giri� Uyar�s�.
        return 1;
    }

    fgets(metin, MAX_LENGTH, dosya); //Dosya Okuma ��lemi.
    fclose(dosya); //Okunan Dosyay� Kapatarak Gereksiz Bellek Kullan�m�n� �nleme.

    printf("Anahtar degerini girin: "); //Kullan�c�dan De�er Atamas� �steniyor Yine.
    scanf("%d", &anahtar);

    printf("1 - Sifreleme\n2 - Sifre Cozme\nSeciminiz: ");
    scanf("%d", &secim);

    if (secim == 1) {
        // �ifreleme ��lemi.
    } else if (secim == 2) {
        int i;
        for (i = 0; metin[i] != '\0'; ++i) {
            if (isalpha(metin[i])) {
                char base = islower(metin[i]) ? 'a' : 'A';
                cozulmusMetin[i] = base + (metin[i] - base - anahtar + 26) % 26; // Harfin Bulundu�u "base" �le ��lem Yap�l�yor.
                if (cozulmusMetin[i] < base) { // E�er Harf S�n�rlar� A��ld�ysa,
                    cozulmusMetin[i] += 26; // 26 Ekleyerek Alfabe S�n�rlar� ��inde Tutuyoruz.
                }
            } else {
                cozulmusMetin[i] = metin[i];
            }
        }
        cozulmusMetin[i] = '\0';

        printf("Sifre cozuldu: %s\n", cozulmusMetin);

        dosya = fopen("cozulmus.txt", "w"); //Yeni Dosya.
        fprintf(dosya, "%s", cozulmusMetin);
        fclose(dosya);
    } else {
        printf("Gecersiz secim!"); //Ayn� �ekilde Uyar�.
        return 1;
    }

    return 0;
}

