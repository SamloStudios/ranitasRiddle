#include <iostream>
#include <vector>
#include <algorithm>
#include "JuegoRanas.cpp"
#include <string>
using namespace std;

int main() {
    int n_ranas_por_equipo = 3;
    JuegoRanas* juego = new JuegoRanas(n_ranas_por_equipo);
    juego->echo();


    int cycle = 1;
    bool cycle_up = true;
    char color = 'r';
    while (cycle > 0)
    {
        for (int i = 0; i < cycle; i++) {
            vector<ranita*> ranas = juego->getRanitasColor(color);
            if (cycle == n_ranas_por_equipo) {
                for (int n = 0; n < n_ranas_por_equipo; n++) {
                    juego->avanzar(*ranas[n]);
                }
                cycle_up = false;
                if (i != cycle-1) color = (color == 'v') ? 'r' : 'v'; //Cambia el color
            } else if (!cycle_up) {
                juego->avanzar(*ranas[i + abs(n_ranas_por_equipo-cycle)]);
            } else {
                juego->avanzar(*ranas[i]);
            }
        }
        color = (color == 'v') ? 'r' : 'v'; //Cambia el color
        if (cycle_up) {
            cycle++;
        } else cycle--;
    }

    delete juego;

    return 0;
}