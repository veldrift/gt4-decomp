typedef int s32;
struct P8 { char pad[8]; char **f8; };
struct Mid { char pad[0x60]; P8 *f60; char pad1[0x70 - 0x64]; void *f70; };
struct Self { char pad[0x6C]; Mid *mid; };
extern "C" void func_003C0700(void *);
extern "C" s32 func_00444440(void *, long);
extern "C" s32 func_00445880(void *, s32);
extern "C" long SPEC_DATABASE__RaceSpec__getEnemyCode(void *, s32);
extern "C" long func_00447458(void *, s32);

extern "C" void func_0011C138(Self *arg0) {
    Mid *m = arg0->mid;
    void *spec = m->f70;
    long a = SPEC_DATABASE__RaceSpec__getEnemyCode(spec, 0);
    long b = func_00447458(spec, 0);
    if (b != -1) b -= 1;
    else b = 0;
    char *obj = *m->f60->f8 + 0x20;
    func_00444440(obj, a);
    func_00445880(obj, (int)b);
    func_003C0700(m);
}
