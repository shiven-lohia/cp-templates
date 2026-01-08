// finds the minimum of a unimodal function on interval [l,r]
template <typename F> double find_min(double l, double r, double eps, const F &f) {
	while (r - l > eps) {
		double m1 = l + (r - l) / 3;
		double m2 = r - (r - l) / 3;
		f(m1) > f(m2) ? l = m1 : r = m2;
	}

	return l;
}

// auto f = [](double x) {
//     return (x - 3) * (x - 3) + 5;
// };

// double x_min = find_min(-100, 100, 1e-9, f);