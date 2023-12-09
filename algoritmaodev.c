#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000 // Maksimum dosya uzunluğu

int main() {
    FILE *dosya;
    char metin[MAX_LENGTH], sifreliMetin[MAX_LENGTH], cozulmusMetin[MAX_LENGTH]; // Değişken Atamaları
    int anahtar, secim;
    char dosyaAdi[MAX_LENGTH];

    printf("******************VERILEN INPUT DOSYASINI KAYDETTIGINIZ VARSAYILMAKTADIR.******************\n"); // Başlık
    printf("******Input Dosyasini, Proje Ile Ayni Dizine Kaydediniz.******\n\n");
    printf("Dosya adini girin: "); // Kullanıcıdan Dosya Adı Alınıyor
    scanf("%s", dosyaAdi);

    dosya = fopen(dosyaAdi, "r");
    if (dosya == NULL) {
        printf("Dosya acilamadi!"); // Hatalı Giriş Uyarısı
        return 1;
    }

    fgets(metin, MAX_LENGTH, dosya); // Dosya Okuma İşlemi
    fclose(dosya); // Okunan Dosyayı Kapatarak Gereksiz Bellek Kullanımını Önleme

    printf("Anahtar degerini girin: "); // Kullanıcıdan Değer Ataması İsteniyor Yine
    scanf("%d", &anahtar);

    printf("1 - Sifreleme\n2 - Sifre Cozme\nSeciminiz: ");
    scanf("%d", &secim);

    if (secim == 1) { //Şifreleme İşlemi.
        int i;
        for (i = 0; metin[i] != '\0'; ++i) {
            if (isalpha(metin[i])) {
                char base = islower(metin[i]) ? 'a' : 'A';
                sifreliMetin[i] = base + (metin[i] - base + anahtar) % 26; // Harfin Bulunduğu "base" İle İşlem Yapılacak
            } else {
                sifreliMetin[i] = metin[i];
            }
        }
        sifreliMetin[i] = '\0';

        printf("Sifreleme tamamlandi: %s\n", sifreliMetin);

        dosya = fopen("sifreli.txt", "w"); // Yeni Dosya
        fprintf(dosya, "%s", sifreliMetin);
        fclose(dosya);
    } else if (secim == 2) { //Deşifre İşlemi.
        int i;
        for (i = 0; metin[i] != '\0'; ++i) {
            if (isalpha(metin[i])) {
                char base = islower(metin[i]) ? 'a' : 'A';
                cozulmusMetin[i] = base + (metin[i] - base - anahtar + 26) % 26; // Harfin Bulunduğu "base" İle İşlem Yapılacak. "-", deşifre için.
            } else {
                cozulmusMetin[i] = metin[i];
            }
        }
        cozulmusMetin[i] = '\0';

        printf("Sifre cozuldu: %s\n", cozulmusMetin);

        dosya = fopen("cozulmus.txt", "w"); // Yeni Dosya
        fprintf(dosya, "%s", cozulmusMetin);
        fclose(dosya);
    } else {
        printf("Gecersiz secim!"); // Aynı Şekilde Uyarı
        return 1;
    }

    return 0;
}
