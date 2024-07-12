/**
 * @file          Test.hpp
 * @description   Test sinfi olusturmak.
 * @course        1_A
 * @assignment    2_odev
 * @date          8/5/2023
 * @author        yazan: Asem Hagi Hasan. mail:asem.hagihasan@ogr.sakarya.edu.tr
 * ogrenci No:     B201210567
 **/
#ifndef Test_hpp
#define Test_hpp
#include <iostream>
#include <string>
#include "IkiliAramaAgaci.hpp"
using namespace std;

class Test
{
public:
    Test();

private:
    int yiginSayisi(string satir, int indexSayisi);
    IkiliAramaAgaci maxYukseklikDondur(IkiliAramaAgaci *agaclar, int boyut);
};

#endif