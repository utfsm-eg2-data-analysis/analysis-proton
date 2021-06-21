#!/bin/bash

#################################################################################
# ./run_final_merge.sh <target> <first nset> <final nset>                       #
#     <target> = (D, C, Fe, Pb)                                                 #
#     <nset>   = (1 - 10)                                                       #
#                                                                               #
# EG: ./run_final_merge.sh D 1 25                                               #
#################################################################################

#####
# Function
###select 

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
FNSET=${INPUTARRAY[1]}
LNSET=${INPUTARRAY[2]}

####
# Main
###

# set env
source ~/.bashrc

for ((NST=${FNSET}; NST <= ${LNSET}; NST++)); do
    # set main dirs
    NSET=$(get_num_2dig $NST)
    OUTDIR=/lustre19/expphy/volatile/clas/claseg2/jpgarces/GST_out/${TARNAME}
    SIMDIR=/lustre19/expphy/volatile/clas/claseg2/jpgarces/GST_out/${TARNAME}/${NSET}-merged      # dir where are located all the JPSims
   
    mkdir -p ${OUTDIR}/merged
    
    cd ${SIMDIR}

    hadd pruned${TARNAME}_${NSET}_merged.root *.root #merge run files
    
    mv -v pruned${TARNAME}_${NSET}_merged.root ${OUTDIR}/merged/pruned${TARNAME}_${NSET}_merged.root
done

cd ${OUTDIR}/merged

hadd pruned${TARNAME}_merged.root *.root

mv -v pruned${TARNAME}_merged.root ${OUTDIR}/pruned${TARNAME}_merged.root

rm -rf ${OUTDIR}/merged
