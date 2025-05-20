#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 10100

int n = 0 , m = 0, a = 0, b= 0, d[MAX];
vector<int> gr[MAX], ans;
priority_queue<int, vector<int>, greater<int>> pq;

void topo(){
    for(int i = 1; i <= n; i++)
	{
		if(d[i] == 0)pq.push(i);
	}

    while(!pq.empty()){
        int node = pq.top();
        pq.pop();

        ans.push_back(node);
        for(auto u : gr[node]){
            --d[u];
            if(d[u] == 0) pq.push(u);
        }
    }

    if(ans.size() == n){
        for(auto x : ans) cout<< x << " ";
        cout<< endl;
    }
    else {
        cout<< "Sandro fails."<<endl;
    }

    return;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b;
		gr[a].push_back(b);
		d[b]++;
	}
	
	topo();
	
	return 0;
}