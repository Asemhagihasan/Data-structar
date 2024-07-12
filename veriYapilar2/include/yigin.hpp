/**
 * @file          yigin.hpp
 * @description   yigin sinfi oluturmak
 * @course        1_A
 * @assignment    2_odev
 * @date          8/5/2023
 * @author        yazan: Asem Hagi Hasan. mail:asem.hagihasan@ogr.sakarya.edu.tr
 * ogrenci No:     B201210567
 **/
#ifndef Yigin_hpp
#define Yigin_hpp
#include <iostream>
using namespace std;

class Yigin
{
public:
    Yigin();
    ~Yigin();
    void ekle(int veri);
    bool bosmu();
    int getir();
    int tepe;

private:
    void genislet(int boyut);
    int kapasite;
    int *veriler;
};

#endif