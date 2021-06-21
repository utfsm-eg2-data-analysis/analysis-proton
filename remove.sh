#!/bin/bash

##############################################################                                                                                                                                             
#for((i=2;i<=25;i++)); do ./remove.sh <tarname> ${i}; done   #                                                                                                                                            
#     <target> = (D, C, Fe, Pb)                              #                                                                                                                                             
#     <nset>   = (1 - 10)                                    #                                                                                                                                             
#                                                            #                                                                                                                                             
# EG: ./remove.sh D 1                                        #                                                                                                                                                       
##############################################################                                                                                                                                             

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

# set env                                                                                                                                                                                                  
source ~/.bashrc


#####                                                                                                                                                                                                      
# Input                                                                                                                                                                                                    
###                                                                                                                                                                                                        

INPUTARRAY=("$@")

TARNAME=${INPUTARRAY[0]}
NSET=${INPUTARRAY[1]}
RN=$(get_num_2dig $NSET)

#####                                                                                                                                                                                                      
# Main                                                                                                                                                                                                     
###                                                                                                                                                                                                        


# set main dirs                                                                                                                                                                                            
SIMDIR=/lustre19/expphy/volatile/clas/claseg2/jpgarces/GST_out/${TARNAME}/${RN}-merged
OUTDIR=/lustre19/expphy/volatile/clas/claseg2/jpgarces/GST_out/${TARNAME}

cd ${SIMDIR}

mv -v pruned${TARNAME}_${RN}.root ${OUTDIR}/pruned${TARNAME}_${RN}.root

cd ${OUTDIR}

rm -rf ${RN}-merged

