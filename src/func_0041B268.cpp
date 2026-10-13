struct VEntry {
    short delta;
    short index;
    int (*fn)(void *);
};

struct Obj {
    char pad[0x20];
    char *vtbl;
};

extern "C" void *func_0041A988(void *self, int i);

extern "C" int func_0041B268(void *self) {
    int sum = 0;
    for (int i = 0; i < 20; i++) {
        Obj *o = (Obj *)func_0041A988(self, i);
        VEntry *e = (VEntry *)(o->vtbl + 0x30);
        sum += e->fn((char *)o + e->delta);
    }
    return sum;
}
