/* Purpose:
 *     - Test harness file for DirectXTex.h functions used in this project
 *
 * Notes:
 *     - For this library to be tested accurately, it needs to be executed on
 *       a windows environment where the actual library definition exists.
 */

#include <DirectXTex.h>

#include <iostream>

int main()
{
    DirectX::ScratchImage scratchImage;
    DirectX::TexMetadata metadata;

    const char* filename = "nonexistent.png";

    const HRESULT result = LoadFromWICFile(filename, DirectX::WIC_FLAGS_NONE, &metadata, scratchImage);

    if(result == S_OK)
    {
        std::cout << "LoadFromWICFile unexpectedly succeeded for " << filename << '\n';
        return 1;
    }

    std::cout << "LoadFromWICFile failed as expected for " << filename << '\n';
    return 0;
}

