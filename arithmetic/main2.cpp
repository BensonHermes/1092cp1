#include <iostream>
// #include <stdlib>
#define N 50
#define OP 5
using namespace std; 
char op[OP] = {'(','+','-','*','/',};
int  op_priority[OP] = {0,1,1,2,2};// 與op[OP]對應,用以存放運算子的優先順序

int priority(char c);
void to_postfix(char infix[], char postfix[]);


char stack[N];	// This is a global variable.
int top=-1;
// -------------------------
//    將資料 item 放入堆疊
// -------------------------
void push(char item){
	if (top>=N-1){
		printf("Stack full!\n");
		exit(-1);
	}
	stack[++top]=item;
}
// ------------------------------------ 
//    傳回堆疊頂端的資料，但並非取出  
// ------------------------------------ 
int pop(){
	if (top==-1){
		printf("Stack empty!\n");
		exit(-1);
	}
	return stack[top--];
}

void stackPrint(){
	int i;
	printf("stack =");
	for (i=0; i<=top; i++)
		printf(" %c", stack[i]);
	printf("\n");
}

// ----------------------
//    判斷是否為空堆疊
// ----------------------
bool IsEmpty(void)
{
    return (top < 0) ? true : false;   
}

// ----------------------
//    判斷堆疊是否滿溢
// ----------------------
bool IsFull()
{
   return (top >= N - 1) ? true : false;
}

// --------------------------
//    傳回堆疊頂端的資料
// --------------------------
char top_data()
{
   return stack[top];    
}

// ---------------------------
//    傳回運算子 c 的優先序
// ---------------------------
int priority(char c)
{
   int i;
   
   for( i=0; i < OP; i++)
      if(op[i] == c)
         return op_priority[i];
   return -1;
}

// ------------------------------------
//    將中置式infix轉成後置式postfix
// ------------------------------------
void to_postfix(char infix[], char postfix[])
{
   int i=0, j=-1;
   char x, y;

   while((x=infix[i++]) != '\0'){
      switch(x){
         case '(' : push(x);
                    break;
         case ')' : while(! IsEmpty() && (x=pop()) != '(')
                       postfix[++j]=x;
                    break;
         case '+' :
         case '-' :
         case '*' :
         case '/' : y=top_data();
                    while(priority(y) >= priority(x)){
                       postfix[++j]=pop();
                       y=top_data();
                    }
                    push(x);
                    break;
          default : // x 為運算元
                    postfix[++j]=x;
      }
   }
   while(! IsEmpty())
      postfix[++j]=pop();
   postfix[++j]='\0';
}
bool IsDight(char c)
{
        return c>='0' && c<='9';
}
int calculate(char postfix[])
{
        int point=0;
        while(postfix[point]!='\0')
        {
                while(IsDight(postfix[point]))
                        push(postfix[point++]);
                int a=pop()-'0', b=pop()-'0',c=0;
                switch(postfix[point])
                {
                 case'+':c=b+a;
                              break;
                 case'-':c=b-a;
                              break;
                 case'*':c=b*a;
                              break;
                 case'/':c=b/a;
                              break;
                }
                push(c+'0');
                point++;
        }
        return pop()-'0';
}
int main(void)
{ 
   char infix[50], postfix[50];

   cout << endl << "請輸入運算式 : " ;
   cin >> infix;
   to_postfix(infix,postfix);  
   cout << "\n中置式 : " << infix << " 後置式 : " << postfix << endl; 
   cout << "答案:" << calculate(postfix) << endl;
   system("PAUSE");
}