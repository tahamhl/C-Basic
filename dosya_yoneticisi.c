#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DOSYA_ADI 100
#define MAX_METIN 1000

// Fonksiyon prototipleri
void dosya_olustur();
void dosya_oku();
void dosya_guncelle();
void dosya_sil();
void menu_goster();

int main() {
    int secim = 0;
    
    while (1) {
        menu_goster();
        printf("Seçiminiz (0-4): ");
        scanf("%d", &secim);
        
        switch (secim) {
            case 0:
                printf("Program sonlandırılıyor...\n");
                return 0;
            case 1:
                dosya_olustur();
                break;
            case 2:
                dosya_oku();
                break;
            case 3:
                dosya_guncelle();
                break;
            case 4:
                dosya_sil();
                break;
            default:
                printf("Geçersiz seçim! Lütfen tekrar deneyin.\n");
                break;
        }
        
        printf("\nDevam etmek için Enter tuşuna basın...");
        getchar(); // Tampon temizleme
        getchar(); // Kullanıcı girişi bekleme
        system("cls"); // Ekranı temizle (Windows)
        // Linux için: system("clear");
    }
    
    return 0;
}

// Menüyü gösteren fonksiyon
void menu_goster() {
    printf("----- DOSYA YÖNETİCİSİ -----\n");
    printf("1. Dosya Oluştur\n");
    printf("2. Dosya Oku\n");
    printf("3. Dosya Güncelle\n");
    printf("4. Dosya Sil\n");
    printf("0. Çıkış\n");
}

// Yeni dosya oluşturan fonksiyon
void dosya_olustur() {
    char dosya_adi[MAX_DOSYA_ADI];
    char metin[MAX_METIN];
    FILE *dosya;
    
    printf("\n----- DOSYA OLUŞTUR -----\n");
    
    // Dosya adını al
    printf("Oluşturulacak dosyanın adını girin: ");
    scanf(" %99[^\n]", dosya_adi);
    
    // Dosya var mı kontrol et
    dosya = fopen(dosya_adi, "r");
    if (dosya != NULL) {
        printf("Hata: %s adında bir dosya zaten var!\n", dosya_adi);
        fclose(dosya);
        return;
    }
    
    // Dosyayı yazma modunda aç
    dosya = fopen(dosya_adi, "w");
    if (dosya == NULL) {
        printf("Hata: Dosya oluşturulamadı!\n");
        return;
    }
    
    // Dosyaya yazılacak metni al
    printf("Dosyaya yazılacak metni girin:\n");
    scanf(" %999[^\n]", metin);
    
    // Metni dosyaya yaz
    fprintf(dosya, "%s", metin);
    fclose(dosya);
    
    printf("Dosya başarıyla oluşturuldu: %s\n", dosya_adi);
}

// Dosya içeriğini okuyan fonksiyon
void dosya_oku() {
    char dosya_adi[MAX_DOSYA_ADI];
    char metin[MAX_METIN];
    FILE *dosya;
    
    printf("\n----- DOSYA OKU -----\n");
    
    // Dosya adını al
    printf("Okunacak dosyanın adını girin: ");
    scanf(" %99[^\n]", dosya_adi);
    
    // Dosyayı okuma modunda aç
    dosya = fopen(dosya_adi, "r");
    if (dosya == NULL) {
        printf("Hata: %s dosyası bulunamadı!\n", dosya_adi);
        return;
    }
    
    // Dosya içeriğini oku ve ekrana yazdır
    printf("\n----- %s İÇERİĞİ -----\n", dosya_adi);
    while (fgets(metin, MAX_METIN, dosya) != NULL) {
        printf("%s", metin);
    }
    
    fclose(dosya);
}

// Dosya içeriğini güncelleyen fonksiyon
void dosya_guncelle() {
    char dosya_adi[MAX_DOSYA_ADI];
    char metin[MAX_METIN];
    int secim;
    FILE *dosya;
    
    printf("\n----- DOSYA GÜNCELLE -----\n");
    
    // Dosya adını al
    printf("Güncellenecek dosyanın adını girin: ");
    scanf(" %99[^\n]", dosya_adi);
    
    // Dosya var mı kontrol et
    dosya = fopen(dosya_adi, "r");
    if (dosya == NULL) {
        printf("Hata: %s dosyası bulunamadı!\n", dosya_adi);
        return;
    }
    fclose(dosya);
    
    printf("Güncelleme seçeneği:\n");
    printf("1. Dosyayı tamamen yeniden yaz\n");
    printf("2. Dosyanın sonuna ekle\n");
    printf("Seçiminiz (1-2): ");
    scanf("%d", &secim);
    
    if (secim == 1) {
        // Dosyayı yazma modunda aç (içeriği siler)
        dosya = fopen(dosya_adi, "w");
    } else if (secim == 2) {
        // Dosyayı ekleme modunda aç
        dosya = fopen(dosya_adi, "a");
    } else {
        printf("Geçersiz seçim!\n");
        return;
    }
    
    if (dosya == NULL) {
        printf("Hata: Dosya açılamadı!\n");
        return;
    }
    
    // Yazılacak metni al
    printf("Yazılacak metni girin:\n");
    scanf(" %999[^\n]", metin);
    
    // Metni dosyaya yaz
    fprintf(dosya, "%s", metin);
    fclose(dosya);
    
    printf("Dosya başarıyla güncellendi: %s\n", dosya_adi);
}

// Dosyayı silen fonksiyon
void dosya_sil() {
    char dosya_adi[MAX_DOSYA_ADI];
    char onay;
    
    printf("\n----- DOSYA SİL -----\n");
    
    // Dosya adını al
    printf("Silinecek dosyanın adını girin: ");
    scanf(" %99[^\n]", dosya_adi);
    
    // Dosya var mı kontrol et
    FILE *dosya = fopen(dosya_adi, "r");
    if (dosya == NULL) {
        printf("Hata: %s dosyası bulunamadı!\n", dosya_adi);
        return;
    }
    fclose(dosya);
    
    // Onay al
    printf("DİKKAT: %s dosyası silinecek! Onaylıyor musunuz? (e/h): ", dosya_adi);
    scanf(" %c", &onay);
    
    if (onay == 'e' || onay == 'E') {
        if (remove(dosya_adi) == 0) {
            printf("Dosya başarıyla silindi: %s\n", dosya_adi);
        } else {
            printf("Hata: Dosya silinemedi!\n");
        }
    } else {
        printf("Dosya silme işlemi iptal edildi.\n");
    }
} 