#!/bin/bash

##############################################################
# ./run_GST_JPSim.sh <target> <first nset> <final nset> <first run> <last run>  #
#     <target> = (D, C, Fe, Pb)                                                 #
#     <nset>   = (1 - 10)                                    #
#                                                            #
# EG: ./run_move.sh D 1 25 1 1000                              #
#     ./run_GST_JPSim.sh Fe 2                                #
#     ./run_GST_JPSim.sh Pb 3                                #
#     ./run_GST_JPSim.sh D 1                                 #
##############################################################

#####
# Function
###select 

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

#####
# Input
###

INPUTARRAY=("$@")

TARNAME=${INPUTARRAY[0]}
FNSET=${INPUTARRAY[1]}
LNSET=${INPUTARRAY[2]}
FIRSTRUN=${INPUTARRAY[3]}
LASTRUN=${INPUTARRAY[4]}

#####
# Main
###

# set env
source ~/.bashrc

# set main dirs
SIMDIR=/lustre19/expphy/volatile/clas/claseg2/jpgarces/particleSim/farm/${TARNAME}/${NSET}      # dir where are located all the JPSims
OUTDIR=/lustre19/expphy/volatile/clas/claseg2/jpgarces/particleSim/farm/${TARNAME}/${NSET}/${FIRSTRUN}-${LASTRUN}               # output dir

for ((NST=${FNSET}; NST <= ${LNSET}; NST++)); do
    # set main dirs
    NSET=$(get_num_2dig $NST)
    #echo "NSET=${NSET}"
    FIRSTDIR=/lustre19/expphy/volatile/clas/claseg2/jpgarces/particleSim/farm/${TARNAME}
    SIMDIR=/lustre19/expphy/volatile/clas/claseg2/jpgarces/particleSim/farm/${TARNAME}/${NSET}      # dir where are located all the JPSims
   
    COUNTER=0

    for ((RN=${FIRSTRUN}; RN <= $((${LASTRUN}/100)); RN++)); do
	STA=$((1+${COUNTER}))
	FIN=$((100+${COUNTER}))
	OUTDIR=/lustre19/expphy/volatile/clas/claseg2/jpgarces/particleSim/farm/${TARNAME}/${NSET}/${STA}-${FIN}               # output dir
	#echo "${OUTDIR}"
	for ((RN2=${STA}; RN2 <= ${FIN}; RN2++)); do # ${NFILES} or 1 for test
	    SRN=$(get_num_4dig $RN2)                                                              # run number to string
	    INDIR=${SIMDIR}/run${SRN}                                                            # define input directory
	    #echo "moving ${OUTDIR}/recsis${TARNAME}_${SRN}.root to ${INDIR}/recsis${TARNAME}.root"
	    mv -v ${OUTDIR}/recsis${TARNAME}_${SRN}.root ${INDIR}/recsis${TARNAME}.root           # change name of file to GST format
	    let COUNTER++
	done
    done

done
