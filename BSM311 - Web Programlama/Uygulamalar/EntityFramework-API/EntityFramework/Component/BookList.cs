using System;
using System.Linq;
using System.Threading.Tasks;
using EntityFramework.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace EntityFramework.Component
{
    public class BookList : ViewComponent
    {
        private readonly BookStoreContext db;

        public BookList (BookStoreContext context)
        {
            db = context;
        }

        public async Task<IViewComponentResult> InvokeAsync(int id)
        {
            var books = db.Books.Where(x => x.AuthorId==id).ToListAsync();
            return View(await books);
        }
    }
}
