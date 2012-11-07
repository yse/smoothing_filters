#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qwt_scale_map.h>
#include <qwt_plot_curve.h>
#include <qwt_symbol.h>
#include <qwt_math.h>
#include <qcolor.h>
#include <qpainter.h>

#include <QMainWindow>
#include <QPushButton>
#include <qwt_plot_curve.h>
#include <qwt_plot.h>
#include <QDial>
#include <QAbstractSlider>
#include <QDoubleSpinBox>

const int DATA_SIZE=2000;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void refresh();
    void changeValue(int);
    void setAlpha(double);
private:
    QPushButton* m_refreshButton;
    QwtPlot* plot;
    QwtPlotCurve* _curve;
    QwtPlotCurve* _curve_sm;
    QDial*      m_dial;
    QDoubleSpinBox*  m_editAlpha;

    double m_alpha;
    double x[DATA_SIZE];
    double y[DATA_SIZE];
    double y_sm[DATA_SIZE];
};

#endif // MAINWINDOW_H
