//! run spf first
vector<ll> max_exp(MAXN+1, 0);

// add a number to the LCM
void add_to_lcm(ll x) {
    while (x > 1) {
        ll p = spf[x];
        ll cnt = 0;
        while (x % p == 0) x /= p, cnt++;
        max_exp[p] = max(max_exp[p], cnt);
    }
}

// get LCM % mod
ll mod_lcm() {
    ll ans = 1;
    for (ll p = 2; p <= MAXN; p++) {
        if (max_exp[p]) {
            ans = ans * power(p, max_exp[p]) % mod;
        }
    }
    return ans;
}
