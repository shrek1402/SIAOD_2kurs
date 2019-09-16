#pragma once
#include <inttypes.h>
#include <algorithm>
#include <iostream>
#include <vector>

typedef struct vertex {
  uint64_t Data;
  vertex* Left = nullptr;
  vertex* Right = nullptr;
} Vertex;

class Tree {
 private:
  std::vector<uint64_t>* inputVector = nullptr;
  Vertex* _Root = nullptr;
  double _Sum = 0.0;
  uint64_t _Size = 0;
  std::vector <std::vector<int>> _A;

  
  void __print(Vertex* vertex);
  void __addNode(uint64_t inputData, Vertex*& vertex);
  void __printTree(Vertex* vertex, int level, int offset);
  void __lab0(Vertex* vertex);
  uint64_t __getSize(Vertex* Vertex);
  uint64_t __getAverageHeight(Vertex* Vertex, size_t length);
  uint64_t __getChecksum(Vertex* vertex);

  template <typename LYAMBDA>
  void __doForEach(Vertex* vertex, LYAMBDA f) {
    if (vertex == nullptr) 
		return;

	__doForEach(vertex->Left, f);
    f(vertex->Data);
    __doForEach(vertex->Right, f);
  }


  // << -- PUBLICK -- >>
 public:
  Tree(std::vector<uint64_t>*);

  Tree();

  void addNode(uint64_t);
  void print();
  void printTree();
  void getSize();
  void lab0();
  double getAverageHeight();
  uint64_t getChecksum();
  uint8_t getHeight(Vertex*);
  
  // << -- Lyambda -- >>
  template <typename LYAMBDA>
  void doForEach(LYAMBDA f) {
    __doForEach(_Root, f);
  }
};