#include "unique.hpp"

template<typename T>
    unique_ptr<T>::unique_ptr(): pointer(nullptr){};
    template<typename T>

    template<typename T>
    unique_ptr<T>::unique_ptr(T*p) : pointer(p) {};

    unique_ptr(unique_ptr&& p) noexcept : pointer(p.pointer)
    {
        p.pointer = nullptr;
    }
    unique_ptr& operator = (unique_ptr&& p) noexcept
    {  
        if(this != &p)
        {
            delete this->pointer;
            this->pointer = p.pointer;
            p.pointer = nullptr;
        }
        return *this;
    }

    ~unique_ptr() noexcept
    {
        delete this->pointer;
    }
    
    void reset(T* p = nullptr)
    {
        delete this->pointer;
        this->pointer = p;       
    }
    T* release()
    {
        T* tmp = this->pointer;
        this->pointer = nullptr;
        return tmp;
    }
    void swap(unique_ptr& other)
    {   
        T* tmp = this->pointer;
        this->pointer = other.pointer;
        other.pointer = tmp;

    }
    T* get()
    {
        return this->pointer;
    }
    
    T& operator *() const
    {
        return *this->pointer;
    }

    T* operator ->() const 
    {
        return this->pointer;
    }
};

int main() {
    unique_ptr<int> ptr1(new int(42));
    std::cout<< *ptr1 << std::endl;

    unique_ptr<int> ptr2(std::move(ptr1));
    std::cout <<*ptr2 << std::endl;

    ptr2.reset(new int(100));
    std::cout<< *ptr2 << std::endl;

    int* rawPtr = ptr2.release();
    std::cout << *rawPtr << std::endl;
    delete rawPtr;

    return 0;
}