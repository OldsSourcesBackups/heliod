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
 * PROPRIETARY/CONFIDENTIAL.  Use of this product is subject to license terms.
 * Copyright  1999 Sun Microsystems, Inc. Some preexisting portions Copyright
 * 1999 Netscape Communications Corp. All rights reserved.
 *
 * prpollsupp.h
 * Native poll support for Unix.
 */

#include "uxpolladapter.h"

// Provide PollAdapter functions using Unix poll() interface.
// Poll the given descriptor array, and return the number of descriptors ready
int UxPollAdapter::poll(void *descArray, PRInt32 numDesc, PRIntervalTime timeout)
{
    struct pollfd *pa = (struct pollfd *)descArray;
    PRIntn msecs;
    PRIntervalTime start, elapsed, remaining;
    PRInt32 ready;

    switch (timeout) 
    {
        case PR_INTERVAL_NO_WAIT: msecs = 0; break;
        case PR_INTERVAL_NO_TIMEOUT: msecs = -1; break;
        default: 
            msecs = PR_IntervalToMilliseconds(timeout);
            start = PR_IntervalNow();
     }
retry:
     ready = ::poll(pa, numDesc, msecs);

     if (-1 == ready) {
        PRIntn oserror = errno;

        if (EINTR == oserror) {
            if (timeout == PR_INTERVAL_NO_TIMEOUT)
                goto retry;
            else if (timeout == PR_INTERVAL_NO_WAIT)
                ready = 0; /* don't retry, just timeout */
            else {
                elapsed = (PRIntervalTime)(PR_IntervalNow() - start);

                if (elapsed > timeout)
                    ready = 0; /* timed out */
                else {
                    remaining = timeout - elapsed;
                    msecs = PR_IntervalToMilliseconds(remaining);
                    goto retry;
                }
            }
        }
    }
  return ready;
}
