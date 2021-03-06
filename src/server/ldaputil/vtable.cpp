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

#include "ldaputili.h"
#include <ldap.h>
#ifdef USE_LDAP_SSL
#include <ldap_ssl.h>
#endif

#if defined( _WINDOWS ) && ! defined( _WIN32 )
/* On 16-bit WINDOWS platforms, it's erroneous to call LDAP API functions
 * via a function pointer, since they are not declared LDAP_CALLBACK.
 * So, we define the following functions, which are LDAP_CALLBACK, and
 * simply delegate to their counterparts in the LDAP API.
 */

#ifdef USE_LDAP_SSL
static LDAP_CALL LDAP_CALLBACK LDAP*
ldapuVd_ssl_init( const char *host, int port, int encrypted )
{
    return ldapssl_init (host, port, encrypted);
}
#else
static LDAP_CALL LDAP_CALLBACK LDAP*
ldapuVd_init    ( const char *host, int port )
{
    return ldap_init (host, port);
}
#endif

static LDAP_CALL LDAP_CALLBACK int
ldapuVd_set_option( LDAP *ld, int opt, void *val )
{
    return ldap_set_option (ld, opt, val);
}

static LDAP_CALL LDAP_CALLBACK int
ldapuVd_simple_bind_s( LDAP* ld, const char *username, const char *passwd )
{
    return ldap_simple_bind_s (ld, username, passwd);
}

static LDAP_CALL LDAP_CALLBACK int
ldapuVd_unbind( LDAP *ld )
{
    return ldap_unbind (ld);
}

static LDAP_CALL LDAP_CALLBACK int
ldapuVd_search_s( LDAP* ld, const char* baseDN, int scope, const char* filter, 
	char** attrs, int attrsonly, LDAPMessage** result )
{
    return ldap_search_s (ld, baseDN, scope, filter, attrs, attrsonly, result);
}

static LDAP_CALL LDAP_CALLBACK int
ldapuVd_count_entries( LDAP* ld, LDAPMessage* msg )
{
    return ldap_count_entries (ld, msg);
}

static LDAP_CALL LDAP_CALLBACK LDAPMessage*
ldapuVd_first_entry( LDAP* ld, LDAPMessage* msg )
{
    return ldap_first_entry (ld, msg);
}

static LDAP_CALL LDAP_CALLBACK LDAPMessage*
ldapuVd_next_entry( LDAP* ld, LDAPMessage* entry )
{
    return ldap_next_entry(ld, entry);
}

static LDAP_CALL LDAP_CALLBACK char*
ldapuVd_get_dn( LDAP* ld, LDAPMessage* entry )
{
    return ldap_get_dn (ld, entry);
}

static LDAP_CALL LDAP_CALLBACK char*
ldapuVd_first_attribute( LDAP* ld, LDAPMessage* entry, BerElement** iter )
{
    return ldap_first_attribute (ld, entry, iter);
}

static LDAP_CALL LDAP_CALLBACK char*
ldapuVd_next_attribute( LDAP* ld, LDAPMessage* entry, BerElement* iter)
{
    return ldap_next_attribute (ld, entry, iter);
}

static LDAP_CALL LDAP_CALLBACK char**
ldapuVd_get_values( LDAP *ld, LDAPMessage *entry, const char *desc )
{
    return ldap_get_values (ld, entry, desc);
}

static LDAP_CALL LDAP_CALLBACK struct berval**
ldapuVd_get_values_len( LDAP *ld, LDAPMessage *entry, const char *desc )
{
    return ldap_get_values_len (ld, entry, desc);
}

#else
/* On other platforms, an LDAP API function can be called via a pointer. */
#ifdef USE_LDAP_SSL
#define ldapuVd_ssl_init        ldapssl_init
#else
#define ldapuVd_init            ldap_init
#endif
#define ldapuVd_set_option      ldap_set_option
#define ldapuVd_simple_bind_s   ldap_simple_bind_s
#define ldapuVd_unbind          ldap_unbind
#define ldapuVd_set_option      ldap_set_option
#define ldapuVd_simple_bind_s   ldap_simple_bind_s
#define ldapuVd_unbind          ldap_unbind
#define ldapuVd_search_s        ldap_search_s
#define ldapuVd_count_entries   ldap_count_entries
#define ldapuVd_first_entry     ldap_first_entry
#define ldapuVd_next_entry      ldap_next_entry
#define ldapuVd_get_dn          ldap_get_dn
#define ldapuVd_first_attribute ldap_first_attribute
#define ldapuVd_next_attribute  ldap_next_attribute
#define ldapuVd_get_values      ldap_get_values
#define ldapuVd_get_values_len  ldap_get_values_len

#endif

/* Several functions in the standard LDAP API have no LDAP* parameter,
   but all the VTable functions do.  Here are some little functions that
   make up the difference, by ignoring their LDAP* parameter:
*/
static int LDAP_CALL LDAP_CALLBACK
ldapuVd_msgfree( LDAP *ld, LDAPMessage *chain )
{
    return ldap_msgfree (chain);
}

static void LDAP_CALL LDAP_CALLBACK
ldapuVd_memfree( LDAP *ld, void *dn )
{
    ldap_memfree (dn);
}

static void LDAP_CALL LDAP_CALLBACK
ldapuVd_ber_free( LDAP *ld, BerElement *ber, int freebuf )
{
    ldap_ber_free (ber, freebuf);
}

static void LDAP_CALL LDAP_CALLBACK
ldapuVd_value_free( LDAP *ld, char **vals )
{
    ldap_value_free (vals);
}

static void LDAP_CALL LDAP_CALLBACK
ldapuVd_value_free_len( LDAP *ld, struct berval **vals )
{
    ldap_value_free_len (vals);
}

static LDAPUVTable_t ldapu_VTable = {
/* By default, the VTable points to the standard LDAP API. */
#ifdef USE_LDAP_SSL
    ldapuVd_ssl_init,
#else
    ldapuVd_init,
#endif
    ldapuVd_set_option,
    ldapuVd_simple_bind_s,
    ldapuVd_unbind,
    ldapuVd_search_s,
    ldapuVd_count_entries,
    ldapuVd_first_entry,
    ldapuVd_next_entry,
    ldapuVd_msgfree,
    ldapuVd_get_dn,
    ldapuVd_memfree,
    ldapuVd_first_attribute,
    ldapuVd_next_attribute,
    ldapuVd_ber_free,
    ldapuVd_get_values,
    ldapuVd_value_free,
    ldapuVd_get_values_len,
    ldapuVd_value_free_len
};

/* Replace ldapu_VTable.  Subsequently, ldaputil will call the
   functions in 'from' (not the LDAP API) to access the directory.
 */
void
ldapu_VTable_set (LDAPUVTable_t* from)
{
    if (from) {
	memcpy (&ldapu_VTable, from, sizeof(LDAPUVTable_t));
    }
}

#ifdef USE_LDAP_SSL
LDAP*
ldapu_ssl_init( const char *defhost, int defport, int defsecure )
{
    if (ldapu_VTable.ldapuV_ssl_init) {
	return ldapu_VTable.ldapuV_ssl_init (defhost, defport, defsecure);
    }
    return NULL;
}
#else
LDAP*
ldapu_init( const char *defhost, int defport )
{
    if (ldapu_VTable.ldapuV_init) {
	return ldapu_VTable.ldapuV_init (defhost, defport);
    }
    return NULL;
}
#endif

int
ldapu_set_option( LDAP *ld, int option, void *optdata )
{
    if (ldapu_VTable.ldapuV_set_option) {
	return ldapu_VTable.ldapuV_set_option (ld, option, optdata);
    }
    return LDAP_LOCAL_ERROR;
}

int
ldapu_simple_bind_s( LDAP *ld, const char *who, const char *passwd )
{
    if (ldapu_VTable.ldapuV_simple_bind_s) {
	return ldapu_VTable.ldapuV_simple_bind_s (ld, who, passwd);
    }
    return LDAP_LOCAL_ERROR;
}

int
ldapu_unbind( LDAP *ld )
{
    if (ldapu_VTable.ldapuV_unbind) {
	return ldapu_VTable.ldapuV_unbind (ld);
    }
    return LDAP_LOCAL_ERROR;
}

int
ldapu_search_s( LDAP *ld, const char *base, int scope,
	        const char *filter, char **attrs, int attrsonly, LDAPMessage **res )
{
    if (ldapu_VTable.ldapuV_search_s) {
	return ldapu_VTable.ldapuV_search_s (ld, base, scope, filter, attrs, attrsonly, res);
    }
    return LDAP_LOCAL_ERROR;
}

int
ldapu_count_entries( LDAP *ld, LDAPMessage *chain )
{
    if (ldapu_VTable.ldapuV_count_entries) {
	return ldapu_VTable.ldapuV_count_entries (ld, chain);
    }
    return 0;
}

LDAPMessage*
ldapu_first_entry( LDAP *ld, LDAPMessage *chain )
{
    if (ldapu_VTable.ldapuV_first_entry) {
	return ldapu_VTable.ldapuV_first_entry (ld, chain);
    }
    return NULL;
}

LDAPMessage*
ldapu_next_entry( LDAP *ld, LDAPMessage *entry )
{
    if (ldapu_VTable.ldapuV_next_entry) {
	return ldapu_VTable.ldapuV_next_entry (ld, entry);
    }
    return NULL;
}

int
ldapu_msgfree( LDAP* ld, LDAPMessage *chain )
{
    if (ldapu_VTable.ldapuV_msgfree) {
	return ldapu_VTable.ldapuV_msgfree (ld, chain);
    }
    return LDAP_SUCCESS;
}

char*
ldapu_get_dn( LDAP *ld, LDAPMessage *entry )
{
    if (ldapu_VTable.ldapuV_get_dn) {
	return ldapu_VTable.ldapuV_get_dn (ld, entry);
    }
    return NULL;
}

void
ldapu_memfree( LDAP* ld, void *p )
{
    if (ldapu_VTable.ldapuV_memfree) {
	ldapu_VTable.ldapuV_memfree (ld, p);
    }
}

char*
ldapu_first_attribute( LDAP *ld, LDAPMessage *entry, BerElement **ber )
{
    if (ldapu_VTable.ldapuV_first_attribute) {
	return ldapu_VTable.ldapuV_first_attribute (ld, entry, ber);
    }
    return NULL;
}

char*
ldapu_next_attribute( LDAP *ld, LDAPMessage *entry, BerElement *ber )
{
    if (ldapu_VTable.ldapuV_next_attribute) {
	return ldapu_VTable.ldapuV_next_attribute (ld, entry, ber);
    }
    return NULL;
}

void
ldapu_ber_free( LDAP* ld, BerElement *ber, int freebuf )
{
    if (ldapu_VTable.ldapuV_ber_free) {
	ldapu_VTable.ldapuV_ber_free (ld, ber, freebuf);
    }
}

char**
ldapu_get_values( LDAP *ld, LDAPMessage *entry, const char *desc )
{
    if (ldapu_VTable.ldapuV_get_values) {
	return ldapu_VTable.ldapuV_get_values (ld, entry, desc);
    } else if (!ldapu_VTable.ldapuV_value_free
	       && ldapu_VTable.ldapuV_get_values_len) {
	auto struct berval** bvals =
		  ldapu_VTable.ldapuV_get_values_len (ld, entry, desc);
	if (bvals) {
	    auto char** vals = (char**)
	      ldapu_malloc ((ldap_count_values_len (bvals) + 1)
			    * sizeof(char*));
	    if (vals) {
		auto char** val;
		auto struct berval** bval;
		for (val = vals, bval = bvals; *bval; ++val, ++bval) {
		    auto const size_t len = (*bval)->bv_len;
		    *val = (char*) ldapu_malloc (len + 1);
		    memcpy (*val, (*bval)->bv_val, len);
		    (*val)[len] = '\0';
		}
		*val = NULL;
		return vals;
	    }
	}
    }
    return NULL;
}

void
ldapu_value_free( LDAP *ld, char **vals )
{
    if (ldapu_VTable.ldapuV_value_free) {
	ldapu_VTable.ldapuV_value_free (ld, vals);
    } else if (!ldapu_VTable.ldapuV_get_values && vals) {
	auto char** val;
	for (val = vals; *val; ++val) {
	    free (*val);
	}
	free (vals);
    }
}

struct berval**
ldapu_get_values_len( LDAP *ld, LDAPMessage *entry, const char *desc )
{
    if (ldapu_VTable.ldapuV_get_values_len) {
	return ldapu_VTable.ldapuV_get_values_len (ld, entry, desc);
    } else if (!ldapu_VTable.ldapuV_value_free_len
	       && ldapu_VTable.ldapuV_get_values) {
	auto char** vals =
		  ldapu_VTable.ldapuV_get_values (ld, entry, desc);
	if (vals) {
	    auto struct berval** bvals = (struct berval**)
	      ldapu_malloc ((ldap_count_values (vals) + 1)
			    * sizeof(struct berval*));
	    if (bvals) {
		auto char** val;
		auto struct berval** bval;
		for (val = vals, bval = bvals; *val; ++val, ++bval) {
		    auto const size_t len = strlen(*val);
		    *bval = (struct berval*) ldapu_malloc (sizeof(struct berval) + len);
		    (*bval)->bv_len = len;
		    (*bval)->bv_val = ((char*)(*bval)) + sizeof(struct berval);
		    memcpy ((*bval)->bv_val, *val, len);
		}
		*bval = NULL;
		return bvals;
	    }
	}
    }
    return NULL;
}

void
ldapu_value_free_len( LDAP *ld, struct berval **vals )
{
    if (ldapu_VTable.ldapuV_value_free_len) {
	ldapu_VTable.ldapuV_value_free_len (ld, vals);
    } else if (!ldapu_VTable.ldapuV_get_values_len && vals) {
	auto struct berval** val;
	for (val = vals; *val; ++val) {
	    free (*val);
	}
	free (vals);
    }
}
