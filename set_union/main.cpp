 #include <iostream>  
 #include <string>  
 #include <vector>  
 #include <set>  
 #include <map>  
 #include <unordered_map>  
 #include <algorithm>
//  #include <bits/stdc++.h>
//  #define max(x, y) ((x) > (y) ? (x) : (y))
 using namespace std;

int main(){
    int count;
    int num;
    set <int> mySet;
    set <int> resSet;
    set <int> tempSet;
    int printTrace=0;
    cin>>count;
    getchar();
    // cout<<count<<endl;
    for (int i = 0; i < count; i++)
    {
        // cin
        string temp;
        char ch;
        if (i==0)
        {
            ch = getchar();
            // cout<<"11"<<endl;
            // cout<<ch<<endl;
            // temp.push_back(ch);
            while (ch!='\n')
            {       
                // cout<<ch<<endl;
                // mySet.insert(num);
                if(ch == ' ')
                {
                    num = stoi(temp);
                    mySet.insert(num);
                    temp.clear();
                }    
                else
                {
                    temp += ch;
                }
                ch = getchar();
            }
            if (count==1)
            {
                for (set<int>::iterator it = mySet.begin(); it != mySet.end(); it++) 
                {
                    if (printTrace==0)
                    {
                        cout << *it;
                        printTrace++;
                    }
                    else
                    {
                        cout <<" "<< *it;
                    }
                }
                cout<<" "<<endl;
                return 0;
            }
        }
        else if(i==1)
        {
            ch =getchar();
            while (ch!='\n')
            {       
                // cout<<num<<endl;
                // mySet.insert(num);
                if(ch == ' ')
                {
                    num = stoi(temp);
                    if (mySet.find(num)!=mySet.end())
                    {
                        resSet.insert(num);
                    }
                    temp.clear();
                }    
                else
                {
                    temp += ch;
                }
                ch = getchar();
            }
        }
        else
        {
            ch =getchar();
            while (ch!='\n')
            {
                // cout<<num<<endl;
                //有找到
                
                if(ch == ' ')
                {
                    num = stoi(temp);
                    if (resSet.find(num)!=resSet.end())
                    {
                        tempSet.insert(num);
                    }
                    temp.clear();
                }    
                else
                {
                    temp += ch;
                }
                ch = getchar();
            }
            // for (set<int>::iterator it = tempSet.begin(); it != tempSet.end(); it++) {
            //     cout << *it << " ";
            //     }
            //     cout<<endl;
            resSet = tempSet;
            tempSet.clear();
        }
    }
    //印出結果
    for (set<int>::iterator it = resSet.begin(); it != resSet.end(); it++) 
    {
        if (printTrace==0)
        {
            cout << *it;
            printTrace++;
        }
        else
        {
            cout <<" "<< *it;
        }
    }
    cout<<endl;
    // cout<<resSet.size()<<endl;
    
    return 0;
}