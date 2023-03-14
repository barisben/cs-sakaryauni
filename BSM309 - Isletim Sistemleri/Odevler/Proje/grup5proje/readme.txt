İşletim Sistemleri Shell Proje Ödevi

Grup No: 5
Barış Yılmaz G191210303
Sultan Çepni B171210096
Gürkan Aslanoğlu G181210375
Ayşe Merve Candaş G071210012
Muhammed Fatih Baykal B181210012


İlk olarak main fonksiyonu parametreleri yardımıyla kullanıcının txt dosyası açıp açmayacağını belirledik. 

Eğer kullanıcı programı batch modunda açmak istiyorsa argv parametresinden kullanıcının girdiği dosya adını alıp
fopen ile açtıktan sonra her satırı bir değişkene atadık. Daha sonra bu değişkendeki her komutu sonsuz while döngüsü
içinde çalışmasını sağladık.

Kullanıcı programı interaktif modda açtıysa kullanıcıdan bir input istedik ve aldığımız bu inputu strtok fonksiyonu
yardımıyla parçalara ayırıp iki boyutlu bir diziye aktardık. Bu ayırma işleminde aynı zamanda kullanıcının komutu
arka planda veya eş zamanlı olarak çalıştırmak isteyip istemediğini kontrol ettik. 

Son olarak komutlar icra etme kısmında ise fork ile programı proseslere ayırarak çocuk proseslerin içinde komutları
çalıştırdık. Eğer komut arka planda çalışacak ise ebeveyn prosesin içinde waitpid kullanmayarak komutun arkaplanda çalışmasını sağladık. 
Daha sonra SIGCHLD sinyali ile de arka planda kapanan prosesi tamamen yok ettik.

Kullanıcının girdiği komutlardaki belirsizliği (ls ;;; ps gibi) yok etmek için aldığımız inputun içinde for döngüsü
ile dolaşarak art arda gelen noktalı virgülleri yok ettik ve komutların düzgün çalışmasını sağladık.
