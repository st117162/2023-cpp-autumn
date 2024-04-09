#include<iostream>

class CGraph{
public:
    int n = 0;
    CGraph(int n) : n(n) {
        matrix = new int* [n] {0};
        for (int i = 0; i < n; ++i) {
            matrix[i] = new int[n] {0};
        }
        color = new int[n] {0};
    }
    ~CGraph() {
        for (int i = 0; i < n; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
        delete[] color;
    } 
    void ReadMatrix();
    int BadBridges();

private:
    int** matrix;
    int* color;
};

void CGraph::ReadMatrix() {
    int a = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cin >> a;
            matrix[i][j] = a;
		}
	}
    for (int k = 0; k < n; ++k) {
        std::cin >> a;
        color[k] = a;
    }
}

int CGraph::BadBridges() {
    int badBridges = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((matrix[i][j] == 1) && (color[i] != color[j])) {
                badBridges += 1;
            }
            matrix[j][i] = 0;
        }
    }
    return badBridges;
}

int main(int argc, char* argv[]) {
	int n = 0;
    std::cin >> n;

    CGraph graph(n);
    graph.ReadMatrix();
    
    std::cout << graph.BadBridges() << std::endl;

	return 0;
}