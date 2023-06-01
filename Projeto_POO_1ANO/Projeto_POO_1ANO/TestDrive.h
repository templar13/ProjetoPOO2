#ifndef TEST_DRIVE_H
#define TEST_DRIVE_H

#include "Circuito.h"


using namespace std;

class Campanha;

class TestDrive {
public:
    string nomeCondutor;

    int numCondutor;

    string dataTeste;

    Circuito circuito;

public:
    TestDrive(int numero);

    TestDrive(string nome, int numero, Circuito);

    TestDrive(string nome, int numero, string data, Circuito);

    bool operator < (const TestDrive& a) const;

    string setData(string data);

    void setConsumo(float consumo);

    float GetConsumo();

    friend ostream& operator << (ostream& s,
        const TestDrive&
        var);
};
#endif