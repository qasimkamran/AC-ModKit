/* Purpose:
 *     Provide the Qt-based GUI launcher for the application
 *
 * Notes:
 *     - The Qt specific implementation is limited to Windows builds. Other
 *       platforms provide a stub so the rest of the project can continue
 *       building without Qt installed.
 */

#include "gui_lib.h"

#include <QLabel>
#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

namespace gui::detail
{

class LauncherWindow : public QWidget
{
public:
    LauncherWindow()
    {
        setWindowTitle("AC ModKit");
        setMinimumSize(360, 200);

        auto* layout = new QVBoxLayout(this);
        layout->setSpacing(12);

        auto* header = new QLabel("Select application mode:", this);
        header->setWordWrap(true);
        header->setAlignment(Qt::AlignCenter);
        layout->addWidget(header);

        auto* autoModeButton = new QPushButton("Auto", this);
        auto* manualModeButton = new QPushButton("Manual", this);

        autoModeButton->setCursor(Qt::PointingHandCursor);
        manualModeButton->setCursor(Qt::PointingHandCursor);

        layout->addWidget(autoModeButton);
        layout->addWidget(manualModeButton);

        connect(autoModeButton, &QPushButton::clicked, this, []() {});
        connect(manualModeButton, &QPushButton::clicked, this, []() {});

        layout->addStretch(1);
    }
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

