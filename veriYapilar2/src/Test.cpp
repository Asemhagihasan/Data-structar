/**
 * @file          Test.cpp
 * @description   veriler dosyasindaki sayilar yigina eklemek ve agaclar oluturmak daha sonra agacin veriisi yazdirmak.
 * @course        1_A
 * @assignment    2_odev
 * @date          8/5/2023
 * @author        yazar: Asem Hagi Hasan. mail:asem.hagihasan@ogr.sakarya.edu.tr
 * ogrenci No:     B201210567
 **/
#include "test.hpp"
#include "IkiliAramaAgaci.hpp"
#include "yigin.hpp"
#include <sstream>
#include <fstream>
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
using namespace std;

Test::Test()
{
    IkiliAramaAgaci deneme;
    int i = 0;
    int indexSayisi = 0;
    int index = 0;
    int adet = 0;
    int sayi;
    int millisecondsToSleep = 10;
    ifstream veriler("veriler.txt");
    string satir;

    while (getline(veriler, satir))
    {

        int *sayilar = new int[satir.length() / 2];
        stringstream ss(satir);

        while (ss >> sayi)
        {
            sayilar[i] = sayi;
            i++;
            indexSayisi++;
        }

        int boyut = yiginSayisi(satir, indexSayisi);
        Yigin *liste = new Yigin[boyut];
        IkiliAramaAgaci *agaclar = new IkiliAramaAgaci[boyut];

        for (int j = 0; j < indexSayisi; j++)
        {
            liste[adet].ekle(sayilar[index]);
            index++;
            if (sayilar[index] % 2 == 0 && sayilar[index] > sayilar[index - 1])
                adet++;
        }

        for (int i = 0; i < boyut; i++)
        {
            while (liste[i].tepe != -1)
            {
                agaclar[i].ekle(liste[i].getir());
            }
        }

        delete[] liste;

        deneme.postorder(maxYukseklikDondur(agaclar, boyut).kok);
        cout << endl;
        i = 0;
        indexSayisi = 0;
        index = 0;
        adet = 0;
        delete[] sayilar;

#ifdef _WIN32

        Sleep(millisecondsToSleep);
#else

        usleep(millisecondsToSleep * 1000);
#endif
    }
}

IkiliAramaAgaci Test::maxYukseklikDondur(IkiliAramaAgaci *agaclar, int boyut)
{
    IkiliAramaAgaci agac = agaclar[0];

    if (boyut == 1)
        return agac;

    for (int j = 1; j < boyut; j++)
    {
        if (agaclar[j].yukseklik(agaclar[j].kok) > agac.yukseklik(agac.kok))
            agac = agaclar[j];
        else if (agaclar[j].yukseklik(agaclar[j].kok) == agac.yukseklik(agac.kok))
        {
            if (agaclar[j].toplamDugum > agac.toplamDugum)
                agac = agaclar[j];
            else if (agaclar[j].toplamDugum == agac.toplamDugum)
                agac = agac;
        }
    }
    return agac;
}

int Test::yiginSayisi(string satir, int indexSayisi)
{
    stringstream ss(satir);
    int number;
    int sayi = 0;
    int count = 0;
    int *array = new int[indexSayisi];

    while (ss >> number)
    {
        array[count] = number;

        if (count > 0)
        {
            if (array[count] % 2 == 0 && array[count] > array[count - 1])
            {
                sayi++;
            }
        }
        count++;
    }
    delete[] array;
    return sayi + 1;
}
