class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        
        vector<vector<int>>dp(n+1,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i+1][j]=dp[i][j]+matrix[i][j];
            }
        }
        
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int l=i+1;l<=n;l++){
                for(int j=0;j<m;j++){
                    int val=0;
                    for(int k=j;k<m;k++){
                        val+=dp[l][k]-dp[i][k];
                        
                        if(val<target){
                            ans=max(ans,val);
                        }
                        else if(val==target){
                            return target;
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};