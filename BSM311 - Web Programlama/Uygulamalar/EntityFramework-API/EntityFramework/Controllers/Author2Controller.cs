using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using EntityFramework.Models;
using Microsoft.AspNetCore.Mvc;

// For more information on enabling MVC for empty projects, visit https://go.microsoft.com/fwlink/?LinkID=397860

namespace EntityFramework.Controllers
{
    public class Author2Controller : Controller
    {
        private readonly BookStoreContext dbBook;

        public Author2Controller(BookStoreContext context)
        {
            dbBook = context;
        }

        // GET: /<controller>/
        public IActionResult Index()
        {
            List<Author> a = dbBook.Authors.ToList();
            return View(a);
        }
        public IActionResult Create()
        {
            return View();
        }
        [HttpPost]
        public IActionResult Create([Bind ("AuthorFName", "AuthorLName")]Author a)
        {
            dbBook.Add(a);
            dbBook.SaveChanges();
            return RedirectToAction("Index");
        }
    }
}
