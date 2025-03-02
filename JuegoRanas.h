#ifndef JUEGORANAS_H
#define JUEGORANAS_H

#include "ranas.cpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


class JuegoRanas {
private:
    // Variables importantes
    vector<ranita*> ranitas; // Vector de ranitas
    int nRanitasEquipo; // Numero de ranitas en el equipo
    int nRanas;
    ranita* primeraRana = nullptr;
    
    void llenarRanitas();
    bool existeColision(ranita &rana);
    
    // Pre declaracion de funciones para sort
    static bool comparePosicion(ranita* a, ranita* b);
    static bool comparePosicion2(ranita* a, ranita* b);
    
    public:
    JuegoRanas(int nRanasEq);
    ~JuegoRanas();
    
    vector<ranita*> getRanitasColor(char color);
    vector<ranita*> getRanitas();
    void avanzar(ranita &rana);
    void avanzarPrimeraRana();
    void sortRanitas(char color);
    void echoTeam();
    void echo();

};

#endif // JUEGORANAS_H