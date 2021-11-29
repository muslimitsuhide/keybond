#include "Objects.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Objects window;

    window.resize(300, 190);
    window.setWindowTitle("KeyBOND");
    window.show();

    return app.exec();
}
