from __future__ import absolute_import, print_function

import fnmatch

from HiggsAnalysis.CombinedLimit.PhysicsModel import *

class HighMassModel(PhysicsModelBase):
    """High mass Xgg model"""

    def doParametersOfInterest(self):
        """Create POI and other parameters, and define the POI set."""
        self.modelBuilder.doVar("mu[1,0,20]")
        # --- S+B+I ---#
        self.modelBuilder.factory_('expr::scale_S("@0-sqrt(@0)", mu)')
        self.modelBuilder.factory_('expr::scale_B("1-sqrt(@0)", mu)')
        self.modelBuilder.factory_('expr::scale_SBI("sqrt(@0)", mu)')
        self.modelBuilder.doSet("POI", "mu")
        # --- Higgs Mass as other parameter ----
        if self.options.mass != 0:
            if self.modelBuilder.out.var("MH"):
                self.modelBuilder.out.var("MH").removeRange()
                self.modelBuilder.out.var("MH").setVal(self.options.mass)
            else:
                self.modelBuilder.doVar("MH[%g]" % self.options.mass)

    def getYieldScale(self, bin, process):
        "Return the name of a RooAbsReal to scale this yield by or the two special values 1 and 0 (don't scale, and set to zero)"
        if not self.DC.isSignal[process]:
            return 1
        pname = process.lower()
        if 'rsg' or 'spin0' in pname:
            return "scale_S"
        if 'interference' in pname:
            return "scale_SBI"
        if 'ggbox' in pname:
            return "scale_B"
