#include "Urbano.h"

using namespace std;

Urbano::Urbano() : Circuito(10) {

}
Urbano::Urbano(float deposito) : Circuito(10, deposito) {}