#include <time.h>
#define APPNAME         "qnvme"
#define LEVEL           APPNAME
#define DEBUG

#define CHOP_FILE(str) (strstr(str, "nvmeqemu") == 0 ? str : strstr(str, "nvmeqemu") + 9)

#define LOG_NORM(fmt, ...)    \
    printf("%s: " fmt "\n", LEVEL, ## __VA_ARGS__)
#define LOG_ERR(fmt, ...)    \
    printf("%s-ERR:%s:%d: " fmt "\n", LEVEL, CHOP_FILE(__FILE__), \
        __LINE__, ## __VA_ARGS__)
#ifdef DEBUG
#define LOG_DBG(fmt, ...)    \
    { \
        struct timespec ts; \
        clock_gettime(CLOCK_REALTIME, &ts); \
        printf("%lld.%09lld ", (long long)ts.tv_sec, (long long)ts.tv_nsec); \
        printf("DBG|:%s:%d: " fmt "\n", CHOP_FILE(__FILE__),__LINE__, ## __VA_ARGS__); \
    }
#else
#define LOG_DBG(fmt, ...)
#endif
