#pragma once

#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <QString>

namespace netsim {
namespace gui {

/**
 * @brief Graphics item representing a network node
 * 
 * Visual representation of nodes in the network simulation.
 * Handles drawing, selection, and interaction for network nodes.
 */
class NodeItem : public QGraphicsItem {
public:
    /**
     * @brief Construct a new NodeItem object
     * @param nodeId Node identifier
     * @param x X coordinate
     * @param y Y coordinate
     */
    NodeItem(const QString& nodeId, qreal x, qreal y);
    
    /**
     * @brief Destroy the NodeItem object
     */
    ~NodeItem() = default;
    
    /**
     * @brief Get node ID
     * @return QString Node identifier
     */
    QString getNodeId() const;
    
    /**
     * @brief Set node position
     * @param x X coordinate
     * @param y Y coordinate
     */
    void setPosition(qreal x, qreal y);
    
    // QGraphicsItem interface
    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    
    // TODO: Implement node visualization
    // TODO: Add selection and interaction handling
    // TODO: Implement different node types (router, host, mobile)
    
private:
    QString nodeId_;    ///< Node identifier
    qreal radius_;      ///< Node radius for drawing
};

} // namespace gui
} // namespace netsim
