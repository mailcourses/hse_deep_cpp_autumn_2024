#include "templates.hpp"

template<class T>
size_t vector<T>::size() const
{
    return size_;
}

template class vector<int>;
template class vector<double>;
template class vector<float>;
//template class vector< <Наш тип> >;
