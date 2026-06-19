from __future__ import absolute_import, print_function

import fnmatch

from HiggsAnalysis.CombinedLimit.PhysicsModel import *

class HighMassModel(PhysicsModelBase):
    """High mass Xgg model"""
    # Yield = u*S+sqrt(u)*I+B = sqrt(u)*(S+Bggf+I)+(u-sqrt(u))*S-sqrt(u)*Bggf+Btot

    def doParametersOfInterest(self):
        """Create POI and other parameters, and define the POI set."""
        self.modelBuilder.doVar("mu[1,0,20]")
        # --- S+B+I ---#
        self.modelBuilder.factory_('expr::scale_S("@0-sqrt(@0)", mu)')
        self.modelBuilder.factory_('expr::scale_B("-sqrt(@0)", mu)')
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
        if not self.DC.isSignal[process]:
            if process == "sbi_mass":
                return "scale_SBI"
            elif process == "ggbox_mass"
                return "scale_B"
            return 1
        return "scale_S"

highMass = HighMassModel()