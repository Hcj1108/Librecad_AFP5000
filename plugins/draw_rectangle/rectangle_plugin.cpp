#include "rectangle_plugin.h"
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>

RectangleDialog::RectangleDialog(QWidget* parent) : QDialog(parent) {
    setWindowTitle(tr("Draw Rectangle"));

    QGridLayout* layout = new QGridLayout(this);

    // 输入框：起点 X/Y，宽度，高度
    layout->addWidget(new QLabel(tr("Start X:")), 0, 0);
    startXEdit = new QLineEdit();
    startXEdit->setValidator(new QDoubleValidator());
    layout->addWidget(startXEdit, 0, 1);

    layout->addWidget(new QLabel(tr("Start Y:")), 1, 0);
    startYEdit = new QLineEdit();
    startYEdit->setValidator(new QDoubleValidator());
    layout->addWidget(startYEdit, 1, 1);

    layout->addWidget(new QLabel(tr("Width:")), 2, 0);
    widthEdit = new QLineEdit();
    widthEdit->setValidator(new QDoubleValidator());
    layout->addWidget(widthEdit, 2, 1);

    layout->addWidget(new QLabel(tr("Height:")), 3, 0);
    heightEdit = new QLineEdit();
    heightEdit->setValidator(new QDoubleValidator());
    layout->addWidget(heightEdit, 3, 1);

    // 按钮
    QPushButton* okButton = new QPushButton(tr("OK"));
    QPushButton* cancelButton = new QPushButton(tr("Cancel"));

    layout->addWidget(okButton, 4, 0);
    layout->addWidget(cancelButton, 4, 1);

    connect(okButton, &QPushButton::clicked, this, &RectangleDialog::checkInputs);
    connect(cancelButton, &QPushButton::clicked, this, &RectangleDialog::reject);
}

void RectangleDialog::checkInputs() {
    if (startXEdit->text().isEmpty() || startYEdit->text().isEmpty() ||
        widthEdit->text().isEmpty() || heightEdit->text().isEmpty()) {
        QMessageBox::warning(this, tr("Error"), tr("All fields must be filled!"));
        return;
    }
    accept();
}

void RectangleDialog::processAction(Document_Interface* doc) {
    double startX = startXEdit->text().toDouble();
    double startY = startYEdit->text().toDouble();
    double width = widthEdit->text().toDouble();
    double height = heightEdit->text().toDouble();

    // 计算矩形的四个顶点
    QPointF p1(startX, startY);
    QPointF p2(startX + width, startY);
    QPointF p3(startX + width, startY + height);
    QPointF p4(startX, startY + height);

    // 绘制四条边
    doc->addLine(&p1, &p2);
    doc->addLine(&p2, &p3);
    doc->addLine(&p3, &p4);
    doc->addLine(&p4, &p1);
}

QString RectanglePlugin::name() const {
    return tr("Rectangle Plugin");
}

PluginCapabilities RectanglePlugin::getCapabilities() const {
    PluginCapabilities caps;
    caps.menuEntryPoints << PluginMenuLocation("plugins_menu", tr("Draw Rectangle"));
    return caps;
}

void RectanglePlugin::execComm(Document_Interface* doc, QWidget* parent, QString cmd) {
    Q_UNUSED(cmd);
    RectangleDialog dialog(parent);
    if (dialog.exec() == QDialog::Accepted) {
        dialog.processAction(doc);
    }
}