#ifndef PION_H_INCLUDED
#define PION_H_INCLUDED
#include "Console.h"
#include <string>

using namespace std;

class Pion
{
private :
    Console* pConsole;
    string m_type;
    int m_posx=0;
    int m_posy=0;
    int m_marquage = 0;

public :
    Pion(string _type, int _posx, int _posy, int _marquage);
    void afficherPion();
    ~Pion();
    string getType();
    void setType(string _type);
    int getPosx();
    int getPosy();
    void setMarquage(int _marquage);
    int getMarquage();
};

#endif // PION_H_INCLUDED
