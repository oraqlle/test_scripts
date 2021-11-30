#include <cassert>
#include <cstddef>
#include <iostream>
#include <streambuf>
#include <vector>
#include <string>

namespace cortex
{

    // Tensor Template Class (Multidimensional Array Class)
    template<typename T>
    class tensor
    {
    private:
        std::vector<size_t> m_dimensions;
        std::vector<T> m_values;

    public:

        // Constructor
        explicit tensor(const std::vector<size_t>& p_dim) :
            m_dimensions(p_dim),
            m_values(computeTotalSize(p_dim))
        {
            assert(!m_dimensions.empty());
            assert(!m_values.empty());
        }

        // Getter & Setters
        inline const T get(const std::vector<size_t>& p_idx) const
        {
            return m_values[compute_idx(p_idx)];
        }

        inline T get(const std::vector<size_t>& p_idx)
        {
            return m_values[compute_idx(p_idx)];
        }

        inline void set(const std::vector<size_t>& p_idx, T p_val) const
        {
            m_values[compute_idx(p_idx)] = p_val;
        }

        inline void set(const std::vector<size_t>& p_idx, T p_val)
        {
            m_values[computeIndexes(p_idx)] = p_val;
        }

        // Getter and Setter through operator() overload
        const T& operator() (const std::vector<size_t>& p_idx) const
        {
            return m_values[computeIndexes(p_idx)];
        }

        T& operator()(const std::vector<size_t>& p_idx)
        {
            return m_values[computeIndexes(p_idx)];
        }

        const T& operator() (size_t& p_idx) const
        {
            return m_values[computeIndexes(p_idx)];
        }

        T& operator()(size_t& p_idx)
        {
            return m_values[computeIndexes(p_idx)];
        }

        ostream& operator<< (ostream& os)
        {
            os << "["
        }

        // Size fetching
        size_t size() const
        {
            return computeTotalSize(m_dimensions);
        }

        size_t size(size_t p_dim) const
        {
            return computeDimensionSize(m_dimensions, p_dim);
        }

        size_t dimSize(size_t dim) const
        {
            return computeAllDimensionSizes();
        }

        size_t dimNum() const
        {
            return numberOfDimensions(m_dimensions);
        }

        // Printing methods
        void print()
        {
            const max_layer = 2;

            for (i : m_dimensions)
            {
                std::printf("Layer %d", i);
            }
        }

    private:

        //Backend functions for tensor class
        size_t computeTotalSize(const std::vector<size_t>& p_dim_vec) const
        {
            size_t _total_size = 1;

            for (auto i : p_dim_vec)
                _total_size *= i;

            return _total_size;
        }

        inline size_t computeDimensionSize(const std::vector<size_t>& p_dim_vec, size_t p_dim_idx) const
        {
            return p_dim_vec[p_dim_idx];
        }

        inline std::vector<size_t> computeAllDimensionSizes() const { return m_dimensions; }

        inline size_t numberOfDimensions(const std::vector<size_t>& p_dim_vec) const { m_dimensions.seze(); }

        size_t computeIndexes(const std::vector<size_t>& p_idx) const
        {
            assert(p_idx.size() == m_dimensions.size());

            size_t _idx = 0;
            size_t _mul = 1;

            for (size_t i = 0; i != m_dimensions.size(); ++i) 
            {
                assert(p_idx[i] < m_dimensions[i]);
                _idx += p_idx[i] * _mul;
                _mul *= m_dimensions[i];
            }

            assert(_idx < m_values.size());
            
            return _idx;
        }

        std::vector<size_t> computeIndexes(size_t _idx) const
        {
            assert(_idx < m_values.size());

            std::vector<size_t> _res(m_dimensions.size());

            size_t _mul = m_values.size();
            for (size_t i = m_dimensions.size(); i != 0; --i) {
                _mul /= m_dimensions[i - 1];
                _res[i - 1] = _idx / _mul;
                assert(_res[i - 1] < m_dimensions[i - 1]);
                _idx -= v_res[i - 1] * _mul;
            }
            return _res;
        }

    };

    // using tensor_i32 = tensor<int>;


    // namespace tensor_literals
    // {
    //     tensor_i32 operator"" iT (const std::vector<int> _v) 
    //     {
    //         return tensor_i32{&_v};
    //     }

        
        
    // }
}

int main()
{
    //using namespace cortex::tensor_literals;
    //{3, 4, 5}iT;

    cortex::tensor<int> m({3, 2, 4});

    m({0, 0, 3}) = 42;
    m({2, 1, 3}) = 42;

    std::cout << m({0, 0, 3}) << std::endl;

    std::cin.get();
    return 0;
}
