#pragma once

#include <cstdint>

#ifndef _WIN32

using HRESULT = std::int32_t;

constexpr HRESULT S_OK    = 0;
constexpr HRESULT E_FAIL  = static_cast<HRESULT>(0x80004005);
constexpr HRESULT E_INVALIDARG = static_cast<HRESULT>(0x80070057);

constexpr bool SUCCEEDED(HRESULT hr) {
    return hr >= 0;
}

constexpr bool FAILED(HRESULT hr) {
    return hr < 0;
}

#endif

