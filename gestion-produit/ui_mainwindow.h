/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QFrame *frame_2;
    QLabel *label_11;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_3;
    QTableView *tableView;
    QGroupBox *groupBox_2;
    QLabel *label_14;
    QLineEdit *lineEdit_refR;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLineEdit *lineEdit_remise;
    QLabel *label_19;
    QPushButton *pushButton_6;
    QPushButton *pushButton_remise;
    QLineEdit *lineEdit_refE;
    QPushButton *pushButton_cal;
    QTextEdit *textEdit;
    QPushButton *pushButtonPDF;
    QTabWidget *tabWidget;
    QWidget *tabAjout;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_ref;
    QLineEdit *lineEdit_quantite;
    QLineEdit *lineEdit_fournisseur;
    QLineEdit *lineEdit_prix;
    QPushButton *pushButton_ajouter;
    QLabel *label_8;
    QLineEdit *lineEdit_nom;
    QListWidget *listWidget;
    QLabel *label_12;
    QWidget *tab_2;
    QGroupBox *groupBox_3;
    QLabel *label_24;
    QLineEdit *lineEdit_ref2;
    QPushButton *pushButton_supp;
    QLabel *label_9;
    QLineEdit *lineEdit_ref3;
    QLabel *label_10;
    QLabel *label_13;
    QLineEdit *lineEdit_prix3;
    QLineEdit *lineEdit_quantite3;
    QPushButton *pushButton_update;
    QPushButton *pushButton_rech;
    QWidget *tab;
    QGroupBox *groupBox_4;
    QLabel *label_25;
    QLineEdit *lineEdit_refch2;
    QPushButton *pushButton_rech2;
    QTableView *tableView2;
    QWidget *tab_3;
    QGroupBox *groupBox_5;
    QLabel *label_26;
    QLineEdit *lineEdit_cin;
    QPushButton *pushButton_rechcin;
    QLabel *label_27;
    QLabel *lab;
    QPushButton *pushButton_stats;
    QPushButton *pushButton_trie;
    QPushButton *pushButton_triQ;
    QPushButton *pushButton_triP;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1576, 926);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(16, 44, 87, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(24, 66, 131, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(20, 55, 109, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(8, 22, 43, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(10, 29, 58, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        QBrush brush8(QColor(255, 255, 255, 128));
        brush8.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        MainWindow->setPalette(palette);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, -41, 1611, 921));
        frame->setStyleSheet(QStringLiteral("background-color: rgb(16, 44, 87);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(420, 10, 691, 361));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush);
        QBrush brush9(QColor(244, 237, 227, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush9);
        QBrush brush10(QColor(117, 109, 100, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush10);
        QBrush brush11(QColor(156, 146, 133, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush11);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush9);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        QBrush brush12(QColor(0, 0, 0, 128));
        brush12.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush12);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush12);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        QBrush brush13(QColor(234, 219, 200, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush13);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush12);
#endif
        frame_2->setPalette(palette1);
        frame_2->setAutoFillBackground(false);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_11 = new QLabel(frame);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(1420, 80, 131, 31));
        QFont font;
        font.setFamily(QStringLiteral("Stencil"));
        font.setPointSize(12);
        label_11->setFont(font);
        label_11->setStyleSheet(QStringLiteral("color: rgb(248, 240, 229);"));
        scrollArea_2 = new QScrollArea(frame);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(470, 80, 901, 321));
        scrollArea_2->setStyleSheet(QStringLiteral("background-color: rgb(248, 240, 229);"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QStringLiteral("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 899, 319));
        tableView = new QTableView(scrollAreaWidgetContents_3);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(0, 0, 901, 321));
        scrollArea_2->setWidget(scrollAreaWidgetContents_3);
        groupBox_2 = new QGroupBox(frame);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(470, 400, 901, 291));
        QPalette palette2;
        QBrush brush14(QColor(248, 240, 229, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush14);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush);
        QBrush brush15(QColor(251, 247, 242, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush15);
        QBrush brush16(QColor(124, 120, 114, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush16);
        QBrush brush17(QColor(165, 160, 153, 255));
        brush17.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush17);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush15);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush12);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush14);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush15);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush16);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush17);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush15);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush12);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush16);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush16);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush17);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush16);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush16);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush12);
#endif
        groupBox_2->setPalette(palette2);
        QFont font1;
        font1.setFamily(QStringLiteral("Stencil"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        groupBox_2->setFont(font1);
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 30, 131, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Stencil"));
        font2.setPointSize(12);
        font2.setUnderline(true);
        label_14->setFont(font2);
        label_14->setStyleSheet(QStringLiteral("color: rgb(248, 240, 229);"));
        lineEdit_refR = new QLineEdit(groupBox_2);
        lineEdit_refR->setObjectName(QStringLiteral("lineEdit_refR"));
        lineEdit_refR->setGeometry(QRect(190, 70, 181, 31));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush18(QColor(255, 255, 255, 128));
        brush18.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush18);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush19(QColor(255, 255, 255, 128));
        brush19.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush19);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush16);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush20(QColor(255, 255, 255, 128));
        brush20.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush20);
#endif
        lineEdit_refR->setPalette(palette3);
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(410, 70, 111, 31));
        label_15->setFont(font);
        label_15->setStyleSheet(QStringLiteral("color: rgb(248, 240, 229);"));
        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(10, 120, 251, 31));
        label_16->setFont(font2);
        label_16->setStyleSheet(QStringLiteral("color: rgb(248, 240, 229);"));
        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(50, 170, 131, 31));
        label_17->setFont(font);
        label_17->setStyleSheet(QStringLiteral("color: rgb(248, 240, 229);"));
        lineEdit_remise = new QLineEdit(groupBox_2);
        lineEdit_remise->setObjectName(QStringLiteral("lineEdit_remise"));
        lineEdit_remise->setGeometry(QRect(530, 70, 181, 31));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush21(QColor(255, 255, 255, 128));
        brush21.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush21);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush22(QColor(255, 255, 255, 128));
        brush22.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush22);
#endif
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush16);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush23(QColor(255, 255, 255, 128));
        brush23.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush23);
#endif
        lineEdit_remise->setPalette(palette4);
        label_19 = new QLabel(groupBox_2);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(50, 70, 131, 31));
        label_19->setFont(font);
        label_19->setStyleSheet(QStringLiteral("color: rgb(248, 240, 229);"));
        pushButton_6 = new QPushButton(groupBox_2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(150, 640, 93, 28));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        pushButton_6->setPalette(palette5);
        pushButton_remise = new QPushButton(groupBox_2);
        pushButton_remise->setObjectName(QStringLiteral("pushButton_remise"));
        pushButton_remise->setGeometry(QRect(730, 70, 93, 28));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Button, brush);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush);
        pushButton_remise->setPalette(palette6);
        pushButton_remise->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lineEdit_refE = new QLineEdit(groupBox_2);
        lineEdit_refE->setObjectName(QStringLiteral("lineEdit_refE"));
        lineEdit_refE->setGeometry(QRect(190, 170, 181, 31));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush24(QColor(255, 255, 255, 128));
        brush24.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Active, QPalette::PlaceholderText, brush24);
#endif
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush25(QColor(255, 255, 255, 128));
        brush25.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush25);
#endif
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush16);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush26(QColor(255, 255, 255, 128));
        brush26.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush26);
#endif
        lineEdit_refE->setPalette(palette7);
        pushButton_cal = new QPushButton(groupBox_2);
        pushButton_cal->setObjectName(QStringLiteral("pushButton_cal"));
        pushButton_cal->setGeometry(QRect(460, 170, 93, 28));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::Button, brush);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush);
        pushButton_cal->setPalette(palette8);
        pushButton_cal->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        textEdit = new QTextEdit(groupBox_2);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(590, 150, 231, 91));
        pushButtonPDF = new QPushButton(frame);
        pushButtonPDF->setObjectName(QStringLiteral("pushButtonPDF"));
        pushButtonPDF->setGeometry(QRect(1420, 620, 93, 28));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::Button, brush);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush);
        pushButtonPDF->setPalette(palette9);
        pushButtonPDF->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        tabWidget = new QTabWidget(frame);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 60, 451, 631));
        tabAjout = new QWidget();
        tabAjout->setObjectName(QStringLiteral("tabAjout"));
        groupBox = new QGroupBox(tabAjout);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 421, 581));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush14);
        palette10.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Active, QPalette::Light, brush);
        palette10.setBrush(QPalette::Active, QPalette::Midlight, brush15);
        palette10.setBrush(QPalette::Active, QPalette::Dark, brush16);
        palette10.setBrush(QPalette::Active, QPalette::Mid, brush17);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette10.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette10.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette10.setBrush(QPalette::Active, QPalette::AlternateBase, brush15);
        palette10.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette10.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Active, QPalette::PlaceholderText, brush12);
#endif
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush14);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Midlight, brush15);
        palette10.setBrush(QPalette::Inactive, QPalette::Dark, brush16);
        palette10.setBrush(QPalette::Inactive, QPalette::Mid, brush17);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette10.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette10.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush15);
        palette10.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette10.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush12);
#endif
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush16);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::Midlight, brush15);
        palette10.setBrush(QPalette::Disabled, QPalette::Dark, brush16);
        palette10.setBrush(QPalette::Disabled, QPalette::Mid, brush17);
        palette10.setBrush(QPalette::Disabled, QPalette::Text, brush16);
        palette10.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush16);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette10.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush14);
        palette10.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette10.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush12);
#endif
        groupBox->setPalette(palette10);
        groupBox->setFont(font1);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 50, 131, 31));
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("color: rgb(248, 240, 229);"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 270, 101, 31));
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("color: rgb(248, 240, 229);"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 330, 131, 31));
        label_4->setFont(font);
        label_4->setStyleSheet(QStringLiteral("color: rgb(248, 240, 229);"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 450, 191, 31));
        label_5->setFont(font);
        label_5->setStyleSheet(QStringLiteral("color: rgb(248, 240, 229);"));
        lineEdit_ref = new QLineEdit(groupBox);
        lineEdit_ref->setObjectName(QStringLiteral("lineEdit_ref"));
        lineEdit_ref->setGeometry(QRect(210, 210, 181, 31));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette11.setBrush(QPalette::Active, QPalette::Text, brush);
        palette11.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette11.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush27(QColor(255, 255, 255, 128));
        brush27.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Active, QPalette::PlaceholderText, brush27);
#endif
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush28(QColor(255, 255, 255, 128));
        brush28.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush28);
#endif
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::Text, brush16);
        palette11.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush29(QColor(255, 255, 255, 128));
        brush29.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush29);
#endif
        lineEdit_ref->setPalette(palette11);
        lineEdit_ref->setClearButtonEnabled(true);
        lineEdit_quantite = new QLineEdit(groupBox);
        lineEdit_quantite->setObjectName(QStringLiteral("lineEdit_quantite"));
        lineEdit_quantite->setGeometry(QRect(210, 330, 181, 31));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette12.setBrush(QPalette::Active, QPalette::Text, brush);
        palette12.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette12.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush30(QColor(255, 255, 255, 128));
        brush30.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Active, QPalette::PlaceholderText, brush30);
#endif
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush31(QColor(255, 255, 255, 128));
        brush31.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush31);
#endif
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::Text, brush16);
        palette12.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush32(QColor(255, 255, 255, 128));
        brush32.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush32);
#endif
        lineEdit_quantite->setPalette(palette12);
        lineEdit_quantite->setClearButtonEnabled(true);
        lineEdit_fournisseur = new QLineEdit(groupBox);
        lineEdit_fournisseur->setObjectName(QStringLiteral("lineEdit_fournisseur"));
        lineEdit_fournisseur->setGeometry(QRect(210, 390, 181, 31));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette13.setBrush(QPalette::Active, QPalette::Text, brush);
        palette13.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette13.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush33(QColor(255, 255, 255, 128));
        brush33.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Active, QPalette::PlaceholderText, brush33);
#endif
        palette13.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette13.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette13.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush34(QColor(255, 255, 255, 128));
        brush34.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush34);
#endif
        palette13.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::Text, brush16);
        palette13.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush35(QColor(255, 255, 255, 128));
        brush35.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush35);
#endif
        lineEdit_fournisseur->setPalette(palette13);
        lineEdit_fournisseur->setClearButtonEnabled(true);
        lineEdit_prix = new QLineEdit(groupBox);
        lineEdit_prix->setObjectName(QStringLiteral("lineEdit_prix"));
        lineEdit_prix->setGeometry(QRect(210, 450, 181, 31));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette14.setBrush(QPalette::Active, QPalette::Text, brush);
        palette14.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette14.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush36(QColor(255, 255, 255, 128));
        brush36.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Active, QPalette::PlaceholderText, brush36);
#endif
        palette14.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush37(QColor(255, 255, 255, 128));
        brush37.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush37);
#endif
        palette14.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::Text, brush16);
        palette14.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush38(QColor(255, 255, 255, 128));
        brush38.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush38);
#endif
        lineEdit_prix->setPalette(palette14);
        lineEdit_prix->setClearButtonEnabled(true);
        pushButton_ajouter = new QPushButton(groupBox);
        pushButton_ajouter->setObjectName(QStringLiteral("pushButton_ajouter"));
        pushButton_ajouter->setGeometry(QRect(160, 510, 93, 28));
        pushButton_ajouter->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 210, 131, 31));
        label_8->setFont(font);
        label_8->setStyleSheet(QStringLiteral("color: rgb(248, 240, 229);"));
        lineEdit_nom = new QLineEdit(groupBox);
        lineEdit_nom->setObjectName(QStringLiteral("lineEdit_nom"));
        lineEdit_nom->setGeometry(QRect(210, 270, 181, 31));
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette15.setBrush(QPalette::Active, QPalette::Text, brush);
        palette15.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette15.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush39(QColor(255, 255, 255, 128));
        brush39.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Active, QPalette::PlaceholderText, brush39);
#endif
        palette15.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette15.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette15.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush40(QColor(255, 255, 255, 128));
        brush40.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush40);
#endif
        palette15.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette15.setBrush(QPalette::Disabled, QPalette::Text, brush16);
        palette15.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette15.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush41(QColor(255, 255, 255, 128));
        brush41.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush41);
#endif
        lineEdit_nom->setPalette(palette15);
        lineEdit_nom->setClearButtonEnabled(true);
        listWidget = new QListWidget(groupBox);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(180, 50, 211, 141));
        listWidget->setFont(font);
        listWidget->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 390, 151, 31));
        label_12->setFont(font);
        label_12->setStyleSheet(QStringLiteral("color: rgb(248, 240, 229);"));
        tabWidget->addTab(tabAjout, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 10, 421, 581));
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::WindowText, brush14);
        palette16.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette16.setBrush(QPalette::Active, QPalette::Light, brush);
        palette16.setBrush(QPalette::Active, QPalette::Midlight, brush15);
        palette16.setBrush(QPalette::Active, QPalette::Dark, brush16);
        palette16.setBrush(QPalette::Active, QPalette::Mid, brush17);
        palette16.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette16.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette16.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette16.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette16.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette16.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette16.setBrush(QPalette::Active, QPalette::AlternateBase, brush15);
        palette16.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette16.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Active, QPalette::PlaceholderText, brush12);
#endif
        palette16.setBrush(QPalette::Inactive, QPalette::WindowText, brush14);
        palette16.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::Midlight, brush15);
        palette16.setBrush(QPalette::Inactive, QPalette::Dark, brush16);
        palette16.setBrush(QPalette::Inactive, QPalette::Mid, brush17);
        palette16.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette16.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette16.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette16.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush15);
        palette16.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette16.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush12);
#endif
        palette16.setBrush(QPalette::Disabled, QPalette::WindowText, brush16);
        palette16.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette16.setBrush(QPalette::Disabled, QPalette::Midlight, brush15);
        palette16.setBrush(QPalette::Disabled, QPalette::Dark, brush16);
        palette16.setBrush(QPalette::Disabled, QPalette::Mid, brush17);
        palette16.setBrush(QPalette::Disabled, QPalette::Text, brush16);
        palette16.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette16.setBrush(QPalette::Disabled, QPalette::ButtonText, brush16);
        palette16.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette16.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush14);
        palette16.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette16.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush12);
#endif
        groupBox_3->setPalette(palette16);
        groupBox_3->setFont(font1);
        label_24 = new QLabel(groupBox_3);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(150, 60, 131, 31));
        label_24->setFont(font);
        label_24->setStyleSheet(QStringLiteral("color: rgb(248, 240, 229);"));
        lineEdit_ref2 = new QLineEdit(groupBox_3);
        lineEdit_ref2->setObjectName(QStringLiteral("lineEdit_ref2"));
        lineEdit_ref2->setGeometry(QRect(120, 110, 181, 31));
        QPalette palette17;
        palette17.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette17.setBrush(QPalette::Active, QPalette::Text, brush);
        palette17.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette17.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush42(QColor(255, 255, 255, 128));
        brush42.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette17.setBrush(QPalette::Active, QPalette::PlaceholderText, brush42);
#endif
        palette17.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette17.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette17.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush43(QColor(255, 255, 255, 128));
        brush43.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette17.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush43);
#endif
        palette17.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette17.setBrush(QPalette::Disabled, QPalette::Text, brush16);
        palette17.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette17.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush44(QColor(255, 255, 255, 128));
        brush44.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette17.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush44);
#endif
        lineEdit_ref2->setPalette(palette17);
        lineEdit_ref2->setClearButtonEnabled(true);
        pushButton_supp = new QPushButton(groupBox_3);
        pushButton_supp->setObjectName(QStringLiteral("pushButton_supp"));
        pushButton_supp->setGeometry(QRect(80, 180, 93, 28));
        QPalette palette18;
        palette18.setBrush(QPalette::Active, QPalette::Button, brush);
        palette18.setBrush(QPalette::Active, QPalette::Base, brush);
        palette18.setBrush(QPalette::Active, QPalette::Window, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette18.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette18.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette18.setBrush(QPalette::Disabled, QPalette::Window, brush);
        pushButton_supp->setPalette(palette18);
        pushButton_supp->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 260, 131, 31));
        label_9->setFont(font);
        label_9->setStyleSheet(QStringLiteral("color: rgb(248, 240, 229);"));
        lineEdit_ref3 = new QLineEdit(groupBox_3);
        lineEdit_ref3->setObjectName(QStringLiteral("lineEdit_ref3"));
        lineEdit_ref3->setGeometry(QRect(220, 260, 181, 31));
        QPalette palette19;
        palette19.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette19.setBrush(QPalette::Active, QPalette::Text, brush);
        palette19.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette19.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush45(QColor(255, 255, 255, 128));
        brush45.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette19.setBrush(QPalette::Active, QPalette::PlaceholderText, brush45);
#endif
        palette19.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette19.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette19.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette19.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush46(QColor(255, 255, 255, 128));
        brush46.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette19.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush46);
#endif
        palette19.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette19.setBrush(QPalette::Disabled, QPalette::Text, brush16);
        palette19.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette19.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush47(QColor(255, 255, 255, 128));
        brush47.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette19.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush47);
#endif
        lineEdit_ref3->setPalette(palette19);
        lineEdit_ref3->setClearButtonEnabled(true);
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 330, 131, 31));
        label_10->setFont(font);
        label_10->setStyleSheet(QStringLiteral("color: rgb(248, 240, 229);"));
        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 400, 111, 31));
        label_13->setFont(font);
        label_13->setStyleSheet(QStringLiteral("color: rgb(248, 240, 229);"));
        lineEdit_prix3 = new QLineEdit(groupBox_3);
        lineEdit_prix3->setObjectName(QStringLiteral("lineEdit_prix3"));
        lineEdit_prix3->setGeometry(QRect(220, 400, 181, 31));
        QPalette palette20;
        palette20.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette20.setBrush(QPalette::Active, QPalette::Text, brush);
        palette20.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette20.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush48(QColor(255, 255, 255, 128));
        brush48.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette20.setBrush(QPalette::Active, QPalette::PlaceholderText, brush48);
#endif
        palette20.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette20.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette20.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette20.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush49(QColor(255, 255, 255, 128));
        brush49.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette20.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush49);
#endif
        palette20.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette20.setBrush(QPalette::Disabled, QPalette::Text, brush16);
        palette20.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette20.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush50(QColor(255, 255, 255, 128));
        brush50.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette20.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush50);
#endif
        lineEdit_prix3->setPalette(palette20);
        lineEdit_prix3->setClearButtonEnabled(true);
        lineEdit_quantite3 = new QLineEdit(groupBox_3);
        lineEdit_quantite3->setObjectName(QStringLiteral("lineEdit_quantite3"));
        lineEdit_quantite3->setGeometry(QRect(220, 330, 181, 31));
        QPalette palette21;
        palette21.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette21.setBrush(QPalette::Active, QPalette::Text, brush);
        palette21.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette21.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush51(QColor(255, 255, 255, 128));
        brush51.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette21.setBrush(QPalette::Active, QPalette::PlaceholderText, brush51);
#endif
        palette21.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette21.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette21.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette21.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush52(QColor(255, 255, 255, 128));
        brush52.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette21.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush52);
#endif
        palette21.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette21.setBrush(QPalette::Disabled, QPalette::Text, brush16);
        palette21.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette21.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush53(QColor(255, 255, 255, 128));
        brush53.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette21.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush53);
#endif
        lineEdit_quantite3->setPalette(palette21);
        lineEdit_quantite3->setClearButtonEnabled(true);
        pushButton_update = new QPushButton(groupBox_3);
        pushButton_update->setObjectName(QStringLiteral("pushButton_update"));
        pushButton_update->setGeometry(QRect(160, 480, 93, 28));
        QPalette palette22;
        palette22.setBrush(QPalette::Active, QPalette::Button, brush);
        palette22.setBrush(QPalette::Active, QPalette::Base, brush);
        palette22.setBrush(QPalette::Active, QPalette::Window, brush);
        palette22.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette22.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette22.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette22.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette22.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette22.setBrush(QPalette::Disabled, QPalette::Window, brush);
        pushButton_update->setPalette(palette22);
        pushButton_update->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        pushButton_rech = new QPushButton(groupBox_3);
        pushButton_rech->setObjectName(QStringLiteral("pushButton_rech"));
        pushButton_rech->setGeometry(QRect(240, 180, 93, 28));
        QPalette palette23;
        palette23.setBrush(QPalette::Active, QPalette::Button, brush);
        palette23.setBrush(QPalette::Active, QPalette::Base, brush);
        palette23.setBrush(QPalette::Active, QPalette::Window, brush);
        palette23.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette23.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette23.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette23.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette23.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette23.setBrush(QPalette::Disabled, QPalette::Window, brush);
        pushButton_rech->setPalette(palette23);
        pushButton_rech->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 10, 421, 581));
        QPalette palette24;
        palette24.setBrush(QPalette::Active, QPalette::WindowText, brush14);
        palette24.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette24.setBrush(QPalette::Active, QPalette::Light, brush);
        palette24.setBrush(QPalette::Active, QPalette::Midlight, brush15);
        palette24.setBrush(QPalette::Active, QPalette::Dark, brush16);
        palette24.setBrush(QPalette::Active, QPalette::Mid, brush17);
        palette24.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette24.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette24.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette24.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette24.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette24.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette24.setBrush(QPalette::Active, QPalette::AlternateBase, brush15);
        palette24.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette24.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette24.setBrush(QPalette::Active, QPalette::PlaceholderText, brush12);
#endif
        palette24.setBrush(QPalette::Inactive, QPalette::WindowText, brush14);
        palette24.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette24.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette24.setBrush(QPalette::Inactive, QPalette::Midlight, brush15);
        palette24.setBrush(QPalette::Inactive, QPalette::Dark, brush16);
        palette24.setBrush(QPalette::Inactive, QPalette::Mid, brush17);
        palette24.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette24.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette24.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette24.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette24.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette24.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette24.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush15);
        palette24.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette24.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette24.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush12);
#endif
        palette24.setBrush(QPalette::Disabled, QPalette::WindowText, brush16);
        palette24.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette24.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette24.setBrush(QPalette::Disabled, QPalette::Midlight, brush15);
        palette24.setBrush(QPalette::Disabled, QPalette::Dark, brush16);
        palette24.setBrush(QPalette::Disabled, QPalette::Mid, brush17);
        palette24.setBrush(QPalette::Disabled, QPalette::Text, brush16);
        palette24.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette24.setBrush(QPalette::Disabled, QPalette::ButtonText, brush16);
        palette24.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette24.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette24.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette24.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush14);
        palette24.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette24.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette24.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush12);
#endif
        groupBox_4->setPalette(palette24);
        groupBox_4->setFont(font1);
        label_25 = new QLabel(groupBox_4);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(150, 60, 131, 31));
        label_25->setFont(font);
        label_25->setStyleSheet(QStringLiteral("color: rgb(248, 240, 229);"));
        lineEdit_refch2 = new QLineEdit(groupBox_4);
        lineEdit_refch2->setObjectName(QStringLiteral("lineEdit_refch2"));
        lineEdit_refch2->setGeometry(QRect(120, 110, 181, 31));
        QPalette palette25;
        palette25.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette25.setBrush(QPalette::Active, QPalette::Text, brush);
        palette25.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette25.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush54(QColor(255, 255, 255, 128));
        brush54.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette25.setBrush(QPalette::Active, QPalette::PlaceholderText, brush54);
#endif
        palette25.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette25.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette25.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette25.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush55(QColor(255, 255, 255, 128));
        brush55.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette25.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush55);
#endif
        palette25.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette25.setBrush(QPalette::Disabled, QPalette::Text, brush16);
        palette25.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette25.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush56(QColor(255, 255, 255, 128));
        brush56.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette25.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush56);
#endif
        lineEdit_refch2->setPalette(palette25);
        lineEdit_refch2->setClearButtonEnabled(true);
        pushButton_rech2 = new QPushButton(groupBox_4);
        pushButton_rech2->setObjectName(QStringLiteral("pushButton_rech2"));
        pushButton_rech2->setGeometry(QRect(160, 180, 93, 28));
        QPalette palette26;
        palette26.setBrush(QPalette::Active, QPalette::Button, brush);
        palette26.setBrush(QPalette::Active, QPalette::Base, brush);
        palette26.setBrush(QPalette::Active, QPalette::Window, brush);
        palette26.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette26.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette26.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette26.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette26.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette26.setBrush(QPalette::Disabled, QPalette::Window, brush);
        pushButton_rech2->setPalette(palette26);
        pushButton_rech2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        tableView2 = new QTableView(groupBox_4);
        tableView2->setObjectName(QStringLiteral("tableView2"));
        tableView2->setGeometry(QRect(10, 240, 401, 321));
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        groupBox_5 = new QGroupBox(tab_3);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 10, 421, 581));
        QPalette palette27;
        palette27.setBrush(QPalette::Active, QPalette::WindowText, brush14);
        palette27.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette27.setBrush(QPalette::Active, QPalette::Light, brush);
        palette27.setBrush(QPalette::Active, QPalette::Midlight, brush15);
        palette27.setBrush(QPalette::Active, QPalette::Dark, brush16);
        palette27.setBrush(QPalette::Active, QPalette::Mid, brush17);
        palette27.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette27.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette27.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette27.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette27.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette27.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette27.setBrush(QPalette::Active, QPalette::AlternateBase, brush15);
        palette27.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette27.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette27.setBrush(QPalette::Active, QPalette::PlaceholderText, brush12);
#endif
        palette27.setBrush(QPalette::Inactive, QPalette::WindowText, brush14);
        palette27.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette27.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette27.setBrush(QPalette::Inactive, QPalette::Midlight, brush15);
        palette27.setBrush(QPalette::Inactive, QPalette::Dark, brush16);
        palette27.setBrush(QPalette::Inactive, QPalette::Mid, brush17);
        palette27.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette27.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette27.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette27.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette27.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette27.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette27.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush15);
        palette27.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette27.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette27.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush12);
#endif
        palette27.setBrush(QPalette::Disabled, QPalette::WindowText, brush16);
        palette27.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette27.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette27.setBrush(QPalette::Disabled, QPalette::Midlight, brush15);
        palette27.setBrush(QPalette::Disabled, QPalette::Dark, brush16);
        palette27.setBrush(QPalette::Disabled, QPalette::Mid, brush17);
        palette27.setBrush(QPalette::Disabled, QPalette::Text, brush16);
        palette27.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette27.setBrush(QPalette::Disabled, QPalette::ButtonText, brush16);
        palette27.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette27.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette27.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette27.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush14);
        palette27.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette27.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette27.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush12);
#endif
        groupBox_5->setPalette(palette27);
        groupBox_5->setFont(font1);
        label_26 = new QLabel(groupBox_5);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(180, 60, 131, 31));
        label_26->setFont(font);
        label_26->setStyleSheet(QStringLiteral("color: rgb(248, 240, 229);"));
        lineEdit_cin = new QLineEdit(groupBox_5);
        lineEdit_cin->setObjectName(QStringLiteral("lineEdit_cin"));
        lineEdit_cin->setGeometry(QRect(120, 110, 181, 31));
        QPalette palette28;
        palette28.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette28.setBrush(QPalette::Active, QPalette::Text, brush);
        palette28.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette28.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush57(QColor(255, 255, 255, 128));
        brush57.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette28.setBrush(QPalette::Active, QPalette::PlaceholderText, brush57);
#endif
        palette28.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette28.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette28.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette28.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush58(QColor(255, 255, 255, 128));
        brush58.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette28.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush58);
#endif
        palette28.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette28.setBrush(QPalette::Disabled, QPalette::Text, brush16);
        palette28.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette28.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush59(QColor(255, 255, 255, 128));
        brush59.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette28.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush59);
#endif
        lineEdit_cin->setPalette(palette28);
        lineEdit_cin->setClearButtonEnabled(true);
        pushButton_rechcin = new QPushButton(groupBox_5);
        pushButton_rechcin->setObjectName(QStringLiteral("pushButton_rechcin"));
        pushButton_rechcin->setGeometry(QRect(160, 180, 93, 28));
        QPalette palette29;
        palette29.setBrush(QPalette::Active, QPalette::Button, brush);
        palette29.setBrush(QPalette::Active, QPalette::Base, brush);
        palette29.setBrush(QPalette::Active, QPalette::Window, brush);
        palette29.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette29.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette29.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette29.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette29.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette29.setBrush(QPalette::Disabled, QPalette::Window, brush);
        pushButton_rechcin->setPalette(palette29);
        pushButton_rechcin->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_27 = new QLabel(groupBox_5);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(30, 290, 361, 31));
        label_27->setFont(font);
        label_27->setStyleSheet(QStringLiteral("color: rgb(248, 240, 229);"));
        lab = new QLabel(groupBox_5);
        lab->setObjectName(QStringLiteral("lab"));
        lab->setGeometry(QRect(230, 350, 131, 31));
        lab->setFont(font);
        lab->setStyleSheet(QStringLiteral("color: rgb(248, 240, 229);"));
        tabWidget->addTab(tab_3, QString());
        pushButton_stats = new QPushButton(frame);
        pushButton_stats->setObjectName(QStringLiteral("pushButton_stats"));
        pushButton_stats->setGeometry(QRect(1420, 660, 93, 28));
        QPalette palette30;
        palette30.setBrush(QPalette::Active, QPalette::Button, brush);
        palette30.setBrush(QPalette::Active, QPalette::Base, brush);
        palette30.setBrush(QPalette::Active, QPalette::Window, brush);
        palette30.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette30.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette30.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette30.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette30.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette30.setBrush(QPalette::Disabled, QPalette::Window, brush);
        pushButton_stats->setPalette(palette30);
        pushButton_stats->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        pushButton_trie = new QPushButton(frame);
        pushButton_trie->setObjectName(QStringLiteral("pushButton_trie"));
        pushButton_trie->setGeometry(QRect(1420, 130, 93, 28));
        QPalette palette31;
        palette31.setBrush(QPalette::Active, QPalette::Button, brush);
        palette31.setBrush(QPalette::Active, QPalette::Base, brush);
        palette31.setBrush(QPalette::Active, QPalette::Window, brush);
        palette31.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette31.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette31.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette31.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette31.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette31.setBrush(QPalette::Disabled, QPalette::Window, brush);
        pushButton_trie->setPalette(palette31);
        pushButton_trie->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        pushButton_triQ = new QPushButton(frame);
        pushButton_triQ->setObjectName(QStringLiteral("pushButton_triQ"));
        pushButton_triQ->setGeometry(QRect(1420, 170, 93, 28));
        QPalette palette32;
        palette32.setBrush(QPalette::Active, QPalette::Button, brush);
        palette32.setBrush(QPalette::Active, QPalette::Base, brush);
        palette32.setBrush(QPalette::Active, QPalette::Window, brush);
        palette32.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette32.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette32.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette32.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette32.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette32.setBrush(QPalette::Disabled, QPalette::Window, brush);
        pushButton_triQ->setPalette(palette32);
        pushButton_triQ->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        pushButton_triP = new QPushButton(frame);
        pushButton_triP->setObjectName(QStringLiteral("pushButton_triP"));
        pushButton_triP->setGeometry(QRect(1420, 210, 93, 28));
        QPalette palette33;
        palette33.setBrush(QPalette::Active, QPalette::Button, brush);
        palette33.setBrush(QPalette::Active, QPalette::Base, brush);
        palette33.setBrush(QPalette::Active, QPalette::Window, brush);
        palette33.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette33.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette33.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette33.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette33.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette33.setBrush(QPalette::Disabled, QPalette::Window, brush);
        pushButton_triP->setPalette(palette33);
        pushButton_triP->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1576, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Tri\303\251 par:", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "OUTILS", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "*REMISE:", Q_NULLPTR));
        lineEdit_refR->setText(QString());
        label_15->setText(QApplication::translate("MainWindow", "REMISE(%):", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "ESTIMATION FINALE:", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "R\303\251f\303\251rence:", Q_NULLPTR));
        lineEdit_remise->setText(QString());
        label_19->setText(QApplication::translate("MainWindow", "R\303\251f\303\251rence:", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "Chercher", Q_NULLPTR));
        pushButton_remise->setText(QApplication::translate("MainWindow", "Appliquer", Q_NULLPTR));
        lineEdit_refE->setText(QString());
        pushButton_cal->setText(QApplication::translate("MainWindow", "Calculer", Q_NULLPTR));
        pushButtonPDF->setText(QApplication::translate("MainWindow", "PDF", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Cat\303\251gorie :", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "NOM :", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Quantit\303\251:", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Prix :", Q_NULLPTR));
        lineEdit_ref->setText(QString());
        lineEdit_quantite->setText(QString());
        lineEdit_fournisseur->setText(QString());
        lineEdit_prix->setText(QString());
        pushButton_ajouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "R\303\251f\303\251rence:", Q_NULLPTR));
        lineEdit_nom->setText(QString());

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "Nourriture", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MainWindow", "Electronique", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("MainWindow", "Electro-menager", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("MainWindow", "Vetements", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("MainWindow", "Accessoires", Q_NULLPTR));
        listWidget->setSortingEnabled(__sortingEnabled);

        label_12->setText(QApplication::translate("MainWindow", "Fournisseur:", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabAjout), QApplication::translate("MainWindow", "Ajout", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Supprimer/Modifier", Q_NULLPTR));
        label_24->setText(QApplication::translate("MainWindow", "R\303\251f\303\251rence:", Q_NULLPTR));
        lineEdit_ref2->setText(QString());
        pushButton_supp->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "R\303\251f\303\251rence:", Q_NULLPTR));
        lineEdit_ref3->setText(QString());
        label_10->setText(QApplication::translate("MainWindow", "Quantit\303\251:", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "Prix :", Q_NULLPTR));
        lineEdit_prix3->setText(QString());
        lineEdit_quantite3->setText(QString());
        pushButton_update->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        pushButton_rech->setText(QApplication::translate("MainWindow", "Verifier", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Rechercher", Q_NULLPTR));
        label_25->setText(QApplication::translate("MainWindow", "R\303\251f\303\251rence:", Q_NULLPTR));
        lineEdit_refch2->setText(QString());
        pushButton_rech2->setText(QApplication::translate("MainWindow", "chercher", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Rechercher", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "COMMANDE", Q_NULLPTR));
        label_26->setText(QApplication::translate("MainWindow", "CIN:", Q_NULLPTR));
        lineEdit_cin->setText(QString());
        pushButton_rechcin->setText(QApplication::translate("MainWindow", "LOCK", Q_NULLPTR));
        label_27->setText(QApplication::translate("MainWindow", "Nombre de tentatives restantes :", Q_NULLPTR));
        lab->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Page", Q_NULLPTR));
        pushButton_stats->setText(QApplication::translate("MainWindow", "stat", Q_NULLPTR));
        pushButton_trie->setText(QApplication::translate("MainWindow", "Alphabet", Q_NULLPTR));
        pushButton_triQ->setText(QApplication::translate("MainWindow", "Quantite", Q_NULLPTR));
        pushButton_triP->setText(QApplication::translate("MainWindow", "Prix", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
