#include "auth.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    auth window;

    window.show();


    return app.exec();
}
