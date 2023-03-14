using System;
using Microsoft.AspNetCore.Mvc;

namespace ViewComponentProject.Component
{
    public class SehirListele : ViewComponent
    {
        public IViewComponentResult Invoke()
        {
            return View();
        }
    }
}
