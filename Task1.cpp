#include <iostream>
using namespace std;

template <typename Tip>
class Stek
{
    struct Cvor {
        Tip element;
        Cvor *sljedeci;
        Cvor(const Tip &element, Cvor *sljedeci): element(element), sljedeci(sljedeci) {}
    };

    Cvor *Vrh;
    int duz;



public:

    Stek(): Vrh(nullptr),duz(0) {}
    Stek(const Stek<Tip> &s)
    {
        Cvor *p(s.Vrh);
        Cvor *q = 0;
        duz=s.duz;

        while(p!=0) {
            Cvor *novi=new Cvor(p->element,0);
            if(q==0) {
                Vrh=novi;

            } else {
                q->sljedeci=novi;

            }
            q=novi;
            p=p->sljedeci;
        }
        duz=s.duz;
    }

    ~Stek()
    {
        while(duz!=0) {
            Cvor *pomm=Vrh;
            Vrh=Vrh->sljedeci;
            delete pomm;
            duz--;
        }
    }



    Stek &operator=(const Stek &s)
    {
        if(&s==this) return *this;
        Cvor *p(s.Vrh);
        Cvor *q = 0;
        duz=s.duz;
        while(p!=0) {
            Cvor *novi=new Cvor(p->element,0);
            if(q==0) {
                Vrh=novi;

            } else {

                q->sljedeci=novi;

            }
            q=novi;
            p=p->sljedeci;


        }
       // duz=s.duz;
        return *this;

    }

    Tip &vrh() {
        if(Vrh==0) throw("Stek je prazan/n");
        return Vrh->element;
    }
  
    int brojElemenata() {
        return duz;
    }


    void brisi()
    {
        Cvor *pomm;
        while(Vrh!=nullptr) {
            pomm=Vrh;
            Vrh=Vrh->sljedeci;
            delete pomm;
            duz--;
        }
        duz=0;

    }
    
    
    Tip skini()
    {
        if(duz==0)throw("Stek je prazan/n");
        Tip x=Vrh->element;
        Cvor *pomm(Vrh);

        if(duz==1) {
            Vrh=nullptr;
            delete pomm;

        } else {
            Cvor *p(Vrh);
            p=p->sljedeci;
            Vrh=Vrh->sljedeci;
            pomm->sljedeci=nullptr;
            delete pomm;
            pomm=p;
        }

        duz--;
        return x;

    }


    void stavi(const Tip &el)
    {
        if(duz==0) {
            Cvor *novi=new Cvor(el,0);
            Vrh=novi;

        } else {
            Cvor *novi=new Cvor(el,0);
            novi->sljedeci=Vrh;
            Vrh=novi;
        }
        duz++;

    }





//Testirajmo metodu
    bool TestBrisi()
    {
        Stek<int> s;
        for(int i=5; i<=3; i++) s.stavi(i);
        s.brisi();
        if(s.brojElemenata()==0) return true;
        return false;
    }//brisi


//Testirajmo vrh
    bool TestBrojEl()
    {
        Stek<int> s;
        for(int i=7; i>=1; i--) {
            s.stavi(i);
        }
        if(s.vrh()==2) return true;
        return false;
    }

    bool TestStavi()
    {
        Stek<int> s;
        s.stavi(1);
        s.stavi(3);
        if(s.brojElemenata()==2) return true;
        return false;
    } //stavi


    bool TestSkini()
    {
        Stek<int> s;
        s.stavi(5);
        s.stavi(3);
        s.skini();
        if(s.brojElemenata()==1) return true;
        return false;
    }//skini


//test za broj elemenata
    bool TestVrh()
    {
        Stek<int> s;
        if(s.brojElemenata()==0) {
            return true;
        }

        return false;
    }
};

int main()
{

    Stek<int>s;
    for(int i=0; i<5; i++) {
        s.stavi(i);
    }
    std::cout<<s.vrh()<<" ";
    s.vrh()++;
    std::cout<<s.vrh();

    std::cout << "Kompajlirao se!";
    return 0;
}
