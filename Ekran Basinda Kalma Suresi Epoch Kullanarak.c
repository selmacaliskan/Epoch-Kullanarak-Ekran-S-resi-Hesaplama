#include <stdio.h>
#include <time.h>

// Tarih ve zaman yapıları
struct tarih {
    int gun;
    int ay;
    int yil;
};

// Zamanı tutacak union
union zaman {
    int saat;
    int dakika;
    int saniye;
};

// Zamanı saniyeye çeviren fonksiyon
int zamani_saniyeye_cevir(int saat, int dakika, int saniye) {
    return saat * 3600 + dakika * 60 + saniye;
}

// Ekranda kalma süresi hesaplamak için zaman farkını veren fonksiyon
void ekran_suresini_hesapla(time_t baslangic_zamani) {
    // Program bitiş zamanını al
    time_t bitis_zamani = time(NULL);
    
    if (bitis_zamani == -1) {
        printf("Zaman alınamadı!\n");
        return;
    }

    // Geçen süreyi hesapla
    double fark = difftime(bitis_zamani, baslangic_zamani);
    
    printf("\nEkranda kalma suresi: %.0f saniye\n", fark);
}

int main() {
    time_t baslangic_zamani;
    baslangic_zamani = time(NULL);  // Programın başlangıç zamanını al

    if (baslangic_zamani == -1) {
        printf("Zaman alınamadı!\n");
        return 1;
    }

    struct tarih birinci_tarih, ikinci_tarih;
    union zaman birinci_zaman, ikinci_zaman; // union kullanıldı
    int saat, dakika, saniye;

    // İlk tarihi al
    printf("Lutfen bir gun giriniz (1-31): ");
    scanf("%d", &birinci_tarih.gun);
    printf("Lutfen bir ay giriniz (1-12): ");
    scanf("%d", &birinci_tarih.ay);
    printf("Lutfen bir yil giriniz: ");
    scanf("%d", &birinci_tarih.yil);
    
    printf("Lutfen bir saat giriniz (0-23): ");
    scanf("%d", &saat);
    printf("Lutfen bir dakika giriniz (0-59): ");
    scanf("%d", &dakika);
    printf("Lutfen bir saniye giriniz (0-59): ");
    scanf("%d", &saniye);

    birinci_zaman.saat = saat;
    birinci_zaman.dakika = dakika;
    birinci_zaman.saniye = saniye;  // union içinde sırasıyla kullanıyoruz

    // İkinci tarihi al
    printf("\nIkinci tarihi giriniz:\n");
    printf("Lutfen bir gun giriniz (1-31): ");
    scanf("%d", &ikinci_tarih.gun);
    printf("Lutfen bir ay giriniz (1-12): ");
    scanf("%d", &ikinci_tarih.ay);
    printf("Lutfen bir yil giriniz: ");
    scanf("%d", &ikinci_tarih.yil);
    
    printf("Lutfen bir saat giriniz (0-23): ");
    scanf("%d", &saat);
    printf("Lutfen bir dakika giriniz (0-59): ");
    scanf("%d", &dakika);
    printf("Lutfen bir saniye giriniz (0-59): ");
    scanf("%d", &saniye);

    ikinci_zaman.saat = saat;
    ikinci_zaman.dakika = dakika;
    ikinci_zaman.saniye = saniye;

    // Tarihleri struct tm'ye çevir
    struct tm t1 = {0}, t2 = {0};

    t1.tm_mday = birinci_tarih.gun;
    t1.tm_mon = birinci_tarih.ay - 1;
    t1.tm_year = birinci_tarih.yil - 1900;
    t1.tm_hour = birinci_zaman.saat;
    t1.tm_min = birinci_zaman.dakika;
    t1.tm_sec = birinci_zaman.saniye;

    t2.tm_mday = ikinci_tarih.gun;
    t2.tm_mon = ikinci_tarih.ay - 1;
    t2.tm_year = ikinci_tarih.yil - 1900;
    t2.tm_hour = ikinci_zaman.saat;
    t2.tm_min = ikinci_zaman.dakika;
    t2.tm_sec = ikinci_zaman.saniye;

    // Epoch zamanlarını hesapla
    time_t epoch1 = mktime(&t1);
    time_t epoch2 = mktime(&t2);

    if (epoch1 == -1 || epoch2 == -1) {
        printf("Gecersiz tarih girdiniz!\n");
        return 1;
    }

    // Farkı hesapla
    double fark = difftime(epoch2, epoch1);

    printf("\nTarih farkinin epoch degeri: %.0f saniye\n", fark);

    // Ekranda kalma süresini hesapla
    ekran_suresini_hesapla(baslangic_zamani);

    return 0;
}
