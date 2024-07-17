#ifndef CHATBOTWINDOW_H
#define CHATBOTWINDOW_H

#include <QDialog>

namespace Ui {
class ChatbotWindow;
}

class ChatbotWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ChatbotWindow(QWidget *parent = nullptr);
    ~ChatbotWindow();

public slots:
    void processUserInput();  // Added public slots for better organization
signals:
    void chatbotQuestionAsked(const QString &question);

private:
    Ui::ChatbotWindow *ui;
};

#endif // CHATBOTWINDOW_H
