#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <QTextCodec> // подключение класса кодека текста
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>


int main(int argc, char *argv[ ])
{
   QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8")); //изменения
   QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8")); //изменения
   QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8")); //изменения

QApplication app(argc, argv);

	QSpinBox *sb=new QSpinBox;
	QSlider *sl=new QSlider(Qt::Horizontal);
	sb->setMaximum(100);
	sl->setMaximum(100);

	QWidget *window = new QWidget;
	QHBoxLayout *layout = new QHBoxLayout;
	layout->addWidget(sb);
	layout->addWidget(sl);

	window->setLayout(layout);
	window->show();
	
	QObject::connect(sb,SIGNAL(valueChanged(int)),sl,SLOT(setValue(int)));
	QObject::connect(sl,SIGNAL(valueChanged(int)),sb,SLOT(setValue(int)));


return app.exec();
}
