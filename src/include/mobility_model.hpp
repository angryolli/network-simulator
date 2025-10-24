#pragma once

#include <vector>
#include <memory>
#include <string>

namespace netsim {

// Forward declarations
class MobileNode;
class Mobility;

// Manages mobility simulation for all mobile nodes
// Coordinates movement of multiple mobile nodes and updates their
// positions during simulation runtime.
class MobilityModel {
public:
    // Construct a new MobilityModel object
    MobilityModel();
    
    // Destroy the MobilityModel object
    ~MobilityModel() = default;
    
    // Add mobile node to mobility simulation
    // node: Shared pointer to mobile node
    void addMobileNode(std::shared_ptr<MobileNode> node);
    
    // Update all mobile node positions
    // deltaTime: Time step
    void updatePositions(double deltaTime);
    
    // TODO: Implement coordinated movement simulation, collision detection/avoidance, and different mobility patterns
    
private:
    std::vector<std::shared_ptr<MobileNode>> mobileNodes_;  // Mobile nodes in simulation
};

} // namespace netsim
