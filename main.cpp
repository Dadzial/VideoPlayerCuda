#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>

extern "C" int addNumbers();

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    QMainWindow main_window;
    main_window.setWindowTitle("Video Player");
    main_window.resize(1200, 800);

    QWidget *central = new QWidget(&main_window);
    main_window.setCentralWidget(central);

    QVBoxLayout *layout = new QVBoxLayout(central);
    layout->setContentsMargins(0, 30, 0, 0);
    layout->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

    QPushButton *play_button = new QPushButton("Open Video");
    play_button->setFixedSize(100, 30);

    play_button->setStyleSheet(
        "QPushButton {"
        "   background-color: white;"
        "   color: black;"
        "   font-weight: bold;"
        "   border-radius: 5px;"
        "}"
    );

    layout->addWidget(play_button);

    int result = addNumbers();
    QLabel *label = new QLabel(QString::number(result));
    label->setStyleSheet("color: white; font-size: 18px;");
    layout->addWidget(label);


    main_window.setStyleSheet(
        "QMainWindow {"
        "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
        "                                stop:0 #002240, "
        "                                stop:0.5 #00254C, "
        "                                stop:1 #002860);"
        "}"
    );

    main_window.show();
    return QApplication::exec();
}
