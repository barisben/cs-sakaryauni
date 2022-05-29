using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using EntityFramework.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

// For more information on enabling MVC for empty projects, visit https://go.microsoft.com/fwlink/?LinkID=397860

namespace EntityFramework.Controllers
{
    public class BookManuelController : Controller
    {
        private readonly BookStoreContext db;

        public BookManuelController(BookStoreContext bs)
        {
            db = bs;
        }

        // GET: /<controller>/
        public IActionResult Index()
        {
            List<Book> b = db.Books.Include(bk => bk.Auth).ToList();

            var b2 = (from bk in db.Books where bk.Auth != null select bk).ToList();

            var b3 = (from bk in db.Books where bk.BookTitle.Contains("suc") select bk).ToList();

            var b4 = db.Books.Where(x => x.BookTitle.Contains("suc")).ToList();

            var b5 = db.Books.Where(x => x.Auth.AuthorAge > 40).OrderByDescending(x => x.Auth.AuthorAge).ToList();

            var b6 = (from t in db.Books where t.Auth.AuthorAge > 40 orderby t.Auth.AuthorAge descending select t).ToList();

            var yas = db.Authors.Where(x => x.Book.Count > 0).Select(x => x.AuthorAge).Sum();

            var b7 = (from a in db.Authors
                      join bk in db.Books
                      on a.AuthorId equals bk.AuthorId
                      select new
                      {
                          YazarAd = a.AuthorFName + " " + a.AuthorLName,
                          KitapAdi = bk.BookTitle
                      }).ToList();

            return View(b2);
        }
    }
}