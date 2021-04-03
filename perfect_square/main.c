#include <stdio.h>
#define min(x, y) ((x) < (y) ? (x) : (y))
int main(void) {
    int n=0;
    scanf("%d", &n);
    int dp[n+1];
    dp[0]=0;
    for (int i = 1; i <= n; i++)
    {
        dp[i]=i;
        for (int k = 1; i-k*k>=0 ; k++)
        {
            dp[i]=min(dp[i], dp[i-k*k]+1);
        }
        
    }
    printf("%d\n", dp[n]);
    
    
    
   
    
    return 0;
}
