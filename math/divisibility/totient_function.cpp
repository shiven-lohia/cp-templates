// O(sqrtN) phi value
int phi(int n) {
	int ans = n;
	for (int p = 2; p * p <= n; p++) {
		if (n % p == 0) {
			while (n % p == 0) { n /= p; }
			ans -= ans / p;
		}
	}
	if (n > 1) { ans -= ans / n; }
	return ans;
}

// O(nlognlogn) all phi values
int MAXN = 2000001;
int phi[MAXN+1];

void precompute_phi() {
	for (int i = 1; i < MAXN; i++) { phi[i] = i; }
	for (int i = 2; i < MAXN; i++) {
		if (phi[i] == i) {
			for (int j = i; j < MAXN; j += i) { phi[j] -= phi[j] / i; }
		}
	}
}