/* compiler: ee-gcc2.96-as2004 */
typedef unsigned long long U64 __attribute__((aligned(4)));
struct Result { char pad[0x84]; int code; };
struct Obj { void *handle; char timer[8]; U64 addr; char data[0x200]; int size; int pad; int count; void (*callback)(Result *); };
extern Result D_00863830;
extern "C" void func_00520E60(void *) throw();
extern "C" int func_00520F90(void *, U64, int, void *, int, int *) throw();
extern "C" void func_0053A890(void *, unsigned int *);
extern "C" int func_0053A860(void *);
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" int func_00521A58(Obj *p) {
    unsigned int time;
    int sent = 0;
    char *timer = p->timer;
    if (p->callback) {
        func_0053A890(timer, &time);
        if (time >= 501) {
            func_00520F90(p->handle, p->addr, 0x35, p->data, p->size, &sent);
            func_0053A860(timer);
            p->count++;
        }
        if (p->count == 60) {
            Result *r = &D_00863830;
            func_005A48D8(r, 0, 0x88);
            r->code = 0xc358;
            p->callback(r);
            func_00520E60(p->handle);
            func_005A48D8(p, 0, 0x224);
        }
    }
    return 0;
}
