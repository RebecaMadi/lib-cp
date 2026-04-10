// Transforma um vetor sem elementos repetidos em permutação de 1 a n
// Ex: [50, 10, 30] -> [3, 1, 2]
void compress(ll v[]){
    map<ll,ll> id;
    for(int i=0;i<n;i++) id[v[i]]=0;
    ll sz = 0;
    for(auto& [val, rank] : id) rank = sz++;
    for(int i=0;i<n;i++) v[i] = id[v[i]]; 
}
