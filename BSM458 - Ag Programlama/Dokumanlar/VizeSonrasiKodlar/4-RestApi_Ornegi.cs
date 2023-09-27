using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;

namespace LogToplamaServis.IsKatmani
{
    public enum httpVerb
    {
        GET,
        POST,
        PUT,
        DELETE
    }
    public class restClient
    {
        public string endPoint { get; set; }
        public httpVerb httpMethod { get; set; }

        public restClient()
        {
            endPoint = string.Empty;
            httpMethod = httpVerb.GET;
        }
        public string makeRequest()
        {
            string strResponseValue = string.Empty;

            HttpWebRequest request = (HttpWebRequest)WebRequest.Create(endPoint);

            request.Method = httpMethod.ToString();

            using (HttpWebResponse response = (HttpWebResponse)request.GetResponse())
            {
                if (response.StatusCode != HttpStatusCode.OK)
                {
                    throw new ApplicationException("Hata kodu:" + response.StatusCode);
                }

                using (Stream responseStream = response.GetResponseStream())
                {
                    if (responseStream != null)
                    {
                        using (StreamReader reader = new StreamReader(responseStream))
                        {
                            strResponseValue = reader.ReadToEnd();
                        }
                    }
                }
            }
            return strResponseValue;
        }

        public string stringParsing(string cevap)
        {
            string[] parcalar;
            parcalar = cevap.Split(':');
            string value_ham = parcalar[5];
            string value = value_ham.Substring(0, value_ham.Length - 4);
            return value;
        }
    }
}
