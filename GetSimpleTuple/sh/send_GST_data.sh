#!/bin/bash

##############################################################
# ./send_GST_data.sh <target>                                #
#     <target> = (C, Fe, Pb)                                 #
#                                                            #
# EG: ./send_GST_data.sh C                                   #
#     ./send_GST_data.sh Fe                                  #
#     ./send_GST_data.sh Pb                                  #
##############################################################

#####
# Input
###

TARNAME="$@"

#####
# Main
###

# set env
source ~/.bashrc

# set main dirs
GSTDIR=${HOME}/usm-data-analysis/analysis-proton/GetSimpleTuple            # dir of GetSimpleTuple
DATADIR=/cache/mss/clas/eg2a/production/Pass2/Clas                         # dir where are located all the data files
OUTDIR=/volatile/clas/claseg2/${USER}/out/GetSimpleTuple/data/${TARNAME}  # output dir
TMPDIR=/volatile/clas/claseg2/${USER}/tmp/GetSimpleTuple/data/${TARNAME}  # temp dir to store logs and job scripts

# create dirs just in case
mkdir -p ${OUTDIR} ${TMPDIR}

# copy binary to output dir
cp -v ${GSTDIR}/bin/GetSimpleTuple_data ${OUTDIR}

# obtain run numbers
if [[ "${TARNAME}" == "C" ]]; then
    RNLIST=${GSTDIR}/include/C-thickD2rn.txt
elif [[ "${TARNAME}" == "Fe" ]]; then
    RNLIST=${GSTDIR}/include/Fe-thickD2rn.txt
elif [[ "${TARNAME}" == "Pb" ]]; then
    RNLIST=${GSTDIR}/include/Pb-thinD2rn.txt
fi
TOTALRN=$(wc -l < ${RNLIST}) # total number of run numbers

for ((COUNTER=1; COUNTER <= ${TOTALRN}; COUNTER++)); do # ${nfiles} or 1
    # update rn value
    RN=$(sed -n "$COUNTER{p;q}" ${RNLIST}) # data from RNLIST

    # setting jobname
    jobname="GST_data-${TARNAME}_${RN}"
    jobfile="${TMPDIR}/${jobname}.sh"

    echo ${jobname}

    echo "#!/bin/bash"                                                 > ${jobfile}
    echo "#SBATCH -J ${jobname}"                                      >> ${jobfile}
    echo "#SBATCH -o ${TMPDIR}/${jobname}.out"                        >> ${jobfile}
    echo "#SBATCH -e ${TMPDIR}/${jobname}.err"                        >> ${jobfile}
    echo "#SBATCH --time=4:00:00"                                     >> ${jobfile} # 4hrs or 15min for test
    echo "#SBATCH --mem=1GB"                                          >> ${jobfile}
    echo ""                                                           >> ${jobfile}
    echo "source ${HOME}/.bashrc"                                     >> ${jobfile}
    echo ""                                                           >> ${jobfile}
    echo "cd ${OUTDIR}"                                               >> ${jobfile} # enter GST output dir
    for file in ${DATADIR}/clas_${RN}*; do                                          # list all the files of a run
	    inputfile=$(readlink -f ${file})                                            # retrieve full path of each input file
	    echo "ln -s ${inputfile} ${inputfile##*/}"                    >> ${jobfile} # symbolic link each input file
    done
    echo "./GetSimpleTuple_data -t${TARNAME} -r${RN}"                 >> ${jobfile} # execute program
    echo "rm -v clas_${RN}*.root"                                     >> ${jobfile} # remove symbolic link of input files
    echo ""                                                           >> ${jobfile}
    echo "Submitting job: ${jobfile}"
    sbatch ${jobfile} # submit job!
done
