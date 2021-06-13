using Proje.Interfaces;

namespace Proje.Classes
{
    class OrganikAtikKutusu : IAtikKutusu
    {
        public int BosaltmaPuani { get; } = 0;
        public int Kapasite { get; set; } = 700;
        public int DoluHacim { get; set; }
        public int DolulukOrani
        {
            get
            {
                return (DoluHacim * 100) / Kapasite;
            }
        }
        public bool Bosalt()
        {
            if (DolulukOrani >= 75)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        public bool Ekle(Atik atik)
        {
            if (DoluHacim + atik.Hacim <= Kapasite)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}