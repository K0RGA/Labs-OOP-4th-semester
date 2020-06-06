#include "graphicsvector.h"

GraphicsVector::GraphicsVector(qreal x1, qreal y1, qreal x2, qreal y2)
    :QGraphicsLineItem(x1,y1,x2,y2)
{
    setPen(QPen(QBrush(Qt::black),2));
    setZValue(1);
    setToolTip(QString("Start Coords:(%1, %2))\nEnd Coords:(%3, %4))\nLength: %5").arg(line().x1()).arg(line().y1()).arg(line().x2()).arg(line().y2()).arg(line().length()));
    setCursor(QCursor(Qt::OpenHandCursor));
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | ItemSendsGeometryChanges);
    lline.setLine(line().x2() -0.2*line().dx() + 0.125*line().normalVector().dx(), line().y2() - 0.2*line().dy() + 0.125*line().normalVector().dy(), line().x2(), line().y2());
    rline.setLine(line().x2() -0.2*line().dx() - 0.125*line().normalVector().dx(), line().y2() - 0.2*line().dy() - 0.125*line().normalVector().dy(), line().x2(), line().y2());
}

GraphicsVector::GraphicsVector(const QLineF& linef)
    :QGraphicsLineItem(linef)
{
    setPen(QPen(QBrush(Qt::black),2));
    setZValue(1);
    setToolTip(QString("Start Coords:(%1, %2))\nEnd Coords:(%3, %4))\nLength: %5").arg(line().x1()).arg(line().y1()).arg(line().x2()).arg(line().y2()).arg(line().length()));
    setCursor(QCursor(Qt::OpenHandCursor));
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | ItemSendsGeometryChanges);
    lline.setLine(line().x2() -0.2*line().dx() + 0.125*line().normalVector().dx(), line().y2() - 0.2*line().dy() + 0.125*line().normalVector().dy(), line().x2(), line().y2());
    rline.setLine(line().x2() -0.2*line().dx() - 0.125*line().normalVector().dx(), line().y2() - 0.2*line().dy() - 0.125*line().normalVector().dy(), line().x2(), line().y2());
}

GraphicsVector::GraphicsVector(const GraphicsVector& other)
    :QGraphicsLineItem(other.line())
{
    setPen(QPen(QBrush(Qt::black),2));
    setZValue(1);
    setToolTip(QString("Start Coords:(%1, %2))\nEnd Coords:(%3, %4))\nLength: %5").arg(line().x1()).arg(line().y1()).arg(line().x2()).arg(line().y2()).arg(line().length()));
    setCursor(QCursor(Qt::OpenHandCursor));
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | ItemSendsGeometryChanges);
    lline = other.lline;
    rline = other.rline;
}

void GraphicsVector::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    painter->setPen(pen());
    painter->drawLine(line());
    painter->drawLine(lline);
    painter->drawLine(rline);
    painter->restore();
}

QPainterPath GraphicsVector::shape() const
{
    QPainterPath path(QPointF(line().x1(), line().y1()));
    path.lineTo(line().x2(), line().y2());
    path.lineTo(rline.x1(), rline.y1());
    path.moveTo(lline.x1(), lline.y1());
    path.lineTo(line().x2(), line().y2());
    QPainterPathStroker stroker;
    stroker.setWidth(pen().widthF()*1.5);
    return stroker.createStroke(path);
}

GraphicsVector& GraphicsVector::operator=(const GraphicsVector& operand)
{
    prepareGeometryChange();
    setLine(operand.line());
    setPen(QPen(QBrush(Qt::black),2));
    setZValue(1);
    setToolTip(QString("Start Coords:(%1, %2))\nEnd Coords:(%3, %4))\nLength: %5").arg(line().x1()).arg(line().y1()).arg(line().x2()).arg(line().y2()).arg(line().length()));
    setCursor(QCursor(Qt::OpenHandCursor));
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | ItemSendsGeometryChanges);
    lline = operand.lline;
    rline = operand.rline;
    return *this;
}

GraphicsVector& GraphicsVector::operator=(const QGraphicsLineItem& operand)
{
    setLine(operand.line());
    setZValue(1);
    setToolTip(QString("Start Coords:(%1, %2))\nEnd Coords:(%3, %4))\nLength: %5").arg(line().x1()).arg(line().y1()).arg(line().x2()).arg(line().y2()).arg(line().length()));
    setCursor(QCursor(Qt::OpenHandCursor));
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    lline.setLine(line().x2() - 0.2*line().dx() + 0.125*line().normalVector().dx(), line().y2() - 0.2*line().dy() + 0.125*line().normalVector().dy(), line().x2(), line().y2());
    rline.setLine(line().x2() - 0.2*line().dx() - 0.125*line().normalVector().dx(), line().y2() - 0.2*line().dy() - 0.125*line().normalVector().dy(), line().x2(), line().y2());
    return *this;
}

GraphicsVector GraphicsVector::operator+(const GraphicsVector& operand)
{
    return GraphicsVector(0, 0, line().dx() + operand.line().dx(), line().dy() + operand.line().dy());
}

GraphicsVector GraphicsVector::operator-(const GraphicsVector& operand)
{
    return GraphicsVector(0, 0, line().dx() - operand.line().dx(), line().dy() - operand.line().dy());
}

GraphicsVector GraphicsVector::operator-()
{
    return GraphicsVector(0, 0, -line().dx(), -line().dy());
}

GraphicsVector operator*(qreal coef, const GraphicsVector& vector)
{
    return GraphicsVector(vector.line().x1(), vector.line().y1(), vector.line().x1() + vector.line().dx() * coef, vector.line().y1() + vector.line().dy() * coef);
}

GraphicsVector operator*(const GraphicsVector& vector, qreal coef)
{
    return GraphicsVector(vector.line().x1(), vector.line().y1(), vector.line().x1() + vector.line().dx() * coef, vector.line().y1() + vector.line().dy() * coef);
}

qreal operator*(const GraphicsVector& operand1, const GraphicsVector& operand2)
{
    return (operand1.line().dx() * operand2.line().dx() + operand1.line().dy() * operand2.line().dy());
}

QVariant GraphicsVector::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if(change == QGraphicsItem::ItemSelectedHasChanged)
    {
        if(value != 0)
        {
            QPen pent = pen();
            pent.setBrush(Qt::blue);
            setPen(pent);
            if(selected_count == 0)
                max_number = 0;
            max_number++;
            selected_count++;
            selection_number = max_number;
        }
        else
        {
            QPen pent = pen();
            pent.setBrush(Qt::black);
            setPen(pent);
            selected_count--;
            selection_number = 0;
        }
    }
    if(change == QGraphicsItem::ItemPositionHasChanged)
    {
        setToolTip(QString("Start Coords:(%1, %2))\nEnd Coords:(%3, %4))\n").arg(scenePos().x() + line().x1()).arg(scenePos().y() + line().y1()).arg(scenePos().x() + line().x2()).arg(scenePos().y() + line().y2()));
    }
    return QGraphicsItem::itemChange(change, value);
}

void GraphicsVector::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    setCursor(QCursor(Qt::ClosedHandCursor));
    QGraphicsLineItem::mousePressEvent(event);
}

void GraphicsVector::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    setCursor(QCursor(Qt::OpenHandCursor));
    QGraphicsLineItem::mouseReleaseEvent(event);
}


int GraphicsVector::seletion_number()
{
    return selection_number;
}

void GraphicsVector::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    QMenu menu;
    QAction *removeAction = menu.addAction("Remove");
    QAction *selectAction = menu.addAction("Select");
    QAction *selectedAction = menu.exec(event->screenPos());
}

int GraphicsVector::max_number = 0;
int GraphicsVector::selected_count = 0;
