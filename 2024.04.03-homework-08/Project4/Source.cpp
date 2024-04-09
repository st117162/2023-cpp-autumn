#include<iostream>
#include<algorithm>

class CGraph {
public:
    int n = 0;
    CGraph(int n) : n(n) {
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
    void ReadMatrix();
    int ShortestRoute();

private:
    int** matrix;
};

void CGraph::ReadMatrix() {
    int a = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> a;
            matrix[i][j] = a;
        }
    }
}

int CGraph::ShortestRoute() {
    int shortest = 3000;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if ((i != j) && (j != k) && (k != i)) {
                    shortest = std::min(shortest, matrix[i][j] + matrix[j][k] + matrix[k][i]);
                }
            }
        }
    }
    return shortest;
}

int main(int argc, char* argv[]) {
    int n = 0;
    std::cin >> n;

    CGraph graph(n);
    graph.ReadMatrix();

    std::cout << graph.ShortestRoute() << std::endl;

    return 0;
}