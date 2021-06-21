#!/bin/bash                                                                                                                                                                                                

# set env                                                                                                                                                                                                  
source /home/jpgarces/.bashrc

TRN=
FSTN=
SCDN=
THRN=

root -l -q "plot_jlab_bins.C('${TRN}',${FSTN},${SCDN},${THRN})"  
