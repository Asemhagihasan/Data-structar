/*
* @file testProgram.cpp
* @description dosyanin okunup hucre, doku, organ, sistem, organizmaya gore dosyadan degerleri alir.
* @course 1.ogretim A grubu
* @assignment 2
* @date 25-12-2022
* @author ASEM HAJI HASAN asem.hagihasan@ogr.sakarya.edu.tr 
*/ 

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include "testProgram.hpp"
#include "System.hpp"
#include "Organizma.hpp"
#include "Organ.hpp"
#include "kontrol.hpp"
using namespace std;

void testProgram::verilerOkumak()
{
    ifstream Veri("Veri.txt");
    string satir;
    int sayi;
    int sayac;
    Hucre *hucreler = new Hucre();
    Doku *dokular = new Doku();
    IkiliAramaAgaci *Agac = new IkiliAramaAgaci();
    Organizma *systemler = new Organizma();
    System *aktifSystem = systemler->ilkSystem;
    Organ *organ = new Organ();

    for (int i = 0; getline(Veri, satir); i++)
    {
        hucreler = new Hucre();
        sayac = 0;
        stringstream ss(satir);

        while (ss >> sayi)
        {
            hucreler->hucrelerEkle(sayi);
            sayac++;
        }
        hucreler->degerleriSirala();
        dokular->dokuOlusturmak(hucreler, sayac);

        hucreler->hucrelerSil();
        if ((i + 1) % 20 == 0)
        {
            dokuDugum *gec = dokular->ilk;
            for (int i = 0; i < 20; i++)
            {
                Agac->ekle(gec->veri);
                gec = gec->sonraki;
            }
            dokular->dokuYokit();
            aktifSystem->organEkle(organ->dengeliDengesizoldunu(Agac->kok));
            
            Kontrol* MutasyonKontrol = new Kontrol(Agac);
            if(!organ->dengeliDengesizoldunu(Agac->kok) || Agac->kok->veri %50 == 0)
                aktifSystem->mutasyonOrganEkle(false);
            else
                aktifSystem->mutasyonOrganEkle(true);
            delete Agac;
            Agac = new IkiliAramaAgaci();
            delete MutasyonKontrol;
        }
        if ((i + 1) % 2000 == 0)
        {
            aktifSystem->sonraki = new System();
            aktifSystem = aktifSystem->sonraki;
        }
    }
    systemler->yazdir();
    system("pause");
    system("cls");
    systemler->mutyazdir();
}