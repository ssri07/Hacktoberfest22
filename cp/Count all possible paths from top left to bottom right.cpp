//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int numberOfPaths(int m, int n){
        long mod = 1e9 + 7;
        long long dp[100][100];

        for(int i = 0; i < n; i++) // fill first row
            dp[0][i] = 1;
            
        for(int i = 1; i < m; i++) // fill first column
            dp[i][0] = 1; 
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = (dp[i][j-1] % mod + dp[i-1][j] % mod) % mod; // add top and left cell
            }
        }
        return dp[m-1][n-1];
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}

// } Driver Code Ends