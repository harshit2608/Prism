#include "pmpch.h"

#include "Prism/Memory/MemoryAllocator.h"

namespace Prism
{
	void MemoryAllocator::Init(std::size_t allocationSize)
	{
		// GetInstance().GetInstance().m_PoolAllocator.Init(allocationSize);
		GetInstance().m_LinearAllocator.Init(allocationSize);
	}

	void MemoryAllocator::Init(Config &vals)
	{
		// GetInstance().GetInstance().m_PoolAllocator.Init(vals);
	}

	void *MemoryAllocator::allocate(std::size_t size, std::size_t alignment)
	{
		return GetInstance().m_LinearAllocator.allocate(size, alignment);
	}

	void MemoryAllocator::deallocate(void *ptr)
	{
		GetInstance().m_LinearAllocator.deallocate(ptr);
	}

	void MemoryAllocator::deallocate(void *ptr, size_t size)
	{
		GetInstance().m_LinearAllocator.deallocate(ptr, size);
	}

	MemoryAllocator &MemoryAllocator::GetInstance()
	{
		static MemoryAllocator m_MemoryAllocator;
		return m_MemoryAllocator;
	}

} // namespace Prism
