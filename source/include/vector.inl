#include "vector.h"
#include <iostream>
/// Iterator accessor methods.

namespace sc {
    /// Returns a regular iterator to the begining of the list.
    template < typename T >
    typename vector<T>::iterator  vector<T>::begin(void)
    {
        return iterator(&m_storage[0]);
    }

    template < typename T >
    typename vector<T>::iterator  vector<T>::end(void)
    {
        return iterator(&m_storage[m_end]);
    }

    template < typename T >
    typename vector<T>::const_iterator  vector<T>::cbegin(void) const
    {
        return const_iterator(&m_storage[0]);
    }

    template < typename T >
    typename vector<T>::const_iterator  vector<T>::cend(void) const
    {
        return const_iterator(&m_storage[m_end]);
    }

    //===============================================================
    //======================== CAPACIDADE ===========================
    //===============================================================

    template < typename T >
    typename vector<T>::size_type  vector<T>::size(void)const
    {
        return m_end;
    }

    template < typename T >
    typename vector<T>::size_type  vector<T>::capacity(void) const
    {
        return m_capacity;
    }

    template < typename T >
    bool vector<T>::empty(void)const
    {
        return m_end == 0;
    }


    template < typename T >
    void vector<T>::clear(void)
    {
        //for (auto p = m_storage[0]; p != m_storage[m_end]; ++p)
        //    p.~T();
        //m_end = 0;
        
        while (m_end != 0)
        {
            m_storage[m_end].~T();
            m_end--;
        }
    }

    template < typename T >
    void vector<T>::push_front(const_reference value)
    {
        m_storage = std::make_unique<T>
            (std::move(value),
            std::move(m_storage)
            );
        m_end++;
    }

    template < typename T >
    void vector<T>::reserve(size_type new_capacity)
    {    
        if (new_capacity <= m_capacity) {
            goto final;
        }
        else {
      
            auto new_storage = std::make_unique<T[]>(new_capacity * sizeof(T));

            for (auto i = 0; i < m_end; ++i)
                new_storage[i] = m_storage[i];

            auto m_end_rec = m_end;

            while (m_end != 0)
            {
                m_storage[m_end].~T();
                m_end--;
            }

            m_storage = std::move(new_storage);

            m_end = m_end_rec;
            m_capacity = new_capacity;
        }
        final: ;
    }

    template < typename T >
    void vector<T>::push_back (const_reference value)
    {

        if (m_capacity == m_end)
        {
            if (m_end == 0) {
                reserve(2);
                //m_storage agora tem dois espaço de memória
                m_storage[0] = value;
                m_end++;
            }
            else {
                reserve(size() * 2);
                m_storage[m_end++] = value;
            }

            // adicionando o valor no proxima espaço de memória válido
            //m_end++;
           
        } 
        //throw std::length_error{ "Array ta cheio!!" };
        else { m_storage[m_end++] = value; }
    }

    template < typename T >
    void vector<T>::pop_back(void)
    {
        if (m_end > 0)
        {
            m_end--;
            m_storage[m_end].~T();
        }
    }

    template < typename T >
    void vector<T>::pop_front(void)
    {
        if (m_end > 0)
        {
            m_storage[0].~T();
            m_end--;
        }
    }

    //=============================================================================
    //=========================== [V] Element access===============================
    //=============================================================================
    template < typename T >
    typename vector<T>::reference vector<T>::operator[](size_type index)
    {
        //assert(index >= 0 && index < m_end);
        return m_storage[index];
    }

    template < typename T >
    typename vector<T>::const_reference vector<T>::operator[](size_type index)const
    {
        assert(index >= 0 && index < m_end);
        return m_storage[index];
    }
    /*
    template < typename T >
    typename vector<T>::const_reference vector<T>::back(void) const
    {
        std::cout << "a";
        return *cend();
    }

    
    template < typename T >
    typename vector<T>::const_reference vector<T>::front(void) const
    {
        return *cbegin();
    }

    template < typename T >
    typename vector<T>::reference vector<T>::back(void) 
    {
        return *(end());
        // deveria ser end() -1
    }
    */
    //template < typename T >
    //typename vector<T>::reference vector<T>::front(void) 
    //{
     //   return reference;// (m_storage[0]);
    //    
    //}

    template < typename T >
    typename vector<T>::const_reference vector<T>::at(size_type i) const
    {
        if (i < 0 || i >= size()) {
            throw std::out_of_range(" ");
        }
        return this->m_storage[i];
    }

    template < typename T >
    typename vector<T>::reference vector<T>::at(size_type i)
    {
        //std::cout << i;
        if (i < 0 || i >= size()) {
            throw std::out_of_range(" ");
        }
        return this->m_storage[i];
    }

    template < typename T >
    typename vector<T>::pointer vector<T>::data(void)
    {

    }

    template < typename T >
    typename vector<T>::const_reference vector<T>::data(void) const
    {

    }

    template<typename T>
    inline bool vector<T>::full(void) const
    {
        if (m_end == m_capacity)
            return true;
        return false;
    }


    template<typename T>
    inline void vector<T>::emplace_back(reference& args)
    {
        // refazer depois
        if (m_end >= m_capacity)
            reserve(m_capacity + m_capacity / 2);

        auto new_storage = std::make_unique<T[]>(std::forward<T>(args));
        ++m_end;
        return *new_storage;
    }

    template<typename T>
    inline void vector<T>::emplace_back(const_reference& args)
    {
        // refazer depois
        if (m_end >= m_capacity)
            reserve(m_capacity + m_capacity / 2);

        auto new_storage = std::make_unique<T[]>(std::forward<T>(args));
        ++m_end;
        return *new_storage;
    }

    template<typename T>
    inline typename vector<T>::iterator vector<T>::insert(iterator pos_, const_reference value_)
    {
        return iterator();
    }

    template<typename T>
    inline typename vector<T>::iterator vector<T>::insert(const_iterator pos_, const_reference value_)
    {
        return iterator();
    }

    //template<typename T>
    //inline vector<T>::iterator sc::vector<T>::erase(iterator pos)
    //{
    //    return iterator();
    //}
}
