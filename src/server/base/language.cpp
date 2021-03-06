/*
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS HEADER.
 *
 * Copyright 2008 Sun Microsystems, Inc. All rights reserved.
 *
 * THE BSD LICENSE
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer. 
 * Redistributions in binary form must reproduce the above copyright notice, 
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution. 
 *
 * Neither the name of the  nor the names of its contributors may be
 * used to endorse or promote products derived from this software without 
 * specific prior written permission. 
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER 
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; 
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR 
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * language.cpp: interface with libsi18n
 * 
 * Tony Xue
 */

#include "netsite.h"
#include "i18n.h"
#include "safs/nsfcsafs.h"
#include "base/language.h"

char * lang_acceptlang_file(const char *path)
{
    int len = strlen(path);
    if (len < 1 || path[len - 1] == '/')
        return NULL;

    int size = len + XP_EXTRA_LANGUAGE_PATH_LEN + 1;
    char *buf = (char *) MALLOC(size);
    if (buf == NULL)
        return NULL;

    XPLanguageEnumState *state = NULL;
    while (const char *lang = XP_EnumAudienceLanguageTags(XP_LANGUAGE_AUDIENCE_CLIENT, &state)) {
        NSFCFileInfo finfo;

        if (XP_FormatLanguageDir(path, len, lang, buf, size) != -1) {
            if (NSFC_GetFileInfo(buf, &finfo, nsapi_nsfc_cache) == PR_SUCCESS) {
                XP_EndLanguageEnum(&state);
                return buf;
            }
        }

        if (XP_FormatLanguageFile(path, len, lang, buf, size) != -1) {
            if (NSFC_GetFileInfo(buf, &finfo, nsapi_nsfc_cache) == PR_SUCCESS) {
                XP_EndLanguageEnum(&state);
                return buf;
            }
        }
    }
    XP_EndLanguageEnum(&state);

    FREE(buf);

    return NULL;
}
