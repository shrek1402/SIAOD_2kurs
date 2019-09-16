#include "Tree.h"

Tree::Tree(std::vector<uint64_t>* inputArr) {
  inputVector = inputArr;
  for (auto it : *inputArr) {
    __addNode(it, _Root);
  }
}

Tree::Tree() { _Root = new Vertex; }


void Tree::__addNode(uint64_t inputData, Vertex*& vertex) {
  if (vertex == nullptr) {
    vertex = new Vertex;
    vertex->Data = inputData;
  }
  if (inputData < vertex->Data) {
    if (vertex->Left != nullptr)
      __addNode(inputData, vertex->Left);
    else {
      vertex->Left = new Vertex;
      vertex->Left->Data = inputData;
    }
  }
  if (inputData > vertex->Data) {
    if (vertex->Right != nullptr)
      __addNode(inputData, vertex->Right);
    else {
      vertex->Right = new Vertex;
      vertex->Right->Data = inputData;
    }
  }
}

void Tree::printTree() {
  __printTree(_Root, 0, 0);

  for (size_t i = 0; i < 10; i++) {
    for (size_t j = 0; j < 10; j++) {
      if (_A[i][j] != 0) {
        std::cout << _A[i][j];

      } else
        std::cout << " ";
    }
    std::cout << std::endl;
  }
}

void Tree::__printTree(Vertex* vertex, int level, int offset) {
  if (vertex == nullptr) return;
}

void Tree::addNode(uint64_t inputData) { __addNode(inputData, _Root); }

uint8_t Tree::getHeight(Vertex* vertex) {
  if (vertex == nullptr)
    return 0;
  else
    return uint8_t(
        (1 + std::max(getHeight(vertex->Left), getHeight(vertex->Right))));
}

uint64_t Tree::__getSize(Vertex* Vertex)  // TODO
{
  if (Vertex == nullptr)
    return 0;
  else
    return uint64_t((1 + __getSize(Vertex->Left) + __getSize(Vertex->Right)));
}

void Tree::getSize() {
  _Size = __getSize(_Root);
  std::cout << _Size;
}

double Tree::getAverageHeight() {
  _Sum = __getAverageHeight(_Root, 1);

  if (!_Size) _Size = __getSize(_Root);
  if (!_Size) return NAN;

  return _Sum / _Size;
}

uint64_t Tree::__getAverageHeight(Vertex* Vertex, size_t length) {
  if (Vertex == nullptr)
    return 0;
  else {
    return uint64_t(length + __getAverageHeight(Vertex->Left, length + 1) +
                    __getAverageHeight(Vertex->Right, length + 1));
  }
}

uint64_t Tree::getChecksum() { return uint64_t(__getChecksum(_Root)); }

uint64_t Tree::__getChecksum(Vertex* vertex) {
  if (vertex == nullptr) return 0;

  return vertex->Data + __getChecksum(vertex->Left) +
         __getChecksum(vertex->Right);
}

void Tree::print() { __print(_Root); }

void Tree::__print(Vertex* vertex) {
  if (vertex == nullptr) return;

  __print(vertex->Left);
  std::cout << vertex->Data << " ";
  __print(vertex->Right);
}

void Tree::lab0() { __lab0(_Root); }

void Tree::__lab0(Vertex* vertex) {
    vertex->Left = new Vertex;
    vertex->Right = new Vertex;
    vertex->Right->Right = new Vertex;
    vertex->Right->Right->Left = new Vertex;
    vertex->Right->Right->Right = new Vertex;

	vertex->Data                      = rand() % 10;
	vertex->Left->Data                = rand() % 10;
	vertex->Right->Data               = rand() % 10;
	vertex->Right->Right->Data        = rand() % 10;
	vertex->Right->Right->Left->Data  = rand() % 10;
	vertex->Right->Right->Right->Data = rand() % 10;
}