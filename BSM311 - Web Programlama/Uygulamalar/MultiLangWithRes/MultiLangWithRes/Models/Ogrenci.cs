using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Threading.Tasks;

namespace MultiLangWithRes.Models
{
    public class Ogrenci
    {
        [Required(ErrorMessage="Lütfen Ad Alanını Giriniz")]
        [Display(Name ="Öğrenci Ad")]
        public string Ad { get; set; }
        [RegularExpression("^[a-zA-Z0-9_\\.-]+@([a-zA-Z0-9-]+\\.)+[a-zA-Z]{2,6}$", ErrorMessage = "Geçersiz Mail")]
        [Required(ErrorMessage = "Lütfen Mail Alanını Giriniz")]
        [Display(Name = "Öğrenci Mail Adres")]
        public string Email { get; set; }
        [Display(Name = "Öğrenci Doğum Tarihi")]
        public DateTime DogumTarihi { get; set; }
    }
}