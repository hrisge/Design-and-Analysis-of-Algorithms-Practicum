#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 100024

int N = 0, M = 0, x = 0, y =0, t = 0, K = 0, d[MAX], Q = 0;

vector<pair<int, int>> gr[MAX];

bool used[MAX];

priority_queue<pair<int, int>> pq;
queue<int> q;

void dijkstra(int from){
    fill(d, d + N + 2, INT32_MAX);
    d[from] = 0;
    pq.push({-d[from], from});
    int node, u, w;

    while(!pq.empty()){
        node = pq.top().second;
        pq.pop();
        
        if(used[node]) continue;

        used[node] = true;

        for(auto p : gr[node]){
            u = p.first;
            w = p.second;

            if(d[u] > d[node] + w){
                d[u] = d[node] + w;
                pq.push({-d[u], u});
            }
        }
    }

    return;

}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

    cin>>N>>M;
    for(int i=0;i<M;++i){
        cin>>x>>y>>t;
        gr[x].push_back({y, t});
        gr[y].push_back({x, t});
    }

    cin>>K;
    for(int i=0;i<K;++i){
        cin>>x;
        gr[N].push_back({x, 0});
    }

    dijkstra(N);

    cin >> 	Q;
	for(int i = 0; i < Q; i++){
		cin >> x;
        q.push(x);
	}

    while(!q.empty()){
        x = q.front();
        q.pop();
        cout << d[x] << endl;
    }
}