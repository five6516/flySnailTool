#ifndef THREADDEMO_H
#define THREADDEMO_H

#include <QWidget>
#include <DataCaculator.h>
#include <QThread>
#include <DataCalculatorThread.h>
#include <DataCalculatoRunnable.h>
#include <QPropertyAnimation>
#include <QTimer>
#include <QFutureWatcher>
namespace Ui {
class ThreadDemo;
}

class ThreadDemo : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(double animation READ animation WRITE setAnimation NOTIFY animationChanged)
public:
    explicit ThreadDemo(QWidget *parent = nullptr);
    ~ThreadDemo();
signals:
    void animationChanged(int animation);
    void done(const QString& data);
public slots:
    void startCal();
    void stopCal();
    void getData(const QString& data);

    void calSlots();
private:
    Ui::ThreadDemo *ui;

    DataCaculator* m_pDataCaculator;
    int m_framesCount = 0;
    float m_fps = 0;
    float m_avgfps = 0;
    int m_counter = 0;
    double m_animation = 0;

    QPropertyAnimation m_proAnimation;
    QTimer m_timer_fps;
    QTimer* timer_cal;
    QThread * thread_2;
    DataCalculatorThread* dataCalculatorThread;
    DataCalculatoRunnable* dataCalculatoRunnable;
    QList<QFutureWatcher<QString>*> watches;

    double animation() { return m_animation;}
    void setAnimation(double animation){ m_animation = animation; emit animationChanged(animation);}

    void cal();
};

#endif // THREADDEMO_H
