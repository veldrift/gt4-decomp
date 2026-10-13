struct VEntry { short delta; short index; int (*fn)(void *); };
struct Obj { int unk0; VEntry *vt; };
struct Owner { char pad[0x10]; char *p; };
extern "C" void func_0015F3E0(void *, void *);
extern "C" void func_0015F388(void *, int);
extern "C" void MGame__incTotalPrizeMoney(void *, void *arg1, int count, Obj **arg3) {
    if (count > 0) {
        Owner *buf[4];
        func_0015F3E0(buf, arg1);
        char *p = buf[0]->p + 0x348;
        Obj *o = *arg3;
        VEntry *e = (VEntry *)((char *)o->vt + 0x58);
        *(long *)((char *)p + 0x48) += e->fn((char *)o + e->delta);
        func_0015F388(buf, 2);
    }
}
