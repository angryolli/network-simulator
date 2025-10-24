#pragma once

#include <vector>
#include <memory>
#include <string>

namespace netsim {

// Forward declarations
class Node;
class Link;
class EventQueue;
class Stats;
class ConfigManager;

// Main simulation engine managing the entire network simulation
// Owns all nodes, links, and simulation components. Coordinates
// the discrete-event simulation process and manages simulation state.
class NetworkSimulator {
public:
    // Construct a new NetworkSimulator object
    NetworkSimulator();
    
    // Destroy the NetworkSimulator object
    ~NetworkSimulator() = default;
    
    // Add a node to the simulation
    // node: Shared pointer to node
    void addNode(std::shared_ptr<Node> node);
    
    // Add a link to the simulation
    // link: Shared pointer to link
    void addLink(std::shared_ptr<Link> link);
    
    // Start the simulation
    void start();
    
    // Stop the simulation
    void stop();
    
    // TODO: Implement simulation control logic, network topology management, and statistics collection
    
private:
    std::vector<std::shared_ptr<Node>> nodes_;     // Simulation nodes
    std::vector<std::shared_ptr<Link>> links_;      // Simulation links
    std::unique_ptr<EventQueue> eventQueue_;        // Event processing queue
    std::unique_ptr<Stats> stats_;                  // Statistics collector
    std::unique_ptr<ConfigManager> config_;         // Configuration manager
    bool running_;                                   // Simulation running state
};

} // namespace netsim
