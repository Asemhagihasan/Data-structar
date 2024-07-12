#ifndef Doku_hpp
#define Doku_hpp
#include "dokuDugum.hpp"
#include "Hucre.hpp"

class Doku
{
public:
    Doku();
    void dokuOlusturmak(Hucre *deneme , int sayi);
    void yazdir();
    void dokuYokit();
    dokuDugum *ilk;
};

#endif
