#include "Pion.h"
#include <iostream>
#include <string.h>
#include "Console.h"
#include <string>

using namespace std;

Pion::Pion(string _type, int _posx, int _posy, int _marquage):m_type(_type),m_posx(_posx),m_posy(_posy), m_marquage(_marquage)
{

}

Pion::~Pion()
{

}

void Pion::afficherPion()
{
    ///Affichage du pion avec conversion des coordonn�es

    int posx =(m_posx*4)+7;
    int posy =(m_posy*2)+4;
    pConsole->gotoLigCol(posy,posx);
    cout<<m_type;
}

string Pion::getType()
{
    return m_type;
}

int Pion::getPosx()
{
    return m_posx;
}

int Pion::getPosy()
{
    return m_posy;
}

void Pion::setMarquage(int _marquage)
{
    m_marquage = _marquage;
}

int Pion::getMarquage()
{
    return m_marquage;
}

void Pion::setType(string _type)
{
    m_type = _type;
}
