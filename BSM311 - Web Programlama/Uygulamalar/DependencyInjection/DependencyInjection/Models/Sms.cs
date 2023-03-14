using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace DependencyInjection.Models
{
    public class Sms : IMesaj
    {
        public void MesajAt(string msj)
        {
            //sms atma kodları
        }

        public string MesajLog()
        {
            return "SMS atıldı.";
        }
    }
}
