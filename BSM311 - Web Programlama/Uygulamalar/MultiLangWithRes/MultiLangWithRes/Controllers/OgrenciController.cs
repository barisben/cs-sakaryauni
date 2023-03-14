using Microsoft.AspNetCore.Mvc;
using MultiLangWithRes.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace MultiLangWithRes.Controllers
{
    public class OgrenciController : Controller
    {
        public IActionResult Index()
        {
            return View();
        }

        [HttpPost]
        public IActionResult Index([Bind("Ad,Email,DogumTarihi")] Ogrenci ogr)
        {
            return View();
        }
    }
}
