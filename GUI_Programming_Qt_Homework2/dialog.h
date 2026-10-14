#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

class QLineEdit;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    // 增加簡報中的三個自訂槽函數 (Customary slot functions)
    void decChanged(const QString &);
    void hexChanged(const QString &);
    void binChanged(const QString &);

private:
    QLineEdit* decEdit;
    QLineEdit* hexEdit;
    QLineEdit* binEdit;
};

#endif // DIALOG_H
