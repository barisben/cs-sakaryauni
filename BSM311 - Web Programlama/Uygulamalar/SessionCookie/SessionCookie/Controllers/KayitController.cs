using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace SessionCookie.Controllers
{
    public class KayitController : Controller
    {
        public IActionResult Index()
        {
            return View();
        }
    }
}
