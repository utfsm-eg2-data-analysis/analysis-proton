#!/bin/bash                                                                                                                                                                                                

# set env                                                                                                                                                                                                  
source /home/jpgarces/.bashrc

TRN=
FSTN=

root -l -q "plot_1d_Pt2.C('${TRN}',${FSTN})"  
