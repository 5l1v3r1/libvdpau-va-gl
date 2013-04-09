/*
 * Copyright 2013  Rinat Ibragimov
 *
 * This file is part of libvdpau-va-gl
 *
 * libvdpau-va-gl distributed under the terms of LGPLv3. See COPYING for details.
 */

#include "watermark.h"

// grayscale 50x24 image with text "va_gl" on it
const char *watermark_data = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xff\xff\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xff\xff\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xff\xff\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xff\xff\0\0\0\0\0\x13\xf7\xfb\x17\0\0\0\0\x0a\xef\xe8\x04\0\x44\xb3\xef\xf5\xc5\x42\0\0\0\0\0\0\0\0\0\0\0\0\0\x22\xb1\xf3\xeb\x97\x09\xff\xff\0\0\0\xff\xff\0\0\0\0\0\0\xa6\xff\x70\0\0\0\0\x62\xff\x8a\0\0\xff\xff\xff\xff\xff\xf9\x32\0\0\0\0\0\0\0\0\0\0\0\x13\xe5\xff\xff\xff\xff\xac\xff\xff\0\0\0\xff\xff\0\0\0\0\0\0\x40\xff\xcc\0\0\0\0\xca\xff\x27\0\0\xaa\x31\x06\x21\xad\xff\xa6\0\0\0\0\0\0\0\0\0\0\0\x8a\xff\xde\x3e\x0b\x3e\xdf\xff\xff\0\0\0\xff\xff\0\0\0\0\0\0\0\xd9\xff\x28\0\0\x31\xff\xc4\0\0\0\0\0\0\0\x14\xff\xe1\0\0\0\0\0\0\0\0\0\0\0\xd7\xff\x4b\0\0\0\x4c\xff\xff\0\0\0\xff\xff\0\0\0\0\0\0\0\x74\xff\x83\0\0\x98\xff\x62\0\0\x02\x73\xce\xf4\xff\xff\xff\xf8\0\0\0\0\0\0\0\0\0\0\0\xf7\xff\x0f\0\0\0\x10\xff\xff\0\0\0\xff\xff\0\0\0\0\0\0\0\x14\xf8\xdd\x01\x0c\xf2\xf2\x0b\0\0\x8d\xff\xff\xff\xff\xff\xff\xff\0\0\0\0\0\0\0\0\0\0\0\xf7\xff\x0f\0\0\0\x10\xff\xff\0\0\0\xff\xff\0\0\0\0\0\0\0\0\xa8\xff\x3b\x67\xff\x9c\0\0\0\xec\xff\x5d\x11\x02\x11\xff\xff\0\0\0\0\0\0\0\0\0\0\0\xd7\xff\x4b\0\0\0\x4b\xff\xff\0\0\0\xff\xff\0\0\0\0\0\0\0\0\x42\xff\x97\xce\xff\x39\0\0\0\xed\xff\x4f\x06\x21\xab\xff\xff\0\0\0\0\0\0\0\0\0\0\0\x8b\xff\xdd\x3c\x0a\x3c\xdd\xff\xff\0\0\0\xff\xff\0\0\0\0\0\0\0\0\x01\xda\xf7\xff\xd6\0\0\0\0\xa4\xff\xff\xff\xff\xae\xff\xff\0\0\0\0\0\0\0\0\0\0\0\x15\xe6\xff\xff\xff\xff\xaf\xff\xfa\0\0\0\xff\xff\0\0\0\0\0\0\0\0\0\x76\xff\xff\x74\0\0\0\0\x11\xa3\xec\xee\x9d\x0b\xff\xff\0\0\0\0\0\0\0\0\0\0\0\0\x24\xb3\xf4\xec\x98\x28\xff\xe9\0\0\0\xff\xff\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x6b\xff\xbe\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xaf\x3c\x0d\x18\x64\xf0\xff\x6b\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xff\xff\xff\xff\xff\xff\xff\xff\xff\0\0\xff\xff\xff\xff\xff\xff\xcb\x05\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xff\xff\xff\xff\xff\xff\xff\xff\xff\0\0\x49\xb7\xe5\xf8\xdb\x89\x0d\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
const int watermark_width = 50;
const int watermark_height = 24;
