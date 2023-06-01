#include <string>

#include <vector>

#include <list>

#include <iostream>

#include <assert.h>

#include "Campanha.h"

using namespace std;

Campanha::Campanha(string n) {
    nome = n;
}

bool Campanha::addTeste(string nome, int numero, Circuito escolha) {
    TestDrive* f = findTesteDrive(numero);
    if (f == NULL) {
        TestDrive t(nome, numero, escolha);
        return testedrive.insert(t);
    }
    else {
        cout << "A pessoa com o nome " << nome << " ja se encontra inscrita com o numero : " << numero << endl;
        return false;
    }

}

bool Campanha::addTeste(string nome, int numero, string data, Circuito escolha) {
    TestDrive* f = findTesteDrive(numero);
    if (f == NULL) {
        TestDrive t(nome, numero, data, escolha);
        return testedrive.insert(t);
    }
    else {
        cout << "A pessoa com o nome " << nome << " ja se encontra inscrita com o numero : " << numero << endl;
        return false;
    }

}

TestDrive* Campanha::findTesteDrive(int numero) {
    TestDrive d(numero);
    return testedrive.find(d);
}

TestDrive* Campanha::findTesteDriveC(float dist) {

    string nome;
    int numero = NULL;
    Circuito a(dist);
    TestDrive d(nome, numero, a);
    return testedrive.find(d);
}

void Campanha::setData(int numero, string data) {
    TestDrive* f = findTesteDrive(numero);
    if (f != NULL)
        f->setData(data);

}

void Campanha::setConsumo(int numero, float consumo) {
    TestDrive* f = findTesteDrive(numero);
    if (f != NULL)
        f->setConsumo(consumo);
}
Colecao<Circuito> Campanha::getCircuitosDist(float distancia) { // criar colecao de um tipo de circuito , que fica ordenado de acordo com o operator <
    Colecao<Circuito> circuitos;
    Colecao<TestDrive>::iterator it;
    for (it = testedrive.begin(); it != testedrive.end(); it++) {
        if (it->circuito.distancia == distancia)
            circuitos.insert(it->circuito);
    }
    return circuitos;
}

Colecao<TestDrive> Campanha::getTestDrivesDist(float distancia) { // criar colecao de teste drives de um tipo de circuito , 
    Colecao<TestDrive> testdrives;                                //que fica ordenado de acordo com o operator <
    Colecao<TestDrive>::iterator it;
    for (it = testedrive.begin(); it != testedrive.end(); it++) {
        if (it->circuito.distancia == distancia)
            testdrives.insert(*it);
    }
    return testdrives;
}

void printconsumos(string name, Colecao<TestDrive> testedrives) {
    cout << endl;
    cout << "Consumos Circuito " << name << ":" << endl;
    if (testedrives.size() == 0)
    {
        cout << '\t' << "Nao existem consumos para este Circuito" << endl;
        return;
    }

    Colecao < TestDrive > ::iterator it;
    for (it = testedrives.begin(); it != testedrives.end(); it++) {
        cout << '\t' << it->nomeCondutor << "(" << it->numCondutor << "): " << it->circuito.consumo;
        if (it->circuito.consumo == 0)
            cout << " TestDrive nao realizado" << endl;
        else
            cout << " Km/l" << endl;
    }
}

void Campanha::mostrarConsumosCMisto() {
    printconsumos("Misto", getTestDrivesDist(Misto().distancia));
}

void Campanha::mostrarConsumosCUrbano() {
    printconsumos("Urbano", getTestDrivesDist(Urbano().distancia));
}

void Campanha::mostrarConsumosCExtraurbano() {
    printconsumos("ExtraUrbano", getTestDrivesDist(ExtraUrbano().distancia));
}

void printmelhorconsumo(string name, Colecao<Circuito> circuitos) {
    cout << endl << "Melhor Consumo " << name << ": " << endl;
    if (circuitos.size() == 0) {
        cout << '\t' << "Ainda nao foram realizados TestDrives neste circuito" << endl;
        return;
    }
    Circuito melhor = *circuitos.begin(); // busca 1º elemento uma vez que ja esta ordenado graças ao operador < devido à class colecao ser um set
    if (melhor.consumo == 0) {
        Colecao < Circuito > ::iterator it;
        for (it = circuitos.begin(); it != circuitos.end(); it++) {
            if (melhor.consumo == 0)
                melhor = *it;
        }
    }
    if (melhor.consumo == 0)
        cout << '\t' << "Ainda nao foram realizados TestDrives neste circuito" << endl;
    else
        cout << '\t' << melhor.consumo << " Km/l" << endl;
}

void Campanha::melhorConsumoCMisto() {
    printmelhorconsumo("Misto", getCircuitosDist(Misto().distancia));
}

void Campanha::melhorConsumoCUrbano() {
    printmelhorconsumo("Urbano", getCircuitosDist(Urbano().distancia));
}

void Campanha::melhorConsumoCExtraurbano() {
    printmelhorconsumo("ExtraUrbano", getCircuitosDist(ExtraUrbano().distancia));
}

void Campanha::mostrarTodosTestDrives() {
    int n = 1;
    Colecao < TestDrive > ::iterator it;
    for (it = testedrive.begin(); it != testedrive.end(); it++, n++) {
        cout << endl << "Teste Drive numero " << n << endl << *it;
    }
}

void Campanha::mostrarTestDrive(int numero) {
    TestDrive* f = findTesteDrive(numero);
    if (f != NULL) {
        cout << endl << *f << endl;
    }
    else {
        cout << endl << "Teste Drive com o numero " << numero << " nao existe" << endl;
    }
}