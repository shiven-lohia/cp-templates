ll inv[mod];
inv[1] = 1;
for (ll i = 2; i < mod; i++) { inv[i] = mod - mod / i * inv[mod % i] % mod; }