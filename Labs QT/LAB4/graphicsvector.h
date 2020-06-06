#ifndef GRAPHICSVECTOR_H
#define GRAPHICSVECTOR_H
#include <QGraphicsItem>
#include <QPainter>
#include <QDebug>
#include <QCursor>
#include <QMenu>
#include <QGraphicsSceneContextMenuEvent>

class GraphicsVector : public QGraphicsLineItem
{
public:
    GraphicsVector(qreal x1 = 0, qreal y1 = 0, qreal x2 = 0, qreal y2 = 0);
    GraphicsVector(const QLineF& linef);
    GraphicsVector(const GraphicsVector& other);

    GraphicsVector& operator=(const GraphicsVector& operand);
    GraphicsVector& operator=(const QGraphicsLineItem& operand);
    GraphicsVector operator+(const GraphicsVector& operand);
    GraphicsVector operator-(const GraphicsVector& operand);
    GraphicsVector operator-();
    //qreal operator*(const GraphicsVector& operand);


    int seletion_number();

    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant & value);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
private:
    QLineF rline;
    QLineF lline;
    static int max_number;
    static int selected_count;
    int selection_number = 0;
};

GraphicsVector operator*(qreal coef, const GraphicsVector& vector);
GraphicsVector operator*(const GraphicsVector& vector, qreal coef);
qreal operator*(const GraphicsVector& vector1, const GraphicsVector& vector2);


#endif // GRAPHICSVECTOR_H
