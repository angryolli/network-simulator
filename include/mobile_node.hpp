#pragma once

#include "node.hpp"
#include <QPointF>

namespace netsim {

// Forward declarations
class Mobility;

/**
 * @brief Mobile node with 2D coordinates and signal range
 * 
 * Extends Node with mobility capabilities for wireless network simulation.
 * Communication is restricted by signal range, enabling realistic wireless scenarios.
 */
class MobileNode : public Node {
public:
    /**
     * @brief Construct a new MobileNode object
     * @param address Node address
     * @param position Initial 2D position
     * @param range Signal range
     */
    MobileNode(const std::string& address, const QPointF& position, double range);
    
    /**
     * @brief Destroy the MobileNode object
     */
    ~MobileNode() = default;
    
    /**
     * @brief Get current position
     * @return QPointF Current 2D position
     */
    QPointF getPosition() const;
    
    /**
     * @brief Set position
     * @param position New 2D position
     */
    void setPosition(const QPointF& position);
    
    /**
     * @brief Get signal range
     * @return double Signal range
     */
    double getRange() const;
    
    /**
     * @brief Check if another node is in range
     * @param other Other mobile node
     * @return true if in range, false otherwise
     */
    bool isInRange(const MobileNode& other) const;
    
    // TODO: Implement mobility management
    // TODO: Add signal strength calculation
    // TODO: Implement dynamic connectivity updates
    
private:
    QPointF position_;      ///< Current 2D position
    double range_;          ///< Signal range
    std::unique_ptr<Mobility> mobility_;  ///< Mobility behavior
};

} // namespace netsim
