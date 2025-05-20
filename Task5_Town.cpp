#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 200005

vector<pair<int, int>> gr[MAX];

int n = 0, d[MAX];

void bfs01(int s, int t){
    for(int i=1; i<=n;++i) d[i] = INT32_MAX / 2;
    
    deque<pair<int, int>> dq;
    
    d[s] = 0;
    dq.push_back({s,0});

    while(!dq.empty()){
        int curr = dq.front().first;
        int w = dq.front().second;
        dq.pop_front();

        if(d[curr] < w) continue;
        
        for(auto u : gr[curr]){
            if(d[u.first] > u.second + d[curr]){
                d[u.first] = u.second + d[curr];
                
                if(u.second == 0) dq.push_front({u.first, d[u.first]});
                else dq.push_back({u.first, d[u.first]});
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int from, to;
    cin>> n>>from>>to;
    int u, v;
    while((cin>> u >> v)){
        gr[u].push_back({v, 0});
        gr[v].push_back({u, 1});
    }

    bfs01(from, to);
    if (d[to] == INT32_MAX / 2) cout << "X\n";
    else
        cout << d[to] << endl;
}