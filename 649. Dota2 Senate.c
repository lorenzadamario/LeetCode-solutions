//risoluzione problema dota2 leetcode, scansione della stringa 1 volta sola, runtime 0s

char* predictPartyVictory(char* senate) {
    int d=0, r=0, countd=0, countr=0;
    int len=strlen(senate), debito=0;

    for (int i=0; i< len; i++){
        
        if (senate[i]== 'R'){

            if(countr<0)
                countr++;

            else if (countr==0){
                countd--;
                r++;

                //controllo la priorità per le posizioni maggiori
                if(debito<0)
                    debito++;
            
                else
                    debito=debito+2;

            }
        }

        if (senate[i]== 'D'){

            if(countd<0)
                countd++;

            else if (countd==0){
                countr--;
                d++;

            //gestisco il valore maggiore acquisito se si ci trova prima

                 if(debito>0)
                    debito--;
                
                else
                    debito=debito-2;
            }
        }
    }

   

// se uno è il doppio dell'altro allora vince

        if((r+countr)>=2*(d+countd))
            return "Radiant";
    
        if ((d+countd)>=2*(r+countr))
            return "Dire";
        
     
        

        if (debito>0)
            return "Radiant";
        
        
        return "Dire";
        

}