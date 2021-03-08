#include <stdio.h>
#include <string.h>

int main(void) {
    char str[1000];
    int numRows;
    int size=0;
    char ans[1000][100];
    int currentRow=0;
    int downFlag=1;

    gets(str);
    size = strlen(str);
    scanf("%d",&numRows);
    
    // for (int i = 0; i < size; i++){
    //     printf("%c\n", str[i]);
    // }
    
    if (numRows==0){
        printf("%s", str);
    }
    for (int i = 0; i < size; i++)
    {
        ans[currentRow][0]=*strncat(&ans[currentRow][0],&str[i],1);
        currentRow += 1 * downFlag;

        if (currentRow == numRows-1)
        {
            downFlag = -1;
        }
        if (currentRow == 0)
        {
            downFlag = 1;
        }
        

    }
    
    for (int m = 0; m < numRows; m++)
    {
        printf("%s", ans[m]);
        
    }
    printf("\n");
    

    return 0;
}
