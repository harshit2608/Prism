#pragma once

#include "Prism/Core/Base.h"
#include "Prism/Memory/PoolAllocator.h"
#include "Prism/Memory/LinearAllocator.h"

namespace Prism
{
    class MemoryAllocator
    {
    public:
        static void *allocate(std::size_t size, std::size_t alignment = 0);
        static void deallocate(void *ptr);
        static void deallocate(void *ptr, size_t size);

        static void Init(std::size_t allocationSize);
        static void Init(Config &vals);
        static void ResetPool() { GetInstance().m_LinearAllocator.ResetPool(); }

        static void Print()
        {
            GetInstance().m_LinearAllocator.Print();
        }

    private:
        MemoryAllocator() = default;
        ~MemoryAllocator()
        {
            // m_PoolAllocator.ResetPool
            m_LinearAllocator.FreePool();
        }

        MemoryAllocator(MemoryAllocator &other) = delete;
        void operator=(const MemoryAllocator &other) = delete;

        static MemoryAllocator &GetInstance();

    private:
        std::size_t m_TotalSize;
        std::size_t m_Used;
        std::size_t m_Peak;

    private:
        // PoolAllocator m_PoolAllocator;
        LinearAllocator m_LinearAllocator;
    };
} // namespace Prism
