// -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE
// Use an algorihtm similar to Floyd-Warshall to compute the result.
#include <cassert>

#include <algorithm> // std::min, std::max
#include <array>
#include <iostream>
#include <limits> // std::numeric_limits

using namespace std;
// The problem states that N <= 100
static constexpr int N = 101;
using Graph = array<array<int, N>, N>;

static inline int floyd_warshall(Graph& c, int n, int src, int dest, int tourist) {
    for(int k = 1; k <= n; ++k) {
        for(int from = 1; from <= n; ++from) {
            for(int to = 1; to <= n; ++to) {
                c[from][to] = max(c[from][to], min(c[from][k], c[k][to]));
            }
        }
    }
    // let y = c[from][to] - 1 => include the tourist guide in each
    //                                   trip
    // (x + y - 1) / y + 1  => a trick to round up to the nearest integer
    const int y = c[src][dest] - 1;
    return (tourist + y - 1) / y;
}

int main() {

    int n = 0;
    int r = 0;
    int scenario = 1;

    cin >> n >> r;
    while(n != 0 && r != 0) {
        // undirected graph
        Graph graph {{{}}};
        for(int i = 0; i < r; ++i) {
            int c1, c2, p;
            cin >> c1 >> c2 >> p;
            graph[c1][c2] = graph[c2][c1] = p;
        }
        int s = 0, d = 0, t = 0;
        cin >> s >> d >> t;
        cout << "Scenario #" << scenario << endl;
        cout << "Minimum Number of Trips = ";
        cout << floyd_warshall(graph, n, s, d, t) << endl << endl;
        cin >> n >> r;
        ++scenario;
    }
    return 0;
}
