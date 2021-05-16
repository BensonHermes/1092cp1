#include <stdio.h>
#include <string.h>


int len;
char inp[26];


int main(void)
{
    int leftRemove = 0;
    int rightRemove = 0;
    int count=0;
    int idx=0;
    char temp;
    int left=0;
    int right=0;

    gets(inp);
    len = strlen(inp);

    char strArr[26];
    for (int i = 0; i < len; i++){
        if (inp[i]== '('){
            left++;
        }
        else if (inp[i]== ')')
        {
            right++;
        }
        else
        {
            continue;
        }
    
    }

    for (int i = 0; i < len; i++)
    {
        if ((left>=0&&right==0) || (left==0&&right>=0))
        {
            for (int i = 0; i < len; i++){
                if (inp[i]!='(' && inp[i]!=')')
                {
                    printf("%c", inp[i]);
                }
            }
            printf("\n");
            return 0;
            
            
        }
        // if (inp[0]== ')' || inp[len-1]=='(' )
        // {
        //     printf("\n");
        //     return 0;
        // }
        
        
        
        if (inp[i] == '(')
        {
            count++;
            strArr[idx++]='(';
        }
        else if(inp[i] == ')')
        {
            if (count-1 < 0)
            {
                continue;
            }
            else
            {
                count--;
                strArr[idx++]=')';
            }
        }
        else
        {
            strArr[idx++]= inp[i];
        }
        
    }
    if (count!=0)
    {
        count=0;
        // for (int i = len-1; i >= 0; i--)
        // {
        //     if (inp[i] == ')')
        //     {
        //         count++;
        //         strArr[idx++]=')';
        //     }
        //     else if(inp[i] == '(')
        //     {
        //         if (count-1 < 0)
        //         {
        //             continue;
        //         }
        //         else
        //         {
        //             count--;
        //             strArr[idx++]='(';

        //         }
                
        //     }
        //     else
        //     {
        //         strArr[idx++]= inp[i];
        //     }
            
        // }
        for (int k = idx-1;k >=0 ; k--)
        {
            // printf("k=%d\n", k);
            if (strArr[k]==')')
            {
                count++;
            }
            else if (strArr[k]=='(')
            {
                if (count-1 < 0)
                {
                    idx--;
                    // printf("count=%d\n", count);
                    for (int l = k; l < idx; l++)
                    {
                        // printf("----l=%d\n", l);
                        temp = strArr[l+1];
                        strArr[l]=temp;
                    }
                    
                }
                else
                {
                    count--;
                    continue;

                }
            }
            else
            {
                continue;
            }
            
            
            
        }
        
    }
    

    for (int k = 0; k < idx; k++)
    {
        printf("%c", strArr[k]);
    }
    printf("\n");
    
    
    

    return 0;
}
