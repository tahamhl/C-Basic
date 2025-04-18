#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KELIME_UZUNLUK 20
#define MAX_KELIME_SAYISI 10
#define MAX_TAHMIN_HAKKI 6

// Fonksiyon prototipleri
void oyun_baslat();
void kelime_sec(char kelimeler[][MAX_KELIME_UZUNLUK], char *secilen_kelime);
void tahmin_durumu_goster(char *kelime, char *tahminler, int yanlis_tahmin);
int harf_kontrol(char harf, char *kelime, char *tahminler);
void adam_asmaca_ciz(int yanlis_tahmin);
int oyun_bitti_mi(char *kelime, char *tahminler, int yanlis_tahmin);

int main() {
    // Rastgele sayı üreteci için seed
    srand(time(NULL));
    
    printf("***** ADAM ASMACA OYUNU *****\n\n");
    printf("Oyun başlatılıyor...\n\n");
    
    oyun_baslat();
    
    return 0;
}

// Oyunu başlatan fonksiyon
void oyun_baslat() {
    // Kelime listesi
    char kelimeler[MAX_KELIME_SAYISI][MAX_KELIME_UZUNLUK] = {
        "PROGRAMLAMA",
        "BILGISAYAR",
        "ALGORITMA",
        "KLAVYE",
        "MONITOR",
        "YAZILIM",
        "INTERNET",
        "VERITABANI",
        "MATEMATIK",
        "DONGU"
    };
    
    char secilen_kelime[MAX_KELIME_UZUNLUK];
    char tahminler[26] = {0}; // Kullanıcının tahmin ettiği harfler
    char tahmin;
    int yanlis_tahmin = 0;
    int tahmin_sayisi = 0;
    int sonuc;
    
    // Rastgele kelime seç
    kelime_sec(kelimeler, secilen_kelime);
    
    while (1) {
        // Oyun durumunu göster
        tahmin_durumu_goster(secilen_kelime, tahminler, yanlis_tahmin);
        
        // Oyun bitti mi kontrol et
        sonuc = oyun_bitti_mi(secilen_kelime, tahminler, yanlis_tahmin);
        if (sonuc != 0) {
            if (sonuc == 1) {
                printf("\nTEBRİKLER! Kelimeyi doğru tahmin ettiniz: %s\n", secilen_kelime);
            } else {
                printf("\nÜZGÜNÜM, kaybettiniz! Doğru kelime: %s\n", secilen_kelime);
            }
            break;
        }
        
        // Kullanıcıdan harf al
        printf("\nBir harf tahmin edin: ");
        scanf(" %c", &tahmin);
        tahmin = toupper(tahmin); // Büyük harfe çevir
        
        // Harf mi kontrol et
        if (!isalpha(tahmin)) {
            printf("Lütfen sadece harf girin!\n");
            continue;
        }
        
        // Daha önce tahmin edilmiş mi kontrol et
        if (tahminler[tahmin - 'A'] == 1) {
            printf("Bu harfi zaten tahmin ettiniz!\n");
            continue;
        }
        
        // Harfi kaydet
        tahminler[tahmin - 'A'] = 1;
        tahmin_sayisi++;
        
        // Kelimede var mı kontrol et
        if (!harf_kontrol(tahmin, secilen_kelime, tahminler)) {
            yanlis_tahmin++;
            printf("Yanlış tahmin! Kalan hakkınız: %d\n", MAX_TAHMIN_HAKKI - yanlis_tahmin);
        } else {
            printf("Doğru tahmin!\n");
        }
    }
    
    // Oyun istatistiklerini göster
    printf("\nOYUN İSTATİSTİKLERİ\n");
    printf("Toplam tahmin sayısı: %d\n", tahmin_sayisi);
    printf("Doğru tahmin sayısı: %d\n", tahmin_sayisi - yanlis_tahmin);
    printf("Yanlış tahmin sayısı: %d\n", yanlis_tahmin);
    
    // Tekrar oynamak isteyip istemediğini sor
    char tekrar;
    printf("\nTekrar oynamak istiyor musunuz? (e/h): ");
    scanf(" %c", &tekrar);
    
    if (tekrar == 'e' || tekrar == 'E') {
        printf("\nYeni oyun başlatılıyor...\n\n");
        oyun_baslat();
    } else {
        printf("\nOyun sona erdi. Tekrar bekleriz!\n");
    }
}

// Kelime listesinden rastgele kelime seçen fonksiyon
void kelime_sec(char kelimeler[][MAX_KELIME_UZUNLUK], char *secilen_kelime) {
    int indeks = rand() % MAX_KELIME_SAYISI;
    strcpy(secilen_kelime, kelimeler[indeks]);
}

// Tahmin durumunu gösteren fonksiyon
void tahmin_durumu_goster(char *kelime, char *tahminler, int yanlis_tahmin) {
    printf("\n");
    
    // Adam asmaca çizimi
    adam_asmaca_ciz(yanlis_tahmin);
    
    // Kelime durumu
    printf("\nKelime: ");
    int i;
    for (i = 0; i < strlen(kelime); i++) {
        if (tahminler[kelime[i] - 'A'] == 1) {
            printf("%c ", kelime[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
    
    // Tahmin edilen harfler
    printf("\nTahmin edilen harfler: ");
    for (i = 0; i < 26; i++) {
        if (tahminler[i] == 1) {
            printf("%c ", 'A' + i);
        }
    }
    printf("\n");
}

// Harfin kelimede olup olmadığını kontrol eder
int harf_kontrol(char harf, char *kelime, char *tahminler) {
    int i;
    int bulundu = 0;
    
    for (i = 0; i < strlen(kelime); i++) {
        if (kelime[i] == harf) {
            bulundu = 1;
        }
    }
    
    return bulundu;
}

// Adam asmaca çizimini yapan fonksiyon
void adam_asmaca_ciz(int yanlis_tahmin) {
    printf("  +---+\n");
    printf("  |   |\n");
    
    if (yanlis_tahmin >= 1) {
        printf("  O   |\n");
    } else {
        printf("      |\n");
    }
    
    if (yanlis_tahmin >= 2) {
        if (yanlis_tahmin >= 3) {
            if (yanlis_tahmin >= 4) {
                printf(" /|\\  |\n"); // 4: sağ kol
            } else {
                printf(" /|   |\n"); // 3: sol kol
            }
        } else {
            printf("  |   |\n"); // 2: gövde
        }
    } else {
        printf("      |\n");
    }
    
    if (yanlis_tahmin >= 5) {
        if (yanlis_tahmin >= 6) {
            printf(" / \\  |\n"); // 6: sağ bacak
        } else {
            printf(" /    |\n"); // 5: sol bacak
        }
    } else {
        printf("      |\n");
    }
    
    printf("      |\n");
    printf("=========\n");
}

// Oyunun bitip bitmediğini kontrol eder
// 0: devam ediyor, 1: kazandı, -1: kaybetti
int oyun_bitti_mi(char *kelime, char *tahminler, int yanlis_tahmin) {
    // Kaybetti mi?
    if (yanlis_tahmin >= MAX_TAHMIN_HAKKI) {
        return -1;
    }
    
    // Tüm harfler bulundu mu?
    int i;
    for (i = 0; i < strlen(kelime); i++) {
        if (tahminler[kelime[i] - 'A'] == 0) {
            return 0; // Devam ediyor
        }
    }
    
    return 1; // Kazandı
} 