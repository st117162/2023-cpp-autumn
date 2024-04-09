#include<iostream>

class CGraph {
public:
	CGraph();
	CGraph(int vertexes, int _edges);
	~CGraph();
	void ReadMatrix();
	void IsTour();

private:
	void initMatrix();
	void dispose();

	int _vertexes;
	int _edges;
	int** _matrix;
};

int main(int argc, char* argv[]) {
	int vertexes = 0;
	int edges = 0;
	std::cin >> vertexes >> edges;
	CGraph graph(vertexes, edges);
	graph.ReadMatrix();
	graph.IsTour();
	return 0;
}

CGraph::CGraph() :
	_vertexes(0), _edges(0), _matrix(nullptr) {}

CGraph::CGraph(int _vertexes, int _edges) :
	_vertexes(_vertexes), _edges(_edges), _matrix(nullptr) {}

CGraph::~CGraph() {
	dispose();
}

void CGraph::ReadMatrix() {
	initMatrix();
	for (int k = 0; k < _edges; ++k)
	{
		int i = 0;
		int j = 0;
		std::cin >> i >> j;
		_matrix[i - 1][j - 1] += 1;
	}
}

void CGraph::IsTour() {
	for (int i = 0; i < _vertexes; ++i) {
		if (_matrix[i][i] != 0) {
			std::cout << "NO" << std::endl;
			return;
		}
	}
	for (int i = 0; i < _vertexes; ++i) {
		for (int j = 0; j < _vertexes; ++j) {
			if ((i != j) && ((_matrix[i][j] + _matrix[j][i] == 0) || (_matrix[i][j] + _matrix[j][i] > 1))) {
				std::cout << "NO" << std::endl;
				return;
			}
		}
	}
	std::cout << "YES" << std::endl;
	return;
}

void CGraph::initMatrix() {
	_matrix = new int* [_vertexes];
	for (int i = 0; i < _vertexes; ++i)
	{
		_matrix[i] = new int [_vertexes] { 0 };
	}
}

void CGraph::dispose() {
	if (_matrix != nullptr) {
		for (int i = 0; i < _vertexes; ++i) {
			delete[] _matrix[i];
		}
		delete[] _matrix;
		_matrix = nullptr;
	}
}
