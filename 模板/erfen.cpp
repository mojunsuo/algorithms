// #include<bitsdc++.h>
// using namespace std;
// const int N = 500005;
// typedef long long ll;
// int T,n;
// char ss[N];
// int len,has[N],tr[N],rk[N],sa[N],h[N];
// int cmp(int x,int y,int k)
// {
//     if(x+k>len||y+k>len)    return 0;
//     return rk[x]==rk[y]&&rk[x+k]==rk[y+k];
// }
// void getsa()
// {
//     len=n;
//     int i,cnt;
//     for(i=1;i<=len;i++)    has[ss[i]]++;
//     for(i=1,cnt=0;i<=128;i++)    if(has[i])    tr[i]=++cnt;
//     for(i=1;i<=128;i++)    has[i]+=has[i-1];
//     for(i=1;i<=len;i++)    rk[i]=tr[ss[i]],sa[has[ss[i]]--]=i;
//     for(int k=1;cnt!=len;k<<=1)
//     {
//         for(i=1;i<=len;i++)    has[i]=0;
//         for(i=1;i<=len;i++)    has[rk[i]]++;
//         for(i=1;i<=len;i++)    has[i]+=has[i-1];
//         for(i=len;i>=1;i--)    if(sa[i]>k)    tr[sa[i]-k]=has[rk[sa[i]-k]]--;
//         for(i=1;i<=k;i++)    tr[len-i+1]=has[rk[len-i+1]]--;
//         for(i=1;i<=len;i++)    sa[tr[i]]=i;
//         for(i=1,cnt=0;i<=len;i++)    tr[sa[i]]=cmp(sa[i],sa[i-1],k)?cnt:++cnt;
//         for(i=1;i<=len;i++)    rk[i]=tr[i];
//     }
// }
// void getheight()
// {
//     for(int i=1;i<=len;i++)
//     {
//         if(rk[i]==1)    continue;
//         for(int j=max(1,h[rk[i-1]]-1);;j++)
//         {
//             if(ss[i+j-1]==ss[sa[rk[i]-1]+j-1])    h[rk[i]]=j;
//             else    break;
//         }
//     }
// }
// int main()
// {
//     scanf("%s",ss+1);
//     n=strlen(ss+1);
//     for(int i=1;i<n;i++)
//     {
//         ss[n+i]=ss[i];
//     }
//     int ln=n;
//     n=n*2-1;
//     getsa();
//     getheight();
//     ll ans=0;
//     for(int i=1;i<=n;i++)
//     {
//         ans+=min(ln,n-sa[i]+1);
//         ans-=min(ln,h[i]);
//     }
//     printf("%lld\n",ans);
// 	return 0;
// }
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5003;
int n,xi,yi,zi;
ll mx,sum,tot;
struct node
{
    int ti;
    ll ai;
    node(int TI,ll AI):ti(TI),ai(AI){}
    node(){}
    bool friend operator < (node x,node y)
    {
        return x.ti<y.ti;
    }
}a[N];
int work()
{
    deque<pair<int,ll>>q;
    tot-=a[1].ai;
    if(tot<0)
    {
        return 0;
    }
    q.push_back(make_pair(a[1].ti-yi+zi,a[1].ai));
    for(int i=2;i<=n;i++)
    {
        //
        //auto pp=q.front();
        if(tot>=a[i].ai)
        {
            tot-=a[i].ai;
            q.push_back(make_pair(a[i].ti+zi-yi,a[i].ai));
            //a[i].ai=0;
            continue;
        }
        int tmp=a[i].ai;
        if(tot<tmp)
        {
            tmp-=tot;
            q.push_back(make_pair(a[i].ti+zi-yi,tot));
            tot=0;
        }
        while(!q.empty()&&q.front().first+xi<=a[i].ti)
        {
            //tot+=q.front().second;
            auto pp=q.front();
            q.pop_front();
            if(pp.second>tmp)
            {
                if(a[i].ti-pp.first-xi<=yi)
                {
                    q.push_back(make_pair(a[i].ti+zi-(a[i].ti-pp.first-xi),tmp));
                }
                else{
                    q.push_back(make_pair(a[i].ti+zi-yi,tmp));
                }
                pp.second-=tmp;
                q.push_front(pp);
                tmp=0;
                break;
            }
            else{
                if(a[i].ti-pp.first-xi<=yi)
                {
                    q.push_back(make_pair(a[i].ti+zi-(a[i].ti-pp.first-xi),pp.second));
                }
                else{
                    q.push_back(make_pair(a[i].ti+zi-yi,pp.second));
                }
                tmp-=pp.second;
            }
            
            
            
        }
        if(tmp)
        {
            return 0;
        }
    }
    return 1;
}
ll sol()
{
    ll lx=mx,rx=sum;
    while(lx<=rx)
    {
        ll mid=(lx+rx)>>1;
        tot=mid;
        if(work())
        {
            rx=mid-1;
        }else{
            lx=mid+1;
        }
    }
    return lx;
}
int main()
{
    scanf("%d%d%d%d",&n,&xi,&yi,&zi);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%lld",&a[i].ti,&a[i].ai);
        mx=max(mx,a[i].ai);
        sum+=a[i].ai;
    }
    sort(a+1,a+1+n);
    printf("%lld\n",sol());
    return 0;
}