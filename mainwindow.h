#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// The QMainWindow class provides a main application window.
#include <QMainWindow>
// Used to draw objects on screen
#include <QPainter>
// Importing Needed libraries
#include <QMouseEvent>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void paintEvent(QPaintEvent *event);
    //virtual void resizeEvent(QResizeEvent *event);

private slots:
    void on_action2_px_triggered();

    void on_action10_px_triggered();

    void on_actionBlack_triggered();

    void on_actionRed_triggered();

    void on_actionClear_all_triggered();

private:
    Ui::MainWindow *ui;
    QImage image;
    bool drawing;
    QPoint lastPoint;
    int brushSize;
    QColor brushColor;

};
#endif // MAINWINDOW_H
