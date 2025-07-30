#ifndef EX_POW
#define EX_POW

#include "RooAbsPdf.h"
#include "RooAbsReal.h"
#include "RooRealProxy.h"

class Expow : public RooAbsPdf {
public:
    Expow() {}
    Expow(const char *name, const char *title, RooAbsReal& _mgg,
          RooAbsReal& _p1, RooAbsReal& _p2);
    Expow(const Expow& other, const char* name=0);
    TObject* clone(const char* newname) const override { return new Expow(*this,newname); }

protected:
    RooRealProxy mgg, p1, p2;
    Double_t evaluate() const override;

    ClassDefOverride(Expow,1)
};

#endif