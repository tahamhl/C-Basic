#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Fonksiyon prototipleri
float toplama(float a, float b);
float cikarma(float a, float b);
float carpma(float a, float b);
float bolme(float a, float b);
float us_alma(float a, float b);
float karekok(float a);

int main() {
    int secim;
    float sayi1, sayi2, sonuc;
    char devam = 'e';
    
    while (devam == 'e' || devam == 'E') {
        // Menüyü göster
        printf("\n----- HESAP MAKİNESİ -----\n");
        printf("1. Toplama\n");
        printf("2. Çıkarma\n");
        printf("3. Çarpma\n");
        printf("4. Bölme\n");
        printf("5. Üs Alma\n");
        printf("6. Karekök\n");
        printf("0. Çıkış\n");
        printf("Seçiminiz (0-6): ");
        scanf("%d", &secim);
        
        if (secim == 0) {
            printf("Hesap makinesi kapatılıyor...\n");
            break;
        }
        
        if (secim < 0 || secim > 6) {
            printf("Geçersiz seçim! Lütfen tekrar deneyin.\n");
            continue;
        }
        
        // Karekök dışındaki işlemler için iki sayı al
        if (secim != 6) {
            printf("Birinci sayıyı girin: ");
            scanf("%f", &sayi1);
            printf("İkinci sayıyı girin: ");
            scanf("%f", &sayi2);
        } else {
            // Karekök için tek sayı yeterli
            printf("Sayıyı girin: ");
            scanf("%f", &sayi1);
        }
        
        // İşlemi gerçekleştir
        switch (secim) {
            case 1:
                sonuc = toplama(sayi1, sayi2);
                printf("%.2f + %.2f = %.2f\n", sayi1, sayi2, sonuc);
                break;
            case 2:
                sonuc = cikarma(sayi1, sayi2);
                printf("%.2f - %.2f = %.2f\n", sayi1, sayi2, sonuc);
                break;
            case 3:
                sonuc = carpma(sayi1, sayi2);
                printf("%.2f * %.2f = %.2f\n", sayi1, sayi2, sonuc);
                break;
            case 4:
                if (sayi2 == 0) {
                    printf("Hata: Sıfıra bölme hatası!\n");
                } else {
                    sonuc = bolme(sayi1, sayi2);
                    printf("%.2f / %.2f = %.2f\n", sayi1, sayi2, sonuc);
                }
                break;
            case 5:
                sonuc = us_alma(sayi1, sayi2);
                printf("%.2f ^ %.2f = %.2f\n", sayi1, sayi2, sonuc);
                break;
            case 6:
                if (sayi1 < 0) {
                    printf("Hata: Negatif sayının karekökü hesaplanamaz!\n");
                } else {
                    sonuc = karekok(sayi1);
                    printf("√%.2f = %.2f\n", sayi1, sonuc);
                }
                break;
        }
        
        // Devam etmek isteyip istemediğini sor
        printf("\nDevam etmek istiyor musunuz? (e/h): ");
        scanf(" %c", &devam);
    }
    
    printf("Program sonlandı. İyi günler!\n");
    return 0;
}

// Toplama işlemi
float toplama(float a, float b) {
    return a + b;
}

// Çıkarma işlemi
float cikarma(float a, float b) {
    return a - b;
}

// Çarpma işlemi
float carpma(float a, float b) {
    return a * b;
}

// Bölme işlemi
float bolme(float a, float b) {
    return a / b;
}

// Üs alma işlemi
float us_alma(float a, float b) {
    return pow(a, b);
}

// Karekök alma işlemi
float karekok(float a) {
    return sqrt(a);
} 