#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <numeric>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<long> vl;
typedef long long ll;
typedef pair<long long, long long> llll;
typedef vector<long long> vll;
#define matrix(a) vector< vector<a> >
#define sz(a) int((a).size()) 
#define lop(i,a,b) for (int i=a; i<=b; i++)
#define vlop(i,v) lop(i,0,sz(v)-1)
#define vlop1(i,v) lop(i,1,sz(v)-1)
#define rlop(i,a,b) for (int i=b; i>=a; i--)
#define vrlop(i,v) rlop(i,0,sz(v)-1)
#define vrlop1(i,v) rlop(i,1,sz(v)-1)
#define printv(i,v) vlop(i,v)cout<<v[i]<<" "
#define all(s) (s).begin(),(s).end()
#define isthere(c,x) ((c).find(x) != (c).end()) 
#define cisthere(c,x) (find(all(c),x) != (c).end())
#define pb push_back
#define enter cout<<'\n'

void dfs(matrix(int)& alist, vi& tour, int root, vi& entry, vi& leave, vi& visited) {
	visited[root] = 1;
	tour.pb(root);
	entry[root] = sz(tour) - 1;
	for(auto child: alist[root]) {
		if (!visited[child]) {
			dfs(alist, tour, child, entry, leave, visited);
			tour.pb(root);
		}
	}
	leave[root] = sz(tour) - 1;
	return;
}

int main() {
	int n;
	matrix(int) alist(n + 1);
	vi tour; /*Eulerian tour*/
	vi entry(n + 1); /*first time Euler tour reaches node i*/
	vi leave(n + 1); /*first time dfs finishes all search in i's descendent tree in Euler tour*/
	vi visited(n + 1, 0);
	dfs(alist, tour, 1, entry, leave, visited);
	return 0;
}
