#ifndef UNIQUE_PTR_HPP
#define UNIQUE_PTR_HPP

#include <utility> 

template<typename T>
class unique_ptr
{
private:
    T* pointer;

public:
    unique_ptr();
    explicit unique_ptr(T* p);
    unique_ptr(unique_ptr&& p) noexcept;

    unique_ptr& operator=(unique_ptr&& p) noexcept;


    ~unique_ptr() noexcept;


    void reset(T* p = nullptr);
    T* release();
    void swap(unique_ptr& other);
    T* get();


    T& operator*() const;
    T* operator->() const;
};

#include "unique_ptr_impl.hpp"

#endif
