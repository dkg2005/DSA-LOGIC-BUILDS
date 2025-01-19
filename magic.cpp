#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, n) for (lli i = (a); i < (n); ++i)
#define loopD(i, a, n) for (lli i = (a); i >= (n); --i)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define sz(a) ((lli)a.size())
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define endl '\n'
#define fastio std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pb push_back
#define pp pop_back()
#define fi first
#define si second
#define v(a) vector<int>(a)
#define vv(a) vector<vector<int>>(a)
#define present(c, x) ((c).find(x) != (c).end())
#define set_bits __builtin_popcountll
#define MOD 1000000007
#define int long long

typedef long long lli;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<lli, lli> pll;
typedef pair<int, int> pii;
typedef unordered_map<int, int> umpi;
typedef map<int, int> mpi;
typedef vector<pii> vp;
typedef vector<lli> vll;
typedef vector<vll> vvll;

struct Segment {
    int xStart, yStart, xEnd, yEnd;

    bool isVertical() const { return xStart == xEnd; }
    bool isHorizontal() const { return yStart == yEnd; }
    bool isDiagonal() const { return abs(xEnd - xStart) == abs(yEnd - yStart); }
};

int numSegments, K;
vector<Segment> segments;
map<pair<int, int>, vector<int>> pointMap;

void addSegment(const Segment& segment, int idx) {
    int xStart = segment.xStart, yStart = segment.yStart;
    int xEnd = segment.xEnd, yEnd = segment.yEnd;

    if (segment.isVertical()) {
        int yMin = min(yStart, yEnd), yMax = max(yStart, yEnd);
        for (int y = yMin; y <= yMax; y++) {
            pointMap[{xStart, y}].push_back(idx);
        }
    } else if (segment.isHorizontal()) {
        int xMin = min(xStart, xEnd), xMax = max(xStart, xEnd);
        for (int x = xMin; x <= xMax; x++) {
            pointMap[{x, yStart}].push_back(idx);
        }
    } else if (segment.isDiagonal()) {
        int steps = abs(xEnd - xStart);
        int dx = (xEnd - xStart) / steps, dy = (yEnd - yStart) / steps;
        for (int i = 0; i <= steps; i++) {
            int x = xStart + i * dx, y = yStart + i * dy;
            pointMap[{x, y}].push_back(idx);
        }
    }
}

int calculateDistance(int x1, int y1, int x2, int y2) {
    if (x1 == x2) return abs(y1 - y2);
    if (y1 == y2) return abs(x1 - x2);
    if (abs(x1 - x2) == abs(y1 - y2)) return abs(x1 - x2);
    return 0;
}

int findMinDistance(const pair<int, int>& point, const vector<int>& segmentIndexes) {
    vector<int> distances;
    for (auto segmentIdx : segmentIndexes) {
        const Segment& seg = segments[segmentIdx];
        bool isEndPoint = (point.first == seg.xStart && point.second == seg.yStart) || 
                          (point.first == seg.xEnd && point.second == seg.yEnd);

        if (isEndPoint) {
            int xOther = (point.first == seg.xStart && point.second == seg.yStart) ? seg.xEnd : seg.xStart;
            int yOther = (point.first == seg.xStart && point.second == seg.yStart) ? seg.yEnd : seg.yStart;
            distances.push_back(calculateDistance(point.first, point.second, xOther, yOther));
        } else {
            distances.push_back(calculateDistance(point.first, point.second, seg.xStart, seg.yStart));
            distances.push_back(calculateDistance(point.first, point.second, seg.xEnd, seg.yEnd));
        }
    }
    return distances.empty() ? 0 : *min_element(distances.begin(), distances.end());
}

void processSegments() {
    cin >> numSegments;
    segments.resize(numSegments);
    for (int i = 0; i < numSegments; i++) {
        cin >> segments[i].xStart >> segments[i].yStart >> segments[i].xEnd >> segments[i].yEnd;
        addSegment(segments[i], i);
    }
    cin >> K;

    int totalDistance = 0;
    for (auto& [point, segmentIndexes] : pointMap) {
        if (sz(segmentIndexes) == K) {
            totalDistance += findMinDistance(point, segmentIndexes);
        }
    }
    cout << totalDistance;
}

int32_t main() {
    fastio
    processSegments();
    return 0;
}