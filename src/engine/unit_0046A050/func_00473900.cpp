typedef int s32;

struct Elem {
    char pad0[8];
    s32 k8;
    char pad1[0x3C - 0xC];
};

extern char D_0061850C[];
extern char PDISTD__global_font_manager[];

extern "C" void func_004732F0(void *a0, float *a1, float *a2);
extern "C" s32 func_00105818(void *p);
extern "C" void func_00490700(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);

extern "C" void func_00473900(void *arg0, float x0, float y0, float dx, float dy) {
    float pos[3];
    float v1[3];
    float v2[3];
    float a;
    float b;
    float c;
    float d;
    float f20;
    float f3;
    s32 idx;
    char *base;
    Elem *e;
    s32 r;
    float dxv;
    float dyv;
    pos[0] = x0;
    pos[1] = y0;
    pos[2] = 0.0f;
    func_004732F0(arg0, v1, pos);
    a = x0 + dx;
    b = y0 + dy;
    pos[0] = a;
    pos[1] = b;
    pos[2] = 0.0f;
    func_004732F0(arg0, v2, pos);
    base = D_0061850C;
    idx = *(s32 *)(base + 0x78);
    e = (Elem *)(base + idx * 0x3C);
    f20 = 640.0f / (float)e->k8;
    r = func_00105818(e);
    f3 = 480.0f / (float)r;
    dxv = v2[0] - v1[0];
    dyv = v2[1] - v1[1];
    func_00490700(*(s32 *)PDISTD__global_font_manager, (s32)(v1[0] * f20), (s32)(v1[1] * f3), (s32)(dxv * f20), (s32)(dyv * f3));
}
