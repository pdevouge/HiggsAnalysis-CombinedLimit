#include <math.h>

#include "../interface/InvPowLin.h"
#include "RooAbsReal.h"

ClassImp(InvPowLin)

InvPowLin::InvPowLin(const char *name, const char *title, RooAbsReal& _mgg,
                    RooAbsReal& _p1, RooAbsReal& _p2, RooAbsReal& _p3) :
    RooAbsPdf(name, title),
    mgg("mgg", "mgg", this, _mgg),
    p1("p1", "p1", this, _p1),
    p2("p2", "p2", this, _p2),
    p3("p3", "p3", this, _p3) {}

// InvPowLin copy constructor
InvPowLin::InvPowLin(const InvPowLin& other, const char* name) :
    RooAbsPdf(other, name),
    mgg("mgg", this, other.mgg),
    p1("p1", this, other.p1),
    p2("p2", this, other.p2),
    p3("p3", this, other.p3) {}

Double_t InvPowLin::evaluate() const {
    return pow(1 + mgg*p1, p2 + p3*mgg);
}