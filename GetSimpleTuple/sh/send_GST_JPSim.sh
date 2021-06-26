#!/bin/bash

###################################################################
# ./send_GST_JPSim.sh <target> <nset>                             #
#     <target> = (D, C, Fe, Pb)                                   #
#     <ndir>   = (1 - 25)-> representing 01-merged,..., 25-merged #
# for((i=1;i<=25;i++)); do ./send_GST_JPSim.sh C ${i}; done       #
# EG: ./send_GST_JPSim.sh C 1                                     #
#     ./send_GST_JPSim.sh Fe 2                                    #
#     ./send_GST_JPSim.sh Pb 3                                    #
#     ./send_GST_JPSim.sh D 4                                     #
###################################################################

#####
# Functions
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

#####
# Input
###

INPUTARRAY=("$@")

TARNAME=${INPUTARRAY[0]}
NST=${INPUTARRAY[1]}
NSET="$(get_num_2dig $NST)-merged"

SUFIX="${TARNAME}" # usually, the end of the root files is like this
 
#####
# Main
###

# set env
source ~/.bashrc

# set main dirs
GSTDIR=${HOME}/GetSimpleTuple                                              # dir of the executable
SIMDIR=/cache/clas/eg2a/production/Simulation/Proton_Lepto/${TARNAME}/${NSET}
#SIMDIR=/lustre19/expphy/volatile/clas/claseg2/jpgarces/particleSim/farm/${TARNAME}/${NSET}   # dir where are located all the JPSims
OUTDIR=${HOME}/volatile/GST_out/${TARNAME}/${NSET} # output dir
TMPDIR=${HOME}/volatile/GST_tmp/${TARNAME}/${NSET} # temp dir to store logs and job scripts
mkdir -p ${OUTDIR} ${TMPDIR} # just in case

# general options for job
proj="eg2a"
track="analysis" # "analysis" or "debug"
time="10" # "240" or "5" minutes
diskspace="1" # "GB"
memusage="500" # "MB"
osname="general"

# LOOP
for inputfile in ${SIMDIR}/*.root; do
# inputfile=${SIMDIR}/recsisD_01_1-100.root

    # set RN
    RN=${inputfile##*/}
    RN=${RN#*_}
    RN=${RN%.root}

    # setting jobname
    jobname="GST_${TARNAME}_${RN}"
    jobfile="${TMPDIR}/job_${jobname}.xml"

    echo ${jobname}

    # job properties
    echo "<Request>"                                                                       > ${jobfile}
    echo "  <Project name=\"$proj\"></Project>"                                           >> ${jobfile}
    echo "  <Track name=\"$track\"></Track>"                                              >> ${jobfile}
    echo "  <OS name=\"$osname\"></OS>"                                                   >> ${jobfile}
    echo "  <Name name=\"${jobname}\"></Name>"                                            >> ${jobfile}
    echo "  <TimeLimit time=\"$time\" unit=\"minutes\"></TimeLimit>"                      >> ${jobfile}
    echo "  <DiskSpace space=\"$diskspace\" unit=\"GB\"></DiskSpace>"                     >> ${jobfile}
    echo "  <Memory space=\"$memusage\" unit=\"MB\"></Memory>"                            >> ${jobfile}
    echo "  <CPU core=\"1\"></CPU>"                                                       >> ${jobfile}
    # set inputs
    echo "    <Input src=\"${GSTDIR}/bin/GetSimpleTuple_sim\"  dest=\"GetSimpleTuple_sim\"/>" >> ${jobfile}
    echo "    <Input src=\"${GSTDIR}/sh/run_GST_JPSim.sh\"  dest=\"run_GST_JPSim.sh\"/>"      >> ${jobfile}
    echo "    <Input src=\"${inputfile}\"  dest=\"recsis${TARNAME}_${RN}.root\"/>"            >> ${jobfile}
    # set command
    echo "    <Command><![CDATA["                                                         >> ${jobfile}
    #echo "      source /u/apps/root/6.22.06/setroot_CUE.bash"                             >> ${jobfile}
    echo "      sed -i \"s|^TARNAME=|TARNAME=${TARNAME}|g\"       run_GST_JPSim.sh"        >> ${jobfile}
    echo "      sed -i \"s|^RN=|RN=${RN}|g\"                      run_GST_JPSim.sh"        >> ${jobfile}
    echo "      chmod 755 ./run_GST_JPSim.sh"                                              >> ${jobfile}
    echo "      sh run_GST_JPSim.sh"                                                       >> ${jobfile}
    #echo "      echo \"path: \$PATH\""                                                       >> ${jobfile}
    #echo "      echo \"rootsys: \$ROOTSYS\""                                                       >> ${jobfile}
    #echo "      echo \"root_include_path: \$ROOT_INCLUDE_PATH\""                                                       >> ${jobfile}
    #echo "      echo \"ld_library_path: \$LD_LIBRARY_PATH\""                                                       >> ${jobfile}
    echo "    ]]></Command>"                                                              >> ${jobfile}
    # set outputs
    echo "    <Output src=\"pruned${TARNAME}_${RN}.root\"    dest=\"${OUTDIR}/pruned${TARNAME}_${RN}.root\" /> "     >> ${jobfile}
    # set logs
    echo "    <Stdout dest=\"${TMPDIR}/${jobname}.out\"/>"                        >> ${jobfile}
    echo "    <Stderr dest=\"${TMPDIR}/${jobname}.err\"/>"                        >> ${jobfile}
    echo "  <Job>"                                                                        >> ${jobfile}
    echo "  </Job>"                                                                       >> ${jobfile}
    echo "</Request>"                                                                     >> ${jobfile}

    # print
    echo "Running job ${jobfile}"
    jsub --xml ${jobfile}

done
