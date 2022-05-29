using System;
using System.ComponentModel.DataAnnotations;

namespace EntityFramework.Models
{
    public class Book
    {
        [Key]
        public int BookId { get; set; }
        public string BookTitle { get; set; }
        public int AuthorId { get; set; }
        public Author Auth { get; set; }
    }
}