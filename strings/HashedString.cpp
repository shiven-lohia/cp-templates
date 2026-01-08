// choose the base of the polynomial hash randomly
// mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
// const ll B = uniform_int_distribution<ll>(0, M - 1)(rng);
// vector<long long> HashedString::pow = {1};

// for m different strings, use a larger prime modulus such as 2^61-1

class HashedString {
  private:
	static const long long M = 1e9 + 9;
	static const long long B = 9973;
	static vector<long long> pow;
	vector<long long> p_hash;

  public:
	HashedString(const string &s) : p_hash(s.size() + 1) {
		while (pow.size() <= s.size()) { pow.push_back((pow.back() * B) % M); }
		p_hash[0] = 0;
		for (int i = 0; i < s.size(); i++) {
			p_hash[i + 1] = ((p_hash[i] * B) % M + s[i]) % M;
		}
	}

	long long get_hash(int start, int end) {
		long long raw_val = (p_hash[end + 1] - (p_hash[start] * pow[end - start + 1]));
		return (raw_val % M + M) % M;
	}
};
vector<long long> HashedString::pow = {1};

// HashedString hs(s);
// ll hash = hs.get_hash(l,r)