#include "Misto.h"

using namespace std;

Misto::Misto() : Circuito(15) {}
Misto::Misto(float deposito) : Circuito(15, deposito) {}