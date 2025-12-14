const ll MAXN = 2000000;
ll spf[MAXN + 1];
vector<ll> primes;

// O(n) build SPF and primes
void sieve() {
    for (ll i = 2; i <= MAXN; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }
        for (ll p : primes) {
            if (i * p > MAXN) break;
            spf[i * p] = p;
            if (p == spf[i]) break; 
        }
    }
}


// O(log n) factorization using SPF
vector<ll> factor(ll n) {
    vector<ll> ret;
    while (n > 1) {
        ll p = spf[n];
        ret.push_back(p);
        n /= p;
    }
    return ret;
}

// O(log n) divisor count using SPF
ll num_divisors(ll x) {
    ll ans = 1;

    while (x > 1) {
        ll p = spf[x];
        ll cnt = 0;
        while (x % p == 0) {
            x /= p;
            cnt++;
        }
        ans *= (cnt + 1);
    }

    return ans;
}

