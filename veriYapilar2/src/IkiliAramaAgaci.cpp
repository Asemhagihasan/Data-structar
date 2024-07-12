/**
 * @file          ikiliAramaAgaci.cpp
 * @description   agac olusturmak ve verisi eklemek dolasim yontemleri ve yukseklik bulma.
 * @course        1_A
 * @assignment    2_odev
 * @date          8/5/2023
 * @author        yazan: Asem Hagi Hasan. mail:asem.hagihasan@ogr.sakarya.edu.tr
 * ogrenci No:     B201210567
 **/
#include "IkiliAramaAgaci.hpp"
#include <algorithm>
#include <iostream>

IkiliAramaAgaci::IkiliAramaAgaci()
{
    kok = 0;
    toplamDugum = 0;
}

void IkiliAramaAgaci::ekle(int veri)
{
    if (kok == 0)
    {
        kok = new Dugum(veri);
        toplamDugum += veri;
    }

    else
        ekle(veri, kok);
}
void IkiliAramaAgaci::ekle(int veri, Dugum *aktifeDugum)
{
    if (aktifeDugum->veri > veri)
    {
        if (aktifeDugum->sol)
            ekle(veri, aktifeDugum->sol);
        else
        {
            aktifeDugum->sol = new Dugum(veri);
            toplamDugum += veri;
        }
    }
    if (aktifeDugum->veri < veri)
    {
        if (aktifeDugum->sag)
            return ekle(veri, aktifeDugum->sag);
        else
        {
            aktifeDugum->sag = new Dugum(veri);
            toplamDugum += veri;
        }
    }

    else
        return;
}

int IkiliAramaAgaci::yukseklik(Dugum *aktifeDugum)
{
    if (aktifeDugum)
    {
        return 1 + max(yukseklik(aktifeDugum->sol), yukseklik(aktifeDugum->sag));
    }
    return -1;
}

void IkiliAramaAgaci::postorder(Dugum *aktif)
{
    if (aktif)
    {
        postorder(aktif->sol);
        postorder(aktif->sag);
        cout << static_cast<char>(aktif->veri) << "  ";
    }
}
