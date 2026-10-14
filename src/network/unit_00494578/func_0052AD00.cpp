typedef unsigned short u16;
struct Data { int size; char pad[20]; u16 flags; };
struct Source { char pad[0x40]; u16 count; };
extern "C" int func_0052D9C8(int, Data **, Source *, int);
extern "C" int func_0052AE68(Data *, int);
static inline int add_count(int old, int count) { return old + count; }
extern "C" int func_0052AD00(int arg0, int arg1, u16 arg2, Data *arg3, Source *arg4) {
    Data *sp[4];
    u16 *flags = arg3 ? &arg3->flags : (u16 *)0x10;
    int old = *flags & 0x7ff;
    sp[0] = arg3;
    int size;
    if (arg3) size = arg3->size - 4;
    else size = -4;
    int result = func_0052D9C8(arg1, sp, arg4, size);
    if (result == 0) {
        Data *p = sp[0];
        u16 *f = p ? &p->flags : (u16 *)0x10;
        *f = (*f & 0xf800) | ((add_count(old, arg4->count)) & 0x7ff) | (arg2 & 0xf800);
        func_0052AE68(p, 0);
        return 0;
    }
    return result;
}
