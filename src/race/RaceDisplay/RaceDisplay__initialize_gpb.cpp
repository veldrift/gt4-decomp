/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Str4 { char c[4]; };
struct Obj { char pad0[4]; s32 unk4; };
extern Obj D_00621518;
extern unsigned int PDISTD__LOCALE;
extern const Str4 D_006A0420;
extern const char D_006A0428[];
extern const char D_006A0440[];
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" char *func_00329F50(char *, int, const char *);
extern "C" void *func_0048EDA0(unsigned int);
extern "C" void func_0057DA20(char *, const char *, ...);
extern "C" void func_0048F320(void *, const char *);
extern "C" void func_0048F5B0(void *, s32);
extern "C" void func_0039B298(void);

extern "C" void RaceDisplay__initialize_gpb(void)
{
    if (D_00621518.unk4 == 0) {
        char path[0x80];
        char name[0x80];
        *(Str4 *)name = D_006A0420;
        func_005A48D8(name + 4, 0, 0x7C);
        func_00329F50(name, 0x80, D_006A0428);
        func_0057DA20(path, D_006A0440, name, func_0048EDA0(PDISTD__LOCALE));
        func_0048F320(&D_00621518, path);
        func_0048F5B0(&D_00621518, (s32)func_0039B298);
    }
}
