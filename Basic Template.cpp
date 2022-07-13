#include<bits/stdc++.h>
using namespace std; 
 
#define fast            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define lli             long long int
#define ld              long double
#define pll             pair<lli,lli>
#define ve              vector<lli>
#define vep             vector<pll>
#define pb              push_back
#define mp              make_pair
#define all(x)          (x).begin(),(x).end()
#define fr(i,a,n)       for(lli i=a;i<(n);i++)
#define frx(i,a,n)      for(lli i=a;i>(n);i--)
#define lb              lower_bound
#define ub              upper_bound
#define F               first
#define S               second
#define endl            '\n'
#define op(x)           cout<<x<<endl
#define op2(x,y)        cout<<x<<" "<<y<<endl
#define parr(arr,a,n)   fr(u,a,n) cout<<arr[u]<<" "; cout<<endl
#define yes             cout<<"YES"<<endl
#define no              cout<<"NO"<<endl
#define mem(a,x)        memset(a,x,sizeof(a))
#define sz(a) 		    ((lli) a.size())
#define INF             ((lli)4e18)
#define INF2            ((lli)1e17)

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}

const lli N=1e5+10;
//-----------------------------------------CODE_BEGINS----------------------------//

void solve(){
    
}

int main(){
    fast;
    lli test=1;
    cin>>test;
    while(test--){
        solve();
    }
}

////// Basic Modular 

lli mod;

lli add(lli a,lli b){
    lli res=a+b;
    if(res>=mod) res-=mod;
    return res;
}

lli sub(lli a,lli b){
    lli res=a-b;
    if(res<0) res+=mod;
    return res;
}

lli mul(lli a,lli b){
    return (a*b)%mod;
}

///// Interactive asker

lli ask(ve v){
    cout<<"? ";
    for(auto e:v)cout<<e<<" ";
    cout<<endl;
    lli ans;
    cin>>ans;
    return ans;
}

///// RNG Stuff

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
lli random_long(lli l = 0,lli r = 10){
    uniform_int_distribution<int64_t> generator(l,r);
    return generator(rng);
}

//////__int128 I/O

#ifdef __SIZEOF_INT128__
ostream& operator << (ostream &os, __int128 const& value){
    static char buffer[64];
    int index = 0;
    __uint128_t T = (value < 0) ? (-(value + 1)) + __uint128_t(1) : value;
    if (value < 0) 
        os << '-';
    else if (T == 0)
        return os << '0';
    for(; T > 0; ++index){
        buffer[index] = static_cast<char>('0' + (T % 10));
        T /= 10;
    }    
    while(index > 0)
        os << buffer[--index];
    return os;
}
istream& operator >> (istream& is, __int128& T){
    static char buffer[64];
    is >> buffer;
    size_t len = strlen(buffer), index = 0;
    T = 0; int mul = 1;
    if (buffer[index] == '-')
        ++index, mul *= -1;
    for(; index < len; ++index)
        T = T * 10 + static_cast<int>(buffer[index] - '0');
    T *= mul;    
    return is;
}
#endif

//////Pragmas

#pragma GCC optimize ("O3")

#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")

////recc.

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

/////coordinate compression

sort(all(comp));
comp.resize(unique(all(comp))-comp.begin());

////////custom comparator
///// RETURN TRUE WHEN A < B
///// RETURN FALSE WHEN A > B
///// RETURN FALSE WHEN A==B

static bool cmp(const string &a,const string &b) {
    int n=a.size(),m=b.size();
    if(n<m)return true;
    if(n>m)return false;
    return (a<b);
}

/// declaration for set

set<int,decltype(&cmp)> s(cmp);

///////////PBDS

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<lli,lli>, null_type, less<pair<lli,lli>>, rb_tree_tag, tree_order_statistics_node_update> pset;


order_of_key (k) : Number of items strictly smaller than k 
find_by_order(k) : K-th element in a set (counting from zero)

////////////Custom Hash

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

unordered_map<long long, int, custom_hash> safe_map;

//////////////// GOOGLE TEMPLATE

int main(){
    fast;
    lli test,cur=1;
    cin>>test;
    while(cur<test+1){
        cout<<"Case #"<<cur<<": ";
        solve();
        cur++;
    }
}

////// Local Template

#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
