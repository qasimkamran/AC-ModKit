/* Purpose:
 *     - Test harness for all texture_correct namespace functions and classes
 *
 * Notes:
 *     - The DirectXTex.h functions are separated out into the corresponding text file,
 *       this was important to note since the texture_correct namespace relies on that lib.
 */

#include "texture_correct_lib.h"

#include <array>
#include <chrono>
#include <filesystem>
#include <iostream>
#include <string>
#include <string_view>

namespace
{
    void Require(bool condition, std::string_view message, int& failures)
    {
        if(!condition)
        {
            std::cerr << "FAIL: " << message << '\n';
            ++failures;
        }
    }

    std::filesystem::path CreateTempDirectory()
    {
        const auto now = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        const auto tempRoot = std::filesystem::temp_directory_path();
        const std::filesystem::path tempDir = tempRoot / ("texture_correct_tests_" + std::to_string(now));

        std::filesystem::create_directories(tempDir);
        return tempDir;
    }

    void RemoveDirectory(const std::filesystem::path& path)
    {
        std::error_code ec;
        std::filesystem::remove_all(path, ec);
    }
}

int main()
{
    using texture_correct::ImageFormat;
    using Format = ImageFormat::Format;

    int failures = 0;

    ImageFormat defaultFormat;
    Require(defaultFormat == Format::PNG, "default constructor should initialize to PNG", failures);

    constexpr std::array cases{
        std::pair{Format::PNG, std::string_view{"png"}},
        std::pair{Format::JPG, std::string_view{"jpg"}},
        std::pair{Format::BMP, std::string_view{"bmp"}},
        std::pair{Format::GIF, std::string_view{"gif"}},
        std::pair{Format::TIFF, std::string_view{"tiff"}},
    };

    for(const auto& [format, extension] : cases)
    {
        Require(ImageFormat::ToString(format) == extension,
                "ToString should map enum value to matching extension",
                failures);

        const auto parsed = ImageFormat::FromString(extension);
        Require(parsed.has_value(), "FromString should recognize known extensions", failures);
        if(parsed)
        {
            Require(parsed.value() == format, "FromString result should match the original format", failures);
        }

        const ImageFormat persisted(format);
        Require(persisted == format, "ImageFormat stores the provided enum value", failures);
    }

    Require(!ImageFormat::FromString("PNG").has_value(),
            "FromString should be case-sensitive and reject uppercase names",
            failures);

    Require(!ImageFormat::FromString("not_an_extension").has_value(),
            "FromString should reject unrecognized extensions",
            failures);

    const auto missingImage = texture_correct::GetScratchImageFromFilename("definitely_missing.png");
    Require(!missingImage.has_value(),
            "GetScratchImageFromFilename should fail for non-existent files",
            failures);

    const auto tempDir = CreateTempDirectory();

    const auto emptyDirectoryResult = texture_correct::GetScratchImageVectorFromPath(tempDir.string());
    Require(!emptyDirectoryResult.has_value(),
            "GetScratchImageVectorFromPath should report failure when no valid images are present",
            failures);

    DirectX::ScratchImage scratchImage;
    const bool saveResult = texture_correct::SaveScratchImageAsDds(scratchImage, tempDir.string());
    Require(!saveResult,
            "SaveScratchImageAsDds should fail when the ScratchImage metadata is invalid",
            failures);

    RemoveDirectory(tempDir);

    if(failures != 0)
    {
        std::cerr << failures << " test(s) failed\n";
        return 1;
    }

    std::cout << "All texture_correct tests passed\n";
    return 0;
}
