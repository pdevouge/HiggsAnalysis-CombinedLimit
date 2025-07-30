#include <math.h>

#include "../interface/Expow.h"
#include "RooAbsReal.h"

ClassImp(Expow)

Expow::Expow(const char *name, const char *title, RooAbsReal& _mgg,
            RooAbsReal& _p1, RooAbsReal& _p2) :
    RooAbsPdf(name, title),
    mgg("mgg", "mgg", this, _mgg),
    p1("p1", "p1", this, _p1),
    p2("p2", "p2", this, _p2) {}

// Expow copy constructor
Expow::Expow(const Expow& other, const char* name) :
    RooAbsPdf(other, name),
    mgg("mgg", this, other.mgg),
    p1("p1", this, other.p1),
    p2("p2", this, other.p2) {}

Double_t Expow::evaluate() const {
    return exp(p1*mgg) * pow(mgg, p2);
}