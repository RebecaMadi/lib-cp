pair<ll,ll> pontos[200002];       
vector<pair<ll,ll>> lower, upper; 
int n;

ll produto_vetorial(pair<ll,ll> a, pair<ll,ll> b, pair<ll,ll> c){
    return (b.first-a.first)*(c.second-a.second) - (b.second-a.second)*(c.first-a.first);
}

void convex_hull(){

    sort(pontos, pontos+n);
    
    // Metade do convex hull a partir do ponto mais à esquerda
    for(int i=0;i<n;i++){
        //                                        penúltio               último                 atual     se "<=" inclui colineares
        while(lower.size()>=2 && produto_vetorial(lower[lower.size()-2], lower[lower.size()-1], pontos[i]) < 0)
            lower.pop_back();
        lower.push_back(pontos[i]);
    }

    // Metade do convex hull a partir do ponto mais à direita
    for(int i=n-1;i>=0;i--){
        while(upper.size()>=2 && produto_vetorial(upper[upper.size()-2], upper[upper.size()-1], pontos[i]) < 0)
            upper.pop_back();
        upper.push_back(pontos[i]);
    }

    // Remove duplicatas
    lower.pop_back();
    upper.pop_back();

    // Junta ambos no mesmo vector
    lower.insert(lower.end(), upper.begin(), upper.end());
}