/*
 * Copyright (c) 2020 Ingo Albrecht
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 */

typedef signed char      int8_t;
typedef signed int       int16_t;
typedef signed long      int32_t;

typedef unsigned char      uint8_t;
typedef unsigned int       uint16_t;
typedef unsigned long      uint32_t;

typedef signed int   intptr_t;
typedef unsigned int uintptr_t;

typedef signed long   intmax_t;
typedef unsigned long uintmax_t;

#define INT8_MIN   (-128)
#define INT16_MIN  (-32767-1)
#define INT32_MIN  (-2147483647-1)
#define INT8_MAX   (127)
#define INT16_MAX  (32767)
#define INT32_MAX  (2147483647)
#define UINT8_MAX  (255)
#define UINT16_MAX (65535)
#define UINT32_MAX (4294967295)

#define INTPTR_MIN  (-32767-1)
#define INTPTR_MAX  (32767)
#define UINTPTR_MAX (65535)

#define INTMAX_MIN  (-2147483647-1)
#define INTMAX_MAX  (2147483647)
#define UINTMAX_MAX (4294967295)

#ifdef __STDINT_TEST
#include <stdio.h>
int main(void) {
	printf("sizeof(int8_t)    = %d\n", sizeof(int8_t));
	printf("sizeof(int16_t)   = %d\n", sizeof(int16_t));
	printf("sizeof(int32_t)   = %d\n", sizeof(int32_t));
	printf("sizeof(uint8_t)   = %d\n", sizeof(uint8_t));
	printf("sizeof(uint16_t)  = %d\n", sizeof(uint16_t));
	printf("sizeof(uint32_t)  = %d\n", sizeof(uint32_t));
	printf("sizeof(intptr_t)  = %d\n", sizeof(intptr_t));
	printf("sizeof(uintptr_t) = %d\n", sizeof(uintptr_t));
	printf("sizeof(intmax_t)  = %d\n", sizeof(intmax_t));
	printf("sizeof(uintmax_t) = %d\n", sizeof(uintmax_t));
#define SL(v) ((signed long)(v))
#define UL(v) ((unsigned long)(v))
	printf("INT8_MIN  = %ld\n", SL(INT8_MIN));
	printf("INT16_MIN = %ld\n", SL(INT16_MIN));
	printf("INT32_MIN = %ld\n", SL(INT32_MIN));
	printf("INT8_MAX  = %ld\n", SL(INT8_MAX));
	printf("INT16_MAX = %ld\n", SL(INT16_MAX));
	printf("INT32_MAX = %ld\n", SL(INT32_MAX));
	printf("UINT8_MAX  = %lu\n", UL(UINT8_MAX));
	printf("UINT16_MAX = %lu\n", UL(UINT16_MAX));
	printf("UINT32_MAX = %lu\n", UL(UINT32_MAX));
	return 0;
}
#endif
