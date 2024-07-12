/*
* @file Organizma.cpp
* @description organizma sadece yazdirmadan sorumlu olan sinif
* @course 1.ogretim A grubu
* @assignment 2
* @date 25-12-2022
* @author ASEM HAJI HASAN asem.hagihasan@ogr.sakarya.edu.tr 
*/ 

#include "Organizma.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

void Organizma::yazdir()
{
    System *gec = ilkSystem;
    system("cls");
    cout << setw(42) << "ORGANIZMA" << endl;
    while (gec->sonraki != 0)
    {
        for (int i = 0; i < 100; i++)
        {
            if (gec->organlar[i])
                cout << " ";
            else
                cout << "#";
        }
        cout << endl;
        gec = gec->sonraki;
    }
}
void Organizma::mutyazdir()
{
    System *gec = ilkSystem;
    system("cls");
    cout << setw(48) << "ORGANIZMA (MUTASYON)" << endl;
    while (gec->sonraki != 0)
    {
        for (int i = 0; i < 100; i++)
        {
            if (gec->mutasyon[i])
                cout << " ";
            else
                cout << "#";
        }
        cout << endl;
        gec = gec->sonraki;
    }
}