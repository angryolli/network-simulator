#pragma once

#include <string>
#include <memory>
#include <queue>

namespace netsim {

// Forward declarations
class Packet;
class Link;

/**
 * @brief Represents a network interface connecting a node to a link
 * 
 * Interfaces handle packet queuing and transmission to connected links.
 * Each interface belongs to one node and connects to one link.
 */
class Interface {
public:
    /**
     * @brief Construct a new Interface object
     * @param id Interface identifier
     */
    explicit Interface(const std::string& id);
    
    /**
     * @brief Destroy the Interface object
     */
    ~Interface() = default;
    
    /**
     * @brief Get interface ID
     * @return const std::string& Interface identifier
     */
    const std::string& getId() const;
    
    /**
     * @brief Connect interface to a link
     * @param link Shared pointer to link
     */
    void connectToLink(std::shared_ptr<Link> link);
    
    // TODO: Implement packet queuing logic
    // TODO: Implement transmission scheduling
    // TODO: Add interface statistics tracking
    
private:
    std::string id_;                              ///< Interface identifier
    std::shared_ptr<Link> connectedLink_;         ///< Connected link
    std::queue<std::shared_ptr<Packet>> queue_;   ///< Packet transmission queue
};

} // namespace netsim
