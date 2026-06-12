#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Fix qc_applicationwindow.cpp with CRLF awareness

with open('librecad/src/main/qc_applicationwindow.cpp', 'rb') as f:
    raw = f.read()

text = raw.decode('gbk')
NL = '\r\n'  # CRLF

# 1. Move m_mutex creation before moveToThread, T->start after connect
old = '    OCRT->moveToThread(T);' + NL
old += '    T->start();//' + NL
old += '    connect(OCRT, &OCRruning::running, OCRT, &OCRruning::getocr);'

new = '    m_mutex = new QMutex;' + NL
new += '    OCRT->setMutex(m_mutex);' + NL
new += '    OCRT->moveToThread(T);' + NL
new += '    connect(OCRT, &OCRruning::running, OCRT, &OCRruning::getocr);' + NL
new += '    T->start();'

text = text.replace(old, new)

# 2. Remove the now-duplicate m_mutex lines
old2 = '    //' + NL
old2 += '    m_mutex = new QMutex;' + NL
old2 += '    OCRT->setMutex(m_mutex);' + NL
old2 += '   ' + NL

text = text.replace(old2, '')

# 3. Add chart = new SimpleBarChart(this) after setupUi
text = text.replace(
    '    ui->setupUi(this);' + NL,
    '    ui->setupUi(this);' + NL + '    chart = new SimpleBarChart(this);' + NL
)

# 4. Destructor: add cleanup
old_dtor = 'QC_ApplicationWindow::~QC_ApplicationWindow() {' + NL
old_dtor += '    RS_DEBUG->print("QC_ApplicationWindow::~QC_ApplicationWindow");' + NL
old_dtor += '' + NL
old_dtor += '    RS_DEBUG->print("QC_ApplicationWindow::~QC_ApplicationWindow: "' + NL
old_dtor += '                    \"deleting dialog factory\");'

new_dtor = 'QC_ApplicationWindow::~QC_ApplicationWindow() {' + NL
new_dtor += '    RS_DEBUG->print("QC_ApplicationWindow::~QC_ApplicationWindow");' + NL
new_dtor += '' + NL
new_dtor += '    RS_DEBUG->print("QC_ApplicationWindow::~QC_ApplicationWindow: "' + NL
new_dtor += '                    \"deleting dialog factory\");' + NL
new_dtor += '' + NL
new_dtor += '    if (T && T->isRunning()) {' + NL
new_dtor += '        T->quit();' + NL
new_dtor += '        T->wait(3000);' + NL
new_dtor += '    }' + NL
new_dtor += '    delete m_mutex;' + NL
new_dtor += '    m_mutex = nullptr;' + NL
new_dtor += '    delete T;' + NL
new_dtor += '    T = nullptr;'

text = text.replace(old_dtor, new_dtor)

with open('librecad/src/main/qc_applicationwindow.cpp', 'wb') as f:
    f.write(text.encode('gbk'))

# Verify
checks = [
    ('mutex before moveToThread', 'm_mutex = new QMutex;\r\n    OCRT->setMutex'),
    ('connect before T->start', 'getocr);\r\n    T->start();'),
    ('chart after setupUi', 'setupUi(this);\r\n    chart = new SimpleBarChart'),
    ('dtor cleanup', 'delete m_mutex;\r\n    m_mutex = nullptr;\r\n    delete T;\r\n    T = nullptr;'),
]
for label, pat in checks:
    if pat in text:
        print('OK  ' + label)
    else:
        print('FAIL ' + label)
