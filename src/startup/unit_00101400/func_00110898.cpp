typedef int s32;
struct B2 { char a; char b; };
struct Ent { B2 c; char pad[0x7E]; };
struct Z { s32 w[4]; };
struct Cnt { s32 n; };
struct Other { char pad[0x60]; Cnt *cnt; char pad2[0x70 - 0x64]; void *f70; };
struct Obj {
    char pad0[4]; Ent ents[6];
    char pad1[0x304 - 4 - 6 * 0x80]; Z z[5];
    char pad2[0x408 - 0x354]; char name[0x40];
    char pad3[0x454 - 0x448]; s32 w[8];
    char pad4[0x478 - 0x474]; s32 f478;
};
extern B2 D_0068D308;
extern "C" s32 func_004472A0(void *);
extern "C" char *func_005A609C(char *, const char *);

extern "C" void func_00110898(Obj *arg0, Other *arg1) {
    s32 n = arg1->cnt->n;
    for (s32 i = 0; i < n; i++) {
        arg0->ents[i].c = D_0068D308;
        arg0->z[i].w[0] = 0;
        arg0->z[i].w[1] = 0;
        arg0->z[i].w[2] = 0;
        arg0->z[i].w[3] = 0;
        arg0->w[i] = 0x157529FF;
    }
    arg0->f478 = n;
    func_005A609C(arg0->name, (const char *)func_004472A0(arg1->f70));
}
