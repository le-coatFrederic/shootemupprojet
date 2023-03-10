#ifndef DATAENTITIESCLIENT_HPP
#define DATAENTITIESCLIENT_HPP

#include <vector>

template <typename T>
class Data {
public:
    // constructors / destructors
    Data();
    ~Data();

    // accessors
    std::vector<T*> getData();
    void addEntity(T* cell);

    void deleteCell(T* cell);
private:
    std::vector<T*> data;
};
#endif

