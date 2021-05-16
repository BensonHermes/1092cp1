#include <stdio.h>
#include <string.h>

char resultSets[100][26];
int len;
char inp[26];
int resultSetsRow = 0;

void find_results(int index, int leftCount, int rightCount, int leftRemove, int rightRemove, char *strArr, int strIdx)
{
    int flag=0;
    if (index == len)
    {
        // printf("++++\n");
        if (leftRemove == 0 && rightRemove == 0)
        {
            // printf("resultSetsRow=%d\n", resultSetsRow);
            if (resultSetsRow==0)
            {
                for (int l = 0; l < strIdx; l++)
                {
                //     printf("strIdx=%d\n", l);
                    resultSets[resultSetsRow][l] = strArr[l];
            
                }
                resultSetsRow++;
            }
            if (resultSetsRow>=1){
                for (int n = 0; n < resultSetsRow; n++)
                {
                    // printf("same=%d\n", strcmp(resultSets[n], strArr));
                    // printf("n=%d, resultSetsRow=%d strArr=%s\n", n, resultSetsRow, strArr);
                    if (strcmp(resultSets[n], strArr)==0)
                    {
                        // printf("\n");
                        flag=1;
                        // for (int k = 0; k < strIdx; k++)
                        // {
                        //     printf("%c", resultSets[n][k]);
                        // }
                        // printf("\n");
                        // for (int l = 0; l < strIdx; l++)
                        // {
                        //     printf("%c", resultSets[resultSetsRow][l]);
                        // }
                        // printf("\n");
                    }
                }
                if (flag==0)
                {
                    for (int l = 0; l < strIdx; l++)
                    {
                        resultSets[resultSetsRow][l] = strArr[l];
                    
                    }
                    resultSetsRow++;
                }
        }
            return;
        }
        else{
            // printf("@@@\n");
            resultSetsRow=0;
            return;
        }
    }

    char character = inp[index];
    // printf("character=%c\n", character);
    // delete current
    if (character == '(' && leftRemove > 0)
    {
        // printf("1\n");
        // leftRemove > 0 ignore current (
        find_results(index + 1, leftCount, rightCount, leftRemove - 1, rightRemove, strArr, strIdx);
    }
    if (character == ')' && rightRemove > 0)
    {
        // printf("2\n");

        find_results(index + 1, leftCount, rightCount, leftRemove, rightRemove - 1, strArr, strIdx);
    }
    // keep char
    strArr[strIdx] = character;
    // path.append(character);
    if (character != '(' && character != ')')
    {
        // printf("3\n");
        find_results(index + 1, leftCount, rightCount, leftRemove, rightRemove, strArr, strIdx + 1);
    }
    else if (character == '(')
    {
        find_results(index + 1, leftCount + 1, rightCount, leftRemove, rightRemove, strArr, strIdx + 1);
    }
    else if (rightCount < leftCount)
    {
        // printf("5\n");
        find_results(index + 1, leftCount, rightCount + 1, leftRemove, rightRemove, strArr, strIdx + 1);
    }

    // strIdx--;
}

int main(void)
{
    int leftRemove = 0;
    int rightRemove = 0;

    gets(inp);
    len = strlen(inp);
    // fgets(inp, sizeof(inp), stdin);
    // for (size_t i = 0; i < len; i++)
    // {
    //     printf("%c", inp[i]);
    // }
    // printf("\n");
    char strArr[26];
    int strIdx = 0;

    for (int i = 0; i < len; i++)
    {
        if (inp[i] == '(')
        {
            leftRemove++;
        }
        else if (inp[i] == ')')
        {
            if (leftRemove == 0)
            {
                rightRemove++;
            }
            if (leftRemove > 0)
            {
                leftRemove--;
            }
        }
    }
    // printf("leftRemove=%d, rightRemove=%d\n", leftRemove, rightRemove);
    // printf("yes\n");
    find_results(0, 0, 0, leftRemove, rightRemove, strArr, strIdx);
    // printf("-----\n");
    // printf("resultSetsRow=%d\n", resultSetsRow);
    
    if (resultSetsRow==0)
    {
        printf("\n");
    }
    else
    {
        for (int i = 0; i < resultSetsRow; i++)
        {
            if (i==0)
            {
                for (int k = 0; k < len; k++)
                {
                    printf("%c", resultSets[i][k]);
                    // printf("HI");
                }
            }
            // else
            // {
            //     printf("或");
            //     // printf("resultSetsRow=%d\n", resultSetsRow);
            //     for (int k = 0; k < len; k++)
            //     {
            //         printf("%c", resultSets[i][k]);
            //     }

            // }
            
        }
        printf("\n");
        }
    
    
    

    return 0;
}
