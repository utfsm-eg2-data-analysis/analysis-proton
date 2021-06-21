!/bin/bash                                                                                          

##############################################################                                       
#for((i=1;i<=25;i++)); do ./merge.sh <tarname> ${i}; done    #                                       
#     <target> = (D, C, Fe, Pb)                              #                                       
#     <nset>   = (1 - 10)                                    #                                       
#                                                            #                                       
# EG: ./merge.sh D 1                               #                                      
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

# set env                                                                                            
source ~/.bashrc

# set main dirs                                                                                      
SIMDIR=/lustre19/expphy/volatile/clas/claseg2/jpgarces/GST_out/${TARNAME}/${RN}-merged

cd ${SIMDIR}

hadd pruned${TARNAME}_${RN}.root *.root
