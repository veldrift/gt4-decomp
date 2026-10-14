/* compiler: ee-gcc2.96-as2004 */
typedef int s32;
typedef unsigned int u32;
typedef unsigned long long Addr __attribute__((aligned(4)));
struct Obj { char p0[0x14C]; s32 count; char p150[8]; s32 state; char p15C[8]; void *handle; };
struct Disp { char pad[8]; s32 (*f8)(void *, s32, void *, void *); s32 (*fC)(void *, s32, s32, void *, void *); };
struct Net { char pad[0x60]; Addr addr; s32 port; };
struct Vt { char pad[0x14]; s32 (*f14)(Obj *, s32); s32 (*f18)(Obj *); s32 (*f1C)(Obj *, s32, s32); };
extern Disp *D_0064B4B8;
extern Net *D_0064B47C;
extern Vt *D_0064B4AC;
extern "C" void func_005319A8(Obj *, s32, Addr, s32) throw();
extern "C" void func_00532628(Obj *, s32) throw();
extern "C" void func_005368F8(s32 arg0, u32 arg1, Obj *arg2) {
    s32 id = arg0 & 0xFFFF;
    if (arg2 == 0) return;
    switch (arg1) {
    case 0: {
        if (arg2->state == 2) {
            s32 sp[4];
            sp[0] = -1;
            if (D_0064B4B8->f8(arg2->handle, id, sp, D_0064B4B8) != 0) return;
            if (D_0064B4B8->fC(arg2->handle, id, sp[0], &D_0064B47C->addr, &D_0064B47C->port) != 0) return;
            arg2->count++;
            func_005319A8(arg2, id, D_0064B47C->addr, D_0064B47C->port);
        }
        if (D_0064B4AC != 0 && D_0064B4AC->f18(arg2) != 0) {
            D_0064B4AC->f1C(arg2, id, 0);
        }
        break;
    }
    case 1:
    case 2:
        if (D_0064B4AC != 0 && D_0064B4AC->f18(arg2) != 0) {
            D_0064B4AC->f14(arg2, id);
        }
        if (arg2->state == 2) func_00532628(arg2, id);
        break;
    default: break;
    }
}
