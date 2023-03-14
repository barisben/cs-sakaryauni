(Defun Hesap(x y)
;Sayilarin toplami
(print "x+y:")
(setq sonuc (Topla x y))
(print sonuc)

(print "x-y:")
(setq sonuc (Cikar x y))
(print sonuc)

(print "x*y:")
(setq sonuc (Carp x y))
(print sonuc)

(print "x/y:")
;SON SATIRDAKİ KODU DÖNDÜRECEĞİ İÇİN 2 DEFA YAZACAK, HEM BİZ PRINT EDİYORUZ HEM HESAP DONDURUYOR
;(setq sonuc (Bol x y))
;(print sonuc)

;SON SATIRA PRINT VE SETQ KOYMUYORUZ Kİ 2 DEFA YAZMASIN
(Bol x y)
)

(Defun Topla(x y)
(+ x y)
)

(Defun Cikar(x y)
(- x y)
)

(Defun Carp(x y)
(* x y)
)

(Defun Bol(x y)
(/ x y)
)