int myAtoi(char* s) {

    int i=0, segno=1, numero=0, inizio=0;

     while(s[i]==' '){
        i++;
    }
//guardo il segno e se c'è + o - salto la prima cella

    if (s[i]=='-' || s[i]=='+') {
        if (s[i]=='-') {
            segno = -1;
        }
        i++;
    }
    
//ciclo e costruisco il numero 

    for (; s[i] >= '0' && s[i] <= '9' && s[i]!= '\0'; i++){

        if(s[i]!='0'|| inizio){
            
            inizio=1;
               if (numero > INT_MAX / 10 || (numero == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10)) { //correggo il troncamento di '/'
                        if (segno==-1)
                            return INT_MIN;
                    return INT_MAX;
                }

            numero=numero*10+(s[i]-'0');
                
        }

        

    }

    return segno*numero;
}