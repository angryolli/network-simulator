#pragma once

#include <vector>
#include <memory>
#include <string>

namespace netsim {

// Forward declarations
class MobileNode;
class Mobility;

/**
 * @brief Manages mobility simulation for all mobile nodes
 * 
 * Coordinates movement of multiple mobile nodes and updates their
 * positions during simulation runtime.
 */
class MobilityModel {
public:
    /**
     * @brief Construct a new MobilityModel object
     */
    MobilityModel();
    
    /**
     * @brief Destroy the MobilityModel object
     */
    ~MobilityModel() = default;
    
    /**
     * @brief Add mobile node to mobility simulation
     * @param node Shared pointer to mobile node
     */
    void addMobileNode(std::shared_ptr<MobileNode> node);
    
    /**
     * @brief Update all mobile node positions
     * @param deltaTime Time step
     */
    void updatePositions(double deltaTime);
    
    // TODO: Implement coordinated movement simulation
    // TODO: Add collision detection and avoidance
    // TODO: Implement different mobility patterns
    
private:
    std::vector<std::shared_ptr<MobileNode>> mobileNodes_;  ///< Mobile nodes in simulation
};

} // namespace netsim
