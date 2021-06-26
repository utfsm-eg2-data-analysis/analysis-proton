#!/bin/bash

##########################################################################################
# ./run_jcache.sh <target> <# first merged folder> <# last merged folder> <last run>  #
#     <target> = (D, C, Fe, Pb)                                                          #
#                                                                                        #
# EG: ./run_jcache.sh D 2 25                                                             #
##########################################################################################

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

#####
# Input
###

INPUTARRAY=("$@")

TARNAME=${INPUTARRAY[0]}
FIRSTMRG=${INPUTARRAY[1]}
LASTMRG=${INPUTARRAY[2]}


#####
# Main
###

# set env
source ~/.bashrc

# set main dirsarces/particleSim/farm/${TARNAME}/${NSET}     
INDIR=/lustre19/expphy/volatile/clas/claseg2/jpgarces/particleSim/farm/${TARNAME}
OUTDIR=/cache/clas/eg2a/production/Simulation/Proton_Lepto/${TARNAME}
for ((MRG=${FIRSTMRG}; MRG <= ${LASTMRG}; MRG++)); do # ${NFILES} or 1 for test
    SETN=$(get_num_2dig $MRG)
    COUNTER=0
    for ((FIRSTRN=1; FIRSTRN <= 10; FIRSTRN++)); do
	STA=$((1+100*${COUNTER}))
	END=$(($STA+99))
	cp -r ${INDIR}/${SETN}-merged ${OUTDIR}/
        jcache put ${OUTDIR}/${SETN}-merged/recsis${TARNAME}_${SETN}_${STA}-${END}.root           # change name of file to GST format
        let  COUNTER++
    done
done

