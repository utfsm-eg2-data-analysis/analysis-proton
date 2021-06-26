# GetSimpleTuple/sh

## send_GST_HSim.sh

This Bash script creates a job file that is submitted into the USM farm, that is in charge of executing **GetSimpleTuple_sim**
for all the root files inside a Hayk's simulation directory.

Usage is:

```
./send_GST_HSim.sh <target> <ndir>
```

where:

* `<target> = (D, C, Fe, Pb)`

* `<ndir> = (1 - 9)`

Feel free to edit the directories `SIMDIR`, `GSTDIR`, `OUTDIR`, `TMPDIR` at convenience.
The directory `SIMDIR` and the naming scheme of the input files is described within the script.

To run the full sample of simulations, you should run all the `<ndir>` for each `<target>`, that would be a total of 36 jobs.

## send_GST_data.sh

This Bash script creates a job file that is submitted into the USM farm, that is in charge of executing **GetSimpleTuple_data**
for all the root data files in ClasTool format after the Pass2 cooking.

Usage is:

```
./send_GST_data.sh <target>
```

where:

* `<target> = (C, Fe, Pb)`

Feel free to edit the directories `GSTDIR`, `OUTDIR`, `TMPDIR` at convenience.

Contrary to `send_GST_HSim.sh`, to run the full sample of data files, you should run the script for each target, this would send a total
of 549 jobs, one per each **run number**.

All the **run numbers** are specified for each target at `../include/C-thickD2rn.txt`, `../include/Fe-thickD2rn.txt`, `../include/Pb-thinD2rn.txt`
