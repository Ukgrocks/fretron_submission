/* 3 different set of coordinates of airports for ‘N’ different flights started
from same point of time and place. Draw the flight path for the individual
flights such that there is no intersection of flight paths for safety and
optimization.
For example:
Input :
Flight 1 : 1,1 2,2 3,3
Flight 2 : 1,1 2,4 3,2
Flight 3 : 1,1 4,2 3,4
Output :
Draw the path of all flights in which they had traveled. */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Point {
    int x, y;
};

bool compare(const Point& a, const Point& b) {
    return a.x < b.x;
}

bool isSafe(const vector<Point>& flightPath, Point newPoint) {
    for (int i = 0; i < flightPath.size(); i++) {
        if (flightPath[i].x == newPoint.x && flightPath[i].y == newPoint.y) {
            return false;
        }
    }
    return true;
}

void drawFlightPath(const vector<Point>& flightPath) {
    for (int i = 0; i < flightPath.size(); i++) {
        cout << "(" << flightPath[i].x << ", " << flightPath[i].y << ") ";
    }
    cout << endl;
}

void drawAllFlightPaths(const vector<vector<Point>>& flightPaths) {
    for (int i = 0; i < flightPaths.size(); i++) {
        cout << "Flight " << i + 1 << ": ";
        drawFlightPath(flightPaths[i]);
    }
}

int main() {
    int n;
    cout << "Enter the number of flights: ";
    cin >> n;
    vector<vector<Point>> flightPaths(n);
    for (int i = 0; i < n; i++) {
        int numPoints;
        cout << "Enter the number of points for Flight " << i + 1 << ": ";
        cin >> numPoints;
        flightPaths[i].resize(numPoints);
        cout << "Enter the coordinates of points for Flight " << i + 1 << ":" << endl;
        for (int j = 0; j < numPoints; j++) {
            cin >> flightPaths[i][j].x >> flightPaths[i][j].y;
        }
        sort(flightPaths[i].begin(), flightPaths[i].end(), compare);
    }
    // vector<Point> safePoints;
    // for (int i = 0; i < flightPaths[0].size(); i++) {
    //     bool safe = true;
    //     for (int j = 0; j < n; j++) {
    //         if (!isSafe(flightPaths[j], flightPaths[0][i])) {
    //             safe = false;
    //             break;
    //         }
    //     }
    //     if (safe) {
    //         safePoints.push_back(flightPaths[0][i]);
    //     }
    // }
    cout << "Safe points: ";
    // drawFlightPath(safePoints);
    drawAllFlightPaths(flightPaths);
    return 0;
}

