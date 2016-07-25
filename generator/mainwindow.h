#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMainWindow>
#include <QComboBox>
#include <QColorDialog>
#include <QColor>
#include <QObject>
#include <QMessageBox>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QVector>
#include <QRadioButton>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void                    setEyeWidget();
    void                    setItemWidget();
    void                    setSpotWidget();
    void                    setPlanWidget();
    void                    set_color_button();
    void                    add_item_to_file();
    void                    generate_file();

private:
    void                                            get_transformation(QTreeWidgetItem *);
    void                                            get_particularity(QTreeWidgetItem *);
    Ui::MainWindow *ui;
    QVector<QRadioButton *>       *m_button;
    bool                                            _eye;
};

#endif // MAINWINDOW_H
