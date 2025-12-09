vector<ll> dist(n, LLONG_MAX);

function<void(ll)> dijkstra = [&](ll source) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    dist[source] = 0; pq.push({0, source});

    while (!pq.empty()) {
        ll cur_dist = pq.top().F;
        ll cur = pq.top().S;
        pq.pop();

        if (cur_dist > dist[cur]) continue;

        for (auto &e : adj[cur]) {
            ll next = e.F;
            ll w = e.S;

            if (dist[cur] < dist[next] - w) {
                dist[next] = dist[cur] + w;
                pq.push({dist[next], next});
            }
        }
    }
};