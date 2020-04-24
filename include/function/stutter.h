#ifndef STUTTER_H
#define STUTTER_H

#include <QWidget>

namespace Ui {
class Stutter;
}

class Stutter : public QWidget
{
    Q_OBJECT

public:
    explicit Stutter(QWidget *parent = nullptr);
    ~Stutter();
    // Updates stutter tab's threshold limit while changing parameters
    void stutterLimitUpdate();
    QString output() const;

signals:
    void outputChanged();

private slots:

    // void on_initSv_valueChanged();
    void on_threshold_valueChanged();
    // void on_initBpm_valueChanged();
    void on_generateButton_clicked();
    void on_aveBpm_valueChanged(double);
    void on_aveSv_valueChanged(double);
    void on_NormFrontTelButton_clicked();
    void on_MaxFronTelButton_clicked();
    void on_NormBackTelButton_clicked();
    void on_MaxBackTelButton_clicked();
    void on_output_textChanged();

private:
    void initBoxSliders();

    QVector<double> readOffsets(); // Get offsets from input
    bool isSkipLast() const;
    double aveBpm() const;
    double aveSv() const;
    double initSv() const;
    double initBpm() const;
    double threshold() const;
    Ui::Stutter *ui;
};

#endif // STUTTER_H
