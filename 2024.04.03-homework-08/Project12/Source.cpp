#include<iostream>

class CGraph {
public:
	CGraph();
	CGraph(int vertexes);
	~CGraph();
	void ReadMatrix();
	void IsOriented();

private:
	int power(int vertex);
	void initMatrix();
	void dispose();

	int _vertexes;
	int** _matrix;
};

int main(int argc, char* argv[]) {
	int vertexes = 0;
	std::cin >> vertexes;
	CGraph graph(vertexes);
	graph.ReadMatrix();
	graph.IsOriented();
	return 0;
}

CGraph::CGraph() :
	_vertexes(0), _matrix(nullptr) {}

CGraph::CGraph(int _vertexes) :
	_vertexes(_vertexes), _matrix(nullptr) {}

CGraph::~CGraph() {
	dispose();
}

void CGraph::ReadMatrix() {
	initMatrix();
	for (int i = 0; i < _vertexes; ++i)
	{
		for (int j = 0; j < _vertexes; ++j)
		{
			std::cin >> _matrix[i][j];
		}
	}
}

void CGraph::IsOriented() {
	for (int i = 0; i < _vertexes; ++i) {
		if (_matrix[i][i] == 1) {
			std::cout << "NO" << std::endl;
			return;
		}
	}
	for (int i = 0; i < _vertexes; ++i) {
		for (int j = 0; j < _vertexes; ++j) {
			if (_matrix[i][j] != _matrix[j][i]) {
				std::cout << "YES" << std::endl;
				return;
			}
		}
	}

	std::cout << "NO" << std::endl;
}

int CGraph::power(int vertex) {
	int count = 0;
	for (int j = 0; j < _vertexes; ++j)
	{
		count += _matrix[vertex][j];
	}
	return count;
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
