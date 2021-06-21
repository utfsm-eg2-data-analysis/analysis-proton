#!/bin/bash

##############################################################
# ./run_GST_JPSim.sh <target> <nset>                         #
#     <target> = (D, C, Fe, Pb)                              #
#     <nset>   = (1 - 10)                                    #
#                                                            #
# EG: ./run_GST_JPSim.sh C 1                                 #
#     ./run_GST_JPSim.sh Fe 2                                #
#     ./run_GST_JPSim.sh Pb 3                                #
#     ./run_GST_JPSim.sh D 1                                 #
##############################################################

#####
# Function
###

function get_num_2dig()
{
  sr2=$1
  srn2=""
  if [[ $sr2 -lt 10 ]]; then
    srn2="0$sr2"
  else
    srn2="$sr2"
  fi
  echo $srn2
}


function get_num_4dig()
{
  sr=$1
  srn=""
  if [[ $sr -lt 10 ]]; then
    srn="000$sr"
  elif [[ $sr -lt 100 ]]; then
    srn="00$sr"
  elif [[ $sr -lt 1000 ]]; then
    srn="0$sr"
  else
    srn="$sr"
  fi
  echo $srn
}

#####
# Input
###

INPUTARRAY=("$@")

TARNAME=${INPUTARRAY[0]}
NSET=$(get_num_2dig ${INPUTARRAY[1]})

#if [[ "$TARNAME" == "C" && $NSET -lt 3 ]]; then
#    NFILES=12
#else
#    NFILES=10
#fi

NFILES=1000

SUFIX="${TARNAME}" # usually, the end of the root files is like this

#####
# Main
###

# set env
source ~/.bashrc

# set main dirs
GSTDIR=${HOME}/GetSimpleTuple                                             # dir of the executable
SIMDIR=/lustre19/expphy/volatile/clas/claseg2/jpgarces/particleSim/farm/${TARNAME}/${NSET}      # dir where are located all the JPSims
OUTDIR=/lustre19/expphy/volatile/clas/claseg2/jpgarces/out${TARNAME}/GetSimpleTuple/sim               # output dir
mkdir -p ${OUTDIR} # just in case

for ((RN=1; RN <= ${NFILES}; RN++)); do # ${NFILES} or 1 for test
    SRN=$(get_num_4dig $RN)                                                              # run number to string
    INDIR=${SIMDIR}/run${SRN}                                                            # define input directory
    mv -v ${INDIR}/recsis${TARNAME}.root ${INDIR}/recsis${TARNAME}_${SRN}.root           # change name of file to GST format
    cp -v ${GSTDIR}/bin/GetSimpleTuple_sim ${INDIR}/                                     # copy binary to simdir
    cd ${INDIR}                                                                          # enter input directory
    ./GetSimpleTuple_sim -t${TARNAME} -r${SRN}                                           # execute program
    mv -v pruned${TARNAME}_${SRN}.root ${OUTDIR}/pruned${TARNAME}_${NSET}_${SRN}.root # move output file to outdir
    mv -v ${INDIR}/recsis${TARNAME}_${SRN}.root ${INDIR}/recsis${TARNAME}.root           # change name of file to original name
    rm -v ${INDIR}/GetSimpleTuple_sim                                                    # remove binary from input directory
done
