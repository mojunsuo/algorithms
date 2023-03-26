#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
int main(){
    tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> t;

    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> t;

    t.find_by_order();

    t.order_of_key();

   

}


