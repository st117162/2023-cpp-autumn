#include <iostream>

class CGraph {
public:
    int n = 0;
    int m = 0;
    CGraph(int n, int m) : n(n), m(m) {
        matrix = new int* [n] {0};
        for (int i = 0; i < n; ++i) {
            matrix[i] = new int[n] {0};
        }
    }
    ~CGraph() {
        for (int i = 0; i < n; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
    void ReadEdges();
    void CountRoads();

private:
    int** matrix;
};

void CGraph::ReadEdges() {
    int i = 0;
    int j = 0;
    for (int k = 0; k < m; ++k)
    {
        std::cin >> i >> j;
        matrix[i - 1][j - 1] += 1;
        matrix[j - 1][i - 1] += 1;
    }
}

void CGraph::CountRoads() {
    int roads = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            roads += matrix[i][j];
        }
        std::cout << roads << " ";
        roads = 0;
    }
    std::cout << std::endl; 
}

int main(int argc, char* argv[]) {
    int n = 0;
    int m = 0;
    std::cin >> n >> m;

    CGraph graph(n, m);
    graph.ReadEdges(); 

    graph.CountRoads();

    return 0;
}
