#ifndef SIEWO_H
#define SIEWO_H
#endif
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


class plik
{
    public :
        string fname;


    void clear_file()
    {
        ofstream plik(this->fname.c_str() , ios::trunc);
        if( plik.good() == true )
        {
            cout<<"Clear file";
            plik.close();
        }
        else
        cout<<"Ups! Cos poszlo nie tak";
    }

    void save(string text)
    {
        ofstream plik(this->fname.c_str() , ios::out);
        if( plik.good() == true )
        {
            plik << text;
            plik.close();
        }
        else
        cout<<"Ups! Cos poszlo nie tak";
    }

    void output(string text)
    {
        ofstream plik(this->fname.c_str() , ios::app);
        if( plik.good() == true )
        {
            plik << text<<'\n';
            plik.close();
        }
        else
        cout<<"Ups! Cos poszlo nie tak";
    }

    string load()
    {
        string text;
        ifstream plik(this->fname.c_str() , ios::in);
        if( plik.good() == true )
        {
            string line;
            while(!plik.eof())
            {
                getline( plik, line );
                text+=line+" ";
            }
            plik.close();
        }
        else
        cout<<"Ups! Cos poszlo nie tak, upewnij sie ze plik zanuduje sie w tej samej lokalizacji co program";
        return text;
    }
    void wypisz()
    {
        cout<<"Siewo";
    }
};
