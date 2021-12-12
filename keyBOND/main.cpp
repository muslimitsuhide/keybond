#include "Objects.h"
#include "auth.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    auth window1;
    Objects window;

    window.show();
    window.close();
    window1.show();

    return app.exec();
}
