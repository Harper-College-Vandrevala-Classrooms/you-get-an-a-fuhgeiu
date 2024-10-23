#include <iostream>


namespace container {

template <typename T>
class m_data {
    
    size_t* m_data_ID = nullptr;       // store ID
    size_t m_length;
    T* cd_data = nullptr;               // store content
    size_t cd_length;
    
    
// add to container
public:
    
    void add_data (T* data,size_t id) {
        
        auto m_block = new size_t[m_length + 1];
        for (size_t i = 0; i < m_length; i++) m_block[i] = std::move(*m_data_ID[i]);
        m_length++;
        m_data_ID = m_block;
        m_data_ID[m_length] = id;
        
        auto cd_block = new T [m_length];
        for (size_t i = 0; i < cd_length; i++) cd_block[i] = std::move(*cd_data[i]);
        cd_length++;
        cd_data = cd_block;
        cd_data[cd_length] = data;
    }
    
    
    
    
    
    
};


}
