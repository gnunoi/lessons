#include <iostream>
#include <cmath>

using namespace std;

struct Position {
    int x;
    int y;
    bool marked;
};

double distance(Position p1, Position p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y))    
}

int main()
{
    int n = 0, k = 0, T = 0;
    Position p[1001];
    cin >> n >> k >> T;

    for(int i = 1; i <= n; i++){
        cin >> p[i].x >> p[i].y;
    }

    for(int i = 1; i <= k; i++){
        
    }
    return 0;
}