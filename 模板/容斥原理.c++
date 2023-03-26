https://www.luogu.com.cn/problem/solution/P1450

https://www.luogu.com.cn/problem/solution/P2567

/*楼下写的蛮清楚的...这里在下再解释一下这个容斥是怎么来的吧

首先，我们把它当成一个完全背包，处理出来一个dp数组存储方案数，转移方程dp[i] += dp[i - v[i]]dp[i]+=dp[i?v[i]]，复杂度是O(4 \times maxs)O(4×maxs)的。

然后不妨来思考一下，这里的完全背包含义是什么？含义是我们可以无限制的放硬币。

那么这里其实差的就是那个限制。所以先来考虑一个弱化版本：

如果只有一种硬币，那么情况如何呢？这里的方案数包含了一部分超过dd个的。譬如，此时可能求得的结果是带d + 1d+1枚，d + 2d+2枚...只要把这一部分减去就可以了。因此直接删掉合理的情况，那剩下的就是不合理的，而不合理的情况也就是一个容量s - (d + 1) \times vs?(d+1)×v的背包，这个就是不合理的，减去这部分不合理的就是合理的，换言之ans -= dp[s - (d + 1) \* v

而多种硬币呢？其实这就是一个容斥问题了。

所以底下这个是一定能过的：*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
#define MAXN 100003
LL dp[MAXN], c[5], d[5], s;
inline int f(int id) {
    return c[id] * (d[id] + 1);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    dp[0] = 1;    
    cin>>c[1]>>c[2]>>c[3]>>c[4];
    for(int i = 1; i <= 4; ++i)
        for(int j = c[i]; j <= MAXN; ++j)
                dp[j] += dp[j - c[i]];
    int T;
    cin>>T;
    while(T--) {
        cin>>d[1]>>d[2]>>d[3]>>d[4]>>s;
        LL ans = dp[s];
        if(s >= f(1)) ans -= dp[s - f(1)];
        if(s >= f(2)) ans -= dp[s - f(2)];
        if(s >= f(3)) ans -= dp[s - f(3)];
        if(s >= f(4)) ans -= dp[s - f(4)];
        if(s >= f(1) + f(2)) ans += dp[s - f(1) - f(2)];
        if(s >= f(1) + f(3)) ans += dp[s - f(1) - f(3)];
        if(s >= f(1) + f(4)) ans += dp[s - f(1) - f(4)];
        if(s >= f(2) + f(3)) ans += dp[s - f(2) - f(3)];
        if(s >= f(2) + f(4)) ans += dp[s - f(2) - f(4)];
        if(s >= f(3) + f(4)) ans += dp[s - f(3) - f(4)];
        if(s >= f(1) + f(2) + f(3)) ans -= dp[s - f(1) - f(2) - f(3)];
        if(s >= f(1) + f(2) + f(4)) ans -= dp[s - f(1) - f(2) - f(4)];
        if(s >= f(1) + f(3) + f(4)) ans -= dp[s - f(1) - f(3) - f(4)]; 
        if(s >= f(2) + f(3) + f(4)) ans -= dp[s - f(2) - f(3) - f(4)];
        if(s >= f(1) + f(2) + f(3) + f(4)) ans += dp[s - f(1) - f(2) - f(3) - f(4)];
        cout<<ans<<endl;
    }
    return 0;
}
4 4 4 3 3 2 2 2 0 
0 0 1 0 1 1 0 1 0

x