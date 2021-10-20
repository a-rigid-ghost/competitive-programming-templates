///Sparse table struct - there are 2 types of queries, use only one

struct SparseTable{
    lli N,K;
    vector<ve> table;
    ve logtwo;
    
    ///change the function accordingly
    lli f(lli a,lli b){
        return min(a,b);
    }
    
    ///constructor
    SparseTable(ve a){
        N=sz(a);
        K=log2(N)+2;
        table=vector<ve>(N,ve(K));
        logtwo=ve(N+5);
        
        ///computing logarithms of 2 and building the table
        logtwo[1]=0;
        fr(i,2,N+1){
            logtwo[i]=logtwo[i/2]+1;
        }
        frx(i,N-1,-1){
            table[i][0]=a[i];
            for(lli j=1;i+(1LL<<j)-1<N;j++){
                table[i][j]=f(table[i][j-1],table[i+(1LL<<(j-1))][j-1]);
            }
        }
    }
    
    ///O(logn) query
    lli query(lli l,lli r){
        lli ans=1e18;  ///initialize with a useless value
        lli curl=l;
        while(curl<=r){
            lli temp=logtwo[r-curl+1];
            ans=f(ans,table[curl][temp]);
            curl+=(1LL<<temp);
        }
        return ans;
    }
    
    ///O(1) query, only for idempotent operators
    lli query(lli l,lli r){
        lli temp=logtwo[r-l+1];
        lli ans=f(table[l][temp],table[r-(1LL<<temp)+1][temp]);
        return ans;
    }
};


//////////////Trie Array Implementation

const lli N=30*1e6;
lli nxt[N+10][2],cnt[N+10][2];
 
struct bTrie{
    lli ptr=0;
    
    void add(lli x){
        lli id=0;
        frx(i,29,-1){
            lli b=(x&(1LL<<i))?1:0;
            if(nxt[id][b]==-1)nxt[id][b]=++ptr;
            cnt[id][b]++;
            id=nxt[id][b];
        }
    }
    
    lli query(lli x,lli k){
        lli ans=0,id=0;
        frx(i,29,-1){
            lli bx=(x&(1LL<<i))?1:0;
            lli bk=(k&(1LL<<i))?1:0;
            if(id==-1)break;
            if(bx==0 && bk==0){
                ans+=cnt[id][1];
                id=nxt[id][0];
            }
            else if(bx==0 && bk==1){
                id=nxt[id][1];
            }
            else if(bx==1 && bk==0){
                ans+=cnt[id][0];
                id=nxt[id][1];
            }
            else{
                id=nxt[id][0];
            }
        }
        return ans;
    }
};

//////////Trie Pointer Implementation

struct node {
	node *nxt[2];
	int cnt=0;
};

struct Trie{
    node *head;
    
    Trie(){
        head=new node();
    }
    
    void add(int x){
        node *cur=head;
        for(int i=29;i>-1;i--){
            int bx=(x>>i)&1;
            if(cur->nxt[bx]==NULL) cur->nxt[bx]=new node();
            cur=cur->nxt[bx];
            (cur->cnt)++;
        }
    }
    
    void rem(int x){
        node *cur=head;
        for(int i=29;i>-1;i--){
            int bx=(x>>i)&1;
            cur=cur->nxt[bx];
            (cur->cnt)--;
        }
    }
    
    int query(int x,int k){
        node *cur=head;
        int ans=0;
        for(int i=29;i>-1;i--){
            if(cur==NULL)break;
            int bx=(x>>i)&1,bk=(k>>i)&1;
            if(bk==0){
                int tmp=bx^1;
                if(cur->nxt[tmp]!=NULL) ans+=(cur->nxt[tmp]->cnt);
                cur=cur->nxt[bx];
            }
            else{
                int tmp=bx^1;
                cur=cur->nxt[tmp];
            }
        }
        return ans;
    }
};
