#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <map>

class QPushButton;
class QLineEdit;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void createGui();
    void buttonHanderNums();
    void buttonHandlerOperation();
    void buttonHandlerEqual();
    void buttonHandlerBackSpace();
    void connectSignals();
    void reset();

private:
    std::string num_str  = "";
    std::string line_str = "";

    int res = 0;

    QPushButton *m_btn_0,     *m_btn_1,     *m_btn_2,         *m_btn_3,
                *m_btn_4,     *m_btn_5,     *m_btn_6,         *m_btn_7,
                *m_btn_8,     *m_btn_9,     *m_btn_backspace, *m_btn_plus,
                *m_btn_minus, *m_btn_equal;

    QLineEdit *m_line_res;



    enum buttonOperation{
        buttonPlus,
        buttonMinus
    };


};

#endif // MAINWINDOW_H
