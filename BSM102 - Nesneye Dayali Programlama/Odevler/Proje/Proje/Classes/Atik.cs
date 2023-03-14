using Proje.Interfaces;
using System.Drawing;

namespace Proje.Classes
{
    public class Atik : IAtik
    {
        public int Hacim { get; }
        public Image Image { get; }
        public Atik(int _hacim, Image _image)
        {
            Hacim = _hacim;
            Image = _image;
        }
    }
}