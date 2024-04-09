#include<iostream>

class CGraph {
public:
	CGraph();
	CGraph(int vertexes);
	~CGraph();
	void ReadMatrix();
	void PrintSrc();
	void PrintStock();

private:
	bool isSrc(int vertex);
	bool isStock(int vertex);
	int CountSrc();
	int CountStock();
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
	graph.PrintSrc();
	graph.PrintStock();
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

void CGraph::PrintSrc() {
	std::cout << CountSrc();
	for (int i = 0; i < _vertexes; ++i) {
		if (isSrc(i)) {
			std::cout << " " << i + 1;
		}
	}
	std::cout << std::endl;
}

void CGraph::PrintStock() {
	std::cout << CountStock();
	for (int i = 0; i < _vertexes; ++i) {
		if (isStock(i)) {
			std::cout << " " << i + 1;
		}
	}
	std::cout << std::endl;
}

bool CGraph::isSrc(int vertex) {
	for (int i = 0; i < _vertexes; ++i) {
		if (_matrix[i][vertex] != 0) {
			return false;
		}
	}
	return true;
}

bool CGraph::isStock(int vertex) {
	for (int i = 0; i < _vertexes; ++i) {
		if (_matrix[vertex][i] != 0) {
			return false;
		}
	}
	return true;
}

int CGraph::CountSrc() {
	int count = 0;
	for (int i = 0; i < _vertexes; ++i) {
		if (isSrc(i)) {
			count += 1;
		}
	}
	return count;
}

int CGraph::CountStock() {
	int count = 0;
	for (int i = 0; i < _vertexes; ++i) {
		if (isStock(i)) {
			count += 1;
		}
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
