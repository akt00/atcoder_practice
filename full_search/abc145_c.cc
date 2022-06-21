#include <iostream>
#include <vector>
#include <cmath>
#include<algorithm>
using namespace std;


inline float dist(int x1, int y1, int x2, int y2) {

    return (float)sqrt(pow(x1 - x2, 2) + pow(y1-y2, 2));
}

int main() {

    int n;
    cin >> n;
    vector<vector<int>> points;

    for (auto i = 0; i < n; i++) {
        vector<int> point(2, 0);
        cin >> point[0];
        cin >> point[1];
        points.push_back(point);
    }

    std::sort(points.begin(), points.end());
    for (auto i : points) {
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    float total_dist = 0;
    int count = 0;
    while (true) {
        count++;
        for (auto i = 0; i < n - 1;i++) {
            total_dist += dist(points[i][0], points[i][1], points[i+1][0], points[i+1][1]);
        }
        if(next_permutation(points.begin(), points.end()) == false) break;
    }
    cout << total_dist / (float)count << endl;
}
