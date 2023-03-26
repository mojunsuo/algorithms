https://www.luogu.com.cn/problem/solution/P1450

https://www.luogu.com.cn/problem/solution/P2567

/*¥��д���������...���������ٽ���һ������ݳ�����ô���İ�

���ȣ����ǰ�������һ����ȫ�������������һ��dp����洢��������ת�Ʒ���dp[i] += dp[i - v[i]]dp[i]+=dp[i?v[i]]�����Ӷ���O(4 \times maxs)O(4��maxs)�ġ�

Ȼ�󲻷���˼��һ�£��������ȫ����������ʲô�����������ǿ��������Ƶķ�Ӳ�ҡ�

��ô������ʵ��ľ����Ǹ����ơ�������������һ�������汾��

���ֻ��һ��Ӳ�ң���ô�������أ�����ķ�����������һ���ֳ���dd���ġ�Ʃ�磬��ʱ������õĽ���Ǵ�d + 1d+1ö��d + 2d+2ö...ֻҪ����һ���ּ�ȥ�Ϳ����ˡ����ֱ��ɾ��������������ʣ�µľ��ǲ�����ģ�������������Ҳ����һ������s - (d + 1) \times vs?(d+1)��v�ı�����������ǲ�����ģ���ȥ�ⲿ�ֲ�����ľ��Ǻ���ģ�����֮ans -= dp[s - (d + 1) \* v

������Ӳ���أ���ʵ�����һ���ݳ������ˡ�

���Ե��������һ���ܹ��ģ�*/

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