#ifndef CIRCUITO_H
#define CIRCUITO_H

#include <string>

#include <vector>

#include <list>

#include <iostream>

#include <assert.h>

using namespace std;

class Circuito {
public:
    float consumo;
    float distancia;

public:
    Circuito(float);
    Circuito(float distancia, float deposito);
    void setConsumo(float);
    float getConsumo();
    bool operator < (const Circuito& a) const;
    friend ostream& operator << (ostream& s,
        const Circuito&
        var);
};
#endif