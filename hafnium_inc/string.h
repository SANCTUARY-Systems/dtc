/*
 * Copyright 2020 The Hafnium Authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "hf/check.h"
#include "hf/std.h"

static inline size_t strlen(const char *s)
{
	return strnlen_s(s, RSIZE_MAX);
}

static inline size_t strnlen(const char *s, size_t maxlen)
{
	return strnlen_s(s, maxlen);
}

static inline char *strrchr(const char *s, int c)
{
	size_t cur = strnlen_s(s, RSIZE_MAX);
	CHECK(s[cur] == '\0');
	do {
		if (s[cur] == c) {
			return (char*)(&s[cur]);
		}
	} while ((cur--) > 0);
	return NULL;
}

static inline void *memcpy(void *dest, const void *src, size_t n)
{
	memcpy_s(dest, RSIZE_MAX, src, n);
	return dest;
}

static inline void *memmove(void *dest, const void *src, size_t n)
{
	memmove_s(dest, RSIZE_MAX, src, n);
	return dest;
}

static inline void *memset(void *s, int c, size_t n)
{
	memset_s(s, RSIZE_MAX, c, n);
	return s;
}
