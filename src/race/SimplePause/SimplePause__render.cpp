/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

struct Disp {
    char pad0[0x1C];
    float f1C;
    float f20;
    char pad24[0x44 - 0x24];
    u32 f44;
    char pad48[4];
    s32 f4C;
    char pad50[0x64 - 0x50];
    s32 f64;
};
struct Arg { char pad[8]; s32 f8; };

extern Disp *PDISTD__global_font_manager;
extern char D_006A2B48[];
extern char D_006A2B58[];
extern char D_006A2B70[];

extern "C" s32 func_00105818(void *);
extern "C" const char *DisplayRText__getRTextStr(const char *);
extern "C" void func_00490290(void *, const char *);
extern "C" void func_00490700(void *, s32, s32, s32, s32);
extern "C" void func_004909E0(void *, const char *);
extern "C" void func_004A1638(s32);
extern "C" void func_004A2808(s32, float);
extern "C" void func_004A6140(s32, s32, s32, s32);
extern "C" void func_004AA168(u32);

extern "C" void SimplePause__render(void *arg0, Arg *arg1) {
    func_004AA168(0x80000000);
    func_004A1638(6);
    func_004A2808(0x44, 1.0f);
    s32 s1 = arg1->f8;
    s32 v = func_00105818(arg1);
    func_004A6140(0, v * 0x1B6 / 0x1E0, s1, v);
    Disp *d = PDISTD__global_font_manager;
    d->f1C = 640.0f;
    d->f20 = 448.0f;
    func_00490700(PDISTD__global_font_manager, 0, 0x198, 0x280, 0x28);
    func_00490290(PDISTD__global_font_manager, D_006A2B48);
    PDISTD__global_font_manager->f44 = 0x80A7A5A5;
    Disp *d2 = PDISTD__global_font_manager;
    d2->f64 = 5;
    d2->f4C = 1;
    const char *s = DisplayRText__getRTextStr(D_006A2B58);
    if (s == 0) s = D_006A2B70;
    func_004909E0(PDISTD__global_font_manager, s);
}
