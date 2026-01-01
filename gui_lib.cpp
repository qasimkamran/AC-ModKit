/* Purpose:
 *     Provide the Qt-based GUI launcher for the application
 *
 * Notes:
 *     - The Qt specific implementation is limited to Windows builds. Other
 *       platforms provide a stub so the rest of the project can continue
 *       building without Qt installed.
 */

#include "gui_lib.h"

#include <QApplication>
#include <QDialog>

#include "ui.h"

namespace gui::detail
{

class LauncherWindow : public QDialog
{
public:
    LauncherWindow(QWidget* parent = nullptr)
        : QDialog(parent)
    {
        ui.setupUi(this);
        ui.textureCorrectStack->setCurrentWidget(ui.main);

        connect(
            ui.autoModeButton,
            &QPushButton::clicked,
            this,
            [this]() { ui.textureCorrectStack->setCurrentWidget(ui.main); }
        );

        connect(
            ui.manualModeButton,
            &QPushButton::clicked,
            this,
            [this]()
            {
                ui.textureCorrectStack->setCurrentWidget(ui.manualMode);
                ui.manualModeSubStack->setCurrentWidget(ui.singleFile);
            }
        );
    }

private:
    Ui::launcher ui;
};

} // namespace gui::detail

namespace gui
{

int RunGuiApplication(int argc, char* argv[])
{
    QApplication app(argc, argv);

    detail::LauncherWindow window;
    window.show();

    return app.exec();
}

} // namespace gui
