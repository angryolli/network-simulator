#pragma once

#include <string>
#include <map>

namespace netsim {

/**
 * @brief Manages simulation configuration and parameters
 * 
 * Handles loading and storing simulation parameters from configuration
 * files or programmatic configuration. Supports flexible network setup.
 */
class ConfigManager {
public:
    /**
     * @brief Construct a new ConfigManager object
     */
    ConfigManager();
    
    /**
     * @brief Destroy the ConfigManager object
     */
    ~ConfigManager() = default;
    
    /**
     * @brief Load configuration from file
     * @param filename Configuration file path
     * @return true if successful, false otherwise
     */
    bool loadFromFile(const std::string& filename);
    
    /**
     * @brief Get configuration value
     * @param key Configuration key
     * @return std::string Configuration value
     */
    std::string getValue(const std::string& key) const;
    
    /**
     * @brief Set configuration value
     * @param key Configuration key
     * @param value Configuration value
     */
    void setValue(const std::string& key, const std::string& value);
    
    // TODO: Implement configuration file parsing
    // TODO: Add validation for configuration parameters
    // TODO: Support different configuration formats
    
private:
    std::map<std::string, std::string> config_;  ///< Configuration parameters
};

} // namespace netsim
