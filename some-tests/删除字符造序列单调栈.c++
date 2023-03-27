#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    vector<int>cnt(10,0);
    vector<int>has(10,0);
    for(auto i:s)
    {
        cnt[i-'0']++;
    }
    vector<int>a;
    for(int i=0;i<s.size();i++)
    {
        int cur=s[i]-'0';
        if(a.empty())
        {
            a.push_back(cur);
            has[cur]++;
        }
        else{
            while(!a.empty()&&cur>=a.back())
            {
                if(cnt[a.back()]<=2)
                {
                    break;
                }
                cnt[a.back()]--;
                has[a.back()]--;
                a.pop_back();
            }
            if(has[cur]<2)
            {
                a.push_back(cur);
                has[cur]++;
            }
            else{
                cnt[cur]--;
            }
        }
    }
    for(int i:a)
    {
        cout<<i<<" ";
    }
}