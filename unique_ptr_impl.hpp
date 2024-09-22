template<typename T>
unique_ptr<T>::unique_ptr() : pointer(nullptr) {}

template<typename T>
unique_ptr<T>::unique_ptr(T* p) : pointer(p) {}

template<typename T>
unique_ptr<T>::unique_ptr(unique_ptr&& p) noexcept : pointer(p.pointer)
{
    p.pointer = nullptr;
}

template<typename T>
unique_ptr<T>& unique_ptr<T>::operator=(unique_ptr&& p) noexcept
{
    if (this != &p)
    {
        delete this->pointer;
        this->pointer = p.pointer;
        p.pointer = nullptr;
    }
    return *this;
}

template<typename T>
unique_ptr<T>::~unique_ptr() noexcept
{
    delete this->pointer;
}

template<typename T>
void unique_ptr<T>::reset(T* p)
{
    delete this->pointer;
    this->pointer = p;
}

template<typename T>
T* unique_ptr<T>::release()
{
    T* tmp = this->pointer;
    this->pointer = nullptr;
    return tmp;
}

template<typename T>
void unique_ptr<T>::swap(unique_ptr& other)
{
    T* tmp = this->pointer;
    this->pointer = other.pointer;
    other.pointer = tmp;
}

template<typename T>
T* unique_ptr<T>::get()
{
    return this->pointer;
}

template<typename T>
T& unique_ptr<T>::operator*() const
{
    return *this->pointer;
}

template<typename T>
T* unique_ptr<T>::operator->() const
{
    return this->pointer;
}
