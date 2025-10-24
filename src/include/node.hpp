#pragma once

#include <string>
#include <vector>
#include <memory>

namespace netsim {

// Forward declarations
class Interface;
class TrafficGenerator;

/**
 * @brief Represents a network node that can act as end-host, router, or both
 * 
 * Each node has an address and can send/receive packets through interfaces.
 * Nodes can have multiple roles: EndHost, Router, or both.
 */
class Node {
public:
    /**
     * @brief Construct a new Node object
     * @param address Node address identifier
     */
    explicit Node(const std::string& address);
    
    /**
     * @brief Destroy the Node object
     */
    ~Node() = default;
    
    /**
     * @brief Get the node address
     * @return const std::string& Node address
     */
    const std::string& getAddress() const;
    
    /**
     * @brief Add an interface to this node
     * @param interface Shared pointer to interface
     */
    void addInterface(std::shared_ptr<Interface> interface);
    
    // TODO: Implement packet sending logic
    // TODO: Implement packet receiving logic
    // TODO: Add routing table management
    // TODO: Implement role-based behavior (EndHost/Router)
    
private:
    std::string address_;                                    ///< Node address
    std::vector<std::shared_ptr<Interface>> interfaces_;   ///< Connected interfaces
    std::shared_ptr<TrafficGenerator> trafficGenerator_;    ///< Traffic generation component
};

} // namespace netsim
