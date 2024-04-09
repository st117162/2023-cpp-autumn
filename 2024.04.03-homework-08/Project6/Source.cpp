#include<iostream>

class CGraph {
public:
	CGraph();
	CGraph(int vertexes, int _edges);
	~CGraph();
	void ReadMatrix();
	int CountImportant();

private:
	void initMatrix();
	void dispose();

	int _vertexes;
	int _edges;
	int** _matrix;
};

int main(int argc, char* argv[]) {
	int vertexes = 0;
	std::cin >> vertexes;
	CGraph graph(vertexes, vertexes - 1);
	graph.ReadMatrix();
	std::cout << graph.CountImportant() << std::endl;
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
		_matrix[j - 1][i - 1] += 1;
	}
}

int CGraph::CountImportant() {
	int count = 0;
	bool isImportant = false;
	for (int i = 0; i < _vertexes; ++i)
	{
		isImportant = false;
		for (int j = 0; j < _vertexes; ++j)
		{
			for (int k = j + 1; k < _vertexes; ++k)
			{
				if (_matrix[i][j] == 0)
				{
					break;
				}
				if (_matrix[i][k] > 0)
				{
					isImportant = true;
					break;
				}
			}
			if (isImportant)
			{
				break;
			}
		}
		if (isImportant)
		{
			++count;
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
