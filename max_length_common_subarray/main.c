#include <stdio.h>
#include <string.h>
#define max(x, y) ((x) > (y) ? (x) : (y))

int main(void) {
    int arrA[1001];
    int arrB[1001];
    int sizeA;
    int sizeB;
    int ans=0;
    scanf("%d", &sizeA);
    for (size_t i = 0; i < sizeA; i++){
        scanf("%d", &arrA[i]);
    }
    scanf("%d", &sizeB);
    for (size_t i = 0; i < sizeB; i++){
        scanf("%d", &arrB[i]);
    }
    
    int dp[sizeA+1][sizeB+1];

    for (int i = 0; i <= sizeA; ++i){
        for (int j = 0; j <= sizeB; ++j) {
            if (i == 0 || j == 0){
                dp[i][j] = 0;
            }
            
            else if (arrA[i-1] == arrB[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                ans = max(ans, dp[i][j]);
            }
            
            else{
                dp[i][j] = 0;
            }
        }
    }
    printf("%d\n", ans);
    

    return 0;
}
