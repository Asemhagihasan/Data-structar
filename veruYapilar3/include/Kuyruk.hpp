#ifndef Kuyruk_hpp
#define Kuyruk_hpp
#include<iostream>
#include "Dugum.hpp"
using namespace std;

class Kuyruk
{
public:
	Kuyruk();
	~Kuyruk();
	void ekle(int veri);
	void cikar();
    bool bosmu();
	int getir();
	int elemanSayisiGetir();
    friend ostream& operator<<(ostream& os,Kuyruk& kuyruk);
	Dugum *ilk;
	Dugum *sonraki;
	Dugum *son;
	int elemanSayisi;
	int veri;
	


};

#endif