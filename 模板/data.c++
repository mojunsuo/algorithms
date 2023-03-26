#include<bits/stdc++.h>
using namespace std;
    int a[10005];
int main()
{
    srand(time(NULL));
    int n=rand()%10000+1;
    int q=rand()%10000+1;
    for(int i=1;i<=n;i++)
    {
        a[i]=i;
    }
    for(int i=1;i<=n;i++)
    {
        int ui=rand()%n+1;
        int vi=rand()%n+1;
        swap(a[ui],a[vi]);
    }
    printf("%d %d\n",n,q);
    for(int i=1;i<=n;i++)
    {
        printf("%d ",a[i]);
    }
    puts("");
    for(int i=1;i<=q;i++)
    {
        int pi=rand()%n+1;
        int ki=rand()%n+1;
        printf("%d %d\n",pi,ki);
    }
}