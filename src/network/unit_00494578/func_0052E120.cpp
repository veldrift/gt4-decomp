struct Obj { int zero; volatile int pos; int eight; volatile int size; char *base; volatile int cur; };
extern "C" int func_0052E120(Obj *o) {
    char *p = o->base + o->pos;
    *(int *)p = 0;
    *(int *)(p + 4) = 0;
    int pos = o->pos;
    int size = o->size;
    pos += 8;
    o->cur = (int)p;
    size += 8;
    o->pos = pos;
    o->size = size;
    return 0;
}
