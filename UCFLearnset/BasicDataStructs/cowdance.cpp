#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream iFile;
    iFile.open("cowdance.in");

    ofstream oFile;
    oFile.open("cowdance.out");

    int n, t; iFile >> n >> t;
    vector<int> cowDurs;
    for (int i = 0; i < n; i++) {
        int cowDur; iFile >> cowDur;
        cowDurs.push_back(cowDur);
    }

        cout << "Working Fine" << endl;

    int lowestWorking = n+1;
    int l = 0, r = n;
    while (r >= l) {
        int search = (l+r)/2;
        priority_queue <int, vector<int>, greater<int>> minq;

        int timeUsed = 0;
        for (int i = 0; i < search; i++) minq.push(cowDurs[i]);
        
        bool works = true;
        for (int i = search; i < cowDurs.size(); i++) {
            int dur = minq.top();
            timeUsed = dur;

            minq.pop();
            minq.push(cowDurs[i]+timeUsed);
            if (timeUsed > t) works = false;
        }
        while (!minq.empty()) {
            int dur = minq.top();
            timeUsed = dur;
            minq.pop();

            if (timeUsed > t) works = false;
        }

        if (works) lowestWorking = search;

        if (works) r = search-1;
        else l = search+1;
    }

    oFile << lowestWorking << endl;
    oFile.close();
    iFile.close();
}