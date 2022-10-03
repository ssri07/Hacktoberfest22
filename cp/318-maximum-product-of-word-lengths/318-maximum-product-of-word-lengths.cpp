class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        int state[n];
        for(int i=0;i<n;i++)
        {
            int temp=0;
            for(int j=0;j<words[i].size();j++)
            {
                temp |= 1<<(words[i][j]-'a');
            }
            state[i]=temp;
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(!(state[i]&state[j]))
                    ans=max(ans,(int)(words[i].size()*words[j].size()));
            }
        }
        
        return ans;
    }
};