#include <math.h>

#include "../interface/Dijet.h"
#include "RooAbsReal.h"

ClassImp(Dijet)

Dijet::Dijet(const char *name, const char *title, RooAbsReal& _mgg,
            RooAbsReal& _p1, RooAbsReal& _p2) :
    RooAbsPdf(name, title),
    mgg("mgg", "mgg", this, _mgg),
    p1("p1", "p1", this, _p1),
    p2("p2", "p2", this, _p2) {}

// Dijet copy constructor
Dijet::Dijet(const Dijet& other, const char* name) :
    RooAbsPdf(other, name),
    mgg("mgg", this, other.mgg),
    p1("p1", this, other.p1),
    p2("p2", this, other.p2) {}

Double_t Dijet::evaluate() const {
    return pow(mgg, p1 + p2*log(mgg));
}