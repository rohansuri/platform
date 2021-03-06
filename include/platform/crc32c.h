/* -*- Mode: C++; tab-width: 4; c-basic-offset: 4; indent-tabs-mode: nil -*- */
/*
 *     Copyright 2015 Couchbase, Inc
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */

//
// Generate a CRC-32C (Castagnolia)
// CRC polynomial of 0x1EDC6F41
//
// When available a hardware assisted function is used for increased
// performance.
//
#pragma once
#include <platform/visibility.h>
#include <cstddef>
#include <cstdint>

#if defined(__x86_64__) || defined(_M_X64) || defined(_M_IX86)
#define CB_CRC32_HW_SUPPORTED 1
#endif

PLATFORM_PUBLIC_API
uint32_t crc32c(const uint8_t* buf, size_t len, uint32_t crc_in);

// The following methods are used by unit testing to force the calculation
// of the checksum by using a given implementation.
PLATFORM_PUBLIC_API
uint32_t crc32c_sw(const uint8_t* buf, size_t len, uint32_t crc_in);
#ifdef CB_CRC32_HW_SUPPORTED
PLATFORM_PUBLIC_API
uint32_t crc32c_hw(const uint8_t* buf, size_t len, uint32_t crc_in);
PLATFORM_PUBLIC_API
uint32_t crc32c_hw_1way(const uint8_t* buf, size_t len, uint32_t crc_in);
#endif
