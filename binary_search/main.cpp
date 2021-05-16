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
int cnt;
/*
int binarySearch(vector<int> vect, int target){
  if( vect.size() == 0)
    return -1;

  int left = 0;
  int right = vect.size()-1;
  while(left+1 < right){
    cnt++;
    // 防止left+right溢出
    int mid = left + (right - left) / 2;
    if(vect[mid] == target){ 
         return mid; 
    }else if(vect[mid] < target){ 
         left = mid; 
    }else{ 
         right = mid; 
    }
  }
    if(vect[left] == target) return left;
    if(vect[right] == target) return right;
   return -1;
}*/

int binarySearch(vector<int> vect, int target){
  if(vect.size() == 0)
    return -1;

  int left = 0;
  int right = vect.size();
  while(left < right){
      cnt++;
    // 防止left+right溢出
    int mid = left + (right - left) / 2;
    if(vect[mid] == target){ 
         return mid; 
    }else if(vect[mid] < target){ 
         left = mid + 1; 
    }else{ 
         right = mid ; 
    }
  }
  if(left != vect.size() && vect[left] == target){
      return left;
      }
  // 没有找到
   return -1;
}

int main(){
    int target;
    int num;
    int pos;
    vector <int> v; 
    scanf("%d", &target);
    while (scanf("%d", &num)!=EOF)
    {
        v.push_back(num);
    }
    // cout<<target<<endl;
    // for(vector <int> :: iterator it = v.begin(); it != v.end(); ++it){ 
    // printf(" %d", *it); 
    // } 
    pos = binarySearch(v, target);
    if (pos==-1)
    {
        cout<<-1<<endl;
    }
    else{
        cout<<pos<<endl<<cnt<<endl;
    }
    

    
    return 0;
}