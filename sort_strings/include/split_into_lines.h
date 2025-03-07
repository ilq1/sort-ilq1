#pragma once
char **split_into_lines(char *buffer, size_t buffer_size, long* line_count)
{
    size_t count = 0;
    char *p = buffer;

    for (p = buffer; p < buffer + buffer_size; p++)
    {
        if (*p == '\n')
        {
            *p = '\0';
            count++;
        }
    }
    if (p > buffer && *(p - 1) != '\0')
    {
        count++;
    }

    if (*line_count < count)
    {
        count = *line_count;
    }

    char **lines = malloc(count * sizeof(char *));
    if (!lines)
    {
        return NULL;
    }

    size_t i = 0;
    p = buffer;
    while (p < buffer + buffer_size && i < count)
    {
        lines[i] = p;
        while (p < buffer + buffer_size && *p != '\0'){
            p++;
        }
        p++;
        i++;
    }
    *line_count = count;
    return lines;
}