
#include "node.hpp"
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <new>
#include <stdexcept>
#include <map>
#include <unordered_map>
#include "decision_tree.hpp"


void trainingLoop(DecisionTree& tree, int epochs = 10) {
    double lastImpurity = 1.0;
    for (int i = 0; i < epochs; i++) {
        tree.runTree();
        std::cout << "Last impurity: " << lastImpurity << "\n";
        lastImpurity = tree.calculateAllImpurity();
        
        tree.makeSplits();
        tree.resetTree();
    }

}


int main() {


    DecisionTree tree; 
    



    trainingLoop(tree);
    return 0;
}