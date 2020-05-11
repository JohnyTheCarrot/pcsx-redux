/***************************************************************************
 *   Copyright (C) 2020 PCSX-Redux authors                                 *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.           *
 ***************************************************************************/

#include <memory.h>

#include "common/compiler/stdint.h"
#include "openbios/kernel/flushcache.h"
#include "openbios/shell/shell.h"

extern uint8_t _binary_shell_bin_start[];
extern uint8_t _binary_shell_bin_end[];

int startShell(uint32_t arg) {
    memcpy((uint32_t *) 0x80030000, _binary_shell_bin_start, _binary_shell_bin_end - _binary_shell_bin_start);
    flushCache();
    return ((int(*)(int)) 0x80030000)(arg);
}