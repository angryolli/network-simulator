#include "node_item.hpp"
#include <QPainter>
#include <QStyleOptionGraphicsItem>

namespace netsim {
namespace gui {

NodeItem::NodeItem(const QString& nodeId, qreal x, qreal y)
    : nodeId_(nodeId), radius_(20.0)
{
    setPos(x, y);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    
    // TODO: Initialize node appearance and set up interaction flags
}

QString NodeItem::getNodeId() const
{
    return nodeId_;
}

void NodeItem::setPosition(qreal x, qreal y)
{
    // TODO: Update position and notify connected links of position change
    setPos(x, y);
}

QRectF NodeItem::boundingRect() const
{
    // TODO: Return bounding rectangle for node
    return QRectF(-radius_, -radius_, 2 * radius_, 2 * radius_);
}

void NodeItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    
    // TODO: Draw node representation, handle different node states, and add node type indicators
    
    painter->setPen(QPen(Qt::black, 2));
    painter->setBrush(QBrush(QColor(173, 216, 230))); // Light blue
    painter->drawEllipse(-radius_, -radius_, 2 * radius_, 2 * radius_);
    
    // Draw node ID
    painter->setPen(Qt::black);
    painter->drawText(QRectF(-radius_, -radius_, 2 * radius_, 2 * radius_), 
                     Qt::AlignCenter, nodeId_);
}

} // namespace gui
} // namespace netsim
