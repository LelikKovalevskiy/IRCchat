#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H
class referenceCount
{
private:
    int count;

public:
    void addRef()
    {
        count++;
    }

    int delRef()
    {
        return --count;
    }
};
template < typename T > class smartPointer
{
private:
    T*    pData;
    referenceCount* reference;

public:
    smartPointer() : pData(0), reference(0)
    {
        reference = new referenceCount();
        reference->addRef();
    }

    smartPointer(T* pValue) : pData(pValue), reference(0)
    {
        reference = new referenceCount();
        reference->addRef();
    }

    smartPointer(const smartPointer<T>& sp) : pData(sp.pData), reference(sp.reference)
    {
        reference->addRef();
    }

    ~smartPointer()
    {

        if(reference->delRef() == 0)
        {
            delete pData;
            delete reference;
        }
    }

    T& operator* () const
    {
        return *pData;
    }

    T* operator-> () const
    {
        return pData;
    }

    smartPointer<T>& operator = (const smartPointer<T>& sp)
    {
        if (this != &sp)
        {
            if(reference->delRef() == 0)
            {
                delete pData;
                delete reference;
            }
            pData = sp.pData;
            reference = sp.reference;
            reference->addRef();
        }
        return *this;
    }
    operator bool()
    {
        return pData;
    }
    T* standartPointer()
    {
        return pData;
    }

    operator T*()
    {
       return pData;
    }

    operator const T*()const
    {
       return reinterpret_cast<T*>(pData);
    }
};

#endif // SMARTPOINTER_H
