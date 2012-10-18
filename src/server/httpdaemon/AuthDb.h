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

#ifndef HTTPDAEMON_AUTHDB_H
#define HTTPDAEMON_AUTHDB_H

#include "generated/ServerXMLSchema/AuthDb.h"
#include "libaccess/acl.h"

//-----------------------------------------------------------------------------
// AuthDb
//-----------------------------------------------------------------------------

class AuthDb : public ServerXMLSchema::AuthDbWrapper,
               public ConfigurationObject {
public:
    ~AuthDb();

    ACLVirtualDb_t *getVirtualDb() const { return virtdb; }

protected:
    AuthDb(ServerXMLSchema::AuthDb& authDb,
           ConfigurationObject *parent,
           const VirtualServer *vs);

private:
    ACLVirtualDb_t *virtdb;
};

//-----------------------------------------------------------------------------
// ServerAuthDb
//-----------------------------------------------------------------------------

/**
 * ServerAuthDb wraps a ServerXMLSchema::Server's ServerXMLSchema::AuthDb and
 * exposes the corresponding VirtualServer-specific ACLVirtualDb_t *.
 */
class ServerAuthDb : public AuthDb {
public:
    ServerAuthDb(ServerXMLSchema::AuthDb& authDb,
                 VirtualServer *vs);
};

//-----------------------------------------------------------------------------
// VirtualServerAuthDb
//-----------------------------------------------------------------------------

/**
 * VirtualServerAuthDb wraps a ServerXMLSchema::VirtualServer's
 * ServerXMLSchema::AuthDb and exposes the corresponding ACLVirtualDb_t *.
 */
class VirtualServerAuthDb : public AuthDb {
public:
    VirtualServerAuthDb(ServerXMLSchema::AuthDb& authDb,
                        VirtualServer *vs);
};

#endif // HTTPDAEMON_AUTHDB_H