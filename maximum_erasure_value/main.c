#include <stdio.h>
#include <string.h>
#define max(x, y) ((x) > (y) ? (x) : (y))

int main(void) {
    // int arr[10000];
    int accSum[10000]={0};
    int nums[10000];
    int num=0;
    int size=0;
    int ans=0;
    int startPos=0;
    int map[10000]={-1};
    while(scanf("%d", &num)!= EOF){
        nums[size]=num;
        size++;
    }
    // printf("%d", size);
    if (size==1)
    {
        printf("%d\n", nums[0]);
        return 0;
    }
    
    for (int i = 0; i < size; i++)
    {
        accSum[i+1]=accSum[i]+nums[i];
    }
    // for (int i = 0; i < size; i++)
    // {
    //     printf("%d", nums[i]);
    // }
    for (int k = 0; k < size; k++)
    {
        startPos = max(startPos, map[nums[k]]+1);
        ans = max(ans, accSum[k+1]-accSum[startPos]);
        map[nums[k]]=k;
    }
    printf("%d\n", ans);
    return 0;
}
