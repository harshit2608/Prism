#pragma once

#include "Prism/Core/Base.h"

#include <unordered_map>

namespace Prism
{
	enum class AllocationCategory
	{
		CurrentAllocations,
		TotalAllocation,
		TotalDeallocations,
		TotalAllocateMemory,
		MaxMemoryAllowed
	};

	std::unordered_map<AllocationCategory, double> m_AllocationTracker;

	class MemoryTrack
	{
	public:
	private:
	};

} // namespace Prism
