#!/bin/bash                                                                                                                                                                                                

#################################################################################                                                                                                                          
# ./binning.sh <target>                                                         #                                                                                                                          
#     <target> = (D, C, F (for Fe), P (for Pb))                                                 #                                                                                                                          
#     <nset>   = (1 - 10)                                                       #                                                                                                                          
#                                                                               #                                                                                                                          
# EG: ./run_mergeV3.sh D 3 5 1 1000                                             #                                                                                                                          
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


#####                                                                                                                                                                                                      
# Input                                                                                                                                                                                                    
###                                                                                                                                                                                                        

INPUTARRAY=("$@")

TARNAME=${INPUTARRAY[0]}

####                                                                                                                                                                                                       
# Main                                                                                                                                                                                                     
###                                                                                                                                                                                                        

# set env                                                                                                                                                                                                  
source ~/.bashrc

for((i=1; i <= 3; i++)); do
    
    for((j=1; j <= 3; j++)); do
	
	if [ "${i}" = "1" -a "${j}" = "1" ]; then
	    echo "No pasa naaa"
	else
	    #echo "${i}${j}"
	    for((k=1;k<=25;k++)); do ./send_plot_jlab_bins.sh ${TARNAME} ${k} ${i} ${j}; done
        fi
    done

done
