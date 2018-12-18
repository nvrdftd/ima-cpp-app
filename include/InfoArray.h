#pragma once

#include <vector>

namespace ima {

    template <class T>
    class InfoArray {
        public:
            void add(const T &elem)
            {
                _infoArr.push_back(elem);
            }
            T &get(unsigned int index)
            {
                return _infoArr.at(index);
            }
            const T &get(unsigned int index) const
            {
                return _infoArr.at(index);
            }
            unsigned int getNumOfElements() const
            {
                return _infoArr.size();
            }
        private:
            std::vector<T> _infoArr;
    };

}
