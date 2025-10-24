#pragma once

#include <string>
#include <QPointF>

namespace netsim {

// Defines movement behavior for mobile nodes
// Contains movement logic and parameters for mobile node simulation.
// Linked to MobileNode via mobility_id for dynamic position updates.
class Mobility {
public:
    // Construct a new Mobility object
    // mobilityId: Mobility identifier
    explicit Mobility(const std::string& mobilityId);
    
    // Destroy the Mobility object
    ~Mobility() = default;
    
    // Get mobility ID
    // Returns: Mobility identifier
    const std::string& getMobilityId() const;
    
    // Calculate next position
    // currentPosition: Current position
    // deltaTime: Time step
    // Returns: Next position
    QPointF calculateNextPosition(const QPointF& currentPosition, double deltaTime);
    
    // TODO: Implement movement models, velocity/acceleration management, and boundary handling
    
private:
    std::string mobilityId_;  // Mobility identifier
};

}
