#include "db.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int db_open(Database *db, const char *filename) {
    if (db == NULL || filename == NULL) {
        return -1;
    }
    db->fd = open(filename, O_RDWR | O_CREAT, 0644);
    if (db->fd == -1) {
        perror("open");
        return -1;
    }
    db->count = 0;
    db->capacity = 16;
    db->index = malloc(db->capacity * sizeof(IndexEntry));
    if (db->index == NULL) {
        perror("close");
        close(db->fd);
        return -1;
    }
    return 0;
}

int db_close(Database *db) {
    if (db == NULL) {
        return -1;
    }
    free(db->index);
    db->index = NULL;

    if (close(db->fd) == -1) {
        perror("close");
        return -1;
    }
}