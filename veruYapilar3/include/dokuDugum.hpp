#ifndef dokuDugum_hpp
#define dokuDugum_hpp

class dokuDugum
{
public:
    dokuDugum(int veri);
    int veri;
    dokuDugum *sonraki;
    dokuDugum *sol;
    dokuDugum *sag;
};


#endif