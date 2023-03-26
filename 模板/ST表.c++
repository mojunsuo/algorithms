#include <iostream>
using  namespace std;

int n,m,x,y,a[100010],lg[100010],f[100010][20];

int main()
{
	cin>>n>>m; lg[1]=0;
	for (int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
	for (int i=1;i<=n;i++) cin>>f[i][0];
	for (int j=1;j<=lg[n];j++)
	for (int i=1;i<=n-(1<<j)+1;i++){
		f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	}
	
	
	for (int i=1;i<=m;i++)
	{
		cin>>x>>y; int l=lg[y-x+1];
		cout<<max(f[x][l],f[y-(1<<l)+1][l])<<endl;
	}
}