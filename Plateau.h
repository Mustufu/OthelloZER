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
    int compteurPions=4;
    int m_tour=0;

public :

    Plateau();
    ~Plateau();
    void afficher(int _tour);
    void setPionsBlancs(int _pions);
    Coordonnes Curseur();
    void menuJeu();
    void menuQuitter();
    bool ajouterPion(Coordonnes maCoord);
    Coordonnes parcoursMatrice(int _tour);
    int getTour();
    void vsIA();
    bool casePossible(int _tour);
    bool blindageAjouterPion(Coordonnes maCoord);
    bool blindageAjouterPionIA(Coordonnes maCoord2, int _tour);
    bool blindageAjouterPionSansConversion(Coordonnes maCoord, int _tour);
    bool ajouterPionIA(Coordonnes maCoord2, int _tour);
    void setTour(int _tour);
    void retournerPion();
    int compteScore();
};

#endif // PLATEAU_H_INCLUDED
