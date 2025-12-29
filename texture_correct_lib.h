#pragma once

#include <string>
#include <vector>
#include <optional>
#include <string_view>

#include <DirectXTex.h>

namespace texture_correct {

class ImageFormat
{
    public:
        enum Format : uint8_t { PNG, JPG, BMP, GIF, TIFF };

        constexpr ImageFormat() = default;

        constexpr ImageFormat(Format format) : value_(format) {}

        constexpr Format value() const { return value_; }

        constexpr operator Format() const { return value_; }

        friend constexpr bool operator==(ImageFormat a, Format b) { return a.value_ == b; }
        friend constexpr bool operator!=(ImageFormat a, Format b) { return a.value_ != b; }

        static constexpr std::string_view ToString(Format format)
        {
            switch(format)
            {
                case Format::PNG:  return "png";
                case Format::JPG:  return "jpg";
                case Format::BMP:  return "bmp";
                case Format::GIF:  return "gif";
                case Format::TIFF: return "tiff";
            }
            return "unknown";
        }

        static constexpr std::optional<Format> FromString(std::string_view s)
        {
            if (s == "png")  return Format::PNG;
            if (s == "jpg")  return Format::JPG;
            if (s == "bmp")  return Format::BMP;
            if (s == "gif")  return Format::GIF;
            if (s == "tiff") return Format::TIFF;

            return std::nullopt;
        }

    private:
        Format value_ = Format::PNG;
};

std::optional<DirectX::ScratchImage> GetScratchImageFromFilename(std::string filename);
std::optional<std::vector<DirectX::ScratchImage>> GetScratchImageVectorFromPath(std::string path);
bool SaveScratchImageAsDds(DirectX::ScratchImage& image);

} // namespace texture_correct
