#pragma once

#ifdef DEBUG
    #define LOGS(...)\
        fprintf(stderr, "-----LOG-----\nFILE: %s\nLINE: %d\nFUNC: %s\n~~~~~~~~~~~~~", __FILE__, __LINE__, __func__);\
        fprintf(stderr, __VA_ARGS__);\
        fprintf(stderr, "\n~~~~~~~~~~~~~\n---LOG-END---\n\n");
    #define ON_DEBUG(...)\
        __VA_ARGS__
#else
    #define LOGS(...) ;
    #define ON_DEBUG(...)\
        ;
#endif
