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
typedef long long ll;
typedef pair<long long, long long> l4;
typedef vector<long long> vll;
typedef double db;
typedef vector<double> vdb;
typedef pair<double, double> dd;
typedef set<int> si;
typedef set<long long> sll;
#define fi first
#define se second
#define matrix(a) vector< vector<a> >
#define sz(a) int((a).size()) 
#define lop(i,a,b) for (int i=a; i<=b; i++)
#define vlop(i,v) lop(i,0,sz(v)-1)
#define vlop1(i,v) lop(i,1,sz(v)-1)
#define rlop(i,a,b) for (int i=b; i>=a; i--)
#define vrlop(i,v) rlop(i,0,sz(v)-1)
#define vrlop1(i,v) rlop(i,1,sz(v)-1)
#define printv(i,v) vlop(i,v)cout<<v[i]<<" "
#define printv1(i,v) vlop1(i,v)cout<<v[i]<<" "
#define all(s) (s).begin(),(s).end()
#define pb push_back
#define enter cout<<'\n'
#define lb(i,v) int(lower_bound(all(v),i)-v.begin())
#define ub(i,v) int(upper_bound(all(v),i)-v.begin())
int n0,n1,n,m;
int tonode(int i, int j) {
	return (i - 1)*m + j;
}

int main() {
	/*turn a grid with row 1,...,n, coloumn 1,...,m into an undirected graph where two adjacent grid are connected
	iff both are marked zero*/
	matrix(int) alist(n*m + 1),grid(n+2,vi(m+2));
	lop(i, 1, n ) {
		lop(j, 1, m ) {
			if (!grid[i][j]) {
				n0 = tonode(i, j, m);
				if (!grid[i - 1][j]&&i-1>=1) {
					int n1 = tonode(i - 1, j, m);
					alist[n1].pb(n0);
					alist[n0].pb(n1);
				}
				if (!grid[i + 1][j]&&i+1<=n) {
					int n1 = tonode(i + 1, j, m);
					alist[n1].pb(n0);
					alist[n0].pb(n1);
				}
				if (!grid[i][j - 1]&&j-1>=0) {
					int n1 = tonode(i, j - 1, m);
					alist[n1].pb(n0);
					alist[n0].pb(n1);
				}
				if (!grid[i][j + 1]&&j+1<=m) {
					int n1 = tonode(i, j + 1, m);
					alist[n1].pb(n0);
					alist[n0].pb(n1);
				}
			}
		}
	}
}
