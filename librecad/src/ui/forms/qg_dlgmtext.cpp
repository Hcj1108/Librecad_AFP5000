
#include "qg_dlgmtext.h"
#include <QPushButton>
#include <QTextCodec>
#include <QTextStream>
#include <QFileDialog>
#include <QRegularExpression>
#include "rs_system.h"
#include "rs_settings.h"
#include "rs_font.h"
#include "rs_graphic.h"
#include "rs_math.h"
#include <QDate>

/*
 *  Constructs a QG_DlgMText as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  true to construct a modal dialog.
 */
QG_DlgMText::QG_DlgMText(QWidget* parent, bool modal, Qt::WindowFlags fl)
    : QDialog(parent, fl), saveSettings(true)
{
    setModal(modal);
    setupUi(this);
    /*connect(Date_MBox, QOverload<int>::of(&QComboBox::activated),
        this, &QG_DlgMText::DateMBoxcurrentIndexChanged);*/
    init();
}

/*
 *  Destroys the object and frees any allocated resources
 */
QG_DlgMText::~QG_DlgMText()
{
    destroy();
   
}

/**
 *  界面文本翻译
 *  刷新函数
 */
void QG_DlgMText::languageChange()
{
    retranslateUi(this);
}
/**
*    界面初始化
*/
void QG_DlgMText::init() {

    QIcon icon(":/PNG/Resources/PNG/PMSZ.png");
    this->setWindowIcon(icon);
    cbFont->init();
    font=NULL;
    text = NULL;
    isNew = false;
    updateUniCharComboBox(0);
    updateUniCharButton(0);
    buttonBox->button(QDialogButtonBox::Ok)->setText(QString::fromLocal8Bit("确认"));
    buttonBox->button(QDialogButtonBox::Cancel)->setText(QString::fromLocal8Bit("取消"));
}

/**
*  根据用户选择的“Unicode 字符页码范围”，
*  动态填充“特殊字符下拉框”里的具体字符列表
*/
void QG_DlgMText::updateUniCharComboBox(int) {
    QString t = cbUniPage->currentText();
    int i1 = t.indexOf('-');
    int i2 = t.indexOf(']');
    int min = t.mid(1, i1-1).toInt(NULL, 16);
    int max = t.mid(i1+1, i2-i1-1).toInt(NULL, 16);

    cbUniChar->clear();
    for (int c=min; c<=max; c++) {
        char buf[5];
        snprintf(buf,5, "%04X", c);
        cbUniChar->addItem(QString("[%1] %2").arg(buf).arg(QChar(c)));
    }
}

/**
*  告诉程序用户点击了“取消”或关闭按钮，并且不要
*  保存当前在界面上修改的任何设置。
*/
void QG_DlgMText::reject() {
    saveSettings=false;
    QDialog::reject();
}
/**
*  保存用户在对话框中修改的各项设置（比如字体、高度、角度等）
*  以便下次打开对话框时能记住这些参数
*/
void QG_DlgMText::destroy() {
    if (isNew&&saveSettings) {
        RS_SETTINGS->beginGroup("/Draw");
        RS_SETTINGS->writeEntry("/TextHeight", leHeight->text());
        RS_SETTINGS->writeEntry("/TextFont", cbFont->currentText());
        RS_SETTINGS->writeEntry("/TextDefault", (int)cbDefault->isChecked());
        RS_SETTINGS->writeEntry("/TextAlignment", getAlignmentcom());
        //RS_SETTINGS->writeEntry("/TextLetterSpacing", leLetterSpacing->text());
        //RS_SETTINGS->writeEntry("/TextWordSpacing", leWordSpacing->text());
        RS_SETTINGS->writeEntry("/TextLineSpacingFactor",leLineSpacingFactor->text());
        RS_SETTINGS->writeEntry("/TextString", teText->toPlainText());
        //RS_SETTINGS->writeEntry("/TextShape", getShape());
        RS_SETTINGS->writeEntry("/TextAngle", leAngle->text());
        //RS_SETTINGS->writeEntry("/TextRadius", leRadius->text());
        /*新增 ,将当前字体相关设置写入一个配置类,方便下次打开时使用*/
        RS_SETTINGS->writeEntry("/TextWordSpace", lewordspace->text());
        /*新增 ,将当前字体相关设置写入一个配置类,方便下次打开时使用*/
        RS_SETTINGS->writeEntry("/TextY_scale", ley_scale->text());
        RS_SETTINGS->writeEntry("/TextX_scale", lex_scale->text());
        //保存生产日期
        if (m_mfgDate.isValid()) {
            RS_SETTINGS->writeEntry("/TextMFGDate", m_mfgDate.toString("yyyy MM dd"));
        }
        //保存保质期偏移
        RS_SETTINGS->writeEntry("/TextEXPYears", m_expYears);
        RS_SETTINGS->writeEntry("/TextEXP Months", m_expMonths);
        RS_SETTINGS->writeEntry("/TextEXPDays", m_expDays);
        //RS_SETTINGS->writeEntry("/TextRadius", leRadius->text());
        RS_SETTINGS->endGroup();
    }
}

/**
 *  多行文本编辑对话框的初始化与数据填充
 */
void QG_DlgMText::setText(RS_MText& t, bool isNew) {
    text = &t;// 3. 将传入的 RS_MText 对象的地址存起来，方便后续 updateText 使用
    this->isNew = isNew;
   
    QString fon;
    QString height;
    QString def;
    QString alignment;
    QString lineSpacingFactor;
    QString str;
    QString angle;
    QString wordSpacing;
	QString y_scale;
    QString x_scale;
   
    if (isNew) {
       
        RS_SETTINGS->beginGroup("/Draw");
        QByteArray iso = RS_System::localeToISO( QLocale::system().name().toLocal8Bit() );
        if (iso=="ISO8859-1") {
             fon = RS_SETTINGS->readEntry("/TextFont", "normallatin1");
        } else if (iso=="ISO8859-2") {
             fon = RS_SETTINGS->readEntry("/TextFont", "normallatin2");
        } else if (iso=="ISO8859-7") {
             fon = RS_SETTINGS->readEntry("/TextFont", "greekc");
        } else if (iso=="KOI8-U" || iso=="KOI8-R") {
             fon = RS_SETTINGS->readEntry("/TextFont", "cyrillic_ii");
        } else {
             fon = RS_SETTINGS->readEntry("/TextFont", "standard");
                }
        height = RS_SETTINGS->readEntry("/TextHeight", "200");
        def = RS_SETTINGS->readEntry("/TextDefault", "0");
        alignment = RS_SETTINGS->readEntry("/TextAlignment", "4");//4是左对齐
        //letterSpacing = RS_SETTINGS->readEntry("/TextLetterSpacing", "0");

        wordSpacing = RS_SETTINGS->readEntry("/TextWordSpace", "5");
        y_scale = RS_SETTINGS->readEntry("/TextY_scale", "1");
        x_scale = RS_SETTINGS->readEntry("/TextX_scale", "1");
        lineSpacingFactor = RS_SETTINGS->readEntry("/TextLineSpacingFactor", "8");
        str = RS_SETTINGS->readEntry("/TextString", "");
        angle = RS_SETTINGS->readEntry("/TextAngle", "0");
        // 恢复生产日期
        QString mfgDateStr = RS_SETTINGS->readEntry("/TextMFGDate", "");
        if (!mfgDateStr.isEmpty()) {
            m_mfgDate = QDate::fromString(mfgDateStr, "yyyy MM dd");
        }
        // 恢复保质期偏移
        m_expYears = RS_SETTINGS->readEntry("/TextEXPYears", "0").toInt();
        m_expMonths = RS_SETTINGS->readEntry("/TextEXP Months", "12").toInt();
        m_expDays = RS_SETTINGS->readEntry("/TextEXPDays", "0").toInt();
        RS_SETTINGS->endGroup();
        
    } else {
        fon = text->getStyle();// 例如，从 RS_MText 对象获取字体
        setFont(fon);
        height = QString("%1").arg(text->getHeight());
		wordSpacing = QString("%1").arg(text->getWordSpace());
        y_scale = QString("%1").arg(text->gety_scale());
        x_scale = QString("%1").arg(text->getx_scale());

        if (font) {
            if (font->getLineSpacingFactor()==text->getLineSpacingFactor()) {
                def = "1";
            } else {
                def = "0";
            }
        }
        alignment = QString("%1").arg(text->getAlignment());
        lineSpacingFactor = QString("%1").arg(text->getLineSpacingFactor());
        str = text->getText();
        angle = QString("%1").arg(RS_Math::rad2deg(text->getAngle()));
        RS_Graphic* graphic = text->getGraphic();
        RS_Layer* lay = text->getLayer(false);
       
    }
   
    cbDefault->setChecked(def=="1");
    setFont(fon);
    leHeight->setText(height);
	lewordspace->setText(wordSpacing);
    ley_scale->setText(y_scale);
    lex_scale->setText(x_scale);

    setAlignment(alignment.toInt());//加载文本旋转角度

    if (def!="1" || font==NULL) {
        leLineSpacingFactor->setText(lineSpacingFactor);
    } else {
        leLineSpacingFactor->setText(QString("%1").arg(font->getLineSpacingFactor()));
    }
    teText->setText(str);
    leAngle->setText(angle);
    // 显示生产日期
    if (m_mfgDate.isValid()) {
        label_9->setText(QString::fromLocal8Bit("%1").arg(m_mfgDate.toString("yyyy MM dd")));
    } else {
        label_9->setText(QString::fromLocal8Bit("未设置"));
    }
    teText->setFocus();
    teText->moveCursor(QTextCursor::End);
}


/**
 * 多行文本编辑对话框的“数据提交与同步”核心函数，
 * 将参数保存至实体中
 */
void QG_DlgMText::updateText() {
    if (text) {
        // 在保存前替换占位符为实际日期
        QString finalText = replaceDatePlaceholders(teText->toPlainText());

        text->setStyle(cbFont->currentText());
        text->setHeight(leHeight->text().toDouble());
        text->setWordSpace(lewordspace->text().toDouble());
        text->sety_scale(ley_scale->text().toDouble());
        text->setx_scale(lex_scale->text().toDouble());
        text->setText(finalText);
        text->setLineSpacingFactor(leLineSpacingFactor->text().toDouble());
        text->setAlignment(getAlignmentcom());
        text->setAngle(RS_Math::deg2rad(leAngle->text().toDouble()));
    }
    if (text && !isNew) {
        text->update();
    }
}

/**
 * 加载文本旋转角度
 */
void QG_DlgMText::setAlignment(int a) {
    switch (a) {
    case 4:
        AligncomboBox->setCurrentIndex(0);
        break;
    case 5:
        AligncomboBox->setCurrentIndex(1);
        break;
    case 6:
        AligncomboBox->setCurrentIndex(2);
        break;
    default:
        AligncomboBox->setCurrentIndex(0);
        break;
    }
}
/**
 * 更改文本旋转角度
 */
int QG_DlgMText::getAlignmentcom() {
    int index = AligncomboBox->currentIndex();
    switch (index) {
    case 0:  // 第一个选项
        return 4;
        break;
    case 1:
        return 5;
        break;
    case 2:
        return 6;
        break;
    default:
        return 4;
        break;
    }
}
/**
* 用来设置字体下拉框（cbFont）的选中项，并更新关联的字体对象引用。
*/
void QG_DlgMText::setFont(const QString& f) {
    cbFont->setCurrentIndex( cbFont->findText(f) );
    font = cbFont->getFont();
    defaultChanged(false);
}

/**
* 根据“使用默认行距”复选框的状态，来自动填充或清空行距输入框
*/
void QG_DlgMText::defaultChanged(bool) {
    if (cbDefault->isChecked() && font) {
        leLineSpacingFactor->setText(
                        QString("%1").arg(font->getLineSpacingFactor()));
    }
}

/**
* 加载外部文本文件的内容，并将其应用到当前多行文本编辑器中
*/
void QG_DlgMText::loadText() {
    QString appDir = QCoreApplication::applicationDirPath();
    QString modelsPath = appDir + "/PrintJob";
    // 检查文件夹是否存在，如果不存在则创建
    QDir dir(modelsPath);
    if (!dir.exists()) {
        // 创建文件夹（包括所有必要的父目录）
        if (!dir.mkpath(".")) {
            // 文件夹创建失败，显示错误信息并使用默认目录
            QMessageBox::warning(this,
                QString::fromLocal8Bit("文件夹创建失败"),
                QString::fromLocal8Bit("无法创建目录: %1\n将使用默认目录。").arg(modelsPath));
        }
        else {
            // 文件夹创建成功
            qDebug() << QString::fromLocal8Bit("成功创建目录:") << modelsPath;
        }
    }
    QString fn = QFileDialog::getOpenFileName( this, QString(), modelsPath);
    if (!fn.isEmpty()) {
        load(fn);
    }
}
/**
*  负责读取并加载指定文件的内容到文本编辑框中
*/
void QG_DlgMText::load(const QString& fn) {
    QFile f(fn);
    if (!f.open(QIODevice::ReadOnly)) {
        return;
    }
    QTextStream ts(&f);
    teText->setText(ts.readAll());
}
/**
*  将当前多行文本编辑器中的内容保存到一个外部文件中
*/
void QG_DlgMText::saveText() {
    QString appDir = QCoreApplication::applicationDirPath();
    QString modelsPath = appDir + "/PrintJob";
    // 检查文件夹是否存在，如果不存在则创建
    QDir dir(modelsPath);
    if (!dir.exists()) {
        // 创建文件夹（包括所有必要的父目录）
        if (!dir.mkpath(".")) {
            // 文件夹创建失败，显示错误信息并使用默认目录
            QMessageBox::warning(this,
                QString::fromLocal8Bit("文件夹创建失败"),
                QString::fromLocal8Bit("无法创建目录: %1\n将使用默认目录。").arg(modelsPath));
        }
    }
    QString fn = QFileDialog::getSaveFileName(this, QString(), modelsPath);
    if (!fn.isEmpty()) {
        save(fn);
    }
}
/**
*  专门负责将当前文本编辑框的内容写入并保存到指定文件中
*/
void QG_DlgMText::save(const QString& fn) {
    QString text = teText->toPlainText();
    QFile f(fn);
    if (f.open(QIODevice::WriteOnly)) {
        QTextStream t(&f);
        t << text;
        f.close();
    }
}
/**
*  将符号选择框中的某个特殊字符插入到当前文本编辑框的光标位置
*/
void QG_DlgMText::insertSymbol(int) {
    QString str = cbSymbol->currentText();//​获取组合框的当前文本
    int i=str.indexOf('(');
    if (i!=-1) {
        teText->textCursor().insertText(QString("%1").arg(str.at(i+1)));
    }
}

void  QG_DlgMText::setQuickTime() {

    teText->textCursor().insertText("hh:mm:ss");
    
}
void  QG_DlgMText::setMFGDateText() {

    teText->textCursor().insertText(QString::fromLocal8Bit("生产日期"));
}
void  QG_DlgMText::setEXPDateText() {

    teText->textCursor().insertText(QString::fromLocal8Bit("保质期至"));
}
void  QG_DlgMText::setLineBreak() {

    teText->insertPlainText("\n");
}
void QG_DlgMText::setMFGDate() {
    // 确认弹窗
    QDialog dialog;
    dialog.setWindowTitle(QString::fromLocal8Bit("选择日期 "));
    dialog.resize(700, 350);

    RollingBox timebox(&dialog);

    // 使用QDialogButtonBox简化按钮的创建和连接
    QDialogButtonBox* buttonBox = new QDialogButtonBox(&dialog);
    buttonBox->setGeometry(120, 200, 500, 200);

    QPushButton* okButton = new QPushButton(QString::fromLocal8Bit("新建 "));
    QPushButton* modifyButton = new QPushButton(QString::fromLocal8Bit("修改 ")); // 添加修改按钮
    QPushButton* cancelButton = new QPushButton(QString::fromLocal8Bit("取消 "));
    buttonBox->addButton(okButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(modifyButton, QDialogButtonBox::ActionRole); // 添加修改按钮到按钮盒
    buttonBox->addButton(cancelButton, QDialogButtonBox::ActionRole);

    buttonBox->setStyleSheet("QPushButton { margin-right: 50px; width: 100px; height: 50px; }");

    // 连接取消按钮
    connect(cancelButton, &QPushButton::clicked, &dialog, &QDialog::reject);

    // 连接修改按钮
    connect(modifyButton, &QPushButton::clicked, &dialog, [&]() {
        QDate newDate(timebox.readYear(), timebox.readMonth(), timebox.readDay());
        QTextCursor cursor = teText->textCursor();
        QString newDateStr = newDate.toString("yyyy MM dd");
        if (m_mfgDate.isValid()) {
            QString oldDateStr = m_mfgDate.toString("yyyy MM dd");
            QString text = teText->toPlainText();
            int pos = text.indexOf(oldDateStr);
            if (pos >= 0) {
                cursor.setPosition(pos);
                cursor.setPosition(pos + oldDateStr.length(), QTextCursor::KeepAnchor);
                cursor.insertText(newDateStr);
            }
            QString oldExpDateStr = m_mfgDate.addYears(m_expYears).addMonths(m_expMonths).addDays(m_expDays).addDays(-1).toString("yyyy MM dd");
            QString newExpDateStr = newDate.addYears(m_expYears).addMonths(m_expMonths).addDays(m_expDays).addDays(-1).toString("yyyy MM dd");
            text = teText->toPlainText();
            int expPos = text.indexOf(oldExpDateStr);
            if (expPos >= 0) {
                cursor.setPosition(expPos);
                cursor.setPosition(expPos + oldExpDateStr.length(), QTextCursor::KeepAnchor);
                cursor.insertText(newExpDateStr);
            }
        }
        else {
            cursor.insertText("{MFG}");
        }
        m_mfgDate = newDate;
        label_9->setText(QString::fromLocal8Bit("%1").arg(m_mfgDate.toString("yyyy MM dd")));
        dialog.accept();
        });

    // 连接确定按钮
    connect(okButton, &QPushButton::clicked, &dialog, [&]() {
        m_mfgDate = QDate(timebox.readYear(), timebox.readMonth(), timebox.readDay());
        QTextCursor cursor = teText->textCursor();
        cursor.insertText("{MFG}");
        label_9->setText(QString::fromLocal8Bit("%1").arg(m_mfgDate.toString("yyyy MM dd")));
        dialog.accept();
        });

    dialog.exec(); // 直接调用 exec，内部逻辑由按钮连接处理
}
void QG_DlgMText::setEXPDate() {

    QDialog dialog;
    dialog.setWindowTitle(QString::fromLocal8Bit("保质期偏移"));
    dialog.setFixedSize(380, 300);

    QVBoxLayout mainLayout(&dialog);
    mainLayout.setSpacing(15);
    mainLayout.setContentsMargins(30, 20, 30, 20);

    QLabel title(QString::fromLocal8Bit("设置保质期偏移量:"), &dialog);
    title.setAlignment(Qt::AlignCenter);
    title.setStyleSheet("font-size: 18px; font-weight: bold;");
    mainLayout.addWidget(&title);

    // 年月日输入
    QGridLayout* gridLayout = new QGridLayout();
    gridLayout->setSpacing(12);

    QLabel* yearLabel = new QLabel(QString::fromLocal8Bit("年偏移:"), &dialog);
    yearLabel->setStyleSheet("font-size: 16px;");
    QSpinBox* yearSpin = new QSpinBox(&dialog);
    yearSpin->setRange(0, 100);
    yearSpin->setValue(m_expYears);
    yearSpin->setStyleSheet("font-size: 18px; padding: 5px;");
    gridLayout->addWidget(yearLabel, 0, 0);
    gridLayout->addWidget(yearSpin, 0, 1);

    QLabel* monthLabel = new QLabel(QString::fromLocal8Bit("月偏移:"), &dialog);
    monthLabel->setStyleSheet("font-size: 16px;");
    QSpinBox* monthSpin = new QSpinBox(&dialog);
    monthSpin->setRange(0, 1200);
    monthSpin->setValue(m_expMonths);
    monthSpin->setStyleSheet("font-size: 18px; padding: 5px;");
    gridLayout->addWidget(monthLabel, 1, 0);
    gridLayout->addWidget(monthSpin, 1, 1);

    QLabel* dayLabel = new QLabel(QString::fromLocal8Bit("日偏移:"), &dialog);
    dayLabel->setStyleSheet("font-size: 16px;");
    QSpinBox* daySpin = new QSpinBox(&dialog);
    daySpin->setRange(0, 365);
    daySpin->setValue(m_expDays);
    daySpin->setStyleSheet("font-size: 18px; padding: 5px;");
    gridLayout->addWidget(dayLabel, 2, 0);
    gridLayout->addWidget(daySpin, 2, 1);

    mainLayout.addLayout(gridLayout);
    mainLayout.addStretch();

    // 按钮
    QHBoxLayout* btnLayout = new QHBoxLayout();
    btnLayout->setSpacing(20);
    btnLayout->setAlignment(Qt::AlignCenter);

    QPushButton* cancelBtn = new QPushButton(QString::fromLocal8Bit("取消"), &dialog);
    QPushButton* okBtn = new QPushButton(QString::fromLocal8Bit("新建"), &dialog);

    QString btnStyle = R"(
        QPushButton { font-size: 16px; padding: 8px 25px; border: 2px solid #cccccc; border-radius: 6px; min-width: 80px; min-height: 35px; font-weight: bold; }
        QPushButton:hover { background-color: #f8f8f8; }
    )";
    cancelBtn->setStyleSheet(btnStyle);
    okBtn->setStyleSheet(btnStyle + R"(
        QPushButton { background-color: #4CAF50; color: white; border-color: #45a049; }
        QPushButton:hover { background-color: #45a049; }
    )");

    btnLayout->addWidget(cancelBtn);
    btnLayout->addWidget(okBtn);
    mainLayout.addLayout(btnLayout);

    connect(cancelBtn, &QPushButton::clicked, &dialog, &QDialog::reject);
    connect(okBtn, &QPushButton::clicked, &dialog, [&]() {
        m_expYears = yearSpin->value();
        m_expMonths = monthSpin->value();
        m_expDays = daySpin->value();
        int years = yearSpin->value();
        int months = monthSpin->value();
        int days = daySpin->value();
        QString placeholder;
        if (years > 0) placeholder += QString("+%1Y").arg(years);
        if (months > 0) placeholder += QString("+%1M").arg(months);
        if (days > 0) placeholder += QString("+%1D").arg(days);
        if (placeholder.isEmpty()) placeholder = "+0M";
        teText->textCursor().insertText(QString("{EXP%1}").arg(placeholder));
        dialog.accept();
    });

    dialog.exec();
}



QString QG_DlgMText::replaceDatePlaceholders(const QString& input) {
    QString result = input;

    // 替换 {MFG} 为实际生产日期
    if (result.contains("{MFG}") && m_mfgDate.isValid()) {
        result.replace("{MFG}", m_mfgDate.toString("yyyy MM dd"));
    }

    // 替换 {EXP...} 为实际保质期（支持多个）
    QRegularExpression expRe(R"(\{EXP((?:\+\d+[YMD])*)\})");
    QRegularExpressionMatchIterator expIt = expRe.globalMatch(result);
    while (expIt.hasNext()) {
        QRegularExpressionMatch match = expIt.next();
        QString expStr = match.captured(1);
        QDate baseDate = m_mfgDate.isValid() ? m_mfgDate : QDate::currentDate();
        QDate expiryDate = baseDate;

        // 先加年月偏移
        QRegularExpression yearRe(R"(\+(\d+)Y)");
        QRegularExpression monthRe(R"(\+(\d+)M)");
        QRegularExpression dayRe(R"(\+(\d+)D)");
        QRegularExpressionMatch yMatch = yearRe.match(expStr);
        QRegularExpressionMatch mMatch = monthRe.match(expStr);
        QRegularExpressionMatch dMatch = dayRe.match(expStr);
        if (yMatch.hasMatch()) expiryDate = expiryDate.addYears(yMatch.captured(1).toInt());
        if (mMatch.hasMatch()) expiryDate = expiryDate.addMonths(mMatch.captured(1).toInt());
        // 只有日期没被月末钳位时，才减1天（年月偏移后的日期 - 1天）
        if (expiryDate.day() == baseDate.day()) {
            expiryDate = expiryDate.addDays(-1);
        }
        // 最后加日偏移
        if (dMatch.hasMatch()) expiryDate = expiryDate.addDays(dMatch.captured(1).toInt());
        result.replace(match.captured(0), expiryDate.toString("yyyy MM dd"));
    }

    return result;
}

void QG_DlgMText::updateUniCharButton(int) {
    QString t = cbUniChar->currentText();
    int i1 = t.indexOf(']');
    int c = t.mid(1, i1-1).toInt(NULL, 16);
    bUnicode->setText(QString("%1").arg(QChar(c)));
}

void QG_DlgMText::insertChar() {
    QString t = cbUniChar->currentText();
    int i1 = t.indexOf(']');
    int c = t.mid(1, i1-1).toInt(NULL, 16);
    teText->textCursor().insertText( QString("%1").arg(QChar(c)) );
}
