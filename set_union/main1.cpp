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
    set <int> allSet;
    int size=0;
    int arr[5001]={-1};
    cin>>count;

    cout<<count<<endl;

    for (int i = 0; i < count; i++)
    {
        // cin
        if (i==0)
        {
            while (cin>>num)
            {       
                // cout<<num<<endl;
                mySet.insert(num);

                char ch = getchar();
                if(ch == '\n')
                    break;

            }
        }
        else if(i==1)
        {
            while (cin>>num)
            {       
                if (mySet.find(num)!=mySet.end())
                {
                    resSet.insert(num);
                }
                char ch = getchar();
                if(ch == '\n')
                    break;
            }
        }
        else
        {
            while (cin>>num)
            {
                cout<<num<<endl;
                //有找到
                if (resSet.find(num)!=resSet.end())
                {
                    arr[size++]=resSet.find(num);
                    continue;
                }
                char ch = getchar();
                if(ch == '\n')
                    break;
            }
            for (int k = 0; k < count; k++)
            {
                /* code */
            }
            
            
        }
    }
    for (set<int>::iterator it = resSet.begin(); it != resSet.end(); it++) 
    {
        cout << *it << " ";
    }
    // cout<<resSet.size()<<endl;
    
    return 0;
}