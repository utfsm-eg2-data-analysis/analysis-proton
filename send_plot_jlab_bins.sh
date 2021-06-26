#!/bin/bash

#########################################################################################
# ./send_plot_jlab_bins.sh <tarname> <code 1> <code 2> <code 3>                         #
#     <tarname>= (D,C,F (for Fe),P (for Pb))                                                            #
#     <code 1> = (1-25) -> 01-merged,...,25merged                                       #
#     <code 2/3>   = (1 - 3) -> 9 possible combinations (each for one of the Q2xNu bins #
# for((i=2;i<=25;i++)); do ./send_plot_jlab_bins.sh F ${i} 1 1; done                    #
# EG: ./send_plot_jlab_bins.sh P 1 1 2                                                  #
#########################################################################################

#####
# Functions
###

#####
# Input
###

INPUTARRAY=("$@")

TRN=${INPUTARRAY[0]}
FSTN=${INPUTARRAY[1]}
SCDN=${INPUTARRAY[2]}
THRN=${INPUTARRAY[3]}

if [ "${TRN}" == "F" ]
then
    TARNAME="Fe"
elif [ "${TRN}" == "P" ]
then
    TARNAME="Pb"
else
    TARNAME=${TRN}
fi

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

RN="$(get_num_2dig $FSTN)"

#NST=${INPUTARRAY[1]}
#NSET="$(#get_num_2dig $NST)-merged"

#SUFIX="${TARNAME}" # usually, the end of the root files is like this
 
#####
# Main
###

# set env
source ~/.bashrc

# set main dirs
HMDIR=${HOME}                                              # dir of the executable
OUTDIR=${HOME}/volatile/Acceptance_out # output dir
TMPDIR=${HOME}/volatile/Acceptance_tmp # temp dir to store logs and job scripts
mkdir -p ${OUTDIR} ${TMPDIR} # just in case

# general options for job
proj="eg2a"
track="analysis" # "analysis" or "debug"
time="40" # "240" or "5" minutes
diskspace="1" # "GB"
memusage="500" # "MB"
osname="general"

# LOOP
#for inputfile in ${SIMDIR}/*.root; do
# inputfile=${SIMDIR}/recsisD_01_1-100.root

    # set RN
    #RN=${inputfile##*/}
    #RN=${RN#*_}
    #RN=${RN%.root}

    # setting jobname
    jobname="Acceptance_${TARNAME}"      #"GST_${TARNAME}_${RN}"
    jobfile="${TMPDIR}/job_${jobname}.xml"

    #infile="prunedC_all.root"
    infile="/lustre19/expphy/volatile/clas/claseg2/jpgarces/GST_out/${TARNAME}/pruned${TARNAME}_${RN}.root"

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
    echo "    <Input src=\"${infile}\"  dest=\"pruned${TARNAME}_${RN}.root\"/>" >> ${jobfile}
    echo "    <Input src=\"${HMDIR}/plot_jlab_bins.C\"  dest=\"plot_jlab_bins.C\"/>" >> ${jobfile}
    echo "    <Input src=\"${HMDIR}/run_plot_jlab_bins.sh\"  dest=\"run_plot_jlab_bins.sh\"/>"      >> ${jobfile}
    # set command
    echo "    <Command><![CDATA["                                                         >> ${jobfile}
    #echo "      source /u/apps/root/6.22.06/setroot_CUE.bash"                             >> ${jobfile}
    echo "      sed -i \"s|^TRN=|TRN=${TRN}|g\"       run_plot_jlab_bins.sh"        >> ${jobfile}
    echo "      sed -i \"s|^FSTN=|FSTN=${FSTN}|g\"       run_plot_jlab_bins.sh"        >> ${jobfile}
    echo "      sed -i \"s|^SCDN=|SCDN=${SCDN}|g\"       run_plot_jlab_bins.sh"        >> ${jobfile}
    echo "      sed -i \"s|^THRN=|THRN=${THRN}|g\"       run_plot_jlab_bins.sh"        >> ${jobfile}
    #echo "      sed -i \"s|^RN=|RN=${RN}|g\"                      run_GST_JPSim.sh"        >> ${jobfile}
    echo "      chmod 755 ./run_plot_jlab_bins.sh"                                              >> ${jobfile}
    echo "      sh run_plot_jlab_bins.sh"                                                       >> ${jobfile}
    #echo "      root -l -q plot_jlab_bins.C"                                              >> ${jobfile}
    echo "    ]]></Command>"                                                              >> ${jobfile}
    # set outputs
    echo "    <Output src=\"Tree_${TARNAME}_${RN}_${SCDN}${THRN}.root\"    dest=\"${OUTDIR}/Tree_${TARNAME}_${RN}_${SCDN}${THRN}.root\" /> "     >> ${jobfile}
    # set logs
    echo "    <Stdout dest=\"${TMPDIR}/${jobname}_${RN}_${SCDN}${THRN}.out\"/>"                        >> ${jobfile}
    echo "    <Stderr dest=\"${TMPDIR}/${jobname}_${RN}_${SCDN}${THRN}.err\"/>"                        >> ${jobfile}
    echo "  <Job>"                                                                        >> ${jobfile}
    echo "  </Job>"                                                                       >> ${jobfile}
    echo "</Request>"                                                                     >> ${jobfile}

    # print
    echo "Running job ${jobfile}"
    jsub --xml ${jobfile}

#done
