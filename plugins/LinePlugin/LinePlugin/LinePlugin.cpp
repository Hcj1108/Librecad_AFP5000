#include "LinePlugin.h"
#include <QMessageBox>
#include <QDoubleValidator>

LineDialog::LineDialog(QWidget* parent) : QDialog(parent) {
    setWindowTitle("Line Input");

    QVBoxLayout* layout = new QVBoxLayout(this);

    // 添加标签和输入框
    layout->addWidget(new QLabel("Start Point X:"));
    startXEdit = new QLineEdit(this);
    startXEdit->setValidator(new QDoubleValidator(this));
    layout->addWidget(startXEdit);

    layout->addWidget(new QLabel("Start Point Y:"));
    startYEdit = new QLineEdit(this);
    startYEdit->setValidator(new QDoubleValidator(this));
    layout->addWidget(startYEdit);

    layout->addWidget(new QLabel("End Point X:"));
    endXEdit = new QLineEdit(this);
    endXEdit->setValidator(new QDoubleValidator(this));
    layout->addWidget(endXEdit);

    layout->addWidget(new QLabel("End Point Y:"));
    endYEdit = new QLineEdit(this);
    endYEdit->setValidator(new QDoubleValidator(this));
    layout->addWidget(endYEdit);

    // OK按钮
    okButton = new QPushButton("OK", this);
    layout->addWidget(okButton);

    connect(okButton, &QPushButton::clicked, this, &LineDialog::onOkButtonClicked);
}

LineDialog::~LineDialog() {}

QPointF LineDialog::getStartPoint() const {
    return QPointF(startXEdit->text().toDouble(), startYEdit->text().toDouble());
}

QPointF LineDialog::getEndPoint() const {
    return QPointF(endXEdit->text().toDouble(), endYEdit->text().toDouble());
}

void LineDialog::onOkButtonClicked() {
    if (startXEdit->text().isEmpty() || startYEdit->text().isEmpty() ||
        endXEdit->text().isEmpty() || endYEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all the fields.");
        return;
    }
    accept(); // 确认并关闭对话框
}

LinePlugin::LinePlugin() {}
LinePlugin::~LinePlugin() {}

PluginCapabilities LinePlugin::getCapabilities() const {
    PluginCapabilities pluginCapabilities;
    pluginCapabilities.menuEntryPoints
        << PluginMenuLocation("plugins_menu", tr("Draw Line Plugin"));
    return pluginCapabilities;
}

QString LinePlugin::name() const {
    return tr("Draw Line Plugin");
}

void LinePlugin::execComm(Document_Interface* doc, QWidget* parent, QString cmd) {
    // 弹出对话框获取用户输入的起点和终点
    LineDialog dialog(parent);
    if (dialog.exec() == QDialog::Accepted) {
        QPointF start = dialog.getStartPoint();
        QPointF end = dialog.getEndPoint();

        // 使用文档接口添加一条直线
        QVector<QPointF> points;
        points.append(start);
        points.append(end);

        // 使用 Polyline 绘制直线
        doc->addPolyline(points, false);
    }
}
