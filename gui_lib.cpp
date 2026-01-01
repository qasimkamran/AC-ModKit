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
#include <QCoreApplication>
#include <QDialog>
#include <QDir>
#include <QFileInfo>
#include <QPushButton>
#include <QWidget>
#include <QStringList>
#include <QUrl>

#include "ui.h"

namespace
{

QString ResolveAssetPath(const QString& fileName)
{
    const QString assetDir = QStringLiteral("assets");
    const QString binaryCandidate = QDir(QCoreApplication::applicationDirPath())
                                         .filePath(assetDir + QLatin1Char('/') + fileName);

    if (QFileInfo::exists(binaryCandidate))
    {
        return binaryCandidate;
    }

#ifdef AC_MODKIT_SOURCE_ASSETS_DIR
    const QString sourceCandidate = QDir(QStringLiteral(AC_MODKIT_SOURCE_ASSETS_DIR))
                                        .filePath(fileName);

    if (QFileInfo::exists(sourceCandidate))
    {
        return sourceCandidate;
    }
#endif

    return {};
}

void ApplyBackgroundImage(QWidget& widget)
{
    const QStringList candidates{
        QStringLiteral("ACModkit-Background.png"),
        QStringLiteral("background.png"),
    };

    QString backgroundPath;
    for (const auto& candidate : candidates)
    {
        backgroundPath = ResolveAssetPath(candidate);
        if (!backgroundPath.isEmpty())
        {
            break;
        }
    }

    if (backgroundPath.isEmpty())
    {
        return;
    }

    const auto backgroundUrl = QUrl::fromLocalFile(backgroundPath).toString();
    const QString style = QString::fromLatin1(
        "background-image: url(%1);\n"
        "background-repeat: no-repeat;\n"
        "background-position: center;")
                               .arg(backgroundUrl);

    widget.setStyleSheet(style);
}

} // namespace

namespace gui::detail
{

class LauncherWindow : public QDialog
{
public:
    LauncherWindow(QWidget* parent = nullptr)
        : QDialog(parent)
    {
        ui.setupUi(this);
        ui.textureCorrectStack->setCurrentWidget(ui.welcome);
        ApplyBackgroundImage(*this);

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
