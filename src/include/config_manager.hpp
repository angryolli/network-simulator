#pragma once

#include <string>
#include <map>

namespace netsim {

// Manages simulation configuration and parameters
// Handles loading and storing simulation parameters from configuration
// files or programmatic configuration. Supports flexible network setup.
class ConfigManager {
public:
    // Construct a new ConfigManager object
    ConfigManager();
    
    // Destroy the ConfigManager object
    ~ConfigManager() = default;
    
    // Load configuration from file
    // filename: Configuration file path
    // Returns: true if successful, false otherwise
    bool loadFromFile(const std::string& filename);
    
    // Get configuration value
    // key: Configuration key
    // Returns: Configuration value
    std::string getValue(const std::string& key) const;
    
    // Set configuration value
    // key: Configuration key
    // value: Configuration value
    void setValue(const std::string& key, const std::string& value);
    
    // TODO: Implement configuration file parsing, validation, and support for different formats
    
private:
    std::map<std::string, std::string> config_;  // Configuration parameters
};

}
