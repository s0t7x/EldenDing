/********************************************************************************
** Form generated from reading UI file 'EldenDing.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELDENDING_H
#define UI_ELDENDING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EldenDingClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QTableView *tvItems;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *leSearch;
    QLabel *label;
    QComboBox *cbType;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLineEdit *leItemIdDec;
    QLabel *label_5;
    QSpinBox *sbQuantity;
    QLabel *label_4;
    QLineEdit *leItemIdHex;
    QPushButton *pbSpawn;

    void setupUi(QMainWindow *EldenDingClass)
    {
        if (EldenDingClass->objectName().isEmpty())
            EldenDingClass->setObjectName(QString::fromUtf8("EldenDingClass"));
        EldenDingClass->resize(600, 386);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EldenDingClass->sizePolicy().hasHeightForWidth());
        EldenDingClass->setSizePolicy(sizePolicy);
        EldenDingClass->setMinimumSize(QSize(600, 300));
        centralWidget = new QWidget(EldenDingClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        centralWidget->setMinimumSize(QSize(600, 300));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        tvItems = new QTableView(centralWidget);
        tvItems->setObjectName(QString::fromUtf8("tvItems"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tvItems->sizePolicy().hasHeightForWidth());
        tvItems->setSizePolicy(sizePolicy2);
        tvItems->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(tvItems);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        leSearch = new QLineEdit(centralWidget);
        leSearch->setObjectName(QString::fromUtf8("leSearch"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(leSearch->sizePolicy().hasHeightForWidth());
        leSearch->setSizePolicy(sizePolicy3);
        leSearch->setMinimumSize(QSize(200, 0));
        leSearch->setSizeIncrement(QSize(0, 0));

        horizontalLayout->addWidget(leSearch);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        cbType = new QComboBox(centralWidget);
        cbType->addItem(QString());
        cbType->addItem(QString());
        cbType->addItem(QString());
        cbType->addItem(QString());
        cbType->addItem(QString());
        cbType->addItem(QString());
        cbType->setObjectName(QString::fromUtf8("cbType"));
        cbType->setEditable(false);

        horizontalLayout->addWidget(cbType);

        horizontalLayout->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 70));
        groupBox->setMaximumSize(QSize(16777215, 100));
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBox->setFlat(false);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        leItemIdDec = new QLineEdit(groupBox);
        leItemIdDec->setObjectName(QString::fromUtf8("leItemIdDec"));
        leItemIdDec->setMaximumSize(QSize(200, 16777215));
        leItemIdDec->setReadOnly(true);

        gridLayout_2->addWidget(leItemIdDec, 0, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 0, 2, 1, 1);

        sbQuantity = new QSpinBox(groupBox);
        sbQuantity->setObjectName(QString::fromUtf8("sbQuantity"));
        sbQuantity->setMinimum(1);
        sbQuantity->setValue(1);

        gridLayout_2->addWidget(sbQuantity, 0, 3, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        leItemIdHex = new QLineEdit(groupBox);
        leItemIdHex->setObjectName(QString::fromUtf8("leItemIdHex"));
        leItemIdHex->setMaximumSize(QSize(200, 16777215));
        leItemIdHex->setReadOnly(true);

        gridLayout_2->addWidget(leItemIdHex, 1, 1, 1, 1);

        pbSpawn = new QPushButton(groupBox);
        pbSpawn->setObjectName(QString::fromUtf8("pbSpawn"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pbSpawn->sizePolicy().hasHeightForWidth());
        pbSpawn->setSizePolicy(sizePolicy4);
        pbSpawn->setFlat(false);

        gridLayout_2->addWidget(pbSpawn, 1, 2, 1, 2);


        verticalLayout->addWidget(groupBox);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(2, 1);

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        EldenDingClass->setCentralWidget(centralWidget);

        retranslateUi(EldenDingClass);

        pbSpawn->setDefault(true);


        QMetaObject::connectSlotsByName(EldenDingClass);
    } // setupUi

    void retranslateUi(QMainWindow *EldenDingClass)
    {
        EldenDingClass->setWindowTitle(QCoreApplication::translate("EldenDingClass", "EldenDing", nullptr));
        label_2->setText(QCoreApplication::translate("EldenDingClass", "Filter:", nullptr));
        leSearch->setPlaceholderText(QCoreApplication::translate("EldenDingClass", "Itemname", nullptr));
        label->setText(QCoreApplication::translate("EldenDingClass", "Type:", nullptr));
        cbType->setItemText(0, QString());
        cbType->setItemText(1, QCoreApplication::translate("EldenDingClass", "good", nullptr));
        cbType->setItemText(2, QCoreApplication::translate("EldenDingClass", "weapon", nullptr));
        cbType->setItemText(3, QCoreApplication::translate("EldenDingClass", "armor", nullptr));
        cbType->setItemText(4, QCoreApplication::translate("EldenDingClass", "spell", nullptr));
        cbType->setItemText(5, QCoreApplication::translate("EldenDingClass", "talisman", nullptr));

        groupBox->setTitle(QString());
        label_3->setText(QCoreApplication::translate("EldenDingClass", "Item Id (dec):", nullptr));
        leItemIdDec->setPlaceholderText(QCoreApplication::translate("EldenDingClass", "none", nullptr));
        label_5->setText(QCoreApplication::translate("EldenDingClass", "Quantity:", nullptr));
        label_4->setText(QCoreApplication::translate("EldenDingClass", "Item Id (hex):", nullptr));
        leItemIdHex->setPlaceholderText(QCoreApplication::translate("EldenDingClass", "none", nullptr));
        pbSpawn->setText(QCoreApplication::translate("EldenDingClass", "spawn", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EldenDingClass: public Ui_EldenDingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELDENDING_H
