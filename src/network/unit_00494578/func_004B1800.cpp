typedef struct { char b[24]; } Blob24;

struct VEntry { short delta; short index; void (*fn)(void *, void *, int); };
struct Obj { char pad[0xA4]; char *vtbl; };
struct Src { char pad[0x48]; int unk; };

extern "C" int func_004AF6B8(void *o);
extern "C" int func_004AC798(int a);
extern "C" void func_004AC7B8(int a);

extern "C" void *func_004B1800(void *arg0, Obj *arg1, Src *arg2) {
    int buf[6];
    int s1;
    int r;
    VEntry *e;

    s1 = arg2->unk;
    func_004AF6B8(buf);
    buf[0] = 9;
    r = func_004AC798(s1);
    e = (VEntry *)(arg1->vtbl + 0xE0);
    e->fn((char *)arg1 + e->delta, buf, r);
    func_004AC7B8(s1);
    *(Blob24 *)arg0 = *(Blob24 *)buf;
    return arg0;
}
