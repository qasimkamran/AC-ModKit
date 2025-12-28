/* Purpose:
 *     This library provides all functions and classes useful for texture correction
 * 
 * Notes:
 *     - Use the stubs/DirectXTex.h for LSP on a linux development environment
 * */

#include "texture_correct_lib.h"

#include <optional>
#include <filesystem>

#include <DirectXTex.h>

using namespace texture_correct;

std::optional<DirectX::ScratchImage> GetScratchImageFromFilename(std::string& filename)
{
    std::filesystem::path filepath(filename);

    std::error_code errorCode;

    if(!std::filesystem::exists(filepath, errorCode))
    {
        printf("ERROR: File %s does not exist\n", filename.c_str());
        return std::nullopt;
    }

    if(!ImageFormat::FromString(filepath.extension().string()).has_value())
    {
        printf("ERROR: %s is not a recognized file extension", filepath.extension().c_str());
        return std::nullopt;
    }

    DirectX::ScratchImage image;
    DirectX::TexMetadata info;

    HRESULT result = LoadFromWICFile(filename.c_str(), DirectX::WIC_FLAGS_NONE, &info, image);

    if(result != S_OK)
    {
        printf("ERROR: LoadFromWICFile failed to load %s", filename.c_str());
        return std::nullopt;
    }

    return image;
}

bool SaveScratchImageAsDds(DirectX::ScratchImage& image);

