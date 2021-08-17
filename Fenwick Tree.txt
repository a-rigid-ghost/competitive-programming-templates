// 1-based indexing , fenwick tree for prefix sum
 
struct fen{
    lli n;
    ve B;
    
    fen(lli N){
        n=N;
        B.assign(n+20,0);
    }
    
    void update(lli x, lli val) {
          for(; x <= n; x += x&-x) B[x] += val;
    }
    
    lli query(lli x) {
         lli sum = 0;
         for(; x > 0; x -= x&-x) sum += B[x];
         return sum;
    }
};
