#include <stdio.h>


int main(void) {
    int nums[25];
    int a;
    int size=0;
    int start;
    int end;

    while( scanf("%d",&a) != EOF){
        nums[size]=a;
        size++;
    }
    start = nums[0];
    // for (int i = 0; i < size; i++){
    //     printf("%d\n", nums[i]);
    // }

    if(size==0){
        printf("\n");

    else if(size==1){
        printf("%d\n",start);
    }
    else{
        for (int i = 0; i < size; i++)
        {
            if (nums[i+1]-nums[i]==1)
            {
                end = nums[i+1];
            }
            else{
                
                if (i==0 && nums[i+1]-start>1 )
                {
                    printf("%d\n",start);
                }
                else if(nums[i+1]-start>1 && start - nums[i-1] >1){
                    printf("%d\n",start);
                }
                else if(i == size-1 && start - nums[i-1] >1){
                    printf("%d\n",start);
                }
                else{
                    printf("%d->%d\n", start, end);
                }
                start = nums[i+1];
            }
            
        }
        
    }
    return 0;
}
