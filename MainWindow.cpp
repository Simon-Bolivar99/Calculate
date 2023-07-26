#include "MainWindow.h"

#include <QPushButton>
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    createGui();
}

MainWindow::~MainWindow()
{
}

void MainWindow::createGui()
{
    m_btn_1 = new QPushButton();
        m_btn_1->setText("1");


    auto m_layout = new QGridLayout();
        m_layout->addWidget(m_btn_1, 1, 1, 1, 1);

    setLayout(m_layout);
}

