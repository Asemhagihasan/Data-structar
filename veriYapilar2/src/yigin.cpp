/**
 * @file          yigin.cpp
 * @description   yigin sinife olusturmak.
 * @course        1_A
 * @assignment    2_odev
 * @date          8/5/2023
 * @author        yazan: Asem Hagi Hasan. mail:asem.hagihasan@ogr.sakarya.edu.tr
 * ogrenci No:     B201210567
 **/
#include "Yigin.hpp"
#include <iomanip>
Yigin::Yigin()
{
    tepe = -1;
    veriler = 0;
    kapasite = 5;
    genislet(kapasite);
}
Yigin::~Yigin()
{
    delete[] veriler;
}
bool Yigin::bosmu()
{
    if (tepe == -1)
        return true;
    return false;
}

void Yigin::ekle(int veri)
{
    if (tepe == kapasite - 1)
        genislet(kapasite);

    tepe++;
    veriler[tepe] = veri;
}

int Yigin::getir()
{
    if (tepe != -1)
    {
        int sonSayi = veriler[tepe];
        tepe--;
        return sonSayi;
    }
    throw std::out_of_range("Yigin Bos");
}
void Yigin::genislet(int boyut)
{
    int *yeniAlan = new int[boyut + kapasite];
    for (int i = 0; i <= tepe; i++)
    {

        yeniAlan[i] = veriler[i];
    }
    if (veriler)
        delete[] veriler;
    veriler = yeniAlan;
    kapasite += boyut;
}
