typedef unsigned short u16;
struct Entry { int state; int *obj; int zero; char pad[0x20]; u16 serial; char tail[0x16]; };
struct Obj { void *parent; int *slots[32]; Entry *entries; char pad[0x3C]; u16 serial; };
extern "C" void func_00526040(Obj *, int *, u16 *);
extern "C" int func_005260A8(Obj *);
extern "C" void func_00529760(int *, int);
extern "C" int func_0052A270(void *,int *);
extern "C" int func_0052A368(void *,int *);
extern "C" void *func_005A48D8(void *,int,unsigned int);
static inline void setIndex(u16 *out, unsigned value) { (void)(*(volatile u16 *)out = value); }
extern "C" void func_00525AF8(Obj *p, int *obj) {
    struct Result { u16 index; int state; } r;
    setIndex(&r.index, 0xFFFE);
    r.state = 0;
    long invalid = 0xFFFE;
    func_00526040(p, &r.state, &r.index);
    unsigned freeSlot = 32;
    if (r.state == 7) {
        int i = func_005260A8(p);
        if (i != invalid) {
            Entry *e = p->entries + i;
            func_005A48D8(e, 0, 0x44);
            e->obj = obj;
            e->state = 2;
            int seq = p->serial + 1;
            e->zero = 0;
            p->serial = seq;
            e->serial = seq;
            func_00529760(obj, i);
            func_0052A270(p->parent, obj);
            return;
        }
        func_0052A368(p->parent, obj);
        return;
    }
    for (unsigned i = 0; i < 32; i++) {
        if (p->slots[i] == obj) return;
        if (p->slots[i] == 0) {
            if (freeSlot == 32) freeSlot = i;
        }
    }
    if (freeSlot != 32) p->slots[freeSlot] = obj;
    else func_0052A368(p->parent, obj);
}
