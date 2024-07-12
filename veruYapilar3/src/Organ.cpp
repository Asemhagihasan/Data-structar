/*
* @file Organ.cpp
* @description doku sinifini alip bir agac yapar ve dengesizligi kontrol eder.
* @course 1.ogretim A grubu
* @assignment 2
* @date 25-12-2022
* @author ASEM HAJI HASAN asem.hagihasan@ogr.sakarya.edu.tr 
*/ 

#include "Organ.hpp"
#include "dokuDugum.hpp"
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int Organ::yukseklik(dokuDugum *aktifeDugum)
{
    if (aktifeDugum)
    {
        return 1 + max(yukseklik(aktifeDugum->sol), yukseklik(aktifeDugum->sag));
    }
    return -1;
}
bool Organ::dengeliDengesizoldunu(dokuDugum *gec)
{
    if (fabs(yukseklik(gec->sol) - yukseklik(gec->sag)) == 0 || fabs(yukseklik(gec->sol) - yukseklik(gec->sag)) == 1)
        return true;
    else
        return false;
}
