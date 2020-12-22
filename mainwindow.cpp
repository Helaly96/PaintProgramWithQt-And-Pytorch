#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Create an image that has the shape of the window
    image = QImage(this->size(), QImage::Format_RGB32);
    // Fill the image with white color
    image.fill(Qt::white);
    // We are currently not drawing
    drawing = false;
    // Drawing Parameters
    brushColor = Qt::black;
    brushSize = 2;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        drawing = true;
        lastPoint = event->pos();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    if ((event->buttons() & Qt::LeftButton) && drawing) {
        // The parent of the painter (where we will draw is the white image)
        QPainter painter(&image);
        // Set the pen parameters
        painter.setPen(QPen(brushColor, brushSize, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        // draw a line between the last point and the current position
        painter.drawLine(lastPoint, event->pos());
        // Update the last point pos
        lastPoint = event->pos();
        // Update the canvas
        this->update();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        drawing = false;
    }
}

// draw the image to the screen
void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter canvasPainter(this);
    canvasPainter.drawImage(this->rect(), image, image.rect());
}

void MainWindow::on_action2_px_triggered()
{
    this->brushSize = 2;
}

void MainWindow::on_action10_px_triggered()
{
    this->brushSize = 10;
}

void MainWindow::on_actionBlack_triggered()
{
    this->brushColor = Qt::black;
}


void MainWindow::on_actionRed_triggered()
{
    this->brushColor = Qt::red;
}

void MainWindow::on_actionClear_all_triggered()
{
    this->image.fill(Qt::white);
    this->update();
}
