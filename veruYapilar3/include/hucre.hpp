#ifndef Hucre_hpp
#define Hucre_hpp
#include "Kuyruk.hpp"
#include "hucreDugum.hpp"
#include "Radix.hpp"

class Hucre
{
public:
    Hucre();
    void hucrelerSil();
    void hucrelerEkle(int veri);
    void yazdir();
    void degerleriSirala();
    
    hucreDugum *ilk;
    int hucreSayisi;
    
};

#endif
