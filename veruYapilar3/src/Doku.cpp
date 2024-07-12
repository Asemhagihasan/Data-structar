/*
* @file Doku.cpp
* @description doku sinifi bir bagli liste elemanlarini alir, bir diziye saklar ve bu diziden orta elemani dondurur
* @course 1.ogretim A grubu
* @assignment 2
* @date 25-12-2022
* @author ASEM HAJI HASAN asem.hagihasan@ogr.sakarya.edu.tr 
*/ 


#include "Doku.hpp"
#include <iostream>
using namespace std;
Doku::Doku()
{
    ilk = 0;
}
void Doku::dokuOlusturmak(Hucre *deneme, int adet)
{
    hucreDugum *gec = deneme->ilk;
    int *hucreler = new int [adet];
    for (int i = 0; i < adet; i++)
    {
        hucreler[i] = gec->veri;
        gec = gec->sonraki;
    }
    int OrtadakiEleman;
    OrtadakiEleman = hucreler[(adet - 1) / 2];
    delete [] hucreler;
    dokuDugum *yenidoku = new dokuDugum(OrtadakiEleman);
    if (ilk == 0)
    {
        ilk = yenidoku;
    }
    else
    {
        dokuDugum *gec = ilk;

        while (gec->sonraki != 0)
        {
            gec = gec->sonraki;
        }
        gec->sonraki = yenidoku;
    }
}
void Doku::dokuYokit()
{
    dokuDugum *gec = ilk;
    while (gec != 0)
    {
        dokuDugum *silincek = gec;
        gec = gec->sonraki;
        delete silincek;
    }
    ilk = 0;
}
void Doku::yazdir()
{
    dokuDugum *gec = ilk;
    while (gec != 0)
    {
        cout << gec->veri << " ";
        gec = gec->sonraki;
    }
}
