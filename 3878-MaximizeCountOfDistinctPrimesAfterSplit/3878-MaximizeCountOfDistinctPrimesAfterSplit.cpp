// Last updated: 12/14/2025, 4:15:12 PM
#include <bits/stdc++.h>
using namespace std;

/* ---------- sieve up to 1e5 ---------- */
const int LIM = 100000;
bitset<LIM + 1> isPrime = []{
    bitset<LIM + 1> p;  p.set();  p[0] = p[1] = 0;
    for (int i = 2; i * i <= LIM; ++i)
        if (p[i]) for (int j = i * i; j <= LIM; j += i) p[j] = 0;
    return p;
}();

/* ---------- lazy seg-tree for range add / range max ---------- */
struct SegTree {
    int n;
    vector<int> mx, lazy;
    SegTree(int _n = 0){ init(_n); }
    void init(int _n){
        n = max(1,_n);
        mx.assign(4*n,0); lazy.assign(4*n,0);
    }
    void push(int node){
        if (lazy[node]==0) return;
        for (int ch : {node<<1, node<<1|1}){
            mx[ch]   += lazy[node];
            lazy[ch] += lazy[node];
        }
        lazy[node] = 0;
    }
    void add(int node,int l,int r,int ql,int qr,int val){
        if (qr<l || r<ql) return;
        if (ql<=l && r<=qr){ mx[node]+=val; lazy[node]+=val; return; }
        push(node);
        int mid=(l+r)>>1;
        add(node<<1,l,mid,ql,qr,val);
        add(node<<1|1,mid+1,r,ql,qr,val);
        mx[node]=max(mx[node<<1],mx[node<<1|1]);
    }
    void rangeAdd(int l,int r,int val){ if(l<=r) add(1,0,n-1,l,r,val); }
    int maxVal()const{ return mx[1]; }
};

class Solution {
public:
    vector<int> maximumCount(vector<int>& nums, vector<vector<int>>& queries) {
        const int n = nums.size();
        SegTree seg(max(1,n-1));                 // handles n==2 too
        array<int, LIM+1> present{};             // 0/1 whether prime appears
        vector<set<int>> occ(LIM+1);             // positions per prime

        int D = 0;                               // # distinct primes

        auto addInterval = [&](int l,int r,int delta){
            if (l<=r) seg.rangeAdd(l,r,delta);   // [l,r] inclusive
        };

        /* ---------- build ---------- */
        for (int i=0;i<n;++i) if (isPrime[nums[i]]){
            int p = nums[i];
            occ[p].insert(i);
        }
        for (int p=2;p<=LIM;++p) if (!occ[p].empty()){
            present[p]=1; ++D;
            if (occ[p].size()>=2){
                addInterval(*occ[p].begin(), *occ[p].rbegin()-1, +1);
            }
        }

        vector<int> out;  out.reserve(queries.size());

        for (auto &q : queries){
            int idx = q[0], val = q[1];
            int old = nums[idx];

            /* ---- remove old value ---- */
            if (isPrime[old]){
                int p = old;
                auto &S = occ[p];
                int beforeSz = S.size();
                if (beforeSz>=2){
                    addInterval(*S.begin(), *S.rbegin()-1, -1);
                }
                S.erase(idx);
                if (beforeSz==1){ present[p]=0; --D; }
                else if (beforeSz==2){          // interval disappears
                    // nothing to add back
                }else if (beforeSz>2){
                    addInterval(*S.begin(), *S.rbegin()-1, +1);
                }
            }

            /* ---- insert new value ---- */
            nums[idx]=val;
            if (isPrime[val]){
                int p = val;
                auto &S = occ[p];
                int beforeSz = S.size();
                if (beforeSz>=2){
                    addInterval(*S.begin(), *S.rbegin()-1, -1);
                }
                S.insert(idx);
                if (beforeSz==0){ present[p]=1; ++D; }
                if (S.size()>=2){
                    addInterval(*S.begin(), *S.rbegin()-1, +1);
                }
            }

            out.push_back(D + seg.maxVal());
        }
        return out;
    }
};
