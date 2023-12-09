#UYGULAMA
---
Kodumuzun ve uygulamamızın amacı, herhangi bir input dosyası içerisinde yer alan yazı/ların kullanıcı tarafından belirtilen anahtar değeri çerçevesinde 26 harflik İngiliz alfabesine göre şifrelenmesini sağlamaktır.

Öncelikle karşımıza bilgilendirme adına yazılmış bir ana ve bir yan olmak üzere iki başlık çıkıyor ve ne yapmamız gerektiğini belirtiyor.

Sonrasında girdiğimiz dosya adı, programın olduğu dizin içerisinde aranıyor ve bulnuyor. Eğer bulunamazsa, bizi bir uyarı mesajı karşılıyor.

Dosya bulunduktan sonra, dosya içerisindeki yazı sistem tarafından okunuyor ve kapatılıyor.

Girilen anahtar değerine göre bir şifreleme algoritması oluşturuluyor.

Eğer uç harflerden biri varsa ve anahtar değeri ile birlikte mevcut işlem uygulandığında 26 harflik alfabenin sonunu da geçiyorsa, alfabenin başına yani "a" harfine geri yönlendiriliyoruz.

Bu işlemi eğer anahtar değeri olağandan yüksek bir değer girilirse yine tekrarlamış oluyoruz.
