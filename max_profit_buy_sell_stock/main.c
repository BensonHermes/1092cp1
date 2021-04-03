#include <stdio.h>
#include <string.h>
#define max(x, y) ((x) > (y) ? (x) : (y))

int main(void) {
    int arr[100001];
    int size=0;
    int p;
    int min;
    int profit = 0;
    int maxProfit=0;
    // int flag=0;
    while(scanf("%d", &p)!=EOF){
        arr[size]=p;
        size++;
    }
    min=arr[0];
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i]<min)
        {
            min = arr[i];
        }
        else{
            profit = arr[i]-min;
            maxProfit = max(profit, maxProfit);
            // flag=1;
        }
        
    }
    printf("%d\n", maxProfit);    
    return 0;
}
