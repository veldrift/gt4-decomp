/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta, index; void (*fn)(void *, int); };
struct Elem { char pad[0x40C]; VEntry *vt; char tail[8]; };
struct List { int data[2]; void *vt; };
extern char D_00689728[];
extern "C" void func_00500FE8(void *, int) throw();
extern "C" void func_00574DA8(void *, int);
extern "C" void func_005760A8(void *, int);
extern "C" void func_0057CA38(void *, int);
extern "C" void func_005C1628(void *) throw();
extern "C" void func_0060F1D0(void *, int);
extern "C" void func_0060F270(void *, int);
extern "C" void func_0060F310(void *, int);
static inline void destroyList(List *p) { p->vt = D_00689728; func_0057CA38(p, 0); }
extern "C" void func_00501458(char *o, int flags) {
    Elem *end = (Elem *)(o + 0x47B0);
    func_0060F310(o + 0x8800, 2);
    func_0060F270(o + 0x67D8, 2);
    func_0060F270(end, 2);
    if (o + 0x630 != 0) {
        Elem *begin = (Elem *)(o + 0x630);
        if (begin != end) {
            do {
                --end;
                VEntry *e = end->vt + 1;
                e->fn((char *)end + e->delta, 2);
            } while (begin != end);
        }
    }
    func_0060F1D0(o + 0x218, 2);
    destroyList((List *)(o + 0x1F0));
    destroyList((List *)(o + 0x1E4));
    destroyList((List *)(o + 0x1D8));
    destroyList((List *)(o + 0x1CC));
    func_00500FE8(o + 0xB8, 2);
    func_00574DA8(o + 0x68, 2);
    func_00574DA8(o + 0x38, 2);
    func_00574DA8(o + 8, 2);
    func_005760A8(o, 2);
    if (flags & 1) return func_005C1628(o);
}
