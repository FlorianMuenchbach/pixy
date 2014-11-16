#ifndef INFOWIDGET_H
#define INFOWIDGET_H

#include <QTableWidget>
#include <QTableWidgetItem>
#include <QString>
#include <QTime>

class MainWindow;

class InfoWidget : public QTableWidget {
    Q_OBJECT
    public:
        InfoWidget(MainWindow *main);
        ~InfoWidget();
        void gotFrameData();

    protected:
    public slots:
        void handleImage(QImage image);
        void handleFlush();
    private slots:
    private:
        MainWindow *m_main;
        QString m_s_fps_camera;
        QString m_s_fps_video;
        QTime m_camera_time;
        QTime m_video_time;
        int m_fps_camera_counter;
        int m_fps_video_counter;
        QTableWidgetItem *m_fps_camera_item;
        QTableWidgetItem *m_fps_video_item;
        float m_fps_camera;
        float m_fps_video;
};

#endif // INFOWIDGET_H
