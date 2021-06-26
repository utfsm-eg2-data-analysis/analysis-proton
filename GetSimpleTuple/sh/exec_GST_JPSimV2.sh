#!/bin/bash

####################################################################################
# ./run_GST_JPSim.sh <target> <first nset> <final nset> <first run> <last run>     #
#     <target> = (D, C, Fe, Pb)                                                    #
#     <nset>   = (1 - 10)                                                          #
#                                                                                  #
# EG: ./run_GST_JPSimV2.sh D 1 25 1 1000                                            #
#                                                                                  #
####################################################################################

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
FNSET=${INPUTARRAY[1]}
LNSET=${INPUTARRAY[2]}
FIRSTRUN=${INPUTARRAY[3]}
LASTRUN=${INPUTARRAY[4]}


#if [[ "$TARNAME" == "C" && $NSET -lt 3 ]]; then
#    NFILES=12
#else
#    NFILES=10
#fi


SUFIX="${TARNAME}" # usually, the end of the root files is like this

#####
# Main
###

# set env
source ~/.bashrc

for ((NST=${FNSET}; NST <= ${LNSET}; NST++)); do
    # set main dirs
    NSET=$(get_num_2dig $NST)
    #echo "------------------- START set=${NSET} ------------------------"
# set main dirs
    GSTDIR=${HOME}/GetSimpleTuple                                             # dir of the executable
    SIMDIR=/lustre19/expphy/volatile/clas/claseg2/jpgarces/particleSim/farm/${TARNAME}/${NSET}      # dir where are located all the JPSims
    OUTDIR=/lustre19/expphy/volatile/clas/claseg2/jpgarces/out${TARNAME}/GetSimpleTuple/sim/${NSET}               # output dir
    MRGDIR=/lustre19/expphy/volatile/clas/claseg2/jpgarces/out${TARNAME}/GetSimpleTuple/sim/merged
    FINDIR=/lustre19/expphy/volatile/clas/claseg2/jpgarces/out${TARNAME}/GetSimpleTuple/sim
    mkdir -p ${FINDIR}
    mkdir -p ${OUTDIR} # just in case
    mkdir -p ${MRGDIR}

    for ((RN=${FIRSTRUN}; RN <= ${LASTRUN}; RN++)); do # ${NFILES} or 1 for test
	SRN=$(get_num_4dig $RN)                                                              # run number to string
	INDIR=${SIMDIR}/run${SRN}                                
	#echo "-------------------------- START run= ${RN} -------------------------"# define input directory
	mv -v ${INDIR}/recsis${TARNAME}.root ${INDIR}/recsis${TARNAME}_${SRN}.root           # change name of file to GST format
	#echo "${INDIR}/recsis${TARNAME}.root -> ${INDIR}/recsis${TARNAME}_${SRN}.root"
	cp -v ${GSTDIR}/bin/GetSimpleTuple_sim ${INDIR}/
        #echo "Copying GetSimpleTuple_sim" # copy binary to simdir
	cd ${INDIR}                                                                          # enter input directory
	./GetSimpleTuple_sim -t${TARNAME} -r${SRN}
        #echo "Running GetSimpleTuple_sim" # execute program
	mv -v pruned${TARNAME}_${SRN}.root ${OUTDIR}/pruned${TARNAME}_${NSET}_${SRN}.root
	#echo "Moved pruned${TARNAME}_${SRN}.root to ${OUTDIR}" # move output file to outdir
	mv -v ${INDIR}/recsis${TARNAME}_${SRN}.root ${INDIR}/recsis${TARNAME}.root           # change name of file to original name
	rm -v ${INDIR}/GetSimpleTuple_sim        
        #echo "Renamed to original and removed GetSimpleTuple_sim" # remove binary from input directory
    done

    cd ${OUTDIR}

    #echo "Changed directory to ${OUTDIR}"

    hadd pruned${TARNAME}_${NSET}.root *.root

    #echo "Ran hadd to get pruned${TARNAME}_${NSET}.root"

    mv -v pruned${TARNAME}_${NSET}.root ${MRGDIR}

    #echo "Moved pruned${TARNAME}_${NSET}.root to ${MRGDIR}"
    
    cd ../

    rm -rf ${NSET}

    #echo "Remove ${OUTDIR}"
done

cd ${MRGDIR}

#echo "Changed directory to ${MGDIR}"

hadd pruned${TARNAME}.root *.root

#echo "Ran hadd to get pruned${TARNAME}.root"

mv -v pruned${TARNAME}.root ${FINDIR}

#echo "Moved pruned${TARNAME}.root to ${FINDIR}" 

cd ../

rm -rf merged  

#echo "Removed ${MRGDIR}"
