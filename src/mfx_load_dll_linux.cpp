/* ******************************************************************************
 *\
 *
 * Copyright (C) 2012-2013 Intel Corporation.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 * - Neither the name of Intel Corporation nor the names of its contributors
 * may be used to endorse or promote products derived from this software
 * without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY INTEL CORPORATION "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL INTEL CORPORATION BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * File Name: mfx_load_dll_linux.cpp
 *
 \*
 ******************************************************************************
 */

#if !defined(_WIN32) && !defined(_WIN64)

#include "mfx_dispatcher.h"
#include <dlfcn.h>
#include <string.h>

#if !defined(_DEBUG)

#if defined(LINUX64)
const msdk_disp_char *defaultDLLName[2] = { "libmfxhw64.so", "libmfxsw64.so" };
#elif defined(__APPLE__)
#ifdef __i386__
const msdk_disp_char *defaultDLLName[2] = { "libmfxhw32.dylib",
                                            "libmfxsw32.dylib" };
#else
const msdk_disp_char *defaultDLLName[2] = { "libmfxhw64.dylib",
                                            "libmfxsw64.dylib" };
#endif // #ifdef __i386__ for __APPLE__

#else  // for Linux32 and Android
const msdk_disp_char *defaultDLLName[2] = { "libmfxhw32.so", "libmfxsw32.so" };
#endif // (defined(WIN64))

#else // defined(_DEBUG)

#if defined(LINUX64)
const msdk_disp_char *defaultDLLName[2] = { "libmfxhw64_d.so",
                                            "libmfxsw64_d.so" };
#elif defined(__APPLE__)
#ifdef __i386__
const msdk_disp_char *defaultDLLName[2] = { "libmfxhw32_d.dylib",
                                            "libmfxsw32_d.dylib" };
#else
const msdk_disp_char *defaultDLLName[2] = { "libmfxhw64_d.dylib",
                                            "libmfxsw64_d.dylib" };
#endif // #ifdef __i386__ for __APPLE__

#else  // for Linux32 and Android
const msdk_disp_char *defaultDLLName[2] = { "libmfxhw32_d.so",
                                            "libmfxsw32_d.so" };
#endif // (defined(WIN64))

#endif // !defined(_DEBUG)

namespace MFX {
mfxStatus mfx_get_default_dll_name(msdk_disp_char *pPath, size_t /*pathSize*/,
                                   eMfxImplType implType)
{
    strcpy(pPath, defaultDLLName[implType]);

    return MFX_ERR_NONE;
} // mfxStatus GetDefaultDLLName(wchar_t *pPath, size_t pathSize, eMfxImplType
  // implType)

mfxModuleHandle mfx_dll_load(const msdk_disp_char *pFileName)
{
    mfxModuleHandle hModule = (mfxModuleHandle)0;

    // check error(s)
    if (NULL == pFileName) {
        return NULL;
    }
    // load the module
    hModule = dlopen(pFileName, RTLD_LAZY);

    return hModule;
} // mfxModuleHandle mfx_dll_load(const wchar_t *pFileName)

mfxFunctionPointer mfx_dll_get_addr(mfxModuleHandle handle,
                                    const char *pFunctionName)
{
    if (NULL == handle) {
        return NULL;
    }

    mfxFunctionPointer addr = (mfxFunctionPointer)dlsym(handle, pFunctionName);
    if (dlerror()) {
        return NULL;
    }

    return addr;
} // mfxFunctionPointer mfx_dll_get_addr(mfxModuleHandle handle, const char
  // *pFunctionName)

bool mfx_dll_free(mfxModuleHandle handle)
{
    if (NULL == handle) {
        return true;
    }
    dlclose(handle);

    return true;
} // bool mfx_dll_free(mfxModuleHandle handle)
} // namespace MFX

#endif // #if !defined(_WIN32) && !defined(_WIN64)
