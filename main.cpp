#include<iostream>
#include<fstream>
#include <vector>
#include<cstdlib>
#include <unistd.h>
#include<cstring>
using namespace std;

struct osoba
{
    char ime[80];
    char prezime[80];
    int broj_godina;
};

void ispisi(std::vector<osoba> vektor);

int rx_file_exsist(const char* path)
{

    int ret = access(path, F_OK);
    if(ret<0)
    {
        return false;
    }
    else
        return true;
}
int main(int argc, char *argv[])
{

    const char* pathfull = __FILE__;
    const char* path = pathfull-'main.cpp';
    path+='Imenik.txt';
vector<osoba> vektor;

if(rx_file_exsist(path))
{
    ifstream in("Imenik.txt");
    char ime[80], prezime[80];
    int godine;
    while(in >> ime && in >> prezime && in >> godine)
    {
        osoba x;
        strcpy(ime,x.ime);
        strcpy(prezime,x.prezime);
        x.broj_godina=godine;
        vektor.push_back(x);
    }
    in.close();
}


        if(!strcmp("-unesi",argv[1]))
        {
         osoba a;
         strcpy(argv[2], a.ime);
         strcpy(argv[3], a.prezime);
         a.broj_godina=stoi(argv[4]);
         vektor.push_back(a);
        }
         else if(!strcmp("-ispisi",argv[1]))
        {
         ispisi(vektor);
        }

return 0;
}

