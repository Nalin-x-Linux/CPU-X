/****************************************************************************
*    Copyright © 2014-2015 Xorg
*
*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
****************************************************************************/

/*
* PROJECT CPU-X
* FILE core.h
*/

#ifndef _CORE_H_
#define _CORE_H_

#include "cpu-x.h"
#if HAS_LIBPCI
# include "pci/pci.h"
#endif


/* Static elements provided by libcpuid */
static int call_libcpuid_static(Labels *data);
/* Required: HAS_LIBCPUID */

/* Dynamic elements provided by libcpuid */
static int call_libcpuid_dynamic(Labels *data);
/* Required: HAS_LIBCPUID && root privileges */

/* Elements provided by dmidecode (need root privileges) */
static int call_dmidecode(Labels *data);
/* Required: HAS_DMIDECODE && root privileges */

/* Alternative function if started as regular user (Linux only) */
static int fallback_mode(Labels *data);
/* Required: none */

/* Get CPU multipliers ("x current (min-max)" label) */
static int cpu_multipliers(Labels *data);
/* Required: HAS_LIBCPUID */

/* Find some PCI devices, like chipset and GPU */
static void find_devices(Labels *data);
/* Required: HAS_LIBPCI */

/* Retrieve GPU temperature */
static int gpu_temperature(Labels *data);
/* Required: none */


#endif /* _CORE_H_ */
