#include <bits/stdc++.h>
using namespace std;

struct Lec {
    string name;
    int room;
    int timeTaken;
    int startTime;
};

class Compare {
    public:
    bool operator() (Lec l1, Lec l2) {
        return l1.timeTaken > l2.timeTaken;
    }
};
class CompareStr {
    public:
    bool operator() (Lec l1, Lec l2) {
        if (strcmp(l1.name.c_str(), l2.name.c_str()) < 0) return true;
        else return false;
    }
};

int main() {
    int n, maxTime; cin >> n >> maxTime;
    vector<pair<string, int>> lectures;
    for (int i = 0; i < n; i++) {
        pair<string, int> p;
        cin >> p.first; cin >> p.second;
        lectures.push_back(p);
    }


    int roomsNeeded = n, l = 0, r = n;
    while (l <= r) {
        int search = (l+r)/2;
        if (search == 0) {
            l = search+1;
            continue;
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < search; i++) {
            pq.push(lectures[i].second);
        }

        int time = 0;
        bool valid = true;

        for (int i = search; i < n; i++) {
            time = pq.top();
            pq.pop();
            pq.push(lectures[i].second+time);
        }
        while (!pq.empty()) {
            time = pq.top();
            pq.pop();
            if (time > maxTime) valid = false;
        }

        if (valid) roomsNeeded = search;
        if (valid) r = search-1;
        else l = search+1;
    }

    priority_queue<Lec, vector<Lec>, Compare> cq;
    vector<Lec> res(0);

    int time = 0;
    for (int i = 0; i < roomsNeeded; i++) {
        Lec l = {lectures[i].first, i, lectures[i].second, time};
        cq.push(l);
    }
    for (int i = roomsNeeded; i < n; i++) {
        int prev = cq.top().timeTaken;
        vector<int> rooms;
        
        while (!cq.empty() && cq.top().timeTaken == prev) {
            Lec l = cq.top();
            time = l.timeTaken;
            cq.pop();

            rooms.push_back(l.room);
            res.push_back(l);
        }
        sort(rooms.begin(), rooms.end());
        for (int j = 0; j < rooms.size() && i+j < n; j++) 
            cq.push({lectures[i+j].first, rooms[j], lectures[i+j].second+time, time});
        i += rooms.size()-1;
    }
    while (!cq.empty()) {
        res.push_back(cq.top());
        cq.pop();
    }
    sort(res.begin(), res.end(), CompareStr());

    cout << roomsNeeded << endl;
    for (int i = 0; i < res.size(); i++) {
        Lec l = res[i];
        cout << l.name << " " << l.room << " " << l.startTime << endl;
    }
    return 0;
}