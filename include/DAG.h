#pragma once

#include <map>
#include <vector>
#include <utility>

namespace ima {
    template <class T>
    class GraphEdge {
        public:
            GraphEdge(unsigned int edgeId): _edgeId(edgeId) {}

            GraphEdge(unsigned int edgeId, const T &data)
            {
                _edgeId = edgeId;
                _data = data;
            }

            GraphEdge(const GraphEdge<T> &) = default;

            GraphEdge(GraphEdge<T> &&) = default;

            GraphEdge<T> &operator=(const GraphEdge<T> &) = default;

            GraphEdge<T> &operator=(GraphEdge<T> &&) = default;

            T &getData()
            {
                return _data;
            }

            void setData(const T &data)
            {
                _data = data;
            }

            unsigned int getEdgeId()
            {
                return _edgeId;
            }

        private:
            unsigned int _edgeId;
            T _data;

    };

    template <class T, class S>
    class GraphNode {
        public:
            GraphNode(unsigned int nodeId, const T &data)
            {
                _nodeId = nodeId;
                _data = data;
            }

            GraphNode(const GraphNode<T, S> &) = default;

            GraphNode(GraphNode<T, S> &&) = default;

            GraphNode<T, S> &operator=(const GraphNode<T, S> &) = default;

            GraphNode<T, S> &operator=(GraphNode<T, S> &&) = default;

            T &getData()
            {
                return _data;
            }

            void setData(const T &data)
            {
                _data = data;
            }

            unsigned int getNodeId()
            {
                return _nodeId;
            }

            GraphEdge<S> &getEdge(unsigned int id) noexcept
            {
                return *_oEdgeMap.at(id);
            }

            void insertIEdge(unsigned int id, GraphEdge<S> *newEdge)
            {
                _iEdgeMap.insert(std::make_pair(id, newEdge));
            }

            void insertOEdge(unsigned int id, GraphEdge<S> *newEdge)
            {
                _oEdgeMap.insert(std::make_pair(id, newEdge));
            }

            bool hasSuccessor()
            {
                if (_oEdgeMap.size() == 0) {
                    return false;
                }
                return true;
            }

            std::vector<unsigned int> getINodeId()
            {
                std::vector<unsigned int> _vector;
                for (auto iter = _iEdgeMap.begin(); iter != _iEdgeMap.end(); ++iter) {
                    _vector.push_back(iter->first);
                }
                return _vector;
            }

            std::vector<unsigned int> getONodeId()
            {
                std::vector<unsigned int> _vector;
                for (auto iter = _oEdgeMap.begin(); iter != _oEdgeMap.end(); ++iter) {
                    _vector.push_back(iter->first);
                }
                return _vector;
            }

        private:
            T _data;
            unsigned int _nodeId;
            std::map<unsigned int, GraphEdge<S>*> _iEdgeMap;
            std::map<unsigned int, GraphEdge<S>*> _oEdgeMap;

    };

    template <class T, class S>
    class DAG {
        public:
            DAG(): _numOfNodes(0), _numOfEdges(0), _nextNodeId(0), _nextEdgeId(0) {}

            void connectNodes(unsigned int id) noexcept
            {
                GraphNode<T, S> &currentNode = *_nodeVector.at(id);
                for (unsigned int x = 0; x < id; ++x) {
                    GraphEdge<S> *newEdge = new GraphEdge<S>(_nextEdgeId);
                    _edgeVector.push_back(newEdge);
                    currentNode.insertIEdge(x, newEdge);
                    GraphNode<T, S> &otherNode = *_nodeVector.at(x);
                    otherNode.insertOEdge(id, newEdge);
                    ++_numOfEdges;
                    ++_nextEdgeId;
                }
            }

            void insert(const T &data)
            {
                GraphNode<T, S> *newNode = new GraphNode<T, S>(_nextNodeId, data);
                _nodeVector.push_back(newNode);
                connectNodes(_nextNodeId);
                ++_numOfNodes;
                ++_nextNodeId;
            }

            GraphNode<T, S> &getNode(unsigned int id) noexcept
            {
                return *_nodeVector.at(id);
            }

            T &getNodeData(unsigned int id) noexcept
            {
                return (*_nodeVector.at(id)).getData();
            }

            void setNodeData(unsigned int id, const T &data) noexcept
            {
                (*_nodeVector.at(id)).setData(data);
            }

            GraphEdge<S> &getEdge(unsigned int id) noexcept
            {
                return *_edgeVector.at(id);
            }

            GraphEdge<S> &getEdge(unsigned int fromId, unsigned int toId) noexcept
            {
                return (*_nodeVector.at(fromId)).getEdge(toId);
            }

            S &getEdgeData(unsigned int id) noexcept
            {
                return (*_edgeVector.at(id)).getData();
            }

            S &getEdgeData(unsigned int fromId, unsigned int toId) noexcept
            {
                return (*_nodeVector.at(fromId)).getEdge(toId).getData();
            }

            void setEdgeData(unsigned int fromId, unsigned int toId, const S &data) noexcept
            {
                (*_nodeVector.at(fromId)).getEdge(toId).setData(data);
            }

            bool isTerminal(unsigned int id) noexcept
            {
                return (*_nodeVector.at(id)).hasSuccessor();
            }

            unsigned int getNumOfNodes()
            {
                return _numOfNodes;
            }

            unsigned int getNumOfEdges()
            {
                return _numOfEdges;
            }

            std::vector<unsigned int> getIEdgeId(unsigned int id) noexcept
            {
                std::vector<unsigned int> _vector;
                for (unsigned int i: (*_nodeVector.at(id)).getINodeId()) {
                    _vector.push_back(getEdge(i, id).getEdgeId());
                }
                return _vector;

            }

            std::vector<unsigned int> getOEdgeId(unsigned int id) noexcept
            {
                std::vector<unsigned int> _vector;
                for (unsigned int i: (*_nodeVector.at(id)).getONodeId()) {
                    _vector.push_back(getEdge(id, i).getEdgeId());
                }
                return _vector;

            }
            ~DAG()
            {
                for (auto edge: _edgeVector) {
                    delete edge;
                }
                for (auto node: _nodeVector) {
                    delete node;
                }
            }

        private:
            unsigned int _numOfNodes;
            unsigned int _numOfEdges;
            unsigned int _nextNodeId;
            unsigned int _nextEdgeId;
            std::vector<GraphNode<T, S>*> _nodeVector;
            std::vector<GraphEdge<S>*> _edgeVector;
    };
}
