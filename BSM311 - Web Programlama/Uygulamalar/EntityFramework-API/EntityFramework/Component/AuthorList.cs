using System;
using System.Threading.Tasks;
using EntityFramework.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace EntityFramework.Component
{
    public class AuthorList : ViewComponent
    {
        private readonly BookStoreContext db;

        public AuthorList(BookStoreContext context)
        {
            db = context;
        }

        public async Task<IViewComponentResult> InvokeAsync()
        {
            var aut = db.Authors.ToListAsync();
            return View(await aut);
        }
    }
}
