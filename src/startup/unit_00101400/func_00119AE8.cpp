typedef int s32;
typedef unsigned char u8;
typedef long long s64;

struct E { s64 key; s32 id; s32 val; };
struct Elem { char pad[0x178]; s32 f178; char pad2[4]; s32 f180; };
struct Obj { char pad[0x170]; s32 f170; s32 f174; s32 f178; };

extern "C" s32 D_00622F4C;
extern "C" Elem *func_003EEC70(void *arg0, s32 arg1);
extern "C" void func_003EF348(void *arg0, char *arg1);
extern "C" void func_003EF388(void *arg0);
extern "C" void func_00444440(void *arg0, s64 arg1);
extern "C" void func_00445880(void *arg0, s32 arg1);

extern "C" void func_00119AE8(void *arg0) {
    s32 base = D_00622F4C;
    s32 i = 0;
    u8 *a2 = (u8 *)base + 0x38BF8;
    E *p = (E *)((char *)base + 0x38C28);
    ((Obj *)arg0)->f170 = a2[0x29];
    ((Obj *)arg0)->f174 = a2[0x2A];
    func_003EF348(arg0, (char *)base + 0x38C00);
    func_003EF388(arg0);
    do {
        Elem *s0 = func_003EEC70(arg0, i);
        if (i == 0) {
            s0->f180 = 1;
        } else {
            func_00444440(s0, p->key);
            func_00445880(s0, p->id);
            s0->f180 = 0;
        }
        s32 v = p->val;
        p++;
        i++;
        s0->f178 = v;
    } while (i < 6);
    ((Obj *)arg0)->f178 = 1;
}
