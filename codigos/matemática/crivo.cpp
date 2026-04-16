int sieve[N];
 
vi primes;

// O(n log logn)
void sv(){
    for(int x=2;x<=N;x++){
        if(sieve[x])    continue;
 
        for(int i=2*x;i<=N;i+=x){
            sieve[i] = x;
        }
    }
 
    for(int x=2;x<=N;x++){
        if(sieve[x]==0) primes.pb(x);
    }
}
