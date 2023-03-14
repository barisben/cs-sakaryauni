using EntityFramework.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace EntityFramework.DA
{
    public class AuthorRepoConcrete : IAuthorRepo
    {
        private readonly BookStoreContext db;
        public AuthorRepoConcrete(BookStoreContext b)
        {
            db = b;
        }

        public Author CreateAuthor(Author a)
        {
            db.Authors.Add(a);
            db.SaveChanges();
            return a;
        }

        public void DeleteAuthor(int id)
        {
            var author = db.Authors.FirstOrDefault(x => x.AuthorId == id);
            db.Authors.Remove(author);
            db.SaveChanges();
        }

        public List<Author> GetAuthors()
        {
            return db.Authors.ToList();
        }

        public Author GetAuthorById(int id)
        {
            return db.Authors.FirstOrDefault(x => x.AuthorId == id);
        }

        public Author UpdateAuthor(int id, Author a)
        {
            var author= db.Authors.FirstOrDefault(x => x.AuthorId == id);
            author.AuthorFName = a.AuthorFName;
            db.Update(author);
            db.SaveChanges();
            return author;
        }
    }
}
