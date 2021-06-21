#include "TIdentificatorV2.h"
#include "GSTtree.h"

#include "Headers.hxx"
#include "Constants.hxx"
#include "Math.hxx"
#include "PDG.hxx"

void SetElectronBranches_Data(TTree* tree, data_e& de) {
  // electron (46)
  tree->Branch("Q2", &de.Q2);
  tree->Branch("W", &de.W);
  tree->Branch("Nu", &de.Nu);
  tree->Branch("Xb", &de.Xb);
  tree->Branch("Yb", &de.Yb);
  tree->Branch("vxe", &de.vxe);
  tree->Branch("vye", &de.vye);
  tree->Branch("vze", &de.vze);
  tree->Branch("Sector", &de.Sector);
  tree->Branch("TargType", &de.TargType);
  tree->Branch("Px", &de.Px);
  tree->Branch("Py", &de.Py);
  tree->Branch("Pz", &de.Pz);
  tree->Branch("P", &de.P);
  tree->Branch("Betta", &de.Betta);
  tree->Branch("Etot", &de.Etot);
  tree->Branch("Ein", &de.Ein);
  tree->Branch("Eout", &de.Eout);
  tree->Branch("vxec", &de.vxec);
  tree->Branch("vyec", &de.vyec);
  tree->Branch("vzec", &de.vzec);
  tree->Branch("XEC", &de.XEC);
  tree->Branch("YEC", &de.YEC);
  tree->Branch("ZEC", &de.ZEC);
  tree->Branch("PhiLab", &de.PhiLab);
  tree->Branch("ThetaLab", &de.ThetaLab);
  tree->Branch("StatDC", &de.StatDC);
  tree->Branch("DCStatus", &de.DCStatus);
  tree->Branch("StatEC", &de.StatEC);
  tree->Branch("ECStatus", &de.ECStatus);
  tree->Branch("TimeEC", &de.TimeEC);
  tree->Branch("PathEC", &de.PathEC);
  tree->Branch("Chi2EC", &de.Chi2EC);
  tree->Branch("StatSC", &de.StatSC);
  tree->Branch("SCStatus", &de.SCStatus);
  tree->Branch("TimeSC", &de.TimeSC);
  tree->Branch("PathSC", &de.PathSC);
  tree->Branch("StatCC", &de.StatCC);
  tree->Branch("CCStatus", &de.CCStatus);
  tree->Branch("Nphe", &de.Nphe);
  tree->Branch("Chi2CC", &de.Chi2CC);
  tree->Branch("Status", &de.Status);
  tree->Branch("NRowsDC", &de.NRowsDC);
  tree->Branch("NRowsEC", &de.NRowsEC);
  tree->Branch("NRowsSC", &de.NRowsSC);
  tree->Branch("NRowsCC", &de.NRowsCC);
  // evnt (1)
  tree->Branch("evnt", &de.evnt);
}

void SetParticleBranches_Data(TTree* tree, data_p& dp) {
  // electron (46)
  tree->Branch("Q2", &dp.Q2);
  tree->Branch("W", &dp.W);
  tree->Branch("Nu", &dp.Nu);
  tree->Branch("Xb", &dp.Xb);
  tree->Branch("Yb", &dp.Yb);
  tree->Branch("vxe", &dp.vxe);
  tree->Branch("vye", &dp.vye);
  tree->Branch("vze", &dp.vze);
  tree->Branch("SectorEl", &dp.SectorEl);
  tree->Branch("TargType", &dp.TargType);
  tree->Branch("Pex", &dp.Pex);
  tree->Branch("Pey", &dp.Pey);
  tree->Branch("Pez", &dp.Pez);
  tree->Branch("Pe", &dp.Pe);
  tree->Branch("BettaEl", &dp.BettaEl);
  tree->Branch("Etote", &dp.Etote);
  tree->Branch("Eine", &dp.Eine);
  tree->Branch("Eoute", &dp.Eoute);
  tree->Branch("vxec", &dp.vxec);
  tree->Branch("vyec", &dp.vyec);
  tree->Branch("vzec", &dp.vzec);
  tree->Branch("XECe", &dp.XECe);
  tree->Branch("YECe", &dp.YECe);
  tree->Branch("ZECe", &dp.ZECe);
  tree->Branch("PhiLabEl", &dp.PhiLabEl);
  tree->Branch("ThetaLabEl", &dp.ThetaLabEl);
  tree->Branch("StatDCEl", &dp.StatDCEl);
  tree->Branch("DCStatusEl", &dp.DCStatusEl);
  tree->Branch("StatECEl", &dp.StatECEl);
  tree->Branch("ECStatusEl", &dp.ECStatusEl);
  tree->Branch("TimeECEl", &dp.TimeECEl);
  tree->Branch("PathECEl", &dp.PathECEl);
  tree->Branch("Chi2ECEl", &dp.Chi2ECEl);
  tree->Branch("StatSCEl", &dp.StatSCEl);
  tree->Branch("SCStatusEl", &dp.SCStatusEl);
  tree->Branch("TimeSCEl", &dp.TimeSCEl);
  tree->Branch("PathSCEl", &dp.PathSCEl);
  tree->Branch("StatCCEl", &dp.StatCCEl);
  tree->Branch("CCStatusEl", &dp.CCStatusEl);
  tree->Branch("NpheEl", &dp.NpheEl);
  tree->Branch("Chi2CCEl", &dp.Chi2CCEl);
  tree->Branch("StatusEl", &dp.StatusEl);
  tree->Branch("NRowsDCEl", &dp.NRowsDCEl);
  tree->Branch("NRowsECEl", &dp.NRowsECEl);
  tree->Branch("NRowsSCEl", &dp.NRowsSCEl);
  tree->Branch("NRowsCCEl", &dp.NRowsCCEl);
  // particle (49)
  tree->Branch("Eh", &dp.Eh);
  tree->Branch("Zh", &dp.Zh);
  tree->Branch("ThetaPQ", &dp.ThetaPQ);
  tree->Branch("Pt2", &dp.Pt2);
  tree->Branch("Pl2", &dp.Pl2);
  tree->Branch("PhiPQ", &dp.PhiPQ);
  tree->Branch("Mx2", &dp.Mx2);
  tree->Branch("T", &dp.T);
  tree->Branch("PhiLab", &dp.PhiLab);
  tree->Branch("ThetaLab", &dp.ThetaLab);
  tree->Branch("vxh", &dp.vxh);
  tree->Branch("vyh", &dp.vyh);
  tree->Branch("vzh", &dp.vzh);
  tree->Branch("Sector", &dp.Sector);
  tree->Branch("Px", &dp.Px);
  tree->Branch("Py", &dp.Py);
  tree->Branch("Pz", &dp.Pz);
  tree->Branch("P", &dp.P);
  tree->Branch("Betta", &dp.Betta);
  tree->Branch("Mass2", &dp.Mass2);
  tree->Branch("Etot", &dp.Etot);
  tree->Branch("Ein", &dp.Ein);
  tree->Branch("Eout", &dp.Eout);
  tree->Branch("XEC", &dp.XEC);
  tree->Branch("YEC", &dp.YEC);
  tree->Branch("ZEC", &dp.ZEC);
  tree->Branch("pid", &dp.pid);
  tree->Branch("T4", &dp.T4);
  tree->Branch("deltaZ", &dp.deltaZ);
  tree->Branch("StatDC", &dp.StatDC);
  tree->Branch("DCStatus", &dp.DCStatus);
  tree->Branch("StatEC", &dp.StatEC);
  tree->Branch("ECStatus", &dp.ECStatus);
  tree->Branch("TimeEC", &dp.TimeEC);
  tree->Branch("PathEC", &dp.PathEC);
  tree->Branch("Chi2EC", &dp.Chi2EC);
  tree->Branch("StatSC", &dp.StatSC);
  tree->Branch("SCStatus", &dp.SCStatus);
  tree->Branch("TimeSC", &dp.TimeSC);
  tree->Branch("PathSC", &dp.PathSC);
  tree->Branch("StatCC", &dp.StatCC);
  tree->Branch("CCStatus", &dp.CCStatus);
  tree->Branch("Nphe", &dp.Nphe);
  tree->Branch("Chi2CC", &dp.Chi2CC);
  tree->Branch("Status", &dp.Status);
  tree->Branch("NRowsDC", &dp.NRowsDC);
  tree->Branch("NRowsEC", &dp.NRowsEC);
  tree->Branch("NRowsSC", &dp.NRowsSC);
  tree->Branch("NRowsCC", &dp.NRowsCC);
  // event (1)
  tree->Branch("evnt", &dp.evnt);
}

void AssignElectronVar_Data(TIdentificatorV2* t, data_e& de, Int_t evnt, TString dataKind, TString targetOption) {
  // electron (46)
  de.Q2 = t->Q2();
  de.W = t->W();
  de.Nu = t->Nu();
  de.Xb = t->Xb();
  de.Yb = t->Yb();
  de.vxe = t->X(0);
  de.vye = t->Y(0);
  de.vze = t->Z(0);
  de.Sector = t->Sector(0);
  de.Px = t->Px(0);
  de.Py = t->Py(0);
  de.Pz = t->Pz(0);
  de.P = t->Momentum(0);
  de.Betta = t->Betta(0);
  de.Etot = t->Etot(0);
  de.Ein = t->Ein(0);
  de.Eout = t->Eout(0);
  TVector3* fVert = t->GetCorrectedVert();
  de.vxec = fVert->X();
  de.vyec = fVert->Y();
  de.vzec = fVert->Z();
  de.TargType = t->TargTypeSM(dataKind, targetOption, 0);
  de.XEC = t->XEC(0);
  de.YEC = t->YEC(0);
  de.ZEC = t->ZEC(0);
  de.PhiLab = t->PhiLab(0);
  de.ThetaLab = t->ThetaLab(0);
  de.StatDC = t->StatDC(0);
  de.DCStatus = t->DCStatus(0);
  de.StatEC = t->StatEC(0);
  de.ECStatus = t->ECStatus(0);
  de.TimeEC = t->TimeEC(0);
  de.PathEC = t->PathEC(0);
  de.Chi2EC = t->Chi2EC(0);
  de.StatSC = t->StatSC(0);
  de.SCStatus = t->SCStatus(0);
  de.TimeSC = t->TimeSC(0);
  de.PathSC = t->PathSC(0);
  de.StatCC = t->StatCC(0);
  de.CCStatus = t->CCStatus(0);
  de.Nphe = t->Nphe(0);
  de.Chi2CC = t->Chi2CC(0);
  de.Status = t->Status(0);
  de.NRowsDC = t->NRowsDC();
  de.NRowsEC = t->NRowsEC();
  de.NRowsSC = t->NRowsSC();
  de.NRowsCC = t->NRowsCC();
  // evnt (1)
  de.evnt = evnt;
}

void AssignParticleVar_Data(TIdentificatorV2* t, data_p& dp, Int_t row, Int_t evnt, TString dataKind, TString targetOption) {
  // electron (46)
  dp.Q2 = t->Q2();
  dp.W = t->W();
  dp.Nu = t->Nu();
  dp.Xb = t->Xb();
  dp.Yb = t->Yb();
  dp.vxe = t->X(0);
  dp.vye = t->Y(0);
  dp.vze = t->Z(0);
  dp.SectorEl = t->Sector(0);
  dp.Pex = t->Px(0);
  dp.Pey = t->Py(0);
  dp.Pez = t->Pz(0);
  dp.Pe = t->Momentum(0);
  dp.BettaEl = t->Betta(0);
  dp.Etote = t->Etot(0);
  dp.Eine = t->Ein(0);
  dp.Eoute = t->Eout(0);
  TVector3* fVert = t->GetCorrectedVert();
  dp.vxec = fVert->X();
  dp.vyec = fVert->Y();
  dp.vzec = fVert->Z();
  dp.TargType = t->TargTypeSM(dataKind, targetOption, 0);
  dp.XECe = t->XEC(0);
  dp.YECe = t->YEC(0);
  dp.ZECe = t->ZEC(0);
  dp.PhiLabEl = t->PhiLab(0);
  dp.ThetaLabEl = t->ThetaLab(0);
  dp.StatDCEl = t->StatDC(0);
  dp.DCStatusEl = t->DCStatus(0);
  dp.StatECEl = t->StatEC(0);
  dp.ECStatusEl = t->ECStatus(0);
  dp.TimeECEl = t->TimeEC(0);
  dp.PathECEl = t->PathEC(0);
  dp.Chi2ECEl = t->Chi2EC(0);
  dp.StatSCEl = t->StatSC(0);
  dp.SCStatusEl = t->SCStatus(0);
  dp.TimeSCEl = t->TimeSC(0);
  dp.PathSCEl = t->PathSC(0);
  dp.StatCCEl = t->StatCC(0);
  dp.CCStatusEl = t->CCStatus(0);
  dp.NpheEl = t->Nphe(0);
  dp.Chi2CCEl = t->Chi2CC(0);
  dp.StatusEl = t->Status(0);
  dp.NRowsDCEl = t->NRowsDC();
  dp.NRowsECEl = t->NRowsEC();
  dp.NRowsSCEl = t->NRowsSC();
  dp.NRowsCCEl = t->NRowsCC();
  // particle (49)
  dp.pid = particleID(t->GetCategorization(row, dataKind, targetOption));
  dp.vxh = t->X(row);
  dp.vyh = t->Y(row);
  dp.vzh = t->Z(row);
  dp.Sector = t->Sector(row);
  dp.deltaZ = t->Z(row) - fVert->Z();
  dp.XEC = t->XEC(row);
  dp.YEC = t->YEC(row);
  dp.ZEC = t->ZEC(row);
  dp.Etot = t->Etot(row);
  dp.Ein = t->Ein(row);
  dp.Eout = t->Eout(row);
  // let's define some auxiliary Double_t
  Double_t fMass = particleMass(dp.pid);
  TLorentzVector* fGamma = t->GetCorrPhotonMomentum(row);
  Double_t fPx = (dp.pid == 22) * fGamma->Px() + (dp.pid != 22) * t->Px(row);
  Double_t fPy = (dp.pid == 22) * fGamma->Py() + (dp.pid != 22) * t->Py(row);
  Double_t fPz = (dp.pid == 22) * fGamma->Pz() + (dp.pid != 22) * t->Pz(row);
  Double_t fP = TMath::Sqrt(fPx * fPx + fPy * fPy + fPz * fPz);
  Double_t fE = (dp.pid == 22) * fGamma->E() + (dp.pid != 22) * TMath::Sqrt(fMass * fMass + fP * fP);
  Double_t fZ = fE / t->Nu();
  // continue...
  dp.Px = fPx;
  dp.Py = fPy;
  dp.Pz = fPz;
  dp.P = fP;
  dp.PhiLab = PhiLab(fPx, fPy, fPz);
  dp.ThetaLab = ThetaLab(fPx, fPy, fPz);
  dp.Eh = fE;
  dp.Zh = fZ;
  dp.ThetaPQ = ThetaPQ(t->Px(0), t->Py(0), t->Pz(0), fPx, fPy, fPz);
  dp.PhiPQ = PhiPQ(t->Px(0), t->Py(0), t->Pz(0), fPx, fPy, fPz);
  Double_t fCosThetaPQ = (fPz * (kEbeam - t->Pz(0)) - fPx * t->Px(0) - fPy * t->Py(0)) / (TMath::Sqrt(t->Nu() * t->Nu() + t->Q2()) * fP);
  Double_t fPt2 = fP * fP * (1 - fCosThetaPQ * fCosThetaPQ);
  Double_t fPl2 = fP * fP * fCosThetaPQ * fCosThetaPQ;
  dp.Pt2 = fPt2;
  dp.Pl2 = fPl2;
  dp.Mx2 = t->W() * t->W() + fMass * fMass - 2 * fZ * t->Nu() * t->Nu() + 2 * TMath::Sqrt(fPl2 * (t->Nu() * t->Nu() + t->Q2())) - 2 * kMassProton * fZ * t->Nu();
  dp.T = fMass * fMass - 2 * fZ * t->Nu() * t->Nu() + 2 * TMath::Sqrt(fPl2 * (t->Nu() * t->Nu() + t->Q2())) - t->Q2();
  dp.Betta = t->Betta(row);  // BettaMeasured
  dp.Mass2 = fP * fP * (TMath::Power(t->Betta(row), -2) - 1);
  dp.T4 = t->PathSC(0) / 30. - t->TimeSC(0) + t->TimeSC(row) - (t->PathSC(row) / 30.) * TMath::Sqrt(TMath::Power(fMass / fP, 2) + 1);
  // status
  dp.StatDC = t->StatDC(row);
  dp.DCStatus = t->DCStatus(row);
  dp.StatEC = t->StatEC(row);
  dp.ECStatus = t->ECStatus(row);
  dp.TimeEC = t->TimeEC(row);
  dp.PathEC = t->PathEC(row);
  dp.Chi2EC = t->Chi2EC(row);
  dp.StatSC = t->StatSC(row);
  dp.SCStatus = t->SCStatus(row);
  dp.TimeSC = t->TimeSC(row);
  dp.PathSC = t->PathSC(row);
  dp.StatCC = t->StatCC(row);
  dp.CCStatus = t->CCStatus(row);
  dp.Nphe = t->Nphe(row);
  dp.Chi2CC = t->Chi2CC(row);
  dp.Status = t->Status(row);
  dp.NRowsDC = t->NRowsDC();
  dp.NRowsEC = t->NRowsEC();
  dp.NRowsSC = t->NRowsSC();
  dp.NRowsCC = t->NRowsCC();
  // evnt (1)
  dp.evnt = evnt;
}
