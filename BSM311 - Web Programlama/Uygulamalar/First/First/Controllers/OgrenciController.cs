using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using First.Models;
using Microsoft.AspNetCore.Mvc;

// For more information on enabling MVC for empty projects, visit https://go.microsoft.com/fwlink/?LinkID=397860

namespace First.Controllers
{
    public class OgrenciController : Controller
    {
        static List<Ogrenci> students = new List<Ogrenci>(); //static cunku her sayfa yenilenmesinde liste sıfırdan olusmasın diye
        
        public IActionResult Index()
        {
            return View();
        }
        [HttpPost]
        public string Kaydet(string OgrAd, string OgrSoyad, string OgrNo)
        {
            string txt = OgrAd + " " + OgrSoyad + " " + OgrNo;

            return txt;
        }
        [HttpPost]
        public IActionResult Kaydet2(Ogrenci ogr)
        {
            students.Add(ogr);
            //return View(ogr);
            return RedirectToAction("OgrenciListele", "Ogrenci");
        }

        public IActionResult OgrenciListele()
        {
            return View(students);
        }

        public string OgrDuzenle(int id)
        {
            string txt = "duzenlenecek kisiye ait deger "+id;
            return txt;
        }
    }
}
