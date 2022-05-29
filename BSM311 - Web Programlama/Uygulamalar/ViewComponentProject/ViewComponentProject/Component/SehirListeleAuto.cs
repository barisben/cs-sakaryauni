using System;
using System.Collections.Generic;
using System.Linq;
using Microsoft.AspNetCore.Mvc;

namespace ViewComponentProject.Component
{
    public class SehirListeleAuto : ViewComponent
    {
        /*
        public IViewComponentResult Invoke()
        {
            List<string> sehirler = new List<string>() { "Ankara", "Bursa", "İzmir" };
            return View(sehirler);
        }
        */

        public IViewComponentResult Invoke(string s)
        {
            List<string> sehirler = s.Split(";").ToList();
            return View(sehirler);
        }
    }
}