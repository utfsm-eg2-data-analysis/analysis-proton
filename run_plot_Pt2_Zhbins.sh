#!/bin/bash                                                                                                                                                                                                

# set env                                                                                                                                                                                                  
source /home/jpgarces/.bashrc

TRN=
FSTN=
SCDN=

root -l -q "plot_Pt2_Zhbins.C('${TRN}',${FSTN},${SCDN})"  
