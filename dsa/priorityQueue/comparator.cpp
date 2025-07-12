
struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second; // min-heap based on second
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;