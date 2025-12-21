#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x, y;
    double g, h, f;
    shared_ptr<Node> parent;

    Node(int x, int y, shared_ptr<Node> parent = nullptr) 
        : x(x), y(y), parent(parent), g(0), h(0), f(0) {}
  // Comparison operator for the priority queue (min-heap)
    bool operator>(const Node& other) const { return f > other.f; }
};

class Heuristics {
public:
    // Best for grid movement (4 directions: Up, Down, Left, Right)
    static double manhattan(int x1, int y1, int x2, int y2) {
        return abs(x1 - x2) + abs(y1 - y2);
    }

    // Best for any-angle or diagonal movement
    static double euclidean(int x1, int y1, int x2, int y2) {
        return sqrt(pow(x1 - x2, 2) + pow(x1 - x2, 2));
    }
};

class AStarSearch {
private:
    int rows, cols;
    vector<vector<int>> grid;

public:
    AStarSearch(vector<vector<int>> g) : grid(g) {
        rows = g.size();
        cols = g[0].size();
    }

    void findPath(pair<int, int> start, pair<int, int> goal) {
        auto cmp = [](shared_ptr<Node> a, shared_ptr<Node> b) { return a->f > b->f; };
        priority_queue<shared_ptr<Node>, vector<shared_ptr<Node>>, decltype(cmp)> openList(cmp);
        
        vector<vector<bool>> closedList(rows, vector<bool>(cols, false));

        auto startNode = make_shared<Node>(start.first, start.second);
        startNode->h = Heuristics::manhattan(start.first, start.second, goal.first, goal.second);
        startNode->f = startNode->g + startNode->h;
        
        openList.push(startNode);

        while (!openList.empty()) {
            shared_ptr<Node> current = openList.top();
            openList.pop();

            if (current->x == goal.first && current->y == goal.second) {
                printPath(current);
                return;
            }

            closedList[current->x][current->y] = true;

            // Neighbors: Up, Down, Left, Right
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};

            for (int i = 0; i < 4; i++) {
                int nx = current->x + dx[i];
                int ny = current->y + dy[i];

                if (isValid(nx, ny) && !closedList[nx][ny] && grid[nx][ny] == 0) {
                    auto neighbor = make_shared<Node>(nx, ny, current);
                    neighbor->g = current->g + 1;
                    neighbor->h = Heuristics::manhattan(nx, ny, goal.first, goal.second);
                    neighbor->f = neighbor->g + neighbor->h;
                    openList.push(neighbor);
                }
            }
        }
        cout << "Goal unreachable." << endl;
    }

private:
    bool isValid(int x, int y) {
        return (x >= 0 && x < rows && y >= 0 && y < cols);
    }

    void printPath(shared_ptr<Node> target) {
        vector<pair<int, int>> path;
        while (target) {
            path.push_back({target->x, target->y});
            target = target->parent;
        }
        reverse(path.begin(), path.end());
        
        cout << "Optimal Path: ";
        for (auto p : path) cout << "(" << p.first << "," << p.second << ") ";
        cout << endl;
    }
};

int main() {
    // 0 = Walkable, 1 = Wall
    vector<vector<int>> map = {
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    AStarSearch solver(map);
    
    pair<int, int> startPos = {0, 0};
    pair<int, int> goalPos = {4, 4};

    cout << "Starting A* Search..." << endl;
    solver.findPath(startPos, goalPos);

    return 0;
}

