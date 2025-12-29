/* Purpose:
 *     This library provides all functions and classes useful for texture correction
 * 
 * Notes:
 *     - Use the stubs/DirectXTex.h for LSP on a linux development environment
 * */

#include "texture_correct_lib.h"
#include "winerror.h"

#include <system_error>
#include <vector>
#include <optional>
#include <filesystem>

#include <DirectXTex.h>
#include <winnls.h>

namespace texture_correct
{

static std::wstring ToWide(const std::string& utf8)
{
    if (utf8.empty())
        return std::wstring();

    int sizeNeeded = MultiByteToWideChar(CP_UTF8, 0, utf8.data(), (int)utf8.size(), nullptr, 0);

    std::wstring wide(sizeNeeded, 0);

    MultiByteToWideChar(CP_UTF8, 0, utf8.data(), (int)utf8.size(), wide.data(), sizeNeeded);

    return wide;
}

static bool FileValid(std::filesystem::path filepath)
{
    std::error_code errorCode;

    if(!std::filesystem::exists(filepath, errorCode))
    {
        printf("ERROR: %s does not exist\n", filepath.c_str());
        return false;
    }

    if(!std::filesystem::is_regular_file(filepath,  errorCode))
    {
        printf("ERROR: %s is not for a file - %s\n", __func__, filepath.c_str());
        return false;
    }

    if(!ImageFormat::FromString(filepath.extension().string()).has_value())
    {
        printf("ERROR: %s is not a recognized file extension\n", filepath.extension().c_str());
        return false;
    }

    return true;
}

static bool DirValid(std::filesystem::path directory)
{
    std::error_code errorCode;

    if(!std::filesystem::exists(directory, errorCode))
    {
        printf("ERROR: %s does not exist\n", directory.c_str());
        return false;
    }

    if(!std::filesystem::is_directory(directory))
    {
        printf("ERROR: %s is not for a directory - %s\n", __func__, directory.c_str());
        return false;
    }

    return true;
}

std::optional<DirectX::ScratchImage> GetScratchImageFromFilename(std::string path)
{
    std::filesystem::path filepath(path);

    if(!FileValid(filepath))
        return std::nullopt;

    DirectX::ScratchImage image;
    DirectX::TexMetadata info;

    HRESULT result = LoadFromWICFile(ToWide(filepath).c_str(), DirectX::WIC_FLAGS_NONE, &info, image);

    if(result != S_OK)
    {
        printf("ERROR: LoadFromWICFile failed to load %s\n", path.c_str());
        return std::nullopt;
    }

    return image;
}


std::optional<std::vector<DirectX::ScratchImage>> GetScratchImageVectorFromPath(std::string path)
{
    std::vector<DirectX::ScratchImage> images;

    std::filesystem::path directory(path);

    if(!DirValid(directory))
        return std::nullopt;

    std::vector<std::filesystem::path> filepaths;

    for(auto& entry : std::filesystem::directory_iterator(directory))
    {
        if(!entry.is_regular_file() || !ImageFormat::FromString(entry.path().extension().string()).has_value())
            continue;

        filepaths.push_back(entry);
    }

    for(std::filesystem::path filepath : filepaths)
    {
        DirectX::ScratchImage image;
        DirectX::TexMetadata info;

        HRESULT result = LoadFromWICFile(ToWide(filepath).c_str(), DirectX::WIC_FLAGS_NONE, &info, image);

        if(result != S_OK)
            printf("ERROR: LoadFromWICFile failed to load %s\n", filepath.c_str());
    }

    if(images.empty())
    {
        printf("ERROR: No images were loaded from %s\n", directory.c_str());
        return std::nullopt;
    }

    return images;
}

static bool ScratchImageValid(DirectX::ScratchImage& image)
{
    DirectX::TexMetadata info = image.GetMetadata();

    if(image.GetImageCount() == 0 || image.GetImages() == nullptr)
    {
        printf("ERROR: No images read from ScratchImage\n");
        return false;
    }

    if(info.width == 0 || info.height == 0)
    {
        printf("ERROR: TexMetadata height or width is 0\n");
        return false;
    }

    return true;
}

bool SaveScratchImageAsDds(DirectX::ScratchImage& image, std::string output_path)
{
    if(!ScratchImageValid(image))
        return false;

    if(!DirValid(std::filesystem::path(output_path)))
        return false;

    HRESULT result = DirectX::SaveToDDSFile(image.GetImages(),
                                            image.GetImageCount(),
                                            image.GetMetadata(),
                                            DDS_FLAGS_NONE,
                                            ToWide(output_path).c_str());

    if(result != S_OK)
        return false;

    return true;
}

} // namespace texture_correct

