#include "JuegoRanas.h"

// Constructor y destructor
JuegoRanas::JuegoRanas(int nRanasEq){
    nRanitasEquipo = nRanasEq;
    llenarRanitas();
    nRanas = nRanitasEquipo*2;
};

JuegoRanas::~JuegoRanas(){
    for (int i = 0; i > nRanas; i++) {
        delete ranitas[i]; // Liberar memoria
    }
    cout << "Juego de ranitas eliminado" << endl;
};

void JuegoRanas::echo(){
    sortRanitas('v');
    cout << "\033[1;37m[ECHO] - Posicion de las ranitas: " << endl;
    string out;
    for (int i = 0; i < nRanitasEquipo*2; i++) {
        out += (ranitas[i]->getColorH() + "[-.-](" + to_string(ranitas[i]->getPosicion()) + ")");
        //cout << "La ranita " << ranitas[i]->getNombre() << " esta en la posicion " << ranitas[i]->getPosicion() << endl;
    }
    cout << out << endl;
};

void JuegoRanas::echoTeam(){
    cout << "[:TEAMS:]" << endl;
    for (int i = 0; i < nRanas; i++) {
        if (dynamic_cast<ranitaRoja*>(ranitas[i])) {
            cout << "La ranita " << ranitas[i]->getNombre() << " es una ranita roja" << endl;
        } else if (dynamic_cast<ranitaVerde*>(ranitas[i])) {
            cout << "La ranita " << ranitas[i]->getNombre() << " es una ranita verde" << endl;
        }
    }
}

void JuegoRanas::avanzarPrimeraRana(){
    if (primeraRana == nullptr) {
        cout << "No hay ranitas sorteadas en el juego" << endl;
    } else avanzar(*primeraRana);
}

vector<ranita*> JuegoRanas::getRanitasColor(char color){
    vector<ranita*> ranitasColor;
    sortRanitas(color);

    for (int i = 0; i < nRanas; i++){
        if (dynamic_cast<ranitaRoja*>(ranitas[i]) && color == 'r'){
            ranitasColor.push_back(ranitas[i]);
        }
        if (dynamic_cast<ranitaVerde*>(ranitas[i]) && color == 'v'){
            ranitasColor.push_back(ranitas[i]);
        }
    }
    return ranitasColor;
}

vector<ranita*> JuegoRanas::getRanitas(){
    return ranitas;
}

void JuegoRanas::avanzar(ranita &rana){
    int pos = rana.getPosicion();
    rana.advance();
    
    cout << rana.getColorH();
    cout << "\n - La Rana " << rana.getNombre() << " avanza!!" << endl;
    if (existeColision(rana)) {
        rana.advance();
        cout << "La rana tuvo que saltar" << endl;
    }
    if (existeColision(rana)) {
        cout << "\033[1;35mError, la ranita " << rana.getNombre() << " colisiono con otra ranita" << endl;
        this->echo();
        delete this;
    } else if (pos > nRanitasEquipo+1 || pos < -nRanitasEquipo-1) {
        cout << "Error, la ranita " << rana.getNombre() << " se salio del rango" << endl;
        this->echo();
        delete this;
    } else echo();
    //cout << "La ranita " << rana.getNombre() << " avanzo a la posicion " << rana.getPosicion() << endl;
};

/// ------- Funciones privadas de la clase JuegoRanas ------- ///
void JuegoRanas::llenarRanitas(){
    // Llenar el vector con ranitas rojas y verdes -F
    for (int i = 1; i < nRanitasEquipo+1; i++) {
        ranitas.push_back(new ranitaRoja(i)); // Llenar el vector con ranitas rojas
    }
    for (int i = -1; i > -1-nRanitasEquipo; i--) {
        ranitas.push_back(new ranitaVerde(i)); // Llenar el vector con ranitas verdes
    }
};

void JuegoRanas::sortRanitas(char color) { // Ordenar las ranitas para que avancen segun la que haya avanzado mas
    if (color == 'r') {
        sort(ranitas.begin(), ranitas.end(), comparePosicion); // Ordenar las ranitas de menor a mayor
    }
    else if (color == 'v') {
        sort(ranitas.begin(), ranitas.end(), comparePosicion2); // Ordenar las ranitas de mayor a menor
    }
    else {
        cout << "Error, color no valido" << endl;
    }
    primeraRana = ranitas[0];
};

bool JuegoRanas::existeColision(ranita &rana){
    int pos = rana.getPosicion();
    //Si la rana se encuantra en la misma posicion que otra rana
    for (ranita* r : ranitas) { 
        if (pos == r->getPosicion()) {
            if (&rana == r) continue; //si es la misma rana, ignorar
            return true; //si las ranas colisionan
        }
    }
    return false;
}

// Funciones SORT para ordenar las ranitas
bool JuegoRanas::comparePosicion(ranita* a, ranita* b) { // Ordenar mayor a menor
    // Ordenar mayor a menor
    return a->getPosicion() < b->getPosicion();
}
    
bool JuegoRanas::comparePosicion2(ranita* a, ranita* b) { // Ordenar mayor a menor
    // Ordenar mayor a menor
    return a->getPosicion() > b->getPosicion();
}