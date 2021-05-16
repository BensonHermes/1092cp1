#include <stdio.h>
#include <string.h>

int main(void) {
    long long arr[100001];
    long long map[100001]={0};
    int max=-1;
    int val;
  
    int count;
    // printf("3\n");
    scanf("%d",&count);
    printf("%d\n", count);
    for (int i = 0; i < count; i++)
    {
        scanf("%lld", &arr[i]);
    }
    // printf("1\n");
    for (int i = 0; i < count; i++)
    {
        map[arr[i]] = map[arr[i]]+1;
    }
    // printf("2\n");
    for (int i = 0; i < count; i++)
    {
        if (map[i] >= max)
        {
            max = map[i];
            val=i;
            printf("%d\n", max);
        }
        
    }
    printf("%d\n", max*val*10000);
    printf("%d\n", val);
    return 0;
}
