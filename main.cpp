#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <iostream>
extern "C" void addCuda(int a, int b, int *c);

int main(int argc, char *argv[]) {

    int result;
    addCuda(2, 3, &result);
    std::cout << "Result from CUDA: " << result << std::endl;

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
