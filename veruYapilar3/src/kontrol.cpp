/*
* @file kontrol.cpp
* @description mutasyonun kontrol edildigi sinif.
* @course 1.ogretim A grubu
* @assignment 2
* @date 25-12-2022
* @author ASEM HAJI HASAN asem.hagihasan@ogr.sakarya.edu.tr 
*/ 
#include "kontrol.hpp"
Kontrol::Kontrol(IkiliAramaAgaci *Agac)
{
    this->Agac = Agac;
    PostorderOku(this->Agac->kok);
    ikiyeBolen();
    yeniAgacOlustur();
}
Kontrol::~Kontrol()
{
    delete Agac;
}
void Kontrol::PostorderOku(dokuDugum *aktif)
{
    if (aktif)
    {
        PostorderOku(aktif->sol);
        PostorderOku(aktif->sag);
        verilar[verilerSayisi] = aktif->veri;
        verilerSayisi++;
    }

}
void Kontrol::ikiyeBolen()
{
    for (int i = 0; i < 20; i++)
    {
        if(verilar[i]%2 == 0)
            verilar[i]/=2;
    }
}
void Kontrol::yeniAgacOlustur()
{
    Agac = new IkiliAramaAgaci;
    for (int i = 0; i < 20; i++)
    {
        Agac->ekle(verilar[i]);
    }
}