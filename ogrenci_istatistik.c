#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_OGRENCI 100

// Harf notu sınırları
#define AA_SINIR 90
#define BA_SINIR 85
#define BB_SINIR 80
#define CB_SINIR 75
#define CC_SINIR 70
#define DC_SINIR 65
#define DD_SINIR 60
#define FD_SINIR 50
#define FF_SINIR 0

// Öğrenci yapısı
typedef struct {
    char ad[50];
    int no;
    float not;
    char harf_not[3];
} Ogrenci;

// Fonksiyon prototipleri
float ortalama_hesapla(Ogrenci sinif[], int n);
float standart_sapma_hesapla(Ogrenci sinif[], int n, float ortalama);
void harf_notu_belirle(Ogrenci sinif[], int n);
void sinifi_yazdir(Ogrenci sinif[], int n, float ortalama, float standart_sapma);

int main() {
    Ogrenci sinif[MAX_OGRENCI];
    int n = 0;
    float ort, std_sapma;
    
    printf("Sınıftaki öğrenci sayısını girin (maksimum %d): ", MAX_OGRENCI);
    scanf("%d", &n);
    
    if (n <= 0 || n > MAX_OGRENCI) {
        printf("Geçersiz öğrenci sayısı!\n");
        return 1;
    }
    
    // Öğrenci bilgilerini al
    for (int i = 0; i < n; i++) {
        printf("\n%d. Öğrenci Bilgileri:\n", i+1);
        printf("Ad: ");
        scanf(" %49[^\n]", sinif[i].ad);
        printf("Numara: ");
        scanf("%d", &sinif[i].no);
        printf("Not: ");
        scanf("%f", &sinif[i].not);
        
        // Not sınırlarını kontrol et
        if (sinif[i].not < 0 || sinif[i].not > 100) {
            printf("Geçersiz not değeri! Not 0-100 arasında olmalıdır.\n");
            i--; // Öğrencinin bilgilerini tekrar girmesi için
            continue;
        }
    }
    
    // Ortalama ve standart sapma hesapla
    ort = ortalama_hesapla(sinif, n);
    std_sapma = standart_sapma_hesapla(sinif, n, ort);
    
    // Harf notlarını belirle
    harf_notu_belirle(sinif, n);
    
    // Sonuçları yazdır
    sinifi_yazdir(sinif, n, ort, std_sapma);
    
    return 0;
}

// Sınıfın not ortalamasını hesaplar
float ortalama_hesapla(Ogrenci sinif[], int n) {
    float toplam = 0;
    
    for (int i = 0; i < n; i++) {
        toplam += sinif[i].not;
    }
    
    return toplam / n;
}

// Notların standart sapmasını hesaplar
float standart_sapma_hesapla(Ogrenci sinif[], int n, float ortalama) {
    float varyans = 0;
    
    for (int i = 0; i < n; i++) {
        varyans += pow(sinif[i].not - ortalama, 2);
    }
    
    return sqrt(varyans / n);
}

// Öğrencilerin harf notlarını belirler
void harf_notu_belirle(Ogrenci sinif[], int n) {
    for (int i = 0; i < n; i++) {
        if (sinif[i].not >= AA_SINIR) {
            strcpy(sinif[i].harf_not, "AA");
        } else if (sinif[i].not >= BA_SINIR) {
            strcpy(sinif[i].harf_not, "BA");
        } else if (sinif[i].not >= BB_SINIR) {
            strcpy(sinif[i].harf_not, "BB");
        } else if (sinif[i].not >= CB_SINIR) {
            strcpy(sinif[i].harf_not, "CB");
        } else if (sinif[i].not >= CC_SINIR) {
            strcpy(sinif[i].harf_not, "CC");
        } else if (sinif[i].not >= DC_SINIR) {
            strcpy(sinif[i].harf_not, "DC");
        } else if (sinif[i].not >= DD_SINIR) {
            strcpy(sinif[i].harf_not, "DD");
        } else if (sinif[i].not >= FD_SINIR) {
            strcpy(sinif[i].harf_not, "FD");
        } else {
            strcpy(sinif[i].harf_not, "FF");
        }
    }
}

// Sınıf bilgilerini yazdırır
void sinifi_yazdir(Ogrenci sinif[], int n, float ortalama, float standart_sapma) {
    printf("\n----- SINIF BİLGİLERİ -----\n");
    printf("Sınıf Mevcudu: %d\n", n);
    printf("Sınıf Ortalaması: %.2f\n", ortalama);
    printf("Standart Sapma: %.2f\n\n", standart_sapma);
    
    printf("%-20s %-10s %-10s %-10s\n", "Ad", "Numara", "Not", "Harf Notu");
    printf("--------------------------------------------------\n");
    
    for (int i = 0; i < n; i++) {
        printf("%-20s %-10d %-10.2f %-10s\n", 
               sinif[i].ad, sinif[i].no, sinif[i].not, sinif[i].harf_not);
    }
} 