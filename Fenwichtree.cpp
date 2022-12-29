#include <bits/stdc++.h> 
using namespace std; 

class BIT{
public:
    int size;
    vector<long long> v;
    BIT(int s){
        size = s;
        v.resize(s, 0);
    }
    void update(int i, int delta){
        while(i < size){
            v[i] += delta;
            i += i & (-i);
        }
    }
    long long sum(int i){
        long long s = 0;
        while(i > 0){
            s += v[i];
            i -= i & (-i);
        }
        return s;
    }
};

int solve(vector<int> v, int n) {
    int N = 1e6 + 1, M = 1e9 + 7;
    BIT *pre = new BIT(N), *post = new BIT(N);
    long long fn = v[0], ans = fn, totSum = fn;
    pre->update(v[0], 1);
    post->update(v[0], v[0]);
    for(int i = 1; i < n; i++) {
        int rank = pre->sum(v[i]) + 1;
        long long sumGreaterThanI = totSum - post->sum(v[i]);
        fn = (fn + rank * 1ll * v[i] + sumGreaterThanI) % M;
        ans = (ans + fn) % M;
        pre->update(v[i], 1);
        post->update(v[i], v[i]);
        totSum += v[i];
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << solve(v, n);
}