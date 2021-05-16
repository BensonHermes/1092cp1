#include<iostream>  
#include<stack> 
#include<vector>
#include<string>  
using namespace std;  
// defines the Boolean function for operator, operand, equalOrhigher precedence and the string conversion function.  
bool IsOperator(char);  
bool IsOperand(char);  
bool eqlOrhigher(char, char);  
// int convert();  

// stack <char> inpS;
stack <string> revS;
vector <string> inpArr;
stack <string> postS;

void PrintStack(stack<string> s)
{
    // If stack is empty then return
    if (s.empty())
        return;
     
 
    string x = s.top();
 
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
void insertAtBottom(){

}

int calculate(){
    stack <int> S;  
    int ans=0;
    int n1, n2;
    string ss;
    // PrintStack(revS);
    // string
    int revSSize = revS.size();
    cout<<"size="<<revSSize<<endl;
    for (int i = 0; i<7; i++)
    {
        cout<<"i = "<<i<<endl;
        ss = revS.top();
        cout<<"ss = "<<ss<<endl;
        // cout<<"top3 = "<<S.top()<<endl;
        if (ss.compare("+")==0 || ss.compare("-")==0|| ss.compare("*")==0|| ss.compare("/")==0)
        {
            cout<<"operator"<<ss<<endl;
            // cout<<"1--"<<endl;
            n2 = S.top();
            S.pop();
            n1 = S.top();
            S.pop();
            if (ss.compare("+")==0)
            {
                ans = n1+n2;
            }
            else if (ss.compare("-")==0)
            {
                ans = n1-n2;
            }
            else if (ss.compare("*")==0)
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
            S.push(stoi(ss));
            cout<<"s top = "<<S.top()<<endl;
        }
        revS.pop();
        PrintStack(revS);
        // cout<<revS.top()<<endl;
    }
    cout<<"done"<<endl;
    ans = S.top();
    cout<<ans<<endl;
    return ans;
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
int convert()  
{  
    stack <string> S;  
    string postfix ="";    
    string str;  
    char ch[20];
    char sTop[20];
    cout<<"1"<<endl;
    S.push( "(" );  
    // infix += ')';  
    cout<<inpArr.size()<<endl;
    for(int i = 0; i<inpArr.size(); i++)  
    {  
        // cout<<"2"<<endl;
        str = inpArr[i];  
        // cout<<"3"<<endl;
        strcpy(ch, str.c_str());
        cout<<ch<<endl;
        if(str.compare("(")==0)  
        {
            cout<<"is ("<<endl;
            S.push(str);  
        }
        // else if(IsOperator(*ch))  
        else if(str.compare("+")==0 || str.compare("-")==0|| str.compare("*")==0|| str.compare("/")==0)
        {  
            // cout<<str.compare("-");
            cout<<"is operator"<<endl;
            cout <<"S.top="<<S.top()<<endl;
            strcpy(sTop, S.top().c_str());
            // cout<<"strcpy"<<sTop<<endl;
            while(!S.empty() && eqlOrhigher(*sTop, *ch))  
            {  
                cout<<"operator loop"<<endl;
                postS.push(S.top());
                // postfix += S.top();  
                S.pop(); 
                strcpy(sTop, S.top().c_str()); 
            }  
            S.push(ch);  
        }  
        else if(str.compare(")")==0)  
        {  
            cout<<"is )"<<endl;
            strcpy(sTop, S.top().c_str());
            cout<<S.top()<<"::"<<sTop<<endl;
            while(!S.empty() && (*sTop != '(') )  
            {  
                cout<<"7.5"<<endl;
                
                postS.push(S.top());
                // postfix += S.top();  
                S.pop();  
                strcpy(sTop, S.top().c_str());
                cout<<S.top()<<"::"<<sTop<<endl;
            }  
            
            S.pop();  
            cout<<"^^"<<endl;
        }
        else 
        {
            cout<<"digit"<<endl;
            postS.push(str);
        }
        // cout<<"9"<<endl;
        
    }  
    PrintStack(postS);
return 0;  
}  

int main()  
{  
    string infix_expression, postfix_expression;
    
    int res;   
    char in;
    // string inpStr;
    // getline(cin,inpStr);
    // // cin >> infix_expression;  
    // while (inpStr)
    // {
    //     /* code */
    // }
    string temp;
    string s;
    int cnt=0;
    int flag=0;
    string inpS;
    getline(cin, inpS);
    inpS.push_back(')');
    inpS = "("+inpS;
    for (int k = 0; k < inpS.size(); k++)
    {
        in = inpS[k];
        if(IsOperator(in))
        {
            if (flag==1)
            {
                temp+=in;
                flag=0;
            }
            
            else if (in=='-' && cnt == 0)
            {
                temp+=in;
                // cout<<temp<<endl;
                flag=1;
            }
            else if (temp.empty())
            {
                s.push_back(in);
                inpArr.push_back(s);
            }
            else
            {
                cout<<"$$"<<temp<<endl;
                inpArr.push_back(temp);
                s.push_back(in);
                inpArr.push_back(s);
                temp.clear();
            }
            
            
        }   
        else if (in=='\n')
        {
            inpArr.push_back(temp);
            temp.clear();
        }
        
        else if (flag==1)
        {
            temp+=in;
            cout<<"@"<<cnt<<endl;
            flag=0;
        }
        
        else if (in =='(' && inpS[k+1]=='-')
        {
            flag=1;
            cout<<"@@"<<cnt<<endl;
            s.push_back(in);
            inpArr.push_back(s);
            
        }
        else if (in=='(')
        {
            s.push_back(in);
            inpArr.push_back(s);
        }
        
        else if (in ==')')
        {
            if (!temp.empty())
            {
                inpArr.push_back(temp);
                temp.clear();
            }
            
            s.push_back(in);
            inpArr.push_back(s);
        }
        
        
        else
        {
            // s.push_back(in);
            // cout<<"--"<<s<<endl;
            // inpArr.push_back(temp);
            temp+=in;
            cout<<"!!"<<temp<<endl;
        }
        
        s.clear();
        cnt++;

    }

    for (int i = 0; i < cnt; i++)
    {
        cout<<inpArr[i]<<endl;
    }
    //delete ')' conevrt 不用pushback(')')
    // inpArr.pop_back();
    cout<<"+++"<<endl;
    convert();
    // cout<<"size"<<inpS.size()<<endl;
    int size = postS.size();
    for (int i = 0; i < size; i++)
    {
        revS.push(postS.top());
        postS.pop();
    }
    PrintStack(revS);
    calculate();
    
    
    
    // postfix_expression = convert(infix_expression);  
    // cout << "\n Your Infix expression is: " << infix_expression;  
    // cout << "\n Postfix expression is: " << postfix_expression;  
    // cout<<endl;
    // res = calculate(postfix_expression);
    // cout<<res<<endl;

    //cin.ignore();   

    return 0;  
}  