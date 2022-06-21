#include <iostream>
#include <vector>
#include <cmath>
#include<algorithm>
using namespace std;
// permutation full search


double dist(int x1, int y1, int x2, int y2) {

    return sqrt(pow(x1 - x2, 2) + pow(y1-y2, 2));
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
    cout << endl;
    
    double total_dist = 0;
    int count = 0;
    std::sort(points.begin(), points.end());
  
    while (true) {
        cout << ++count << endl;
        for (auto i = 0; i < n - 1;i++) {
            total_dist += dist(points[i][0], points[i][1], points[i+1][0], points[i+1][1]);
        }


        for (auto i : points) {
            for (auto j : i) cout << j << " ";
            cout << endl;
        }
        cout << endl;
        if(next_permutation(points.begin(), points.end()) == false) break;
    }
    cout << "avg total = " << total_dist/6<< endl;
}
