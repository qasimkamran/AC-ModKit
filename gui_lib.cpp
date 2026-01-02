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
#include <QPixmap>
#include <QPushButton>
#include <QStringList>
#include <QToolButton>
#include <QWidget>
#include <optional>
#include <qlineedit.h>
#include <qpixmap.h>
#include <qstackedwidget.h>
#include <qwidget.h>
#include <vector>

#include "texture_correct_lib.h"
#include "ui.h"

static QString ResolveAssetPath(const QString& fileName)
{
    const QString assetDir = QStringLiteral("assets");
    const QString binaryCandidate = QDir(QCoreApplication::applicationDirPath()).filePath(assetDir + QLatin1Char('/') + fileName);

    if(QFileInfo::exists(binaryCandidate))
        return binaryCandidate;

    return {};
}

static void ApplyBackgroundImage(QWidget& widget)
{
    const QStringList candidates { QStringLiteral("background.png") };

    QString backgroundPath;
    for(const auto& candidate : candidates)
    {
        backgroundPath = ResolveAssetPath(candidate);
        if(!backgroundPath.isEmpty())
            break;
    }

    if(backgroundPath.isEmpty())
        return;

    const QString normalizedPath = QDir::fromNativeSeparators(backgroundPath);
    const QString style = QString::fromLatin1(
        "background-image: url(\"%1\");\n"
        "background-repeat: no-repeat;\n"
        "background-position: center;").arg(normalizedPath);

    widget.setAttribute(Qt::WA_StyledBackground, true);
    widget.setAutoFillBackground(true);
    widget.setStyleSheet(style);
}

static QStringList FilenamesFromQString(const QString* text)
{
    return text->split(';', Qt::SkipEmptyParts);
}

static std::optional<QPixmap> GetScaledPixMapFromFilename(const QSize size, const QString& filename)
{
    QPixmap pixmap = QPixmap(filename);

    if(pixmap.isNull())
        return std::nullopt;

    pixmap = pixmap.scaled(size, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    return pixmap;
}

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

        connect(
            ui.browseToolButton,
            &QToolButton::clicked,
            this,
            [this]()
            {
                const QStringList filenames = texture_correct::GetFilenamesFromDialog(this);
                if (filenames.isEmpty())
                    return;

                ui.browseLineEdit->setText(filenames.join(QStringLiteral("; ")));
            }
        );

        connect(
            ui.browseLineEdit,
            &QLineEdit::textChanged,
            this,
            [this](const QString& text)
            {
                if(text.trimmed().isEmpty())
                    return;

                const QStringList filenames = FilenamesFromQString(&text);

                if(!texture_correct::FilenamesValid(filenames))
                    return;

                // Check if the index has changed
                const int currentIndex = ui.manualModeSubStack->currentIndex();

                QWidget* target = (filenames.count() > 1) ? ui.multiFile : ui.singleFile;

                if(ui.manualModeSubStack->currentWidget() == target)
                    LauncherWindow::OnSetCurrentWidget(ui.manualModeSubStack->currentIndex());
                else
                    ui.manualModeSubStack->setCurrentWidget(target);
            }
        );

        connect(
            ui.manualModeSubStack,
            &QStackedWidget::currentChanged,
            this,
            &LauncherWindow::OnSetCurrentWidget
        );
    }

private:
    Ui::launcher ui;

    void OnSetCurrentWidget(const int index)
    {
        if(ui.manualModeSubStack->widget(index) == ui.singleFile)
        {
            QString text = ui.browseLineEdit->text();

            std::optional<QPixmap> pixmap = GetScaledPixMapFromFilename(ui.imagePreviewLabel->size(), text);

            if(pixmap == std::nullopt)
                return;

            const QStringList filenames = FilenamesFromQString(&text);

            if(!texture_correct::FilenamesValid(filenames))
                return;

            ui.imagePreviewLabel->setPixmap(*pixmap);
            ui.filenameTextEdit->setText(QFileInfo(filenames.front().trimmed()).fileName());
        }
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
