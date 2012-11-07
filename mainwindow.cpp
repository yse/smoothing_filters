#include "mainwindow.h"

#include <QVector>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include <qwt_plot_magnifier.h>
#include <qwt_plot_panner.h>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
            m_alpha(0.01)
{
    srand(time(NULL));
    //ui->setupUi(this);
    resize(400,400);
    plot = new QwtPlot(this);
    //plot->resize(2,2);
    _curve = new QwtPlotCurve("temp item");
    _curve_sm = new QwtPlotCurve("smothing");

    QwtPlotMagnifier* plotMagnifer =  new QwtPlotMagnifier(plot->canvas());
    QwtPlotPanner* plotPanner = new QwtPlotPanner(plot->canvas());
    //plotMagnifer->setMouseButton(Qt::RightButton);

    m_refreshButton = new QPushButton("refresh");
    m_dial = new QDial();
    m_dial->setRange(0,1000);

    m_editAlpha = new QDoubleSpinBox();
    m_editAlpha->setMaximum(1.0);
    m_editAlpha->setMinimum(0.0);
    m_editAlpha->setValue(m_alpha);
    m_editAlpha->setDecimals(4);
    m_editAlpha->setSingleStep(0.0001);


    QPen _graph_pen("red");
    //_graph_pen.setStyle(Qt::DotLine);

    QHBoxLayout *horizontal = new QHBoxLayout();
    horizontal->addWidget(m_editAlpha);
    horizontal->addWidget(m_dial);


    QVBoxLayout *widgetLayout = new QVBoxLayout();
    widgetLayout->addWidget(plot);
    //widgetLayout->addWidget(m_dial);
    widgetLayout->addLayout(horizontal);
    widgetLayout->addWidget(m_refreshButton);
    setLayout(widgetLayout);
    _curve->attach(plot);
    _curve_sm->attach(plot);
    _curve->setPen(_graph_pen);


    plot->enableAxis(QwtPlot::xBottom);
    plot->enableAxis(QwtPlot::yLeft);

   // plot->show();

    memset(&x[0],0,DATA_SIZE);
    memset(&y[0],0,DATA_SIZE);
    memset(&y_sm[0],0,DATA_SIZE);

    refresh();

    connect(m_refreshButton, SIGNAL(clicked()), this, SLOT(refresh()));
    connect(m_dial, SIGNAL(valueChanged(int)), this, SLOT(changeValue(int)));
    connect(m_editAlpha, SIGNAL(valueChanged(double)),this,SLOT(setAlpha(double)));

}

MainWindow::~MainWindow()
{

}
#include "stdio.h"
void MainWindow::refresh()
{

    for(int i=0; i < DATA_SIZE; i++)
    {
        //y[i] = rand() % 100;
        y[i] = sin(2*3.14*i)+(rand()%5)*sin(2*3.14*1000*i)/50.0;
        if(i>1)
            y_sm[i]= y_sm[i-1] + m_alpha*(y[i]-y_sm[i-1]);
        x[i] = i;
    }
    _curve->setSamples(x,y,DATA_SIZE);
    _curve_sm->setSamples(x,y_sm,DATA_SIZE);
    plot->replot();

}

void MainWindow::changeValue(int value)
{
    m_alpha = (double)(value)/10000.0;
    setAlpha(m_alpha);
}

void MainWindow::setAlpha(double value)
{
    m_alpha = value;
    m_editAlpha->setValue(m_alpha);
    y_sm[0] = 0;
    for(int i=1; i < DATA_SIZE; i++)
    {
        y_sm[i]= y_sm[i-1] + m_alpha*(y[i]-y_sm[i-1]);
    }
    _curve_sm->setSamples(x,y_sm,DATA_SIZE);
    plot->replot();
}
