/** @return a random integer between 0 and INT64_MAX */
ll rng() {
	static std::mt19937 gen(std::chrono::steady_clock::now().time_since_epoch().count());
	return std::uniform_int_distribution<long long>(0, INT64_MAX)(gen);
}

/** @return a random integer between 0 and INT_MAX */
int rng() {
	static std::mt19937 gen(std::chrono::steady_clock::now().time_since_epoch().count());
	return std::uniform_int_distribution<int>(0, INT)(gen);
}

/** @return a random integer between l and r */
int rng(int l, int r) {
	static std::mt19937 gen(std::chrono::steady_clock::now().time_since_epoch().count());
	return std::uniform_int_distribution<int>(l, r)(gen);
}