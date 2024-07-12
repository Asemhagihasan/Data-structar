/**
 * Listeler.cpp
 * listeler tanimlamak ve listeye degerler eklemek konum degistirmek ve ortalama hesaplama.
 * 1-A
 * Birinci odev
 * 7/19/2023 Tarihta olusturdu
 * Yazan: Asem Hagi Hasan. Mail adresi:asem.hagihasan@ogr.sakarya.edu.tr
 * ogrenci no:B201210567
 */

#include "Listeler.hpp"
#include <sstream>
#include <fstream>
#include <iostream>
#include "Dugum.hpp"
#include <cmath>
using namespace std;
Listeler::Listeler()
{
    ilk = 0;
}

void Listeler::ekle(int veri)
{
    Dugum *yeni = new Dugum(veri);
    if (ilk == 0)
    {
        ilk = yeni;
    }
    else
    {
        Dugum *gec = sonDugumGetir();
        gec->sonraki = yeni;
    }
}

int Listeler::satirSayisi()
{
    int satirSayisi = 0;
    ifstream veriler("benioku.txt");
    string satir;
    int sayi;
    while (getline(veriler, satir))
    {
        satirSayisi++;
        stringstream ss(satir);
    }
    return satirSayisi;
}

void Listeler::listeyeEkleme(Listeler *&yukariListe, Listeler *&asagiListe)
{
    ifstream veriler("benioku.txt");
    string satir;
    int sayi;
    int index = 0;
    while (getline(veriler, satir))
    {
        stringstream ss(satir);
        while (ss >> sayi)
        {
            yukariListe[index].ekle(sayi / 10);
            asagiListe[index].ekle(sayi % 10);
        }
        index++;
    }
}

void Listeler::konumDegistir(Listeler &konumA, Listeler &konumB)
{
    Dugum *gec = konumA.ilk;
    konumA.ilk = konumB.ilk;
    konumB.ilk = gec;
}

Dugum *Listeler::sonDugumGetir()
{
    Dugum *gec = ilk;
    while (gec->sonraki != 0)
    {
        gec = gec->sonraki;
    }
    return gec;
}

void Listeler::ortalamaHesap(Listeler *yukariListe, Listeler *asagiListesi)
{
    double ustOrtalamaToplam = 0;
    double altOrtalamaToplam = 0;
    bool devam = true;
    int satirlar = satirSayisi();

    for (int j = 0; devam; j++)
    {
        double ustOrtalama = 0;
        double ustAdet = 0;
        double ustToplam = 0;
        double altOrtalama = 0;
        double altAdet = 0;
        double altToplam = 0;
        devam = false;

        for (int i = 0; i < satirlar; i++)
        {
            if (yukariListe[i].ilk)
            {
                ustAdet++;
                ustToplam += yukariListe[i].ilk->veri;
                yukariListe[i].ilk = yukariListe[i].ilk->sonraki;
            }

            if (asagiListesi[i].ilk)
            {
                altAdet++;
                altToplam += asagiListesi[i].ilk->veri;
                asagiListesi[i].ilk = asagiListesi[i].ilk->sonraki;
            }
        }
        if (ustAdet > 0)
        {
            ustOrtalama = ustToplam / ustAdet;
            ustOrtalamaToplam += ustOrtalama;
            ustOrtalamaToplam = floor(ustOrtalamaToplam * 10) / 10;
        }

        if (altAdet > 0)
        {
            altOrtalama = altToplam / altAdet;
            altOrtalamaToplam += altOrtalama;
            altOrtalamaToplam = floor(altOrtalamaToplam * 10) / 10;
        }
        for (int k = 0; k < satirlar; k++)
        {
            if (yukariListe[k].ilk)
            {
                devam = true;
                break;
            }
        }
    }

    cout << " Ust: " << ustOrtalamaToplam << endl;
    cout << " Alt:" << altOrtalamaToplam << endl;
}

void Listeler::yazdir()
{
    int satirlar = satirSayisi();
    int konumA;
    int konumB;
    Listeler *yokariDogruListesi = new Listeler[satirlar];
    Listeler *asagiDuguruListesi = new Listeler[satirlar];

    listeyeEkleme(yokariDogruListesi, asagiDuguruListesi);

    cout << "kounmA giriniz:";
    cin >> konumA;
    cout << endl;

    cout << "kounmB giriniz:";
    cin >> konumB;
    cout << endl;
    if ((konumA >= 0 && konumA < satirlar) && (konumB >= 0 && konumB < satirlar))
        konumDegistir(yokariDogruListesi[konumA], asagiDuguruListesi[konumB]);
    else
        cout << "Girdiniz konum sinir disidir!!";

    ortalamaHesap(yokariDogruListesi, asagiDuguruListesi);
}
