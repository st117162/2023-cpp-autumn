#include<iostream>

class CGraph {
public:
	CGraph();
	CGraph(int vertexes);
	~CGraph();
	void PrintEdges();
	void ReadMatrix();

private:
	void initMatrix();
	int getEdgesCountFromMatrix();
	void dispose();

	int _vertexes;
	int** _matrix;
};

int main(int argc, char* argv[]) {
	int vertexes = 0;
	std::cin >> vertexes;
	CGraph graph(vertexes);
	graph.ReadMatrix();
	graph.PrintEdges();
	return 0;
}

CGraph::CGraph():
	_vertexes(0), _matrix(nullptr) {}

CGraph::CGraph(int _vertexes) :
	_vertexes(_vertexes), _matrix(nullptr) {}

CGraph::~CGraph() {
	dispose();
}

void CGraph::PrintEdges() {
	std::cout << _vertexes << " " << getEdgesCountFromMatrix() << std::endl;
	for (int i = 0; i < _vertexes; ++i)
	{
		for (int j = 0; j < _vertexes; ++j) {
			if (_matrix[i][j] == 1) {
				std::cout << i + 1 << " " << j + 1 << std::endl;
			}
		}
	}
}

void CGraph::ReadMatrix() {
	initMatrix();
	for (int i = 0; i < _vertexes; ++i)
	{
		for (int j = 0; j < _vertexes; ++j) {
			std::cin >> _matrix[i][j];
		}
	}
}

void CGraph::initMatrix() {
	_matrix = new int* [_vertexes];
	for (int i = 0; i < _vertexes; ++i)
	{
		_matrix[i] = new int [_vertexes] { 0 };
	}
}

int CGraph::getEdgesCountFromMatrix() {
	int count = 0;
	for (int i = 0; i < _vertexes; ++i) {
		for (int j = 0; j < _vertexes; ++j)
		{
			count += _matrix[i][j];
		}
	}
	return count;
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