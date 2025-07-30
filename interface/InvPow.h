#ifndef INV_POW
#define INV_POW

#include "RooAbsPdf.h"
#include "RooAbsReal.h"
#include "RooRealProxy.h"

class InvPow : public RooAbsPdf {
public:
    InvPow() {}
    InvPow(const char *name, const char *title, RooAbsReal& _mgg,
           RooAbsReal& _p1, RooAbsReal& _p2);
    InvPow(const InvPow& other, const char* name=0);
    TObject* clone(const char* newname) const override { return new InvPow(*this,newname); }

protected:
    RooRealProxy mgg, p1, p2;
    Double_t evaluate() const override;

    ClassDefOverride(InvPow,1)
};

#endif