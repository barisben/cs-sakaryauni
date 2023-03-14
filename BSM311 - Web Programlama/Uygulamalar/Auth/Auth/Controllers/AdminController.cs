using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Auth.Controllers
{
    public class AdminController : Controller
    {
        [Authorize(Roles="Admin")]
        public IActionResult Index()
        {
            return View();
        }
    }
}
