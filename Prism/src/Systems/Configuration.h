#pragma once

#include "Prism/Core/Base.h"

namespace Prism
{
    struct Config
    {
        size_t ChunkSize;
        size_t TotalChunks;
        size_t TotalSize;
    };

    class PM_API Configuration
    {
    public:
        static bool ReadConfig();
        static bool ReadConfig(const std::string &filepath);

    private:
        static bool Deserialize(const std::string &filepath);
    };
} // namespace Prism
