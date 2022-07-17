#include "ThreadDemo.h"
#include "ui_ThreadDemo.h"

#include <QVBoxLayout>
#include <QDebug>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QPixmap>
#include <QThread>
#include <QThreadPool>
#include <QtConcurrent>
#include <QRandomGenerator>
#include <QElapsedTimer>
#include <QFuture>
#include <QFutureWatcher>

#define Method_Type 0

ThreadDemo::ThreadDemo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ThreadDemo),
    #if (Method_Type == 1 || Method_Type == 2 || Method_Type == 6)
    timer_cal(new QTimer()),
    #endif
    #if Method_Type == 2
    thread_2(new QThread(this)),
    #endif
    #if Method_Type == 4
    dataCalculatoRunnable(new DataCalculatoRunnable()),
    #endif
    dataCalculatorThread(new DataCalculatorThread(this)),
    m_pDataCaculator(new DataCaculator(this))
{
    ui->setupUi(this);

    connect(ui->startButton, SIGNAL(clicked(bool)), this, SLOT(startCal()));
    connect(ui->stopButton, SIGNAL(clicked(bool)), this, SLOT(stopCal()));
    connect(ui->helpButton, &QPushButton::clicked, [&](){
        QDialog* dlg = new QDialog(this);
        dlg->setAttribute(Qt::WA_DeleteOnClose);
        QVBoxLayout* vlayout = new QVBoxLayout();

        dlg->setLayout(vlayout);

        QLabel* label = new QLabel();
        label->setPixmap(QPixmap(":/res/thread.png"));
        vlayout->addWidget(label);
        dlg->show();
    });

    m_proAnimation.setPropertyName("animation");
    m_proAnimation.setTargetObject(this);
    m_proAnimation.setDuration(1000);
    m_proAnimation.setStartValue(0);
    m_proAnimation.setEndValue(1);
    m_proAnimation.setLoopCount(-1); //永远运行，直到stop

    connect(this, &ThreadDemo::animationChanged, [&](int value){
        m_framesCount ++;
    });

    m_timer_fps.setInterval(1000);

    connect(&m_timer_fps, &QTimer::timeout, [&](){
        m_fps = m_framesCount;
        m_avgfps = m_avgfps + (m_framesCount - m_avgfps)*1.0 / ++m_counter;
        m_framesCount = 0;

        ui->label->setText(QString::asprintf("fps: %.0f/ %.0f",m_fps, m_avgfps));
    });

    m_timer_fps.start();
    m_proAnimation.start();
}

ThreadDemo::~ThreadDemo()
{
    delete ui;
}

void ThreadDemo::cal()
{
    QRandomGenerator rand;
    Q_FOREVER
    {
        QElapsedTimer t;
        t.start();

        QString data;
        const char* nucleabases = "CGAT";

        for(int i = 0; i < 5; i ++)
        {
            for(int k = 0; k < 80; k++)
            {
                int index = rand.bounded(0,4);
                data.append(nucleabases[index]);

                for(int j = 0; j < 5000000; j++)
                    ;
            }
        }
        emit done(QString::number(t.elapsed())+ ":thread:" + data);
    }
}

void ThreadDemo::startCal()
{
#if (Method_Type == 0)//完全阻塞主线程
    for(int i=0; i<20;i++)
    {
        ui->listWidget->addItem(m_pDataCaculator->cal());
    }
#elif (Method_Type == 1)//定时器定时阻塞主线程
    timer_cal->setParent(this);
    timer_cal->setInterval(100);
    connect(timer_cal, &QTimer::timeout, [&](){
        ui->listWidget->addItem(m_pDataCaculator->cal());
    });
    timer_cal->start();
#elif (Method_Type == 2)//QThread开线程
    timer_cal->setInterval(100);
    connect(timer_cal, &QTimer::timeout, [&](){
        ui->listWidget->addItem(m_pDataCaculator->cal());
    });

    timer_cal->moveToThread(thread_2);
    connect(thread_2, &QThread::finished, timer_cal, &QTimer::stop);
    connect(thread_2, &QThread::finished, thread_2, &QThread::deleteLater);
    connect(thread_2, SIGNAL(started()), timer_cal, SLOT(start()));
    thread_2->start();
#elif (Method_Type == 3)//QThread开线程
    connect(dataCalculatorThread, &QThread::finished, dataCalculatorThread, &QThread::deleteLater);
    connect(dataCalculatorThread, &DataCalculatorThread::done, [&](const QString& data){
        ui->listWidget->addItem(data);
    });
    dataCalculatorThread->start();
#elif (Method_Type == 4)//QRunnable开线程
    connect(dataCalculatoRunnable, &DataCalculatoRunnable::done, this, &ThreadDemo::getData ,Qt::QueuedConnection);
    QThreadPool::globalInstance()->start(dataCalculatoRunnable);
#elif (Method_Type == 5)//QConcurrent开线程
//    QFutureWatcher<QString>* watcher = new QFutureWatcher<QString>;
//    connect(watcher, &QFutureWatcher<QString>::finished, [=](){
//        QString data = watcher->future().result();

//        ui->listWidget->addItem(data);

//        watches.removeOne(watcher);
//        watcher->deleteLater();
//    });
    connect(this, &ThreadDemo::done, [&](const QString& data){
        ui->listWidget->addItem(data);
    });
    QFuture<void> f = QtConcurrent::run(&ThreadDemo::cal,this);
    //watcher->setFuture(f);
    //watches.append(watcher);

#elif (Method_Type == 6)
//    timer_cal->setInterval(100);
//    timer_cal->setParent(this);
//    connect(timer_cal, &QTimer::timeout, [&](){
//        QEventLoop loop;
//        QMetaObject::invokeMethod(this,"calSlots",Qt::DirectConnection);
//        loop.exec();
//    });
//    timer_cal->start();

#endif
}

void ThreadDemo::stopCal()
{
#if (Method_Type == 1)
    timer_cal->stop();
#elif (Method_Type == 2)
    thread_2->quit();
    timer_cal->deleteLater();
#elif (Method_Type == 3)
    dataCalculatorThread->requestInterruption();
#elif (Method_Type == 4)
#elif (Method_Type == 6)
    timer_cal->stop();
#endif
}

void ThreadDemo::getData(const QString &data)
{
    ui->listWidget->addItem(data);
}

void ThreadDemo::calSlots()
{
    QRandomGenerator rand;
    QElapsedTimer t;
    t.start();

    QString data;
    const char* nucleabases = "CGAT";

    for(int i = 0; i < 5; i ++)
    {
        for(int k = 0; k < 80; k++)
        {
            int index = rand.bounded(0,4);
            data.append(nucleabases[index]);

            for(int j = 0; j < 5000000; j++)
                ;
        }
    }
    ui->listWidget->addItem(QString::number(t.elapsed())+ ":thread:" + data);
}
