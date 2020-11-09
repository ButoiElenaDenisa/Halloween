#include <iostream>
#include <cstring>

using namespace std;

class Decoratiune
{
private:
    char* culoare;
    char* denumire;
    bool esteReciclabila;
    float pretAtribut;
public:
    Decoratiune()
    {
        culoare = NULL;
        denumire = NULL;
        esteReciclabila = false;
        pretAtribut = 0;
    }
    Decoratiune(const Decoratiune&d)
    {
        if (d.culoare != NULL)
        {
            culoare = new char[strlen(d.culoare)];
            strcpy(culoare, d.culoare);
        }
        if (d.denumire != NULL)
        {
            denumire = new char[strlen(d.denumire)];
            strcpy(denumire, d.denumire);
        }
        esteReciclabila = d.esteReciclabila;
        pretAtribut = d.pretAtribut;
    }
    Decoratiune operator=(const Decoratiune &d)
    {
        if (d.culoare != NULL)
        {
            culoare = new char[strlen(d.culoare)];
            strcpy(culoare, d.culoare);
        }
        if (d.denumire != NULL)
        {
            denumire = new char[strlen(d.denumire)];
            strcpy(denumire, d.denumire);
        }
        esteReciclabila = d.esteReciclabila;
        pretAtribut = d.pretAtribut;
    }
    friend ostream& operator<<(ostream& o, const Decoratiune& d);
    float pret()
    {
        return pretAtribut;
    }
};

ostream& operator<<(ostream& o, const Decoratiune& d)
{
    cout << "Decoratiunea:" << endl;
    if (d.denumire)
        cout << "Denumire: " << d.denumire << endl;
    else
        cout << "Produsul nu are nicio denumire completata" << endl;
    if (d.culoare)
        cout << "Culoare: " << d.culoare << endl;
    else
        cout << "Produsul nu are nicio culoare completata" << endl;
    cout << "Pret: " << d.pretAtribut << endl;
    if (d.esteReciclabila)
        cout << "Este reciclabila" << endl;
    else
        cout << "Nu este reciclabila" << endl;
}

class ListaProduse
{
private:
    int nrProduse;
    Decoratiune produse[101];
public:
    ListaProduse()
    {
        nrProduse = 0;
    }
    ListaProduse operator+(const Decoratiune& d)
    {
        ListaProduse listaNoua = *this;
        listaNoua.produse[0];
        listaNoua.nrProduse++;
        return listaNoua;
    }
    ListaProduse operator=(const ListaProduse& d)
    {
        nrProduse = d.nrProduse;
        for (int i = 0; i < nrProduse; i++)
        {
            produse[i] = d.produse[i];
        }
        return *this;
    }
    Decoratiune operator[](int i) const
    {
        return produse[i];
    }
    void remove(int position)
    {
        for (int i = position - 1; i <nrProduse; i++)
            produse[i] = produse[i + 1];
        nrProduse--;
    }
    float pret()
    {
        float total = 0;
        for (int i = 0; i < nrProduse; i++)
        {
            total += produse[i].pret();
        }
    }
};

int main()
{
    Decoratiune a, c;

    ListaProduse b;

    b = b + a;

    cout << b[1];
    cout << b[1].pret();
    cout << b.pret();
    b.remove(1);

    return 0;
}
