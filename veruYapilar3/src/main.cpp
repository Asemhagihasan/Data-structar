/*
* @file main.cpp
* @description programin basladigi sayfa
* @course 1.ogretim A grubu
* @assignment 2
* @date 25-12-2022
* @author ASEM HAJI HASAN asem.hagihasan@ogr.sakarya.edu.tr 
*/ 

#include <iostream>
#include <iomanip>
#include "testProgram.hpp"
#include <sstream>
#include <string>
#include <fstream>
#include <iomanip>
#include "kontrol.hpp"

using namespace std;
int main()
{
   testProgram *test;
   test->verilerOkumak();
   delete test;
   system("pause");
}
