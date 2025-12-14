//! add modint first
vector<int> derangements(int n) {
    vector<int> ans;
    ans.reserve(n);
    mi a = 1, b = 0;
    ans.push_back(0);

    for (int i = 2; i <= n; i++) {
        mi c = (i - 1) * (a + b);
        ans.push_back((int)c);
        a = b;
        b = c;
    }

    return ans;
}