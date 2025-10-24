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

// Graphics item representing a network link
// Visual representation of links connecting nodes in the network simulation.
// Handles drawing and animation of packet transmission.
class LinkItem : public QGraphicsItem {
public:
    // Construct a new LinkItem object
    // sourceNode: Source node item
    // destNode: Destination node item
    LinkItem(NodeItem* sourceNode, NodeItem* destNode);
    
    // Destroy the LinkItem object
    ~LinkItem() = default;
    
    // Update link appearance based on utilization
    // utilization: Link utilization (0.0 to 1.0)
    void setUtilization(double utilization);
    
    // QGraphicsItem interface
    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    
    // TODO: Implement link visualization, packet animation support, and utilization-based coloring
    
private:
    NodeItem* sourceNode_;    // Source node item
    NodeItem* destNode_;      // Destination node item
    double utilization_;       // Current link utilization
};

} // namespace gui
} // namespace netsim
