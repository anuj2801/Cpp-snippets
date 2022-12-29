#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using pbset=tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
// less_equal<T> //for multiset
//or,
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update> new_data_set;
int main()
{   
    pbset<int> s;
    s.insert(5); //insertion in O(logn)
    s.insert(9);
    s.insert(2);
    s.insert(3);
    //2 3 5 9
    cout<<*s.find_by_order(1)<<endl;  //element at index t in O(logn)
    cout<<s.order_of_key(6)<<endl; //how many elements less than 5 (this one is valid for multiset too)... or,position of 5 or rank of 5 (for set only)
    cout<<s.size()<<endl;
    return 0;
}