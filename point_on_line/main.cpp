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


vector<vector<int> > points;
int gcd(int a, int b){
    return (b==0 ? a : gcd(b, a%b));
}

int main(){
    int n;
    int coord;
    // int y;
    int res = 0;
    int factor;
    double slope;
    double dx;
    double dy;
    int maxCount;
    int ans;
    cin>>n;
    // cout<<n<< endl;
    for (int i = 0; i < n; i++)
    {
        vector<int>row;
        for (int j = 0; j < 2; j++)
        {
            cin>>coord;
            row.push_back(coord);
        }
        points.push_back(row);
    }
    // for(int i=0;i<points.size();i++){
    //     for(int j=0;j<points[i].size();j++){
    //         cout<<points[i][j]<<"=>";
    //     }
    //     cout<<""<<endl;       
    // }
    unordered_map<double, int> hash;
    int verticalPoint = 0;
    // cout<<"1"<<endl;
    // cout<<"size="<<points.size()<<endl;
    for(int i=0;i<points.size();i++)
    {
        // int duplicates = 0;
        maxCount=0;
        // cout<<"i="<<i<<endl;
        for(int j=i+1;j<points.size();j++)
        {
            // cout<<"i="<<i<<"; j="<<j<<endl;
            // cout<<"x1="<<points[i][0]<<"y1="<<points[i][1]<<"x2="<< points[j][0]<<"y2="<<points[j][1]<<endl;
            // if (points[i][0] == points[j][0] && points[i][1]==points[j][1])
            // {
            //     duplicates += 1;
            // }
                
            if (points[i][0] == points[j][0])
            {
                verticalPoint++;
            }                
            else
            {
                // cout<<"4"<<endl;
                dx = points[i][0] - points[j][0];
                dy = points[i][1] - points[j][1];
                factor = gcd(dx,dy);
                slope = (double)((dy/factor) / (dx/factor));
                // cout<<"slope="<<slope<<endl;
                hash[slope]++;
            }
            
            // cout<<"hashSize="<<hash.size()<<endl;
            // cout<<"maxCount="<<maxCount<<endl;
            // cout<<"hash[slope]="<<hash[slope]<<endl;
            maxCount = max(maxCount, hash[slope]);
            // cout<<"maxCount="<<maxCount<<endl;
            // if (hash[slope]>res)
            // {
            //     res = hash[slope]+1;
            // }
            
            res = max(res, hash[slope]);
        }
        
        // cout<<"hashSize="<<hash.size()<<endl;
        // cout<<"6"<<endl;
        hash.clear();
        // cout<<"-----------"<<endl;
        // cout<<"res="<<res<<endl;
        // cout<<"-----------"<<endl;
    }   

    // for (auto p : points)
    // {
    //     int samePoint = 0, verticalPoint = 0;
    //     unordered_map<LD, int> hash;
    //     for (auto q : points)
    //     {
    //         if (p == q)
    //             samePoint += 1;
    //         else if (p[0] == q[0])
    //             verticalPoint++;
    //         else
    //         {
    //             LD k = (LD)(p[1] - q[1]) / (p[0] - q[0]); // 强制类型转换
    //             hash[k]++;
    //         }
    //     }
    //     int c = verticalPoint;
    //     for (auto h : hash)
    //         c = max(c, h.second);
    //     res = max(res, c + samePoint);
    // }
    // cout<<"-----"<<endl;
    cout<<res+1<<endl;
    

    return 0;
}