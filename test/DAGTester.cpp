#include "DAG.h"
#include <string>
#include <cassert>

int main(int argc, char **argv)
{
    using namespace imacore;

    DAG<std::string, std::string> journeyDAG;

    int numOfNodes = 2000;
    for (int i = 0; i < numOfNodes; ++i) {
        std::string testStr = std::to_string(i);
        journeyDAG.insert(testStr);
        assert(journeyDAG.getNodeData(i) == testStr);
    }

    assert(journeyDAG.getNumOfNodes() == numOfNodes);
    std::cout << "DAG Test: Pass" << std::endl;
    assert(journeyDAG.getNumOfEdges() == (numOfNodes * (numOfNodes - 1) / 2));
    std::cout << "DAG Test: Pass" << std::endl;



    for (int i = 0; i < numOfNodes; ++i) {
        for (int j = i + 1; j < numOfNodes; ++j) {
            assert(journeyDAG.getEdgeData(i, j) == "");
            std::cout << "DAG Test: Pass" << std::endl;
        }
    }

    for (int i = 0; i < numOfNodes; ++i) {
        for (int j = i + 1; j < numOfNodes; ++j) {
            journeyDAG.setEdgeData(i, j, "Changed");
            assert(journeyDAG.getEdgeData(i, j) == "Changed");
            std::cout << "DAG Test: Pass" << std::endl;
        }
    }
    for (int i = 0; i < numOfNodes; ++i) {
        journeyDAG.setNodeData(i, "Modified");
        assert(journeyDAG.getNodeData(i) == "Modified");
        std::cout << "DAG Test: Pass" << std::endl;
    }

    std::cout << "DAG Test: All Pass" << std::endl;

    return 0;
}
