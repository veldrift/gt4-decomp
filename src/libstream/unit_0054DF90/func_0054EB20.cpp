/* compiler: ee-gcc2.96-nsa-nosib */
typedef int s32;
extern "C" {
int func_0054ED08(void *, s32);
void func_00574EE8(void *);
void func_005A6AB0(void *, void *, s32);
void func_005ADCC0(void *);
void func_005ADCE0(void *);
}
extern void *PDISTD__global_font_manager_;
struct Obj {
    char pad[0x22C];
    s32 f22C;
    s32 f230;
    s32 f234;
    s32 f238;
    s32 f23C;
    char p240[0x320 - 0x240];
    char p320[0x404 - 0x320];
    s32 f404;
};

extern "C" s32 func_0054EB20(Obj *o, void *data, s32 a, s32 b, s32 c) {
    func_0054ED08(o, 0);
    func_005ADCE0(PDISTD__global_font_manager_);
    o->f22C = 1;
    o->f230 = a;
    o->f234 = b;
    o->f238 = c;
    o->f23C = 1;
    if (data != 0) {
        o->f23C = 0;
        func_005A6AB0(o->p240, data, 0x80);
    }
    o->f404 = 2;
    func_005ADCC0(PDISTD__global_font_manager_);
    func_00574EE8(o->p320);
    return 0;
}
