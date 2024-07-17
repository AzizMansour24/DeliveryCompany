#include "BarChartItem.h"
#include <QPainter>

BarChartItem::BarChartItem(const QString& poste, int nombreDemployes)
    : poste_(poste), nombreDemployes_(nombreDemployes)
{
}

QRectF BarChartItem::boundingRect() const
{
    // Définissez la zone de délimitation de votre objet ici.
    return QRectF(0, 0, 10, 40);
}

void BarChartItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    Q_UNUSED(option); // Ignore le paramètre option (évite les avertissements)
    Q_UNUSED(widget); // Ignore le paramètre widget (évite les avertissements)
    // Dessinez votre barre ici en utilisant les données de poste_ et nombreDemployes_.
    QRectF rect = boundingRect();

    // Dessinez un rectangle pour représenter la barre
    painter->setBrush(QColor(0, 0, 255)); // Couleur de remplissage
    painter->setPen(QColor(0, 0, 0));     // Couleur de la bordure
    painter->drawRect(rect);

    // Dessinez le texte (poste et nombre d'employés) au-dessus de la barre
    painter->setPen(QColor(0, 0, 0)); // Couleur du texte
    painter->drawText(rect, Qt::AlignCenter, poste_);
    painter->drawText(rect.translated(0, 20), Qt::AlignCenter, QString::number(nombreDemployes_));
}
