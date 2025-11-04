template <typename T>       
class Node {
    int id;
    bool isLeaf;
    T classifierValue;
public:
    Node(int nodeId, bool leafStatus, T value)
        : id(nodeId), isLeaf(leafStatus), classifierValue(value) {}
};