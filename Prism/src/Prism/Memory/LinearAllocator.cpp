#include "pmpch.h"

#include "Prism/Memory/LinearAllocator.h"
#include "Utils/MemoryUtils.h"

namespace Prism
{
    static int count = 0;
    void LinearAllocator::Init(std::size_t allocationSize)
    {
        if (m_StartPtr != nullptr)
        {
            FreePool(); // FIXME: Not Sure
        }
        m_StartPtr = malloc(allocationSize);
        memset(m_StartPtr, -1, allocationSize);

        PM_CORE_INFO("Allocate {0} Bytes in memory.", allocationSize);
        m_Offset = 0;
        m_TotalSize = allocationSize;

        MemoryUtils::WhatsBehindThatPointer(m_StartPtr, allocationSize);
    }

    std::size_t LinearAllocator::alignMemory(std::size_t baseAddress, std::size_t alignment)
    {
        const std::size_t multiplier = (baseAddress / alignment) + 1;
        const std::size_t alignedAddress = multiplier * alignment;
        const std::size_t padding = alignedAddress - baseAddress;
        return padding;
    }

    void *LinearAllocator::allocate(std::size_t size, std::size_t alignment)
    {
        count++;
        PM_CORE_TRACE("Enter allocate {0} time to allocate {1} memory", count, size);

        std::size_t padding = 0;
        const std::size_t currentAddres = m_Offset + (std::size_t)m_StartPtr;
        if (alignment != 0 && m_Offset % alignment != 0)
        {
            std::cout << "Entered alignmen";
            padding = alignMemory(currentAddres, alignment);
        }

        if (m_Offset + size + padding >= m_TotalSize)
        {
            PM_CORE_CRITICAL("Memory Full. Please Allocate More Memory. \n Max Memory allowed : %zu\n Required Memory : %zu Bytes", m_TotalSize, (m_Offset + size + padding) - m_TotalSize);
            return nullptr;
        }

        PM_CORE_TRACE("Current memory address %zu", currentAddres);

        m_Offset += size;
        const std::size_t nextPtr = currentAddres + padding;

        PM_CORE_TRACE("Padding is : {0} Alignment : {1}", padding, alignment);
        PM_CORE_TRACE("Next Address : {0} \n Offset is : {1}", nextPtr, m_Offset);

        return (void *)nextPtr;
    }

    void LinearAllocator::deallocate(void *ptr)
    {
        PM_TRACE("Linear Allocator does not support individual deallocations\n", false);
    }

    void LinearAllocator::deallocate(void *ptr, std::size_t size)
    {
        PM_TRACE("Linear Allocator does not support individual deallocations\n", false);
    }

    void LinearAllocator::ResetPool()
    {
        PM_CORE_WARN("ResetPool Called, current Offset is : {0}", m_Offset);
        m_Offset = 0;
        memset(m_StartPtr, -1, m_TotalSize); // FIXME: Not sure cause it maight casue perfgormance lag
        PM_CORE_WARN("memory Add : {1}", std::size_t(m_StartPtr));
    }

    void LinearAllocator::FreePool()
    {
        free(m_StartPtr);
        m_StartPtr = nullptr;
    }

    void LinearAllocator::Print()
    {
        PM_CORE_WARN("PRINTING HEAP DATA", true);
        std::cout << sizeof(m_StartPtr) << std::endl;
        std::cout << m_StartPtr << std::endl;
        std::cout << &m_StartPtr << std::endl;
        std::cout << *&m_StartPtr << std::endl;
        std::cout << sizeof(*&m_StartPtr) << std::endl;

        MemoryUtils::WhatsBehindThatPointer(m_StartPtr, m_TotalSize);
    }
} // namespace Prism
