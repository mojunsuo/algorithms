#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
int main(){
    //tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> t;

    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> t;

    //t.find_by_order();

    //t.order_of_key();

    int n,q;
    cin>>n>>q;
    vector<vector<int>>a(n+1,vector<int>(2,0));
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][0];
        a[i][1]=i;
    }

    vector<vector<pair<int,int>>>needsolve(n+1);

    vector<vector<int>>query(q,vector<int>(2,0));
    for(int i=0;i<q;i++)
    {
        cin>>query[i][0]>>query[i][1];
        
        needsolve[a[query[i][0]][0]].push_back(make_pair(query[i][1],i));
    }
    vector<int>ans(q,-1);

    sort(a.begin(),a.end());

    for(int i=n;i>=1;i--)
    {
        int cur=t.order_of_key(a[i][1]);
        
        for(auto&j:needsolve[i])
        {
            auto p=t.find_by_order(cur+j.first-1);
            if(p!=t.end())
            {
                ans[j.second]=*p;
            }
        }
        t.insert(a[i][1]);
    }
    for(int i:ans)
    {
        cout<<i<<endl;
    }
    
}