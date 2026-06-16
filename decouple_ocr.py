# -*- coding: utf-8 -*-
"""解耦 OcrFilterRules：去掉 getUi()、ui_OcrFilterRules.h 暴露"""

# ===== 1. OcrFilterRules.h =====
with open('librecad/src/OCRdemo/OcrFilterRules.h', 'rb') as f:
    h = f.read()
h = h.decode('utf-8')

# 删除 getUi()
h = h.replace(
    '\t\t/// 获取内部 UI 指针（直接访问控件）\n\t\tUi::OcrFilterRulesClass* getUi() const { return ui; }\n\n\t\t// ========== 自定义检测文本',
    '\t\t// ========== 自定义检测文本'
)

# 添加 setShelfLifeDaysRange 和 setLineEditReadOnly
h = h.replace(
    '\t\tvoid setShelfLifeDays(int days);\n\t\tint getShelfLifeDays() const;',
    '\t\tvoid setShelfLifeDays(int days);\n\t\tvoid setShelfLifeDaysRange(int min, int max);\n\t\tint getShelfLifeDays() const;'
)
h = h.replace(
    '\t\tvoid setCloseButtonIcons();',
    '\t\tvoid setCloseButtonIcons();\n\t\tvoid setLineEditReadOnly();'
)

with open('librecad/src/OCRdemo/OcrFilterRules.h', 'wb') as f:
    f.write(h.encode('utf-8'))
print('OK .h')


# ===== 2. OcrFilterRules.cpp =====
with open('librecad/src/OCRdemo/OcrFilterRules.cpp', 'rb') as f:
    cpp = f.read()
cpp = cpp.decode('utf-8')

# 添加 setShelfLifeDaysRange
cpp = cpp.replace(
    'int OcrFilterRules::getShelfLifeDays() const',
    'void OcrFilterRules::setShelfLifeDaysRange(int min, int max)\n{\n\tif (ui->spinBox) {\n\t\tui->spinBox->setMinimum(min);\n\t\tui->spinBox->setMaximum(max);\n\t}\n}\n\nint OcrFilterRules::getShelfLifeDays() const'
)

# 添加 setLineEditReadOnly
cpp = cpp.replace(
    'void OcrFilterRules::setCloseButtonIcons()',
    'void OcrFilterRules::setLineEditReadOnly()\n{\n\tif (ui->lineEdit) ui->lineEdit->setFocusPolicy(Qt::NoFocus);\n\tif (ui->lineEdit_3) ui->lineEdit_3->setFocusPolicy(Qt::NoFocus);\n}\n\nvoid OcrFilterRules::setCloseButtonIcons()'
)

with open('librecad/src/OCRdemo/OcrFilterRules.cpp', 'wb') as f:
    f.write(cpp.encode('utf-8'))
print('OK .cpp')


# ===== 3. qc_applicationwindow.cpp =====
with open('librecad/src/main/qc_applicationwindow.cpp', 'rb') as f:
    raw = f.read()
q = raw.decode('gbk')

# 删除 #include "ui_OcrFilterRules.h"
q = q.replace('#include "ui_OcrFilterRules.h"\n', '')
print('Removed ui_OcrFilterRules.h include')

# 替换 getUi()->spinBox->setMaximum/setMinimum -> setShelfLifeDaysRange
q = q.replace(
    '    ocrFilterRules.getUi()->spinBox->setMaximum(10000);\n    ocrFilterRules.getUi()->spinBox->setMinimum(-10000);',
    '    ocrFilterRules.setShelfLifeDaysRange(-10000, 10000);'
)
print('Replaced setMaximum/setMinimum')

# 替换 getUi()->spinBox->setValue -> setShelfLifeDays
q = q.replace(
    'ocrFilterRules.getUi()->spinBox->setValue(save_time);',
    'ocrFilterRules.setShelfLifeDays(save_time);'
)
print('Replaced spinBox setValue')

# 替换 getUi()->spinBox_2->setValue -> setShelfLifeMonths
q = q.replace(
    'ocrFilterRules.getUi()->spinBox_2->setValue(Savemonth);',
    'ocrFilterRules.setShelfLifeMonths(Savemonth);'
)
print('Replaced spinBox_2 setValue')

# 替换 getUi()->spinBox_3->setValue -> setShelfLifeYears
q = q.replace(
    'ocrFilterRules.getUi()->spinBox_3->setValue(Saveyear);',
    'ocrFilterRules.setShelfLifeYears(Saveyear);'
)
print('Replaced spinBox_3 setValue')

# 替换 getUi()->lineEdit->setFocusPolicy / lineEdit_3 -> setLineEditReadOnly
q = q.replace(
    '    ocrFilterRules.getUi()->lineEdit->setFocusPolicy(Qt::NoFocus);\n    ocrFilterRules.getUi()->lineEdit_3->setFocusPolicy(Qt::NoFocus);',
    '    ocrFilterRules.setLineEditReadOnly();'
)
print('Replaced focus policy')

with open('librecad/src/main/qc_applicationwindow.cpp', 'wb') as f:
    f.write(q.encode('gbk'))
print('OK qc_applicationwindow.cpp')

print('\nAll done - getUi() removed, coupling resolved')
