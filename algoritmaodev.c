#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000 //Maksimum Dosya Uzunluðu.

int main() {
    FILE *dosya;
    char metin[MAX_LENGTH], sifreliMetin[MAX_LENGTH], cozulmusMetin[MAX_LENGTH]; //Deðiþken Atamalarý.
    int anahtar, secim;
    char dosyaAdi[MAX_LENGTH];

    printf("******************VERILEN INPUT DOSYASINI KAYDETTIGINIZ VARSAYILMAKTADIR.******************\n"); // Baþlýk.
	printf("******Input Dosyasini, Proje Ile Ayni Dizine Kaydediniz.******\n\n");
    printf("Dosya adini girin: "); // Kullanýcýdan Dosya Adý Alýnýyor.
    scanf("%s", dosyaAdi);

    dosya = fopen(dosyaAdi, "r");
    if (dosya == NULL) {
        printf("Dosya acilamadi!"); //Hatalý Giriþ Uyarýsý.
        return 1;
    }

    fgets(metin, MAX_LENGTH, dosya); //Dosya Okuma Ýþlemi.
    fclose(dosya); //Okunan Dosyayý Kapatarak Gereksiz Bellek Kullanýmýný Önleme.

    printf("Anahtar degerini girin: "); //Kullanýcýdan Deðer Atamasý Ýsteniyor Yine.
    scanf("%d", &anahtar);

    printf("1 - Sifreleme\n2 - Sifre Cozme\nSeciminiz: ");
    scanf("%d", &secim);

    if (secim == 1) {
        // Þifreleme Ýþlemi.
    } else if (secim == 2) {
        int i;
        for (i = 0; metin[i] != '\0'; ++i) {
            if (isalpha(metin[i])) {
                char base = islower(metin[i]) ? 'a' : 'A';
                cozulmusMetin[i] = base + (metin[i] - base - anahtar + 26) % 26; // Harfin Bulunduðu "base" Ýle Ýþlem Yapýlýyor.
                if (cozulmusMetin[i] < base) { // Eðer Harf Sýnýrlarý Aþýldýysa,
                    cozulmusMetin[i] += 26; // 26 Ekleyerek Alfabe Sýnýrlarý Ýçinde Tutuyoruz.
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
        printf("Gecersiz secim!"); //Ayný Þekilde Uyarý.
        return 1;
    }

    return 0;
}

