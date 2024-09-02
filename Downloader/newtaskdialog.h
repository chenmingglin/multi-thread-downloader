#pragma once

#include <QDialog>
#include <QUrl>
namespace Ui {
class NewTaskDialog;
}

class NewTaskDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewTaskDialog(QWidget *parent = nullptr);
    ~NewTaskDialog();

    QUrl get_url() const;
    QString get_path() const;
    QString get_file_name() const;
    quint64 get_file_size() const;
private slots:
    void on_selectBtn_clicked();

    void on_buttonBox_accepted();

private:
    void init();
    void set_file_name_and_size();
    [[nodiscard]]QString& get_file_extension_from_content_type(QString& type);
private:
    Ui::NewTaskDialog *ui;

    QUrl m_url {};
    QString m_path {};
    QString m_file_name {};
    quint64 m_file_size {};
};

