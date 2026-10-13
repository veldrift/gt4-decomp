typedef int s32;
typedef signed char s8;

struct Text5 { char c[5]; };
struct func_004726B8_Obj;
struct func_004727B8_p;

extern char *D_006187A8;
extern void *D_00624984;
extern "C" const Text5 D_0068E438;
extern char PDISTD__UNIT_MANAGER[];
extern "C" const char *func_00472758(struct func_004726B8_Obj *p);
extern "C" char *func_004727B8(struct func_004727B8_p *p);
extern "C" void func_00490A40(void *a, void *b, s32 c, s32 d, const char *e, char *f, char *g);

extern "C" void func_00127D20(s32 dummy, s32 size, char *buf) {
    char *v = D_006187A8;
    char *s3 = v + 0x4D4;
    s32 s4 = *(s32 *)(v + 0x4D0);
    if (*s3 == 0x2D) {
        *(Text5 *)buf = D_0068E438;
        return;
    }
    const char *s1 = func_00472758((struct func_004726B8_Obj *)PDISTD__UNIT_MANAGER);
    char *b = func_004727B8((struct func_004727B8_p *)PDISTD__UNIT_MANAGER);
    func_00490A40(D_00624984, buf, size, s4, s1, s3, b);
}
