#include <stdio.h>
#include <string.h>
#define max(x, y) ((x) > (y) ? (x) : (y))

int main(void) {
    char dominoes[100000];
    int size;
    int force = 0;
    int currentForce[100000];
    char ans[100000];
  
    gets(dominoes);
    size = strlen(dominoes);
    
    for (int i = 0; i < size; i++)
    {  
        if (dominoes[i]=='R')
        {
            force = size;
        } else if (dominoes[i]=='L')
        {
            force = 0;
        } else{ //if '.'
            force = max(force-1, 0);
        }
        currentForce[i]+=force;
        
    }

    force = 0;
    for (int i = size; i >= 0; i--)
    {
        if (dominoes[i]=='L')
        {
            force = size;
        } else if (dominoes[i]=='R')
        {
            force = 0;
        } else{ //if '.'
            force = max(force-1, 0);
        }
        currentForce[i]-=force;
    }

    for (int k = 0; k < size; k++)
    {
        if (currentForce[k]>0)
        {
            printf("%c",'R');
        } else if (currentForce[k]<0)
        {
            printf("%c",'L');
        }else{
            printf("%c",'.');
        }
    }
    
    
    printf("\n");

    return 0;
}
