#ifndef ACCES_H
#define ACCES_H

#include <QDialog>
#include <QWidget>
namespace Ui {
class acces;
}

class acces : public QDialog
{
    Q_OBJECT

public:
    explicit acces(QWidget *parent = nullptr);
    ~acces();
    QString getUsername() const;
     QString getPassword() const;

signals:
     void loginSuccessful(const QString &roleUtilisateur); // Déplacez 'signals' à la section 'public'

     void loginButtonClicked();
     void loginCancelled();


private slots:
    void on_pb_login_clicked();
   void onDialogRejected();

private:
    Ui::acces *ui;

};

#endif // ACCES_H
