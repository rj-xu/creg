#include <stdarg.h>
#include <stdio.h>

#include "log.h"

const char *G_COLOR[] = {
    ANSI_COLOR_CYAN, ANSI_COLOR_BLUE, ANSI_COLOR_GREEN, ANSI_COLOR_YELLOW, ANSI_COLOR_RED,
};

const char *G_TAG[] = {
    "TRACE", "DEBUG", "INFO ", "WARN ", "ERROR",
};

void vprint(const char *fmt, va_list vlist)
{
    (void)fmt;
    (void)vlist;

    static char s_buf[128] = {0};
    char *p = s_buf;
    while (*fmt++)
    {
        char c = *fmt;

        if (c != '%')
        {
            *p++ = c;
            continue;
        }
    }
}

void print(const char *fmt, ...)
{

    va_list vlist;
    va_start(vlist, fmt);
    vprint(fmt, vlist);
    va_end(vlist);
}

// inline void LogPrint(LogLv_t lv, const char *fmt, ...)
// {
//     if (lv >= LOG_LV)
//     {
//         printf("%s[%s] ", G_COLOR[lv], G_TAG[lv]);

//         va_list args;
//         va_start(args, fmt);
//         vprintf(fmt, args);
//         va_end(args);

//         printf(ENDL);
//     }
// }
