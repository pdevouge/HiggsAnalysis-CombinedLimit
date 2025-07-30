#ifndef INV_POWLIN
#define INV_POWLIN

#include "RooAbsPdf.h"
#include "RooAbsReal.h"
#include "RooRealProxy.h"

class InvPowLin : public RooAbsPdf {
public:
    InvPowLin() {}
    InvPowLin(const char *name, const char *title, RooAbsReal& _mgg,
             RooAbsReal& _p1, RooAbsReal& _p2, RooAbsReal& _p3);
    InvPowLin(const InvPowLin& other, const char* name=0);
    TObject* clone(const char* newname) const override { return new InvPowLin(*this,newname); }

protected:
    RooRealProxy mgg, p1, p2, p3;
    Double_t evaluate() const override;

    ClassDefOverride(InvPowLin,1)
};

#endif