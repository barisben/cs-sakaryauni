using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;

namespace EntityFramework.Models
{
    public class Author
    {
        [Key]
        public int AuthorId { get; set; }
        [Required(ErrorMessage ="Bu alan zorunlu.")]
        [Display(Name ="Yazar Adı")]
        public string AuthorFName { get; set; }
        [Display(Name = "Yazar Soyadı")]
        [MaxLength(50, ErrorMessage="En fazla 50 karakter girebilirsiniz.")]
        public string AuthorLName { get; set; }
        public string AuthorAddress { get; set; }
        //[Range(18, 100, ErrorMessage ="Yaş aralığı dışındadır.")]
        public int AuthorAge { get; set; }
        public ICollection<Book> Book { get; set; }
    }
}