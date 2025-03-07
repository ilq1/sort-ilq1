#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* mmap_io(const char* filename, size_t* size) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        return NULL;
    }
    struct stat sb;
    if (fstat(fd, &sb) == -1) {
        close(fd);
        return NULL;
    }
    *size = sb.st_size;

    void* mapped = mmap(NULL, *size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (mapped == MAP_FAILED) {
        close(fd);
        return NULL;
    }

    char* buffer = malloc(*size + 1);
    if (!buffer) {
        munmap(mapped, *size);
        close(fd);
        return NULL;
    }

    memcpy(buffer, mapped, *size);
    buffer[*size] = '\0';

    munmap(mapped, *size);
    close(fd);
    return buffer;
}
