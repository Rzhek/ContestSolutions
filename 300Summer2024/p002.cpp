#include <bits/stdc++.h>
using namespace std;


double minAngleDistance(int ang1, int ang2) {
    int maxAng = max(ang1, ang2), minAng = min(ang1, ang2);
    return min(maxAng-minAng, 360+(minAng-maxAng));
}

double shortestDis(int startIdx, int startAngle, int destIdx, int destAngle, vector<vector<vector<int>>> &adjList, vector<int> &radii) {
    if (startIdx == destIdx) {
        int move = minAngleDistance(startAngle, destAngle);
        return (move*2*M_PI*radii[startIdx]/360.0);
    } 
    
    double minimum = 1e9;
    for (int i = 0; i < adjList[startIdx].size(); i++) {
        if ((adjList[startIdx][i][0] > startIdx && startIdx < destIdx) || (adjList[startIdx][i][0] < startIdx && startIdx > destIdx)) {
            int move = minAngleDistance(adjList[startIdx][i][1], startAngle);
            double timeTo = (move*2*M_PI*radii[startIdx]/360.0)+adjList[startIdx][i][2];
            minimum = min(timeTo+shortestDis(adjList[startIdx][i][0], adjList[startIdx][i][1], destIdx, destAngle, adjList, radii), minimum);
        }
    }
    return minimum;
}

int main() {
    int t; cin >> t;
    cout << fixed << setprecision(2);
    while (t--) {
        int c, r; cin >> c >> r;
        vector<int> radii(c);
        for (int i = 0; i < c; i++) cin >> radii[i];

        vector<vector<vector<int>>> adjList(c);
        for (int i = 0; i < r; i++) {
            int idx, angle; cin >> idx >> angle; //1 based idx
            adjList[idx-1].push_back({idx, angle, radii[idx]-radii[idx-1]});
            adjList[idx].push_back({idx-1, angle, radii[idx]-radii[idx-1]});
        }
        int startIdx, startAngle; cin >> startIdx >> startAngle; //1 based idx
        int destIdx, destAngle; cin >> destIdx >> destAngle; //1 based idx
        cout << shortestDis(startIdx-1, startAngle, destIdx-1, destAngle, adjList, radii) << endl;
    }
    return 0;
}