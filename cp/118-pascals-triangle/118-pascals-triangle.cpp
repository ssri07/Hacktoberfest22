class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(1);
        ans.push_back(temp);
        if(numRows==1)
        {
            return ans;
        }
        temp.push_back(1);
        ans.push_back(temp);
        if(numRows==2)
        {
            return ans;
        }
        
        for(int i=3;i<=numRows;i++)
        {
            int id=i-2;
            vector<int> v;
            v.push_back(1);
            
            for(int j=0;j<ans[id].size()-1;j++)
            {
                int s=ans[id][j]+ans[id][j+1];
                v.push_back(s);
            }
            
            v.push_back(1);
            ans.push_back(v);
        }
        return ans;
        
    }
};