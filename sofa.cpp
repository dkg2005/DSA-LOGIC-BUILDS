#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <tuple>

using namespace std;

const vector<pair<int, int>> mv = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int x, int y, int r, int c, const vector<vector<char>>& g) {
    return x >= 0 && x < r && y >= 0 && y < c && g[x][y] != 'H';
}

bool canMove(int x1, int y1, int x2, int y2, int r, int c, const vector<vector<char>>& g) {
    return valid(x1, y1, r, c, g) && valid(x2, y2, r, c, g);
}

bool rotSpace(int x, int y, int r, int c, const vector<vector<char>>& g) {
    for (int dx = x; dx < x + 2 && dx < r; ++dx) {
        for (int dy = y; dy < y + 2 && dy < c; ++dy) {
            if (!valid(dx, dy, r, c, g)) return false;
        }
    }
    return x + 1 < r && y + 1 < c;
}

bool atDest(int x1, int y1, int x2, int y2, int gx1, int gy1, int gx2, int gy2) {
    return (x1 == gx1 && y1 == gy1 && x2 == gx2 && y2 == gy2) || 
           (x1 == gx2 && y1 == gy2 && x2 == gx1 && y2 == gy1);
}

int bfs(int x1, int y1, int x2, int y2, int gx1, int gy1, int gx2, int gy2, int r, int c, const vector<vector<char>>& g) {

    queue<tuple<int, int, int, int, int>> q;
    set<pair<pair<int, int>, pair<int, int>>> v;

    q.push({x1, y1, x2, y2, 0});
    v.insert({{x1, y1}, {x2, y2}});

    while (!q.empty()) {
        auto [x1, y1, x2, y2, s] = q.front();
        q.pop();

        if (atDest(x1, y1, x2, y2, gx1, gy1, gx2, gy2)) {
            return s;
        }

        for (const auto& m : mv) {
            int nx1 = x1 + m.first, ny1 = y1 + m.second;
            int nx2 = x2 + m.first, ny2 = y2 + m.second;

            if (canMove(nx1, ny1, nx2, ny2, r, c, g)) {
                pair<pair<int, int>, pair<int, int>> ns = {{nx1, ny1}, {nx2, ny2}};
                if (v.find(ns) == v.end()) {
                    v.insert(ns);
                    q.push({nx1, ny1, nx2, ny2, s + 1});
                }
            }
        }

        bool ha = (x1 == x2), va = (y1 == y2);

        if (ha || va) {
            int bx = min(x1, x2), by = min(y1, y2);

            for (int dx = bx - 1; dx <= bx; ++dx) {
                for (int dy = by - 1; dy <= by; ++dy) {
                    if (rotSpace(dx, dy, r, c, g)) {
                        vector<pair<pair<int, int>, pair<int, int>>> ns;
                        if (ha) {
                            ns.push_back({{dx, dy}, {dx + 1, dy}});
                            ns.push_back({{dx, dy + 1}, {dx + 1, dy + 1}});
                        } else {
                            ns.push_back({{dx, dy}, {dx, dy + 1}});
                            ns.push_back({{dx + 1, dy}, {dx + 1, dy + 1}});
                        }

                        for (const auto& ns2 : ns) {
                            if (v.find(ns2) == v.end() && 
                                canMove(ns2.first.first, ns2.first.second, ns2.second.first, ns2.second.second, r, c, g)) {
                                v.insert(ns2);
                                q.push({ns2.first.first, ns2.first.second, ns2.second.first, ns2.second.second, s + 1});
                            }
                        }
                    }
                }
            }
        }
    }

    return -1;
}

int main() {
    int r, c;
    cin >> r >> c;

    vector<vector<char>> g(r, vector<char>(c));
    int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
    int gx1 = -1, gy1 = -1, gx2 = -1, gy2 = -1;

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> g[i][j];
            if (g[i][j] == 's') {
                if (x1 == -1) {
                    x1 = i;
                    y1 = j;
                } else {
                    x2 = i;
                    y2 = j;
                }
            } else if (g[i][j] == 'S') {
                if (gx1 == -1) {
                    gx1 = i;
                    gy1 = j;
                } else {
                    gx2 = i;
                    gy2 = j;
                }
            }
        }
    }

    int res = bfs(x1, y1, x2, y2, gx1, gy1, gx2, gy2, r, c, g);

    if (res == -1) {
        cout << "Impossible";
    } else {
        cout << res;
    }

    return 0;
}
