#pragma once

#include "Prism/Memory/MemoryAllocator.h"

void *operator new(std::size_t size)
{
    printf("%zu\n", size);
    return Prism::MemoryAllocator::allocate(size);
}

void *operator new[](std::size_t size)
{
    printf("Inside new array %zu\n", size);
    return Prism::MemoryAllocator::allocate(size);
}

void operator delete(void *ptr) noexcept
{
    Prism::MemoryAllocator::deallocate(ptr);
}

void operator delete(void *ptr, std::size_t size) noexcept
{
    Prism::MemoryAllocator::deallocate(ptr, size);
}