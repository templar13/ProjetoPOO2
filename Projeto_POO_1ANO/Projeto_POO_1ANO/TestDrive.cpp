#include "TestDrive.h"

using namespace std;

TestDrive::TestDrive(int numero) : circuito(NULL) {
    numCondutor = numero;
    dataTeste.clear();
}

TestDrive::TestDrive(string nome, int numero, Circuito escolha) : circuito(escolha) {
    nomeCondutor = nome;
    numCondutor = numero;

}

TestDrive::TestDrive(string nome, int numero, string data, Circuito escolha) : circuito(escolha) {
    nomeCondutor = nome;
    numCondutor = numero;
    dataTeste = data;
}

bool TestDrive::operator < (const TestDrive& outra) const {
    return (numCondutor < outra.numCondutor);
}

string TestDrive::setData(string data) {
    return dataTeste = data;
}

void TestDrive::setConsumo(float consumo) {
    circuito.setConsumo(consumo);
}

float TestDrive::GetConsumo() {
    return circuito.getConsumo();
}

ostream& operator << (ostream& s,
    const TestDrive&
    var) {
    s << '\t' << "Nome condutor : " << var.nomeCondutor << endl;
    s << '\t' << "Numero condutor : " << var.numCondutor << endl;
    if (var.dataTeste == "") {
        s << '\t' << "Data teste: Nao marcado" << endl;
    }
    else {
        s << '\t' << "Data teste : " << var.dataTeste << endl;
    }
    s << var.circuito;
    return s;
}