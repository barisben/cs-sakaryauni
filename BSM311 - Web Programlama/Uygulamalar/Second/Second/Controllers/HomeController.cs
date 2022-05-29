using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Logging;
using Second.Models;

namespace Second.Controllers
{
    public class HomeController : Controller
    {
        private readonly ILogger<HomeController> _logger;

        public HomeController(ILogger<HomeController> logger)
        {
            _logger = logger;
        }

        public IActionResult Index()
        {
            return View();
        }

        public IActionResult Privacy()
        {
            return View();
        }

        [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
        public IActionResult Error()
        {
            return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
        }

        public IActionResult Deneme()
        {
            return View();
        }

        public IActionResult Deneme2()
        {
            ViewBag.msg = "ViewBag message";
            ViewData["msg2"] = "ViewData message";
            TempData["msg3"] = "TempData message";
            return RedirectToAction("Deneme3");
            //return View(ogr);
        }

        public IActionResult Deneme3()
        {
            string tmp=Convert.ToString(TempData["msg3"]);//controller to controller

            Ogrenci ogr = new Ogrenci();
            ogr.OgrAd = "Ali";
            ogr.OgrNo = 10;

            Bolum blm = new Bolum();
            blm.BolumAd = "Bilgisayar";
            blm.BolumId = 12;

            //TempData["blm"] = blm;

            OgrenciBolum OgrBlm = new OgrenciBolum();
            OgrBlm.ogr = ogr;
            OgrBlm.blm = blm;

            //return View(ogr);
            return View(OgrBlm);
        }
    }
}
