/***************************************/
/*  GetSimpleTuple_data.cxx            */
/*                                     */
/*  Andrés Bórquez                     */
/*                                     */
/***************************************/

// December 2020
// Independent of Analyser

#include "GetSimpleTuple_data.hxx"

/*** Options ***/

TString targetOption;
TString rnOption;

TString dataKind = "data";

/*** Declaration of functions ***/

int parseCommandLine(int argc, char *argv[]);
void printOptions();
void printUsage();

int main(int argc, char **argv) {
  parseCommandLine(argc, argv);
  printOptions();

  SetNumberingScheme("PDG");

  // assign options
  TString inputFiles = "clas_" + rnOption + "_*.pass2.root";                // *: all rn files, node dir
  TString outputFile = "pruned" + targetOption + "_" + rnOption + ".root";  // node dir
  TString outTitle = "Data of particles";

  /*** DATA STRUCTURES ***/

  // output
  data_e de;
  data_p dp;

  /*** INPUT ***/

  // init ClasTool
  TClasTool *input = new TClasTool();
  input->InitDSTReader("ROOTDSTR");

  input->Add(inputFiles);

  // define TIdentificatorV2
  TIdentificatorV2 *t = new TIdentificatorV2(input);
  Int_t nEvents = (Int_t)input->GetEntries();

  /*** OUTPUT ***/

  // define output file
  TFile *rootFile = new TFile(outputFile, "RECREATE", outTitle);

  // define output ntuples
  TTree *tElectrons = new TTree("ntuple_e", "All electrons");
  SetElectronBranches_Data(tElectrons, de);

  TTree *tParticles = new TTree("ntuple_data", "Stable particles");
  SetParticleBranches_Data(tParticles, dp);

  /*** START ***/

  // jumps to first readable event (mandatory)
  input->Next();

  // loop around events
  for (Int_t i = 0; i < nEvents; i++) {  // nEvents or 2000
    if (input->GetNRows("EVNT") > 0) {   // prevent seg-fault
      if (t->GetCategorization(0, dataKind, targetOption) == "electron") {
        AssignElectronVar_Data(t, de, i, dataKind, targetOption);  // (TIdentificator, data_e, evnt, dataKind, targetOption)
        tElectrons->Fill();
        // loop in detected particles
        for (Int_t p = 1; p < input->GetNRows("EVNT"); p++) {
          // rest of particles
          if (t->GetCategorization(p, dataKind, targetOption) == "proton") {
            AssignParticleVar_Data(t, dp, p, i, dataKind, targetOption);  // (TIdentificator, data_p, row, evnt, dataKind, targetOption)
            tParticles->Fill();
          }
        }  // end of loop in rest of particles
      }    // end of electron condition
    }      // end of smth-in-EVNT-bank condition

    // next event!
    input->Next();
  }  // end of loop in events

  // write and close output file
  rootFile->Write();
  rootFile->Close();
  std::cout << "File " << outputFile << " has been created!" << std::endl;

  return 0;
}

/*** Input/output functions ***/

void printUsage() {
  std::cout << "GetSimpleTuple_data program. Usage is:" << std::endl;
  std::cout << std::endl;
  std::cout << "./GetSimpleTuple_data -h" << std::endl;
  std::cout << "    prints usage and exit program" << std::endl;
  std::cout << std::endl;
  std::cout << "./GetSimpleTuple_data -t[target]" << std::endl;
  std::cout << "    selects target, which can be: C, Fe, Pb" << std::endl;
  std::cout << std::endl;
  std::cout << "./GetSimpleTuple_data -r[run number]" << std::endl;
  std::cout << "    selects run number" << std::endl;
  std::cout << "    numbering scheme for data files = clas_<run number>_*.pass2.root" << std::endl;
  std::cout << std::endl;
}

int parseCommandLine(int argc, char *argv[]) {
  int c;
  if (argc == 1) {
    std::cerr << "Empty command line. Execute ./bin/GetSimpleTuple_data -h to print usage." << std::endl;
    exit(1);
  }
  while ((c = getopt(argc, argv, "ht:r:")) != -1) switch (c) {
      case 'h':
        printUsage();
        exit(0);
        break;
      case 't':
        targetOption = optarg;
        break;
      case 'r':
        rnOption = optarg;
        break;
      default:
        std::cerr << "Unrecognized argument. Execute ./bin/GetSimpleTuple_data -h to print usage." << std::endl;
        exit(0);
        break;
    }
}

void printOptions() {
  std::cout << "Executing GetSimpleTuple_data program. The chosen parameters are: " << std::endl;
  std::cout << "  targetOption   = " << targetOption << std::endl;
  std::cout << "  rnOption       = " << rnOption << std::endl;
  std::cout << std::endl;
}
