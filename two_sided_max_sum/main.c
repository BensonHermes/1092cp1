#include <stdio.h>
#include <string.h>
#define max(x, y) ((x) > (y) ? (x) : (y))
int main(void) {
    
    int size=0;
    scanf("%d", &size);
    int arr[size];
    int count = 0;
    int aSum, bSum = 0;
    int start =0;
    int end = size-1;

    for (size_t i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    while(count<=size){
        if (count%2==0) {
            aSum += max(arr[start], arr[end]);
        } else {
            bSum += max(arr[start], arr[end]);
        }
        if(arr[start] > arr[end]) {
            start++;
        } else {
            end--;
        }
        count++;   
    }
    if (aSum >= bSum) {
        printf("%s\n", "True");
    } else {
        printf("%s\n", "False");
    }

    return 0;
}
