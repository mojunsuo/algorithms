class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2*k,-INT_MAX));
        for(int i=0;i<2*k;i++)
        {
            if(i%2==0)
            {
                dp[0][i]=-prices[0];
            }
            else{
                dp[0][i]=0;
            }
        }
        int n=prices.size();
        for(int i=1;i<n;i++)
        {
            dp[i][0]=max(dp[i-1][0],-prices[i]);
            for(int j=1;j<2*k;j++)
            {
                if(j%2==0)
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]-prices[i]);
                else
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+prices[i]);
            }
        }
        int ans=0;
        /*for(auto&i:dp)
        {
            for(int j:i)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }*/
        for(int i=0;i<2*k;i++)
        {
            ans=max(ans,dp.back()[i]);
        }
        return ans;
    }
};  