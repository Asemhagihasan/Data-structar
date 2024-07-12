#ifndef Sysytem_hpp
#define Sysytem_hpp


class System
{
public:
    System();
    void organEkle(bool organ);
    void mutasyonOrganEkle(bool organ);
    int organSayisi;
    bool *organlar = new bool[100];
    bool *mutasyon = new bool[100];
    System *sonraki;
};






#endif
