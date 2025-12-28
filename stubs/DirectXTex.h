#pragma once

#include <stddef.h>

#include <winnt.h>
#include <winerror.h>

#ifndef _WIN32

namespace DirectX {

enum WIC_FLAGS : uint32_t
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
    WIC_FLAGS_DEFAULT_SRGB      = 0x100,
};

struct TexMetadata {};

struct Image
{
    const void* pixels;
    size_t width;
    size_t height;
};

class ScratchImage 
{
public:
    const Image* GetImages() const { return nullptr; }
    
    size_t GetImageCount() const { return 0; }
    
    const TexMetadata& GetMetadata() const
    {
        static TexMetadata m;
        return m;
    }
};

inline int LoadFromWICFile(...) { return -1; }
inline int SaveToDDSFile(...) { return -1; }

} // namespace DirectX

#endif

