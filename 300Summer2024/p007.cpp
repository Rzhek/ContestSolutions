#include <bits/stdc++.h>
using namespace std;

#define BOARDSIZE 6
using pii = pair<int, int>;
using board = tuple<pii, pii, pii, pii>;
map<board, board> visited;

vector<pii> boardToVec(board &tup) {
    auto [a, b, c, d] = tup;
    vector<pii> vec = {a, b, c, d};
    return vec;
}

board sortBoard(board tup) {
    vector<pii> vec = boardToVec(tup);
    sort(vec.begin(), vec.end(), [](pii a, pii b){
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });
    return {vec[0], vec[1], vec[2], vec[3]};
}

vector<int> findDiff(board &parent, board &child) {
    vector<pii> pV = boardToVec(parent), cV = boardToVec(child);
    for (int i = 0; i < pV.size(); i++) {
        for (int j=0; j < cV.size(); j++) {
            if (pV[i].first == cV[j].first && pV[i].second == cV[j].second) {
                pV.erase(pV.begin()+i--);
                cV.erase(cV.begin()+j);
                break;
            }
        }
    }
    if (pV.size() == 1 && cV.size() == 1) return {cV[0].first, cV[0].second, pV[0].first, pV[0].second};
    return {-1, -1, -1, -1};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    vector<pii> sCheckers(4, {0, 0});
    vector<pii> dCheckers(4, {0, 0});
    for (int i = 0; i < 4; i++) cin >> sCheckers[i].first >> sCheckers[i].second;
    for (int i = 0; i < 4; i++) cin >> dCheckers[i].first >> dCheckers[i].second;

    board source(sCheckers[0], sCheckers[1], sCheckers[2], sCheckers[3]);
    board dest(dCheckers[0], dCheckers[1], dCheckers[2], dCheckers[3]);
    source = sortBoard(source);
    dest = sortBoard(dest);

    int res = 0;
    queue<pair<board, pair<board, int>>> q;
    q.push({source, {source, 0}});

    while (!q.empty()) {
        pair<board, pair<board, int>> abc = q.front();
        q.pop();

        board cur = abc.first;

        board prevBoard = abc.second.first;
        int cRes = abc.second.second;

        if (visited.find(cur) != visited.end()) continue;
        visited[cur] = prevBoard;

        if (cur == dest) {
            res = cRes;
            break;
        }

        vector<pii> vec = boardToVec(cur), vecCopy = boardToVec(cur);
        for (int i = 0; i < 4; i++) {
            pii checker = vec[i];
            int up = 0, right = BOARDSIZE-1, left = 0, down = BOARDSIZE-1;
            for (int j = 0; j < 4; j++) {
                if (i == j) continue;
                pii oChecker = vec[j];
                
                if (checker.first == oChecker.first) { //Same row
                    if (oChecker.second < checker.second) left = max(left, oChecker.second+1); //Checker blocks left
                    else if (oChecker.second > checker.second) right = min(right, oChecker.second-1); //Checker blocks right
                } else if (checker.second == oChecker.second) { //Same col
                    if (oChecker.first < checker.first) up = max(up, oChecker.first+1); //Checker blocks top
                    else if (oChecker.first > checker.first) down = min(down, oChecker.first-1); //Checker blocks bottom
                }
            }

            vector<int> directions = {up, right, left, down};
            board newSource;
            for (int j = 0; j < 4; j++) {
                switch(j) {
                    case 0:
                    case 3:
                        vec[i] = {directions[j], checker.second};
                    break;
                    case 1:
                    case 2: 
                        vec[i] = {checker.first, directions[j]};
                    break;
                }
                newSource = sortBoard({vec[0], vec[1], vec[2], vec[3]});
                if (newSource == cur) continue;
                q.push({newSource, {cur, cRes+1}});
            }
            vec[i] = vecCopy[i];
        }
    }     
    cout << res << "\n";
    
    board target = dest;
    vector<vector<int>> moves;
    while (res--) {
        moves.push_back(findDiff(target, visited[target]));
        target = visited[target];
    }
    for (int i = moves.size()-1; i >= 0; i--) {
        for (int j = 0; j < 4; j++) cout << moves[i][j] << " ";
        cout << "\n";
    }
    return 0;
}