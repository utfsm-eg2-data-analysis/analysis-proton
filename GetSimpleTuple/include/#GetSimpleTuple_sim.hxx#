#include "GSTtree.h"
#include "TIdentificatorV2.h"

#include "Constants.hxx"
#include "Headers.hxx"
#include "Math.hxx"
#include "PDG.hxx"

using namespace ROOT::VecOps;

#ifndef INVLD
#define INVLD -9999
#endif

void SetElectronBranches_Sim(TTree* tree, sim_e& se) {
  // simrec (46)
  tree->Branch("Q2", &se.Q2);
  tree->Branch("W", &se.W);
  tree->Branch("Nu", &se.Nu);
  tree->Branch("Xb", &se.Xb);
  tree->Branch("Yb", &se.Yb);
  tree->Branch("vxe", &se.vxe);
  tree->Branch("vye", &se.vye);
  tree->Branch("vze", &se.vze);
  tree->Branch("Sector", &se.Sector);
  tree->Branch("TargType", &se.TargType);
  tree->Branch("Px", &se.Px);
  tree->Branch("Py", &se.Py);
  tree->Branch("Pz", &se.Pz);
  tree->Branch("P", &se.P);
  tree->Branch("Betta", &se.Betta);
  tree->Branch("Etot", &se.Etot);
  tree->Branch("Ein", &se.Ein);
  tree->Branch("Eout", &se.Eout);
  tree->Branch("vxec", &se.vxec);
  tree->Branch("vyec", &se.vyec);
  tree->Branch("vzec", &se.vzec);
  tree->Branch("XEC", &se.XEC);
  tree->Branch("YEC", &se.YEC);
  tree->Branch("ZEC", &se.ZEC);
  tree->Branch("ThetaLab", &se.ThetaLab);
  tree->Branch("PhiLab", &se.PhiLab);
  tree->Branch("StatDC", &se.StatDC);
  tree->Branch("DCStatus", &se.DCStatus);
  tree->Branch("StatEC", &se.StatEC);
  tree->Branch("ECStatus", &se.ECStatus);
  tree->Branch("TimeEC", &se.TimeEC);
  tree->Branch("PathEC", &se.PathEC);
  tree->Branch("Chi2EC", &se.Chi2EC);
  tree->Branch("StatSC", &se.StatSC);
  tree->Branch("SCStatus", &se.SCStatus);
  tree->Branch("TimeSC", &se.TimeSC);
  tree->Branch("PathSC", &se.PathSC);
  tree->Branch("StatCC", &se.StatCC);
  tree->Branch("CCStatus", &se.CCStatus);
  tree->Branch("Nphe", &se.Nphe);
  tree->Branch("Chi2CC", &se.Chi2CC);
  tree->Branch("Status", &se.Status);
  tree->Branch("NRowsDC", &se.NRowsDC);
  tree->Branch("NRowsEC", &se.NRowsEC);
  tree->Branch("NRowsSC", &se.NRowsSC);
  tree->Branch("NRowsCC", &se.NRowsCC);
  // event (1)
  tree->Branch("evnt", &se.evnt);
  // gsim (17)
  tree->Branch("mc_Q2", &se.mc_Q2);
  tree->Branch("mc_W", &se.mc_W);
  tree->Branch("mc_Nu", &se.mc_Nu);
  tree->Branch("mc_Xb", &se.mc_Xb);
  tree->Branch("mc_Yb", &se.mc_Yb);
  tree->Branch("mc_vxe", &se.mc_vxe);
  tree->Branch("mc_vye", &se.mc_vye);
  tree->Branch("mc_vze", &se.mc_vze);
  tree->Branch("mc_Sector", &se.mc_Sector);
  tree->Branch("mc_TargType", &se.mc_TargType);
  tree->Branch("mc_Px", &se.mc_Px);
  tree->Branch("mc_Py", &se.mc_Py);
  tree->Branch("mc_Pz", &se.mc_Pz);
  tree->Branch("mc_P", &se.mc_P);
  tree->Branch("mc_Betta", &se.mc_Betta);
  tree->Branch("mc_ThetaLab", &se.mc_ThetaLab);
  tree->Branch("mc_PhiLab", &se.mc_PhiLab);
}

void SetParticleBranches_Sim(TTree* tree, sim_p& sp) {
  // simrec electron (46)
  tree->Branch("Q2", &sp.Q2);
  tree->Branch("W", &sp.W);
  tree->Branch("Nu", &sp.Nu);
  tree->Branch("Xb", &sp.Xb);
  tree->Branch("Yb", &sp.Yb);
  tree->Branch("vxe", &sp.vxe);
  tree->Branch("vye", &sp.vye);
  tree->Branch("vze", &sp.vze);
  tree->Branch("SectorEl", &sp.SectorEl);
  tree->Branch("TargType", &sp.TargType);
  tree->Branch("Pex", &sp.Pex);
  tree->Branch("Pey", &sp.Pey);
  tree->Branch("Pez", &sp.Pez);
  tree->Branch("Pe", &sp.Pe);
  tree->Branch("BettaEl", &sp.BettaEl);
  tree->Branch("Etote", &sp.Etote);
  tree->Branch("Eine", &sp.Eine);
  tree->Branch("Eoute", &sp.Eoute);
  tree->Branch("vxec", &sp.vxec);
  tree->Branch("vyec", &sp.vyec);
  tree->Branch("vzec", &sp.vzec);
  tree->Branch("XECe", &sp.XECe);
  tree->Branch("YECe", &sp.YECe);
  tree->Branch("ZECe", &sp.ZECe);
  tree->Branch("ThetaLabEl", &sp.ThetaLabEl);
  tree->Branch("PhiLabEl", &sp.PhiLabEl);
  tree->Branch("StatDCEl", &sp.StatDCEl);
  tree->Branch("DCStatusEl", &sp.DCStatusEl);
  tree->Branch("StatECEl", &sp.StatECEl);
  tree->Branch("ECStatusEl", &sp.ECStatusEl);
  tree->Branch("TimeECEl", &sp.TimeECEl);
  tree->Branch("PathECEl", &sp.PathECEl);
  tree->Branch("Chi2ECEl", &sp.Chi2ECEl);
  tree->Branch("StatSCEl", &sp.StatSCEl);
  tree->Branch("SCStatusEl", &sp.SCStatusEl);
  tree->Branch("TimeSCEl", &sp.TimeSCEl);
  tree->Branch("PathSCEl", &sp.PathSCEl);
  tree->Branch("StatCCEl", &sp.StatCCEl);
  tree->Branch("CCStatusEl", &sp.CCStatusEl);
  tree->Branch("NpheEl", &sp.NpheEl);
  tree->Branch("Chi2CCEl", &sp.Chi2CCEl);
  tree->Branch("StatusEl", &sp.StatusEl);
  tree->Branch("NRowsDCEl", &sp.NRowsDCEl);
  tree->Branch("NRowsECEl", &sp.NRowsECEl);
  tree->Branch("NRowsSCEl", &sp.NRowsSCEl);
  tree->Branch("NRowsCCEl", &sp.NRowsCCEl);
  // simrec particle (49)
  tree->Branch("Eh", &sp.Eh);
  tree->Branch("Zh", &sp.Zh);
  tree->Branch("ThetaPQ", &sp.ThetaPQ);
  tree->Branch("Pt2", &sp.Pt2);
  tree->Branch("Pl2", &sp.Pl2);
  tree->Branch("PhiPQ", &sp.PhiPQ);
  tree->Branch("Mx2", &sp.Mx2);
  tree->Branch("T", &sp.T);
  tree->Branch("ThetaLab", &sp.ThetaLab);
  tree->Branch("PhiLab", &sp.PhiLab);
  tree->Branch("vxh", &sp.vxh);
  tree->Branch("vyh", &sp.vyh);
  tree->Branch("vzh", &sp.vzh);
  tree->Branch("Sector", &sp.Sector);
  tree->Branch("Px", &sp.Px);
  tree->Branch("Py", &sp.Py);
  tree->Branch("Pz", &sp.Pz);
  tree->Branch("P", &sp.P);
  tree->Branch("Betta", &sp.Betta);
  tree->Branch("Mass2", &sp.Mass2);
  tree->Branch("Etot", &sp.Etot);
  tree->Branch("Ein", &sp.Ein);
  tree->Branch("Eout", &sp.Eout);
  tree->Branch("XEC", &sp.XEC);
  tree->Branch("YEC", &sp.YEC);
  tree->Branch("ZEC", &sp.ZEC);
  tree->Branch("pid", &sp.pid);
  tree->Branch("T4", &sp.T4);
  tree->Branch("deltaZ", &sp.deltaZ);
  tree->Branch("StatDC", &sp.StatDC);
  tree->Branch("DCStatus", &sp.DCStatus);
  tree->Branch("StatEC", &sp.StatEC);
  tree->Branch("ECStatus", &sp.ECStatus);
  tree->Branch("TimeEC", &sp.TimeEC);
  tree->Branch("PathEC", &sp.PathEC);
  tree->Branch("Chi2EC", &sp.Chi2EC);
  tree->Branch("StatSC", &sp.StatSC);
  tree->Branch("SCStatus", &sp.SCStatus);
  tree->Branch("TimeSC", &sp.TimeSC);
  tree->Branch("PathSC", &sp.PathSC);
  tree->Branch("StatCC", &sp.StatCC);
  tree->Branch("CCStatus", &sp.CCStatus);
  tree->Branch("Nphe", &sp.Nphe);
  tree->Branch("Chi2CC", &sp.Chi2CC);
  tree->Branch("Status", &sp.Status);
  tree->Branch("NRowsDC", &sp.NRowsDC);
  tree->Branch("NRowsEC", &sp.NRowsEC);
  tree->Branch("NRowsSC", &sp.NRowsSC);
  tree->Branch("NRowsCC", &sp.NRowsCC);
  // event-related (1)
  tree->Branch("evnt", &sp.evnt);
  // gsim electron (17)
  tree->Branch("mc_Q2", &sp.mc_Q2);
  tree->Branch("mc_W", &sp.mc_W);
  tree->Branch("mc_Nu", &sp.mc_Nu);
  tree->Branch("mc_Xb", &sp.mc_Xb);
  tree->Branch("mc_Yb", &sp.mc_Yb);
  tree->Branch("mc_vxe", &sp.mc_vxe);
  tree->Branch("mc_vye", &sp.mc_vye);
  tree->Branch("mc_vze", &sp.mc_vze);
  tree->Branch("mc_SectorEl", &sp.mc_SectorEl);
  tree->Branch("mc_TargType", &sp.mc_TargType);
  tree->Branch("mc_Pex", &sp.mc_Pex);
  tree->Branch("mc_Pey", &sp.mc_Pey);
  tree->Branch("mc_Pez", &sp.mc_Pez);
  tree->Branch("mc_Pe", &sp.mc_Pe);
  tree->Branch("mc_BettaEl", &sp.mc_BettaEl);
  tree->Branch("mc_ThetaLabEl", &sp.mc_ThetaLabEl);
  tree->Branch("mc_PhiLabEl", &sp.mc_PhiLabEl);
  // gsim particle (22)
  tree->Branch("mc_Eh", &sp.mc_Eh);
  tree->Branch("mc_Zh", &sp.mc_Zh);
  tree->Branch("mc_ThetaPQ", &sp.mc_ThetaPQ);
  tree->Branch("mc_Pt2", &sp.mc_Pt2);
  tree->Branch("mc_Pl2", &sp.mc_Pl2);
  tree->Branch("mc_PhiPQ", &sp.mc_PhiPQ);
  tree->Branch("mc_Mx2", &sp.mc_Mx2);
  tree->Branch("mc_T", &sp.mc_T);
  tree->Branch("mc_ThetaLab", &sp.mc_ThetaLab);
  tree->Branch("mc_PhiLab", &sp.mc_PhiLab);
  tree->Branch("mc_vxh", &sp.mc_vxh);
  tree->Branch("mc_vyh", &sp.mc_vyh);
  tree->Branch("mc_vzh", &sp.mc_vzh);
  tree->Branch("mc_Sector", &sp.mc_Sector);
  tree->Branch("mc_Px", &sp.mc_Px);
  tree->Branch("mc_Py", &sp.mc_Py);
  tree->Branch("mc_Pz", &sp.mc_Pz);
  tree->Branch("mc_P", &sp.mc_P);
  tree->Branch("mc_Betta", &sp.mc_Betta);
  tree->Branch("mc_Mass2", &sp.mc_Mass2);
  tree->Branch("mc_pid", &sp.mc_pid);
  tree->Branch("mc_deltaZ", &sp.mc_deltaZ);
}

void NullElectronVar_SIMREC(sim_e& se) {
  // (46 variables)
  se.Q2 = INVLD;
  se.W = INVLD;
  se.Nu = INVLD;
  se.Xb = INVLD;
  se.Yb = INVLD;
  se.vxe = INVLD;
  se.vye = INVLD;
  se.vze = INVLD;
  se.Sector = INVLD;
  se.Px = INVLD;
  se.Py = INVLD;
  se.Pz = INVLD;
  se.P = INVLD;
  se.Betta = INVLD;
  se.Etot = INVLD;
  se.Ein = INVLD;
  se.Eout = INVLD;
  se.vxec = INVLD;
  se.vyec = INVLD;
  se.vzec = INVLD;
  se.TargType = INVLD;
  se.XEC = INVLD;
  se.YEC = INVLD;
  se.ZEC = INVLD;
  se.ThetaLab = INVLD;
  se.PhiLab = INVLD;
  se.StatDC = INVLD;
  se.DCStatus = INVLD;
  se.StatEC = INVLD;
  se.ECStatus = INVLD;
  se.TimeEC = INVLD;
  se.PathEC = INVLD;
  se.Chi2EC = INVLD;
  se.StatSC = INVLD;
  se.SCStatus = INVLD;
  se.TimeSC = INVLD;
  se.PathSC = INVLD;
  se.StatCC = INVLD;
  se.CCStatus = INVLD;
  se.Nphe = INVLD;
  se.Chi2CC = INVLD;
  se.Status = INVLD;
  se.NRowsDC = INVLD;
  se.NRowsEC = INVLD;
  se.NRowsSC = INVLD;
  se.NRowsCC = INVLD;
}

void NullParticleVar_SIMREC(sim_p& sp) {
  // electron (46)
  sp.Q2 = INVLD;
  sp.W = INVLD;
  sp.Nu = INVLD;
  sp.Xb = INVLD;
  sp.Yb = INVLD;
  sp.vxe = INVLD;
  sp.vye = INVLD;
  sp.vze = INVLD;
  sp.SectorEl = INVLD;
  sp.Pex = INVLD;
  sp.Pey = INVLD;
  sp.Pez = INVLD;
  sp.Pe = INVLD;
  sp.BettaEl = INVLD;
  sp.Etote = INVLD;
  sp.Eine = INVLD;
  sp.Eoute = INVLD;
  sp.vxec = INVLD;
  sp.vyec = INVLD;
  sp.vzec = INVLD;
  sp.TargType = INVLD;
  sp.XECe = INVLD;
  sp.YECe = INVLD;
  sp.ZECe = INVLD;
  sp.ThetaLabEl = INVLD;
  sp.PhiLabEl = INVLD;
  sp.StatDCEl = INVLD;
  sp.DCStatusEl = INVLD;
  sp.StatECEl = INVLD;
  sp.ECStatusEl = INVLD;
  sp.TimeECEl = INVLD;
  sp.PathECEl = INVLD;
  sp.Chi2ECEl = INVLD;
  sp.StatSCEl = INVLD;
  sp.SCStatusEl = INVLD;
  sp.TimeSCEl = INVLD;
  sp.PathSCEl = INVLD;
  sp.StatCCEl = INVLD;
  sp.CCStatusEl = INVLD;
  sp.NpheEl = INVLD;
  sp.Chi2CCEl = INVLD;
  sp.StatusEl = INVLD;
  sp.NRowsDCEl = INVLD;
  sp.NRowsECEl = INVLD;
  sp.NRowsSCEl = INVLD;
  sp.NRowsCCEl = INVLD;
  // particle (49)
  sp.pid = INVLD;
  sp.Eh = INVLD;
  sp.Zh = INVLD;
  sp.ThetaPQ = INVLD;
  sp.PhiPQ = INVLD;
  sp.Pt2 = INVLD;
  sp.Pl2 = INVLD;
  sp.Mx2 = INVLD;
  sp.T = INVLD;
  sp.ThetaLab = INVLD;
  sp.PhiLab = INVLD;
  sp.T4 = INVLD;
  sp.vxh = INVLD;
  sp.vyh = INVLD;
  sp.vzh = INVLD;
  sp.Sector = INVLD;
  sp.Px = INVLD;
  sp.Py = INVLD;
  sp.Pz = INVLD;
  sp.P = INVLD;
  sp.Betta = INVLD;
  sp.Mass2 = INVLD;
  sp.Etot = INVLD;
  sp.Ein = INVLD;
  sp.Eout = INVLD;
  sp.XEC = INVLD;
  sp.YEC = INVLD;
  sp.ZEC = INVLD;
  sp.deltaZ = INVLD;
  sp.StatDC = INVLD;
  sp.DCStatus = INVLD;
  sp.StatEC = INVLD;
  sp.ECStatus = INVLD;
  sp.TimeEC = INVLD;
  sp.PathEC = INVLD;
  sp.Chi2EC = INVLD;
  sp.StatSC = INVLD;
  sp.SCStatus = INVLD;
  sp.TimeSC = INVLD;
  sp.PathSC = INVLD;
  sp.StatCC = INVLD;
  sp.CCStatus = INVLD;
  sp.Nphe = INVLD;
  sp.Chi2CC = INVLD;
  sp.Status = INVLD;
  sp.NRowsDC = INVLD;
  sp.NRowsEC = INVLD;
  sp.NRowsSC = INVLD;
  sp.NRowsCC = INVLD;
}

void NullElectronVar_GSIM(sim_e& se) {
  // (17 variables)
  se.mc_Q2 = INVLD;
  se.mc_W = INVLD;
  se.mc_Nu = INVLD;
  se.mc_Xb = INVLD;
  se.mc_Yb = INVLD;
  se.mc_vxe = INVLD;
  se.mc_vye = INVLD;
  se.mc_vze = INVLD;
  se.mc_Sector = INVLD;
  se.mc_TargType = INVLD;
  se.mc_Px = INVLD;
  se.mc_Py = INVLD;
  se.mc_Pz = INVLD;
  se.mc_P = INVLD;
  se.mc_Betta = INVLD;
  se.mc_ThetaLab = INVLD;
  se.mc_PhiLab = INVLD;
}

void NullParticleVar_GSIM(sim_p& sp) {
  // gsim electron (17)
  sp.mc_Q2 = INVLD;
  sp.mc_W = INVLD;
  sp.mc_Nu = INVLD;
  sp.mc_Xb = INVLD;
  sp.mc_Yb = INVLD;
  sp.mc_vxe = INVLD;
  sp.mc_vye = INVLD;
  sp.mc_vze = INVLD;
  sp.mc_SectorEl = INVLD;
  sp.mc_TargType = INVLD;
  sp.mc_Pex = INVLD;
  sp.mc_Pey = INVLD;
  sp.mc_Pez = INVLD;
  sp.mc_Pe = INVLD;
  sp.mc_BettaEl = INVLD;
  sp.mc_ThetaLabEl = INVLD;
  sp.mc_PhiLabEl = INVLD;
  // gsim particle (22)
  sp.mc_Eh = INVLD;
  sp.mc_Zh = INVLD;
  sp.mc_ThetaPQ = INVLD;
  sp.mc_Pt2 = INVLD;
  sp.mc_Pl2 = INVLD;
  sp.mc_PhiPQ = INVLD;
  sp.mc_ThetaLab = INVLD;
  sp.mc_PhiLab = INVLD;
  sp.mc_Mx2 = INVLD;
  sp.mc_T = INVLD;
  sp.mc_vxh = INVLD;
  sp.mc_vyh = INVLD;
  sp.mc_vzh = INVLD;
  sp.mc_Sector = INVLD;
  sp.mc_Px = INVLD;
  sp.mc_Py = INVLD;
  sp.mc_Pz = INVLD;
  sp.mc_P = INVLD;
  sp.mc_Betta = INVLD;
  sp.mc_Mass2 = INVLD;
  sp.mc_deltaZ = INVLD;
  sp.mc_pid = INVLD;
}

void AssignElectronVar_SIMREC(TIdentificatorV2* t, sim_e& se, Int_t evnt, TString dataKind, TString targetOption) {
  // simrec (46)
  se.Q2 = t->Q2();
  se.W = t->W();
  se.Nu = t->Nu();
  se.Xb = t->Xb();
  se.Yb = t->Yb();
  se.vxe = t->X(0);
  se.vye = t->Y(0);
  se.vze = t->Z(0);
  se.Sector = t->Sector(0);
  se.Px = t->Px(0);
  se.Py = t->Py(0);
  se.Pz = t->Pz(0);
  se.P = t->Momentum(0);
  se.Betta = t->Betta(0);
  se.Etot = t->Etot(0);
  se.Ein = t->Ein(0);
  se.Eout = t->Eout(0);
  TVector3* fVert = t->GetCorrectedVert();
  se.vxec = fVert->X();
  se.vyec = fVert->Y();
  se.vzec = fVert->Z();
  se.TargType = t->TargTypeSM(dataKind, targetOption, 0);
  se.XEC = t->XEC(0);
  se.YEC = t->YEC(0);
  se.ZEC = t->ZEC(0);
  se.ThetaLab = t->ThetaLab(0);
  se.PhiLab = t->PhiLab(0);
  se.StatDC = t->StatDC(0);
  se.DCStatus = t->DCStatus(0);
  se.StatEC = t->StatEC(0);
  se.ECStatus = t->ECStatus(0);
  se.TimeEC = t->TimeEC(0);
  se.PathEC = t->PathEC(0);
  se.Chi2EC = t->Chi2EC(0);
  se.StatSC = t->StatSC(0);
  se.SCStatus = t->SCStatus(0);
  se.TimeSC = t->TimeSC(0);
  se.PathSC = t->PathSC(0);
  se.StatCC = t->StatCC(0);
  se.CCStatus = t->CCStatus(0);
  se.Nphe = t->Nphe(0);
  se.Chi2CC = t->Chi2CC(0);
  se.Status = t->Status(0);
  se.NRowsDC = t->NRowsDC();
  se.NRowsEC = t->NRowsEC();
  se.NRowsSC = t->NRowsSC();
  se.NRowsCC = t->NRowsCC();
}

void AssignElectronVar_GSIM(TIdentificatorV2* t, sim_e& se, Int_t evnt, TString dataKind, TString targetOption) {
  // event-related (1)
  se.evnt = evnt;
  // gsim (17)
  se.mc_Q2 = t->Q2(1);
  se.mc_W = t->W(1);
  se.mc_Nu = t->Nu(1);
  se.mc_Xb = t->Xb(1);
  se.mc_Yb = t->Yb(1);
  se.mc_vxe = t->X(0, 1);
  se.mc_vye = t->Y(0, 1);
  se.mc_vze = t->Z(0, 1);
  se.mc_Sector = t->Sector(0, 1);
  se.mc_Px = t->Px(0, 1);
  se.mc_Py = t->Py(0, 1);
  se.mc_Pz = t->Pz(0, 1);
  se.mc_P = t->Momentum(0, 1);
  se.mc_Betta = t->Betta(0, 1);
  se.mc_ThetaLab = t->ThetaLab(0, 1);
  se.mc_PhiLab = t->PhiLab(0, 1);
  se.mc_TargType = t->TargTypeSM(dataKind, targetOption, 1);
}

void AssignParticleVar_SIMREC(TIdentificatorV2* t, sim_p& sp, Int_t row, Int_t evnt, TString dataKind, TString targetOption) {
  // simrec electron (46)
  sp.Q2 = t->Q2();
  sp.W = t->W();
  sp.Nu = t->Nu();
  sp.Xb = t->Xb();
  sp.Yb = t->Yb();
  sp.vxe = t->X(0);
  sp.vye = t->Y(0);
  sp.vze = t->Z(0);
  sp.SectorEl = t->Sector(0);
  sp.Pex = t->Px(0);
  sp.Pey = t->Py(0);
  sp.Pez = t->Pz(0);
  sp.Pe = t->Momentum(0);
  sp.BettaEl = t->Betta(0);
  sp.Etote = t->Etot(0);
  sp.Eine = t->Ein(0);
  sp.Eoute = t->Eout(0);
  TVector3* fVert = t->GetCorrectedVert();
  sp.vxec = fVert->X();
  sp.vyec = fVert->Y();
  sp.vzec = fVert->Z();
  sp.TargType = t->TargTypeSM(dataKind, targetOption, 0);
  sp.XECe = t->XEC(0);
  sp.YECe = t->YEC(0);
  sp.ZECe = t->ZEC(0);
  sp.PhiLabEl = t->PhiLab(0);
  sp.ThetaLabEl = t->ThetaLab(0);
  sp.StatDCEl = t->StatDC(0);
  sp.DCStatusEl = t->DCStatus(0);
  sp.StatECEl = t->StatEC(0);
  sp.ECStatusEl = t->ECStatus(0);
  sp.TimeECEl = t->TimeEC(0);
  sp.PathECEl = t->PathEC(0);
  sp.Chi2ECEl = t->Chi2EC(0);
  sp.StatSCEl = t->StatSC(0);
  sp.SCStatusEl = t->SCStatus(0);
  sp.TimeSCEl = t->TimeSC(0);
  sp.PathSCEl = t->PathSC(0);
  sp.StatCCEl = t->StatCC(0);
  sp.CCStatusEl = t->CCStatus(0);
  sp.NpheEl = t->Nphe(0);
  sp.Chi2CCEl = t->Chi2CC(0);
  sp.StatusEl = t->Status(0);
  sp.NRowsDCEl = t->NRowsDC();
  sp.NRowsECEl = t->NRowsEC();
  sp.NRowsSCEl = t->NRowsSC();
  sp.NRowsCCEl = t->NRowsCC();
  // simrec particle (49)
  sp.pid = particleID(t->GetCategorization(row, dataKind, targetOption));  // in PDG numbering scheme
  sp.vxh = t->X(row);
  sp.vyh = t->Y(row);
  sp.vzh = t->Z(row);
  sp.Sector = t->Sector(row);
  sp.deltaZ = t->Z(row) - fVert->Z();
  sp.XEC = t->XEC(row);
  sp.YEC = t->YEC(row);
  sp.ZEC = t->ZEC(row);
  sp.Etot = t->Etot(row);
  sp.Ein = t->Ein(row);
  sp.Eout = t->Eout(row);
  // let's define some auxiliary Double_t
  Double_t fMass = particleMass(sp.pid);
  TLorentzVector* fGamma = t->GetCorrPhotonMomentum(row);
  Double_t fPx = (sp.pid == 22) * fGamma->Px() + (sp.pid != 22) * t->Px(row);
  Double_t fPy = (sp.pid == 22) * fGamma->Py() + (sp.pid != 22) * t->Py(row);
  Double_t fPz = (sp.pid == 22) * fGamma->Pz() + (sp.pid != 22) * t->Pz(row);
  Double_t fP = TMath::Sqrt(fPx * fPx + fPy * fPy + fPz * fPz);
  Double_t fE = (sp.pid == 22) * fGamma->E() + (sp.pid != 22) * TMath::Sqrt(fMass * fMass + fP * fP);
  Double_t fZ = fE / t->Nu();
  // continue...
  sp.Px = fPx;
  sp.Py = fPy;
  sp.Pz = fPz;
  sp.P = fP;
  sp.PhiLab = PhiLab(fPx, fPy, fPz);
  sp.ThetaLab = ThetaLab(fPx, fPy, fPz);
  sp.Eh = fE;
  sp.Zh = fZ;
  sp.ThetaPQ = ThetaPQ(t->Px(0), t->Py(0), t->Pz(0), fPx, fPy, fPz);
  sp.PhiPQ = PhiPQ(t->Px(0), t->Py(0), t->Pz(0), fPx, fPy, fPz);
  Double_t fCosThetaPQ = (fPz * (kEbeam - t->Pz(0)) - fPx * t->Px(0) - fPy * t->Py(0)) / (TMath::Sqrt(t->Nu() * t->Nu() + t->Q2()) * fP);
  Double_t fPt2 = fP * fP * (1 - fCosThetaPQ * fCosThetaPQ);
  Double_t fPl2 = fP * fP * fCosThetaPQ * fCosThetaPQ;
  sp.Pt2 = fPt2;
  sp.Pl2 = fPl2;
  sp.Mx2 = t->W() * t->W() + fMass * fMass - 2 * fZ * t->Nu() * t->Nu() + 2 * TMath::Sqrt(fPl2 * (t->Nu() * t->Nu() + t->Q2())) - 2 * kMassProton * fZ * t->Nu();
  sp.T = fMass * fMass - 2 * fZ * t->Nu() * t->Nu() + 2 * TMath::Sqrt(fPl2 * (t->Nu() * t->Nu() + t->Q2())) - t->Q2();
  sp.Betta = t->Betta(row);  // BettaMeasured
  sp.Mass2 = fP * fP * (TMath::Power(t->Betta(row), -2) - 1);
  sp.T4 = t->PathSC(0) / 30. - t->TimeSC(0) + t->TimeSC(row) - (t->PathSC(row) / 30.) * TMath::Sqrt(TMath::Power(fMass / fP, 2) + 1);
  // status
  sp.StatDC = t->StatDC(row);
  sp.DCStatus = t->DCStatus(row);
  sp.StatEC = t->StatEC(row);
  sp.ECStatus = t->ECStatus(row);
  sp.TimeEC = t->TimeEC(row);
  sp.PathEC = t->PathEC(row);
  sp.Chi2EC = t->Chi2EC(row);
  sp.StatSC = t->StatSC(row);
  sp.SCStatus = t->SCStatus(row);
  sp.TimeSC = t->TimeSC(row);
  sp.PathSC = t->PathSC(row);
  sp.StatCC = t->StatCC(row);
  sp.CCStatus = t->CCStatus(row);
  sp.Nphe = t->Nphe(row);
  sp.Chi2CC = t->Chi2CC(row);
  sp.Status = t->Status(row);
  sp.NRowsDC = t->NRowsDC();
  sp.NRowsEC = t->NRowsEC();
  sp.NRowsSC = t->NRowsSC();
  sp.NRowsCC = t->NRowsCC();
}

void AssignParticleVar_GSIM(TIdentificatorV2* t, sim_p& sp, Int_t row, Int_t evnt, TString dataKind, TString targetOption) {
  // event-related (1)
  sp.evnt = evnt;
  // gsim electron (17)
  sp.mc_Q2 = t->Q2(1);
  sp.mc_W = t->W(1);
  sp.mc_Nu = t->Nu(1);
  sp.mc_Xb = t->Xb(1);
  sp.mc_Yb = t->Yb(1);
  sp.mc_vxe = t->X(0, 1);
  sp.mc_vye = t->Y(0, 1);
  sp.mc_vze = t->Z(0, 1);
  sp.mc_SectorEl = t->Sector(0, 1);
  sp.mc_Pex = t->Px(0, 1);
  sp.mc_Pey = t->Py(0, 1);
  sp.mc_Pez = t->Pz(0, 1);
  sp.mc_Pe = t->Momentum(0, 1);
  sp.mc_BettaEl = t->Betta(0, 1);
  sp.mc_ThetaLabEl = t->ThetaLab(0, 1);
  sp.mc_PhiLabEl = t->PhiLab(0, 1);
  sp.mc_TargType = t->TargTypeSM(dataKind, targetOption, 1);
  // gsim particle (22)
  sp.mc_pid = ToPDG(t->Id(row, 1));  // from GEANT to PDG
  sp.mc_ThetaPQ = t->ThetaPQ(row, 1);
  sp.mc_PhiPQ = t->PhiPQ(row, 1);
  sp.mc_Pt2 = t->Pt2(row, 1);
  sp.mc_Pl2 = t->Pl2(row, 1);
  Double_t fMass = particleMass(sp.mc_pid);
  Double_t fE = t->Zh(row, 1, fMass) * t->Nu(1);
  sp.mc_Zh = t->Zh(row, 1, fMass);
  sp.mc_Eh = fE;
  sp.mc_Mx2 = t->Mx2(row, 1, fMass);
  sp.mc_T = t->T(row, 1, fMass);
  sp.mc_ThetaLab = t->ThetaLab(row, 1);
  sp.mc_PhiLab = t->PhiLab(row, 1);
  sp.mc_vxh = t->X(row, 1);
  sp.mc_vyh = t->Y(row, 1);
  sp.mc_vzh = t->Z(row, 1);
  sp.mc_Sector = t->Sector(row, 1);
  sp.mc_Px = t->Px(row, 1);
  sp.mc_Py = t->Py(row, 1);
  sp.mc_Pz = t->Pz(row, 1);
  sp.mc_P = t->Momentum(row, 1);
  sp.mc_Betta = t->Betta(row, 1);
  sp.mc_Mass2 = t->Mass2(row, 1);
  sp.mc_deltaZ = t->Z(row, 1) - t->Z(0, 1);
}

/************************/
/*** VECTOR FUNCTIONS ***/
/***                  ***/
/************************/

RVec<Int_t> SortByMomentum(TIdentificatorV2* t, RVec<Int_t> vector_row, Int_t kind) {
  // Returns a new "vector_row2" where particle indices are sorted by their respective momentum (from lower to higher)
  // first, fill the momentum vector
  RVec<Double_t> momentum;
  for (Int_t m = 0; m < (Int_t)vector_row.size(); m++) {
    momentum.push_back(t->Momentum(vector_row[m], kind));
  }
  // Argsort() creates an indices-vector with the indices sorted by the input-vector values
  RVec<Int_t> indices = Argsort(momentum);
  // Take(input-vector, indices-vector) creates a sorted-vector by moving all input-vector indices to match the order assigned by the indices-vector
  RVec<Int_t> vector_row2 = Take(vector_row, indices);
  return vector_row2;
}

void AngularMatching(TIdentificatorV2* t, RVec<Int_t>& simrec_row, RVec<Int_t>& gsim_row, TString dataKind, TString targetOption) {
  // Matches the "simrec_row" vector with the "gsim_row" vector under angular matching
  // if particles don't match, the counterpart is filled with null

  // worst from electron (CLAS paper @ P = 0.75 GeV):
  //       fDeltaThetaLab = 0.33, fDeltaPhiLab = 0.96
  // arbitrary values:
  //       fDeltaThetaLab = 0.5, fDeltaPhiLab = 2.0
  // measured values: (worst from pi+ with 0 < P < 0.35 GeV)
  //       fDeltaThetaLab = 0.78, fDeltaPhiLab = 1.41
  // worst from electron (CLAS paper @ P = 0.1 GeV):
  const Double_t fDeltaThetaLab = 2.40;  // Delta_Theta = 3*sigma_Theta
  const Double_t fDeltaPhiLab = 5.43;    // Delta_Phi = 3*sigma_Phi

  // define output vectors - initially empty
  RVec<Int_t> simrec_new;
  RVec<Int_t> gsim_new;

  // declare PhiLab and ThetaLab
  Double_t simrec_phi;
  Double_t simrec_theta;
  Double_t gsim_phi;
  Double_t gsim_theta;

  // define vector sizes - loop length
  Int_t M = (Int_t)gsim_row.size();
  Int_t N = (Int_t)simrec_row.size();

  // m, n are the vectors' indices
  for (Int_t m = 0; m < M; m++) {
    for (Int_t n = 0; n < N; n++) {

      // gsim angles don't need correction
      gsim_phi = PhiLab(t->Px(gsim_row[m], 1), t->Py(gsim_row[m], 1), t->Pz(gsim_row[m], 1));
      gsim_theta = ThetaLab(t->Px(gsim_row[m], 1), t->Py(gsim_row[m], 1), t->Pz(gsim_row[m], 1));

      // for reconstructed photons
      TLorentzVector* fGamma = t->GetCorrPhotonMomentum(simrec_row[n]);
      TString fParticleName = t->GetCategorization(simrec_row[n], dataKind, targetOption);
      Double_t fPx = (fParticleName == "gamma") * fGamma->Px() + (fParticleName != "gamma") * t->Px(simrec_row[n], 0);
      Double_t fPy = (fParticleName == "gamma") * fGamma->Py() + (fParticleName != "gamma") * t->Py(simrec_row[n], 0);
      Double_t fPz = (fParticleName == "gamma") * fGamma->Pz() + (fParticleName != "gamma") * t->Pz(simrec_row[n], 0);

      simrec_phi = PhiLab(fPx, fPy, fPz);
      simrec_theta = ThetaLab(fPx, fPy, fPz);

      /*** MATCHING CONDITION ***/

      Bool_t fAngularMatching = TMath::Abs(simrec_phi - gsim_phi) < fDeltaPhiLab && TMath::Abs(simrec_theta - gsim_theta) < fDeltaThetaLab;
      if (fAngularMatching && std::find(gsim_new.begin(), gsim_new.end(), gsim_row[m]) == gsim_new.end() &&
          std::find(simrec_new.begin(), simrec_new.end(), simrec_row[n]) == simrec_new.end()) {
        // std::find function returns an iterator to the first element in the range ["begin","end"[ that compares equal to "row"
        // if no such element is found, the function returns "end", this is done to prevent particles that already matched
        gsim_new.push_back(gsim_row[m]);      // add gsim_row to gsim_new
        simrec_new.push_back(simrec_row[n]);  // add simrec_row to simrec_new
      }

    }  // end of simrec loop
  }    // end of gsim loop

  /*** FILL REMAINING ***/

  for (Int_t m = 0; m < M; m++) {
    // if it's not in gsim_new
    if (std::find(gsim_new.begin(), gsim_new.end(), gsim_row[m]) == gsim_new.end()) {
      gsim_new.push_back(gsim_row[m]);  // add gsim_row to gsim_new
      simrec_new.push_back(-1);         // add null simrec
    }
  }

  for (Int_t n = 0; n < N; n++) {
    // if it's not in simrec_new
    if (std::find(simrec_new.begin(), simrec_new.end(), simrec_row[n]) == simrec_new.end()) {
      simrec_new.push_back(simrec_row[n]);  // add simrec_row to simrec_new
      gsim_new.push_back(-1);               // add null gsim
    }
  }

  // assign results
  gsim_row = gsim_new;
  simrec_row = simrec_new;
}
