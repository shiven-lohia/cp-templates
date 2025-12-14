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
