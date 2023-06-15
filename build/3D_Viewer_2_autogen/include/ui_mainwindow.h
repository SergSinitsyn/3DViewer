/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "widget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionParallel;
    QAction *actionCentral;
    QAction *actionColor_edges;
    QAction *actionThickness;
    QAction *actionSolid;
    QAction *actionDashed;
    QAction *actionColor_vertices;
    QAction *actionSize;
    QAction *actionNone;
    QAction *actionCircle;
    QAction *actionSquare;
    QAction *actionBackground_color;
    QAction *actionOpen_OBJ_file;
    QAction *actionModel_information;
    QAction *actionSave_OBJ_to_Image;
    QAction *actionOpen_documentation;
    QAction *actionRecent_files;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    Widget *widget;
    QVBoxLayout *verticalLayout_controls;
    QLabel *label_controls;
    QVBoxLayout *verticalLayout_rotation;
    QHBoxLayout *horizontalLayout_rotationLabel;
    QFrame *line_5;
    QLabel *label_rotation;
    QFrame *line_6;
    QHBoxLayout *horizontalLayout_rotationX;
    QVBoxLayout *verticalLayout_xrot1;
    QLabel *label_x;
    QHBoxLayout *horizontalLayout_xrot2;
    QSpinBox *spinBox_x;
    QLabel *label_xDegree;
    QDial *dial_x;
    QHBoxLayout *horizontalLayout_rotationY;
    QVBoxLayout *verticalLayout_yrot1;
    QLabel *label_y;
    QHBoxLayout *horizontalLayout_yrot2;
    QSpinBox *spinBox_y;
    QLabel *label_yDegree;
    QDial *dial_y;
    QHBoxLayout *horizontalLayout_rotationZ;
    QVBoxLayout *verticalLayout_zrot1;
    QLabel *label_z;
    QHBoxLayout *horizontalLayout_zrot2;
    QSpinBox *spinBox_z;
    QLabel *label_zDegree;
    QDial *dial_z;
    QVBoxLayout *verticalLayout_movement;
    QHBoxLayout *horizontalLayout_movementLabel;
    QFrame *line;
    QLabel *label_moving;
    QFrame *line_7;
    QHBoxLayout *horizontalLayout_movementX;
    QLabel *label_x_2;
    QDoubleSpinBox *doubleSpinBox_move_x;
    QToolButton *toolButton_xNeg;
    QToolButton *toolButton_xPos;
    QHBoxLayout *horizontalLayout_movementY;
    QLabel *label_y_2;
    QDoubleSpinBox *doubleSpinBox_move_y;
    QToolButton *toolButton_yNeg;
    QToolButton *toolButton_yPos;
    QHBoxLayout *horizontalLayout_movementZ;
    QLabel *label_z_2;
    QDoubleSpinBox *doubleSpinBox_move_z;
    QToolButton *toolButton_zNeg;
    QToolButton *toolButton_zPos;
    QVBoxLayout *verticalLayout_scaling;
    QHBoxLayout *horizontalLayout_scalingLabel;
    QFrame *line_8;
    QLabel *label_scaling;
    QFrame *line_9;
    QHBoxLayout *horizontalLayout_scale;
    QHBoxLayout *horizontalLayout_scaleNumber;
    QDoubleSpinBox *doubleSpinBox_scale;
    QLabel *label_percent;
    QToolButton *toolButton_scaleL;
    QToolButton *toolButton_scaleH;
    QHBoxLayout *horizontalLayout_scale2;
    QPushButton *pushButton_scale;
    QVBoxLayout *verticalLayout_record;
    QHBoxLayout *horizontalLayout_recordLabel;
    QFrame *line_10;
    QLabel *label_record;
    QFrame *line_11;
    QPushButton *pushButton_image;
    QPushButton *pushButton_record;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QMenu *menuSettings;
    QMenu *menuType_of_projection;
    QMenu *menuEdges;
    QMenu *menuType;
    QMenu *menuVertices;
    QMenu *menuDisplay_method;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(856, 738);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMaximumSize(QSize(6400, 16777215));
        MainWindow->setSizeIncrement(QSize(0, 0));
        MainWindow->setAcceptDrops(false);
        actionParallel = new QAction(MainWindow);
        actionParallel->setObjectName(QString::fromUtf8("actionParallel"));
        actionParallel->setCheckable(true);
        actionParallel->setChecked(false);
        actionParallel->setEnabled(true);
        actionParallel->setIconVisibleInMenu(false);
        actionCentral = new QAction(MainWindow);
        actionCentral->setObjectName(QString::fromUtf8("actionCentral"));
        actionCentral->setCheckable(true);
        actionCentral->setEnabled(true);
        actionColor_edges = new QAction(MainWindow);
        actionColor_edges->setObjectName(QString::fromUtf8("actionColor_edges"));
        actionThickness = new QAction(MainWindow);
        actionThickness->setObjectName(QString::fromUtf8("actionThickness"));
        actionSolid = new QAction(MainWindow);
        actionSolid->setObjectName(QString::fromUtf8("actionSolid"));
        actionSolid->setCheckable(true);
        actionSolid->setEnabled(true);
        actionDashed = new QAction(MainWindow);
        actionDashed->setObjectName(QString::fromUtf8("actionDashed"));
        actionDashed->setCheckable(true);
        actionDashed->setEnabled(true);
        actionColor_vertices = new QAction(MainWindow);
        actionColor_vertices->setObjectName(QString::fromUtf8("actionColor_vertices"));
        actionSize = new QAction(MainWindow);
        actionSize->setObjectName(QString::fromUtf8("actionSize"));
        actionNone = new QAction(MainWindow);
        actionNone->setObjectName(QString::fromUtf8("actionNone"));
        actionNone->setCheckable(true);
        actionNone->setEnabled(true);
        actionCircle = new QAction(MainWindow);
        actionCircle->setObjectName(QString::fromUtf8("actionCircle"));
        actionCircle->setCheckable(true);
        actionCircle->setEnabled(true);
        actionSquare = new QAction(MainWindow);
        actionSquare->setObjectName(QString::fromUtf8("actionSquare"));
        actionSquare->setCheckable(true);
        actionSquare->setEnabled(true);
        actionBackground_color = new QAction(MainWindow);
        actionBackground_color->setObjectName(QString::fromUtf8("actionBackground_color"));
        actionOpen_OBJ_file = new QAction(MainWindow);
        actionOpen_OBJ_file->setObjectName(QString::fromUtf8("actionOpen_OBJ_file"));
        actionModel_information = new QAction(MainWindow);
        actionModel_information->setObjectName(QString::fromUtf8("actionModel_information"));
        actionSave_OBJ_to_Image = new QAction(MainWindow);
        actionSave_OBJ_to_Image->setObjectName(QString::fromUtf8("actionSave_OBJ_to_Image"));
        actionOpen_documentation = new QAction(MainWindow);
        actionOpen_documentation->setObjectName(QString::fromUtf8("actionOpen_documentation"));
        actionRecent_files = new QAction(MainWindow);
        actionRecent_files->setObjectName(QString::fromUtf8("actionRecent_files"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new Widget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMinimumSize(QSize(640, 480));
        widget->setMaximumSize(QSize(6400, 4800));
        widget->setSizeIncrement(QSize(0, 0));
        widget->setBaseSize(QSize(0, 0));
        QFont font;
        font.setPointSize(13);
        widget->setFont(font);
        widget->setAutoFillBackground(true);

        horizontalLayout->addWidget(widget);

        verticalLayout_controls = new QVBoxLayout();
        verticalLayout_controls->setObjectName(QString::fromUtf8("verticalLayout_controls"));
        label_controls = new QLabel(centralwidget);
        label_controls->setObjectName(QString::fromUtf8("label_controls"));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        label_controls->setFont(font1);

        verticalLayout_controls->addWidget(label_controls, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        verticalLayout_rotation = new QVBoxLayout();
        verticalLayout_rotation->setObjectName(QString::fromUtf8("verticalLayout_rotation"));
        horizontalLayout_rotationLabel = new QHBoxLayout();
        horizontalLayout_rotationLabel->setObjectName(QString::fromUtf8("horizontalLayout_rotationLabel"));
        line_5 = new QFrame(centralwidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout_rotationLabel->addWidget(line_5);

        label_rotation = new QLabel(centralwidget);
        label_rotation->setObjectName(QString::fromUtf8("label_rotation"));
        QFont font2;
        font2.setPointSize(15);
        font2.setItalic(false);
        label_rotation->setFont(font2);
        label_rotation->setCursor(QCursor(Qt::ArrowCursor));
        label_rotation->setAlignment(Qt::AlignCenter);

        horizontalLayout_rotationLabel->addWidget(label_rotation);

        line_6 = new QFrame(centralwidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        horizontalLayout_rotationLabel->addWidget(line_6);


        verticalLayout_rotation->addLayout(horizontalLayout_rotationLabel);

        horizontalLayout_rotationX = new QHBoxLayout();
        horizontalLayout_rotationX->setObjectName(QString::fromUtf8("horizontalLayout_rotationX"));
        verticalLayout_xrot1 = new QVBoxLayout();
        verticalLayout_xrot1->setObjectName(QString::fromUtf8("verticalLayout_xrot1"));
        label_x = new QLabel(centralwidget);
        label_x->setObjectName(QString::fromUtf8("label_x"));

        verticalLayout_xrot1->addWidget(label_x, 0, Qt::AlignHCenter|Qt::AlignBottom);

        horizontalLayout_xrot2 = new QHBoxLayout();
        horizontalLayout_xrot2->setObjectName(QString::fromUtf8("horizontalLayout_xrot2"));
        spinBox_x = new QSpinBox(centralwidget);
        spinBox_x->setObjectName(QString::fromUtf8("spinBox_x"));
        sizePolicy.setHeightForWidth(spinBox_x->sizePolicy().hasHeightForWidth());
        spinBox_x->setSizePolicy(sizePolicy);
        spinBox_x->setMinimumSize(QSize(50, 0));
        spinBox_x->setMaximumSize(QSize(50, 16777215));
        spinBox_x->setFocusPolicy(Qt::WheelFocus);
        spinBox_x->setLayoutDirection(Qt::LeftToRight);
        spinBox_x->setWrapping(false);
        spinBox_x->setFrame(true);
        spinBox_x->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_x->setReadOnly(false);
        spinBox_x->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox_x->setAccelerated(true);
        spinBox_x->setMaximum(359);

        horizontalLayout_xrot2->addWidget(spinBox_x);

        label_xDegree = new QLabel(centralwidget);
        label_xDegree->setObjectName(QString::fromUtf8("label_xDegree"));

        horizontalLayout_xrot2->addWidget(label_xDegree);


        verticalLayout_xrot1->addLayout(horizontalLayout_xrot2);


        horizontalLayout_rotationX->addLayout(verticalLayout_xrot1);

        dial_x = new QDial(centralwidget);
        dial_x->setObjectName(QString::fromUtf8("dial_x"));
        dial_x->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(dial_x->sizePolicy().hasHeightForWidth());
        dial_x->setSizePolicy(sizePolicy2);
        dial_x->setMinimumSize(QSize(60, 60));
        dial_x->setMaximumSize(QSize(60, 60));
        dial_x->setCursor(QCursor(Qt::PointingHandCursor));
        dial_x->setFocusPolicy(Qt::StrongFocus);
        dial_x->setMaximum(359);
        dial_x->setOrientation(Qt::Horizontal);
        dial_x->setInvertedAppearance(false);
        dial_x->setInvertedControls(false);
        dial_x->setWrapping(true);
        dial_x->setNotchesVisible(false);

        horizontalLayout_rotationX->addWidget(dial_x, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        verticalLayout_rotation->addLayout(horizontalLayout_rotationX);

        horizontalLayout_rotationY = new QHBoxLayout();
        horizontalLayout_rotationY->setObjectName(QString::fromUtf8("horizontalLayout_rotationY"));
        verticalLayout_yrot1 = new QVBoxLayout();
        verticalLayout_yrot1->setObjectName(QString::fromUtf8("verticalLayout_yrot1"));
        label_y = new QLabel(centralwidget);
        label_y->setObjectName(QString::fromUtf8("label_y"));

        verticalLayout_yrot1->addWidget(label_y, 0, Qt::AlignHCenter|Qt::AlignBottom);

        horizontalLayout_yrot2 = new QHBoxLayout();
        horizontalLayout_yrot2->setObjectName(QString::fromUtf8("horizontalLayout_yrot2"));
        spinBox_y = new QSpinBox(centralwidget);
        spinBox_y->setObjectName(QString::fromUtf8("spinBox_y"));
        sizePolicy.setHeightForWidth(spinBox_y->sizePolicy().hasHeightForWidth());
        spinBox_y->setSizePolicy(sizePolicy);
        spinBox_y->setMinimumSize(QSize(50, 0));
        spinBox_y->setMaximumSize(QSize(50, 16777215));
        spinBox_y->setWrapping(false);
        spinBox_y->setFrame(true);
        spinBox_y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_y->setReadOnly(false);
        spinBox_y->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox_y->setAccelerated(true);
        spinBox_y->setMaximum(359);

        horizontalLayout_yrot2->addWidget(spinBox_y);

        label_yDegree = new QLabel(centralwidget);
        label_yDegree->setObjectName(QString::fromUtf8("label_yDegree"));

        horizontalLayout_yrot2->addWidget(label_yDegree);


        verticalLayout_yrot1->addLayout(horizontalLayout_yrot2);


        horizontalLayout_rotationY->addLayout(verticalLayout_yrot1);

        dial_y = new QDial(centralwidget);
        dial_y->setObjectName(QString::fromUtf8("dial_y"));
        sizePolicy2.setHeightForWidth(dial_y->sizePolicy().hasHeightForWidth());
        dial_y->setSizePolicy(sizePolicy2);
        dial_y->setMinimumSize(QSize(60, 60));
        dial_y->setMaximumSize(QSize(60, 60));
        dial_y->setCursor(QCursor(Qt::PointingHandCursor));
        dial_y->setFocusPolicy(Qt::StrongFocus);
        dial_y->setMaximum(359);
        dial_y->setOrientation(Qt::Horizontal);
        dial_y->setInvertedAppearance(false);
        dial_y->setInvertedControls(false);
        dial_y->setWrapping(true);
        dial_y->setNotchesVisible(false);

        horizontalLayout_rotationY->addWidget(dial_y, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        verticalLayout_rotation->addLayout(horizontalLayout_rotationY);

        horizontalLayout_rotationZ = new QHBoxLayout();
        horizontalLayout_rotationZ->setObjectName(QString::fromUtf8("horizontalLayout_rotationZ"));
        verticalLayout_zrot1 = new QVBoxLayout();
        verticalLayout_zrot1->setObjectName(QString::fromUtf8("verticalLayout_zrot1"));
        label_z = new QLabel(centralwidget);
        label_z->setObjectName(QString::fromUtf8("label_z"));
        sizePolicy.setHeightForWidth(label_z->sizePolicy().hasHeightForWidth());
        label_z->setSizePolicy(sizePolicy);

        verticalLayout_zrot1->addWidget(label_z, 0, Qt::AlignHCenter|Qt::AlignBottom);

        horizontalLayout_zrot2 = new QHBoxLayout();
        horizontalLayout_zrot2->setObjectName(QString::fromUtf8("horizontalLayout_zrot2"));
        spinBox_z = new QSpinBox(centralwidget);
        spinBox_z->setObjectName(QString::fromUtf8("spinBox_z"));
        sizePolicy.setHeightForWidth(spinBox_z->sizePolicy().hasHeightForWidth());
        spinBox_z->setSizePolicy(sizePolicy);
        spinBox_z->setMinimumSize(QSize(50, 0));
        spinBox_z->setMaximumSize(QSize(50, 16777215));
        spinBox_z->setWrapping(false);
        spinBox_z->setFrame(true);
        spinBox_z->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_z->setReadOnly(false);
        spinBox_z->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox_z->setAccelerated(true);
        spinBox_z->setMaximum(359);

        horizontalLayout_zrot2->addWidget(spinBox_z);

        label_zDegree = new QLabel(centralwidget);
        label_zDegree->setObjectName(QString::fromUtf8("label_zDegree"));

        horizontalLayout_zrot2->addWidget(label_zDegree);


        verticalLayout_zrot1->addLayout(horizontalLayout_zrot2);


        horizontalLayout_rotationZ->addLayout(verticalLayout_zrot1);

        dial_z = new QDial(centralwidget);
        dial_z->setObjectName(QString::fromUtf8("dial_z"));
        sizePolicy2.setHeightForWidth(dial_z->sizePolicy().hasHeightForWidth());
        dial_z->setSizePolicy(sizePolicy2);
        dial_z->setMinimumSize(QSize(60, 60));
        dial_z->setMaximumSize(QSize(60, 60));
        dial_z->setCursor(QCursor(Qt::PointingHandCursor));
        dial_z->setFocusPolicy(Qt::StrongFocus);
        dial_z->setMaximum(359);
        dial_z->setOrientation(Qt::Horizontal);
        dial_z->setInvertedAppearance(false);
        dial_z->setInvertedControls(false);
        dial_z->setWrapping(true);
        dial_z->setNotchesVisible(false);

        horizontalLayout_rotationZ->addWidget(dial_z, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        verticalLayout_rotation->addLayout(horizontalLayout_rotationZ);


        verticalLayout_controls->addLayout(verticalLayout_rotation);

        verticalLayout_movement = new QVBoxLayout();
        verticalLayout_movement->setObjectName(QString::fromUtf8("verticalLayout_movement"));
        horizontalLayout_movementLabel = new QHBoxLayout();
        horizontalLayout_movementLabel->setObjectName(QString::fromUtf8("horizontalLayout_movementLabel"));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_movementLabel->addWidget(line);

        label_moving = new QLabel(centralwidget);
        label_moving->setObjectName(QString::fromUtf8("label_moving"));
        QFont font3;
        font3.setPointSize(15);
        font3.setItalic(false);
        font3.setUnderline(false);
        label_moving->setFont(font3);
        label_moving->setCursor(QCursor(Qt::ArrowCursor));
        label_moving->setAlignment(Qt::AlignCenter);

        horizontalLayout_movementLabel->addWidget(label_moving);

        line_7 = new QFrame(centralwidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        horizontalLayout_movementLabel->addWidget(line_7);


        verticalLayout_movement->addLayout(horizontalLayout_movementLabel);

        horizontalLayout_movementX = new QHBoxLayout();
        horizontalLayout_movementX->setObjectName(QString::fromUtf8("horizontalLayout_movementX"));
        label_x_2 = new QLabel(centralwidget);
        label_x_2->setObjectName(QString::fromUtf8("label_x_2"));
        label_x_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_movementX->addWidget(label_x_2);

        doubleSpinBox_move_x = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_move_x->setObjectName(QString::fromUtf8("doubleSpinBox_move_x"));
        sizePolicy.setHeightForWidth(doubleSpinBox_move_x->sizePolicy().hasHeightForWidth());
        doubleSpinBox_move_x->setSizePolicy(sizePolicy);
        doubleSpinBox_move_x->setMinimumSize(QSize(50, 0));
        doubleSpinBox_move_x->setAlignment(Qt::AlignCenter);
        doubleSpinBox_move_x->setAccelerated(true);
        doubleSpinBox_move_x->setMinimum(0.010000000000000);
        doubleSpinBox_move_x->setMaximum(1.000000000000000);
        doubleSpinBox_move_x->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        horizontalLayout_movementX->addWidget(doubleSpinBox_move_x, 0, Qt::AlignLeft);

        toolButton_xNeg = new QToolButton(centralwidget);
        toolButton_xNeg->setObjectName(QString::fromUtf8("toolButton_xNeg"));
        toolButton_xNeg->setMinimumSize(QSize(30, 30));
        toolButton_xNeg->setMaximumSize(QSize(30, 30));
        QFont font4;
        font4.setPointSize(16);
        font4.setBold(false);
        toolButton_xNeg->setFont(font4);
        toolButton_xNeg->setCursor(QCursor(Qt::PointingHandCursor));
        toolButton_xNeg->setFocusPolicy(Qt::StrongFocus);
        toolButton_xNeg->setAutoFillBackground(false);
        toolButton_xNeg->setAutoRepeat(true);
        toolButton_xNeg->setAutoRepeatInterval(50);

        horizontalLayout_movementX->addWidget(toolButton_xNeg);

        toolButton_xPos = new QToolButton(centralwidget);
        toolButton_xPos->setObjectName(QString::fromUtf8("toolButton_xPos"));
        toolButton_xPos->setMinimumSize(QSize(30, 30));
        toolButton_xPos->setMaximumSize(QSize(30, 30));
        QFont font5;
        font5.setPointSize(16);
        font5.setBold(false);
        font5.setItalic(false);
        toolButton_xPos->setFont(font5);
        toolButton_xPos->setCursor(QCursor(Qt::PointingHandCursor));
        toolButton_xPos->setFocusPolicy(Qt::StrongFocus);
        toolButton_xPos->setAutoRepeat(true);
        toolButton_xPos->setAutoRepeatInterval(50);
        toolButton_xPos->setPopupMode(QToolButton::DelayedPopup);
        toolButton_xPos->setArrowType(Qt::NoArrow);

        horizontalLayout_movementX->addWidget(toolButton_xPos);


        verticalLayout_movement->addLayout(horizontalLayout_movementX);

        horizontalLayout_movementY = new QHBoxLayout();
        horizontalLayout_movementY->setObjectName(QString::fromUtf8("horizontalLayout_movementY"));
        label_y_2 = new QLabel(centralwidget);
        label_y_2->setObjectName(QString::fromUtf8("label_y_2"));
        label_y_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_movementY->addWidget(label_y_2);

        doubleSpinBox_move_y = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_move_y->setObjectName(QString::fromUtf8("doubleSpinBox_move_y"));
        sizePolicy.setHeightForWidth(doubleSpinBox_move_y->sizePolicy().hasHeightForWidth());
        doubleSpinBox_move_y->setSizePolicy(sizePolicy);
        doubleSpinBox_move_y->setMinimumSize(QSize(50, 0));
        doubleSpinBox_move_y->setAlignment(Qt::AlignCenter);
        doubleSpinBox_move_y->setAccelerated(true);
        doubleSpinBox_move_y->setMinimum(0.010000000000000);
        doubleSpinBox_move_y->setMaximum(1.000000000000000);
        doubleSpinBox_move_y->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        horizontalLayout_movementY->addWidget(doubleSpinBox_move_y, 0, Qt::AlignLeft);

        toolButton_yNeg = new QToolButton(centralwidget);
        toolButton_yNeg->setObjectName(QString::fromUtf8("toolButton_yNeg"));
        toolButton_yNeg->setMinimumSize(QSize(30, 30));
        toolButton_yNeg->setMaximumSize(QSize(30, 30));
        QFont font6;
        font6.setPointSize(16);
        toolButton_yNeg->setFont(font6);
        toolButton_yNeg->setCursor(QCursor(Qt::PointingHandCursor));
        toolButton_yNeg->setFocusPolicy(Qt::StrongFocus);
        toolButton_yNeg->setAutoRepeat(true);
        toolButton_yNeg->setAutoRepeatInterval(50);

        horizontalLayout_movementY->addWidget(toolButton_yNeg);

        toolButton_yPos = new QToolButton(centralwidget);
        toolButton_yPos->setObjectName(QString::fromUtf8("toolButton_yPos"));
        toolButton_yPos->setMinimumSize(QSize(30, 30));
        toolButton_yPos->setMaximumSize(QSize(30, 30));
        toolButton_yPos->setFont(font6);
        toolButton_yPos->setCursor(QCursor(Qt::PointingHandCursor));
        toolButton_yPos->setFocusPolicy(Qt::StrongFocus);
        toolButton_yPos->setCheckable(false);
        toolButton_yPos->setAutoRepeat(true);
        toolButton_yPos->setAutoRepeatInterval(50);

        horizontalLayout_movementY->addWidget(toolButton_yPos);


        verticalLayout_movement->addLayout(horizontalLayout_movementY);

        horizontalLayout_movementZ = new QHBoxLayout();
        horizontalLayout_movementZ->setObjectName(QString::fromUtf8("horizontalLayout_movementZ"));
        label_z_2 = new QLabel(centralwidget);
        label_z_2->setObjectName(QString::fromUtf8("label_z_2"));
        label_z_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_movementZ->addWidget(label_z_2);

        doubleSpinBox_move_z = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_move_z->setObjectName(QString::fromUtf8("doubleSpinBox_move_z"));
        sizePolicy.setHeightForWidth(doubleSpinBox_move_z->sizePolicy().hasHeightForWidth());
        doubleSpinBox_move_z->setSizePolicy(sizePolicy);
        doubleSpinBox_move_z->setMinimumSize(QSize(50, 0));
        doubleSpinBox_move_z->setAlignment(Qt::AlignCenter);
        doubleSpinBox_move_z->setAccelerated(true);
        doubleSpinBox_move_z->setMinimum(0.010000000000000);
        doubleSpinBox_move_z->setMaximum(1.000000000000000);
        doubleSpinBox_move_z->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        horizontalLayout_movementZ->addWidget(doubleSpinBox_move_z, 0, Qt::AlignLeft);

        toolButton_zNeg = new QToolButton(centralwidget);
        toolButton_zNeg->setObjectName(QString::fromUtf8("toolButton_zNeg"));
        toolButton_zNeg->setMinimumSize(QSize(30, 30));
        toolButton_zNeg->setMaximumSize(QSize(30, 30));
        toolButton_zNeg->setFont(font6);
        toolButton_zNeg->setCursor(QCursor(Qt::PointingHandCursor));
        toolButton_zNeg->setFocusPolicy(Qt::StrongFocus);
        toolButton_zNeg->setAutoRepeat(true);
        toolButton_zNeg->setAutoRepeatInterval(50);
        toolButton_zNeg->setAutoRaise(false);

        horizontalLayout_movementZ->addWidget(toolButton_zNeg);

        toolButton_zPos = new QToolButton(centralwidget);
        toolButton_zPos->setObjectName(QString::fromUtf8("toolButton_zPos"));
        toolButton_zPos->setMinimumSize(QSize(30, 30));
        toolButton_zPos->setMaximumSize(QSize(30, 30));
        toolButton_zPos->setFont(font6);
        toolButton_zPos->setCursor(QCursor(Qt::PointingHandCursor));
        toolButton_zPos->setFocusPolicy(Qt::StrongFocus);
        toolButton_zPos->setAutoRepeat(true);
        toolButton_zPos->setAutoRepeatInterval(50);

        horizontalLayout_movementZ->addWidget(toolButton_zPos);


        verticalLayout_movement->addLayout(horizontalLayout_movementZ);


        verticalLayout_controls->addLayout(verticalLayout_movement);

        verticalLayout_scaling = new QVBoxLayout();
        verticalLayout_scaling->setObjectName(QString::fromUtf8("verticalLayout_scaling"));
        horizontalLayout_scalingLabel = new QHBoxLayout();
        horizontalLayout_scalingLabel->setObjectName(QString::fromUtf8("horizontalLayout_scalingLabel"));
        line_8 = new QFrame(centralwidget);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        horizontalLayout_scalingLabel->addWidget(line_8);

        label_scaling = new QLabel(centralwidget);
        label_scaling->setObjectName(QString::fromUtf8("label_scaling"));
        QFont font7;
        font7.setPointSize(15);
        font7.setStrikeOut(false);
        label_scaling->setFont(font7);
        label_scaling->setCursor(QCursor(Qt::ArrowCursor));
        label_scaling->setAlignment(Qt::AlignCenter);

        horizontalLayout_scalingLabel->addWidget(label_scaling);

        line_9 = new QFrame(centralwidget);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);

        horizontalLayout_scalingLabel->addWidget(line_9);


        verticalLayout_scaling->addLayout(horizontalLayout_scalingLabel);

        horizontalLayout_scale = new QHBoxLayout();
        horizontalLayout_scale->setObjectName(QString::fromUtf8("horizontalLayout_scale"));
        horizontalLayout_scaleNumber = new QHBoxLayout();
        horizontalLayout_scaleNumber->setObjectName(QString::fromUtf8("horizontalLayout_scaleNumber"));
        doubleSpinBox_scale = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_scale->setObjectName(QString::fromUtf8("doubleSpinBox_scale"));
        doubleSpinBox_scale->setEnabled(true);
        sizePolicy.setHeightForWidth(doubleSpinBox_scale->sizePolicy().hasHeightForWidth());
        doubleSpinBox_scale->setSizePolicy(sizePolicy);
        doubleSpinBox_scale->setMinimumSize(QSize(50, 0));
        doubleSpinBox_scale->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_scale->setMouseTracking(false);
        doubleSpinBox_scale->setLayoutDirection(Qt::LeftToRight);
        doubleSpinBox_scale->setFrame(true);
        doubleSpinBox_scale->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_scale->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        doubleSpinBox_scale->setAccelerated(true);
        doubleSpinBox_scale->setDecimals(3);
        doubleSpinBox_scale->setMinimum(0.001000000000000);
        doubleSpinBox_scale->setMaximum(100000.000000000000000);
        doubleSpinBox_scale->setSingleStep(1.000000000000000);
        doubleSpinBox_scale->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        doubleSpinBox_scale->setValue(100.000000000000000);

        horizontalLayout_scaleNumber->addWidget(doubleSpinBox_scale);

        label_percent = new QLabel(centralwidget);
        label_percent->setObjectName(QString::fromUtf8("label_percent"));
        sizePolicy2.setHeightForWidth(label_percent->sizePolicy().hasHeightForWidth());
        label_percent->setSizePolicy(sizePolicy2);

        horizontalLayout_scaleNumber->addWidget(label_percent);

        toolButton_scaleL = new QToolButton(centralwidget);
        toolButton_scaleL->setObjectName(QString::fromUtf8("toolButton_scaleL"));
        toolButton_scaleL->setMinimumSize(QSize(30, 30));
        toolButton_scaleL->setMaximumSize(QSize(30, 30));
        toolButton_scaleL->setFont(font6);
        toolButton_scaleL->setCursor(QCursor(Qt::PointingHandCursor));
        toolButton_scaleL->setFocusPolicy(Qt::StrongFocus);
        toolButton_scaleL->setLayoutDirection(Qt::LeftToRight);
        toolButton_scaleL->setAutoFillBackground(false);
        toolButton_scaleL->setAutoRepeat(true);
        toolButton_scaleL->setAutoRepeatInterval(50);

        horizontalLayout_scaleNumber->addWidget(toolButton_scaleL, 0, Qt::AlignRight);

        toolButton_scaleH = new QToolButton(centralwidget);
        toolButton_scaleH->setObjectName(QString::fromUtf8("toolButton_scaleH"));
        toolButton_scaleH->setMinimumSize(QSize(30, 30));
        toolButton_scaleH->setMaximumSize(QSize(30, 30));
        toolButton_scaleH->setFont(font5);
        toolButton_scaleH->setCursor(QCursor(Qt::PointingHandCursor));
        toolButton_scaleH->setFocusPolicy(Qt::StrongFocus);
        toolButton_scaleH->setLayoutDirection(Qt::LeftToRight);
        toolButton_scaleH->setAutoRepeat(true);
        toolButton_scaleH->setAutoRepeatInterval(50);
        toolButton_scaleH->setPopupMode(QToolButton::DelayedPopup);
        toolButton_scaleH->setArrowType(Qt::NoArrow);

        horizontalLayout_scaleNumber->addWidget(toolButton_scaleH, 0, Qt::AlignRight);


        horizontalLayout_scale->addLayout(horizontalLayout_scaleNumber);


        verticalLayout_scaling->addLayout(horizontalLayout_scale);

        horizontalLayout_scale2 = new QHBoxLayout();
        horizontalLayout_scale2->setObjectName(QString::fromUtf8("horizontalLayout_scale2"));
        pushButton_scale = new QPushButton(centralwidget);
        pushButton_scale->setObjectName(QString::fromUtf8("pushButton_scale"));
        pushButton_scale->setEnabled(true);
        pushButton_scale->setMaximumSize(QSize(60, 16777215));
        QFont font8;
        font8.setStrikeOut(false);
        pushButton_scale->setFont(font8);
        pushButton_scale->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_scale->setFocusPolicy(Qt::StrongFocus);
        pushButton_scale->setAcceptDrops(false);
        pushButton_scale->setCheckable(false);
        pushButton_scale->setAutoRepeat(false);
        pushButton_scale->setAutoDefault(false);
        pushButton_scale->setFlat(false);

        horizontalLayout_scale2->addWidget(pushButton_scale, 0, Qt::AlignLeft);


        verticalLayout_scaling->addLayout(horizontalLayout_scale2);


        verticalLayout_controls->addLayout(verticalLayout_scaling);

        verticalLayout_record = new QVBoxLayout();
        verticalLayout_record->setObjectName(QString::fromUtf8("verticalLayout_record"));
        horizontalLayout_recordLabel = new QHBoxLayout();
        horizontalLayout_recordLabel->setObjectName(QString::fromUtf8("horizontalLayout_recordLabel"));
        line_10 = new QFrame(centralwidget);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);

        horizontalLayout_recordLabel->addWidget(line_10);

        label_record = new QLabel(centralwidget);
        label_record->setObjectName(QString::fromUtf8("label_record"));
        QFont font9;
        font9.setPointSize(15);
        label_record->setFont(font9);
        label_record->setCursor(QCursor(Qt::ArrowCursor));
        label_record->setAlignment(Qt::AlignCenter);

        horizontalLayout_recordLabel->addWidget(label_record);

        line_11 = new QFrame(centralwidget);
        line_11->setObjectName(QString::fromUtf8("line_11"));
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);

        horizontalLayout_recordLabel->addWidget(line_11);


        verticalLayout_record->addLayout(horizontalLayout_recordLabel);

        pushButton_image = new QPushButton(centralwidget);
        pushButton_image->setObjectName(QString::fromUtf8("pushButton_image"));
        pushButton_image->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_image->setFocusPolicy(Qt::StrongFocus);

        verticalLayout_record->addWidget(pushButton_image);

        pushButton_record = new QPushButton(centralwidget);
        pushButton_record->setObjectName(QString::fromUtf8("pushButton_record"));
        pushButton_record->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_record->setFocusPolicy(Qt::StrongFocus);

        verticalLayout_record->addWidget(pushButton_record);


        verticalLayout_controls->addLayout(verticalLayout_record);

        verticalSpacer = new QSpacerItem(179, 164, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_controls->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_controls);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 856, 24));
        menubar->setCursor(QCursor(Qt::ArrowCursor));
        menubar->setFocusPolicy(Qt::StrongFocus);
        menubar->setDefaultUp(false);
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        menuSettings->setFocusPolicy(Qt::StrongFocus);
        menuSettings->setTearOffEnabled(false);
        menuSettings->setSeparatorsCollapsible(false);
        menuSettings->setToolTipsVisible(false);
        menuType_of_projection = new QMenu(menuSettings);
        menuType_of_projection->setObjectName(QString::fromUtf8("menuType_of_projection"));
        menuType_of_projection->setTearOffEnabled(false);
        menuType_of_projection->setSeparatorsCollapsible(false);
        menuType_of_projection->setToolTipsVisible(false);
        menuEdges = new QMenu(menuSettings);
        menuEdges->setObjectName(QString::fromUtf8("menuEdges"));
        menuType = new QMenu(menuEdges);
        menuType->setObjectName(QString::fromUtf8("menuType"));
        menuVertices = new QMenu(menuSettings);
        menuVertices->setObjectName(QString::fromUtf8("menuVertices"));
        menuDisplay_method = new QMenu(menuVertices);
        menuDisplay_method->setObjectName(QString::fromUtf8("menuDisplay_method"));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuFile->setFocusPolicy(Qt::StrongFocus);
        menuFile->setSeparatorsCollapsible(false);
        menuFile->setToolTipsVisible(false);
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(spinBox_x, dial_x);
        QWidget::setTabOrder(dial_x, spinBox_y);
        QWidget::setTabOrder(spinBox_y, dial_y);
        QWidget::setTabOrder(dial_y, spinBox_z);
        QWidget::setTabOrder(spinBox_z, dial_z);
        QWidget::setTabOrder(dial_z, doubleSpinBox_move_x);
        QWidget::setTabOrder(doubleSpinBox_move_x, toolButton_xNeg);
        QWidget::setTabOrder(toolButton_xNeg, toolButton_xPos);
        QWidget::setTabOrder(toolButton_xPos, doubleSpinBox_move_y);
        QWidget::setTabOrder(doubleSpinBox_move_y, toolButton_yNeg);
        QWidget::setTabOrder(toolButton_yNeg, toolButton_yPos);
        QWidget::setTabOrder(toolButton_yPos, doubleSpinBox_move_z);
        QWidget::setTabOrder(doubleSpinBox_move_z, toolButton_zNeg);
        QWidget::setTabOrder(toolButton_zNeg, toolButton_zPos);
        QWidget::setTabOrder(toolButton_zPos, doubleSpinBox_scale);
        QWidget::setTabOrder(doubleSpinBox_scale, pushButton_image);
        QWidget::setTabOrder(pushButton_image, pushButton_record);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuSettings->menuAction());
        menuSettings->addAction(menuType_of_projection->menuAction());
        menuSettings->addAction(menuEdges->menuAction());
        menuSettings->addAction(menuVertices->menuAction());
        menuSettings->addAction(actionBackground_color);
        menuType_of_projection->addAction(actionParallel);
        menuType_of_projection->addAction(actionCentral);
        menuEdges->addAction(menuType->menuAction());
        menuEdges->addAction(actionColor_edges);
        menuEdges->addAction(actionThickness);
        menuType->addAction(actionSolid);
        menuType->addAction(actionDashed);
        menuVertices->addAction(menuDisplay_method->menuAction());
        menuVertices->addAction(actionColor_vertices);
        menuVertices->addAction(actionSize);
        menuDisplay_method->addAction(actionNone);
        menuDisplay_method->addAction(actionCircle);
        menuDisplay_method->addAction(actionSquare);
        menuFile->addAction(actionOpen_OBJ_file);
        menuFile->addAction(actionRecent_files);
        menuFile->addAction(actionModel_information);
        menuFile->addAction(actionSave_OBJ_to_Image);
        menuFile->addAction(actionOpen_documentation);

        retranslateUi(MainWindow);
        QObject::connect(MainWindow, SIGNAL(settingsChanged(widgetSettings*)), widget, SLOT(getSettings(widgetSettings*)));

        pushButton_scale->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "3D Viewer v2.0 - Old Perrers Team", nullptr));
        actionParallel->setText(QCoreApplication::translate("MainWindow", "Parallel", nullptr));
        actionCentral->setText(QCoreApplication::translate("MainWindow", "Central", nullptr));
        actionColor_edges->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        actionThickness->setText(QCoreApplication::translate("MainWindow", "Thickness", nullptr));
        actionSolid->setText(QCoreApplication::translate("MainWindow", "Solid", nullptr));
        actionDashed->setText(QCoreApplication::translate("MainWindow", "Dashed", nullptr));
        actionColor_vertices->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        actionSize->setText(QCoreApplication::translate("MainWindow", "Size", nullptr));
        actionNone->setText(QCoreApplication::translate("MainWindow", "None", nullptr));
        actionCircle->setText(QCoreApplication::translate("MainWindow", "Circle", nullptr));
        actionSquare->setText(QCoreApplication::translate("MainWindow", "Square", nullptr));
        actionBackground_color->setText(QCoreApplication::translate("MainWindow", "Background color", nullptr));
        actionOpen_OBJ_file->setText(QCoreApplication::translate("MainWindow", "Open OBJ file", nullptr));
        actionModel_information->setText(QCoreApplication::translate("MainWindow", "Model information", nullptr));
        actionSave_OBJ_to_Image->setText(QCoreApplication::translate("MainWindow", "Save OBJ to Image", nullptr));
        actionOpen_documentation->setText(QCoreApplication::translate("MainWindow", "Open documentation", nullptr));
        actionRecent_files->setText(QCoreApplication::translate("MainWindow", "Recent files", nullptr));
        label_controls->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Controls</p></body></html>", nullptr));
        label_rotation->setText(QCoreApplication::translate("MainWindow", "Rotation", nullptr));
        label_x->setText(QCoreApplication::translate("MainWindow", "X axis", nullptr));
        label_xDegree->setText(QCoreApplication::translate("MainWindow", "degree", nullptr));
#if QT_CONFIG(tooltip)
        dial_x->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_y->setText(QCoreApplication::translate("MainWindow", "Y axis", nullptr));
        label_yDegree->setText(QCoreApplication::translate("MainWindow", "degree", nullptr));
#if QT_CONFIG(tooltip)
        dial_y->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_z->setText(QCoreApplication::translate("MainWindow", "Z axis", nullptr));
        label_zDegree->setText(QCoreApplication::translate("MainWindow", "degree", nullptr));
#if QT_CONFIG(tooltip)
        dial_z->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_moving->setText(QCoreApplication::translate("MainWindow", "Movement", nullptr));
        label_x_2->setText(QCoreApplication::translate("MainWindow", "X axis", nullptr));
        toolButton_xNeg->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        toolButton_xPos->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        label_y_2->setText(QCoreApplication::translate("MainWindow", "Y axis", nullptr));
        toolButton_yNeg->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        toolButton_yPos->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        label_z_2->setText(QCoreApplication::translate("MainWindow", "Z axis", nullptr));
        toolButton_zNeg->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        toolButton_zPos->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        label_scaling->setText(QCoreApplication::translate("MainWindow", "Scaling", nullptr));
        label_percent->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        toolButton_scaleL->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        toolButton_scaleH->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_scale->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        label_record->setText(QCoreApplication::translate("MainWindow", "Record", nullptr));
        pushButton_image->setText(QCoreApplication::translate("MainWindow", "Image", nullptr));
        pushButton_record->setText(QCoreApplication::translate("MainWindow", "Screencast", nullptr));
        menuSettings->setTitle(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        menuType_of_projection->setTitle(QCoreApplication::translate("MainWindow", "Projection", nullptr));
        menuEdges->setTitle(QCoreApplication::translate("MainWindow", "Edges", nullptr));
        menuType->setTitle(QCoreApplication::translate("MainWindow", "Type", nullptr));
        menuVertices->setTitle(QCoreApplication::translate("MainWindow", "Vertices", nullptr));
        menuDisplay_method->setTitle(QCoreApplication::translate("MainWindow", "Display method", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
