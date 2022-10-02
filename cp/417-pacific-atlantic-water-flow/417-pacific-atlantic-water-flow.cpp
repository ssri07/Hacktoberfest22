class Solution {
public:
    void dfs(vector<vector<int>>& mat,vector<vector<int>>& p,int x,int y,int val)
    {
        if(x<0 || x>=mat.size() || y<0 || y>=mat[0].size() || p[x][y]==1 || val>mat[x][y])
            return ;
        
            p[x][y]=1;
        
        
        dfs(mat,p,x-1,y,mat[x][y]);
        dfs(mat,p,x+1,y,mat[x][y]);
        dfs(mat,p,x,y-1,mat[x][y]);
        dfs(mat,p,x,y+1,mat[x][y]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> p(m,vector<int>(n,0)), a(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++)
        {
            dfs(heights,p,i,0,heights[i][0]);
        }
        for(int j=0;j<n;j++)
        {
            dfs(heights,p,0,j,heights[0][j]);
        }
        
        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //         cout<<p[i][j]<<" ";
        //     cout<<endl;
        // }
        for(int i=0;i<m;i++)
        {
            dfs(heights,a,i,n-1,heights[i][n-1]);
        }
        for(int j=0;j<n;j++)
        {
            dfs(heights,a,m-1,j,heights[m-1][j]);
        }
        // cout<<endl;
        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //         cout<<a[i][j]<<" ";
        //     cout<<endl;
        // }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                if(a[i][j] == p[i][j] && a[i][j]==1)
                {
                    vector<int> t;
                    t.push_back(i);
                    t.push_back(j);
                    ans.push_back(t);
                }
        }
        
        
        return ans;
        
    }
};