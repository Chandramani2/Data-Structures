#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

struct Node {
    int x, y;
    double g, h, f;
    Node* parent;

    Node(int x, int y, Node* parent = nullptr) 
        : x(x), y(y), parent(parent), g(0), h(0), f(0) {}

    // Comparison operator for the priority queue (min-heap)
    bool operator>(const Node& other) const {
        return f > other.f;
    }
};

double calculateHeuristic(int x1, int y1, int x2, int y2) {
    // Using Euclidean distance: sqrt((x2-x1)^2 + (y2-y1)^2)
    return std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
}

void aStar(int grid[5][5], std::pair<int, int> start, std::pair<int, int> goal) {
    int rows = 5;
    int cols = 5;

    // Open list: stores nodes to be visited, sorted by lowest f value
    auto cmp = [](Node* left, Node* right) { return left->f > right->f; };
    std::priority_queue<Node*, std::vector<Node*>, decltype(cmp)> openList(cmp);

    // Track visited nodes
    std::vector<std::vector<bool>> closedList(rows, std::vector<bool>(cols, false));

    // Initialize start node
    Node* startNode = new Node(start.first, start.second);
    startNode->h = calculateHeuristic(start.first, start.second, goal.first, goal.second);
    startNode->f = startNode->g + startNode->h;
    openList.push(startNode);

    while (!openList.empty()) {
        Node* current = openList.top();
        openList.pop();

        // If goal reached, reconstruct path
        if (current->x == goal.first && current->y == goal.second) {
            std::cout << "Path found: ";
            while (current) {
                std::cout << "(" << current->x << "," << current->y << ") ";
                current = current->parent;
            }
            return;
        }

        closedList[current->x][current->y] = true;

        // Explore 4 neighbors (Up, Down, Left, Right)
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int newX = current->x + dx[i];
            int newY = current->y + dy[i];

            // Boundary and obstacle check (0 = walkable, 1 = obstacle)
            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols &&
                grid[newX][newY] == 0 && !closedList[newX][newY]) {
                
                Node* neighbor = new Node(newX, newY, current);
                neighbor->g = current->g + 1;
                neighbor->h = calculateHeuristic(newX, newY, goal.first, goal.second);
                neighbor->f = neighbor->g + neighbor->h;

                openList.push(neighbor);
            }
        }
    }
    std::cout << "No path found." << std::endl;
}

int main() {
    // 0 = Empty, 1 = Wall
    int grid[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    std::pair<int, int> start = {0, 0};
    std::pair<int, int> goal = {4, 4};

    aStar(grid, start, goal);

    return 0;
}