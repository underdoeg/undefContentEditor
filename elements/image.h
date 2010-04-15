#ifndef IMAGE_H
#define IMAGE_H
#include <QLabel>
#include <QFileDialog>
#include "media.h"

class image : public media, public QLabel, public apiListener
{
public:
    image(QWidget* parent);
    void setBounds(int x, int y, int w, int h);
    QRect getBounds();
    void onMediaDataChange();
    void showMenu();
    void loadImage(QString path, bool resize = false);
    void onFileDownloadComplete(QString fileName);
    void onFileUploadComplete(QString fileName);
    void onSave();
    QString getMediaType();

    QPixmap* pixmap;
    QPixmap pixmapScaled;
};

#endif // IMAGE_H
