#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Seçim sabitleri
#define TAS 1
#define KAGIT 2
#define MAKAS 3

// Fonksiyon prototipleri
void oyun_kurallarini_goster();
int bilgisayar_secimi_yap();
char* secimi_metne_cevir(int secim);
int kazanani_belirle(int oyuncu, int bilgisayar);

int main() {
    int oyuncu_secimi, bilgisayar_secimi;
    int oyuncu_skor = 0, bilgisayar_skor = 0;
    char devam = 'e';
    
    // Rastgele sayı üreteci için seed
    srand(time(NULL));
    
    printf("***** TAŞ KAĞIT MAKAS OYUNU *****\n\n");
    oyun_kurallarini_goster();
    
    while (devam == 'e' || devam == 'E') {
        // Oyuncu seçimini al
        printf("\nSeçiminizi yapın (1-3): ");
        scanf("%d", &oyuncu_secimi);
        
        if (oyuncu_secimi < 1 || oyuncu_secimi > 3) {
            printf("Geçersiz seçim! Lütfen 1, 2 veya 3 girin.\n");
            continue;
        }
        
        // Bilgisayar seçimini yap
        bilgisayar_secimi = bilgisayar_secimi_yap();
        
        // Seçimleri göster
        printf("\nSizin seçiminiz: %s\n", secimi_metne_cevir(oyuncu_secimi));
        printf("Bilgisayarın seçimi: %s\n", secimi_metne_cevir(bilgisayar_secimi));
        
        // Kazananı belirle
        int sonuc = kazanani_belirle(oyuncu_secimi, bilgisayar_secimi);
        
        if (sonuc == 0) {
            printf("Sonuç: Berabere!\n");
        } else if (sonuc == 1) {
            printf("Sonuç: Kazandınız!\n");
            oyuncu_skor++;
        } else {
            printf("Sonuç: Bilgisayar kazandı!\n");
            bilgisayar_skor++;
        }
        
        // Mevcut skoru göster
        printf("\nSKOR\n");
        printf("Siz: %d - Bilgisayar: %d\n", oyuncu_skor, bilgisayar_skor);
        
        // Devam etmek isteyip istemediğini sor
        printf("\nTekrar oynamak istiyor musunuz? (e/h): ");
        scanf(" %c", &devam);
    }
    
    // Final skorunu göster
    printf("\n***** OYUN SONA ERDİ *****\n");
    printf("Final Skoru: Siz %d - %d Bilgisayar\n", oyuncu_skor, bilgisayar_skor);
    
    if (oyuncu_skor > bilgisayar_skor) {
        printf("Tebrikler! Oyunu kazandınız!\n");
    } else if (oyuncu_skor < bilgisayar_skor) {
        printf("Üzgünüm, bilgisayar kazandı!\n");
    } else {
        printf("Oyun berabere bitti!\n");
    }
    
    return 0;
}

// Oyun kurallarını gösteren fonksiyon
void oyun_kurallarini_goster() {
    printf("OYUN KURALLARI:\n");
    printf("1 = TAŞ\n");
    printf("2 = KAĞIT\n");
    printf("3 = MAKAS\n\n");
    printf("Taş makası kırar, kağıt taşı sarar, makas kağıdı keser.\n");
}

// Bilgisayarın rastgele seçim yapması
int bilgisayar_secimi_yap() {
    return (rand() % 3) + 1; // 1, 2 veya 3 döndürür
}

// Seçim numarasını metin olarak döndürür
char* secimi_metne_cevir(int secim) {
    switch (secim) {
        case TAS:
            return "TAŞ";
        case KAGIT:
            return "KAĞIT";
        case MAKAS:
            return "MAKAS";
        default:
            return "GEÇERSİZ";
    }
}

// Kazananı belirleyen fonksiyon
// 0 = berabere, 1 = oyuncu kazandı, 2 = bilgisayar kazandı
int kazanani_belirle(int oyuncu, int bilgisayar) {
    if (oyuncu == bilgisayar) {
        return 0; // Berabere
    }
    
    if ((oyuncu == TAS && bilgisayar == MAKAS) ||
        (oyuncu == KAGIT && bilgisayar == TAS) ||
        (oyuncu == MAKAS && bilgisayar == KAGIT)) {
        return 1; // Oyuncu kazandı
    }
    
    return 2; // Bilgisayar kazandı
} 