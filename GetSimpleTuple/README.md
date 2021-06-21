GetSimpleTuple
=================

## Requirements

* **ROOT** (version 6.14 onwards)

* [**ClasTool**](http://github.com/utfsm-eg2-data-analysis/ClasTool)

## Installation from zero

Please, refer to the document `INSTALL.md`

## Compilation

If you already have **ClasTool** installed, to compile just execute `make` in the current directory. The binary file (or execution file) will be located in directory `bin/`.

**IMPORTANT:** you must use the same version of ROOT that you used to compile **ClasTool**.

## Execution of GetSimpleTuple_data

At least one `.pass2.root` file must be located in the same directory as the binary file. Usage is:

* To print usage and exit program:

  ```
  ./GetSimpleTuple_data -h
  ```

* To select the files to read: (the program will look for all the files that satisfy the following filename scheme: `clas_<run number>_*.pass2.root`. For instance, if you want to filter just one file, then you need to have only that file in the same directory)

  ```
  ./GetSimpleTuple_data -t[target] -r[run number]
  ``` 

  For example, if you have all the files from the run number `42011`, by executing the following, the program will read all of them.

  ```
  ./GetSimpleTuple_data -tC -r42011
  ```

  The target option is necessary for some target-dependent functions, such as the Sampling Fraction Cuts. The full and updated lists of run numbers for each target is located in `include/C-thickD2rn.txt`, `include/Fe-thickD2rn.txt` and `include/Pb-thinD2rn.txt`, respectively.
  
## Execution of GetSimpleTuple_sim

A ClasTool-formatted root file must be located in the same directory as the binary file. Usage is:

* To print usage and exit program:

  ```
  ./GetSimpleTuple_sim -h
  ```

* To select the file to read: (filename scheme must be: `recsis<target>_<run number>.root`)

  ```
  ./GetSimpleTuple_sim -t[target] -r[run number]
  ``` 

  For example, to read a file called `recsisD_00.root`, one should execute:

  ```
  ./GetSimpleTuple_sim -tD -r00
  ``` 

## Structure of the programs

* `src/GetSimpleTuple_data.cxx`

  This is the **source** code of **GetSimpleTuple_data**. It iterates on the events of the input file. From each event, it will (1) read the **EVNT** bank, (2) identify the detected particles. The core of the program is between the **Lines 78-81**, where you can choose which particle you want to filter.

* `include/GetSimpleTuple_data.hxx`

  This library is in charge of all the **input-output operations** of the `TTree` objects.

* `src/GetSimpleTuple_sim.cxx`

  This is the **source** code of **GetSimpleTuple_sim**. It iterates on the events of the input file. From each event, it will (1) read the **GSIM** bank, (2) identify the generated particles, (3) read the **EVNT** bank, (4) identify the reconstructed particles. To store each particle, it will save the iteration number (from the **GSIM** and **EVNT** iterations) into a `RVec<Int_t>` object for each kind of particle, this will allows us to do a further management of the particles. Such as sorting them by kind of particle, by momentum and by **angular matching**.

* `include/GetSimpleTuple_sim.hxx`

  This library is in charge of all the **input-output operations** of the `TTree` objects, as well as the **vector operations** for each `RVec<Int_t>` object, such as `SortByMomentum()` and `AngularMatching()`.

* `include/GSTtree.h`

  This library contains the definition of the **data structures** that will store all the input and output variables.

* `include/TIdentificatorV2.h`

  This is the historical program **Analyser** condensed into a single-file standalone library.

## How to send jobs to the USM farm

Please, refer to `sh/README.md`