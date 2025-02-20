int maxProfit(int* prices, int pricesSize) {
    int i, somma=0, min=prices[0], max=prices[0];

    for(i=0; i<pricesSize; i++){
        if (prices[i]<min){
            somma+=max-min;
            min=prices[i];
            max=min;
        }

        if (prices[i]>max){
            max=prices[i];
        }
    }

    somma+=max-min;
    return 0;
    
    
}