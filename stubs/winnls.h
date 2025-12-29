#pragma once

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cstring>

#include <winnt.h>

#ifndef _WIN32

using UINT   = std::uint32_t;
using LPCCH  = const char*;
using LPWSTR = wchar_t*;

constexpr UINT CP_UTF8 = 65001;

inline int MultiByteToWideChar(UINT /*CodePage*/, DWORD /*dwFlags*/, LPCCH lpMultiByteStr, int cbMultiByte, LPWSTR lpWideCharStr, int cchWideChar)
{
    if (!lpMultiByteStr)
        return 0;

    const int length = (cbMultiByte >= 0) ? cbMultiByte : static_cast<int>(std::strlen(lpMultiByteStr));

    if (length == 0)
        return 0;

    if (!lpWideCharStr || cchWideChar <= 0)
        return length;

    const int copyLength = std::min(length, cchWideChar);

    for (int i = 0; i < copyLength; ++i)
    {
        lpWideCharStr[i] = static_cast<wchar_t>(static_cast<unsigned char>(lpMultiByteStr[i]));
    }

    return copyLength;
}

#endif
