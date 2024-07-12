/*
* @file sistem.cpp
* @description organdan aldigi dengesizlik durumlarini bir dizide saklar.
* @course 1.ogretim A grubu
* @assignment 2
* @date 25-12-2022
* @author ASEM HAJI HASAN asem.hagihasan@ogr.sakarya.edu.tr 
*/ 

#include "System.hpp"

System::System()
{
    organSayisi = 0;
    sonraki = 0;
    
}

void System::organEkle(bool organ)
{
   organlar[organSayisi] = organ;
   organSayisi++;   
}
void System::mutasyonOrganEkle(bool organ)
{
   mutasyon[organSayisi] = organ;  
}
