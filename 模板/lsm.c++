#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int N = 10000007;
int n,cnt,vis[N];
ll dp[N],ddp[N],fac[N],inv[41],sum[N],prime[N];
void qprime()
{
    inv[1]=1;
    for(int i=2;i<=40;i++)
    {
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    }
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!vis[i])
        {
            prime[++cnt]=i;
            dp[i]=3;
            ddp[i]=2;
            sum[i]=1;
        }
        for(int j=1;j<=cnt&&((ll)i)*prime[j]<=n;j++)
        {
            int tmp=i*prime[j];
            vis[tmp]=1;
            if(i%prime[j]==0)
            {
                sum[tmp]=sum[i]+1;
                //dp[tmp]=((dp[i]+1)*inv[sum[i]+1]%mod*(sum[tmp]+1)-1+mod)%mod;
                dp[tmp]=(dp[i]+ddp[i])%mod;
                ddp[tmp]=ddp[i];
                fac[tmp]=fac[i]*inv[sum[i]+1]*(sum[tmp]+1);
                break;
            }else
            {
                dp[tmp]=(3*dp[i]+fac[i]*2)%mod;
                sum[tmp]=1;
                ddp[tmp]=(dp[tmp]-dp[i]+mod)%mod;
                fac[tmp]=fac[i]*2;
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    qprime();
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=(ans+dp[i])%mod;
    }
    printf("%lld\n",ans);
    return 0;
}