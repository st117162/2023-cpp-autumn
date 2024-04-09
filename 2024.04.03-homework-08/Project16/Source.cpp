#include<iostream>

class CGraph {
public:
	CGraph();
	CGraph(int vertexes);
	~CGraph();
	void ReadMatrix();
	int PlaceTracker(int a, int b);

private:
	void initMatrix();
	void dispose();

	int _vertexes;
	int** _matrix;
};

int main(int argc, char* argv[]) {
	int vertexes = 0;
	std::cin >> vertexes;
	CGraph graph(vertexes);
	int a = 0;
	int b = 0;
	std::cin >> a >> b;
	graph.ReadMatrix();
	std::cout << graph.PlaceTracker(a - 1, b - 1) << std::endl;
	return 0;
}

CGraph::CGraph() :
	_vertexes(0), _matrix(nullptr) {}

CGraph::CGraph(int _vertexes) :
	_vertexes(_vertexes), _matrix(nullptr) {}

CGraph::~CGraph() {
	dispose();
}

void CGraph::ReadMatrix()	 {
	initMatrix();
	int i = 0;
	for (int k = 0; k < _vertexes - 1; ++k)
	{
		std::cin >> i;
		_matrix[k + 1][i - 1] += 1;
	}
}

int CGraph::PlaceTracker(int a, int b) {
	while (a != b) {
		if (a > b) {
			for (int i = 0; i < _vertexes; ++i) {
				if (_matrix[a][i] == 1) {
					a = i;
				}
			}
		}
		else {
			for (int i = 0; i < _vertexes; ++i) {
				if (_matrix[b][i] == 1) {
					b = i;
				}
			}
		}
	}
	return a + 1;
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
