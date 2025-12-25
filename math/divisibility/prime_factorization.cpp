// O(sqrtN) factorization
vector<ll> factor(ll n) {
    vector<ll> ret;
    while (n % 2 == 0) {
        ret.push_back(2);
        n /= 2;
    }

    for (ll i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            ret.push_back(i);
            n /= i;
        }
    }

    if (n > 1) ret.push_back(n);

    return ret;
}

// O(log n) list all divisors
vll get_divisors(vector<ll> &pf) {
    sort(asc(pf));

    vector<pair<ll,ll>> pf2;
    for(ll p: pf) {
        if(pf2.empty() || pf2.back().F!=p) pf2.pb({p,1});
        else pf2.back().S++;
    }

    vector<ll> divisors = {1};
    
    for(auto [p,e]: pf2) {
        vll add;
        ll cur = 1;
        for(ll ex=1; ex<=e; ex++) {
            cur*=p;
            for(ll d: divisors) add.pb(d*cur);
        }
        divisors.insert(divisors.end(),asc(add));
    }

    sort(asc(divisors));
    return divisors;
}
