int trap(int* height, int heightSize) {
    int max=0, sum=0, partial=0, count=0, memoria; //metto in partial la somma dei neri che poi toglierò, in somma la somama totale, il max il primo max, il count mi dice quante iterazioni sto facendo prima di trovare un nuovo massimo
    int i;
    for(i=0; i<heightSize; i++){
        if(height[i]>=max){
            sum+=(max*count-partial);
            partial=0;
            max=height[i];
            count=0;
            memoria=i;
        }

        if(height[i]<max){
            partial+=height[i];
            count++;

        }
    }
    count=0;
    partial=0;
    max=0; 

    if(memoria!=heightSize-1){
        for(i=heightSize-1;i>=memoria;i--){
             if(height[i]>=max){
            sum+=(max*count-partial);
            partial=0;
            max=height[i];
            count=0;
           
        }

             if(height[i]<max){
                  partial+=height[i];
                 count++;


        }
    }

    }
    return sum;
}