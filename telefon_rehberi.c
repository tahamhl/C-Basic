#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KISI 100
#define MAX_AD_UZUNLUK 50
#define MAX_TEL_UZUNLUK 15

// Kişi yapısı
typedef struct {
    char ad[MAX_AD_UZUNLUK];
    char telefon[MAX_TEL_UZUNLUK];
    char eposta[MAX_AD_UZUNLUK];
} Kisi;

// Rehber yapısı
typedef struct {
    Kisi kisiler[MAX_KISI];
    int kisi_sayisi;
} Rehber;

// Fonksiyon prototipleri
void menu_goster();
void kisi_ekle(Rehber *rehber);
void kisileri_listele(Rehber rehber);
void kisi_ara(Rehber rehber);
void kisi_duzenle(Rehber *rehber);
void kisi_sil(Rehber *rehber);
void rehberi_kaydet(Rehber rehber);
void rehberi_yukle(Rehber *rehber);

int main() {
    Rehber rehber;
    rehber.kisi_sayisi = 0;
    int secim;
    
    // Varsa kayıtlı rehberi yükle
    rehberi_yukle(&rehber);
    
    while (1) {
        menu_goster();
        printf("Seçiminiz (0-6): ");
        scanf("%d", &secim);
        
        switch (secim) {
            case 0:
                // Çıkmadan önce rehberi kaydet
                rehberi_kaydet(rehber);
                printf("Program sonlandırılıyor...\n");
                return 0;
            case 1:
                kisi_ekle(&rehber);
                break;
            case 2:
                kisileri_listele(rehber);
                break;
            case 3:
                kisi_ara(rehber);
                break;
            case 4:
                kisi_duzenle(&rehber);
                break;
            case 5:
                kisi_sil(&rehber);
                break;
            case 6:
                rehberi_kaydet(rehber);
                printf("Rehber başarıyla kaydedildi.\n");
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
    printf("----- TELEFON REHBERİ -----\n");
    printf("1. Kişi Ekle\n");
    printf("2. Kişileri Listele\n");
    printf("3. Kişi Ara\n");
    printf("4. Kişi Düzenle\n");
    printf("5. Kişi Sil\n");
    printf("6. Rehberi Kaydet\n");
    printf("0. Çıkış\n");
}

// Yeni kişi ekleyen fonksiyon
void kisi_ekle(Rehber *rehber) {
    if (rehber->kisi_sayisi >= MAX_KISI) {
        printf("Hata: Rehber dolu! Yeni kişi ekleyemezsiniz.\n");
        return;
    }
    
    Kisi yeni_kisi;
    
    printf("\n----- KİŞİ EKLE -----\n");
    
    // Kişi bilgilerini al
    printf("Ad Soyad: ");
    scanf(" %49[^\n]", yeni_kisi.ad);
    
    printf("Telefon: ");
    scanf(" %14[^\n]", yeni_kisi.telefon);
    
    printf("E-posta: ");
    scanf(" %49[^\n]", yeni_kisi.eposta);
    
    // Kişiyi rehbere ekle
    rehber->kisiler[rehber->kisi_sayisi] = yeni_kisi;
    rehber->kisi_sayisi++;
    
    printf("Kişi başarıyla eklendi.\n");
}

// Tüm kişileri listeleyen fonksiyon
void kisileri_listele(Rehber rehber) {
    printf("\n----- KİŞİ LİSTESİ (%d kişi) -----\n", rehber.kisi_sayisi);
    
    if (rehber.kisi_sayisi == 0) {
        printf("Rehberde kayıtlı kişi bulunmamaktadır.\n");
        return;
    }
    
    printf("%-4s %-30s %-15s %-30s\n", "No", "Ad Soyad", "Telefon", "E-posta");
    printf("----------------------------------------------------------------------\n");
    
    for (int i = 0; i < rehber.kisi_sayisi; i++) {
        printf("%-4d %-30s %-15s %-30s\n", i+1, 
               rehber.kisiler[i].ad, 
               rehber.kisiler[i].telefon, 
               rehber.kisiler[i].eposta);
    }
}

// Kişi arayan fonksiyon
void kisi_ara(Rehber rehber) {
    char arama_metni[MAX_AD_UZUNLUK];
    int bulunan = 0;
    
    printf("\n----- KİŞİ ARA -----\n");
    
    if (rehber.kisi_sayisi == 0) {
        printf("Rehberde kayıtlı kişi bulunmamaktadır.\n");
        return;
    }
    
    printf("Arama metni: ");
    scanf(" %49[^\n]", arama_metni);
    
    printf("\n----- ARAMA SONUÇLARI -----\n");
    printf("%-4s %-30s %-15s %-30s\n", "No", "Ad Soyad", "Telefon", "E-posta");
    printf("----------------------------------------------------------------------\n");
    
    for (int i = 0; i < rehber.kisi_sayisi; i++) {
        // Büyük/küçük harf duyarsız arama
        if (strstr(rehber.kisiler[i].ad, arama_metni) != NULL || 
            strstr(rehber.kisiler[i].telefon, arama_metni) != NULL || 
            strstr(rehber.kisiler[i].eposta, arama_metni) != NULL) {
            
            printf("%-4d %-30s %-15s %-30s\n", i+1, 
                   rehber.kisiler[i].ad, 
                   rehber.kisiler[i].telefon, 
                   rehber.kisiler[i].eposta);
            bulunan++;
        }
    }
    
    if (bulunan == 0) {
        printf("Arama kriterine uygun kişi bulunamadı.\n");
    } else {
        printf("\nToplam %d kişi bulundu.\n", bulunan);
    }
}

// Kişi düzenleyen fonksiyon
void kisi_duzenle(Rehber *rehber) {
    int indeks;
    
    printf("\n----- KİŞİ DÜZENLE -----\n");
    
    if (rehber->kisi_sayisi == 0) {
        printf("Rehberde kayıtlı kişi bulunmamaktadır.\n");
        return;
    }
    
    // Tüm kişileri listele
    kisileri_listele(*rehber);
    
    printf("\nDüzenlenecek kişinin numarasını girin (1-%d): ", rehber->kisi_sayisi);
    scanf("%d", &indeks);
    
    if (indeks < 1 || indeks > rehber->kisi_sayisi) {
        printf("Hata: Geçersiz kişi numarası!\n");
        return;
    }
    
    indeks--; // Dizin 0'dan başladığı için
    
    printf("\nMevcut Bilgiler:\n");
    printf("Ad Soyad: %s\n", rehber->kisiler[indeks].ad);
    printf("Telefon: %s\n", rehber->kisiler[indeks].telefon);
    printf("E-posta: %s\n", rehber->kisiler[indeks].eposta);
    
    printf("\nYeni Bilgiler (değiştirmek istemediğiniz alanları boş bırakın):\n");
    
    char yeni_ad[MAX_AD_UZUNLUK] = "";
    char yeni_telefon[MAX_TEL_UZUNLUK] = "";
    char yeni_eposta[MAX_AD_UZUNLUK] = "";
    
    printf("Ad Soyad: ");
    getchar(); // Tampon temizleme
    fgets(yeni_ad, MAX_AD_UZUNLUK, stdin);
    yeni_ad[strcspn(yeni_ad, "\n")] = 0; // Sonundaki newline karakterini kaldır
    
    printf("Telefon: ");
    fgets(yeni_telefon, MAX_TEL_UZUNLUK, stdin);
    yeni_telefon[strcspn(yeni_telefon, "\n")] = 0;
    
    printf("E-posta: ");
    fgets(yeni_eposta, MAX_AD_UZUNLUK, stdin);
    yeni_eposta[strcspn(yeni_eposta, "\n")] = 0;
    
    // Boş olmayanları güncelle
    if (strlen(yeni_ad) > 0) {
        strcpy(rehber->kisiler[indeks].ad, yeni_ad);
    }
    
    if (strlen(yeni_telefon) > 0) {
        strcpy(rehber->kisiler[indeks].telefon, yeni_telefon);
    }
    
    if (strlen(yeni_eposta) > 0) {
        strcpy(rehber->kisiler[indeks].eposta, yeni_eposta);
    }
    
    printf("Kişi bilgileri başarıyla güncellendi.\n");
}

// Kişi silen fonksiyon
void kisi_sil(Rehber *rehber) {
    int indeks;
    char onay;
    
    printf("\n----- KİŞİ SİL -----\n");
    
    if (rehber->kisi_sayisi == 0) {
        printf("Rehberde kayıtlı kişi bulunmamaktadır.\n");
        return;
    }
    
    // Tüm kişileri listele
    kisileri_listele(*rehber);
    
    printf("\nSilinecek kişinin numarasını girin (1-%d): ", rehber->kisi_sayisi);
    scanf("%d", &indeks);
    
    if (indeks < 1 || indeks > rehber->kisi_sayisi) {
        printf("Hata: Geçersiz kişi numarası!\n");
        return;
    }
    
    indeks--; // Dizin 0'dan başladığı için
    
    printf("\nSilinecek Kişi:\n");
    printf("Ad Soyad: %s\n", rehber->kisiler[indeks].ad);
    printf("Telefon: %s\n", rehber->kisiler[indeks].telefon);
    printf("E-posta: %s\n", rehber->kisiler[indeks].eposta);
    
    printf("\nBu kişiyi silmek istediğinizden emin misiniz? (e/h): ");
    scanf(" %c", &onay);
    
    if (onay == 'e' || onay == 'E') {
        // Son kişi değilse, diğer kişileri kaydır
        if (indeks < rehber->kisi_sayisi - 1) {
            for (int i = indeks; i < rehber->kisi_sayisi - 1; i++) {
                rehber->kisiler[i] = rehber->kisiler[i + 1];
            }
        }
        
        rehber->kisi_sayisi--;
        printf("Kişi başarıyla silindi.\n");
    } else {
        printf("Silme işlemi iptal edildi.\n");
    }
}

// Rehberi dosyaya kaydeden fonksiyon
void rehberi_kaydet(Rehber rehber) {
    FILE *dosya = fopen("rehber.dat", "wb");
    
    if (dosya == NULL) {
        printf("Hata: Rehber dosyası oluşturulamadı!\n");
        return;
    }
    
    // Kişi sayısını yaz
    fwrite(&rehber.kisi_sayisi, sizeof(int), 1, dosya);
    
    // Kişileri yaz
    for (int i = 0; i < rehber.kisi_sayisi; i++) {
        fwrite(&rehber.kisiler[i], sizeof(Kisi), 1, dosya);
    }
    
    fclose(dosya);
}

// Rehberi dosyadan yükleyen fonksiyon
void rehberi_yukle(Rehber *rehber) {
    FILE *dosya = fopen("rehber.dat", "rb");
    
    if (dosya == NULL) {
        // Dosya yoksa yeni bir rehber oluştur
        rehber->kisi_sayisi = 0;
        return;
    }
    
    // Kişi sayısını oku
    fread(&rehber->kisi_sayisi, sizeof(int), 1, dosya);
    
    // Kişileri oku
    for (int i = 0; i < rehber->kisi_sayisi; i++) {
        fread(&rehber->kisiler[i], sizeof(Kisi), 1, dosya);
    }
    
    fclose(dosya);
    printf("Rehber dosyası başarıyla yüklendi. (%d kişi)\n", rehber->kisi_sayisi);
} 