#include <stdio.h>
#include <stdlib.h>

/**
 * [ https://stackoverflow.com/questions/52984551/using-fgets-with-realloc ],
 * [ https://github.com/Brahvim/College-C-Assignments/blob/26934f9777473ebb2a759f2f17f9715820ffa46f/ReadLine.c#L7 ].
 */
void clear_stdin(void);
// ...I modified this one:
char* read_line(const size_t factor, size_t *out_size);
