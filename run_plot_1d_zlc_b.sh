#!/bin/bash                                                                                                                                                                                                

# set env                                                                                                                                                                                                  
source /home/jpgarces/.bashrc

TRN=
FSTN=

root -l -q "plot_1d_zlc_b.C('${TRN}',${FSTN})"  
