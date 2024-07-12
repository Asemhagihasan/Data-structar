/*
* @file ikiliAramaAgaci.cpp
* @description ikili arama agaci sinifidir.
* @course 1.ogretim A grubu
* @assignment 2
* @date 25-12-2022
* @author ASEM HAJI HASAN asem.hagihasan@ogr.sakarya.edu.tr 
*/ 

#include "IkiliAramaAgaci.hpp"
#include <algorithm>
IkiliAramaAgaci::IkiliAramaAgaci()
{
    kok = 0;
}
IkiliAramaAgaci::~IkiliAramaAgaci()
{
    AgacYokit(kok);
}
void IkiliAramaAgaci::ekle(int veri)
{
    if (kok == 0)
        kok = new dokuDugum(veri);
    else
        ekle(veri, kok);
}
void IkiliAramaAgaci::ekle(int veri, dokuDugum *aktifeDugum)
{
    if (aktifeDugum->veri > veri)
    {
        if (aktifeDugum->sol)
            ekle(veri, aktifeDugum->sol);
        else
            aktifeDugum->sol = new dokuDugum(veri);
    }
    if (aktifeDugum->veri < veri)
    {
        if (aktifeDugum->sag)
            return ekle(veri, aktifeDugum->sag);
        else
            aktifeDugum->sag = new dokuDugum(veri);
    }
    else
        return;
}
int IkiliAramaAgaci::yukseklik(dokuDugum *aktifeDugum)
{
    if (aktifeDugum)
    {
        return 1 + max(yukseklik(aktifeDugum->sol), yukseklik(aktifeDugum->sag));
    }
    return -1;
}
void IkiliAramaAgaci::AgacYokit(dokuDugum *aktifDugum)
{
    if (kok == NULL)
        return;
    if (aktifDugum->sol)
        AgacYokit(aktifDugum->sol);
    if (aktifDugum->sag)
        AgacYokit(aktifDugum->sag);
    delete aktifDugum;
}
void IkiliAramaAgaci::postorder(dokuDugum *aktif)
{
    if (aktif)
    {
        postorder(aktif->sol);
        postorder(aktif->sag);
        cout << aktif->veri << "  ";
    }
}
