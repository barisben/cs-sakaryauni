using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Logging;
using SessionCookie.Models;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Threading.Tasks;

namespace SessionCookie.Controllers
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
            Ogrenci ogr = new Ogrenci() { OgrAd = "Baris", OgrNo = 10};
            

            HttpContext.Session.SetString("DogumYili", "2000");
            HttpContext.Session.SetInt32("Yas", 18);
            HttpContext.Session.SetObject<Ogrenci>("Ogrenci", ogr);
            if (!HttpContext.Request.Cookies.ContainsKey("WebId"))
            {
                HttpContext.Response.Cookies.Append("WebId", "10");
            }
            return View();
        }

        public string QueryStringTest()
        {
            string msg="";
            if (!string.IsNullOrEmpty(HttpContext.Request.Query["ad"]))
            {
                msg = "Merhaba " + HttpContext.Request.Query["ad"];
            }
            else
            {
                msg = "Herhangi bir ad yok.";
            }
            return msg;
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
    }
}
