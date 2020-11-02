#pragma once

#ifdef DEBUG
    #define LOGS(...)\
        fprintf(stderr, __VA_ARGS__);\
        fprintf(stderr, "\t\tin file %s, line %d, function %s\n\n", __FILE__, __LINE__, __func__);
    #define ON_DEBUG(...)\
        __VA_ARGS__
#else
    #define LOGS(...) ;
    #define ON_DEBUG(...)\
        ;
#endif
