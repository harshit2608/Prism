#include "pmpch.h"

#include "Prism/Memory/PoolAllocator.h"

namespace Prism
{
    void PoolAllocator::Init(Config &configVals) {}

    void *PoolAllocator::allocate(size_t size) { return {}; }

    void PoolAllocator::deallocate(void *ptr) {}

    void PoolAllocator::deallocate(void *ptr, size_t size) {}

    void PoolAllocator::ResetPool() {}
} // namespace Prism
