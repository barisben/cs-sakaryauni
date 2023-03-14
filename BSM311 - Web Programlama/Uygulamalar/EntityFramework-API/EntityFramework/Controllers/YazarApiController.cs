using EntityFramework.Models;
using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

// For more information on enabling Web API for empty projects, visit https://go.microsoft.com/fwlink/?LinkID=397860

namespace EntityFramework.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class YazarApiController : ControllerBase
    {
        private readonly BookStoreContext db;

        public YazarApiController(BookStoreContext _db)
        {
            db = _db;
        }

        // GET: api/<YazarApiController>
        [HttpGet]
        public List<Author> Get()
        {
            return db.Authors.ToList();
        }

        // GET api/<YazarApiController>/5
        [HttpGet("{id}")]
        public Author Get(int id)
        {
            return db.Authors.FirstOrDefault(x => x.AuthorId == id);
        }

        // POST api/<YazarApiController>
        [HttpPost]
        public void Post([FromBody] Author a)
        {
            db.Authors.Add(a);
            db.SaveChanges();
        }

        // PUT api/<YazarApiController>/5
        [HttpPut("{id}")]
        public IActionResult Put(int id, [FromBody] Author a)
        {
            var author = db.Authors.FirstOrDefault(x => x.AuthorId == id);
            if (author != null)
            {
                author.AuthorFName = a.AuthorFName;
                author.AuthorLName = a.AuthorLName;
                db.Update(author);
                db.SaveChanges();
                return Ok();
            }
            else
            {
                return NotFound();
            }
        }

        // DELETE api/<YazarApiController>/5
        [HttpDelete("{id}")]
        public IActionResult Delete(int id)
        {
            var author = db.Authors.FirstOrDefault(x => x.AuthorId == id);
            if (author != null)
            {
                db.Authors.Remove(author);
                db.SaveChanges();
                return Ok();
            }
            else
            {
                return NotFound();
            }
        }
    }
}
