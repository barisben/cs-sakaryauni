using EntityFramework.Models;
using Microsoft.AspNetCore.Mvc;
using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Threading.Tasks;

namespace EntityFramework.Controllers
{
    public class CallApiController : Controller
    {
        private static readonly HttpClient client = new HttpClient();
        public async Task<IActionResult> Index()
        {
            List<Author> Authors = new List<Author>();
            var httpClient = new HttpClient();
            var response = await httpClient.GetAsync("http://localhost:44360/api/YazarApiController");
            string apiResponse = await response.Content.ReadAsStringAsync();
            Authors = JsonConvert.DeserializeObject<List<Author>> (apiResponse);
            return View(Authors);
        }
    }
}
