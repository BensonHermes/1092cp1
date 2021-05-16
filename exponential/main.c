#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void) {
    int count;
    scanf("%d",&count);
    long long n,k;
    double ans=1008;
    int res;
  
    for (int i = 0; i < count; i++)
    {
        res=1;
        while (k>0)
        {
            if ((k%2)==1)
            {
                res = (res*n)%1007;
            }
            n = (n*n) % 1007;
            k = floor(k/2);
            
        }
        
        // ans=1008;
        // scanf("%lld", &n);
        // scanf("%lld", &k);
        // // ans = pow((n%1007),k);
        // // // printf("%f\n", ans);
        // // ans = fmod(ans, 1007);

        // while ((int)ans>=1007)
        // {
        //     ans = pow((n%1007),k);
        //     // printf("%f\n", ans);
        //     ans = fmod(ans, 1007);
        // }
        printf("%d\n", (int)res);
    }
    return 0;
}
