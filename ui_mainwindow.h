/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QPushButton *quitButton;
    QPlainTextEdit *keyt2TextEdit;
    QLabel *label_4;
    QPushButton *clearButton;
    QLabel *label_3;
    QPlainTextEdit *keyt1TextEdit;
    QPlainTextEdit *outputTextEdit;
    QPushButton *execButton;
    QPlainTextEdit *inputTextEdit;
    QComboBox *methodSelectionComboBox;
    QComboBox *algorithmSelectionComboBox;
    QComboBox *typeSelectionComboBox;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(972, 754);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 0, 3, 1, 1);

        quitButton = new QPushButton(centralWidget);
        quitButton->setObjectName(QStringLiteral("quitButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(quitButton->sizePolicy().hasHeightForWidth());
        quitButton->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(quitButton, 12, 2, 1, 1);

        keyt2TextEdit = new QPlainTextEdit(centralWidget);
        keyt2TextEdit->setObjectName(QStringLiteral("keyt2TextEdit"));

        gridLayout->addWidget(keyt2TextEdit, 11, 1, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 10, 1, 1, 1);

        clearButton = new QPushButton(centralWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        sizePolicy2.setHeightForWidth(clearButton->sizePolicy().hasHeightForWidth());
        clearButton->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(clearButton, 10, 2, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 10, 0, 1, 1);

        keyt1TextEdit = new QPlainTextEdit(centralWidget);
        keyt1TextEdit->setObjectName(QStringLiteral("keyt1TextEdit"));
        sizePolicy.setHeightForWidth(keyt1TextEdit->sizePolicy().hasHeightForWidth());
        keyt1TextEdit->setSizePolicy(sizePolicy);

        gridLayout->addWidget(keyt1TextEdit, 11, 0, 1, 1);

        outputTextEdit = new QPlainTextEdit(centralWidget);
        outputTextEdit->setObjectName(QStringLiteral("outputTextEdit"));

        gridLayout->addWidget(outputTextEdit, 1, 3, 11, 1);

        execButton = new QPushButton(centralWidget);
        execButton->setObjectName(QStringLiteral("execButton"));
        sizePolicy2.setHeightForWidth(execButton->sizePolicy().hasHeightForWidth());
        execButton->setSizePolicy(sizePolicy2);
        execButton->setAutoDefault(false);
        execButton->setFlat(false);

        gridLayout->addWidget(execButton, 7, 2, 1, 1);

        inputTextEdit = new QPlainTextEdit(centralWidget);
        inputTextEdit->setObjectName(QStringLiteral("inputTextEdit"));
        sizePolicy.setHeightForWidth(inputTextEdit->sizePolicy().hasHeightForWidth());
        inputTextEdit->setSizePolicy(sizePolicy);

        gridLayout->addWidget(inputTextEdit, 1, 0, 5, 2);

        methodSelectionComboBox = new QComboBox(centralWidget);
        methodSelectionComboBox->setObjectName(QStringLiteral("methodSelectionComboBox"));
        sizePolicy2.setHeightForWidth(methodSelectionComboBox->sizePolicy().hasHeightForWidth());
        methodSelectionComboBox->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(methodSelectionComboBox, 4, 2, 1, 1);

        algorithmSelectionComboBox = new QComboBox(centralWidget);
        algorithmSelectionComboBox->setObjectName(QStringLiteral("algorithmSelectionComboBox"));
        sizePolicy2.setHeightForWidth(algorithmSelectionComboBox->sizePolicy().hasHeightForWidth());
        algorithmSelectionComboBox->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(algorithmSelectionComboBox, 3, 2, 1, 1);

        typeSelectionComboBox = new QComboBox(centralWidget);
        typeSelectionComboBox->setObjectName(QStringLiteral("typeSelectionComboBox"));
        sizePolicy2.setHeightForWidth(typeSelectionComboBox->sizePolicy().hasHeightForWidth());
        typeSelectionComboBox->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(typeSelectionComboBox, 2, 2, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 972, 23));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        execButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "CryptoppGUIWrapper", nullptr));
        label->setText(QApplication::translate("MainWindow", "\350\276\223\345\205\245", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\350\276\223\345\207\272", nullptr));
        quitButton->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\345\257\206\351\222\245\344\272\214", nullptr));
        clearButton->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\345\257\206\351\222\245\344\270\200", nullptr));
        execButton->setText(QApplication::translate("MainWindow", "\346\211\247\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
