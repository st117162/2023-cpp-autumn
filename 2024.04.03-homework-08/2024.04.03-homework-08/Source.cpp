#include <iostream>

class CGraph {
public:
    void ReadEdges(int n);
    int CountRoads(int n);

private:
    int matrix[100][100];
};

void CGraph::ReadEdges(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }
}

int CGraph::CountRoads(int n) {
    int roads = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            roads += matrix[i][j];
        }
    }
    return roads / 2;
}

int main() {
    int n;
    std::cin >> n;

    CGraph graph;
    graph.ReadEdges(n);

    std::cout << graph.CountRoads(n) << std::endl;

    return 0;
}