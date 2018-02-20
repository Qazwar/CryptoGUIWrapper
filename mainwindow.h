#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


namespace Ui
{
	class MainWindow;
}
std::string process(int commandIndex,const std::string &text,const std::string &keyt1,const std::string &keyt2);

class MainWindow: public QMainWindow
{
Q_OBJECT

public:
	explicit MainWindow(QWidget *parent=0);
	~MainWindow() final;

public slots:
	void AlgorithmTypeChange(int index);
	void ClickExec();
	void ClickClear();

private:
	Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
