#include<iostream>

class CGraph {
public:
	CGraph();
	CGraph(int vertexes, int _edges);
	~CGraph();
	void PrintMatrix();
	void PrintEdges();
	void ReadMatrix();

private:
	void initMatrix();
	int power(int vertex);
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
	graph.PrintEdges();
	return 0;
}

CGraph::CGraph() :
	_vertexes(0), _edges(0), _matrix(nullptr) {}

CGraph::CGraph(int _vertexes, int _edges) :
	_vertexes(_vertexes), _edges(_edges), _matrix(nullptr) {}

CGraph::~CGraph() {
	dispose();
}

void CGraph::PrintMatrix() {
	for (int i = 0; i < _vertexes; ++i)
	{
		for (int j = 0; j < _vertexes; ++j)
		{
			std::cout << _matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void CGraph::PrintEdges() {
	std::cout << _vertexes << std::endl;
	for (int i = 0; i < _vertexes; ++i)
	{
		std::cout << power(i);
		if (power(i) != 0) {
			for (int j = 0; j < _vertexes; ++j) {
				if (_matrix[i][j] == 1) {
					std::cout << " " << j + 1;
				}
			}
		}
		std::cout << std::endl;
	}
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

void CGraph::initMatrix() {
	_matrix = new int* [_vertexes];
	for (int i = 0; i < _vertexes; ++i)
	{
		_matrix[i] = new int [_vertexes] { 0 };
	}
}


int CGraph::power(int vertex) {
	int count = 0;
	for (int j = 0; j < _vertexes; ++j)
	{
		count += _matrix[vertex][j];
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
