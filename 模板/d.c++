#include<bits/stdc++.h>
using namespace std;
int main()
{
    for(int i=1;i<=1000;i++)
    {
        printf("Case %d : ",i);
        system("data >tt.in");
        system("10301 <tt.in >my.out");
        system("duipai <tt.in >std.out");
        if(system("fc my.out std.out >tt.out")!=0)
        {
            puts("WA");
            return 0;
        }else
        {
            puts("AC");
        }
    }
    return 0;
}
