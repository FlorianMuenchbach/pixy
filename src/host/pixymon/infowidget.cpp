#include "infowidget.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QTime>
#include <QDebug>

InfoWidget::InfoWidget(MainWindow *mainwindow) : QTableWidget((QWidget *)mainwindow) {
        m_main = mainwindow;
        m_camera_time = QTime::currentTime();
        m_video_time = QTime::currentTime();
        m_fps_camera_counter = 0;
        m_fps_video_counter = 0;
        m_s_fps_camera = "fps (Camera)";
        m_s_fps_video = "fps (ViedeoWidget)";
        m_fps_camera = .0;
        m_fps_video = .0;
        m_fps_camera_item = new QTableWidgetItem(m_fps_camera);
        m_fps_video_item  = new QTableWidgetItem(m_fps_video);

        this->setRowCount(2);
        this->setColumnCount(2);
        this->setShowGrid(false);
        this->verticalHeader()->hide();
        this->horizontalHeader()->hide();
        this->setItem(0, 0, new QTableWidgetItem(m_s_fps_camera));
        this->setItem(1, 0, new QTableWidgetItem(m_s_fps_video));
        this->setItem(0, 1, m_fps_camera_item);
        this->setItem(1, 1, m_fps_video_item);
        resizeColumnToContents(0);
        int height = rowHeight(0) + rowHeight(1) + 5;
        setMinimumHeight(height);
        setFixedHeight(height);
}

InfoWidget::~InfoWidget() {
}

void InfoWidget::gotFrameData() {
    int elapsed = m_camera_time.elapsed();
    if (elapsed >= 1000) {
        m_fps_camera = m_fps_camera_counter / (float)elapsed * 1000;
        m_fps_camera_item->setText(QString("%1").arg(m_fps_camera));
        m_fps_camera_counter = 0;
        m_camera_time.restart();
    } else {
        m_fps_camera_counter = m_fps_camera_counter + 1;
    }
}

void InfoWidget::handleImage(QImage image) {
}
void InfoWidget::handleFlush() {
    int elapsed = m_video_time.elapsed();
    if (elapsed >= 1000) {
        m_fps_video = m_fps_video_counter / (float)elapsed * 1000;
        m_fps_video_item->setText(QString("%1").arg(m_fps_video));
        m_fps_video_counter = 0;
        m_video_time.restart();
    } else {
        m_fps_video_counter = m_fps_video_counter + 1;
    }
}

