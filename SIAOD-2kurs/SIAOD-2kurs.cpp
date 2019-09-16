#include "Tree.h"

int main() {
  std::vector<uint64_t> inputData;
  inputData.reserve(6);

  inputData.push_back(2);
  inputData.push_back(1);
  inputData.push_back(3);
  inputData.push_back(5);
  inputData.push_back(4);
  inputData.push_back(6);
  
  /*
  inputData.push_back(4);
  inputData.push_back(2);
  inputData.push_back(1);
  inputData.push_back(3);
  inputData.push_back(6);
  inputData.push_back(5);
  inputData.push_back(7);  */

  Tree myTree;
  myTree.lab0();
  myTree.print();
  //myTree.getSize();
  //std::cout << myTree.getAverageHeight() << std::endl;
  //std::cout << myTree.getChecksum() << std::endl;
  //std::cout << myTree.getHeight() << std::endl;
  //myTree.getSize();


  // myTree.doForEach([&](auto i) {
  //	  });
}