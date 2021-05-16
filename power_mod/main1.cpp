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
vector <int> v;
int main(){
    int cnt;
    long long x,y,p;
    int n;
    long long res;
    scanf("%d",&cnt);
    for (int i = 0; i < cnt; i++)
    {
        cin>>x>>y>>p;
        //eat \n
        getchar();
        // cout<<x<<" "<<y<<" "<<p<<endl;
        res = 1;
        while (y)
        {
            if(y&1)
            {
                res = res * x % p;
            }
            x = x * x % p;
            y>>=1;
        }
        cout<<res<<endl;
    } 
    
    return 0;
}