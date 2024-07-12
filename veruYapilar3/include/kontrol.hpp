 #ifndef kontrol_hpp
 #define kontrol_hpp
 #include "IkiliAramaAgaci.hpp"
 #include "dokuDugum.hpp"

class Kontrol
{
public:
    Kontrol(IkiliAramaAgaci *Agac);
    ~Kontrol();
    void PostorderOku(dokuDugum *aktif);
    void ikiyeBolen();
    void yeniAgacOlustur();

    int verilerSayisi = 0;
    int verilar[20];
    IkiliAramaAgaci *Agac;
};
#endif