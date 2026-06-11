#include "Simulator.h"
#include "Logger.h"
#include "Config.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QPushButton>

Simulator::Simulator(QWidget* parent)
    : QDialog(parent)
{
    ui.setupUi(this);
   
 
    connect(ui.btnBrowse, &QPushButton::clicked, this, &Simulator::onSelectFolder);
    connect(ui.btnConfirm, &QPushButton::clicked, this, &Simulator::onAccept);
    connect(ui.btnCancel, &QPushButton::clicked, this, &QDialog::reject);
}

Simulator::~Simulator() = default;

void Simulator::onSelectFolder()
{
    QString folder = QFileDialog::getExistingDirectory(this,
        QString::fromLocal8Bit("\xd1\xa1\xd4\xf1\xd7\xb4\xd5\xe6\xce\xc4\xbc\xfe\xbc\xd0"),
        "./NG_Pictures/");

    if (folder.isEmpty()) return;

    m_folderPath = folder;
    ui.lineEditPath->setText(folder);

    loadImages(folder);
}

void Simulator::loadImages(const QString& folderPath)
{
    // \xb5\xf7\xd3\xc3 Config.h \xd6\xd0\xb5\xc4\xc8\xab\xbe\xd6 getImageList \xba\xaf\xca\xfd
    std::string path = folderPath.toLocal8Bit().constData();
    m_imageList = ::getImageList(path + "/", "*.bmp");

    ui.labelCount->setText(QString::fromLocal8Bit("\xb7\xa2\xcf\xd6 %1 \xd5\xc5\xcd\xbc\xc6\xac")
        .arg(m_imageList.size()));
}

void Simulator::onAccept()
{
    if (m_folderPath.isEmpty()) {
        QMessageBox::warning(this,
            QString::fromLocal8Bit("\xcc\xe1\xca\xbe"),
            QString::fromLocal8Bit("\xc7\xeb\xcf\xc8\xd1\xa1\xd4\xf1\xd7\xb4\xd5\xe6\xce\xc4\xbc\xfe\xbc\xd0"));
        return;
    }
    Logger::write("\xd1\xa1\xd4\xf1\xb7\xc2\xd5\xe6\xce\xc4\xbc\xfe\xbc\xd0");
    accept();
}
