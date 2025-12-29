#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include <winnt.h>
#include <winerror.h>

#ifndef _WIN32

// Minimal DXGI_FORMAT subset so LSPs understand the metadata structures.
enum DXGI_FORMAT : std::uint32_t
{
    DXGI_FORMAT_UNKNOWN                 = 0,
    DXGI_FORMAT_R32G32B32A32_FLOAT      = 2,
    DXGI_FORMAT_R16G16B16A16_FLOAT      = 10,
    DXGI_FORMAT_R8G8B8A8_UNORM          = 28,
    DXGI_FORMAT_B8G8R8A8_UNORM          = 87,
    DXGI_FORMAT_B8G8R8X8_UNORM          = 88,
};

namespace DirectX {

enum TEX_DIMENSION : std::uint32_t
{
    TEX_DIMENSION_TEXTURE1D = 2,
    TEX_DIMENSION_TEXTURE2D = 3,
    TEX_DIMENSION_TEXTURE3D = 4,
};

enum WIC_FLAGS : std::uint32_t
{
    WIC_FLAGS_NONE              = 0x0,
    WIC_FLAGS_FORCE_RGB         = 0x1,
    WIC_FLAGS_NO_X2_BIAS        = 0x2,
    WIC_FLAGS_NO_16BPP          = 0x4,
    WIC_FLAGS_ALLOW_MONO        = 0x8,
    WIC_FLAGS_ALL_FRAMES        = 0x10,
    WIC_FLAGS_IGNORE_SRGB       = 0x20,
    WIC_FLAGS_FORCE_SRGB        = 0x40,
    WIC_FLAGS_FORCE_LINEAR      = 0x80,
};

enum DDS_FLAGS : std::uint32_t
{
    DDS_FLAGS_NONE              = 0x0,
    DDS_FLAGS_LEGACY_DWORD      = 0x1,
    DDS_FLAGS_FORCE_RGB         = 0x2,
    DDS_FLAGS_NO_ALPHA          = 0x4,
    DDS_FLAGS_NO_16BPP          = 0x8,
    DDS_FLAGS_FORCE_DX10_EXT    = 0x10,
    DDS_FLAGS_FORCE_DX9_LEGACY  = 0x20,
};

struct TexMetadata
{
    std::size_t width           = 0;
    std::size_t height          = 0;
    std::size_t depth           = 0;
    std::size_t arraySize       = 0;
    std::size_t mipLevels       = 0;
    std::uint32_t miscFlags     = 0;
    std::uint32_t miscFlags2    = 0;
    DXGI_FORMAT format          = DXGI_FORMAT_UNKNOWN;
    TEX_DIMENSION dimension     = TEX_DIMENSION_TEXTURE2D;
};

struct Image
{
    std::size_t width       = 0;
    std::size_t height      = 0;
    std::size_t depth       = 0;
    std::size_t rowPitch    = 0;
    std::size_t slicePitch  = 0;
    DXGI_FORMAT format      = DXGI_FORMAT_UNKNOWN;
    std::uint8_t* pixels    = nullptr;
};

class ScratchImage 
{
public:
    ScratchImage() noexcept = default;
    ScratchImage(ScratchImage&&) noexcept = default;
    ScratchImage& operator=(ScratchImage&&) noexcept = default;

    ScratchImage(const ScratchImage&) = delete;
    ScratchImage& operator=(const ScratchImage&) = delete;

    ~ScratchImage() = default;

    const Image* GetImages() const noexcept
    {
        return m_images.empty() ? nullptr : m_images.data();
    }

    std::size_t GetImageCount() const noexcept
    {
        return m_images.size();
    }

    const TexMetadata& GetMetadata() const noexcept
    {
        return m_metadata;
    }

private:
    std::vector<Image> m_images{};
    TexMetadata m_metadata{};
};

HRESULT LoadFromWICFile(const wchar_t* filename, std::uint32_t flags, TexMetadata* metadata, ScratchImage& image) noexcept;
HRESULT SaveToDDSFile(const Image* images, std::size_t nimages, const TexMetadata& metadata, std::uint32_t flags, const wchar_t* filename) noexcept;

} // namespace DirectX

inline HRESULT DirectX::LoadFromWICFile(const wchar_t*, std::uint32_t, TexMetadata*, ScratchImage&) noexcept
{
    return E_FAIL;
}

inline HRESULT DirectX::SaveToDDSFile(const Image*, std::size_t, const TexMetadata&, std::uint32_t, const wchar_t*) noexcept
{
    return E_FAIL;
}

using DirectX::DDS_FLAGS;
using DirectX::DDS_FLAGS_NONE;

#endif
