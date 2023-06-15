/********************************************************************************
** Form generated from reading UI file 'info.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFO_H
#define UI_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Info
{
public:
    QGridLayout *gridLayout;
    QLabel *label_filename_2;
    QLabel *label_filename;
    QLabel *label_numberOfVertices_2;
    QLabel *label_numberOfVertices;
    QLabel *label_numberOfEdges_2;
    QLabel *label_numberOfEdges;
    QLabel *label_numberOfFaces_2;
    QLabel *label_numberOfFaces;

    void setupUi(QDialog *Info)
    {
        if (Info->objectName().isEmpty())
            Info->setObjectName(QString::fromUtf8("Info"));
        Info->resize(213, 118);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Info->sizePolicy().hasHeightForWidth());
        Info->setSizePolicy(sizePolicy);
        Info->setMinimumSize(QSize(0, 0));
        gridLayout = new QGridLayout(Info);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_filename_2 = new QLabel(Info);
        label_filename_2->setObjectName(QString::fromUtf8("label_filename_2"));
        QFont font;
        font.setBold(true);
        label_filename_2->setFont(font);

        gridLayout->addWidget(label_filename_2, 0, 0, 1, 1);

        label_filename = new QLabel(Info);
        label_filename->setObjectName(QString::fromUtf8("label_filename"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_filename->sizePolicy().hasHeightForWidth());
        label_filename->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setBold(true);
        font1.setUnderline(false);
        label_filename->setFont(font1);

        gridLayout->addWidget(label_filename, 0, 1, 1, 1);

        label_numberOfVertices_2 = new QLabel(Info);
        label_numberOfVertices_2->setObjectName(QString::fromUtf8("label_numberOfVertices_2"));

        gridLayout->addWidget(label_numberOfVertices_2, 1, 0, 1, 1);

        label_numberOfVertices = new QLabel(Info);
        label_numberOfVertices->setObjectName(QString::fromUtf8("label_numberOfVertices"));
        sizePolicy1.setHeightForWidth(label_numberOfVertices->sizePolicy().hasHeightForWidth());
        label_numberOfVertices->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_numberOfVertices, 1, 1, 1, 1);

        label_numberOfEdges_2 = new QLabel(Info);
        label_numberOfEdges_2->setObjectName(QString::fromUtf8("label_numberOfEdges_2"));

        gridLayout->addWidget(label_numberOfEdges_2, 2, 0, 1, 1);

        label_numberOfEdges = new QLabel(Info);
        label_numberOfEdges->setObjectName(QString::fromUtf8("label_numberOfEdges"));
        sizePolicy1.setHeightForWidth(label_numberOfEdges->sizePolicy().hasHeightForWidth());
        label_numberOfEdges->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_numberOfEdges, 2, 1, 1, 1);

        label_numberOfFaces_2 = new QLabel(Info);
        label_numberOfFaces_2->setObjectName(QString::fromUtf8("label_numberOfFaces_2"));

        gridLayout->addWidget(label_numberOfFaces_2, 3, 0, 1, 1);

        label_numberOfFaces = new QLabel(Info);
        label_numberOfFaces->setObjectName(QString::fromUtf8("label_numberOfFaces"));
        sizePolicy1.setHeightForWidth(label_numberOfFaces->sizePolicy().hasHeightForWidth());
        label_numberOfFaces->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_numberOfFaces, 3, 1, 1, 1);


        retranslateUi(Info);

        QMetaObject::connectSlotsByName(Info);
    } // setupUi

    void retranslateUi(QDialog *Info)
    {
        Info->setWindowTitle(QCoreApplication::translate("Info", " Model Information", nullptr));
        label_filename_2->setText(QCoreApplication::translate("Info", "Filename:", nullptr));
        label_filename->setText(QCoreApplication::translate("Info", "TextLabel", nullptr));
        label_numberOfVertices_2->setText(QCoreApplication::translate("Info", "Number of vertices:", nullptr));
        label_numberOfVertices->setText(QCoreApplication::translate("Info", "TextLabel", nullptr));
        label_numberOfEdges_2->setText(QCoreApplication::translate("Info", "Number of edges:", nullptr));
        label_numberOfEdges->setText(QCoreApplication::translate("Info", "TextLabel", nullptr));
        label_numberOfFaces_2->setText(QCoreApplication::translate("Info", "Number of faces:", nullptr));
        label_numberOfFaces->setText(QCoreApplication::translate("Info", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Info: public Ui_Info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFO_H
