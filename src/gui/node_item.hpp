#pragma once

#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <QString>

namespace netsim {
namespace gui {

// Graphics item representing a network node
// Visual representation of nodes in the network simulation.
// Handles drawing, selection, and interaction for network nodes.
class NodeItem : public QGraphicsItem {
public:
    // Construct a new NodeItem object
    // nodeId: Node identifier
    // x: X coordinate
    // y: Y coordinate
    NodeItem(const QString& nodeId, qreal x, qreal y);
    
    // Destroy the NodeItem object
    ~NodeItem() = default;
    
    // Get node ID
    // Returns: Node identifier
    QString getNodeId() const;
    
    // Set node position
    // x: X coordinate
    // y: Y coordinate
    void setPosition(qreal x, qreal y);
    
    // QGraphicsItem interface
    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    
    // TODO: Implement node visualization, selection/interaction handling, and different node types
    
private:
    QString nodeId_;    // Node identifier
    qreal radius_;      // Node radius for drawing
};

}
}
