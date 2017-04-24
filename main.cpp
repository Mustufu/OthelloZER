#include <iostream>
#include <conio.h>
#include "Pion.h"
#include "Plateau.h"
#include <windows.h>
#include "Console.h"
#include <mmsystem.h>

using namespace std;

int main()
{

    int choix;
    char menu;
    Coordonnes maCoord;
    Console* pConsole;
    Plateau plateauDeJeu;

    pConsole->gotoLigCol(5,25);
    cout<<"BIENVENUE SUR OTHELLO";
    pConsole->gotoLigCol(10,20);
    cout<<"Appuie sur une touche pour continuer ";
    menu = getch();
    plateauDeJeu.menuJeu();
    return 0;
}
