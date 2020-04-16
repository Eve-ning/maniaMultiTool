#include "common.h"
#include <QVector>
#include <QVector2D>

const QColor Common::Color::GREEN   = QColor(15,  232, 0);
const QColor Common::Color::RED     = QColor(214, 0,   68);
const QColor Common::Color::GREY    = QColor(125, 125, 125);
const QColor Common::Color::BLUE    = QColor(23,  107, 232);
const QColor Common::Color::PURPLE  = QColor(163, 22,  245);
const QColor Common::ColorFade::GREEN   = QColor(15,  232, 0  , 90);
const QColor Common::ColorFade::RED     = QColor(214, 0,   68 , 90);
const QColor Common::ColorFade::GREY    = QColor(125, 125, 125, 90);
const QColor Common::ColorFade::BLUE    = QColor(23,  107, 232, 90);
const QColor Common::ColorFade::PURPLE  = QColor(163, 22,  245, 90);

const QString Common::Suffix::SV     = QString(" (SV)");
const QString Common::Suffix::BPM    = QString(" (BPM)");
const QString Common::Suffix::OFFSET = QString("ms");

double Common::clipValue(double value, bool isBpm) {
    if (isBpm) {
        value = value > BPM_MAX ? BPM_MAX : value;
        value = value < BPM_MIN ? BPM_MIN : value;
    } else {
        value = value > SV_MAX ? SV_MAX : value;
        value = value < SV_MIN ? SV_MIN : value;
    }

    return value;
}
QVector<double> Common::clipValueV(QVector<double> valueV, bool isBpm)
{
    QVector<double> output;
    output.reserve(valueV.size());
    for (double value : valueV) output.push_back(clipValue(value, isBpm));
    return output;
}

QVector<QVector2D> Common::sortByX(QVector<QVector2D> v) {
    std::sort(v.begin(), v.end(), [](QVector2D a, QVector2D b){ return a.x() < b.x(); });
    return v;
}
