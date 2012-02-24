/********************************************************************************
** Form generated from reading UI file 'Graph.ui'
**
** Created: Thu 23. Feb 19:50:20 2012
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPH_H
#define UI_GRAPH_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphDialog
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *graphLabel;

    void setupUi(QWidget *GraphDialog)
    {
        if (GraphDialog->objectName().isEmpty())
            GraphDialog->setObjectName(QString::fromUtf8("GraphDialog"));
        GraphDialog->resize(400, 300);
        gridLayout_2 = new QGridLayout(GraphDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        graphLabel = new QLabel(GraphDialog);
        graphLabel->setObjectName(QString::fromUtf8("graphLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphLabel->sizePolicy().hasHeightForWidth());
        graphLabel->setSizePolicy(sizePolicy);

        gridLayout->addWidget(graphLabel, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(GraphDialog);

        QMetaObject::connectSlotsByName(GraphDialog);
    } // setupUi

    void retranslateUi(QWidget *GraphDialog)
    {
        GraphDialog->setWindowTitle(QApplication::translate("GraphDialog", "GraphDialog", 0, QApplication::UnicodeUTF8));
        graphLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GraphDialog: public Ui_GraphDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPH_H
