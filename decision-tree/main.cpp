#include "decision_tree.hpp"
#include "node.hpp"
#include <iostream>
#include <new>



int main() {
    //So I can easily change the type of the tree without updating every reference to it
    using dType = double;
    dType defaultValue = 0.0;
    Node<dType>* headNode = new Node<dType>(defaultValue);
    DecisionTree<dType> tree(headNode); 
    Node<dType>* Node2 = new Node<dType>(defaultValue);
    std::cout << Node<dType>::peekNextId();
    return 0;
}