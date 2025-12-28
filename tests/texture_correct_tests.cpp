/* Purpose:
 *     - Test harness for all texture_correct namespace functions and classes
 *
 * Notes:
 *     - The DirectXTex.h functions are separated out into the corresponding text file,
 *       this was important to note since the texture_correct namespace relies on that lib.
 */

#include "texture_correct_lib.h"

#include <array>
#include <iostream>
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

    if(failures != 0)
    {
        std::cerr << failures << " test(s) failed\n";
        return 1;
    }

    std::cout << "All texture_correct tests passed\n";
    return 0;
}

