using Microsoft.AspNetCore.Identity;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Threading.Tasks;

namespace Auth.Models
{
    public class OgrenciDetails:IdentityUser
    {
        [Display(Name = "İsim")]
        public string Ad { get; set; }
        public string Soyad { get; set; }
        [Display(Name = "Adres")]
        public string Adres { get; set; }
    }
}
