#ifndef DI_JET
#define DI_JET

#include "RooAbsPdf.h"
#include "RooAbsReal.h"
#include "RooRealProxy.h"

class Dijet : public RooAbsPdf {
public:
    Dijet() {}
    Dijet(const char *name, const char *title, RooAbsReal& _mgg,
          RooAbsReal& _p1, RooAbsReal& _p2);
    Dijet(const Dijet& other, const char* name=0);
    TObject* clone(const char* newname) const override { return new Dijet(*this,newname); }

protected:
    RooRealProxy mgg, p1, p2;
    Double_t evaluate() const override;

    ClassDefOverride(Dijet,1)
};

#endif