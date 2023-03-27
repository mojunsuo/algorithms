class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            if (p[i - 1] == '*') {
                dp[0][i] = true;
            }
            else {
                break;
            }
        }
        for (int i = 1; i <= m; ++i) {//dp[i][j]代表s的前i个字符和p的前j个字符是否匹配
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] | dp[i - 1][j];//有一个成立即可
                }
                else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        if(m==0)
        {
            return n;
        }
        if(n==0)
        {
            return m;
        }
        //vector<int>
        vector<vector<int>>dp(m,vector<int>(n,INT_MAX));
        dp[0][0]=1-(word1[0]==word2[0]);
        for(int i=1;i<m;i++)
        {
            if(dp[i-1][0]<i)
            {
                dp[i][0]=dp[i-1][0]+1;
            }
            else if(word1[i]==word2[0])
            {
                dp[i][0]=dp[i-1][0];
            }
            else{
                dp[i][0]=dp[i-1][0]+1;
            }
        }
    
        for(int i=1;i<n;i++)
        {
            if(dp[0][i-1]<i)
            {
                dp[0][i]=dp[0][i-1]+1;
            }
            else if(word1[0]==word2[i])
            {
                dp[0][i]=dp[0][i-1];
            }
            else{
                dp[0][i]=dp[0][i-1]+1;
            }
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[j][i]=dp[j][i-1]+1;
                int flag=0;
                for(int k=j-1;k>=0;k--){
                    if(k<j)
                    {
                        if(word1[k+1]==word2[i])
                        {
                            flag=1;
                        }
                    }
                    dp[j][i]=min(dp[j][i],dp[k][i-1]+j-k-1+1-flag);
                }
            }
        }
        /*
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
        }*/
        return dp[m-1][n-1];
        //return ans;
    }
};