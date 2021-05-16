#include <stdio.h>
#include <string.h>

int main(void) {
    int num;
    int count=0;
    scanf("%d", &num);
    int arr[100001]={0};
    int front[100001]={0};
    int back[100001]={0};

    for (int i = 1; i <= num; i++)
    {
        scanf("%d", &arr[i]);
        front[i] = arr[i]+front[i-1];
    }
    for (int i = 1; i <= num ; i++)
    {
        back[i] = arr[num-i+1]+back[i-1];
    }
    for (int i = 1, j=1; i <= num && j<=num;)
    {
        if (front[i]==back[j] && (back[j]!=0 || front[i]==0))
        {
            count++;
            i++;
            j++;
        }
        else if (front[i] > back[j])
        {
            j++;
        }
        else
        {
            i++;
        }
        
        
        
    }   
    // for (int i = 1; i <= num; i++)
    // {
    //     printf("%d,", front[i]);
    // }
    // printf("\n");
    // for (int i = 1; i <= num; i++)
    // {
    //     printf("%d,", back[i]);
    // }
    // printf("\n");
    printf("%d\n", count); 

    return 0;
}
