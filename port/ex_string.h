#ifndef EX_STRING_H
#define EX_STRING_H

#pragma once
#include <stdlib.h>

// paths
#define _MAX_PATH 260
#define _MAX_FNAME 256
#define _MAX_EXT 256
#define _MAX_DRIVE 3
void _splitpath(const char *path, char *drive, char *dir, char *fname, char *ext);
void _makepath(char *path, const char *drive, const char *dir, const char *fname, const char *ext);

// case-insensitive comparisons
int stricmp(const char *string1, const char *string2);
int strnicmp(const char *string1, const char *string2, size_t count);
int memicmp(const void *buffer1, const void *buffer2, size_t count);

// in-place modification
char *strupr(char *str);
char *strlwr(char *str);
char *strrev(char *str);

#endif // EX_STRING_H