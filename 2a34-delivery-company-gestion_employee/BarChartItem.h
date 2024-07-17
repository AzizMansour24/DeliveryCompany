#ifndef BARCHARTITEM_H
#define BARCHARTITEM_H


#include <QGraphicsItem>

class BarChartItem : public QGraphicsItem {
public:
    BarChartItem(const QString& poste, int nombreDemployes);

    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

private:
    QString poste_;
    int nombreDemployes_;
};


#endif // BARCHARTITEM_H
