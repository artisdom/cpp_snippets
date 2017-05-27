#include <QApplication>
#include <QDesktopWidget>
#include <QTextEdit>

class Absolute : public QWidget {

public:
    Absolute(QWidget *parent = 0);
};

Absolute::Absolute(QWidget *parent) : QWidget(parent) {

    QTextEdit *ledit = new QTextEdit(this);
    ledit->setGeometry(50, 50, 200, 150);
}

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    Absolute window;

    window.setWindowTitle("Absolute");
    window.show();

    return app.exec();
}
