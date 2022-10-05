//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
  set<int>s;
  int sum=0;
    void primeFactors(int n) 
{ 
    
    while (n%2 == 0) 
    { 
        s.insert(2);
        n = n/2; 
    } 
     
   
    for (int i = 3; i <= sqrt(n); i = i+2) 
    { 
        
        while (n%i == 0) 
        { 
            s.insert(i);
            n = n/i; 
        } 
    } 
     
    
    if (n > 2) 
        s.insert(n);
        
    for(auto &it:s)
     sum+=it;
     
    s.clear(); 
} 
 
    int sumOfAll(int l, int r){
       
       
       
       for(int i=l;i<=r;i++)
       {
           if(i==1)
            sum+=1;
        else{
             primeFactors(i); 
        }    
       
       }
       
       return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin>>l>>r;
        Solution ob;
        cout<<ob.sumOfAll(l,r)<<endl;
    }
    return 0;
}

// } Driver Code Ends