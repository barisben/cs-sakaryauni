using Proje.Classes;

namespace Proje.Interfaces
{
    public interface IAtikKutusu : IDolabilen
    {
        /// <summary>
        /// Atık kutusu boşaltıldığında oyun puanına kaç puan ekleneceğini döndürür.
        /// </summary>
        int BosaltmaPuani { get; }
        /// <summary>
        /// Atık kutusunda gönderilen atığı alacak kadar boş yer varsa atığı kutuya ekler.
        /// </summary>
        /// <param name="atik">Eklenecek Atık</param>
        /// <returns>Atığın kutuya eklenip eklenmediğini döndürür.</returns>
        bool Ekle(Atik atik);
        /// <summary>
        /// Atık kutusunun doluluk oranı %75'in üstündeyse atık kutusunu boşaltır.
        /// </summary>
        /// <returns>Atık kutusunun boşaltılıp boşaltılmadığını döndürür.</returns>
        bool Bosalt();
    }
}