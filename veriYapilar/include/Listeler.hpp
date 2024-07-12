/**
 * Listeler.hpp
 * fonksyonlari tanimlamak
 * 1-A
 * Birinci odev
 * 7/19/2023 Tarihta olusturdu
 * Yazan: Asem Hagi Hasan. Mail adresi:asem.hagihasan@ogr.sakarya.edu.tr
 * ogrenci no:B201210567
 */
#ifndef Listeler_hpp
#define Listeler_hpp
#include <iostream>
#include "Dugum.hpp"
using namespace std;

class Listeler
{
public:
    Listeler();
    void yazdir();

private:
    void ekle(int veri);
    void konumDegistir(Listeler &konumA, Listeler &KonumB);
    int satirSayisi();
    void ortalamaHesap(Listeler *listeler, Listeler *asagiListesi);
    void listeyeEkleme(Listeler *&yukariListe, Listeler *&asagiListe);
    Dugum *sonDugumGetir();
    Dugum *ilk;
};
#endif