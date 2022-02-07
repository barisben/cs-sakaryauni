using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace DependencyInjection.Models
{
    public class Mail : IMesaj
    {
        public void MesajAt(string msj)
        {
            //mail atma kodları
        }

        public string MesajLog()
        {
            return "Mail atıldı.";
        }
    }
}
