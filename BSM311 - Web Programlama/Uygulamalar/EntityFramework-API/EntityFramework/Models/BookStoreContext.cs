using System;
using Microsoft.EntityFrameworkCore;

namespace EntityFramework.Models
{
    public class BookStoreContext:DbContext
    {
        public DbSet<Author> Authors { get; set; }
        public DbSet<Book> Books { get; set; }

        public BookStoreContext(DbContextOptions<BookStoreContext> options):base(options)
        {

        }
    }
}