#include <iostream>

template <typename T> class Vector
{
    public:
        Vector();
        Vector(unsigned int);
        Vector(const Vector&);
        ~Vector();
        bool operator==(const Vector<T>&);
        Vector<T>& operator=(const Vector<T>&);
        T& operator[](int);
        void clear();
        int size();
        bool empty();
        int capacity();
        void push_back(const T&);
        void pop_back();

    
    private:
        int m_capacity;
        int m_size;
        T* m_array;
};

template <typename T>
Vector<T>::Vector()
{
    m_size = 0;
    m_capacity = 0;
    m_array = new T[m_size];
}

template <typename T>
Vector<T>::Vector(unsigned int size)
{
    m_size = size;
    m_capacity = size;
    m_array = new T[m_size];
}

template <typename T> 
Vector<T>::Vector(const Vector& obj)
{
    this->m_size = obj.m_szie;
    this->m_capacity = obj.m_capacity;
    this->m_array = obj.m_array;
}

template <typename T>
Vector<T>::~Vector()
{
    delete [] this->m_array;
}

template <typename T>
bool Vector<T>::operator==(const Vector<T>& obj)
{
    bool result = false;
    if(this->m_size == obj.m_size){
        if(this->m_capacity == obj.m_capacity){
             for(int i=0; i<this->m_size; ++i){
                 if(this->m_array[i] == obj.m_array[i]){
                     result = true;
                }else{
                return result;
                }   
            }
        }
    }
    return result;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& obj)
{
    m_size = obj.m_size;
    m_capacity = obj.m_capacity;
    if(this->m_size != 0){
        delete [] m_array;
        m_array = new T[m_size];
        for(int i=0; i<m_size; ++i){
            m_array[i] = obj.m_array[i];
        }
    }else{
        m_array = nullptr;
    }
        return *this;
}

template <typename T>
T& Vector<T>::operator[](int index) 
{
    if(index < 0 || index > m_size)
        std::cerr << "Warning: Bad index: " << std::endl; 
    return m_array[index];
}

template <typename T>
void Vector<T>::clear()
{
    m_size = 0;
    m_capacity = 0;
    m_array = new T[m_size];
}

template <typename T>
int Vector<T>::size()
{
    return this->m_size;
}

template <typename T>
bool Vector<T>::empty()
{
    if(this->m_size == 0 && this->m_capacity == 0)
        return true;
    return false;
}

template <typename T>
int Vector<T>::capacity()
{
    return this->m_capacity;
}

template <typename T>
void Vector<T>::push_back(const T& elem)
{
    if(this->m_size == this->m_capacity){
        T* temp = new T[2 * m_size];

    for(int i=0; i < this->m_size; ++i){
        temp[i] = this->m_array[i];
    }

    delete [] m_array;
    if(this->m_capacity == 0)
        this->m_capacity ++;

    this->m_capacity *= 2;
    this->m_array = temp;
    }

    this->m_size ++;
    this->m_array[m_size - 1] = elem;
    
}

template <typename T>
void Vector<T>::pop_back()
{
    this->m_size --;
    this->m_capacity = m_size;
}

int main () 
{   
    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(30);
    vec.push_back(30);
    vec.push_back(30);

    std::cout << ":::vec size & capacity before cleaning:::" << std::endl;
    std::cout << "vec.size() == " << vec.size() << std::endl;
    std::cout << "vec.capacity() == " << vec.capacity() << std::endl;

    std::cout << "calling empty() function for vec  ::: result is " << vec.empty() << std::endl;
    vec.pop_back();
    std::cout << "vec.size() after  vec.pop_back() " << vec.size() << std::endl;

    std::cout << std::endl;

    vec.clear();
    std::cout << ":::vec size & capacity after cleaning:::" << std::endl;
    std::cout << "vec.size() == " << vec.size() << std::endl;
    std::cout << "vec.capacity() == " << vec.capacity() << std::endl;

    std::cout << std::endl;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
 
    Vector<int> vec2;
    vec2 = vec;

    std::cout << ":::vec2 size & capacity2 before pop_back function calls:::" << std::endl;
    std::cout << "vec2.size() == " << vec2.size() << std::endl;
    std::cout << "vec2.capacity() == " << vec2.capacity() << std::endl;

    std::cout << std::endl;

    bool res = vec == vec2;
    std::cout << "::: result vec == vec2 is " << res << std::endl;
    std::cout << std::endl;

    vec2.pop_back();
    std::cout << ":::vec2 size & capacity2 after pop_back function calls:::" << std::endl;
    std::cout << "vec2.size() == " << vec2.size() << std::endl;
    std::cout << "vec2.capacity() == " << vec2.capacity() << std::endl;
    res = vec == vec2;
    std::cout << "::: result vec == vec2 is " << res << std::endl;
    std::cout << std::endl;

    std::cout << std::endl;

    Vector<std::string> vec_str(4);
    vec_str.push_back("Nothing1");
    vec_str.push_back("Nothing2");
    vec_str.push_back("Nothing3");
    vec_str.push_back("Nothing4");

    std::cout << ":::vec_str size & capacity before cleaning:::" << std::endl;
    std::cout << "vec_str.size() == " << vec_str.size() << std::endl;
    std::cout << "vec_str.capacity() == " << vec_str.capacity() << std::endl;

    std::cout << std::endl;

    vec_str.clear();
    std::cout << ":::vec_str size & capacity after cleaning:::" << std::endl;
    std::cout << "vec_str.size() == " << vec_str.size() << std::endl;
    std::cout << "vec_str.capacity() == " << vec_str.capacity() << std::endl;

    std::cout << std::endl;

}
