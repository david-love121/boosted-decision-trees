#pragma once
#include <stdexcept>
template <typename T>       
class Node {
private:
    int id;
    // The value which accepts, or sends to the right node when input >= value
    T classifierValue;
    Node* leftChild;
    Node* rightChild;

    static int& idCounter() {
        static int counter = 0;
        return counter;
    }
    static int nextId() { return idCounter()++; }
public:
    static void resetIdCounter(int start = 0) { idCounter() = start; }
    static int peekNextId() { return idCounter(); }

    Node(T value)
        : id(nextId()), classifierValue(value), leftChild(nullptr), rightChild(nullptr) {}
    Node(T value, Node* left, Node* right)
        : id(nextId()), classifierValue(value), leftChild(left), rightChild(right) {}
    Node(int nodeId, T value)
        : id(nodeId), classifierValue(value), leftChild(nullptr), rightChild(nullptr) {}
    Node(int nodeId, T value, Node* left, Node* right)
        : id(nodeId), classifierValue(value), leftChild(left), rightChild(right) {}
    int getId() const { return id; }
    bool getIsLeaf() const { return leftChild == nullptr && rightChild == nullptr; } 
    T getClassifierValue() const { return classifierValue; }
    Node* getLeftChild() const { return leftChild; }
    Node* getRightChild() const { return rightChild; }
    void setLeftChild(Node* left) { leftChild = left; }
    void setRightChild(Node* right) { rightChild = right; }
    void setChildren(Node* left, Node* right) {leftChild = left; rightChild = right; }
    void setClassifierValue(T value) { classifierValue = value; }
    void runInput(T input) {
        if (leftChild == nullptr || rightChild == nullptr) {
            throw std::runtime_error("leftChild or rightChild is null!");
        }
        if (input >= classifierValue) {
            rightChild->runInput(input);
        } else {
            leftChild->runInput(input);
        };
    }


};