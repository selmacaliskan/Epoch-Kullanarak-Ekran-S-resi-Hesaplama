# İki Tarih Arasındaki Farkı ve Çalışma Süresini Hesaplayan C Programı

Bu C programı, kullanıcının girdiği iki farklı tarih ve saat arasındaki zaman farkını saniye cinsinden hesaplar. Ayrıca programın ne kadar süre çalıştığını da hesaplar.

## Açıklama

Program, `time.h` kütüphanesini kullanarak tarih ve zaman işlemleri gerçekleştirir. Kullanıcıdan iki farklı tarih (gün, ay, yıl) ve saat (saat, dakika, saniye) bilgisi alınır. Bu bilgiler, Unix zamanına (epoch) çevrilerek iki tarih arasındaki fark saniye cinsinden hesaplanır. Programın başlangıç ve bitiş zamanları da kaydedilerek ne kadar süre çalıştığı hesaplanır.

## Kullanım

1.  Programı derleyin:

    ```bash
    gcc tarih_farki.c -o tarih_farki
    ```

2.  Çalıştırılabilir dosyayı çalıştırın:

    ```bash
    ./tarih_farki
    ```

3.  Program, sizden ilk tarih ve saat bilgilerini girmenizi isteyecektir. Lütfen bilgileri istenen formatta girin.

4.  Ardından, ikinci tarih ve saat bilgilerini girin.

5.  Program, iki tarih arasındaki farkı saniye cinsinden ve programın çalışma süresini gösterecektir.

## Örnek

Lutfen bir gun giriniz (1-31): 15

Lutfen bir ay giriniz (1-12): 05

Lutfen bir yil giriniz: 2024

Lutfen bir saat giriniz (0-23): 10

Lutfen bir dakika giriniz (0-59): 30

Lutfen bir saniye giriniz (0-59): 00

Ikinci tarihi giriniz:
Lutfen bir gun giriniz (1-31): 20

Lutfen bir ay giriniz (1-12): 05

Lutfen bir yil giriniz: 2024

Lutfen bir saat giriniz (0-23): 12

Lutfen bir dakika giriniz (0-59): 00

Lutfen bir saniye giriniz (0-59): 00

Tarih farkinin epoch degeri: 12600 saniye

Ekranda kalma suresi: 5 saniye


## Kod Yapısı

*   `tarih` adında bir struct (yapı) tanımlanır. Bu yapı, gün, ay ve yıl bilgilerini tutar.
*   `zaman` adında bir union (birlik) tanımlanır. Bu union, farklı zaman birimlerini (bu kodda saat, dakika ve saniye) tutmak için kullanılır.
*   `zamani_saniyeye_cevir` fonksiyonu, verilen saat, dakika ve saniye bilgilerini toplam saniye sayısına çevirir.
*   `ekran_suresini_hesapla` fonksiyonu, programın başlangıç ve bitiş zamanlarını kullanarak çalışma süresini hesaplar.
*   `main` fonksiyonu, kullanıcıdan tarih ve saat bilgilerini alır, bu bilgileri `struct tm` yapısına dönüştürür, Unix zamanına çevirir, iki tarih arasındaki farkı hesaplar ve sonuçları ekrana yazdırır.

## Bağımlılıklar

*   Bu program, herhangi bir harici kütüphaneye bağımlı değildir.

## Katkıda Bulunma

Katkıda bulunmak isterseniz, lütfen bir "pull request" gönderin veya bir "issue" oluşturun.

## Lisans

Bu proje, MIT Lisansı altında lisanslanmıştır.
