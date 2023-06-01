#include <string>

#include <vector>

#include <list>

#include <iostream>

#include <assert.h>

#include "Circuito.h"

using namespace std;

float calcularconsumo(float deposito, float distancia) {
    return  distancia / deposito;
}

Circuito::Circuito(float n) {
    distancia = n;
    consumo = 0;
}

Circuito::Circuito(float dist, float deposito) {
    distancia = dist;
    consumo = calcularconsumo(deposito, dist);
}

void Circuito::setConsumo(float deposito) {
    consumo = calcularconsumo(deposito, this->distancia);
}

bool Circuito::operator < (const Circuito& outra) const {
    return (consumo < outra.consumo);
}

float Circuito::getConsumo() {
    return consumo;
}

ostream& operator << (ostream& s,
    const Circuito&
    var) {
    if (var.distancia == 15) {
        s << '\t' << "Circuito Realizado : Misto " << endl;
    }
    else if (var.distancia == 23) {
        s << '\t' << "Circuito Realizado : Extra-Urbano " << endl;
    }
    else {
        s << '\t' << "Circuito Realizado : Urbano " << endl;
    }
    if (var.consumo == 0)
        s << '\t' << "TestDrive nao foi realizado " << endl;
    else
        s << '\t' << "Consumo medio: " <<
        var.consumo << " km/l" << endl;
    return s;
}