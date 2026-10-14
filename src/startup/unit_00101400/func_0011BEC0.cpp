typedef int s32;
struct VEnt { short adj; short pad; s32 (*fn)(void *); };
struct Vt { char pad[0x98]; VEnt e98; };
struct Self { char pad[0x12C]; Vt *vt; char pad2[0x130 - 0x130]; };
extern char D_00622F4C_[];
extern s32 D_00622F4C;
extern "C" void func_003BB440(void *, s32);
extern "C" void RacePlayerSpec__createEquipments(void *, long, int, int);
extern "C" s32 SPEC_DATABASE__RaceSpec__getEnemyCode(void *, s32);
extern "C" long func_00447458(void *, s32);

extern "C" void func_0011BEC0(Self *arg0) {
    func_003BB440(arg0, D_00622F4C + 0x44);
    VEnt *e = &arg0->vt->e98;
    void *o = (void *)e->fn((char *)arg0 + e->adj);
    s32 a = SPEC_DATABASE__RaceSpec__getEnemyCode(o, 0);
    long b = func_00447458(o, 0);
    long r = b - 1;
    if (~b == 0) r = 0;
    RacePlayerSpec__createEquipments((char *)arg0 + 0x130, a, (int)r, 1);
}
