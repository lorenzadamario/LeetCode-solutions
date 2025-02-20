int search(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1, actual;

    // Verifica se il target è già ai lati
    if (nums[right] == target) {
        return right;
    }
    if (nums[left] == target) {
        return left;
    }

    // Ricerca binaria
    while (right - left > 1) {
        actual = left + (right - left) / 2; // Calcolo del centro

        if (nums[actual] == target) {
            return actual;
        }
        if (nums[actual] > target) {
              //controllo se posso eliminare la parte prima o dopo nums e cioè se devo cercare tornando indietro da actual oppure andando indietro da right fino a actual 
              if(nums[left] < target){ //elimino la parte di destra muovendo il mio right bound in corrispondenza di actual, non inserisco nelle condizioni nums[left]>= actual, perchè prima di entrare nel while ho già verificato l'uguaglianza
                    right = actual;
                 }

             if(nums[left] > target && (nums[actual]- nums[left])>0){ //se sono in prima fase crescente, mi sposto finchè non decresce
                  left = actual;
    
                  }
            if(nums[left] > target && (nums[actual]- nums[left])<0){ //significa che la diminuzione che mi serve è in mezzo tra i due
                  right = actual;
    
                  }

        }
        
        if (nums[actual] < target){ //posso essere sia tra la fase crescente e quella decrescente ch ein una sola delle due, l'unico modo di saperlo e verificare quali sono i due valori estremi tra cui mi muovo
        
           
             if(nums[right]< target && nums[actual]> nums[left]){ //il mio actual mi sta dicendo di andare prima di lui e sono ordinato
                left=actual;

             }

              if(nums[right] < target && nums[actual] < nums[left]){ //il mio actual è attendibile
                right= actual; //sicuramente non mi convine controllare dopo l'actual
                
             }

             if (nums[right] > target){
                left=actual;
             }
        }
          
    }

    return -1; // Elemento non trovato
}