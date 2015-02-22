#ifndef _FRISK_CONFIG_H
#define _FRISK_CONFIG_H

/*
 ** This header defines common utilities that are used throughout Frisk.
 */

/*
 ** Frisk version is FRISK_VERSION_MAJOR.FRISK_VERSION_MINOR.FRISK_VERSION_FIX
 ** For example, if current version is 1.3.52, it means that the major version is 1,
 ** the minor version is 3, and there have been 52 fixes for version 1.3.
 */
#define FRISK_VERSION_MAJOR   0
#define FRISK_VERSION_MINOR   1
#define FRISK_VERSION_FIX     0

/*
 ** When represented as a 32-bit number, the Frisk version has allocated the following:
 ** first 8 bits for the major version (256 possible major versions)
 ** next 10 bits for the minor version (~1024 minor versions)
 ** next 14 bits for fix (~16k fixes)
 */

#define FRISK_VERSION 

#endif /* _FRISK_CONFIG_H */
