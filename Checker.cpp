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
#define INF             (lli)4e18

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}

//-----------------------------------------CODE_BEGINS----------------------------//

////brute force calculation

lli ans=INF;

lli calc(ve &a){
    lli n=a.size();
    lli cur=LLONG_MAX,sum=0;
    for(auto e:a){
        cur=(cur&e);
        sum+=cur;
    }
    return sum;
}

void perm(ve &a,lli idx){
    lli n=a.size();
    if(idx==n){
        ans=min(ans,calc(a));
        return;
    }
    for(int i=idx;i<n;i++){
        swap(a[i],a[idx]);
        perm(a,idx+1);
        swap(a[i],a[idx]);
    }
}

lli brute(ve &a){
    ans=INF;
    perm(a,0);
    return ans;
}

////my approach calculation

lli mysol(ve &a){
    lli n=a.size();
    lli cur=LLONG_MAX,sum=0;
    multiset<lli> s;
    for(auto e:a)s.insert(e);
    while(!s.empty()){
        lli tmp=*s.begin();
        s.erase(s.begin());
        sum+=tmp;
        cur=(cur&tmp);
        multiset<lli> xx;
        for(auto e:s) xx.insert((e&cur));
        s=xx;
    }
    return sum;
}

//////driver functions

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
lli random_long(lli l = 0,lli r = 10){
    uniform_int_distribution<int64_t> generator(l,r);
    return generator(rng);
}

ve genarr(lli n){
    ve v;
    fr(i,0,n) v.pb(random_long());
    return v;
}

int main() {
    lli iter=100;
    lli n=9;
    fr(i,0,iter){
        ve a=genarr(n);
        lli ans1=brute(a);
        lli ans2=mysol(a);
        if(ans1!=ans2){
            cout<<"FOUND COUNTER"<<endl;
            parr(a,0,n);
            trace(ans1,ans2);
            break;
        }
    }
    cout<<"DONE!";
}
