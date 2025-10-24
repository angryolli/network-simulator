#pragma once

#include "node.hpp"
#include <QPointF>

namespace netsim {

// Forward declarations
class Mobility;

// Mobile node with 2D coordinates and signal range
// Extends Node with mobility capabilities for wireless network simulation.
// Communication is restricted by signal range, enabling realistic wireless scenarios.
class MobileNode : public Node {
public:
    // Construct a new MobileNode object
    // address: Node address
    // position: Initial 2D position
    // range: Signal range
    MobileNode(const std::string& address, const QPointF& position, double range);
    
    // Destroy the MobileNode object
    ~MobileNode() = default;
    
    // Get current position
    // Returns: Current 2D position
    QPointF getPosition() const;
    
    // Set position
    // position: New 2D position
    void setPosition(const QPointF& position);
    
    // Get signal range
    // Returns: Signal range
    double getRange() const;
    
    // Check if another node is in range
    // other: Other mobile node
    // Returns: true if in range, false otherwise
    bool isInRange(const MobileNode& other) const;
    
    // TODO: Implement mobility management, signal strength calculation, and dynamic connectivity updates
    
private:
    QPointF position_;      // Current 2D position
    double range_;          // Signal range
    std::unique_ptr<Mobility> mobility_;  // Mobility behavior
};

} // namespace netsim
