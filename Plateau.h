#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED
#include <vector>
#include <iostream>
#include "Pion.h"

class Plateau
{
private :
    vector <vector<Pion*> > plateauJeu;
    int m_compteurPionNoirs=0;
    int m_compteurPionBlancs=0;
    int m_tour =0;

public :

    Plateau();
    ~Plateau();
    void afficher();
    Coordonnes Curseur();
    void menuJeu();
    void menuQuitter();
    void ajouterPion(Coordonnes maCoord);
    Coordonnes parcoursMatrice();
    int getTour();
    bool casePossible();
    bool blindageAjouterPion(Coordonnes maCoord);
    bool blindageAjouterPionIA(Coordonnes maCoord2);
    bool blindageAjouterPionSansConversion(Coordonnes maCoord);
    void ajouterPionIA(Coordonnes maCoord2);
    void setTour(int _tour);
    void retournerPion();
};

#endif // PLATEAU_H_INCLUDED
