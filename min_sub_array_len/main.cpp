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

    
    // int res=len(nums)+1;

    int n;
    int in;
    int target;
    vector <int> v;

    int l=0;
    int r=-1; 
    int sum=0;
    int res;

    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&in);
        v.push_back(in);
    }
    scanf("%d",&target);
    // cout<<n<<" "<<target<<endl;
    int arrSize = v.size();
    res=arrSize+1;
    // cout<<"size= "<<arrSize<<endl;
    while (l<arrSize){
        // cout<<"sum="<<sum<<endl;
        if (sum<target && r<arrSize){
            r=r+1;
            sum=sum+v[r];
        }
        else{
            sum=sum-v[l];
            l=l+1;
        }
        if (sum>=target){
            res=min(res,r-l+1);
            cout<<"res="<<res<<endl;
        }
        
    }
    if (res>arrSize){
        res=0;
    }
    cout<<res<<endl;
    
    return 0;
}