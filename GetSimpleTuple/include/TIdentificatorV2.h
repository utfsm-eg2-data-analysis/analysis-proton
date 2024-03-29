#ifndef TIDENTIFICATORV2_H
#define TIDENTIFICATORV2_H

#include "TClasTool.h"

#ifndef CLASTOOL_THEADERClass
#include "THEADERClass.h"
#endif

#ifndef CLASTOOL_TClasTool
#include "TClasTool.h"
#endif

#ifndef CLASTOOL_TDSTReader
#include "TDSTReader.h"
#endif

#ifndef CLASTOOL_TEVNTClass
#include "TEVNTClass.h"
#endif

#ifndef CLASTOOL_TCCPBClass
#include "TCCPBClass.h"
#endif

#ifndef CLASTOOL_TECPBClass
#include "TECPBClass.h"
#endif

#ifndef CLASTOOL_TGSIMClass
#include "TGSIMClass.h"
#endif

class TIdentificatorV2 {
 public:
  /*******************************/
  /*** PUBLIC FUNCTION MEMBERS ***/
  /***                         ***/
  /*******************************/

  TIdentificatorV2(TClasTool *CT = 0) : kEbeam(5.014), kMpi(0.139570), kMprt(0.938272), kMntr(0.939565), kGOOD(-1000.) {
    // Default constructor
    this->fCT = CT;
  }

  ~TIdentificatorV2() {
    // Default destructor
    fCT = 0;
  }

  Double_t NEvent() {
    // Returns event number from HEAD bank
    return ((THEADERClass *)fCT->GetHEADER())->GetNEvent();
  }

  Int_t NRowsDC() { return fCT->GetNRows("DCPB"); }

  Int_t NRowsEC() { return fCT->GetNRows("ECPB"); }

  Int_t NRowsCC() { return fCT->GetNRows("CCPB"); }

  Int_t NRowsSC() { return fCT->GetNRows("SCPB"); }

  /*** EVNT & GSIM ***/

  Double_t Betta(Int_t k, Bool_t kind = 0) {
    // Returns beta=velocity/c for the particle in the row k of the EVNT bank.
    // If kind is zero, the EVNT bank is used. If not, the GSIM bank is used instead.
    if (kind == 0) {
      fEVNT = (TEVNTClass *)fCT->GetBankRow("EVNT", k);
      return fEVNT->Betta;
    } else {
      fGSIM = (TGSIMClass *)fCT->GetBankRow("GSIM", k);
      return fGSIM->Betta;
      return 0;
    }
  }

  Double_t Id(Int_t k, Bool_t kind = 0) {
    // Returns the ID of the particle in the row k, from Particle Data Group (PDG),
    // estimated from some preliminary analysis during data calibration.
    // If kind is zero, the EVNT bank is used. If not, the GSIM bank is used instead.
    if (kind == 0) {
      fEVNT = (TEVNTClass *)fCT->GetBankRow("EVNT", k);
      return fEVNT->Id;
    } else {
      fGSIM = (TGSIMClass *)fCT->GetBankRow("GSIM", k);
      return fGSIM->Id;
    }
  }

  Double_t Charge(Int_t k, Bool_t kind = 0) {
    // Returns the electrical charge for the particle in the row k of the EVNT bank
    if (kind == 0) {
      fEVNT = (TEVNTClass *)fCT->GetBankRow("EVNT", k);
      return fEVNT->Charge;
    } else {
      fGSIM = (TGSIMClass *)fCT->GetBankRow("GSIM", k);
      return fGSIM->Charge;
    }
  }

  Double_t Px(Int_t k, Bool_t kind = 0) {
    // Returns the momentum X component for the particle in the row k
    if (kind == 0) {
      fEVNT = (TEVNTClass *)fCT->GetBankRow("EVNT", k);
      return fEVNT->Px;
    } else {
      fGSIM = (TGSIMClass *)fCT->GetBankRow("GSIM", k);
      return fGSIM->Px;
    }
  }

  Double_t Py(Int_t k, Bool_t kind = 0) {
    // Returns the momentum Y component for the particle in the row k
    if (kind == 0) {
      fEVNT = (TEVNTClass *)fCT->GetBankRow("EVNT", k);
      return fEVNT->Py;
    } else {
      fGSIM = (TGSIMClass *)fCT->GetBankRow("GSIM", k);
      return fGSIM->Py;
    }
  }

  Double_t Pz(Int_t k, Bool_t kind = 0) {
    // Returns the momentum Z component for the particle in the row k
    if (kind == 0) {
      fEVNT = (TEVNTClass *)fCT->GetBankRow("EVNT", k);
      return fEVNT->Pz;
    } else {
      fGSIM = (TGSIMClass *)fCT->GetBankRow("GSIM", k);
      return fGSIM->Pz;
    }
  }

  Double_t X(Int_t k, Bool_t kind = 0) {
    // Returns the X coordinate for the particle in the row k
    if (kind == 0) {
      fEVNT = (TEVNTClass *)fCT->GetBankRow("EVNT", k);
      return fEVNT->X;
    } else {
      fGSIM = (TGSIMClass *)fCT->GetBankRow("GSIM", k);
      return fGSIM->X;
    }
  }

  Double_t Y(Int_t k, Bool_t kind = 0) {
    // Returns the Y coordinate for the particle in the row k
    if (kind == 0) {
      fEVNT = (TEVNTClass *)fCT->GetBankRow("EVNT", k);
      return fEVNT->Y;
    } else {
      fGSIM = (TGSIMClass *)fCT->GetBankRow("GSIM", k);
      return fGSIM->Y;
    }
  }

  Double_t Z(Int_t k, Bool_t kind = 0) {
    // Returns the Z coordinate for the particle in the row k
    if (kind == 0) {
      fEVNT = (TEVNTClass *)fCT->GetBankRow("EVNT", k);
      return fEVNT->Z;
    } else {  // Fix this
      fGSIM = (TGSIMClass *)fCT->GetBankRow("GSIM", k);
      return fGSIM->Z;
    }
  }

  /*** EVNT ***/

  Int_t StatCC(Int_t k) {
    // Returns the CCPB key for the particle in the row k of the EVNT bank
    fEVNT = (TEVNTClass *)fCT->GetBankRow("EVNT", k);
    return fEVNT->Ccstat;
  }

  Int_t StatSC(Int_t k) {
    // Return the SCPB key for the particle in the row k of the EVNT bank
    fEVNT = (TEVNTClass *)fCT->GetBankRow("EVNT", k);
    return fEVNT->Scstat;
  }

  Int_t StatDC(Int_t k) {
    // Returns the DCPB key for the particle in the row k of the EVNT bank
    fEVNT = (TEVNTClass *)fCT->GetBankRow("EVNT", k);
    return fEVNT->Dcstat;
  }

  Int_t StatEC(Int_t k) {
    // Returns the ECPB key for the particle in the row k of the EVNT bank
    fEVNT = (TEVNTClass *)fCT->GetBankRow("EVNT", k);
    return fEVNT->Ecstat;
  }

  Double_t Status(Int_t k) {
    // Returns the event general goodness status for the particle in the row k of the EVNT bank
    fEVNT = (TEVNTClass *)fCT->GetBankRow("EVNT", k);
    return fEVNT->Status;
  }

  /*** CCPB ***/

  Double_t Nphe(Int_t k) {
    // Returns the number of photo-electrons in the CCPB for the particle in the row k of the EVNT bank
    fEVNT = (TEVNTClass *)fCT->GetBankRow("EVNT", k);
    if (fEVNT->Ccstat >= 1) {
      Int_t ccst = fEVNT->Ccstat - 1;
      fCCPB = (TCCPBClass *)fCT->GetBankRow("CCPB", ccst);
      return fCCPB->Nphe;
    } else {
      return kGOOD;
    }
  }

  Double_t Chi2CC(Int_t k) {
    // Returns the track definition concordance in the CCPB for the particle in the row k of the EVNT bank
    fEVNT = (TEVNTClass *)fCT->GetBankRow("EVNT", k);
    if (fEVNT->Ccstat >= 1) {
      Int_t cc_stat = fEVNT->Ccstat - 1;
      fCCPB = (TCCPBClass *)fCT->GetBankRow("CCPB", cc_stat);
      return fCCPB->Chi2cc;
    } else {
      return kGOOD;
    }
  }

  Double_t CCStatus(Int_t k) {
    // Returns the signal goodness in the CCPB for the particle in the row k of the EVNT bank
    fEVNT = (TEVNTClass *)fCT->GetBankRow("EVNT", k);
    if (fEVNT->Ccstat >= 1) {
      Int_t cc_stat = fEVNT->Ccstat - 1;
      fCCPB = (TCCPBClass *)fCT->GetBankRow("CCPB", cc_stat);
      return fCCPB->Status;
    } else {
      return kGOOD;
    }
  }

  /*** DCPB ***/

  Double_t DCStatus(Int_t k) {
    // Returns the signal goodness in the DCPB for the particle in the row k of the EVNT bank
    fEVNT = (TEVNTClass *)fCT->GetBankRow("EVNT", k);
    if (fEVNT->Dcstat >= 1) {
      Int_t dc_stat = fEVNT->Dcstat - 1;
      fDCPB = (TDCPBClass *)fCT->GetBankRow("DCPB", dc_stat);
      return fDCPB->Status;
    } else {
      return kGOOD;
    }
  }

  /*** ECPB ***/

  Double_t Etot(Int_t k) {
    // Returns total energy deposited in the calorimeter for the particle in the row k of the EVNT bank
    fEVNT = (TEVNTClass *)fCT->GetBankRow("EVNT", k);
    if (fEVNT->Ecstat >= 1) {
      Int_t ec_stat = fEVNT->Ecstat - 1;
      fECPB = (TECPBClass *)fCT->GetBankRow("ECPB", ec_stat);
      return fECPB->Etot;
    } else {
      return kGOOD;
    }
  }

  Double_t Ein(Int_t k) {
    // Returns the energy deposited in the inner part of the calorimeter for the particle in the row k of the EVNT bank
    fEVNT = (TEVNTClass *)fCT->GetBankRow("EVNT", k);
    if (fEVNT->Ecstat >= 1) {
      Int_t ec_stat = fEVNT->Ecstat - 1;
      fECPB = (TECPBClass *)fCT->GetBankRow("ECPB", ec_stat);
      return fECPB->Ein;
    } else {
      return kGOOD;
    }
  }

  Double_t Eout(Int_t k) {
    // Returns the energy deposited in the outer part of the calorimeter for the particle in the row k of the EVNT bank
    fEVNT = (TEVNTClass *)fCT->GetBankRow("EVNT", k);
    if (fEVNT->Ecstat >= 1) {
      Int_t ec_stat = fEVNT->Ecstat - 1;
      fECPB = (TECPBClass *)fCT->GetBankRow("ECPB", ec_stat);
      return fECPB->Eout;
    } else {
      return kGOOD;
    }
  }

  Double_t EChit_Moment2(Int_t k) {
    // (?)
    fEVNT = (TEVNTClass *)fCT->GetBankRow("EVNT", k);
    if (fEVNT->Ecstat >= 1) {
      Int_t ec_stat = fEVNT->Ecstat - 1;
      fECPB = (TECPBClass *)fCT->GetBankRow("ECPB", ec_stat);
      return fECPB->M2_hit;
    } else {
      return kGOOD;
    }
  }

  Double_t EChit_Moment3(Int_t k) {
    // (?)
    fEVNT = (TEVNTClass *)fCT->GetBankRow("EVNT", k);
    if (fEVNT->Ecstat >= 1) {
      Int_t ec_stat = fEVNT->Ecstat - 1;
      fECPB = (TECPBClass *)fCT->GetBankRow("ECPB", ec_stat);
      return fECPB->M3_hit;
    } else {
      return kGOOD;
    }
  }

  Double_t EChit_Moment4(Int_t k) {
    // (?)
    fEVNT = (TEVNTClass *)fCT->GetBankRow("EVNT", k);
    if (fEVNT->Ecstat >= 1) {
      Int_t ec_stat = fEVNT->Ecstat - 1;
      fECPB = (TECPBClass *)fCT->GetBankRow("ECPB", ec_stat);
      return fECPB->M4_hit;
    } else {
      return kGOOD;
    }
  }

  Double_t Chi2EC(Int_t k) {
    // (?)
    fEVNT = (TEVNTClass *)fCT->GetBankRow("EVNT", k);
    if (fEVNT->Ecstat >= 1) {
      Int_t ec_stat = fEVNT->Ecstat - 1;
      fECPB = (TECPBClass *)fCT->GetBankRow("ECPB", ec_stat);
      return fECPB->Chi2ec;
    } else {
      return kGOOD;
    }
  }

  Double_t ECStatus(Int_t k) {
    // Returns the signal goodness in the ECPB for the particle in the row k of the EVNT bank
    fEVNT = (TEVNTClass *)fCT->GetBankRow("EVNT", k);
    if (fEVNT->Ecstat >= 1) {
      Int_t ec_stat = fEVNT->Ecstat - 1;
      fECPB = (TECPBClass *)fCT->GetBankRow("ECPB", ec_stat);
      return fECPB->Status;
    } else {
      return kGOOD;
    }
  }

  Double_t XEC(Int_t k) {
    // (?)
    fEVNT = (TEVNTClass *)fCT->GetBankRow("EVNT", k);
    if (fEVNT->Ecstat >= 1) {
      Int_t ec_stat = fEVNT->Ecstat - 1;
      fECPB = (TECPBClass *)fCT->GetBankRow("ECPB", ec_stat);
      return fECPB->X;
    } else {
      return kGOOD;
    }
  }

  Double_t YEC(Int_t k) {
    // (?)
    fEVNT = (TEVNTClass *)fCT->GetBankRow("EVNT", k);
    if (fEVNT->Ecstat >= 1) {
      Int_t ec_stat = fEVNT->Ecstat - 1;
      fECPB = (TECPBClass *)fCT->GetBankRow("ECPB", ec_stat);
      return fECPB->Y;
    } else {
      return kGOOD;
    }
  }

  Double_t ZEC(Int_t k) {
    // (?)
    fEVNT = (TEVNTClass *)fCT->GetBankRow("EVNT", k);
    if (fEVNT->Ecstat >= 1) {
      Int_t ec_stat = fEVNT->Ecstat - 1;
      fECPB = (TECPBClass *)fCT->GetBankRow("ECPB", ec_stat);
      return fECPB->Z;
    } else {
      return kGOOD;
    }
  }

  Double_t TimeEC(Int_t k) {
    // (?)
    fEVNT = (TEVNTClass *)fCT->GetBankRow("EVNT", k);
    if (fEVNT->Ecstat >= 1) {
      Int_t ec_stat = fEVNT->Ecstat - 1;
      fECPB = (TECPBClass *)fCT->GetBankRow("ECPB", ec_stat);
      return fECPB->Time;
    } else {
      return kGOOD;
    }
  }

  Double_t PathEC(Int_t k) {
    // (?)
    fEVNT = (TEVNTClass *)fCT->GetBankRow("EVNT", k);
    if (fEVNT->Ecstat >= 1) {
      Int_t ec_stat = fEVNT->Ecstat - 1;
      fECPB = (TECPBClass *)fCT->GetBankRow("ECPB", ec_stat);
      return fECPB->Path;
    } else {
      return kGOOD;
    }
  }

  /*** SCPB ***/

  Double_t PathSC(Int_t k) {
    // Returns the path length from target, in the SCPB, for the particle in the row k of the EVNT bank
    fEVNT = (TEVNTClass *)fCT->GetBankRow("EVNT", k);
    if (fEVNT->Scstat >= 1) {
      Int_t sc_stat = fEVNT->Scstat - 1;
      fSCPB = (TSCPBClass *)fCT->GetBankRow("SCPB", sc_stat);
      return fSCPB->Path;
    } else {
      return kGOOD;
    }
  }

  Double_t TimeSC(Int_t k) {
    // Returns the flight time relative to the event start time, in the SCPB, for the particle in the row k of the EVNT bank
    fEVNT = (TEVNTClass *)fCT->GetBankRow("EVNT", k);
    if (fEVNT->Scstat >= 1) {
      Int_t sc_stat = fEVNT->Scstat - 1;
      fSCPB = (TSCPBClass *)fCT->GetBankRow("SCPB", sc_stat);
      return fSCPB->Time;
    } else {
      return kGOOD;
    }
  }

  Double_t EdepSC(Int_t k) {
    // Returns the deposited energy (dE/dX) in the SCPB, for the particle in the row k of the EVNT bank
    fEVNT = (TEVNTClass *)fCT->GetBankRow("EVNT", k);
    if (fEVNT->Scstat >= 1) {
      Int_t sc_stat = fEVNT->Scstat - 1;
      fSCPB = (TSCPBClass *)fCT->GetBankRow("SCPB", sc_stat);
      return fSCPB->Edep;
    } else {
      return kGOOD;
    }
  }

  Double_t SCStatus(Int_t k) {
    // Returns the signal goodness in the SCPB for the particle in the row k of the EVNT bank
    fEVNT = (TEVNTClass *)fCT->GetBankRow("EVNT", k);
    if (fEVNT->Scstat >= 1) {
      Int_t sc_stat = fEVNT->Scstat - 1;
      fSCPB = (TSCPBClass *)fCT->GetBankRow("SCPB", sc_stat);
      return fSCPB->Status;
    } else {
      return kGOOD;
    }
  }

  /*** MATHEMATICAL FUNCTIONS ***/

  Double_t Momentum(Int_t k, Bool_t kind = 0) {
    // Returns the full momentum for the particle in the row k
    return TMath::Sqrt(Px(k, kind) * Px(k, kind) + Py(k, kind) * Py(k, kind) + Pz(k, kind) * Pz(k, kind));
  }

  Double_t Mass2(Int_t k, Bool_t kind = 0) {
    // Returns the mass squared from the SC Time of Flight for the particle in the row k
    return Momentum(k, kind) * Momentum(k, kind) * (TMath::Power(Betta(k, kind), -2) - 1);
  }

  Double_t ThetaLab(Int_t k, Bool_t kind = 0) {
    // Returns the polar angle in Lab frame for the particle in the row k
    TVector3 v3p(Px(k, kind), Py(k, kind), Pz(k, kind));
    return v3p.Theta() * TMath::RadToDeg();
  }

  Double_t PhiLab(Int_t k, Bool_t kind = 0) {
    // Returns the azimuthal angle in Lab frame for the particle in the row k
    TVector3 v3p(Px(k, kind), Py(k, kind), Pz(k, kind));
    Double_t PhiLab_value = v3p.Phi() * TMath::RadToDeg();
    if (PhiLab_value < -30.) {
      return PhiLab_value + 360.;
    } else if (PhiLab_value > 330.) {
      return PhiLab_value - 360.;
    }                     // closure
    return PhiLab_value;  // default
  }

  Double_t ThetaVirtLab(Bool_t kind = 0) {
    // Returns the polar angle of the virtual photon in Lab frame
    // The virtual photon information depends on the electron info
    return TMath::ACos((kEbeam - Momentum(0, kind) * TMath::Cos(ThetaLab(0, kind) * TMath::Pi() / 180.)) /
                       (TMath::Sqrt(Q2(kind) + Nu(kind) * Nu(kind))));
  }

  Double_t PhiVirtLab(Bool_t kind = 0) {
    // Return the azimuthal angle of the virtual photon in Lab frame
    if (PhiLab(0, kind) > 0) {
      return PhiLab(0, kind) - 180.;
    }  // closure
    return PhiLab(0, kind) + 180.;
  }

  Double_t ThetaPQ(Int_t k, Bool_t kind = 0) {
    // Return the polar angle of the particle w.r.t. the virtual photon direction
    // It's defined as the angle between both particle's momentum
    TVector3 Vpi(Px(k, kind), Py(k, kind), Pz(k, kind));
    TVector3 Vvirt(-Px(0, kind), -Py(0, kind), kEbeam - Pz(0, kind));
    return Vvirt.Angle(Vpi) * TMath::RadToDeg();
  }

  Double_t PhiPQ(Int_t k, Bool_t kind = 0) {
    // Returns the azimuthal angle of the particle w.r.t. the virtual photon direction
    // First, it Z-rotates the virtual photon momentum to have Y-component=0
    // Second, it Z-rotates the particle momentum by the same amount
    // Third, it Y-rotates the virtual photon to have X-component=0
    // Lastly, it Y-rotates the particle momentum by the same amount
    // In the end, the values of the particle momentum components will be w.r.t to the virtual photon momentum
    TVector3 Vpi(Px(k, kind), Py(k, kind), Pz(k, kind));
    TVector3 Vvirt(-Px(0, kind), -Py(0, kind), kEbeam - Pz(0, kind));
    Double_t phi_z = TMath::Pi() - Vvirt.Phi();
    Vvirt.RotateZ(phi_z);
    Vpi.RotateZ(phi_z);
    TVector3 Vhelp(0., 0., 1.);
    Double_t phi_y = Vvirt.Angle(Vhelp);
    Vvirt.RotateY(phi_y);
    Vpi.RotateY(phi_y);
    return Vpi.Phi() * TMath::RadToDeg();
  }

  Double_t CosThetaPQ(Int_t k, Bool_t kind = 0) {
    // Returns the cosine of ThetaPQ for the particle
    return (Pz(k, kind) * (kEbeam - Pz(0, kind)) - Px(k, kind) * Px(0, kind) - Py(k, kind) * Py(0, kind)) /
           (TMath::Sqrt(Nu(kind) * Nu(kind) + Q2(kind)) * Momentum(k, kind));
  }

  Int_t Sector(Int_t k, Bool_t kind = 0) {
    // Returns the sector of the CLAS detector where the particle was detected
    if (PhiLab(k, kind) == 330.) {
      return 5;
    }  // closure
    return int((PhiLab(k, kind) + 90.) / 60.) - 1;
  }

  /*** Electron Variables ***/

  Double_t Q2(Bool_t kind = 0) {
    // Returns the four-momentum transfer of the electron-nucleon interaction
    return 4. * kEbeam * Momentum(0, kind) * TMath::Sin(ThetaLab(0, kind) * TMath::DegToRad() / 2) *
           TMath::Sin(ThetaLab(0, kind) * TMath::DegToRad() / 2);
  }

  Double_t W(Bool_t kind = 0) {
    // Returns the invariant mass of the electron-nucleon interaction
    return TMath::Sqrt(kMprt * kMprt + 2. * kMprt * Nu(kind) - Q2(kind));
  }

  Double_t Nu(Bool_t kind = 0) {
    // Returns the energy transfer of the electron-nucleon interaction
    return kEbeam - Momentum(0, kind);
  }

  Double_t Xb(Bool_t kind = 0) {
    // Returns the energy transfer of the electron-nucleon interaction
    return Q2(kind) / 2. / Nu(kind) / kMprt;
  }

  Double_t Yb(Bool_t kind = 0) {
    // Returns the energy transfer of the electron-nucleon interaction
    return Nu(kind) / kEbeam;
  }

  TVector3 *GetCorrectedVert() {
    // Returns electron's vertex correction (only for data and simrec)
    TVector3 RotatedVertPos(X(0), Y(0), Z(0));
    TVector3 RotatedVertDir(Px(0), Py(0), Pz(0));
    TVector3 TargetPos(0.043, -0.33, 0);
    Double_t sect = Sector(0);
    RotatedVertPos.RotateZ(-TMath::DegToRad() * 60. * sect);
    RotatedVertDir.RotateZ(-TMath::DegToRad() * 60. * sect);
    TargetPos.RotateZ(-TMath::DegToRad() * 60. * sect);
    Double_t ShiftLength = (TargetPos.X() - RotatedVertPos.X()) / RotatedVertDir.X();
    RotatedVertDir = ShiftLength * RotatedVertDir;
    RotatedVertPos = RotatedVertPos + RotatedVertDir;
    TVector3 *V_corr = new TVector3();
    V_corr->SetX((RotatedVertPos - TargetPos).X());
    V_corr->SetY((RotatedVertPos - TargetPos).Y());
    V_corr->SetZ(RotatedVertPos.Z());
    return V_corr;
  }

  Int_t TargType(TString dataKind, TString targetOption) {
    // assigns TargType according to corrected vertex cut
    // Taisiya Mineeva & Orlando Soto cuts
    if (dataKind == "data") {
      if (targetOption == "C" && GetCorrectedVert()->Z() > -25.33 && GetCorrectedVert()->Z() < -24.10) {
        return 2;
      } else if (targetOption == "Fe" && GetCorrectedVert()->Z() > -25.65 && GetCorrectedVert()->Z() < -24.26) {
        return 2;
      } else if (targetOption == "Pb" && GetCorrectedVert()->Z() > -25.54 && GetCorrectedVert()->Z() < -24.36) {
        return 2;
      } else if (GetCorrectedVert()->Z() > -31.80 && GetCorrectedVert()->Z() < -28.40) {
        return 1;  // liquid
      }
    } else if (dataKind == "sim") {
      if (targetOption == "D")
        return 1;
      else if (targetOption == "C")
        return 2;
      else if (targetOption == "Fe")
        return 2;
      else if (targetOption == "Pb")
        return 2;
    }  // closure
    return 0;
  }

  Int_t TargTypeSM(TString dataKind, TString targetOption, Int_t kind = 0) {
    // assigns TargType according to vertex cut
    Int_t sector = Sector(0, kind);
    // Sebastián Morán vertex cuts
    Double_t shift[6] = {0.1, -0.4, -0.6, -0.1, 0.4, 0.6};
    if (dataKind == "data") {
      // Raphael Dupré cuts
      if (targetOption == "C") {
        if (TMath::Abs(-30.1 - Z(0) + shift[sector]) < 2.0)
          return 1;
        else if (TMath::Abs(-24.7 - Z(0) + shift[sector]) < 1.5)
          return 2;
      } else if (targetOption == "Fe") {
        if (TMath::Abs(-30.2 - Z(0) + shift[sector]) < 2.0)
          return 1;
        else if (TMath::Abs(-24.9 - Z(0) + shift[sector]) < 1.5)
          return 2;
      } else if (targetOption == "Pb") {
        if (TMath::Abs(-30.1 - Z(0) + shift[sector]) < 2.0)
          return 1;
        else if (TMath::Abs(-24.9 - Z(0) + shift[sector]) < 1.5)
          return 2;
      }
    } else if (dataKind == "sim") {
      // Hayk Hakobyan cuts
      if ((sector == 0) * (-32.50 < Z(0, kind) && Z(0, kind) < -28.00) + (sector == 1) * (-32.50 < Z(0, kind) && Z(0, kind) < -27.50) +
          (sector == 2) * (-32.00 < Z(0, kind) && Z(0, kind) < -27.25) + (sector == 3) * (-32.00 < Z(0, kind) && Z(0, kind) < -27.75) +
          (sector == 4) * (-32.50 < Z(0, kind) && Z(0, kind) < -28.35) + (sector == 5) * (-33.50 < Z(0, kind) && Z(0, kind) < -28.75)) {
        return 1;  // liquid
      } else if ((sector == 0) * (-26.50 < Z(0, kind) && Z(0, kind) < -20.00) +
                 (sector == 1) * (-26.00 < Z(0, kind) && Z(0, kind) < -20.00) +
                 (sector == 2) * (-25.65 < Z(0, kind) && Z(0, kind) < -20.00) +
                 (sector == 3) * (-25.85 < Z(0, kind) && Z(0, kind) < -20.00) +
                 (sector == 4) * (-26.65 < Z(0, kind) && Z(0, kind) < -20.00) +
                 (sector == 5) * (-27.15 < Z(0, kind) && Z(0, kind) < -20.00)) {
        return 2;  // solid
      }
    }          // closure
    return 0;  // default value
  }

  /*** Hadron variables ***/

  Double_t Zh(Int_t k, Bool_t kind = 0, Double_t mass = 0.13957) {
    // Returns the energy fraction of the particle
    return TMath::Sqrt(mass * mass + Momentum(k, kind) * Momentum(k, kind)) / Nu(kind);
  }

  Double_t Pt2(Int_t k, Bool_t kind = 0) {
    // Returns the square of the transverse momentum component w.r.t. the virtual photon direction
    return Momentum(k, kind) * Momentum(k, kind) * (1 - CosThetaPQ(k, kind) * CosThetaPQ(k, kind));
  }

  Double_t Pl2(Int_t k, Bool_t kind = 0) {
    // Returns the square of the longitudinal momentum component w.r.t. the virtual photon direction
    return Momentum(k, kind) * Momentum(k, kind) * CosThetaPQ(k, kind) * CosThetaPQ(k, kind);
  }

  Double_t Mx2(Int_t k, Bool_t kind = 0, Double_t mass = 0.13957) {
    // Returns missing mass of the particle
    return W(kind) * W(kind) - 2. * Nu(kind) * Zh(k, kind, mass) * (Nu(kind) + kMprt) + mass * mass +
           2. * TMath::Sqrt((Q2(kind) + Nu(kind) * Nu(kind)) * Pl2(k, kind));
  }

  Double_t T(Int_t k, Bool_t kind = 0, Double_t mass = 0.13957) {
    // (?)
    return 2. * TMath::Sqrt((Nu(kind) * Nu(kind) + Q2(kind)) * Pl2(k, kind)) + mass * mass - Q2(kind) -
           2. * Nu(kind) * Nu(kind) * Zh(k, kind, mass);
  }

  /*** Corrections ***/

  Double_t TimeCorr4(Int_t k, Double_t mass = 0.93827) {
    // Time correction: compares timing of particle with electron. Edited mass=0.13957 (pion mass) to proton's mass from PDG
    return (PathSC(0) / 30.) - TimeSC(0) + TimeSC(k) - (PathSC(k) / 30.) * TMath::Sqrt(TMath::Power(mass / Momentum(k), 2) + 1);
  }

  TVector3 *XYZToUVW(TVector3 *xyz) {
    // Returns (?)
    Double_t ex = 0., wy = 0., zd = 0.;
    Double_t yu = 0., ve = 0., wu = 0.;
    Double_t xi = 0., yi = 0., zi = 0.;
    Double_t ec_phy = 0.;
    Double_t phy = 0.;
    Double_t rot[3][3];
    // parameters
    const Double_t ec_the = 0.4363323;
    const Double_t ylow = -182.974;
    const Double_t yhi = 189.956;
    const Double_t tgrho = 1.95325;
    const Double_t sinrho = 0.8901256;
    const Double_t cosrho = 0.455715;
    // variables
    ex = xyz->X();
    wy = xyz->Y();
    zd = xyz->Z();
    phy = TMath::ATan2(wy, ex) * 57.29578;
    if (phy < 0.) {
      phy = phy + 360;
    }
    phy = phy + 30.;
    if (phy > 360.) {
      phy = phy - 360.;
    }
    ec_phy = ((Int_t)(phy / 60.)) * 1.0471975;
    rot[0][0] = TMath::Cos(ec_the) * TMath::Cos(ec_phy);
    rot[0][1] = -TMath::Sin(ec_phy);
    rot[0][2] = TMath::Sin(ec_the) * TMath::Cos(ec_phy);
    rot[1][0] = TMath::Cos(ec_the) * TMath::Sin(ec_phy);
    rot[1][1] = TMath::Cos(ec_phy);
    rot[1][2] = TMath::Sin(ec_the) * TMath::Sin(ec_phy);
    rot[2][0] = -TMath::Sin(ec_the);
    rot[2][1] = 0.;
    rot[2][2] = TMath::Cos(ec_the);
    yi = ex * rot[0][0] + wy * rot[1][0] + zd * rot[2][0];
    xi = ex * rot[0][1] + wy * rot[1][1] + zd * rot[2][1];
    zi = ex * rot[0][2] + wy * rot[1][2] + zd * rot[2][2];
    zi = zi - 510.32;
    yu = (yi - ylow) / sinrho;
    ve = (yhi - ylow) / tgrho - xi + (yhi - yi) / tgrho;
    wu = ((yhi - ylow) / tgrho + xi + (yhi - yi) / tgrho) / 2. / cosrho;
    TVector3 *uvw = new TVector3(yu, ve, wu);
    return uvw;
  }

  Bool_t SampFracCheck(Int_t k, TString dataKind, TString targetOption) {
    // Sampling Fraction Cut exclusive for electrons
    /*
    // Just in case, Taisiya Mineeva cuts for sim
    // MeanE  = 0.2623 + 0.0089*p - 0.0019*p*p;
    // SigmaE = TMath::Sqrt(0.0057*0.0057 + 0.0305*0.0305/p);
    */
    Double_t E = TMath::Max(Etot(k), Ein(k) + Eout(k));
    Double_t p = Momentum(k);
    Int_t s = Sector(k);
    Double_t MeanE;
    Double_t SigmaE;
    if (dataKind == "data") {
      if (targetOption == "C") {
        MeanE = kCPar[s][0] + kCPar[s][1] * p + kCPar[s][2] * p * p;
        SigmaE = TMath::Sqrt(kCPar[s][3] * kCPar[s][3] + kCPar[s][4] * kCPar[s][4] / p);
      } else if (targetOption == "Fe") {
        MeanE = kFePar[s][0] + kFePar[s][1] * p + kFePar[s][2] * p * p;
        SigmaE = TMath::Sqrt(kFePar[s][3] * kFePar[s][3] + kFePar[s][4] * kFePar[s][4] / p);
      } else if (targetOption == "Pb") {
        MeanE = kPbPar[s][0] + kPbPar[s][1] * p + kPbPar[s][2] * p * p;
        SigmaE = TMath::Sqrt(kPbPar[s][3] * kPbPar[s][3] + kPbPar[s][4] * kPbPar[s][4] / p);
      }
    } else if (dataKind == "sim") {
      if (targetOption == "D") {
        MeanE = kDPar_Sim[s][0] + kDPar_Sim[s][1] * p + kDPar_Sim[s][2] * p * p;
        SigmaE = TMath::Sqrt(kDPar_Sim[s][3] * kDPar_Sim[s][3] + kDPar_Sim[s][4] * kDPar_Sim[s][4] / p);
      } else if (targetOption == "C") {
        MeanE = kCPar_Sim[s][0] + kCPar_Sim[s][1] * p + kCPar_Sim[s][2] * p * p;
        SigmaE = TMath::Sqrt(kCPar_Sim[s][3] * kCPar_Sim[s][3] + kCPar_Sim[s][4] * kCPar_Sim[s][4] / p);
      } else if (targetOption == "Fe") {
        MeanE = kFePar_Sim[s][0] + kFePar_Sim[s][1] * p + kFePar_Sim[s][2] * p * p;
        SigmaE = TMath::Sqrt(kFePar_Sim[s][3] * kFePar_Sim[s][3] + kFePar_Sim[s][4] * kFePar_Sim[s][4] / p);
      } else if (targetOption == "Pb") {
        MeanE = kPbPar_Sim[s][0] + kPbPar_Sim[s][1] * p + kPbPar_Sim[s][2] * p * p;
        SigmaE = TMath::Sqrt(kPbPar_Sim[s][3] * kPbPar_Sim[s][3] + kPbPar_Sim[s][4] * kPbPar_Sim[s][4] / p);
      }
    }
    // final step
    if (TMath::Abs(E / p - MeanE) < 2.5 * SigmaE) {
      return true;
    }  // closure
    return false;
  }

  TLorentzVector *GetCorrPhotonMomentum(Int_t k) {
    // measure gammas by detection at EC
    Double_t fGammaE, fGammaRt, fGammaR, fGammaThetaEC, fGammaPhiEC, fGammaPx, fGammaPy, fGammaPz;
    fGammaE = TMath::Max(Etot(k), Ein(k) + Eout(k)) / 0.272;
    fGammaRt = TMath::Sqrt(XEC(k) * XEC(k) + YEC(k) * YEC(k));
    fGammaR = TMath::Sqrt(XEC(k) * XEC(k) + YEC(k) * YEC(k) + (ZEC(k) - GetCorrectedVert()->Z()) * (ZEC(k) - GetCorrectedVert()->Z()));
    fGammaThetaEC = TMath::ASin(fGammaRt / fGammaR);
    fGammaPhiEC = TMath::ATan2(YEC(k), XEC(k));
    fGammaPx = fGammaE * TMath::Sin(fGammaThetaEC) * TMath::Cos(fGammaPhiEC);
    fGammaPy = fGammaE * TMath::Sin(fGammaThetaEC) * TMath::Sin(fGammaPhiEC);
    fGammaPz = fGammaE * TMath::Cos(fGammaThetaEC);
    TLorentzVector *fGammaP = new TLorentzVector(fGammaPx, fGammaPy, fGammaPz, fGammaE);
    return fGammaP;
  }

  /*** Electron DC Fiducial Cuts ***/

  Double_t FidThetaMin(Int_t k) {
    // minimum DC theta angle
    Int_t sector = Sector(k);
    Double_t theta_min_val = kThetaPar0[sector] + kThetaPar1[sector] / TMath::Power(Momentum(k), 2) + kThetaPar2[sector] * Momentum(k) +
                             kThetaPar3[sector] / Momentum(k) + kThetaPar4[sector] * TMath::Exp(kThetaPar5[sector] * Momentum(k));
    return theta_min_val;
  }

  Double_t FidFunc(Int_t k, Int_t side, Int_t param) {
    // (?)
    Int_t sector = Sector(k);
    if (side == 0 && param == 0) {
      return kFidPar0Low0[sector] + kFidPar0Low1[sector] * TMath::Exp(kFidPar0Low2[sector] * (Momentum(k) - kFidPar0Low3[sector]));
    } else if (side == 1 && param == 0) {
      return kFidPar0High0[sector] + kFidPar0High1[sector] * TMath::Exp(kFidPar0High2[sector] * (Momentum(k) - kFidPar0High3[sector]));
    } else if (side == 0 && param == 1) {
      return kFidPar1Low0[sector] +
             kFidPar1Low1[sector] * Momentum(k) * TMath::Exp(kFidPar1Low2[sector] * TMath::Power((Momentum(k) - kFidPar1Low3[sector]), 2));
    } else if (side == 1 && param == 1) {
      return kFidPar1High0[sector] + kFidPar1High1[sector] * Momentum(k) *
                                         TMath::Exp(kFidPar1High2[sector] * TMath::Power((Momentum(k) - kFidPar1High3[sector]), 2));
    }            // closure
    return 0.0;  // default
  }

  Double_t FidPhiMin(Int_t k) {
    // minimum DC phi angle
    Int_t sector = Sector(k);
    if (ThetaLab(k, 0) > FidThetaMin(k)) {
      return 60. * sector - FidFunc(k, 0, 0) * (1 - 1 / (1 + (ThetaLab(k, 0) - FidThetaMin(k)) / FidFunc(k, 0, 1)));
    }  // closure
    return 60. * sector;
  }

  Double_t FidPhiMax(Int_t k) {
    // maximum DC phi angle
    Int_t sector = Sector(k);
    if (ThetaLab(k, 0) > FidThetaMin(k)) {
      return 60. * sector + FidFunc(k, 1, 0) * (1 - 1 / (1 + (ThetaLab(k, 0) - FidThetaMin(k)) / FidFunc(k, 1, 1)));
    }  // closure
    return 60. * sector;
  }

  Bool_t FidCheckCut(Int_t k) {
    // checks DC fiducial cut for electrons
    if (ThetaLab(k, 0) > FidThetaMin(k) && PhiLab(k, 0) > FidPhiMin(k) && PhiLab(k, 0) < FidPhiMax(k)) {
      return 1;
    }  // closure
    return 0;
  }

  /*** PiPlus DC Fiducial Cuts ***/

  Double_t FidThetaMinPiPlus(Int_t k) {
    Int_t sector = Sector(k);
    Double_t theta_min_val = kThetaPar0PiPlus[sector] + kThetaPar1PiPlus[sector] / TMath::Power(Momentum(k), 2) +
                             kThetaPar2PiPlus[sector] * Momentum(k) + kThetaPar3PiPlus[sector] / Momentum(k) +
                             kThetaPar4PiPlus[sector] * TMath::Exp(kThetaPar5PiPlus[sector] * Momentum(k));
    return theta_min_val;
  }

  Double_t FidFuncPiPlus(Int_t k, Int_t side, Int_t param) {
    Int_t sector = Sector(k);
    if (side == 0 && param == 0) {
      return kFidPar0Low0PiPlus[sector] +
             kFidPar0Low1PiPlus[sector] * TMath::Exp(kFidPar0Low2PiPlus[sector] * (Momentum(k) - kFidPar0Low3PiPlus[sector]));
    } else if (side == 1 && param == 0) {
      return kFidPar0High0PiPlus[sector] +
             kFidPar0High1PiPlus[sector] * TMath::Exp(kFidPar0High2PiPlus[sector] * (Momentum(k) - kFidPar0High3PiPlus[sector]));
    } else if (side == 0 && param == 1) {
      return kFidPar1Low0PiPlus[sector] +
             kFidPar1Low1PiPlus[sector] * Momentum(k) *
                 TMath::Exp(kFidPar1Low2PiPlus[sector] * TMath::Power((Momentum(k) - kFidPar1Low3PiPlus[sector]), 2));
    } else if (side == 1 && param == 1) {
      return kFidPar1High0PiPlus[sector] +
             kFidPar1High1PiPlus[sector] * Momentum(k) *
                 TMath::Exp(kFidPar1High2PiPlus[sector] * TMath::Power((Momentum(k) - kFidPar1High3PiPlus[sector]), 2));
    }  // closure
    return 0.0;
  }

  Double_t FidPhiMinPiPlus(Int_t k) {
    Int_t sector = Sector(k);
    if (ThetaLab(k) > FidThetaMinPiPlus(k)) {
      return 60. * sector - FidFuncPiPlus(k, 0, 0) * (1 - 1 / (1 + (ThetaLab(k) - FidThetaMinPiPlus(k)) / FidFuncPiPlus(k, 0, 1)));
    }  // closure
    return 60. * sector;
  }

  Double_t FidPhiMaxPiPlus(Int_t k) {
    Int_t sector = Sector(k);
    if (ThetaLab(k) > FidThetaMinPiPlus(k)) {
      return 60. * sector + FidFuncPiPlus(k, 1, 0) * (1 - 1 / (1 + (ThetaLab(k) - FidThetaMinPiPlus(k)) / FidFuncPiPlus(k, 1, 1)));
    }  // closure
    return 60. * sector;
  }

  Bool_t FidCheckCutPiPlus(Int_t k) {
    // checks DC fiducial cut for pi+
    if (ThetaLab(k) > FidThetaMinPiPlus(k) && PhiLab(k) > FidPhiMinPiPlus(k) && PhiLab(k) < FidPhiMaxPiPlus(k)) {
      return 1;
    }  // closure
    return 0;
  }

  /*** PID cuts ***/

  Bool_t ElectronPhaseSpace(Int_t k, TString dataKind) {
    if (dataKind == "sim") {
      if ((Etot(k) / 0.27 > (Sector(k) == 0 || Sector(k) == 1) * (1.03 * Momentum(k) - 0.42) +
                                (Sector(k) == 2) * (1.05 * Momentum(k) - 0.46) + (Sector(k) == 3) * (1.03 * Momentum(k) - 0.44) +
                                (Sector(k) == 4) * (1.06 * Momentum(k) - 0.46) + (Sector(k) == 5) * (1.04 * Momentum(k) - 0.47)) &&
          (Etot(k) / 0.27 < (Sector(k) == 0 || Sector(k) == 1 || Sector(k) == 2) * (1.05 * Momentum(k) + 0.21) +
                                (Sector(k) == 3) * (1.03 * Momentum(k) + 0.23) + (Sector(k) == 4) * (1.06 * Momentum(k) + 0.20) +
                                (Sector(k) == 5) * (1.04 * Momentum(k) + 0.22)) &&
          ((Ein(k) / 0.27 + Eout(k) / 0.27) < (Sector(k) == 0 || Sector(k) == 1) * (1.13 * Momentum(k)) +
                                                  (Sector(k) == 2 || Sector(k) == 3 || Sector(k) == 5) * (1.14 * Momentum(k)) +
                                                  (Sector(k) == 4) * (1.15 * Momentum(k))) &&
          ((Ein(k) / 0.27 + Eout(k) / 0.27) > (Sector(k) == 0 || Sector(k) == 1) * (0.79 * Momentum(k)) +
                                                  (Sector(k) == 2 || Sector(k) == 5) * (0.79 * Momentum(k)) +
                                                  (Sector(k) == 3) * (0.79 * Momentum(k)) + (Sector(k) == 4) * (0.79 * Momentum(k)))) {
        return true;
      }
    } else if (dataKind == "data") {
      if ((Etot(k) / 0.27 > (Sector(k) == 0 || Sector(k) == 1) * (1.05 * Momentum(k) - 0.46) +
                                (Sector(k) == 2 || Sector(k) == 4 || Sector(k) == 5) * (1.11 * Momentum(k) - 0.43) +
                                (Sector(k) == 3) * (1.07 * Momentum(k) - 0.43)) &&
          (Etot(k) / 0.27 < (Sector(k) == 0 || Sector(k) == 1) * (1.05 * Momentum(k) + 0.18) +
                                (Sector(k) == 2 || Sector(k) == 4 || Sector(k) == 5) * (1.11 * Momentum(k) + 0.18) +
                                (Sector(k) == 3) * (1.07 * Momentum(k) + 0.18)) &&
          ((Ein(k) / 0.27 + Eout(k) / 0.27) < (Sector(k) == 0 || Sector(k) == 1) * (1.11 * Momentum(k)) +
                                                  (Sector(k) == 2 || Sector(k) == 5) * (1.19 * Momentum(k)) +
                                                  (Sector(k) == 3) * (1.15 * Momentum(k)) + (Sector(k) == 4) * (1.22 * Momentum(k))) &&
          ((Ein(k) / 0.27 + Eout(k) / 0.27) > (Sector(k) == 0 || Sector(k) == 1) * (0.75 * Momentum(k)) +
                                                  (Sector(k) == 2 || Sector(k) == 5) * (0.84 * Momentum(k)) +
                                                  (Sector(k) == 3) * (0.83 * Momentum(k)) + (Sector(k) == 4) * (0.85 * Momentum(k)))) {
        return true;
      }
    }  // closure
    return false;
  }

  Bool_t IsElectron(Int_t k, TString dataKind, TString targetOption, TVector3 *ECuvw) {
    if (Status(k) > 0 &&  // Status(k) < 100 does nothing
        NRowsDC() != 0 && DCStatus(k) > 0 && StatDC(k) > 0 && NRowsEC() != 0 && StatEC(k) > 0 && NRowsSC() != 0 && SCStatus(k) == 33 &&
        NRowsCC() != 0 &&
        Nphe(k) > (Sector(k) == 0 || Sector(k) == 1) * 25 + (Sector(k) == 2) * 26 + (Sector(k) == 3) * 21 +
                      (Sector(k) == 4 || Sector(k) == 5) * 28 &&
        Charge(k) == -1 && (TimeEC(k) - TimeSC(k) - (PathEC(k) - PathSC(k)) / 30) < 5 * 0.35 &&
        (TimeEC(k) - TimeSC(k) - (PathEC(k) - PathSC(k)) / 30) > -5 * 0.35 && Eout(k) != 0 && Ein(k) > 0.06 && ECuvw->X() > 40 &&
        ECuvw->X() < 410 && ECuvw->Y() < 370 && ECuvw->Z() < 405 && SampFracCheck(k, dataKind, targetOption) &&
        ElectronPhaseSpace(k, dataKind) && FidCheckCut(k)) {
      return true;
    }  // closure
    return false;
  }

  Bool_t IsPositron(Int_t k, TString dataKind, TString targetOption, TVector3 *ECuvw) {
    if (Status(k) > 0 &&  // Status(k) < 100 does nothing
        NRowsDC() != 0 && DCStatus(k) > 0 && StatDC(k) > 0 && NRowsEC() != 0 && StatEC(k) > 0 && NRowsSC() != 0 && SCStatus(k) == 33 &&
        NRowsCC() != 0 &&
        Nphe(k) > (Sector(k) == 0 || Sector(k) == 1) * 25 + (Sector(k) == 2) * 26 + (Sector(k) == 3) * 21 +
                      (Sector(k) == 4 || Sector(k) == 5) * 28 &&
        Charge(k) == 1 &&  // only difference
        (TimeEC(k) - TimeSC(k) - (PathEC(k) - PathSC(k)) / 30) < 5 * 0.35 &&
        (TimeEC(k) - TimeSC(k) - (PathEC(k) - PathSC(k)) / 30) > -5 * 0.35 && Eout(k) != 0 && Ein(k) > 0.06 && ECuvw->X() > 40 &&
        ECuvw->X() < 410 && ECuvw->Y() < 370 && ECuvw->Z() < 405 && SampFracCheck(k, dataKind, targetOption) &&
        ElectronPhaseSpace(k, dataKind) && FidCheckCut(k)) {
      return true;
    }  // closure
    return false;
  }

  Bool_t PiPlusPhaseSpace_SC(Int_t k) {
    Double_t P = Momentum(k);
    Double_t T4 = TimeCorr4(k, 0.13957);
    // sebastian's paramaters
    const Double_t lines_PiPlus[14][2] = {{-0.70, 0.70}, {-0.70, 0.65}, {-0.70, 0.65}, {-0.70, 0.65}, {-0.55, 0.55},
                                          {-0.50, 0.55}, {-0.50, 0.40}, {-0.48, 0.40}, {-0.50, 0.40}, {-0.50, 0.40},
                                          {-0.50, 0.40}, {-0.50, 0.40}, {-0.32, 0.32}, {-0.30, 0.37}};
    if (P < 2.7 && NRowsSC() != 0 && StatSC(k) > 0 &&
        ((P > 0.00 && P <= 0.25 && T4 >= lines_PiPlus[0][0] && T4 <= lines_PiPlus[0][1]) ||
         (P > 0.25 && P <= 0.50 && T4 >= lines_PiPlus[1][0] && T4 <= lines_PiPlus[1][1]) ||
         (P > 0.50 && P <= 0.75 && T4 >= lines_PiPlus[2][0] && T4 <= lines_PiPlus[2][1]) ||
         (P > 0.75 && P <= 1.00 && T4 >= lines_PiPlus[3][0] && T4 <= lines_PiPlus[3][1]) ||
         (P > 1.00 && P <= 1.25 && T4 >= lines_PiPlus[4][0] && T4 <= lines_PiPlus[4][1]) ||
         (P > 1.25 && P <= 1.50 && T4 >= lines_PiPlus[5][0] && T4 <= lines_PiPlus[5][1]) ||
         (P > 1.50 && P <= 1.75 && T4 >= lines_PiPlus[6][0] && T4 <= lines_PiPlus[6][1]) ||
         (P > 1.75 && P <= 2.00 && T4 >= lines_PiPlus[7][0] && T4 <= lines_PiPlus[7][1]) ||
         (P > 2.00 && P <= 2.25 && T4 >= lines_PiPlus[8][0] && T4 <= lines_PiPlus[8][1]) ||
         (P > 2.25 && P <= 2.50 && T4 >= lines_PiPlus[9][0] && T4 <= lines_PiPlus[9][1] && Mass2(k) < 0.5) ||
         (P > 2.50 && P < 2.70 && T4 >= lines_PiPlus[10][0] && T4 <= lines_PiPlus[10][1] && Mass2(k) < 0.4) ||
         (P > 2.7 && P <= 3.3 && T4 >= -0.5 && T4 <= 0.4 && Mass2(k) < 0.4) ||
         (P > 3.3 && P <= 3.7 && T4 >= -0.32 && T4 <= 0.32 && Mass2(k) < 0.37) ||
         (P > 3.7 && T4 >= -0.3 && T4 <= 0.3 && Mass2(k) < 0.37))) {
      return true;
    }  // closure
    return false;
  }

  Bool_t PiPlusPhaseSpace_CC(Int_t k) {
    // for high energy pi+
    Double_t P = Momentum(k);
    Double_t T4 = TimeCorr4(k, 0.13957);
    if (NRowsCC() != 0 && StatCC(k) > 0 && Nphe(k) > 25 && Chi2CC(k) < 5 / 57.3 && P >= 2.7 && T4 > -0.35 && T4 < 0.35) {
      return true;
    }  // closure
    return false;
  }

  Bool_t IsPiPlus(Int_t k, TVector3 *ECuvw) {
    if (Charge(k) == 1 && Status(k) > 0 && NRowsDC() != 0 && StatDC(k) > 0 && DCStatus(k) > 0 &&
        (PiPlusPhaseSpace_CC(k) || PiPlusPhaseSpace_SC(k))) {
      return true;
    }  // closure
    return false;
  }

  Bool_t PiMinusPhaseSpace_SC(Int_t k) {
    Double_t P = Momentum(k);
    Double_t T4 = TimeCorr4(k, 0.13957);
    // sebastian's parameters
    const Double_t lines_PiMinus[5][2] = {{-0.75, 0.80}, {-0.55, 0.55}, {-0.55, 0.55}, {-0.50, 0.44}, {-0.50, 0.45}};
    if (StatSC(k) > 0 && ((0 < P && P <= 0.5 && T4 >= lines_PiMinus[0][0] && T4 <= lines_PiMinus[0][1]) ||
                          (0.5 < P && P <= 1.0 && T4 >= lines_PiMinus[1][0] && T4 <= lines_PiMinus[1][1]) ||
                          (1.0 < P && P <= 1.5 && T4 >= lines_PiMinus[2][0] && T4 <= lines_PiMinus[2][1]) ||
                          (1.5 < P && P <= 2.0 && T4 >= lines_PiMinus[3][0] && T4 <= lines_PiMinus[3][1]) ||
                          (2.0 < P && P <= 2.5 && T4 >= lines_PiMinus[4][0] && T4 <= lines_PiMinus[4][1]))) {
      return true;
    }  // closure
    return false;
  }

  Bool_t PiMinusPhaseSpace_CC(Int_t k) {
    // for high energy pi+
    Double_t P = Momentum(k);
    Double_t T4 = TimeCorr4(k, 0.13957);
    if (StatCC(k) > 0 && Nphe(k) > 25 && P > 2.5 && T4 > -1.50 && T4 < 1.50) {
      return true;
    }  // closure
    return false;
  }

  Bool_t IsPiMinus(Int_t k, TVector3 *ECuvw) {
    Double_t deltaBetta = Betta(k) - (Momentum(k) / TMath::Sqrt(Momentum(k) * Momentum(k) + 0.13957 * 0.13957));
    if (Charge(k) == -1 && Status(k) > 0 && NRowsDC() != 0 && DCStatus(k) > 0 && StatDC(k) > 0 && Etot(k) < 0.15 &&
        (Ein(k) < 0.085 - 0.5 * Eout(k)) && deltaBetta >= -0.03 && deltaBetta <= 0.03 && Momentum(k) < 5.0 &&
        (PiMinusPhaseSpace_SC(k) || PiMinusPhaseSpace_CC(k))) {  // high energy pi-
      return true;
    }  // closure
    return false;
  }

  Bool_t IsGamma(Int_t k, TVector3 *ECuvw) {
    if (Charge(k) == 0 && ECuvw->X() > 40 && ECuvw->X() < 410 && ECuvw->Y() < 370 && ECuvw->Z() < 410 &&
        ((PathEC(k) / (Betta(k) * 30) - PathEC(k) / 30) > -2.2) && ((PathEC(k) / (Betta(k) * 30) - PathEC(k) / 30) < 1.3) &&
        TMath::Max(Etot(k), Ein(k) + Eout(k)) / 0.272 > 0.1) {
      return true;
    }  // closure
    return false;
  }

  Bool_t CheckProtonsCorrectedTOF(Int_t k) {
    Double_t T4 = TimeCorr4(k, 0.938272);
    Double_t P = Momentum(k);
    Double_t calc_upper_limit;
    Double_t calc_lower_limit;
    if (P >= 0.2 && P <= 0.8) {
      // low momentum protons
      calc_lower_limit = kLowP_lower_Proton[0] * TMath::Power(P, 0) + kLowP_lower_Proton[1] * TMath::Power(P, 1) +
                         kLowP_lower_Proton[2] * TMath::Power(P, 2) + kLowP_lower_Proton[3] * TMath::Power(P, 3) +
                         kLowP_lower_Proton[4] * TMath::Power(P, 4) + kLowP_lower_Proton[5] * TMath::Power(P, 5) +
                         kLowP_lower_Proton[6] * TMath::Power(P, 6) + kLowP_lower_Proton[7] * TMath::Power(P, 7) +
                         kLowP_lower_Proton[8] * TMath::Power(P, 8) + kLowP_lower_Proton[9] * TMath::Power(P, 9);
      calc_upper_limit = kLowP_upper_Proton[0] * TMath::Power(P, 0) + kLowP_upper_Proton[1] * TMath::Power(P, 1) +
                         kLowP_upper_Proton[2] * TMath::Power(P, 2) + kLowP_upper_Proton[3] * TMath::Power(P, 3) +
                         kLowP_upper_Proton[4] * TMath::Power(P, 4) + kLowP_upper_Proton[5] * TMath::Power(P, 5) +
                         kLowP_upper_Proton[6] * TMath::Power(P, 6) + kLowP_upper_Proton[7] * TMath::Power(P, 7) +
                         kLowP_upper_Proton[8] * TMath::Power(P, 8) + kLowP_upper_Proton[9] * TMath::Power(P, 9);
    } else if (P >= 0.8 && P <= 3.0) {
      // high momentum protons
      calc_lower_limit = kHighP_lower_Proton[0] * TMath::Power(P, 0) + kHighP_lower_Proton[1] * TMath::Power(P, 1) +
                         kHighP_lower_Proton[2] * TMath::Power(P, 2) + kHighP_lower_Proton[3] * TMath::Power(P, 3);
      calc_upper_limit = kHighP_upper_Proton[0] * TMath::Power(P, 0) + kHighP_upper_Proton[1] * TMath::Power(P, 1) +
                         kHighP_upper_Proton[2] * TMath::Power(P, 2) + kHighP_upper_Proton[3] * TMath::Power(P, 3);
    } else {
      // invalid protons
      calc_lower_limit = 0;
      calc_upper_limit = 0;
    }
    // final condition
    if (T4 >= calc_lower_limit && T4 <= calc_upper_limit) {
      return true;
    }
    return false;
  }

  Bool_t IsProton(Int_t k) {
    if (Charge(k) == 1 && Status(k) > 0 && StatDC(k) > 0 && DCStatus(k) > 0 && FidCheckCutPiPlus(k) && CheckProtonsCorrectedTOF(k)) {
      return true;
    }  // closure
    return false;
  }

  TString GetCategorization(Int_t k, TString dataKind, TString targetOption) {
    // transformation vectors
    TVector3 *ECxyz = new TVector3(XEC(k), YEC(k), ZEC(k));
    TVector3 *ECuvw = XYZToUVW(ECxyz);
    if (IsElectron(k, dataKind, targetOption, ECuvw)) {
      return "electron";
    } else if (IsPiMinus(k, ECuvw)) {
      return "pi-";
    } else if (IsPositron(k, dataKind, targetOption, ECuvw)) {
      return "positron";
    } else if (IsProton(k)) {
      return "proton";
    } else if (IsPiPlus(k, ECuvw)) {
      return "pi+";
    } else if (IsGamma(k, ECuvw)) {
      return "gamma";
    }  // closure
    return "not recognized";
  }

 private:
  /********************************/
  /*** PRIVATE FUNCTION MEMBERS ***/
  /***                          ***/
  /********************************/

  const Double_t kEbeam;  // The energy of incoming electron beam
  const Double_t kMpi;    // mass of the pion
  const Double_t kMprt;   // mass of the proton
  const Double_t kMntr;   // mass of the neutron
  const Double_t kGOOD;   // The key for the exceptions

  TClasTool *fCT;     // Pointer to the main ClasTool object
  TEVNTClass *fEVNT;  // Pointer to the EVNT object
  TGSIMClass *fGSIM;  // Pointer to the GSIM object
  TCCPBClass *fCCPB;  // Pointer to the CCPB object
  TECPBClass *fECPB;  // Pointer to the ECPB object
  TSCPBClass *fSCPB;  // Pointer to the SCPB object
  TDCPBClass *fDCPB;  // Pointer to the DCPB object

  /******************/
  /*   PARAMETERS   */
  /*                */
  /******************/

  /*** Sampling Fraction Cuts ***/

  // for data
  const Double_t kCPar[6][5] = {
      {0.252164, 0.0122263, -0.000793937, 9.55113e-03, 3.40672e-02}, {0.278574, 0.0187482, -0.00238217, 1.39889e-02, 3.74682e-02},
      {0.262079, 0.0230685, -0.00354741, 9.32762e-03, 2.90046e-02},  {0.251108, 0.0201568, -0.00332367, 8.21055e-03, 2.98893e-02},
      {0.263396, 0.00955238, -0.00102038, 2.25684e-02, 3.06508e-02}, {0.255245, 0.0232659, -0.00304798, 1.17254e-02, 3.64221e-02}};

  const Double_t kFePar[6][5] = {
      {0.222404, 0.0222688, -0.0024153, 9.23027e-03, 2.98343e-02},  {0.234623, 0.0194985, -0.00208357, 8.66367e-03, 3.08858e-02},
      {0.252287, 0.024248, -0.00338846, 1.07826e-02, 2.63854e-02},  {0.250946, 0.0208409, -0.00326824, 7.22581e-03, 2.98809e-02},
      {0.271956, 0.0118487, -0.00187084, 1.84073e-02, 3.48029e-02}, {0.252613, 0.022819, -0.00311242, 4.11461e-03, 3.55081e-02}};

  const Double_t kPbPar[6][5] = {
      {0.253431, 0.0138251, -0.00140160, 7.67408e-03, 3.54391e-02}, {0.249059, 0.0147784, -0.00148693, 7.52798e-03, 3.38371e-02},
      {0.254573, 0.0225890, -0.00305686, 8.13241e-03, 2.77300e-02}, {0.255589, 0.0190419, -0.00305263, 7.20303e-03, 3.03627e-02},
      {0.276739, 0.0111585, -0.00175784, 1.80841e-02, 3.53020e-02}, {0.262587, 0.0191659, -0.0026264, 1.99220e-03, 3.76172e-02}};

  // for simulations
  const Double_t kDPar_Sim[6][5] = {
      {0.24876, 0.0179894, -0.00442957, 0.00399225, 0.0249298},  {0.248957, 0.0181533, -0.00416637, 0.00538627, 0.0242045},
      {0.248164, 0.0188304, -0.00427462, 0.00335732, 0.0247301}, {0.250525, 0.0161461, -0.0041662, 0.00346977, 0.0251755},
      {0.248031, 0.0196832, -0.00456827, 0.00354094, 0.0252441}, {0.249069, 0.015629, -0.00363472, 0.00274538, 0.0254185}};

  const Double_t kCPar_Sim[6][5] = {
      {0.250469, 0.015964, -0.00389408, 0.00510237, 0.0248174}, {0.251445, 0.0159875, -0.00375825, 0.00431604, 0.0244632},
      {0.250031, 0.0178331, -0.00422464, 8.4798e-08, 0.024983}, {0.25105, 0.0152426, -0.00390999, 0.00255027, 0.0254091},
      {0.25027, 0.01694, -0.00381344, 0.00399372, 0.0249107},   {0.249087, 0.0150609, -0.0034316, 0.00552327, 0.0246847}};

  const Double_t kFePar_Sim[6][5] = {
      {0.249113, 0.0172746, -0.00420656, 0.00431529, 0.0251379}, {0.248658, 0.0185365, -0.00428943, 0.00540396, 0.0241749},
      {0.249016, 0.0185937, -0.00438778, 0.00417432, 0.0249617}, {0.247588, 0.0196735, -0.00515405, 0.00431868, 0.0250086},
      {0.247964, 0.0196745, -0.00455197, 0.0038769, 0.0251642},  {0.246463, 0.0184054, -0.00431434, 0.00444093, 0.025143}};

  const Double_t kPbPar_Sim[6][5] = {
      {0.247887, 0.0188033, -0.00463279, 0.00358101, 0.0253111}, {0.247159, 0.0206521, -0.00493913, 0.00417953, 0.0245174},
      {0.247663, 0.0197017, -0.00459223, 1.8082e-07, 0.0253269}, {0.249099, 0.0173088, -0.00436998, 0.00339505, 0.0254005},
      {0.249669, 0.0175364, -0.00392209, 0.00482576, 0.0250319}, {0.247958, 0.0165727, -0.00381158, 0.00332387, 0.0253196}};

  /*** DC Fiducial Cuts ***/

  // For FidThetaMin calculation for electron
  const Double_t kThetaPar0[6] = {15, 15, 15, 15, 13, 13};
  const Double_t kThetaPar1[6] = {-0.425145, -1.02217, -0.7837, -1.47798, 3.47361, 3.5714};
  const Double_t kThetaPar2[6] = {-0.666294, -0.616567, -0.673602, -0.647113, -0.34459, -0.398458};
  const Double_t kThetaPar3[6] = {5.73077, 5.51799, 8.05224, 7.74737, 8.45226, 9.54265};
  const Double_t kThetaPar4[6] = {10.4976, 14.0557, 15.2178, 16.7291, -63.4556, -22.649};
  const Double_t kThetaPar5[6] = {-1.13254, -1.16189, -2.08386, -1.79939, -3.3791, -1.89746};

  // For parameter 0 of the FidPhiMin calculation for electron
  const Double_t kFidPar0Low0[6] = {25, 25, 25, 24.6345, 23.4731, 24.8599};
  const Double_t kFidPar0Low1[6] = {-12, -12, -12, -12, -12, -12};
  const Double_t kFidPar0Low2[6] = {0.5605, 0.714261, 0.616788, 0.62982, 1.84236, 1.00513};
  const Double_t kFidPar0Low3[6] = {4.4, 4.4, 4.4, 4.4, 4.4, 4.4};

  // For parameter 1 of the FidPhiMin calculation for electron
  const Double_t kFidPar1Low0[6] = {2.1945, 4, 3.3352, 2.22769, 1.63143, 3.19807};
  const Double_t kFidPar1Low1[6] = {1.51417, 1.56882, 2, 2, 1.90179, 0.173168};
  const Double_t kFidPar1Low2[6] = {-0.354081, -2, -2, -0.760895, -0.213751, -0.1};
  const Double_t kFidPar1Low3[6] = {0.5, 0.5, 1.01681, 1.31808, 0.786844, 1.6};

  // For parameter 0 of the FidPhiMax calculation for electron
  const Double_t kFidPar0High0[6] = {25, 25, 25, 25, 23.7067, 25};
  const Double_t kFidPar0High1[6] = {-8, -10.3277, -12, -11.3361, -12, -11.4641};
  const Double_t kFidPar0High2[6] = {0.479446, 0.380908, 0.675835, 0.636018, 2.92146, 0.55553};
  const Double_t kFidPar0High3[6] = {4.8, 4.79964, 4.4, 4.4815, 4.4, 4.41327};

  // For parameter 1 of the FidPhiMax calculation for electron
  const Double_t kFidPar1High0[6] = {3.57349, 3.02279, 2.02102, 3.1948, 3.0934, 2.48828};
  const Double_t kFidPar1High1[6] = {2, 0.966175, 2, 0.192701, 0.821726, 2};
  const Double_t kFidPar1High2[6] = {-2, -2, -1.70021, -1.27578, -0.233492, -2};
  const Double_t kFidPar1High3[6] = {0.5, 0.527823, 0.68655, 1.6, 1.6, 0.70261};

  // For FidThetaMinPiPlus calculation for pi+
  const Double_t kThetaPar0PiPlus[6] = {7.00823, 5.5, 7.06596, 6.32763, 5.5, 5.5};
  const Double_t kThetaPar1PiPlus[6] = {0.207249, 0.1, 0.127764, 0.1, 0.211012, 0.281549};
  const Double_t kThetaPar2PiPlus[6] = {0.169287, 0.506354, -0.0663754, 0.221727, 0.640963, 0.358452};
  const Double_t kThetaPar3PiPlus[6] = {0.1, 0.1, 0.100003, 0.1, 0.1, 0.1};
  const Double_t kThetaPar4PiPlus[6] = {0.1, 3.30779, 4.499, 5.30981, 3.20347, 0.776161};
  const Double_t kThetaPar5PiPlus[6] = {-0.1, -0.651811, -3.1793, -3.3461, -1.10808, -0.462045};

  // For parameter 0 of the FidPhiMinPiPlus calculation for pi+
  const Double_t kFidPar0Low0PiPlus[6] = {25., 25., 25., 25., 25., 25.};
  const Double_t kFidPar0Low1PiPlus[6] = {-12., -12., -12., -12, -12, -12};
  const Double_t kFidPar0Low2PiPlus[6] = {1.64476, 1.51915, 1.1095, 0.977829, 0.955366, 0.969146};
  const Double_t kFidPar0Low3PiPlus[6] = {4.4, 4.4, 4.4, 4.4, 4.4, 4.4};

  // For parameter 1 of the FidPhiMinPiPlus calculation for pi+
  const Double_t kFidPar1Low0PiPlus[6] = {4., 4., 2.78427, 3.58539, 3.32277, 4.};
  const Double_t kFidPar1Low1PiPlus[6] = {2., 2., 2., 1.38233, 0.0410601, 2.};
  const Double_t kFidPar1Low2PiPlus[6] = {-0.978469, -2., -1.73543, -2., -0.953828, -2.};
  const Double_t kFidPar1Low3PiPlus[6] = {0.5, 0.5, 0.5, 0.5, 0.5, 1.08576};

  // For parameter 0 of the FidPhiMaxPiPlus calculation for pi+
  const Double_t kFidPar0High0PiPlus[6] = {25., 24.8096, 24.8758, 25., 25., 25.};
  const Double_t kFidPar0High1PiPlus[6] = {-11.9735, -8., -8., -12., -8.52574, -8.};
  const Double_t kFidPar0High2PiPlus[6] = {0.803484, 0.85143, 1.01249, 0.910994, 0.682825, 0.88846};
  const Double_t kFidPar0High3PiPlus[6] = {4.40024, 4.8, 4.8, 4.4, 4.79866, 4.8};

  // For parameter 1 of the FidPhiMaxPiPlus calculation for pi+
  const Double_t kFidPar1High0PiPlus[6] = {2.53606, 2.65468, 3.17084, 2.47156, 2.42349, 2.64394};
  const Double_t kFidPar1High1PiPlus[6] = {0.442034, 0.201149, 1.27519, 1.76076, 1.25399, 0.15892};
  const Double_t kFidPar1High2PiPlus[6] = {-2., -0.179631, -2., -1.89436, -2., -2.};
  const Double_t kFidPar1High3PiPlus[6] = {1.02806, 1.6, 0.5, 1.03961, 0.815707, 1.31013};

  // Parameters from Or Hen for proton ID
  const Double_t kLowP_lower_Proton[10] = {-26.8257, 153.155, -408.979, 673.476, -790.433, 708.255, -474.843, 217.295, -58.6269, 6.90981};
  const Double_t kLowP_upper_Proton[10] = {120.251, -1168.19, 5237.42, -13638.1, 22325.3, -23649.6, 16177.8, -6894.16, 1663.4, -173.474};
  const Double_t kHighP_lower_Proton[4] = {-1.1009, 0.719988, -0.280016, 0.0319352};
  const Double_t kHighP_upper_Proton[4] = {1.59223, -1.49056, 0.676338, -0.104644};
};

#endif
