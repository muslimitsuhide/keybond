#include "line.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Objects window;

    window.resize(300, 190);
    window.setWindowTitle("Text input");
    window.show();

    return app.exec();
}
