#ifndef DSTRUCTS_SHARED_PTR_H
#define DSTRUCTS_SHARED_PTR_H

namespace DStructs {
    template <typename T>
    class SharedPtr
    {
    public:
        /// Default constructor
        SharedPtr()
            : m_pObj(nullptr)
            , m_refCount(0)
        {}

        /// Construct a share pointer with given pointer
        /// @param T*
        SharedPtr(T* pObj)
            : m_pObj(pObj)
            , m_refCount(1)
        {}

        /// Copy constructor
        /// @param const SharecPtr<T>&
        SharedPtr(const SharedPtr<T>& obj)
        {
            m_pObj = obj.m_pObj;
            m_refCount = obj.m_refCount;
            m_refCount++;
        }

        /// Destructor
        ~SharedPtr()
        {
            if (--m_refCount == 0) {
                delete m_pObj;
            }
        }

        /// Returns the raw pointer
        /// @return T*
        T* get() const noexcept
        {
            return m_pObj;
        }

        /// Releases the internal raw pointer and start managing 
        /// the pointer of the paramenter
        /// @param T*
        void reset(T* obj) noexcept
        {
            if (m_pObj) {
                delete m_pObj;
                m_refCount = 0;
            }
            m_pObj = obj;
        }

        /// Swap this pointer with the paramenter
        /// @param SharedPtr<T>&
        void swap(SharedPtr<T>& sPtr) noexcept
        {
            // Use copy constructor
            SharedPtr temp(sPtr);

            sPtr.m_pObj = m_pObj;
            sPtr.m_refCount = m_refCount;

            m_pObj = temp.m_pObj;
            m_refCount = temp.m_refCount;

            // Note: the copy constructor above increments the reference counter,
            // therefore we need to decrement here
            m_refCount--;
        }

        /// Returns the number of reference to this object
        /// @return m_refCount
        inline std::size_t count() const
        {
            return m_refCount;
        }

        /// Operators
        SharedPtr<T>& operator=(const SharedPtr<T>& sPtr) const noexcept
        {
            m_pObj = sPtr.m_pObj;
            m_refCount = sPtr.m_refCount;
        }

        T& operator*() const noexcept
        {
            return *m_pObj;
        }

        T* operator->() const noexcept
        {
            return m_pObj;
        }

        T& operator[](std::size_t idx) const
        {
            return *(m_pObj + idx);
        }

        explicit operator bool() const noexcept
        {
            return m_pObj == nullptr;
        }

    private:
        T* m_pObj;
        std::size_t m_refCount;
    };
} // namespace DStructs

#endif // DSTRUCTS_SHARED_PTR_H