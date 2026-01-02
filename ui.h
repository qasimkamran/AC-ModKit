/********************************************************************************
** Form generated from reading UI file 'AC-ModkitogXxCj.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef AC_2D_MODKITOGXXCJ_H
#define AC_2D_MODKITOGXXCJ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_launcher
{
public:
    QTabWidget *tabWidget;
    QWidget *welcome;
    QTextEdit *workInProgress;
    QWidget *textureCorrect;
    QStackedWidget *textureCorrectStack;
    QWidget *main;
    QPushButton *autoModeButton;
    QPushButton *manualModeButton;
    QTextEdit *autoModeDescription;
    QTextEdit *instruction;
    QTextEdit *manualModeDescription;
    QWidget *manualMode;
    QToolButton *browseToolButton;
    QLineEdit *browseLineEdit;
    QStackedWidget *manualModeSubStack;
    QWidget *multiFile;
    QScrollArea *inputScrollArea;
    QWidget *inputScrollAreaWidgetContents;
    QScrollArea *outputScrollArea;
    QWidget *outputScrollAreaWidgetContents;
    QTextEdit *inputTitle;
    QTextEdit *outputTitle;
    QPushButton *saveAsDDSButtonMulti;
    QWidget *singleFile;
    QLabel *imagePreviewLabel;
    QTextEdit *filenameTextEdit;
    QPushButton *saveAsDDSButtonSingle;

    void setupUi(QDialog *launcher)
    {
        if (launcher->objectName().isEmpty())
            launcher->setObjectName(QString::fromUtf8("launcher"));
        launcher->resize(900, 600);
        launcher->setMinimumSize(QSize(900, 600));
        launcher->setMaximumSize(QSize(900, 600));
        launcher->setAutoFillBackground(false);
        launcher->setStyleSheet(QString());
        tabWidget = new QTabWidget(launcher);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(50, 60, 800, 500));
        tabWidget->setMinimumSize(QSize(800, 500));
        tabWidget->setMaximumSize(QSize(800, 500));
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background: rgba(0, 0, 0, 100);\n"
"}\n"
"\n"
"QTabBar {\n"
"    qproperty-drawBase: 0;\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"    border-top: 0px;\n"
"    border-right: 0px;\n"
"    border-left: 0px;\n"
"    border-bottom: 0px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 rgba(255, 255, 255, 35),\n"
"        stop:0.25 rgba(90, 90, 90, 220),\n"
"        stop:0.6 rgba(35, 35, 35, 230),\n"
"        stop:1 rgba(10, 10, 10, 255)\n"
"    );\n"
"\n"
"    border: 2px solid rgba(180, 180, 180, 60);\n"
"    border-bottom-color: rgba(0, 0, 0, 200);\n"
"\n"
"    border-radius: 6px;\n"
"    padding: 6px 14px;\n"
"\n"
"    color: #e6e6e6;\n"
"    font: 700 16pt \"Ubuntu Mono\";\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 rgba(255, 255, 255, 140),\n"
"        stop:0.22 rgba(210, 210, 210, 255),\n"
"        stop:0.55 rgba(120, 120, 120, 255),\n"
""
                        "        stop:1 rgba(40, 40, 40, 255)\n"
"    );\n"
"\n"
"    border: 1px solid rgba(255, 255, 255, 140);\n"
"    border-bottom-color: rgba(30, 30, 30, 255);\n"
"\n"
"    color: #ffffff;\n"
"}"));
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setUsesScrollButtons(false);
        tabWidget->setDocumentMode(true);
        tabWidget->setTabBarAutoHide(false);
        welcome = new QWidget();
        welcome->setObjectName(QString::fromUtf8("welcome"));
        workInProgress = new QTextEdit(welcome);
        workInProgress->setObjectName(QString::fromUtf8("workInProgress"));
        workInProgress->setGeometry(QRect(40, 390, 291, 41));
        workInProgress->setStyleSheet(QString::fromUtf8("border: 0px;\n"
"background: transparent;"));
        workInProgress->setReadOnly(true);
        tabWidget->addTab(welcome, QString());
        textureCorrect = new QWidget();
        textureCorrect->setObjectName(QString::fromUtf8("textureCorrect"));
        textureCorrectStack = new QStackedWidget(textureCorrect);
        textureCorrectStack->setObjectName(QString::fromUtf8("textureCorrectStack"));
        textureCorrectStack->setGeometry(QRect(0, 0, 801, 461));
        textureCorrectStack->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: 0px;"));
        main = new QWidget();
        main->setObjectName(QString::fromUtf8("main"));
        autoModeButton = new QPushButton(main);
        autoModeButton->setObjectName(QString::fromUtf8("autoModeButton"));
        autoModeButton->setGeometry(QRect(410, 290, 280, 80));
        autoModeButton->setMinimumSize(QSize(280, 80));
        autoModeButton->setMaximumSize(QSize(280, 80));
        autoModeButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #E0E0E0;\n"
"    background-color: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 0, y2: 1,\n"
"        stop: 0 #4A4A4A,\n"
"        stop: 0.5 #1E1E1E,\n"
"        stop: 1 #0F0F0F\n"
"    );\n"
"    border: 1px solid #000000;\n"
"    border-radius: 6px;\n"
"    padding: 6px 14px;\n"
"\n"
"	font-family: \"JetBrains Mono\", \"Fira Code\", \"Source Code Pro\", \"Consolas\", \"Courier New\", monospace;\n"
"    font-size: 24pt;\n"
"    font-weight: 600;\n"
"    letter-spacing: 1.5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 0, y2: 1,\n"
"        stop: 0 #5A5A5A,\n"
"        stop: 0.5 #2A2A2A,\n"
"        stop: 1 #1A1A1A\n"
"    );\n"
"    border: 1px solid #2F2F2F;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 0, y2: 1,\n"
"        stop: 0 #0F0F0F,\n"
"        stop: 0.5 #1A1A1A,\n"
"        stop: 1 #2A2A2A\n"
"    );\n"
"    border: 1px solid #000000;\n"
"}\n"
""
                        "\n"
"QPushButton:disabled {\n"
"    color: #777777;\n"
"    background-color: #2B2B2B;\n"
"    border: 1px solid #1A1A1A;\n"
"}\n"
"\n"
""));
        manualModeButton = new QPushButton(main);
        manualModeButton->setObjectName(QString::fromUtf8("manualModeButton"));
        manualModeButton->setGeometry(QRect(90, 290, 280, 80));
        manualModeButton->setMinimumSize(QSize(280, 80));
        manualModeButton->setMaximumSize(QSize(280, 80));
        manualModeButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #E0E0E0;\n"
"    background-color: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 0, y2: 1,\n"
"        stop: 0 #4A4A4A,\n"
"        stop: 0.5 #1E1E1E,\n"
"        stop: 1 #0F0F0F\n"
"    );\n"
"    border: 1px solid #000000;\n"
"    border-radius: 6px;\n"
"    padding: 6px 14px;\n"
"\n"
"	font-family: \"JetBrains Mono\", \"Fira Code\", \"Source Code Pro\", \"Consolas\", \"Courier New\", monospace;\n"
"    font-size: 24pt;\n"
"    font-weight: 600;\n"
"    letter-spacing: 1.5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 0, y2: 1,\n"
"        stop: 0 #5A5A5A,\n"
"        stop: 0.5 #2A2A2A,\n"
"        stop: 1 #1A1A1A\n"
"    );\n"
"    border: 1px solid #2F2F2F;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 0, y2: 1,\n"
"        stop: 0 #0F0F0F,\n"
"        stop: 0.5 #1A1A1A,\n"
"        stop: 1 #2A2A2A\n"
"    );\n"
"    border: 1px solid #000000;\n"
"}\n"
""
                        "\n"
"QPushButton:disabled {\n"
"    color: #777777;\n"
"    background-color: #2B2B2B;\n"
"    border: 1px solid #1A1A1A;\n"
"}\n"
"\n"
""));
        autoModeDescription = new QTextEdit(main);
        autoModeDescription->setObjectName(QString::fromUtf8("autoModeDescription"));
        autoModeDescription->setGeometry(QRect(70, 180, 611, 81));
        autoModeDescription->setStyleSheet(QString::fromUtf8("border: 0px;\n"
"background: transparent;"));
        autoModeDescription->setReadOnly(true);
        instruction = new QTextEdit(main);
        instruction->setObjectName(QString::fromUtf8("instruction"));
        instruction->setGeometry(QRect(40, 30, 601, 41));
        instruction->setStyleSheet(QString::fromUtf8("border: 0px;\n"
"background: transparent;"));
        instruction->setReadOnly(true);
        manualModeDescription = new QTextEdit(main);
        manualModeDescription->setObjectName(QString::fromUtf8("manualModeDescription"));
        manualModeDescription->setGeometry(QRect(70, 90, 611, 81));
        manualModeDescription->setStyleSheet(QString::fromUtf8("border: 0px;\n"
"background: transparent;"));
        manualModeDescription->setReadOnly(true);
        textureCorrectStack->addWidget(main);
        manualMode = new QWidget();
        manualMode->setObjectName(QString::fromUtf8("manualMode"));
        manualMode->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: 0px;"));
        browseToolButton = new QToolButton(manualMode);
        browseToolButton->setObjectName(QString::fromUtf8("browseToolButton"));
        browseToolButton->setGeometry(QRect(640, 40, 61, 41));
        browseToolButton->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    color: #E0E0E0;\n"
"    background-color: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 0, y2: 1,\n"
"        stop: 0 #4A4A4A,\n"
"        stop: 0.5 #1E1E1E,\n"
"        stop: 1 #0F0F0F\n"
"    );\n"
"    border: 1px solid #000000;\n"
"    border-radius: 6px;\n"
"    padding: 2px 10px;\n"
"\n"
"	font-family: \"JetBrains Mono\", \"Fira Code\", \"Source Code Pro\", \"Consolas\", \"Courier New\", monospace;\n"
"    font-size: 20pt;\n"
"    font-weight: 600;\n"
"    letter-spacing: 1.5px;\n"
"    text-align: center;\n"
"    padding-bottom: 10px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background-color: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 0, y2: 1,\n"
"        stop: 0 #5A5A5A,\n"
"        stop: 0.5 #2A2A2A,\n"
"        stop: 1 #1A1A1A\n"
"    );\n"
"    border: 1px solid #2F2F2F;\n"
"}\n"
"\n"
"QToolButton:pressed {\n"
"    background-color: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 0, y2: 1,\n"
"        stop: 0 #0F0F0F,\n"
"        stop: 0.5 #1A1A1A,\n"
"        stop: 1 #2"
                        "A2A2A\n"
"    );\n"
"    border: 1px solid #000000;\n"
"}\n"
"\n"
"QToolButton:disabled {\n"
"    color: #777777;\n"
"    background-color: #2B2B2B;\n"
"    border: 1px solid #1A1A1A;\n"
"}\n"
""));
        browseLineEdit = new QLineEdit(manualMode);
        browseLineEdit->setObjectName(QString::fromUtf8("browseLineEdit"));
        browseLineEdit->setGeometry(QRect(120, 40, 510, 40));
        browseLineEdit->setMinimumSize(QSize(510, 40));
        browseLineEdit->setMaximumSize(QSize(510, 40));
        browseLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: rgba(40, 40, 40, 160);   /* translucent dark gray */\n"
"    color: #E0E0E0;\n"
"\n"
"    border: 1px solid rgba(0, 0, 0, 180);\n"
"    border-radius: 4px;\n"
"\n"
"    padding: 0px;\n"
"\n"
"    font-family: \"JetBrains Mono\", \"Fira Code\", \"Source Code Pro\",\n"
"                 \"Consolas\", \"Courier New\", monospace;\n"
"    font-size: 14pt;\n"
"\n"
"    selection-background-color: rgba(120, 120, 120, 160);\n"
"    selection-color: #FFFFFF;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border: 1px solid rgba(90, 90, 90, 200);\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    background-color: rgba(50, 50, 50, 190);\n"
"    border: 1px solid rgba(140, 140, 140, 220);\n"
"}\n"
"\n"
"QLineEdit:disabled {\n"
"    background-color: rgba(30, 30, 30, 120);\n"
"    color: rgba(200, 200, 200, 120);\n"
"    border: 1px solid rgba(20, 20, 20, 120);\n"
"}"));
        manualModeSubStack = new QStackedWidget(manualMode);
        manualModeSubStack->setObjectName(QString::fromUtf8("manualModeSubStack"));
        manualModeSubStack->setGeometry(QRect(0, 80, 801, 381));
        multiFile = new QWidget();
        multiFile->setObjectName(QString::fromUtf8("multiFile"));
        inputScrollArea = new QScrollArea(multiFile);
        inputScrollArea->setObjectName(QString::fromUtf8("inputScrollArea"));
        inputScrollArea->setGeometry(QRect(30, 60, 251, 301));
        inputScrollArea->setStyleSheet(QString::fromUtf8("QScrollArea {\n"
"    background-color: rgba(40, 40, 40, 160);\n"
"    border: 1px solid rgba(0, 0, 0, 180);\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"}\n"
"\n"
"QScrollArea:hover {\n"
"    border: 1px solid rgba(90, 90, 90, 200);\n"
"}\n"
"\n"
"QScrollArea:disabled {\n"
"    background-color: rgba(30, 30, 30, 120);\n"
"    border: 1px solid rgba(20, 20, 20, 120);\n"
"}"));
        inputScrollArea->setWidgetResizable(true);
        inputScrollAreaWidgetContents = new QWidget();
        inputScrollAreaWidgetContents->setObjectName(QString::fromUtf8("inputScrollAreaWidgetContents"));
        inputScrollAreaWidgetContents->setGeometry(QRect(0, 0, 241, 291));
        inputScrollArea->setWidget(inputScrollAreaWidgetContents);
        outputScrollArea = new QScrollArea(multiFile);
        outputScrollArea->setObjectName(QString::fromUtf8("outputScrollArea"));
        outputScrollArea->setGeometry(QRect(300, 60, 251, 301));
        outputScrollArea->setStyleSheet(QString::fromUtf8("QScrollArea {\n"
"    background-color: rgba(40, 40, 40, 160);\n"
"    border: 1px solid rgba(0, 0, 0, 180);\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"}\n"
"\n"
"QScrollArea:hover {\n"
"    border: 1px solid rgba(90, 90, 90, 200);\n"
"}\n"
"\n"
"QScrollArea:disabled {\n"
"    background-color: rgba(30, 30, 30, 120);\n"
"    border: 1px solid rgba(20, 20, 20, 120);\n"
"}"));
        outputScrollArea->setWidgetResizable(true);
        outputScrollAreaWidgetContents = new QWidget();
        outputScrollAreaWidgetContents->setObjectName(QString::fromUtf8("outputScrollAreaWidgetContents"));
        outputScrollAreaWidgetContents->setGeometry(QRect(0, 0, 241, 291));
        outputScrollArea->setWidget(outputScrollAreaWidgetContents);
        inputTitle = new QTextEdit(multiFile);
        inputTitle->setObjectName(QString::fromUtf8("inputTitle"));
        inputTitle->setGeometry(QRect(10, 20, 71, 31));
        inputTitle->setReadOnly(true);
        outputTitle = new QTextEdit(multiFile);
        outputTitle->setObjectName(QString::fromUtf8("outputTitle"));
        outputTitle->setGeometry(QRect(280, 20, 81, 31));
        outputTitle->setReadOnly(true);
        saveAsDDSButtonMulti = new QPushButton(multiFile);
        saveAsDDSButtonMulti->setObjectName(QString::fromUtf8("saveAsDDSButtonMulti"));
        saveAsDDSButtonMulti->setGeometry(QRect(570, 60, 200, 60));
        saveAsDDSButtonMulti->setMinimumSize(QSize(200, 60));
        saveAsDDSButtonMulti->setMaximumSize(QSize(180, 60));
        saveAsDDSButtonMulti->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #E0E0E0;\n"
"    background-color: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 0, y2: 1,\n"
"        stop: 0 #4A4A4A,\n"
"        stop: 0.5 #1E1E1E,\n"
"        stop: 1 #0F0F0F\n"
"    );\n"
"    border: 1px solid #000000;\n"
"    border-radius: 6px;\n"
"    padding: 6px 14px;\n"
"\n"
"	font-family: \"JetBrains Mono\", \"Fira Code\", \"Source Code Pro\", \"Consolas\", \"Courier New\", monospace;\n"
"    font-size: 16pt;\n"
"    font-weight: 600;\n"
"    letter-spacing: 1.5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 0, y2: 1,\n"
"        stop: 0 #5A5A5A,\n"
"        stop: 0.5 #2A2A2A,\n"
"        stop: 1 #1A1A1A\n"
"    );\n"
"    border: 1px solid #2F2F2F;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 0, y2: 1,\n"
"        stop: 0 #0F0F0F,\n"
"        stop: 0.5 #1A1A1A,\n"
"        stop: 1 #2A2A2A\n"
"    );\n"
"    border: 1px solid #000000;\n"
"}\n"
""
                        "\n"
"QPushButton:disabled {\n"
"    color: #777777;\n"
"    background-color: #2B2B2B;\n"
"    border: 1px solid #1A1A1A;\n"
"}\n"
"\n"
""));
        manualModeSubStack->addWidget(multiFile);
        singleFile = new QWidget();
        singleFile->setObjectName(QString::fromUtf8("singleFile"));
        imagePreviewLabel = new QLabel(singleFile);
        imagePreviewLabel->setObjectName(QString::fromUtf8("imagePreviewLabel"));
        imagePreviewLabel->setGeometry(QRect(150, 30, 331, 281));
        imagePreviewLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgba(40, 40, 40, 160);   /* translucent dark gray */\n"
"    color: #E0E0E0;\n"
"\n"
"    border: 1px solid rgba(0, 0, 0, 180);\n"
"    border-radius: 4px;\n"
"\n"
"    padding: 0;\n"
"\n"
"    font-family: \"JetBrains Mono\", \"Fira Code\", \"Source Code Pro\",\n"
"                 \"Consolas\", \"Courier New\", monospace;\n"
"    font-size: 14pt;\n"
"\n"
"    qproperty-alignment: AlignCenter;\n"
"}"));
        filenameTextEdit = new QTextEdit(singleFile);
        filenameTextEdit->setObjectName(QString::fromUtf8("filenameTextEdit"));
        filenameTextEdit->setGeometry(QRect(160, 320, 311, 31));
        filenameTextEdit->setStyleSheet(QString::fromUtf8(""));
        filenameTextEdit->setReadOnly(true);
        saveAsDDSButtonSingle = new QPushButton(singleFile);
        saveAsDDSButtonSingle->setObjectName(QString::fromUtf8("saveAsDDSButtonSingle"));
        saveAsDDSButtonSingle->setGeometry(QRect(520, 60, 220, 60));
        saveAsDDSButtonSingle->setMinimumSize(QSize(220, 60));
        saveAsDDSButtonSingle->setMaximumSize(QSize(180, 60));
        saveAsDDSButtonSingle->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #E0E0E0;\n"
"    background-color: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 0, y2: 1,\n"
"        stop: 0 #4A4A4A,\n"
"        stop: 0.5 #1E1E1E,\n"
"        stop: 1 #0F0F0F\n"
"    );\n"
"    border: 1px solid #000000;\n"
"    border-radius: 6px;\n"
"    padding: 6px 14px;\n"
"\n"
"	font-family: \"JetBrains Mono\", \"Fira Code\", \"Source Code Pro\", \"Consolas\", \"Courier New\", monospace;\n"
"    font-size: 18pt;\n"
"    font-weight: 600;\n"
"    letter-spacing: 1.5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 0, y2: 1,\n"
"        stop: 0 #5A5A5A,\n"
"        stop: 0.5 #2A2A2A,\n"
"        stop: 1 #1A1A1A\n"
"    );\n"
"    border: 1px solid #2F2F2F;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 0, y2: 1,\n"
"        stop: 0 #0F0F0F,\n"
"        stop: 0.5 #1A1A1A,\n"
"        stop: 1 #2A2A2A\n"
"    );\n"
"    border: 1px solid #000000;\n"
"}\n"
""
                        "\n"
"QPushButton:disabled {\n"
"    color: #777777;\n"
"    background-color: #2B2B2B;\n"
"    border: 1px solid #1A1A1A;\n"
"}\n"
"\n"
""));
        manualModeSubStack->addWidget(singleFile);
        textureCorrectStack->addWidget(manualMode);
        tabWidget->addTab(textureCorrect, QString());

        retranslateUi(launcher);

        tabWidget->setCurrentIndex(1);
        textureCorrectStack->setCurrentIndex(1);
        manualModeSubStack->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(launcher);
    } // setupUi

    void retranslateUi(QDialog *launcher)
    {
        launcher->setWindowTitle(QCoreApplication::translate("launcher", "Assetto Corsa Modkit", nullptr));
#if QT_CONFIG(tooltip)
        launcher->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        launcher->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(accessibility)
        launcher->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        launcher->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(whatsthis)
        tabWidget->setWhatsThis(QCoreApplication::translate("launcher", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        workInProgress->setHtml(QCoreApplication::translate("launcher", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:20pt; font-style:italic; color:#ffffff;\">Work in progress...</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(welcome), QCoreApplication::translate("launcher", "Welcome", nullptr));
        autoModeButton->setText(QCoreApplication::translate("launcher", "Auto", nullptr));
        manualModeButton->setText(QCoreApplication::translate("launcher", "Manual", nullptr));
        autoModeDescription->setHtml(QCoreApplication::translate("launcher", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-style:italic; color:#ffffff;\">Auto mode will have you select a directory of textures and apply a set number of correction techniques to all images of known formats in that directory automatically.</span></p></body></html>", nullptr));
        instruction->setHtml(QCoreApplication::translate("launcher", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:20pt; font-weight:700; font-style:italic; color:#ffffff;\">Choose between application modes:</span></p></body></html>", nullptr));
        manualModeDescription->setHtml(QCoreApplication::translate("launcher", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-style:italic; color:#ffffff;\">Manual mode allows you to apply your desired texture correction techniques from this application to the individual files (or list of files) you pick out.</span></p></body></html>", nullptr));
        browseToolButton->setText(QCoreApplication::translate("launcher", "...", nullptr));
        browseLineEdit->setText(QCoreApplication::translate("launcher", "Browse files...", nullptr));
        inputTitle->setHtml(QCoreApplication::translate("launcher", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-style:italic; color:#ffffff;\">Input</span></p></body></html>", nullptr));
        outputTitle->setHtml(QCoreApplication::translate("launcher", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-style:italic; color:#ffffff;\">Output</span></p></body></html>", nullptr));
        saveAsDDSButtonMulti->setText(QCoreApplication::translate("launcher", "Save as DDS", nullptr));
        imagePreviewLabel->setText(QCoreApplication::translate("launcher", "Image Preview", nullptr));
        filenameTextEdit->setHtml(QCoreApplication::translate("launcher", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-style:italic; color:#ffffff;\">Filename</span></p></body></html>", nullptr));
        saveAsDDSButtonSingle->setText(QCoreApplication::translate("launcher", "Save as DDS", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(textureCorrect), QCoreApplication::translate("launcher", "Texture Correct", nullptr));
    } // retranslateUi

};

namespace Ui {
    class launcher: public Ui_launcher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // AC_2D_MODKITOGXXCJ_H
