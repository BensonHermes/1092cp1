#include <stdio.h>
#include <string.h>

int main(void){
    int num=0;
    scanf("%d", &num);
    if (num==0)
    {
        printf("%d\n",0);
        return 0;
    }
    
    int dp[num][5];//dp[長度-1][vowel index]
    long ans = 0;

    
    //when 長度 =1, initialize dp to equal 1, since a, e, i, o, u
    for (int i = 0; i < 5; i++)
    {
        dp[0][i]=1;
    }
    for (int i = 1; i < num; i++)
    {   //a下 若i=1 即長度=2 aa, ae, ai, ao, au 
        dp[i][0]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-1][3]+dp[i-1][4];
        //b下
        dp[i][1]=dp[i-1][1]+dp[i-1][2]+dp[i-1][3]+dp[i-1][4];
        dp[i][2]=dp[i-1][2]+dp[i-1][3]+dp[i-1][4];;
        dp[i][3]=dp[i-1][3]+dp[i-1][4];
        dp[i][4]=dp[i-1][4];
    }
    for (int i = 0; i < 5; i++)
    {
        ans += dp[num-1][i];
    }     
    printf("%ld\n", ans);
    return 0;
}