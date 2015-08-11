/*
 * Copyright 2013 Luca Barbato. All rights reserved.
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
 */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <mfx/mfxvideo.h>

#ifdef HAVE_LIBVA_DRM
#include <va/va_drm.h>
#include <va/va_drmcommon.h>
#include <va/va_backend.h>

void *mfx_allocate_va(mfxSession session)
{
    char *card = getenv("MFX_DRM_CARD");
    int ret, fd;
    int minor, major;
    VADisplay display;

    if (!card)
        card = (char*)"/dev/dri/card0";
    if ((fd = open(card, O_RDWR)) < 0)
        return NULL;

    if (!(display = vaGetDisplayDRM(fd)))
        goto fail;

    if (vaInitialize(display, &major, &minor) < 0)
        goto fail;

    ret = MFXVideoCORE_SetHandle(session, MFX_HANDLE_VA_DISPLAY, display);
    if (ret != MFX_ERR_NONE)
        goto fail;
    return display;

fail:
    close(fd);
    return NULL;
}

void mfx_deallocate_va(void *handle)
{
    VADisplayContextP display;
    VADriverContextP driver;
    VADisplay disp;
    struct drm_state *state;

    disp = handle;
    if (!disp)
        return;

    display = (VADisplayContextP)disp;

    driver = display->pDriverContext;

    state = (struct drm_state *)driver->drm_state;

    close(state->fd);

    vaTerminate(disp);
}
#endif
