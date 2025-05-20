#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 1100

int N =0, M=0, u = 0, v =0, w=0, res[MAX], s=0, d[MAX];
vector<pair<int, int>> gr[MAX];

priority_queue<pair<int, int>, vector<pair<int, int>>> pq;

bool visited[MAX];

void dijkstra(int node){
    for(int i=0;i<N;++i)  d[i]= INT16_MAX/2;

    d[node] = 0;
    pq.push({0, node});

    while (!pq.empty())
    {
        node = pq.top().second;
        pq.pop();

        if(visited[node]) continue;

        visited[node] = true;

        for(auto p : gr[node]){
            if(d[p.first] > d[node] + p.second){
                d[p.first] =  d[node] + p.second;
                pq.push({d[p.first], p.first});
            }
        }
    }

    for(int i = 0; i < N; i++)cout << d[i] << " " ;
	cout << endl;
	
	return;
}



int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;

    for(int i=0;i<M;++i){
        cin>> u >> v>> w;
        gr[u].push_back({v, w});
        gr[v].push_back({u, w});
    }

    cin>>s;

    dijkstra(s);
}