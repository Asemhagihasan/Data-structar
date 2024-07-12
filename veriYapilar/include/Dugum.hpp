/**
 * Dugum.hpp
 * Dugumun verisi ve adresi tanilamak
 * 1-A
 * Birinci odev
 * 7/19/2023 Tarihta olusturdu
 * Yazan: Asem Hagi Hasan. Mail adresi:asem.hagihasan@ogr.sakarya.edu.tr
 * Ogrenci No:B201210567
 */
#ifndef Dugum_hpp
#define Dugum_hpp

class Dugum
{
public:
    Dugum(int veri);
    int veri;
    Dugum *sonraki;
};

#endif