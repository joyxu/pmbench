#ifndef __RDTSC_H__
#define __RDTSC_H__
/*
   Copyright (c) 2014, Intel Corporation
   All rights reserved.
  
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:
 
       * Redistributions of source code must retain the above copyright
         notice, this list of conditions and the following disclaimer.
       * Redistributions in binary form must reproduce the above copyright
         notice, this list of conditions and the following disclaimer in the
         documentation and/or other materials provided with the distribution.
       * Neither the name of Intel Corporation nor the names of its
         contributors may be used to endorse or promote products derived from
         this software without specific prior written permission.
   
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.
 */

#ifdef __MSVC__
#error "Need gcc compiler (e.g., mingw32)"
#endif
static inline
unsigned long long rdtsc(void) __attribute__((always_inline));

static inline
unsigned long long rdtscp(void) __attribute__((always_inline));

#if defined(__i386__)
static inline
unsigned long long rdtsc(void) 
{
    unsigned long long val; 

    asm volatile ( "rdtsc" : "=A"(val));

    return val;
}

static inline
unsigned long long rdtscp(void) 
{
    unsigned long long val; 

    asm volatile ( "rdtscp" : "=A"(val));

    return val;
}
#elif defined(__x86_64__)
static inline
unsigned long long rdtsc(void) 
{
    unsigned eax, edx; 

    asm volatile ( "rdtsc" : "=a"(eax), "=d"(edx) );

    return (unsigned long long)eax | (((unsigned long long)edx) << 32);
}

static inline
unsigned long long rdtscp(void) 
{
    unsigned eax, edx; 

    asm volatile ( "rdtscp" : "=a"(eax), "=d"(edx) );

    return (unsigned long long)eax | (((unsigned long long)edx) << 32);
}
#endif

#endif
