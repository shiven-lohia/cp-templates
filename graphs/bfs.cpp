function<void(int)> bfs = [&](int i) {
    queue<int> q;
    vector<int> visited(n);
    visited[i] = true;
    q.push(i);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto next : adj[cur]) {
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
};
