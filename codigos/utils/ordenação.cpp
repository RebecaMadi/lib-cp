bool comp(pair<int, pii> a, pair<int, pii> b)
{
    if(a.fr > b.fr) return true;
    else if(a.fr == b.fr && a.sc.fr < b.sc.fr) return true;
    else return false;
}

// sort(v.begin(), v.end(), comp);