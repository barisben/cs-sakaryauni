using DependencyInjection.Models;
using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace DependencyInjection.Controllers
{
    public class OgrenciController : Controller
    {
        IMesaj m;
        public OgrenciController(IMesaj msg)
        {
            this.m = msg;
        }
        public string Index()
        {
            m.MesajAt("Kaydınız başarılı.");
            return m.MesajLog();
        }
    }
}
