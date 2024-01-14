#ifndef SRC_PILE2_H_
#define SRC_PILE2_H_

template <class T> class Pile
{
    private:
        int _maxelem;
        T *pile;
        int _sommet;
    public:
        Pile(int);
        ~Pile();
        int pilesaturee();
        int pilevide();
        void operator<<(T);
        void operator>>(T &x);
        void operator=(Pile &);
        void afficher();
};

#endif