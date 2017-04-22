#include "Plateau.h"
#include <conio.h>
#include <windows.h>
#include <vector>
#include "Pion.h"
#include "console.h"
#include "time.h"



Plateau::Plateau()
{
    ///Constructeur par defaut initialisation de la matrice

    plateauJeu.resize(8);
    for(size_t i=0; i<8; i++)
    {
        plateauJeu[i].resize(8);
    }
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            plateauJeu[i][j]=new Pion(" ",i,j,0);
        }
    }

    ///Initialisation des Pions "Montagnes"

    plateauJeu[3][3]=new Pion("B",3,3,0);
    plateauJeu[3][4]=new Pion("N",3,4,0);
    plateauJeu[4][4]=new Pion("B",4,4,0);
    plateauJeu[4][3]=new Pion("N",4,3,0);
}

Plateau::~Plateau()
{
    ///destructeur
}

bool Plateau::casePossible()
{
    vector <Coordonnes> matriceCoordonnees;
    Console* pConsole;
    Coordonnes maCoord;
    int i,j;
    for(i=0; i<8; i++)
    {
        for(j=0; j<8; j++)
        {
            maCoord.x=i;
            maCoord.y=j;
            if(blindageAjouterPionIA(maCoord))
            {
                matriceCoordonnees.push_back(maCoord);
            }
        }
    }
    if(matriceCoordonnees.size()==0)
    {
        return false;
    }
    if(matriceCoordonnees.size()!=0)
    {
        return true;
    }
}

Coordonnes Plateau::parcoursMatrice()
{
    vector <Coordonnes> matriceCoordonnees;
    srand(time(NULL));
    Console* pConsole;
    int hasard;
    Coordonnes maCoord;
    int i,j;
    for(i=0; i<8; i++)
    {
        for(j=0; j<8; j++)
        {
            maCoord.x=i;
            maCoord.y=j;
            if(blindageAjouterPionIA(maCoord))
            {
                matriceCoordonnees.push_back(maCoord);
            }
        }
    }

    if(finDeJeu()==false)
    {
        hasard = rand()% matriceCoordonnees.size();
        pConsole->gotoLigCol(25,25);
        return matriceCoordonnees[hasard];
    }
}

bool Plateau::blindageAjouterPionIA(Coordonnes maCoord)
{
    int posx=maCoord.x;
    int posy=maCoord.y;
    Console* pConsole;


    if(plateauJeu[posx][posy]->getType()==" ")
    {
        if(m_tour%2==0)
        {
            ///if((plateauJeu[posx+1][posy]->getType()=="B")||(plateauJeu[posx-1][posy]->getType()=="B")||(plateauJeu[posx][posy+1]->getType()=="B")||(plateauJeu[posx][posy-1]->getType()=="B"))
            ///{
            int i=posx;
            int j=posy;
            int cmpt=0;
            int h=0;
            int g=0;
            int compteur=0;

            if(i>1)
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[i-1][posy]->getType()=="B")&&(i>1))
                {
                    ///cout<<"MDRRRRRR C BON";
                    cmpt++;
                    if(plateauJeu[i-2][posy]->getType()=="N")
                    {
                        cmpt=0;
                        compteur++;
                    }
                    i--;
                }
            }

            ///Remontada Haut Gauche

            if((i>1)&&(j>1))
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[i-1][j-1]->getType()=="B")&&(i>1)&&(j>1))
                {
                    cmpt++;
                    if(plateauJeu[i-2][j-2]->getType()=="N")
                    {
                        cmpt=0;
                        compteur++;
                    }
                    i--;
                    j--;
                }
            }

            ///Remontada Bas Gauche

            if((i>1)&&(j<6))
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[i-1][j+1]->getType()=="B")&&(i>1)&&(j<6))
                {
                    cmpt++;
                    if(plateauJeu[i-2][j+2]->getType()=="N")
                    {
                        cmpt = 0;
                        compteur++;
                    }
                    i--;
                    j++;
                }
            }

            ///Remontada Bas droite

            if((i<6)&&(j<6))
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[i+1][j+1]->getType()=="B")&&(i<6)&&(j<6))
                {
                    cmpt++;
                    if(plateauJeu[i+2][j+2]->getType()=="N")
                    {
                        cmpt = 0;
                        compteur++;
                    }
                    i++;
                    j++;
                }
            }

            ///Remontada Haut Droite
            if((i<6)&&(j>1))
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[i+1][j-1]->getType()=="B")&&(j>1)&&(i<6))
                {
                    cmpt++;
                    if(plateauJeu[i+2][j-2]->getType()=="N")
                    {
                        cmpt = 0;
                        compteur++;
                    }
                    i++;
                    j--;
                }
            }

            if(i<6)
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[i+1][posy]->getType()=="B")&&(i<6))
                {
                    cmpt++;
                    if(plateauJeu[i+2][posy]->getType()=="N")
                    {
                        cmpt=0;
                        compteur++;
                    }
                    i++;
                }
            }

            if(j>1)
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[posx][j-1]->getType()=="B")&&(j>1))
                {
                    cmpt++;
                    if(plateauJeu[posx][j-2]->getType()=="N")
                    {
                        cmpt=0;
                        compteur++;
                    }
                    j--;
                }
            }

            if(j<6)
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[posx][j+1]->getType()=="B")&&(j<6))
                {
                    cmpt++;
                    if(plateauJeu[posx][j+2]->getType()=="N")
                    {
                        cmpt=0;
                        compteur++;
                    }
                    j++;
                }
            }
            if(compteur>0)
            {
                return true;
            }
            ///}
        }
        if(m_tour%2==1)
        {
            ///if((plateauJeu[posx+1][posy]->getType()=="N")||(plateauJeu[posx-1][posy]->getType()=="N")||(plateauJeu[posx][posy+1]->getType()=="N")||(plateauJeu[posx][posy-1]->getType()=="N"))
            ///{
            int i=posx;
            int j=posy;
            int cmpt=0;
            int h=0;
            int g=0;
            int compteur=0;

            if(i>1)
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[i-1][posy]->getType()=="N")&&(i>1))
                {
                    cmpt++;
                    if(plateauJeu[i-2][posy]->getType()=="B")
                    {
                        cmpt=0;
                        compteur++;
                    }
                    i--;
                }
            }

            if(i<6)
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[i+1][posy]->getType()=="N")&&(i<6))
                {
                    cmpt++;
                    if(plateauJeu[i+2][posy]->getType()=="B")
                    {
                        cmpt=0;
                        compteur++;
                    }
                    i++;
                }
            }

            if(j>1)
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[posx][j-1]->getType()=="N")&&(j>1))
                {
                    cmpt++;
                    if(plateauJeu[posx][j-2]->getType()=="B")
                    {
                        cmpt=0;
                        compteur++;
                    }
                    j--;
                }
            }

            if(j<6)
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[posx][j+1]->getType()=="N")&&(j<6))
                {
                    cmpt++;
                    if(plateauJeu[posx][j+2]->getType()=="B")
                    {
                        cmpt=0;
                        compteur++;
                    }
                    j++;
                }
            }

            ///Remontada Haut Gauche

            if((i>1)&&(j>1))
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[i-1][j-1]->getType()=="N")&&(i>1)&&(j>1))
                {
                    cmpt++;
                    if(plateauJeu[i-2][j-2]->getType()=="B")
                    {
                        cmpt=0;
                        compteur++;
                    }
                    i--;
                    j--;
                }
            }

            ///Remontada Bas Gauche

            if((i>1)&&(j<6))
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[i-1][j+1]->getType()=="N")&&(i>1)&&(j<6))
                {
                    cmpt++;
                    if(plateauJeu[i-2][j+2]->getType()=="B")
                    {
                        cmpt = 0;
                        compteur++;
                    }
                    i--;
                    j++;
                }
            }

            ///Remontada Bas droite

            if((i<6)&&(j<6))
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[i+1][j+1]->getType()=="N")&&(i<6)&&(j<6))
                {
                    cmpt++;
                    if(plateauJeu[i+2][j+2]->getType()=="B")
                    {
                        cmpt = 0;
                        compteur++;
                    }
                    i++;
                    j++;
                }
            }

            ///Remontada Haut Droite
            if((i<6)&&(j>1))
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[i+1][j-1]->getType()=="N")&&(j>1)&&(i<6))
                {
                    cmpt++;
                    if(plateauJeu[i+2][j-2]->getType()=="B")
                    {
                        cmpt = 0;
                        compteur++;
                    }
                    i++;
                    j--;
                }
            }
            if(compteur>0)
            {
                return true;
            }

            ///}
        }
    }
    return false;

}

bool Plateau::blindageAjouterPionSansConversion(Coordonnes maCoord)
{

    int posx=maCoord.x;
    int posy=maCoord.y;
    Console* pConsole;

    if(plateauJeu[posx][posy]->getType()==" ")
    {
        if(m_tour%2==0)
        {
            ///if((plateauJeu[posx+1][posy]->getType()=="B")||(plateauJeu[posx-1][posy]->getType()=="B")||(plateauJeu[posx][posy+1]->getType()=="B")||(plateauJeu[posx][posy-1]->getType()=="B"))
            ///{
            int i=posx;
            int j=posy;
            int cmpt=0;
            int h=0;
            int g=0;
            int compteur=0;

            if(i>1)
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[i-1][posy]->getType()=="B")&&(i>1))
                {
                    ///cout<<"MDRRRRRR C BON";
                    cmpt++;
                    if(plateauJeu[i-2][posy]->getType()=="N")
                    {
                        for(int h=(posx-cmpt); cmpt>0; cmpt--)
                        {
                            h=(posx-cmpt);
                            plateauJeu[h][posy]->setMarquage(1);
                        }
                        cmpt=0;
                        compteur++;
                    }
                    i--;
                }
            }

            ///Remontada Haut Gauche

            if((i>1)&&(j>1))
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[i-1][j-1]->getType()=="B")&&(i>1)&&(j>1))
                {
                    cmpt++;
                    if(plateauJeu[i-2][j-2]->getType()=="N")
                    {
                        for(cmpt; cmpt>0; cmpt--)
                        {
                            h=(posx-cmpt);
                            g=(posy-cmpt);
                            plateauJeu[h][g]->setMarquage(1);
                        }
                        cmpt=0;
                        compteur++;
                    }
                    i--;
                    j--;
                }
            }

            ///Remontada Bas Gauche

            if((i>1)&&(j<6))
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[i-1][j+1]->getType()=="B")&&(i>1)&&(j<6))
                {
                    cmpt++;
                    if(plateauJeu[i-2][j+2]->getType()=="N")
                    {
                        for(cmpt; cmpt>0; cmpt--)
                        {
                            h=(posx-cmpt);
                            g=(posy+cmpt);
                            plateauJeu[h][g]->setMarquage(1);
                        }
                        cmpt = 0;
                        compteur++;
                    }
                    i--;
                    j++;
                }
            }

            ///Remontada Bas droite

            if((i<6)&&(j<6))
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[i+1][j+1]->getType()=="B")&&(i<6)&&(j<6))
                {
                    cmpt++;
                    if(plateauJeu[i+2][j+2]->getType()=="N")
                    {
                        for(cmpt; cmpt>0; cmpt--)
                        {
                            h=(posx+cmpt);
                            g=(posy+cmpt);
                            plateauJeu[h][g]->setMarquage(1);
                        }
                        cmpt = 0;
                        compteur++;
                    }
                    i++;
                    j++;
                }
            }

            ///Remontada Haut Droite
            if((i<6)&&(j>1))
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[i+1][j-1]->getType()=="B")&&(j>1)&&(i<6))
                {
                    cmpt++;
                    if(plateauJeu[i+2][j-2]->getType()=="N")
                    {
                        for(cmpt; cmpt>0; cmpt--)
                        {
                            h=(posx+cmpt);
                            g=(posy-cmpt);
                            plateauJeu[h][g]->setMarquage(1);
                        }
                        cmpt = 0;
                        compteur++;
                    }
                    i++;
                    j--;
                }
            }

            if(i<6)
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[i+1][posy]->getType()=="B")&&(i<6))
                {
                    cmpt++;
                    if(plateauJeu[i+2][posy]->getType()=="N")
                    {
                        for(int h=(posx+cmpt); cmpt>0; cmpt--)
                        {
                            h=(posx+cmpt);
                            plateauJeu[h][posy]->setMarquage(1);
                        }
                        cmpt=0;
                        compteur++;
                    }
                    i++;
                }
            }

            if(j>1)
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[posx][j-1]->getType()=="B")&&(j>1))
                {
                    cmpt++;
                    if(plateauJeu[posx][j-2]->getType()=="N")
                    {
                        for(cmpt; cmpt>0; cmpt--)
                        {
                            h=(posy-cmpt);
                            plateauJeu[posx][h]->setMarquage(1);
                        }
                        cmpt=0;
                        compteur++;
                    }
                    j--;
                }
            }

            if(j<6)
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[posx][j+1]->getType()=="B")&&(j<6))
                {
                    cmpt++;
                    if(plateauJeu[posx][j+2]->getType()=="N")
                    {
                        for(int h=(posy+cmpt); cmpt>0; cmpt--)
                        {
                            h=(posy+cmpt);
                            plateauJeu[posx][h]->setMarquage(1);
                        }
                        cmpt=0;
                        compteur++;
                    }
                    j++;
                }
            }
            if(compteur>0)
            {
                return true;
            }
            ///}
        }
        if(m_tour%2==1)
        {
            ///if((plateauJeu[posx+1][posy]->getType()=="N")||(plateauJeu[posx-1][posy]->getType()=="N")||(plateauJeu[posx][posy+1]->getType()=="N")||(plateauJeu[posx][posy-1]->getType()=="N"))
            ///{
            int i=posx;
            int j=posy;
            int cmpt=0;
            int h=0;
            int g=0;
            int compteur=0;

            if(i>1)
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[i-1][posy]->getType()=="N")&&(i>1))
                {
                    cmpt++;
                    if(plateauJeu[i-2][posy]->getType()=="B")
                    {
                        for(int h=(posx-cmpt); cmpt>0; cmpt--)
                        {
                            h=(posx-cmpt);
                            plateauJeu[h][posy]->setMarquage(1);
                        }
                        cmpt=0;
                        compteur++;
                    }
                    i--;
                }
            }

            if(i<6)
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[i+1][posy]->getType()=="N")&&(i<6))
                {
                    cmpt++;
                    if(plateauJeu[i+2][posy]->getType()=="B")
                    {
                        for(int h=(posx+cmpt); cmpt>0; cmpt--)
                        {
                            h=(posx+cmpt);
                            plateauJeu[h][posy]->setMarquage(1);
                        }
                        cmpt=0;
                        compteur++;
                    }
                    i++;
                }
            }

            if(j>1)
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[posx][j-1]->getType()=="N")&&(j>1))
                {
                    cmpt++;
                    if(plateauJeu[posx][j-2]->getType()=="B")
                    {

                        for(cmpt; cmpt>0; cmpt--)
                        {
                            h=(posy-cmpt);
                            plateauJeu[posx][h]->setMarquage(1);
                        }
                        cmpt=0;
                        compteur++;
                    }
                    j--;
                }
            }

            if(j<6)
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[posx][j+1]->getType()=="N")&&(j<6))
                {
                    cmpt++;
                    if(plateauJeu[posx][j+2]->getType()=="B")
                    {
                        for(int h=(posy+cmpt); cmpt>0; cmpt--)
                        {
                            h=(posy+cmpt);
                            plateauJeu[posx][h]->setMarquage(1);
                        }
                        cmpt=0;
                        compteur++;
                    }
                    j++;
                }
            }

            ///Remontada Haut Gauche

            if((i>1)&&(j>1))
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[i-1][j-1]->getType()=="N")&&(i>1)&&(j>1))
                {
                    cmpt++;
                    if(plateauJeu[i-2][j-2]->getType()=="B")
                    {
                        for(cmpt; cmpt>0; cmpt--)
                        {
                            h=(posx-cmpt);
                            g=(posy-cmpt);
                            plateauJeu[h][g]->setMarquage(1);
                        }
                        cmpt=0;
                        compteur++;
                    }
                    i--;
                    j--;
                }
            }

            ///Remontada Bas Gauche

            if((i>1)&&(j<6))
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[i-1][j+1]->getType()=="N")&&(i>1)&&(j<6))
                {
                    cmpt++;
                    if(plateauJeu[i-2][j+2]->getType()=="B")
                    {
                        for(cmpt; cmpt>0; cmpt--)
                        {
                            h=(posx-cmpt);
                            g=(posy+cmpt);
                            plateauJeu[h][g]->setMarquage(1);
                        }
                        cmpt = 0;
                        compteur++;
                    }
                    i--;
                    j++;
                }
            }

            ///Remontada Bas droite

            if((i<6)&&(j<6))
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[i+1][j+1]->getType()=="N")&&(i<6)&&(j<6))
                {
                    cmpt++;
                    if(plateauJeu[i+2][j+2]->getType()=="B")
                    {
                        for(cmpt; cmpt>0; cmpt--)
                        {
                            h=(posx+cmpt);
                            g=(posy+cmpt);
                            plateauJeu[h][g]->setMarquage(1);
                        }
                        cmpt = 0;
                        compteur++;
                    }
                    i++;
                    j++;
                }
            }

            ///Remontada Haut Droite
            if((i<6)&&(j>1))
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[i+1][j-1]->getType()=="N")&&(j>1)&&(i<6))
                {
                    cmpt++;
                    if(plateauJeu[i+2][j-2]->getType()=="B")
                    {
                        for(cmpt; cmpt>0; cmpt--)
                        {
                            h=(posx+cmpt);
                            g=(posy-cmpt);
                            plateauJeu[h][g]->setMarquage(1);
                        }
                        cmpt = 0;
                        compteur++;
                    }
                    i++;
                    j--;
                }
            }
            if(compteur>0)
            {
                return true;
            }

            ///}
        }
    }
    return false;
}

void Plateau::menuQuitter()
{
    Console* pConsole;
    char menu;
    system("cls");
    pConsole->gotoLigCol(10,20);
    cout<<"Etes vous sur ?";
    pConsole->gotoLigCol(15,20);
    cout<<"1- Oui";
    pConsole->gotoLigCol(15,30);
    cout<<"2- Non";
    menu = getch();
    switch(menu)
    {
    case '1':
        system("cls");
        pConsole->gotoLigCol(10,20);
        cout<<"A BIENTOT LA MIFF";
        pConsole->gotoLigCol(20,20);
        exit(0);
        break;

    case '2':
        menuJeu();
        break;

    default :
        pConsole->gotoLigCol(25,15);
        cout<<"Appuie sur la bonne touche mon pote";
        pConsole->gotoLigCol(26,15);
        system("PAUSE");
        menuQuitter();
    }
}

void Plateau::vsIA()
{
    int i,j;
    int choix;
    int blind;
    bool finJeu;
    ifstream fichier("Regles du jeu.txt", ios::in);
    char menu;
    Coordonnes maCoord;
    Coordonnes maCoord2;
    Console* pConsole;
    Plateau plateauDeJeu;
    do
    {
        system("cls");
        pConsole->gotoLigCol(1,30);
        plateauDeJeu.afficher();
        if(casePossible())
        {
            if(m_tour%2==1)
            {
                maCoord2 = plateauDeJeu.parcoursMatrice();
                plateauDeJeu.ajouterPionIA(maCoord2);
            }
            else
            {
                maCoord = plateauDeJeu.Curseur();
                plateauDeJeu.ajouterPion(maCoord);
            }
            plateauDeJeu.retournerPion();
            plateauDeJeu.afficher();
            pConsole->gotoLigCol(5,45);
            ///system("PAUSE");
            setTour(1);
        }
        else
        {
            pConsole->gotoLigCol(11,45);
            cout<<"Aucune possibilite, tour adverse";
            pConsole->gotoLigCol(12,45);
            system("PAUSE");
        }
    }
    while(finDeJeu()==false);
}

void Plateau::menuJeu()
{
    int i,j;
    int choix;
    bool finJeu;
    ifstream fichier("Regles du jeu.txt", ios::in);
    char menu;
    Coordonnes maCoord;
    Coordonnes maCoord2;
    Console* pConsole;
    Plateau plateauDeJeu;

    system("cls");
    pConsole->gotoLigCol(5,25);
    cout<<"Salut a tous les gamers que voulez vous faire";
    pConsole->gotoLigCol(10,25);
    cout<<"1- Jeu solo contre IA";
    pConsole->gotoLigCol(12,25);
    cout<<"2- Jeu 1v1 en multijoueur";
    pConsole->gotoLigCol(14,25);
    cout<<"3- Affichage des regles";
    pConsole->gotoLigCol(16,25);
    cout<<"4- Quitter le jeu :(";

    menu = getch();

    switch(menu)
    {
    case '1':
        vsIA();
        system("cls");
        system("PAUSE");
        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
            {
                if(plateauJeu[i][j]->getType()=="N")
                {
                    m_compteurPionNoirs++;
                }
                if(plateauJeu[i][j]->getType()=="B")
                {
                    m_compteurPionBlancs++;
                }
            }
        }
        if(m_compteurPionBlancs>m_compteurPionNoirs)
        {
            pConsole->gotoLigCol(12,20);
            cout<<"FIN DU JEU LES BROS LES BLANCS ONT GAGNE";
        }
        if(m_compteurPionBlancs<m_compteurPionNoirs)
        {
            pConsole->gotoLigCol(12,20);
            cout<<"FIN DU JEU LES BROS LES NOIRS ONT GAGNE";
        }
        if(m_compteurPionBlancs==m_compteurPionNoirs)
        {
            pConsole->gotoLigCol(12,20);
            cout<<"EGALITE";
        }
        break;

    case '2':
        do
        {
            system("cls");
            pConsole->gotoLigCol(1,30);
            plateauDeJeu.afficher();
            maCoord = plateauDeJeu.Curseur();
            plateauDeJeu.ajouterPion(maCoord);
            plateauDeJeu.retournerPion();
            plateauDeJeu.afficher();
        }
        while(choix!=0);
        break;

    case '3':
        ///Affichage des règles

        system("cls");

        if(fichier)
        {
            string ligne;
            while(getline(fichier,ligne))
            {
                cout<<ligne<<endl;
            }
            fichier.close();
            cout<<endl;
            cout<<"                   Appuie sur une touche pour revenir au menu mon pote";
            menu = getch();
            menuJeu();
        }
        else
        {
            cout<<"Impossible d'ouvrir le fichier";
        }
        break;

    case '4':
        menuQuitter();
        break;

    }
}

void Plateau::afficher()
{
    Console* pConsole = NULL;

    /// Alloue la mémoire du pointeur
    pConsole = Console::getInstance();
    pConsole->gotoLigCol(10,45);
    if(m_tour%2==0)
    {
        cout<<"Tour des noirs";
    }
    if(m_tour%2==1)
    {
        cout<<"Tours des blancs";
    }

    ///Affichage de la grille de jeu sur la console avec les reperes

    pConsole->gotoLigCol(4,4);
    cout<<"A";
    pConsole->gotoLigCol(6,4);
    cout<<"B";
    pConsole->gotoLigCol(8,4);
    cout<<"C";
    pConsole->gotoLigCol(10,4);
    cout<<"D";
    pConsole->gotoLigCol(12,4);
    cout<<"E";
    pConsole->gotoLigCol(14,4);
    cout<<"F";
    pConsole->gotoLigCol(16,4);
    cout<<"G";
    pConsole->gotoLigCol(18,4);
    cout<<"H";

    pConsole->gotoLigCol(4,5);

    for(int i=0; i<16; i++)
    {
        for(int j=0; j<7; j++)
        {
            cout<<"   |";
        }
        pConsole->gotoLigCol(4+i,6);
    }
    for(int j=0; j<8; j++)
    {
        for(int i=0; i<7; i++)
        {
            pConsole->gotoLigCol(5+(2*i),6+(2*2*j));
            cout<<"---";
        }
    }

    pConsole->gotoLigCol(2,7);
    cout<<"1";
    pConsole->gotoLigCol(2,11);
    cout<<"2";
    pConsole->gotoLigCol(2,15);
    cout<<"3";
    pConsole->gotoLigCol(2,19);
    cout<<"4";
    pConsole->gotoLigCol(2,23);
    cout<<"5";
    pConsole->gotoLigCol(2,27);
    cout<<"6";
    pConsole->gotoLigCol(2,31);
    cout<<"7";
    pConsole->gotoLigCol(2,35);
    cout<<"8";

    ///Boucle d'affichage des pions dans la grille affichées grace aux conversions de coordonnées

    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            plateauJeu[i][j]->afficherPion();
        }
    }
}

Coordonnes Plateau::Curseur()
{

    ///Declarations de variables

    int key=0;
    int x = 4;
    int y = 7;
    Console* pConsole;
    Coordonnes maCoord;
    pConsole->gotoLigCol(x,y);

    ///Boucle de deplacement du curseur dans la grille
    ///Avance de 4 par 4 horizontalement et de 2 par 2 verticalement

    while(key!=13)
    {
        if(pConsole->isKeyboardPressed())
        {
            key = pConsole->getInputKey();

            if(key == 100)
            {
                if(y<35)
                {
                    y=y+(2*2);
                    pConsole->gotoLigCol(x,y);
                }
            }
            if(key == 115)
            {
                if(x<18)
                {
                    x=x+2;
                    pConsole->gotoLigCol(x,y);
                }
            }
            if(key == 113)
            {
                if(y>=8)
                {
                    y=y-(2*2);
                    pConsole->gotoLigCol(x,y);
                }
            }
            if(key == 122)
            {
                if(x>=6)
                {
                    x=x-(2);
                    pConsole->gotoLigCol(x,y);
                }
            }

            if(key == 13)
            {
                ///Si le joueur appuie sur entrée, on stock les coordonnée de la case actuelle
                ///afin de pouvoir la selectionner
                maCoord.x = y;
                maCoord.y = x;
                return maCoord;
            }
        }
    }
}

bool Plateau::blindageAjouterPion(Coordonnes maCoord)
{

    int posx=maCoord.x;
    int posy=maCoord.y;
    Console* pConsole;

    posx = (posx/4)-(7/4);
    posy = (posy/2)-2;

    if(plateauJeu[posx][posy]->getType()==" ")
    {
        if(m_tour%2==0)
        {
            ///if((plateauJeu[posx+1][posy]->getType()=="B")||(plateauJeu[posx-1][posy]->getType()=="B")||(plateauJeu[posx][posy+1]->getType()=="B")||(plateauJeu[posx][posy-1]->getType()=="B"))
            ///{
            int i=posx;
            int j=posy;
            int cmpt=0;
            int h=0;
            int g=0;
            int compteur=0;

            if(i>1)
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[i-1][posy]->getType()=="B")&&(i>1))
                {
                    ///cout<<"MDRRRRRR C BON";
                    cmpt++;
                    if(plateauJeu[i-2][posy]->getType()=="N")
                    {
                        for(int h=(posx-cmpt); cmpt>0; cmpt--)
                        {
                            h=(posx-cmpt);
                            plateauJeu[h][posy]->setMarquage(1);
                        }
                        cmpt=0;
                        compteur++;
                    }
                    i--;
                }
            }

            ///Remontada Haut Gauche

            if((i>1)&&(j>1))
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[i-1][j-1]->getType()=="B")&&(i>1)&&(j>1))
                {
                    cmpt++;
                    if(plateauJeu[i-2][j-2]->getType()=="N")
                    {
                        for(cmpt; cmpt>0; cmpt--)
                        {
                            h=(posx-cmpt);
                            g=(posy-cmpt);
                            plateauJeu[h][g]->setMarquage(1);
                        }
                        cmpt=0;
                        compteur++;
                    }
                    i--;
                    j--;
                }
            }

            ///Remontada Bas Gauche

            if((i>1)&&(j<6))
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[i-1][j+1]->getType()=="B")&&(i>1)&&(j<6))
                {
                    cmpt++;
                    if(plateauJeu[i-2][j+2]->getType()=="N")
                    {
                        for(cmpt; cmpt>0; cmpt--)
                        {
                            h=(posx-cmpt);
                            g=(posy+cmpt);
                            plateauJeu[h][g]->setMarquage(1);
                        }
                        cmpt = 0;
                        compteur++;
                    }
                    i--;
                    j++;
                }
            }

            ///Remontada Bas droite

            if((i<6)&&(j<6))
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[i+1][j+1]->getType()=="B")&&(i<6)&&(j<6))
                {
                    cmpt++;
                    if(plateauJeu[i+2][j+2]->getType()=="N")
                    {
                        for(cmpt; cmpt>0; cmpt--)
                        {
                            h=(posx+cmpt);
                            g=(posy+cmpt);
                            plateauJeu[h][g]->setMarquage(1);
                        }
                        cmpt = 0;
                        compteur++;
                    }
                    i++;
                    j++;
                }
            }

            ///Remontada Haut Droite
            if((i<6)&&(j>1))
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[i+1][j-1]->getType()=="B")&&(j>1)&&(i<6))
                {
                    cmpt++;
                    if(plateauJeu[i+2][j-2]->getType()=="N")
                    {
                        for(cmpt; cmpt>0; cmpt--)
                        {
                            h=(posx+cmpt);
                            g=(posy-cmpt);
                            plateauJeu[h][g]->setMarquage(1);
                        }
                        cmpt = 0;
                        compteur++;
                    }
                    i++;
                    j--;
                }
            }

            if(i<6)
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[i+1][posy]->getType()=="B")&&(i<6))
                {
                    cmpt++;
                    if(plateauJeu[i+2][posy]->getType()=="N")
                    {
                        for(int h=(posx+cmpt); cmpt>0; cmpt--)
                        {
                            h=(posx+cmpt);
                            plateauJeu[h][posy]->setMarquage(1);
                        }
                        cmpt=0;
                        compteur++;
                    }
                    i++;
                }
            }

            if(j>1)
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[posx][j-1]->getType()=="B")&&(j>1))
                {
                    cmpt++;
                    if(plateauJeu[posx][j-2]->getType()=="N")
                    {
                        for(cmpt; cmpt>0; cmpt--)
                        {
                            h=(posy-cmpt);
                            plateauJeu[posx][h]->setMarquage(1);
                        }
                        cmpt=0;
                        compteur++;
                    }
                    j--;
                }
            }

            if(j<6)
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[posx][j+1]->getType()=="B")&&(j<6))
                {
                    cmpt++;
                    if(plateauJeu[posx][j+2]->getType()=="N")
                    {
                        for(int h=(posy+cmpt); cmpt>0; cmpt--)
                        {
                            h=(posy+cmpt);
                            plateauJeu[posx][h]->setMarquage(1);
                        }
                        cmpt=0;
                        compteur++;
                    }
                    j++;
                }
            }
            if(compteur>0)
            {
                return true;
            }
            ///}
        }
        if(m_tour%2==1)
        {
            ///if((plateauJeu[posx+1][posy]->getType()=="N")||(plateauJeu[posx-1][posy]->getType()=="N")||(plateauJeu[posx][posy+1]->getType()=="N")||(plateauJeu[posx][posy-1]->getType()=="N"))
            ///{
            int i=posx;
            int j=posy;
            int cmpt=0;
            int h=0;
            int g=0;
            int compteur=0;

            if(i>1)
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[i-1][posy]->getType()=="N")&&(i>1))
                {
                    cmpt++;
                    if(plateauJeu[i-2][posy]->getType()=="B")
                    {
                        for(int h=(posx-cmpt); cmpt>0; cmpt--)
                        {
                            h=(posx-cmpt);
                            plateauJeu[h][posy]->setMarquage(1);
                        }
                        cmpt=0;
                        compteur++;
                    }
                    i--;
                }
            }

            if(i<6)
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[i+1][posy]->getType()=="N")&&(i<6))
                {
                    cmpt++;
                    if(plateauJeu[i+2][posy]->getType()=="B")
                    {
                        for(int h=(posx+cmpt); cmpt>0; cmpt--)
                        {
                            h=(posx+cmpt);
                            plateauJeu[h][posy]->setMarquage(1);
                        }
                        cmpt=0;
                        compteur++;
                    }
                    i++;
                }
            }

            if(j>1)
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[posx][j-1]->getType()=="N")&&(j>1))
                {
                    cmpt++;
                    if(plateauJeu[posx][j-2]->getType()=="B")
                    {

                        for(cmpt; cmpt>0; cmpt--)
                        {
                            h=(posy-cmpt);
                            plateauJeu[posx][h]->setMarquage(1);
                        }
                        cmpt=0;
                        compteur++;
                    }
                    j--;
                }
            }

            if(j<6)
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[posx][j+1]->getType()=="N")&&(j<6))
                {
                    cmpt++;
                    if(plateauJeu[posx][j+2]->getType()=="B")
                    {
                        for(int h=(posy+cmpt); cmpt>0; cmpt--)
                        {
                            h=(posy+cmpt);
                            plateauJeu[posx][h]->setMarquage(1);
                        }
                        cmpt=0;
                        compteur++;
                    }
                    j++;
                }
            }

            ///Remontada Haut Gauche

            if((i>1)&&(j>1))
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[i-1][j-1]->getType()=="N")&&(i>1)&&(j>1))
                {
                    cmpt++;
                    if(plateauJeu[i-2][j-2]->getType()=="B")
                    {
                        for(cmpt; cmpt>0; cmpt--)
                        {
                            h=(posx-cmpt);
                            g=(posy-cmpt);
                            plateauJeu[h][g]->setMarquage(1);
                        }
                        cmpt=0;
                        compteur++;
                    }
                    i--;
                    j--;
                }
            }

            ///Remontada Bas Gauche

            if((i>1)&&(j<6))
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[i-1][j+1]->getType()=="N")&&(i>1)&&(j<6))
                {
                    cmpt++;
                    if(plateauJeu[i-2][j+2]->getType()=="B")
                    {
                        for(cmpt; cmpt>0; cmpt--)
                        {
                            h=(posx-cmpt);
                            g=(posy+cmpt);
                            plateauJeu[h][g]->setMarquage(1);
                        }
                        cmpt = 0;
                        compteur++;
                    }
                    i--;
                    j++;
                }
            }

            ///Remontada Bas droite

            if((i<6)&&(j<6))
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[i+1][j+1]->getType()=="N")&&(i<6)&&(j<6))
                {
                    cmpt++;
                    if(plateauJeu[i+2][j+2]->getType()=="B")
                    {
                        for(cmpt; cmpt>0; cmpt--)
                        {
                            h=(posx+cmpt);
                            g=(posy+cmpt);
                            plateauJeu[h][g]->setMarquage(1);
                        }
                        cmpt = 0;
                        compteur++;
                    }
                    i++;
                    j++;
                }
            }

            ///Remontada Haut Droite
            if((i<6)&&(j>1))
            {
                int i=posx;
                int j=posy;
                cmpt=0;
                while((plateauJeu[i+1][j-1]->getType()=="N")&&(j>1)&&(i<6))
                {
                    cmpt++;
                    if(plateauJeu[i+2][j-2]->getType()=="B")
                    {
                        for(cmpt; cmpt>0; cmpt--)
                        {
                            h=(posx+cmpt);
                            g=(posy-cmpt);
                            plateauJeu[h][g]->setMarquage(1);
                        }
                        cmpt = 0;
                        compteur++;
                    }
                    i++;
                    j--;
                }
            }
            if(compteur>0)
            {
                return true;
            }

            ///}
        }
    }
    return false;
}

void Plateau::retournerPion()
{
    int a,b;
    Console* pConsole;
    for(a=0; a<8; a++)
    {
        for(b=0; b<8; b++)
        {
            if((plateauJeu[a][b]->getType()=="N")&&(plateauJeu[a][b]->getMarquage()==1))
            {
                plateauJeu[a][b]->setType("B");
                plateauJeu[a][b]->setMarquage(0);
            }
            if((plateauJeu[a][b]->getType()=="B")&&(plateauJeu[a][b]->getMarquage()==1))
            {
                plateauJeu[a][b]->setType("N");
                plateauJeu[a][b]->setMarquage(0);
            }
        }
    }
}

void Plateau::ajouterPionIA(Coordonnes maCoord2)
{
    int posx=maCoord2.x;
    int posy=maCoord2.y;

    if(blindageAjouterPionSansConversion(maCoord2))
    {
        if(m_tour%2==1)
        {
            plateauJeu[posx][posy] = new Pion("B",posx,posy,0);
            compteurPions++;
        }
        if(m_tour%2==0)
        {
            plateauJeu[posx][posy] = new Pion("N",posx,posy,0);
            compteurPions++;
        }
        setTour(1);

    }

}

void Plateau::ajouterPion(Coordonnes maCoord)
{
    int posx=maCoord.x;
    int posy=maCoord.y;
    Console* pConsole;

    posx = (posx/4)-(7/4);
    posy = (posy/2)-2;

    if(blindageAjouterPion(maCoord))
    {
        if(m_tour%2==0)
        {
            plateauJeu[posx][posy] = new Pion("N",posx,posy,0);

        }
        else if(m_tour%2==1)
        {
            plateauJeu[posx][posy] = new Pion("B",posx,posy,0);

        }
        setTour(1);
    }
}

int Plateau::getTour()
{
    return m_tour;
}

void Plateau::setTour(int _tour)
{
    m_tour=m_tour+_tour;
}

bool Plateau::finDeJeu()
{
    Console* pConsole;
    int i,j;
    ///compteurPions=0;
    for(i=0; i<8; i++)
    {
        for(j=0; j<8; j++)
        {
            if(plateauJeu[i][j]->getType()=="N")
            {
                compteurPions++;
            }
        }
    }

    if(compteurPions==60)
    {
        return true;
    }
    else
    {
        return false;
    }
}
