#include<bits/stdc++.h>
using namespace std;
int main(){
    int dp[10][7];
    dp[0][0]=1;
    dp[1][0]=1;
    dp[1][1]=1;
    for(int i=2;i<=8;i++)
    {
        dp[i][0]=1;
        for(int j=1;j<=i;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
        }
    }
    cout<<dp[8][5];
}

//某一道卡特兰数
https://www.luogu.com.cn/problem/solution/P1044

//盒子与球
https://www.luogu.com.cn/problem/solution/P1287