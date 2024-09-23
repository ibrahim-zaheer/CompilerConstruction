// Online C compiler to run C program online
#include <stdio.h>
#include<stdbool.h>

int main() {
    // Write C code here
 
    int b = 5; 
    int a = b+5;
    char dataArray[b];
    char array2[a];
    bool limit = false;
    bool getOut = false;
    
    for(int i = 0;i != -1; i++){
        
        if(i >= b){
            printf("Limit Exceeded");
            limit = true;
            char array2[a];
            for(int j = 0; j< sizeof(dataArray);j++){
                array2[j] = dataArray[j];
                
            }
        }
        if(!limit){
        scanf("%c",&dataArray[i]);
        }
        if(getOut){
            break;
        }
        else if(limit){
            scanf("%c",&array2[i]);
            if(i > a){
                printf("Program finished");
                getOut = true;
                i = -1;
            }
            
        }
        
    }
    
    for (int t = 0; t< sizeof(array2[t]); t++){
        
        printf("\n %c \n", array2[t]);
        
    }
    
    

    return 0;
}