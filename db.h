#ifndef DB_H
#define DB_H

#include <stddef.h>
#include <sys/types.h>

typedef struct {
    int id;
    int is_active;
    off_t offset;
} IndexEntry;

typedef struct {
    int fd;
    IndexEntry *index;
    size_t count;
    size_t capacity;
} Database;

int db_open(Database *db, const char *filename);
int db_close(Database *db);

#endif
