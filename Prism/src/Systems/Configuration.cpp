#include "pmpch.h"

#include "Systems/Configuration.h"

// #include <yaml-cpp/yaml.h>

namespace Prism
{
    // bool Configuration::ReadConfig()
    // {
    //     const std::string filepath = "Config/config.yaml";
    //     return Deserialize(filepath);
    // }

    // bool Configuration::ReadConfig(const std::string &filepath)
    // {
    //     return Deserialize(filepath);
    // }

    // bool Configuration::Deserialize(const std::string &filepath)
    // {
    //     YAML::Node config;
    //     try
    //     {
    //         config = YAML::LoadFile(filepath);
    //     }
    //     catch (YAML::ParserException e)
    //     {
    //         PM_CORE_ERROR("Failed to load .hazel file %s \n %s", filepath.c_str(), e.what())
    //     }

    //     if (!config["Configurations"])
    //     {
    //         return false;
    //     }
    //     return false;
    // }
} // namespace Prism
