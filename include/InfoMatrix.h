#pragma once

#include <vector>

namespace ima {

    template <class T>
    class InfoMatrix {
        public:
            InfoMatrix(): _m(0), _n(0), _numOfElements(0) {}
            InfoMatrix(unsigned int m, unsigned int n)
            {
                _m = m;
                _n = n;
                _numOfElements = 0;
                for (unsigned int i = 0; i < m; ++i) {
                    _infoMatrix.push_back(std::vector<T>(n));
                }
            }
            InfoMatrix(const InfoMatrix &) = default;
            InfoMatrix(InfoMatrix &&) = default;
            InfoMatrix &operator=(const InfoMatrix &) = default;
            InfoMatrix &operator=(InfoMatrix &&) = default;
            bool isEmpty()
            {
                return _infoMatrix.empty();
            }
            unsigned int getNumOfElements()
            {
                return _numOfElements;
            }
            unsigned int getNumOfRows()
            {
                return _m;
            }
            unsigned int getNumOfColumns()
            {
                return _n;
            }
            void setElement(const T &element, unsigned int m, unsigned int n)
            {
                _infoMatrix[m][n] = element;
                ++_numOfElements;
            }
            T &getElement(unsigned int m, unsigned int n)
            {
                return _infoMatrix[m][n];
            }
        private:
            unsigned int _m;
            unsigned int _n;
            unsigned int _numOfElements;
            std::vector<std::vector<T> > _infoMatrix;
    };

}
