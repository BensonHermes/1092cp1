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
    int x,y,p;
    int n;
    scanf("%d",&cnt);
    for (int i = 0; i < cnt; i++)
    {
        cin>>x>>y>>p;
        cout<<x<<" "<<y<<" "<<p<<endl;
        for (int j = 0; y>0 ; j++)
        {
            v.push_back(y%2);
            y=y/2;
            // cout<<n<<endl;
        }
        //reverse vector to be binary
        getchar();
        reverse(v.begin(),v.end());
        cout<<"1``"<<endl;
        // vector <int> v; 
        for(vector <int> :: iterator it = v.begin(); it != v.end(); ++it)
        { 
            // printf("&&"); 
            printf(" %d", *it); 
        }
        cout<<endl;
        for (int k = 0; k < v.size(); k++)
        {
            v[k];
            pow(2,v[k]);
        }
        
        v.clear();
    
    } 
    

    
    
    return 0;
}