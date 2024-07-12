/*
* @file Hucre.cpp
* @description bagli liste sinifi gibi bir siniftir ayrica elemanlara siralama yapmaktadir
* @course 1.ogretim A grubu
* @assignment 2
* @date 25-12-2022
* @author ASEM HAJI HASAN asem.hagihasan@ogr.sakarya.edu.tr 
*/ 

#include "Hucre.hpp"
#include "hucreDugum.hpp"
#include <iostream>
using namespace std;

Hucre::Hucre()
{
    ilk = 0;
    hucreSayisi = 0;
}

void Hucre::yazdir()
{
    hucreDugum* gec = ilk;
    for(int i  = 0; i < hucreSayisi; i++)
    {
        cout << gec->veri << " ";
        gec = gec->sonraki;
    }
}

void Hucre::hucrelerEkle(int veri)
{
    hucreDugum *yeniDugum = new hucreDugum(veri);
    if (ilk == 0)
    {
        ilk = yeniDugum;
    }
    else
    {
        hucreDugum *gec = ilk;
        while (gec->sonraki != 0)
        {
            gec = gec->sonraki;
        }

        gec->sonraki = yeniDugum;
    }
    hucreSayisi++;
}

void Hucre::degerleriSirala()
{
    int* eskidegerler = new int[hucreSayisi];
    hucreDugum* gec = ilk;
    for(int i = 0; i < hucreSayisi; i++)
    {
        eskidegerler[i] = gec->veri;
        gec = gec->sonraki;
    }
    int j = hucreSayisi;
    hucrelerSil();

    Radix *siralama = new Radix(eskidegerler,j);
    int *siralanmisHucreler = siralama->sirala();
    for(int i = 0; i < j; i++)
    {
        hucrelerEkle(siralanmisHucreler[i]);
    }

    delete siralama;
    delete [] siralanmisHucreler;
    delete [] eskidegerler;
}

void Hucre::hucrelerSil()
{
    hucreDugum *gec = ilk;
    while (gec != 0)
    {
        hucreDugum *silincek = gec;
        gec = gec->sonraki;
        delete silincek;
    }
    ilk = 0;
    hucreSayisi = 0;
}






