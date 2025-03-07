#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
char *file_io(const char* filename,size_t* size)
{
    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        return NULL;
    }

    if (fseek(fp, 0, SEEK_END) != 0)
    {
        fclose(fp);
        return NULL;
    }

    size_t file_size = ftell(fp);
    if (file_size == -1)
    {
        fclose(fp);
        return NULL;
    }

    if (fseek(fp, 0, SEEK_SET) != 0)
    {
        fclose(fp);
        return NULL;
    }

    char *buffer = malloc(file_size + 1);
    if (!buffer)
    {
        fclose(fp);
        return NULL;
    }
    fread(buffer, 1, file_size, fp);
    buffer[file_size] = '\0';
    fclose(fp);
    *size = file_size;
    return buffer;
}


