#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<q;i++)
    {
        int c,d;
        cin>>c>>d;
        int cur=0;
        int ans=-1;
        for(int j=c+1;j<=n;j++)
        {
            if(a[j]>a[c])
            {
                cur++;
            }
            if(cur==d)
            {
                ans=j;
                break;
            }
        }
        cout<<ans<<endl;
    }
}