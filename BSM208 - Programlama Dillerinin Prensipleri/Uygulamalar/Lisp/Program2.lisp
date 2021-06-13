;KULLANICIDAN VERİ ALMA
(Defun Kare()
(print "x:")
(setq x (read))

(print "y:")
(setq y (read))
	(print "x^2+y^2=")
	(+ (* x x) (* y y))
)


;IF KOSUL KULLANIMI
(Defun Gencmi(yas)
	(if (and (> yas 10) (< yas 40)) T nil)
)


;FOR DONGU KULLANIMI
(Defun Artan(sayi)
	(loop for i from 1 to sayi do (print i))
)
;GERİYE DOĞRU YALNIZCA TEK SAYILARI YAZAN FOR DONGU ORNEGI
(Defun AzalanTek(sayi)
	(loop for i from sayi downto 1 do 
		(if (/= (mod i 2) 0) (print i))
	)
)


;UNTIL DONGU KULLANIMI
(Defun Faktoriyel(x)
	(setq sonuc 1)
	(loop until (< x 2) do 
		(setq sonuc (* sonuc x))
		(decf x)
	)
	sonuc
)


;OZYINELEME KULLANIMI
(Defun Fib(x)
	(if (< x 2) x 
		(+ (Fib (- x 2)) (Fib (decf x)))
	)
)


;WHILE DONGU KULLANIMI
(Defun Fib2(x)
	(setq onceki 0)
	(setq simdiki 1)
	(setq i 1)
	(loop while (< i x) do
		(setq toplam (+ onceki simdiki))
		(setq onceki simdiki)
		(setq simdiki toplam)
		(incf i)
	)
	toplam
)


;OPSİYONEL PARAMETRE GİRME (X ZORUNLU, Y VE Z ZORUNLU DEĞİL)
(Defun Fonk(x &optional y z)
	(list x y z)
)
;OPSİYONEL PARAMETRE GİRME (ÖNCEKİ ÖRNEKTE X VE Z GİRİLEMEZKEN BURADA GİRİLEBİLİR,
;PARAMETRE GİRERKEN ":x 6 :z 8" GİBİ GİRİLMELİ
;ORN: (Fonk2 :x 6 :z 8))
(Defun Fonk2(&key x y z)
	(list x y z)
)


;STRING BİRLEŞTİRME
(Defun Birlestir(isim)
	(setq nick (concatenate 'string isim "2021"))
	nick
)


;LİSTENİN BELİRLİ BİR İNDEKSİNE ELEMAN EKLEME (2. İNDEKSE İSE KONUM 3 GİRİLİR | DETAY NOTTA |)
(Defun Ekle(liste konum eleman)
	(push eleman (cdr (nthcdr konum liste)))
	liste
)
;LİSTENİN BELİRLİ BİR İNDEKSİNDEN ELEMAN SİLME
(Defun Silme(liste konum)
	(delete (first (subseq liste konum)) liste)
	liste
)