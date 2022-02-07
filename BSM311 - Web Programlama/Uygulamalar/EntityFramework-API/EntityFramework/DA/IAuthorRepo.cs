using EntityFramework.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace EntityFramework.DA
{
    interface IAuthorRepo
    {
        public Author CreateAuthor(Author a);
        public List<Author> GetAuthors();
        public Author GetAuthorById(int id);
        public void DeleteAuthor(int id);
        public Author UpdateAuthor(int id, Author a);
    }
}
