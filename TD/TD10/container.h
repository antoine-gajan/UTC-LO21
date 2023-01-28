#if !defined(_Container_T_H)
#define _Container_T_H
#include<string>
#include<stdexcept>
namespace TD {
    class ContainerException : public std::exception {
    protected :
        std::string info;
    public:
        ContainerException(const std::string& i="") noexcept :info(i){}
        const char* what() const noexcept { return info.c_str(); }
        ~ContainerException()noexcept{}
    };

    template<class T> class Container {
    protected:
        size_t nb;
    public:
        size_t size() const {return nb;};
        bool empty() const {return nb == 0;};
        virtual T& element (size_t i) = 0;
        virtual const T& element(size_t i) const = 0;
        T& front() {return element(0);};
        const T& front()const {return element(0);};
        T& back() {return element(nb);};
        const T& back()const {return element(nb);};
        virtual void push_back(const T& x) = 0;
        virtual void pop_back() = 0;
        virtual void clear();
        Container(size_t n) : nb(n) {};
        virtual ~Container() = default;
    };

    template<class T>
    void Container<T>::clear() {
        while (!empty()) pop_back();
    }

    template<class T>
    class Vector : public Container<T> {
    protected:
        T* tab = nullptr;
        size_t cap;
    public:
        Vector(size_t n = 0, const T& x = T());
        T& element (size_t i);
        const T& element(size_t i) const {return tab[i];};
        const T& operator[](size_t i) const {return element(i);};
        T& operator[](size_t i) {return element(i);};
        ~Vector() {delete[] tab;};
        Vector(const Vector<T>& v);
        Vector& operator=(const Vector<T>& v);
        size_t capacity() const {return cap;};
        void reserve(size_t c);
        void push_back(const T& x);
        void pop_back();
    };

    template<class T>
    void Vector<T>::pop_back() {
        this->nb--;
    }

    template<class T>
    void Vector<T>::push_back(const T &x) {
        reserve(this->size() + 1);
        tab[this->nb++] = x;
    }

    template<class T>
    void Vector<T>::reserve(size_t c) {
        if (c > cap)
        {
            cap = c;
            T* newtab = new T[cap];
            for (int i = 0; i < this->size(); i++)
            {
                newtab[i] = tab[i];
            }
            T* old = tab;
            tab = newtab;
            cap = c;
            delete[] old;
        }
    }

    template<class T>
    T &Vector<T>::element(size_t i) {
        if (i >= this->size()) throw ContainerException("out of range");
        return tab[i];
    }

    template<class T>
    Vector<T>::Vector(size_t n, const T &x) : Container<T>(n), tab(new T[n]), cap(n) {
        for (size_t i=0; i < n; i++) tab[i] = x;
    }

    template<class T>
    Vector<T> &Vector<T>::operator=(const Vector<T> &v) {
        if (cap < v.capacity())
        {
            reserve(v.capacity());
        }
        for (int i = 0; i < v.size(); i++)
        {
            tab[i] = v[i];
        }
        this->nb = v.size();
    }

    template<class T>
    Vector<T>::Vector(const Vector<T> &v)  : cap(v.size()), Container<T>(v.size()), tab(new T[cap])
    {
        if (this != &v)
        {
            for (int i = 0; i < v.size(); i++){
                tab[i] = v[i];
            }
        }
    }



    template<class T, class C = Vector<T>>
    class Stack1 : private C {
    public:
        bool empty() const {return C::empty();};
        void push(const T& x) {this->push_back(x);};
        void pop() {this->pop_back();};
        size_t size() const {C::size();};
        T& top() {return this->back();};
        const T& top() const {return this->back();};
        void clear() {C::clear();};
        // virtual ~Stack1() = default;
    };

    template<class T, class C = Vector<T>>
    class Stack2 final{
    private:
        C cont;
    public:
        bool empty() const {return cont.empty();};
        void push(const T& x) {cont.push_back(x);};
        void pop() {cont.pop_back();};
        size_t size() const {return cont.size();};
        T& top() {return cont.back();};
        const T& top() const {return cont.back();};
        void clear() {cont.clear();};
        Stack2() = default;
    };
}
#endif