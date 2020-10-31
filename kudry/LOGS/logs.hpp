#pragma once

#ifdef DEBUG
    #define LOGS(...)\
        printf(__VA_ARGS__);\
        printf("\t\tin file %s, line %d, function %s\n\n", __FILE__, __LINE__, __func__);
    #define ON_DEBUG(...)\
        __VA_ARGS__
#else
    #define LOGS(...) ;
    #define ON_DEBUG(...)\
        ;
#endif
