#include "MainWindow.h"

#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    createGui();
    connectSignals();
}

MainWindow::~MainWindow()
{
}

void MainWindow::createGui()
{
    m_line_res    = new QLineEdit();
        m_line_res->setReadOnly(true);
        m_line_res->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_btn_0       = new QPushButton("0");
        m_btn_0->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_btn_1       = new QPushButton("1");
        m_btn_1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_btn_2       = new QPushButton("2");
        m_btn_2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_btn_3       = new QPushButton("3");
        m_btn_3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_btn_4       = new QPushButton("4");
        m_btn_4->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_btn_5       = new QPushButton("5");
        m_btn_5->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_btn_6       = new QPushButton("6");
        m_btn_6->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_btn_7       = new QPushButton("7");
        m_btn_7->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_btn_8       = new QPushButton("8");
        m_btn_8->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_btn_9       = new QPushButton("9");
        m_btn_9->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_btn_plus    = new QPushButton("+");
        m_btn_plus->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_btn_minus   = new QPushButton("-");
        m_btn_minus->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_btn_equal   = new QPushButton("=");
        m_btn_equal->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_btn_backspace   = new QPushButton("BackSpace");
        m_btn_backspace->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    auto m_layout = new QGridLayout();
        m_layout->setMargin(5);
        m_layout->setSpacing(2);
        m_layout->addWidget(m_line_res,       0, 0, 1, 4);
        m_layout->addWidget(m_btn_1,          1, 0, 1, 1);
        m_layout->addWidget(m_btn_2,          1, 1, 1, 1);
        m_layout->addWidget(m_btn_3,          1, 2, 1, 1);
        m_layout->addWidget(m_btn_plus,       1, 3, 1, 1);
        m_layout->addWidget(m_btn_4,          2, 0, 1, 1);
        m_layout->addWidget(m_btn_5,          2, 1, 1, 1);
        m_layout->addWidget(m_btn_6,          2, 2, 1, 1);
        m_layout->addWidget(m_btn_minus,      2, 3, 1, 1);
        m_layout->addWidget(m_btn_7,          3, 0, 1, 1);
        m_layout->addWidget(m_btn_8,          3, 1, 1, 1);
        m_layout->addWidget(m_btn_9,          3, 2, 1, 1);
        m_layout->addWidget(m_btn_equal,      3, 3, 1, 1);
        m_layout->addWidget(m_btn_backspace,  4, 3, 1, 1);
        m_layout->addWidget(m_btn_0,          4, 0, 1, 3);


        setLayout(m_layout);
}

void MainWindow::buttonHanderNums()
{
    auto btn = qobject_cast<QPushButton*>(sender());
    num_str  += btn->text().toUtf8().constData();
    line_str += btn->text().toUtf8().constData();
    m_line_res->clear();
    m_line_res->setText(QString::fromStdString(line_str));
}

void MainWindow::buttonHandlerOperation()
{
    auto btn = qobject_cast<QPushButton*>(sender());
    if (btn->text() == "+" && num_str != "0")
    {
        res += std::stoi(num_str);
        line_str += " + ";
        num_str = "0";
    }

     if (btn->text() == "-" && num_str != "0")
    {
        res -= std::stoi(num_str);
        line_str += " - ";
        num_str = "-0";

    }
     m_line_res->clear();
     m_line_res->setText(QString::fromStdString(line_str));
}

void MainWindow::buttonHandlerEqual()
{
    if(res != 0 && num_str != "0")
    {
        //auto btn = qobject_cast<QPushButton*>(sender());
        m_line_res->clear();
        line_str[line_str.length() - 1] == '+'?  line_str += " = " + std::to_string(res += std::stoi(num_str)) : line_str += " = " + std::to_string(res -= std::stoi(num_str));
        m_line_res->setText(QString::fromStdString(line_str));
        reset();
    }
}

void MainWindow::buttonHandlerBackSpace()
{
    if(!(line_str.empty())){
        if(line_str[line_str.length()] == ' ')
            line_str.pop_back();
        m_line_res->clear();
        line_str.pop_back();
        m_line_res->setText(QString::fromStdString(line_str));
}
}

void MainWindow::connectSignals()
{
    connect(m_btn_0,          &QPushButton::clicked, this,      &MainWindow::buttonHanderNums);
    connect(m_btn_1,          &QPushButton::clicked, this,      &MainWindow::buttonHanderNums);
    connect(m_btn_2,          &QPushButton::clicked, this,      &MainWindow::buttonHanderNums);
    connect(m_btn_3,          &QPushButton::clicked, this,      &MainWindow::buttonHanderNums);
    connect(m_btn_4,          &QPushButton::clicked, this,      &MainWindow::buttonHanderNums);
    connect(m_btn_5,          &QPushButton::clicked, this,      &MainWindow::buttonHanderNums);
    connect(m_btn_6,          &QPushButton::clicked, this,      &MainWindow::buttonHanderNums);
    connect(m_btn_7,          &QPushButton::clicked, this,      &MainWindow::buttonHanderNums);
    connect(m_btn_8,          &QPushButton::clicked, this,      &MainWindow::buttonHanderNums);
    connect(m_btn_9,          &QPushButton::clicked, this,      &MainWindow::buttonHanderNums);
    connect(m_btn_plus,       &QPushButton::clicked, this,      &MainWindow::buttonHandlerOperation);
    connect(m_btn_minus,      &QPushButton::clicked, this,      &MainWindow::buttonHandlerOperation);
    connect(m_btn_equal,      &QPushButton::clicked, this,      &MainWindow::buttonHandlerEqual);
    connect(m_btn_backspace,  &QPushButton::clicked, this,      &MainWindow::buttonHandlerBackSpace);
}

void MainWindow::reset()
{
    line_str = "";
    res = 0;
    num_str = "";
}



