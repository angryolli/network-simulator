#pragma once

#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <QString>

namespace netsim {
namespace gui {

// Forward declarations
class NodeItem;

/**
 * @brief Graphics item representing a network link
 * 
 * Visual representation of links connecting nodes in the network simulation.
 * Handles drawing and animation of packet transmission.
 */
class LinkItem : public QGraphicsItem {
public:
    /**
     * @brief Construct a new LinkItem object
     * @param sourceNode Source node item
     * @param destNode Destination node item
     */
    LinkItem(NodeItem* sourceNode, NodeItem* destNode);
    
    /**
     * @brief Destroy the LinkItem object
     */
    ~LinkItem() = default;
    
    /**
     * @brief Update link appearance based on utilization
     * @param utilization Link utilization (0.0 to 1.0)
     */
    void setUtilization(double utilization);
    
    // QGraphicsItem interface
    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    
    // TODO: Implement link visualization
    // TODO: Add packet animation support
    // TODO: Implement utilization-based coloring
    
private:
    NodeItem* sourceNode_;    ///< Source node item
    NodeItem* destNode_;      ///< Destination node item
    double utilization_;       ///< Current link utilization
};

} // namespace gui
} // namespace netsim
