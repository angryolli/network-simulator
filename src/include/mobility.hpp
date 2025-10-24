#pragma once

#include <string>
#include <QPointF>

namespace netsim {

/**
 * @brief Defines movement behavior for mobile nodes
 * 
 * Contains movement logic and parameters for mobile node simulation.
 * Linked to MobileNode via mobility_id for dynamic position updates.
 */
class Mobility {
public:
    /**
     * @brief Construct a new Mobility object
     * @param mobilityId Mobility identifier
     */
    explicit Mobility(const std::string& mobilityId);
    
    /**
     * @brief Destroy the Mobility object
     */
    ~Mobility() = default;
    
    /**
     * @brief Get mobility ID
     * @return const std::string& Mobility identifier
     */
    const std::string& getMobilityId() const;
    
    /**
     * @brief Calculate next position
     * @param currentPosition Current position
     * @param deltaTime Time step
     * @return QPointF Next position
     */
    QPointF calculateNextPosition(const QPointF& currentPosition, double deltaTime);
    
    // TODO: Implement movement models (random walk, waypoint, etc.)
    // TODO: Add velocity and acceleration management
    // TODO: Implement boundary handling
    
private:
    std::string mobilityId_;  ///< Mobility identifier
};

} // namespace netsim
