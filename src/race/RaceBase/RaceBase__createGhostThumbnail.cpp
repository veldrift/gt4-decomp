/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short delta; short index; void (*fn)(void *, void *); };
extern "C" void RaceBase__createGhostThumbnail(char *self, char *out) {
    Entry *e = (Entry *)(*(char **)(self + 0x64) + 0x1a8);
    e->fn(self + e->delta, out);
    bool flag = false;
    char **cars = *(char ***)(*(char **)(*(char **)(self + 0x6c) + 0x60) + 8);
    int score = *(int *)(cars[0] + 0x11e4);
    int mode = *(int *)(cars[1] + 0x3440);
    *(int *)(out + 0xd4) = 0;
    *(int *)(out + 0xd0) = score;
    if (mode == 1 || mode == 3) flag = true;
    *(bool *)(out + 0xe0) = flag;
    void (*cb)(void *, void *) = *(void (**)(void *, void *))(self + 0xd20);
    if (cb) cb(out, *(void **)(self + 0xd24));
}
