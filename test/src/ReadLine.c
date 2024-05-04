#include "ReadLine.h"

/**
 * [ https://stackoverflow.com/questions/52984551/using-fgets-with-realloc ],
 * [ https://github.com/Brahvim/College-C-Assignments/blob/26934f9777473ebb2a759f2f17f9715820ffa46f/ReadLine.c#L7 ].
 */
void clear_stdin(void) {
    // Correction from last semester's version - I should've used an `int`!
    for (int c; !((c = getchar()) == '\n' || c == EOF);)	// FlawFinder: Ignore. Why? Because I don't know any boundary either!
        ;													// Just trying to clear a buffer, dear linter.
}

char* read_line(const size_t p_factor, size_t *p_out_size) {
    size_t size = 5; // ...Buffer's current size?
    size_t read_size = 0; // How filled is the buffer?!
    char *line = malloc(size);

    if (!line) {
        perror("`read_line()` failed to allocate memory.");
        return NULL;
    }

    for (int c = fgetc(stdin); !(c == EOF || c == '\n'); c = fgetc(stdin)) { // FlawFinder: Ignore. We can't do it here either...
        line[read_size] = c;
        ++read_size;

        if (read_size == size) {
            size += p_factor;
            char *reallocated = realloc(line, size);

            if (!reallocated) {
                perror("`read_line()` failed to re-allocate memory.");
                return line;
            }

            line = reallocated;
        }
    }

    // Tell 'em the size. TELL 'EM!:
    *p_out_size = read_size;

    // We re-allocate to make sure we have a string of the perfect size:
    line = realloc(line, read_size + 1);
    line[read_size] = '\0';

    return line;
}
