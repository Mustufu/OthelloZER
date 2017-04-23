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
        // Empecher la création
        Console();
        ~Console();

        // Empecher la copie d'objet...
        Console& operator= (const Console&){ return *this;}
        Console (const Console&){}
        static Console* m_instance;

    public:
        // Méthodes statiques (publiques)
        static Console* getInstance();
        static void deleteInstance();
        void _setColor(int front, int back);

        // Méthodes publiques
        void gotoLigCol(int lig, int col);
        bool isKeyboardPressed();
        int getInputKey();

};

#endif // CONSOLE_H_INCLUDED
