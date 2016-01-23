#include "siewo.h"

/*
 * @AUTHOR      Jacek Batkowski
 * @CDV         Informatyka, 1 rok, zaocznie
 * @COMPILATOR  GNU GCC Compiler
 * @IDE         Code::Blocks 13.12
 * @LICENSE     MIT (X11)
 * @VCS         GitHub
 */

string cut_text(string&,int&,int&);
void just(string&,int);
void justyfi(string,string&,int);
void trim (string&);

int main()
{
    //obiekty
    plik input,output;
    output.fname="wynik.txt";
    input.fname="test.txt";

    int szer=80;    //szreoksc justowania
    string wynik="";
    std::cout<<"podaj nazwe pliku dla wejscia +'.txt' (nazwa.txt)";
    std::cin>>input.fname;
    std::cout<<"podaj nazwe pliku dla wyjscia +'.txt' (nazwa.txt)";
    std::cin>>output.fname;
    /*  //wprowadzanie dowlnej szerkosci text
     *std::cout<<"podaj szerkosc tekstu (liczba):"
     *std::cin>>szer;
    */
    justyfi(input.load(),wynik,szer);
    output.save(wynik);
    //std::cout<<endl<<wynik;


    return 0;
}

string cut_text(string &text, int &start_poz, int &end_poz )
{
    string buf;
    if(end_poz==text.length())
    {
        buf.insert(0,text,start_poz,text.length()-start_poz+1);
        start_poz=text.length();
        return buf;
    }
    while(end_poz>start_poz)
    {
        if(text[end_poz--]!=' ')
             continue;
        break;
    }
    buf.insert(0,text,start_poz,end_poz-start_poz+1);
    start_poz=end_poz+2;
    return buf;
};

void just(string &text, int szer)
{
    int poz=0;
    while(text.length()<szer)
    {
        if(text[poz++]==' ')
        {
            text.insert(poz," ",1);
            poz++;
        }
        if(poz>=text.length())
             poz=0;
    }
};

void justyfi(string text, string &wynik, int szer)
{
    trim(text);
    int start_poz=0, end_poz;
    if ((start_poz+szer)<text.length())
    {
        end_poz=start_poz+szer;
    } else {
        end_poz=text.length();
    }
    while (start_poz < end_poz)
    {
        string line = cut_text(text,start_poz,end_poz);
        just(line, szer);
        if ((start_poz+szer)<text.length())
        {
            end_poz=start_poz+szer;
        }
        else
        {
            end_poz=text.length();
        }
        //cout<<line<<endl;//debug
        wynik+=line+"\n";
    }
};
void trim (string &text)
{
    for(int i=0;i<text.length();i++)
    {
        if(text[i]==' ')
        {
            if(text[i+1]==' ')
            {
                //cout<<i+1<<" ";//debug
                text.erase(i,1);
                i--;
            }
        }
    }

};
