  #ifndef IkiliAramaAgaci_hpp
  #define IkiliAramaAgaci_hpp
 #include "dokuDugum.hpp"
  #include <iostream>
  using namespace std;
  class IkiliAramaAgaci
  {
  public:
      IkiliAramaAgaci();
      ~IkiliAramaAgaci();
      void ekle(int veri);
      int yukseklik(dokuDugum *aktifeDugum);
      void postorder(dokuDugum *aktif);
      void AgacYokit(dokuDugum *aktif);
      dokuDugum *kok;
  private:
      void ekle(int veri, dokuDugum *aktifeDugum);
  };
  #endif