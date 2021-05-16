#include <stdio.h>
#include <string.h>
#define MAX 10000

int stack[MAX]={0}; 
int top = 0;

void Stack_Push(int a){
    stack[top++]=a;
}
int Pop(){
    return stack[--top];
}
int Top(){
    return stack[top-1];
}

int queue[MAX]={0};
int front = 0, rear = 0;
void Queue_push(int a)
{
     queue[rear++] = a;
}
int Dequeue()
{
     return queue[front++];
}
int First() {
     return queue[front];
}
int Count() {
     return rear - front;
}

int main(void) {
    int num=0;
    int inp=0;
    // int target[MAX]; 
    int order[MAX];


    while (scanf("%d",&num)!=EOF)
    {
        // printf("num=%d\n", num);
        for (size_t i = 0; i < num; i++)
        {
            
            scanf("%d",&inp);
            Queue_push(inp);
            // printf("inp= %d,", inp);
            order[i]=i+1;
            // printf("order=%d", order[i]);
        }
        //queue  正常
        // for (size_t i = 0; i < num; i++)
        // {
        //     printf("%d,", queue[i]);
        // }
        // printf("\n");
        for (int l = 0; l < num; l++)
        {
            if (order[l]!= First())
            {
                // printf("1:order[%d]=%d\n", l, order[l]);
                Stack_Push(order[l]);
                // printf("1: top=%d\n", top);
            }
            else
            {
                // printf("2\n");
                Dequeue();
            }
            // while (First()==Top())
            // {
            //     printf("3\n");
            //     Dequeue();
            //     Pop();
            // }
            while (First()==Top() && First()!=0)
            {
                // printf("3-1\n");
                Dequeue();
                Pop();
            }
        }
        // printf("first()=%d, top()=%d\n", First(), Top());
        while (First()==Top() && First()!=0)
        {
            // printf("3\n");
            Dequeue();
            Pop();
        }
        // printf("top=%d\n", top);
        // printf("Top()=%d\n", Top());
        if (Top()==0)
        {
            printf("TAK\n");
        }
        else
        {
            printf("NIE\n");
        }
        
        
        top=0; 
        front=0;
        rear=0;
        

        
    }
    


    return 0;
}
