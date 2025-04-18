# C-Basic

Temel C programlama örneklerini içeren basit projeler koleksiyonu.

## Projeler

Bu repo aşağıdaki basit C projelerini içermektedir:

1. **Öğrenci İstatistik** (`ogrenci_istatistik.c`)
   - Sınıftaki öğrencilerin notlarını alır
   - Sınıf ortalamasını hesaplar
   - Standart sapmayı hesaplar
   - Harf notlarını belirler (AA, BA, BB, vb.)

2. **Hesap Makinesi** (`hesap_makinesi.c`)
   - Toplama, çıkarma, çarpma, bölme işlemleri
   - Üs alma ve karekök fonksiyonları
   - Kullanıcı dostu menü sistemi

3. **Taş Kağıt Makas** (`tas_kagit_makas.c`)
   - Bilgisayara karşı oynanan klasik oyun
   - Skor takip sistemi
   - Rastgele bilgisayar seçimleri

4. **Dosya Yöneticisi** (`dosya_yoneticisi.c`)
   - Dosya oluşturma, okuma, güncelleme ve silme işlemleri
   - Metin dosyaları yönetimi
   - Kullanıcı dostu arayüz

5. **Telefon Rehberi** (`telefon_rehberi.c`)
   - Kişi ekleme, listeleme, arama
   - Kişi düzenleme ve silme
   - Rehberi dosyada saklama ve yükleme

6. **Adam Asmaca** (`adam_asmaca.c`)
   - Kelime tahmin oyunu
   - Görsel adam asmaca çizimi
   - Rastgele kelime seçimi

## Kurulum ve Çalıştırma

Projeleri çalıştırmak için bir C derleyicisine ihtiyacınız vardır (örn. GCC).

```bash
# Derlemek için
gcc [dosya_adi].c -o [program_adi] -lm

# Örnek
gcc ogrenci_istatistik.c -o ogrenci_istatistik -lm

# Çalıştırmak için
./[program_adi]

# Örnek
./ogrenci_istatistik
```

Not: Windows kullanıcıları için çalıştırma komutu:
```bash
[program_adi].exe

# Örnek
ogrenci_istatistik.exe
```

## Gereksinimler

- C derleyicisi (GCC önerilir)
- Standard C kütüphaneleri

## Katkıda Bulunma

1. Bu repo'yu fork edin
2. Yeni bir branch oluşturun (`git checkout -b yeni-ozellik`)
3. Değişikliklerinizi commit edin (`git commit -am 'Yeni özellik ekle'`)
4. Branch'inizi push edin (`git push origin yeni-ozellik`)
5. Pull request oluşturun

## Lisans

Bu projeler eğitim amaçlıdır ve açık kaynak olarak paylaşılmaktadır.

## İletişim

- GitHub: [@tahamhl](https://github.com/tahamhl) 