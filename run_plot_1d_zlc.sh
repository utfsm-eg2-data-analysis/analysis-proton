#!/bin/bash                                                                                                                                                                                                

# set env                                                                                                                                                                                                  
source /home/jpgarces/.bashrc

TRN=
FSTN=

root -l -q "plot_1d_zlc.C('${TRN}',${FSTN})"  
