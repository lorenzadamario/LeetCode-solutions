//runtime=0s

int maxProfit(int* prices, int pricesSize) {
    //guardo il mio array 
    int i=0,max=prices[0], min=prices[0], sol=0;
    //gioco con il max e con il minimo
    //mi salvo delle posizioni 

    //scorro array
    for(i=0;i<pricesSize; i++){
        if (prices[i]<min){
            if (sol<max-min){
                    sol=max-min;
                }
            min=prices[i];
            max=min;
        
        }
        if (prices[i]>max){
            max=prices[i];
        }

        

    }

    if (sol<max-min){
                    sol=max-min;
                }
    return sol;
}
