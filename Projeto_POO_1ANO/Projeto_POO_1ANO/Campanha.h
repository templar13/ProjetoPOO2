#ifndef CAMPANHA_H
#define CAMPANHA_H

#include "TestDrive.h"

#include "Colecao.h"
#include "Misto.h"
#include "Urbano.h"
#include "ExtraUrbano.h"

using namespace std;

class Campanha {
private:
    string nome;
    Colecao < TestDrive > testedrive;

public:
    Campanha(string nome);

    bool addTeste(string nome, int numero, Circuito);

    bool addTeste(string nome, int numero, string data, Circuito);

    TestDrive* findTesteDrive(int numero);

    TestDrive* findTesteDriveC(float dist);

    Colecao<Circuito> getCircuitosDist(float distancia);

    Colecao<TestDrive> getTestDrivesDist(float distancia);

    void setData(int numero, string data);

    void setConsumo(int numero, float consumo);

    void mostrarConsumosCMisto();

    void mostrarConsumosCUrbano();

    void mostrarConsumosCExtraurbano();

    void melhorConsumoCMisto();

    void melhorConsumoCUrbano();

    void melhorConsumoCExtraurbano();

    void mostrarTodosTestDrives();

    void mostrarTestDrive(int numero);

};
#endif