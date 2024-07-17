#include "chatbotwindow.h"
#include "ui_chatbotwindow.h"

ChatbotWindow::ChatbotWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChatbotWindow)
{
    ui->setupUi(this);
    connect(ui->sendButton, SIGNAL(clicked()), this, SLOT(processUserInput()));
    connect(this, SIGNAL(chatbotQuestionAsked(QString)), parent, SLOT(gestionChatbot(QString)));

}

ChatbotWindow::~ChatbotWindow()
{
    delete ui;
}

void ChatbotWindow::processUserInput()
{
    // Retrieve the user's question from the input line edit
    QString userQuestion = ui->userInputLineEdit->text();

    // Emit the chatbotQuestionAsked signal with the user's question
    emit chatbotQuestionAsked(userQuestion);
}
