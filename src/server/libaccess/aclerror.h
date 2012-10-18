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

#ifndef __aclerror_h
#define __aclerror_h

/* ACL facility name string (in aclbuild.c) */
NSPR_BEGIN_EXTERN_C
extern char * ACL_Program;
NSPR_END_EXTERN_C

/* Define error identifiers */

/* Errors generated in aclparse.c */

/* aclAuthListParse() */
#define ACLERR1000	1000	/* dynamic memory shortage */

/* aclAuthHostsParse() */
#define ACLERR1100	1100	/* unsupported list of host lists */
#define ACLERR1120	1120	/* host list name not found where expected */
#define ACLERR1140	1140	/* undefined host list name */
#define ACLERR1160	1160	/* *unused* */
#define ACLERR1180	1180	/* error adding IP filter entry */
#define ACLERR1200	1200	/* error adding DNS filter entry */
#define ACLERR1220	1220	/* ")" missing */

/* aclAuthUsersParse() */
#define ACLERR1300	1300	/* *unused* */
#define ACLERR1320	1320	/* *unused* */
#define ACLERR1340	1340	/* *unused* */
#define ACLERR1360	1360	/* undefined user or group name */
#define ACLERR1380	1380	/* duplicate user or group name */
#define ACLERR1400	1400	/* ")" missing */
#define ACLERR1420	1420	/* empty auth-user-elem */
#define ACLERR1440	1440	/* duplicate or conflicting use of "all" */
#define ACLERR1460	1460	/* duplicate or conflicting use of "any" */
#define ACLERR1480	1480	/* conflicting use of "all" or "any" */
#define ACLERR1500	1500	/* insufficient dynamic memory */
#define ACLERR1520	1520	/* insufficient dynamic memory */

/* aclDirectivesParse() */
#define ACLERR1600	1600	/* dir-access missing */
#define ACLERR1620	1620	/* invalid dir-access specification */
#define ACLERR1640	1640	/* error adding ACD_AUTH directive to ACL */
#define ACLERR1650	1650	/* error adding directive to ACL */
#define ACLERR1660	1660	/* insufficient dynamic memory */
#define ACLERR1680	1680	/* insufficient dynamic memory */
#define ACLERR1685	1685	/* insufficient dynamic memory */
#define ACLERR1690	1690	/* error adding directive to ACL */
#define ACLERR1695	1695	/* error in "execute" directive */

/* aclACLParse() */
#define ACLERR1700	1700	/* ACL statement missing */
#define ACLERR1720	1720	/* ACL name missing */
#define ACLERR1740	1740	/* opening "{" missing */
#define ACLERR1760	1760	/* closing "}" missing */
#define ACLERR1780	1780	/* unrecognized ACL statement */

/* aclFileOpen() */
#define ACLERR1900	1900	/* file open error */
#define ACLERR1920	1920	/* memory shortage for ACLFile_t */
#define ACLERR1940	1940	/* memory shortage for token */
#define ACLERR1960	1960	/* memory shortage for LEX stream */

/* aclGetDNSString() */
#define ACLERR2100	2100	/* */
#define ACLERR2120	2120	/* */
#define ACLERR2140	2140	/* */

/* aclGetIPAddr() */
#define ACLERR2200	2200	/* */
#define ACLERR2220	2220	/* */
#define ACLERR2240	2240	/* */
#define ACLERR2260	2260	/* */
#define ACLERR2280	2280	/* */
#define ACLERR2300	2300	/* */
#define ACLERR2320	2320	/* */

/* aclGetToken() */
#define ACLERR2400	2400	/* aclGetToken() parse error */

/* aclParseInit() */

/* aclRealmSpecParse() */
#define ACLERR2500	2500	/* missing realm name */
#define ACLERR2520	2520	/* undefined realm name */
#define ACLERR2540	2540	/* insufficient dynamic memory */
#define ACLERR2560	2560	/* missing realm directive */
#define ACLERR2570	2570	/* missing database filespec */
#define ACLERR2580	2580	/* missing authentication method name */
#define ACLERR2600	2600	/* unknown authentication method name */
#define ACLERR2605	2605	/* realm prompt string missing */
#define ACLERR2610	2610	/* unknown realm directive */
#define ACLERR2620	2620	/* missing "}" */

/* aclRightsParse() */
#define ACLERR2700	2700	/* missing rights list element */
#define ACLERR2720	2720	/* missing rights list name */
#define ACLERR2740	2740	/* undefined rights list name */
#define ACLERR2760	2760	/* insufficient dynamic memory */
#define ACLERR2780	2780	/* insufficient dynamic memory */
#define ACLERR2800	2800	/* error creating access right definition */
#define ACLERR2820	2820	/* insufficient dynamic memory */
#define ACLERR2840	2840	/* missing ")" */

/* aclGetFileSpec() */
#define ACLERR2900	2900	/* skip over whitespace failed */
#define ACLERR2920	2920	/* scan over filename failed */
#define ACLERR2940	2940	/* missing filename */

/* aclStringOpen() */
#define ACLERR5000	5000	/* memory shortage for ACLFile_t */
#define ACLERR5020	5020	/* memory shortage for token */
#define ACLERR5040	5040	/* memory shortage for LEX stream */

/* Errors generated in aclbuild.c */

/* accCreate() */
#define ACLERR3000	3000		/* insufficient dynamic memory */
#define ACLERR3020	3020		/* insufficient dynamic memory */

/* accFileRead() */
#define ACLERR3100	3100		/* error initializing ACL parser */
#define ACLERR3120	3120		/* error creating ACL symbol table */

/* aclCreate() */
#define ACLERR3200	3200		/* insufficient dynamic memory */
#define ACLERR3220	3220		/* duplicate ACL name */

/* aclAuthNameAdd() */
#define ACLERR3400	3400		/* realm missing for user/group name */
#define ACLERR3420	3420		/* error opening authentication DB */
#define ACLERR3440	3440		/* error finding name in DB */
#define ACLERR3460	3460		/* insufficient dynamic memory */

/* aclRightDef() */
#define ACLERR3600	3600		/* insufficient dynamic memory */
#define ACLERR3620	3620		/* add right to symbol table failed */

/* ACL_ListPostParseForAuth() */
#define ACLERR3800	3800		/* Undefined method/database */
#define ACLERR3810	3810		/* insufficient dynamic memory */

/* Register.cpp */
#define ACLERR3900	3900		/* Duplicate LAS registered */

/* ACL_EvalBuildContext */
#define ACLERR4000	4000		/* Unable to create context hash */
#define ACLERR4010	4010		/* Unable to alloc cache structure */
#define ACLERR4020	4020		/* Unable to alloc ACE entry */
#define ACLERR4030	4030		/* Unable to alloc ACE entry */
#define ACLERR4040	4040		/* Unable to alloc Auth Ptr Array */
#define ACLERR4050	4050		/* Unable to alloc Auth Ptr Array */

/* ACL_EvalTestRights */
#define ACLERR4100	4100		/* Interim absolute, non-allow value */
#define ACLERR4110	4110		/* BuildContext call failed */

/* ACL_ModuleRegister */
#define ACLERR4200	4200		/* module name missing */
#define ACLERR4210	4210		/* module registration call failed */

/* ACL_GetAttribute */
#define ACLERR4300	4300		/* Couldn't determine method */
#define ACLERR4310	4310		/* Couldn't locate Getter */
#define ACLERR4320	4320		/* Couldn't Set Attr */
#define ACLERR4330	4330		/* Couldn't Get Attr */
#define ACLERR4340	4340		/* All getters declined */
#define ACLERR4350	4350		/* All getters declined */
#define ACLERR4360	4360		/* All getters declined */
#define ACLERR4370	4370		/* All getters declined */
#define ACLERR4380	4380		/* Couldn't determine dbtype */

/* reg_dbname_internal */
#define ACLERR4400	4400		/* dbtype not defined yet */
#define ACLERR4410	4410		/* dbtype not defined yet */
#define ACLERR4420	4420		/* out of memory */

/* ACL_DatabaseRegister */
#define ACLERR4500	4500		/* database name is missing */

/* ACL_ReadDbMapFile */
#define	ACLERR4600	4600		/* Error reading the Map file */
#define	ACLERR4610	4610		/* Couldn't determine dbtype */
#define	ACLERR4620	4620		/* Missing URL for database */
#define	ACLERR4630	4630		/* Invalid proprty pair */
#define	ACLERR4640	4640		/* Register database failed */
#define	ACLERR4650	4650		/* Default database not LDAP */
#define	ACLERR4660	4660		/* Multiple default databases */
#define	ACLERR4670	4670		/* No default database */

/* LASDnsBuild */
#define	ACLERR4700	4700		/* Cannot allocatae hash */
#define	ACLERR4710	4710		/* Cannot add token to hash */
#define	ACLERR4720	4720		/* Cannot add token to hash */
#define	ACLERR4730	4730		/* Cannot add token to hash */
#define	ACLERR4740	4740		/* Cannot add token to hash */
#define	ACLERR4750	4750		/* Cannot add token to hash */
#define	ACLERR4760	4760		/* Cannot add token to hash */

/* LASDnsEval */
#define	ACLERR4800	4800		/* Wrong attribute name */
#define	ACLERR4810	4810		/* Illegal comparator */
#define	ACLERR4820	4820		/* Cannot allocate context struct */
#define	ACLERR4830	4830		/* Cannot get DNS attribute */

/* LASGroupEval */
#define ACLERR4900	4900		/* wrong attribute */
#define ACLERR4910	4910		/* bad comparator */
#define ACLERR4920	4920		/* unable to get database name */

/* LASIpTreeAllocNode */
#define	ACLERR5000	5000		/* Cannot allocate IP tree */

/* LASIpAddPattern */
#define	ACLERR5100	5100		/* Cannot allocate IP tree node */
#define	ACLERR5110	5110		/* Cannot allocate IP tree node */
#define	ACLERR5120	5120		/* Incorrect ip address pattern */

/* LASIpEval */
#define	ACLERR5200	5200		/* Wrong attribute */
#define	ACLERR5210	5210		/* Bad comparator */
#define	ACLERR5220	5220		/* Cannot get session pointer */
#define	ACLERR5230	5230		/* Cannot allocate context */
#define	ACLERR5240	5240		/* Tested 32 bits without conclusion */

/* LASProgramEval */
#define	ACLERR5300	5300		/* Wrong attribute */
#define	ACLERR5310	5310		/* Bad comparator */
#define	ACLERR5320	5320		/* Can't get request pointer */
#define	ACLERR5330	5330		/* Invalid program expression */
#define	ACLERR5340	5340		/* Rejecting Request */

/* LASDayOfWeekEval */
#define	ACLERR5400	5400		/* wrong attribute */
#define	ACLERR5410	5410		/* bad comparator */

/* LASTimeOfDayEval */
#define ACLERR5600	5600		/* wrong attribute */
#define ACLERR5610	5610		/* bad comparator */

/* LASUserEval */
#define ACLERR5700	5700		/* wrong attribute */
#define ACLERR5710	5710		/* bad comparator */
#define ACLERR5720	5720		/* Out of memory */

/* ldapacl.cpp */
#define	ACLERR5800	5800		/* missing the database url */
#define	ACLERR5810	5810		/* missing the database name */
#define	ACLERR5815	5815		/* invalid number of sessions */
#define	ACLERR5820	5820		/* error parsing the db url */
#define	ACLERR5830	5830		/* unable to get db name */
#define ACLERR5840	5840		/* can't get parsed db name */
#define ACLERR5850	5850		/* can't init ldap connection */
#define ACLERR5860	5860		/* passwd check ldap error */
#define ACLERR5870	5870		/* Out of memory */
#define ACLERR5880	5880		/* User doesn't exist anymore */
#define ACLERR5890	5890		/* PList error */
#define ACLERR5895	5895            /* digest error : invalid digest request*/

/* get_ldap_basedn */
#define	ACLERR5500	5500
#define	ACLERR5510	5510
#define	ACLERR5520	5520
#define	ACLERR5530	5530
#define	ACLERR5540	5540
#define	ACLERR5550	5550
#define	ACLERR5560	5560

/* get_user_ismember_ldap */
#define ACLERR5900	5900		/* Can't get db name */
#define ACLERR5910	5910		/* Can't get parsed db name */
#define	ACLERR5920	5920		/* Out of memory */
#define	ACLERR5930	5930		/* Can't init ldap connection */
#define	ACLERR5940	5940		/* Group doesn't exist */
#define	ACLERR5950	5950		/* LDAP error */

/* ACL_LDAPDatabaseHandle */
#define ACLERR6000	6000		/* Not a registered db */
#define ACLERR6010	6010		/* Not an LDAP db */
#define ACLERR6020	6020		/* Out of memory */
#define ACLERR6030	6030		/* Can't init ldap connection */
#define ACLERR6040	6040		/* Can't bind to ldap server */

/* register.cpp */
#define	ACLERR6100	6100		/* missing the database url */
#define	ACLERR6110	6110		/* missing the database name */
#define	ACLERR6120	6120		/* error parsing the db url */

/* nullacl.cpp */
#define	ACLERR6200	6200		/* missing the database url */
#define	ACLERR6210	6210		/* missing the database name */
#define	ACLERR6220	6220		/* db url must have "null:" prefix */
#define	ACLERR6230	6230		/* db url must have "null:///" prefix */
#define	ACLERR6240	6240		/* only "null:///all" or "null:///none" are valid */

/* lasssl.cpp */
#define	ACLERR6300	6300		/* wrong attribute */
#define	ACLERR6310	6310    	/* bad comparator */
#define	ACLERR6320	6320    	/* bad value */
#define	ACLERR6330	6330		/* cannot get session pointer */

/* fileacl.cpp */
#define	ACLERR6400	6400		/* missing the database url */
#define	ACLERR6410	6410		/* missing the database name */
#define	ACLERR6420	6420		/* error parsing the db url */
#define	ACLERR6430	6430		/* open file error, file not exists*/
#define	ACLERR6440	6440		/* error in reading file, line too long ... */

/* ACL_LDAPSessionAllocate */
#define ACLERR6500	6500		/* No associated VS */
#define ACLERR6510	6510		/* Not a registered user db */
#define ACLERR6520	6520		/* Not a registered database */
#define ACLERR6530	6530		/* Not an LDAP database */

/* pamacl.cpp */  
#define ACLERR6600      6600            /* DBT_pamDbUrlIsWrong */
#define ACLERR6601      6601            /* DBT_pamNotRoot */

/* LASIsLockOwnerEval */
#define ACLERR6700	6700		/* wrong attribute */
#define ACLERR6710	6710		/* bad comparator */
#define ACLERR6720	6720		/* wrong attribute pattern */

/* kerberos & gssapi */
#define ACLERR6800      6800            /* no request object */
#define ACLERR6801      6801            /* no auth-db name */
#define ACLERR6802      6802            /* no auth-db type or params */
#define ACLERR6803      6803            /* auth-db is not kerberos */
#define ACLERR6804      6804            /* authorization header not there */
#define ACLERR6805      6805            /* no session object */
#define ACLERR6806      6806            /* bad authorization header */
#define ACLERR6807      6807            /* can't decode authorization header */
#define ACLERR6808      6808            /* server can't get credentials */
#define ACLERR6809      6809            /* cannot obtain user name */

/* Define error return codes */
#define ACLERRNOMEM	-1		/* insufficient dynamic memory */
#define ACLERROPEN	-2		/* file open error */
#define ACLERRDUPSYM	-3		/* duplicate symbol */
#define ACLERRSYNTAX	-4		/* syntax error */
#define ACLERRUNDEF	-5		/* undefined symbol */
#define ACLERRADB	-6		/* authentication DB access error */
#define ACLERRPARSE	-7		/* ACL parsing error */
#define ACLERRNORLM	-8		/* missing authentication realm */
#define ACLERRIO	-9		/* IO error */
#define ACLERRINTERNAL	-10		/* internal processing error */
/* #define ACLERRFAIL	-11 */	/* defined in include/public/nsacl/acldef.h */
#define ACLERRINVAL	-12		/* invalid argument */
#define ACLERRCONFIG	-13		/* auth realms don't math acl */

#include "nserror.h"

#ifndef PUBLIC_NSACL_ACLDEF_H
#include "public/nsacl/acldef.h"
#endif /* !PUBLIC_NSACL_ACLDEF_H */

NSPR_BEGIN_EXTERN_C

/* Functions in aclerror.c */
NSAPI_PUBLIC extern void aclErrorFmt(NSErr_t * errp,
                    char * msgbuf, int maxlen, int maxdepth);

NSPR_END_EXTERN_C

#endif /* __aclerror_h */