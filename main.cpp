#include "main.hpp"
#include "pile2.cpp"

int main()
{
    Pile<int> pile1(10);
    pile1<<3;
    pile1<<4;
    pile1<<4;
    pile1<<7;
    pile1<<9;
    pile1.afficher();
    cout<<"/****************/"<<endl;
    Pile<int> pile2(10);
    int y;
    pile2<<3;
    pile2<<4.5;
    pile2<<8.7;
    pile2<<6.65;
    pile2<<1.25;
    pile2.afficher();
    cout<<"/****************/"<<endl;
    pile2>>y;
    cout<<"y depile est : "<<y<<endl;
    pile2.afficher();
    cout<<"/****************/"<<endl;
    pile2=pile1;
    pile2.afficher();
}