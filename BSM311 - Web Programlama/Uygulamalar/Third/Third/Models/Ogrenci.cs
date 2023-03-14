using System;
using System.ComponentModel.DataAnnotations;

namespace Third.Models
{
    public enum Bolum
    {
        Bilgisayar,
        Elektrik,
        Makine
    }

    public class Ogrenci
    {
        [Required(ErrorMessage = "Lütfen AD alanını bos birakmayiniz.")]
        [StringLength(20)]
        [Display(Name = "Öğrenci Ad")]
        public string OgrAd { get; set; }

        [Required(ErrorMessage = "Lütfen SOYAD alanını bos birakmayiniz.")]
        [Display(Name = "Öğrenci Soyad")]
        public string OgrSoyad { get; set; }

        [EmailAddress(ErrorMessage = "Gecerli bir mail adresi giriniz.")]
        [Display(Name = "Öğrenci Mail")]
        public string OgrMail { get; set; }

        [Phone(ErrorMessage = "Gecerli bir telefon numarasi giriniz.")]
        [Display(Name = "Öğrenci Telefon")]
        public string OgrTel { get; set; }

        [Display(Name = "Öğrenci Bolum")]
        public Bolum OgrBolum { get; set; }
    }
}
