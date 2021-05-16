#include<iostream>  
#include<stack>  
using namespace std;  
// defines the Boolean function for operator, operand, equalOrhigher precedence and the string conversion function.  
bool IsOperator(char);  
bool IsOperand(char);  
bool eqlOrhigher(char, char);  
void convert();  

stack <char> inpS;
stack <char> revS;
stack <char> postS;
stack <char> postRevS;

void PrintStack(stack<char> s)
{
    // If stack is empty then return
    if (s.empty())
        return;
     
 
    char x = s.top();
 
    // Pop the top element of the stack
    s.pop();
 
    // Recursively call the function PrintStack
    PrintStack(s);
 
    // Print the stack element starting
    // from the bottom
    cout << x << " ";
 
    // Push the same element onto the stack
    // to preserve the order
    s.push(x);
}


int calculate(){
    stack <int> S;  
    int ans;
    int n1, n2;
    char ch;
    // cout<<4<<endl;
    int size = postRevS.size();
    for (int i = 0; i< size; i++)
    {
        ch = postRevS.top();
        postRevS.pop();
        cout<<"postRevS = "<<ch<<endl;
        // cout<<"top3 = "<<S.top()<<endl;
        if (IsOperator(ch))
        {
            // cout<<"1--"<<endl;
            n2 = S.top();
            S.pop();
            n1 = S.top();
            S.pop();
            if (ch=='+')
            {
                ans = n1+n2;
            }
            else if (ch=='-')
            {
                ans = n1-n2;
            }
            else if (ch=='*')
            {
                ans = n1*n2;
            }
            else
            {
                ans = n1/n2;
            }
            
            S.push(ans);
            // cout<<"top1 = "<<S.top()<<endl;
        }
        else
        {
            // cout<<2<<endl;
            // cout<<"top2-1 = "<<S.top()<<endl;
            S.push(ch-'0');
            // cout<<"top2 = "<<S.top()<<endl;
        }
    }
    // cout<<3<<endl;
    ans = S.top();
    return ans;
}
  
int main()  
{  
    string infix_expression, postfix_expression;
    
    int res;   
    char in;
   
    // cout << " Enter an infix expression: ";  
    // cin >> infix_expression;  
    while (cin>>in)
    {   
        if(IsOperator(in))
        {
            inpS.push(in);
        }   
        else
        {   
            inpS.push(in);
        }
        
    }
    inpS.push(')');
    PrintStack(inpS);
    // cout<<"size"<<inpS.size()<<endl;
    int size = inpS.size();
    for (int i = 0; i < size; i++)
    {
        revS.push(inpS.top());
        inpS.pop();
    }
    PrintStack(revS);
    cout<<endl;
    convert();
    cout<<"---2"<<endl;
    // cout<<endl;
    // cout<<"---"<<endl;
    PrintStack(postS);
    size = postS.size();
    for (int i = 0; i < size; i++)
    {
        postRevS.push(postS.top());
        postS.pop();
    }
    PrintStack(postRevS);
    cout<<endl;
    res = calculate();
    cout<<endl;
    cout<<res<<endl;

    //cin.ignore();   

    return 0;  
}  
  
// define the IsOperator() function to validate whether any symbol is operator.  
/* If the symbol is operator, it returns true, otherwise false. */  
bool IsOperator(char c)  
{  
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' )  {
        return true;     
    }
    
    return false;  
}  
  
// IsOperand() function is used to validate whether the character is operand.  
bool IsOperand(char c)  
{  
    if( c >= 'A' && c <= 'Z')  /* Define the character in between A to Z. If not, it returns False.*/  
    {
        return true;  
    }
    
    if (c >= 'a' && c <= 'z')  // Define the character in between a to z. If not, it returns False. */  
    {
        return true;  
    }
    
    if(c >= '0' && c <= '9')   // Define the character in between 0 to 9. If not, it returns False. */  
    {
        return true;  
    }
    
    return false;  
}  
// here, precedence() function is used to define the precedence to the operator.  
int precedence(char op)  
{  
    if(op == '+' || op == '-')                   /* it defines the lowest precedence */  
    {
        return 1;  
    }
    
    if (op == '*' || op == '/')  
    {
        return 2;  
    }
    
     /* if(op == '^')                                 exponent operator has the highest precedence * 
return 3;    */   
    return 0; 
} 
/* The eqlOrhigher() function is used to check the higher or equal precedence of the two operators in infix expression. */  
bool eqlOrhigher (char op1, char op2)  
{  
    int p1 = precedence(op1);  
    int p2 = precedence(op2);  
    if (p1 == p2)  
    {  
        if (op1 == '^' )  
        {
            return false;  
        }
        
        return true;  
    }  
    return  (p1>p2 ? true : false);  
}  
  
/* string convert() function is used to convert the infix expression to the postfix expression of the Stack */  
void convert()  
{  
    stack <char> S;  
    // string postfix ="";    
    char ch;  
    
    S.push( '(' );  
    inpS.push(')');
    // infix += ')';  
    int size = revS.size();
    //adjust for ')'
    for(int i = 0; i<size; i++)  
    {  
        ch = revS.top();
        cout<<"size = "<<size<<"ch = "<<ch<<endl;
        revS.pop();
        
        if(ch == ' ')  
        {
            continue;  
        }
        else if(ch == '(')  
        {
            cout<<"@1"<<endl;
            S.push(ch);  
        }
        else if(IsOperand(ch))  
        {
            // postfix += ch;  
            cout<<"@2"<<endl;
            postS.push(ch);
        }
        
        else if(IsOperator(ch))  
        {  
            cout<<"@3"<<endl;
            while(!S.empty() && eqlOrhigher(S.top(), ch))  
            {  
                // postfix += S.top();  
                cout<<"@4"<<endl;
                postS.push(S.top());
                S.pop();  
            }  
            S.push(ch);
        }  
        else if(ch == ')')  
        {  cout<<"@5"<<endl;
            while(!S.empty() && S.top() != '(')  
            {  
                cout<<"@6"<<endl;
                postS.push(S.top());  
                S.pop();  
            }  
            S.pop();  
        }
        
    }  
// return 0;  
}  