#ifndef _AJ_TARGET_H
#define _AJ_TARGET_H
/**
 * @file WSL target macros and includes
 */
/******************************************************************************
 * Copyright AllSeen Alliance. All rights reserved.
 *
 *    Permission to use, copy, modify, and/or distribute this software for any
 *    purpose with or without fee is hereby granted, provided that the above
 *    copyright notice and this permission notice appear in all copies.
 *
 *    THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 *    WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 *    MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 *    ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 *    WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 *    ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 *    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 ******************************************************************************/

#include <stdlib.h>

#define AJ_EXPORT

#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>

#include <ajtcl/aj_target_platform.h>
#include <ajtcl/aj_target_rtos.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef TRUE
#define TRUE (1)
#endif

#ifndef FALSE
#define FALSE (0)
#endif

#ifndef max
#define max(x, y) ((x) > (y) ? (x) : (y))
#endif

#ifndef min
#define min(x, y) ((x) < (y) ? (x) : (y))
#endif

#define WORD_ALIGN(x) ((x & 0x3) ? ((x >> 2) + 1) << 2 : x)
#define HOST_IS_LITTLE_ENDIAN  1
#define HOST_IS_BIG_ENDIAN     0
#define HOST_ENDIANESS          AJ_LITTLE_ENDIAN

#ifndef NDEBUG
extern uint8_t dbgCONFIGUREME;
extern uint8_t dbgINIT;
extern uint8_t dbgNET;
extern uint8_t dbgTARGET_CRYPTO;
extern uint8_t dbgTARGET_NVRAM;
extern uint8_t dbgTARGET_SERIAL;
extern uint8_t dbgTARGET_TIMER;
extern uint8_t dbgTARGET_UTIL;
#endif

#define AJ_ASSERT(x) assert(x)


/*
 * AJ_Reboot() is a NOOP on this platform
 */
#define _AJ_Reboot() do { } while (0)
#define AJ_Reboot() _AJ_Reboot()

#define AJ_CreateNewGUID AJ_RandBytes

#define AJ_GetDebugTime(x) AJ_ERR_RESOURCES

#if (__GNUC__ >= 4) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 1))
#define AJ_DEPRECATED(func) func __attribute__((deprecated)) /**< mark a function as deprecated in gcc. */
#else
#define AJ_DEPRECATED(func) func /**< not all gcc versions support the deprecated attribute. */
#endif

#ifdef __cplusplus
}
#endif

#endif
