/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct VEnt { short adj; short pad; void (*fn)(void *, ...); };
struct Vt { char pad[0x90]; VEnt e90; VEnt e98; VEnt eA0; };
struct Self {
    char pad[0x64]; Vt *vt; char pad1[0xA0 - 0x68]; s32 fA0; s32 fA4;
};
extern s32 D_00618498;
extern "C" void func_00576788(s32);
extern "C" void func_005767C0(s32);

extern "C" void func_0010AC20(Self *arg0, s32 arg1) {
    s32 sub = (s32)arg0 + 0x6C;
    func_00576788(sub);
    if (arg1 == 0) {
        arg0->fA4 = 0;
        Vt *vt = arg0->vt;
        arg0->fA0 = 0;
        VEnt *e = &vt->e90;
        e->fn((char *)arg0 + e->adj, D_00618498);
    } else if (arg0->fA4 != 0) {
        Vt *vt = arg0->vt;
        arg0->fA4 = 0;
        VEnt *e = &vt->eA0;
        e->fn((char *)arg0 + e->adj);
    }
    func_005767C0(sub);
}
