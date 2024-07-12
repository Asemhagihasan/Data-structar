/**
 * @file          ikiliAramaAgaci.hpp
 * @description   ikiliAramaAgaci sinfi oluturmak.
 * @course        1_A
 * @assignment    2_odev
 * @date          8/5/2023
 * @author        yazan: Asem Hagi Hasan. mail:asem.hagihasan@ogr.sakarya.edu.tr
 * ogrenci No:     B201210567
 **/
#ifndef IkiliAramaAgaci_hpp
#define IkiliAramaAgaci_hpp
#include "Dugum.hpp"
#include <iostream>

using namespace std;
class IkiliAramaAgaci
{
public:
    IkiliAramaAgaci();
    void ekle(int veri);
    int yukseklik(Dugum *aktifeDugum);
    void postorder(Dugum *aktif);
    int toplamDugum;
    Dugum *kok;

private:
    void ekle(int veri, Dugum *aktifeDugum);
};

#endif