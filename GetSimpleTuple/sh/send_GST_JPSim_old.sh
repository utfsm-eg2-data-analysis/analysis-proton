#!/bin/bash

###############################################################
# ./send_GST_HSim.sh <target> <nset>                          #
#     <target> = (D, C, Fe, Pb)                               #
#     <ndir>   = (1 - 9)                                      #
#                                                             #
# EG: ./send_GST_JPSim.sh C 1                                 #
#     ./send_GST_JPSim.sh Fe 2                                #
#     ./send_GST_JPSim.sh Pb 3                                #
#     ./send_GST_JPSim.sh D 4                                 #
###############################################################

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
NST=${INPUTARRAY[1]}
NSET=$(get_num_2dig $NST)

SUFIX="${TARNAME}" # usually, the end of the root files is like this

#####
# Main
###

# set env
source ~/.bashrc



# set main dirs
GSTDIR=${HOME}/GetSimpleTuple                                              # dir of the executable
SIMDIR=/lustre19/expphy/volatile/clas/claseg2/jpgarces/particleSim/farm/${TARNAME}/${NSET}   # dir where are located all the JPSims
OUTDIR=/lustre19/expphy/volatile/clas/claseg2/jpgarces/out${TARNAME}/GetSimpleTuple/sim/${NSET} # output dir
TMPDIR=/lustre19/expphy/volatile/clas/claseg2/jpgarces/tmp/GetSimpleTuple_JPSim/${TARNAME}/${NSET} # temp dir to store logs and job scripts
mkdir -p ${OUTDIR} ${TMPDIR} # just in case
# setting jobname

NFILES=1
for ((RN=1; RN <= ${NFILES}; RN++)); do # ${NFILES} or 10 for test
    SRN=$(get_num_4dig $RN)
    INDIR=${SIMDIR}/run${SRN}
    inputfile=$(readlink -f ${INDIR}/recsis${TARNAME}.root)   # retrieve full path of input file (with $SUFIX)
    jobname="GST_JPSim_${TARNAME}_${NSET}_${SRN}"
    echo ${jobname}
    mkdir -p ${TMPDIR}/run${SRN}
    jobfile="${TMPDIR}/run${SRN}/job_particle.xml"
    proj="eg2a"
    track="debug" # "analysis" or "debug"
    time="10" # "240" or "5" minutes
    diskspace="500"
    memusage="2"
    osname="general"

    echo "<Request>"                                                                       > $jobfile
    echo "  <Project name=\"$proj\"></Project>"                                           >> $jobfile
    echo "  <Track name=\"$track\"></Track>"                                              >> $jobfile
    echo "  <TimeLimit time=\"$time\" unit=\"minutes\"></TimeLimit>"                      >> $jobfile
    echo "  <DiskSpace space=\"$diskspace\" unit=\"MB\"></DiskSpace>"                     >> $jobfile
    echo "  <Memory space=\"$memusage\" unit=\"MB\"></Memory>"                            >> $jobfile
    echo "  <CPU core=\"1\"></CPU>"                                                       >> $jobfile
    echo "  <OS name=\"$osname\"></OS>"                                                   >> $jobfile
    echo "  <Job>"                                                                        >> $jobfile
    echo "    <Name name=\"${jobname}\"></Name>"                                          >> $jobfile
   #echo "    <Input src=\"file:${GSTDIR}/bin/GetSimpleTuple_sim\"  dest=\"${TMPDIR}/run${SRN}/GetSimpleTuple_sim\"/>" >> $jobfile
    echo "    <Input src=\"file:${GSTDIR}/bin/GetSimpleTuple_sim\"  dest=\"GetSimpleTuple_sim\"/>" >> $jobfile
    echo "    <Input src=\"file:${INDIR}/recsis${TARNAME}.root\"  dest=\"recsis${TARNAME}_${SRN}.root\"/>" >> $jobfile
    echo "    <Input src=\"file:${HOME}/.bashrc\"  dest=\".bashrc\"/>"                    >> $jobfile
    echo "    <Command><![CDATA["                                                         >> $jobfile
    echo "    source .bashrc"                                                             >> ${jobfile}
    echo "    echo $LD_LIBRARY_PATH"                                                      >> ${jobfile}
   
      #source /apps/root/6.22.06/setroot_CUE.bash
         #alias root='root -l'
         #export OS_NAME=`uname`
         #export OSNAME=${OS_NAME}
         #export CLASTOOL=${HOME}/ClasTool
         #export CLAS_LIB=${HOME}/clas_lib
         #export CLAS_PACK=${HOME}/clas_pack
         #export PATH=${CLASTOOL}/bin/${OSNAME}:${PATH}
         #export ROOT_INCLUDE_PATH=${CLASTOOL}/include:${ROOT_INCLUDE_PATH}
         #export LD_LIBRARY_PATH=${CLASTOOL}/slib/${OS_NAME}:${LD_LIBRARY_PATH}
    #echo "      export "
    echo "      ./GetSimpleTuple_sim -t${TARNAME} -r${SRN}"                     >> ${jobfile} # execute program
    echo "    ]]></Command>"                                                              >> $jobfile
    echo "    <Output src=\"file:pruned${TARNAME}_${SRN}.root\"    dest=\"file:${OUTDIR}/pruned${TARNAME}_${SRN}.root\" /> "     >> $jobfile
    echo "    <Stdout dest=\"${TMPDIR}/run${SRN}/${jobname}.out\"></Stdout>"                        >> $jobfile
    echo "    <Stderr dest=\"${TMPDIR}/run${SRN}/${jobname}.err\"></Stderr>"                        >> $jobfile
    echo "  </Job>"                                                                       >> $jobfile
    echo "</Request>"                                                                     >> $jobfile
    echo "Running job $jobfile..."
    jsub --xml $jobfile
done
