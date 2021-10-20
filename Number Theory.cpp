
lli gcd(lli a,lli b){
    if(a>b)swap(a,b);
    if(a==0)return b;
    return gcd(b%a,a);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////

lli phi(lli n) {
    lli res=n,temp=n;
    for(lli i=2;i*i<=n;i++){
        if(temp%i==0){
            while(temp%i==0)temp/=i;
            res=res*(i-1)/i;
        }
    }
    if(temp>1)res=res*(temp-1)/temp;
    return res;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

const lli N=1e7;
lli spf[N+5]={0};
 
void erato(){
    spf[1]=1;
    for(lli i=2;i<N+1;i++){
        if(!spf[i]){
            spf[i]=i;
            for(lli j=i*i;j<N+1;j+=i){
                if(!spf[j])spf[j]=i;    
            }
        }
    }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////

const lli N=3e5+10;
lli mod=998244353;
lli fac[N];
void precomp(lli p=mod){
    fac[0] = 1; 
    fr(i,1,N) fac[i] = fac[i-1]*i%p; 
}

lli power(lli x, lli y, lli p=mod){ 
    lli res = 1;      
    x = x % p;   
    while (y > 0){ 
        if (y & 1) res = (res*x) % p; 
        y = y>>1; 
        x = (x*x) % p; 
    } 
    return res; 
} 
  
lli modinv(lli n, lli p=mod) { 
    return power(n, p-2, p); 
}

lli ncr(lli n, lli r, lli p=mod) 
{ 
    if (r<0 || r>n) return 0;
    if (r==0) return 1;
    return (fac[n]* modinv(fac[r], p) % p * modinv(fac[n-r], p) % p) % p; 
}

///////////pre-computed ncr

const lli N=55;
lli C[N][N];

void precomp()
{   
    for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j <= i; j++) 
        { 
            if (j == 0 || j == i) 
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] +  C[i - 1][j]; 
        } 
    }
}

lli ncr(lli n,lli r){
    if(n<=0 || n<r)return 0;
    else return C[n][r];
}
