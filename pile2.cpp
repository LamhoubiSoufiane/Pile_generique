#include "main.hpp"
#include "pile2.hpp"


template <class T> Pile<T>::Pile(int nb)
{
    this->_maxelem=nb;
    this->pile=NULL;
    this->pile=new T[this->_maxelem];
    if(!this->pile)
    {
        cout<<"erreur d allocation!!"<<endl;
        exit(1);
    }
    this->_sommet=-1;
}

template<class T> Pile<T>::~Pile()
{
    delete[] this->pile;
}

template<class T> void Pile<T>::operator<<(T x)
{
    if(this->pilesaturee()) 
    {
        cout<<"pile est saturee"<<endl;
        exit(1);
    }
    this->pile[++this->_sommet] = x;
}

template<class T> void Pile<T>::afficher()
{
    int sommtmp=this->_sommet;
    while(this->_sommet >=0 ) 
    {
        cout<<this->pile[this->_sommet]<<endl;
        this->_sommet--;
    }
    this->_sommet=sommtmp;
}

template<class T> int Pile<T>::pilesaturee()
{
    if(this->_maxelem - 1 == this->_sommet) return((int)1);
    return((int)0);
}

template<class T> void Pile<T>::operator>>(T &x)
{
    if(this->pilevide()) 
    {
        cout<<"la pile est vide"<<endl;
        exit(1);
    }
    x=this->pile[this->_sommet--];
}

template<class T>int Pile<T>::pilevide()
{
    if(this->_sommet == -1) return((int)1);
    return((int)0);
}

template<class T>void Pile<T>::operator=(Pile &p)
{
    if(this->_maxelem != p._maxelem)
    {
        cout<<"\nles deux piles n ont pas la meme taille!!"<<endl;
        exit(1);
    }
    this->_sommet=p._sommet;
    T *tabtmp=new T[p._sommet + 1];
    int i=0;
    while(p._sommet >=0)
    {
        tabtmp[i]=p.pile[p._sommet--];
        i++;
    }
    p._sommet=this->_sommet;
    this->_sommet=0;
    i--;
    while(i >= 0 ) 
    {
        this->pile[this->_sommet++]=tabtmp[i--];
    }
    this->_sommet--;
    delete[] tabtmp;
}

