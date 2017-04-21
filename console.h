#ifndef CONSOLE_H_INCLUDED
#define CONSOLE_H_INCLUDED

#include <iostream>
#include <fstream>

class Coordonnes
{
public :
    int x;
    int y;


};

class Console
{
    private:
        // Empecher la cr�ation
        Console();
        ~Console();

        // Empecher la copie d'objet...
        Console& operator= (const Console&){ return *this;}
        Console (const Console&){}

        // Attributs
        static Console* m_instance;

        // M�thodes priv�es
        void _setColor(int front, int back);
    public:
        // M�thodes statiques (publiques)
        static Console* getInstance();
        static void deleteInstance();

        // M�thodes publiques
        void gotoLigCol(int lig, int col);
        bool isKeyboardPressed();
        int getInputKey();

};

#endif // CONSOLE_H_INCLUDED
