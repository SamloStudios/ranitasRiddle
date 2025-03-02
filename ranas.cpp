#include <iostream>
#include <string>

using namespace std;


class ranita {
    public:
    //Constructores
    ranita(){
        nombre = "ranita sin nombre";
    }
    ranita(int posicion) {
        this->posicion = posicion;
        nombre = "ranita " + to_string(posicion);
    }
    //Destructor
    virtual ~ranita() {} //Destructor

    //Metodos
    string getNombre() {
        return nombre;
    }
    char getColor(){
        return color;
    }
    string getColorH(){
        return colorH;
    }
    int getPosicion() {
        return posicion;
    }
    virtual void advance(){};

    protected:
    int posicion;
    string nombre;
    char color;
    string colorH; 
};

class ranitaVerde : public ranita {
    public:
    ranitaVerde(int posicion) : ranita(posicion) {
        color = 'v';
        colorH = "\033[1;32m"; //Colores ascci
    }
    void advance () override {
        posicion++;
    }
    void jump() {
        posicion += 2;
    }
};

class ranitaRoja : public ranita {
    public:
    ranitaRoja(int posicion) : ranita(posicion) {
        color = 'r';
        colorH = "\033[1;31m"; //Colores ascci
    }
    void advance() override {
        posicion--;
    }
    void jump() {
        posicion -= 2;
    }
};