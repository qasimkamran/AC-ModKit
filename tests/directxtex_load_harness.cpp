/* Purpose:
 *     - Test harness file for DirectXTex.h functions used in this project
 *
 * Notes:
 *     - For this library to be tested accurately, it needs to be executed on
 *       a windows environment where the actual library definition exists.
 */

#include <DirectXTex.h>
#include <winnls.h>

#include <iostream>
#include <string>
#include <string_view>

namespace
{
    std::wstring ToWide(std::string_view utf8)
    {
        if(utf8.empty())
            return std::wstring();

        const int sizeNeeded = MultiByteToWideChar(CP_UTF8, 0, utf8.data(), static_cast<int>(utf8.size()), nullptr, 0);
        if(sizeNeeded <= 0)
            return std::wstring();

        std::wstring wide(sizeNeeded, L'\0');
        MultiByteToWideChar(CP_UTF8, 0, utf8.data(), static_cast<int>(utf8.size()), wide.data(), sizeNeeded);
        return wide;
    }
}

int main()
{
    DirectX::ScratchImage scratchImage;
    DirectX::TexMetadata metadata;

    const std::string filename = "nonexistent.png";
    const std::wstring wideFilename = ToWide(filename);

    const HRESULT result = LoadFromWICFile(wideFilename.c_str(), DirectX::WIC_FLAGS_NONE, &metadata, scratchImage);

    if(result == S_OK)
    {
        std::cout << "LoadFromWICFile unexpectedly succeeded for " << filename << '\n';
        return 1;
    }

    std::cout << "LoadFromWICFile failed as expected for " << filename << '\n';
    return 0;
}
