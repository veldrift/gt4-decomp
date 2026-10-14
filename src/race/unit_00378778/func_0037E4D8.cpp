/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32; typedef long s64; typedef signed char s8; typedef float f32;
#define M2C_FIELD(o,T,n) (*(T)((char *)(o)+(n)))
extern "C" {
void func_0036F710(void *,float,float,float,float) throw();
float func_0036F778(void *,float) throw();
void func_0036F948(void *,float,float,float,float) throw();
void func_0036F968(void *,float) throw(); void func_0036F970(void *,float) throw(); void func_0036F978(void *,float) throw();
void func_00378CB8(void *,void *) throw(); float func_00578598(void *);
void *func_005A48D8(void *,int,unsigned);
}
static inline void put(float *p,float v){*p=v;}
extern "C" void func_0037E4D8(char *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 fparg0) {
    struct StackFrame_0037E4D8 { s8 pad0[0x20]; } sp_;
    f32 temp_f0;
    void *temp_s5;
    void *temp_s0;

    temp_s5 = M2C_FIELD(arg0, void **, 0x184);
    func_00378CB8(arg0,arg1);
    M2C_FIELD(arg0, s32 *, 0x188) = arg5;
    M2C_FIELD(arg0, s32 *, 0x148) = 9;
    M2C_FIELD(arg0, s32 *, 0x18C) = arg2;
    M2C_FIELD(arg0, s32 *, 0x190) = arg3;
    M2C_FIELD(arg0, s32 *, 0x194) = arg4;
    M2C_FIELD(arg0, f32 *, 0x198) = fparg0;
    M2C_FIELD(arg0, s32 *, 0x180) = 1;
    func_005A48D8(arg0 + 0x19C, 0, 0xC);
    func_005A48D8(arg0 + 0x1A8, 0, 0xC);
    func_005A48D8(arg0 + 0x1B4, 0, 0xC);
    M2C_FIELD(arg0, s32 *, 0x1C4) = 0;
    M2C_FIELD(arg0, s32 *, 0x1C8) = 2;
    put((float *)(arg0+0x1CC),0.0f);
    put((float *)(arg0+0x1D0),5.0f);
    put((float *)(arg0+0x1D4),1.0f);
    put((float *)(arg0+0x1D8),5.0f);
    put((float *)(arg0+0x1EC),0.0f);
    put((float *)(arg0+0x1F0),0.0f);
    put((float *)(arg0+0x1F4),60.0f);
    M2C_FIELD(arg0, s32 *, 0x1C0) = 1;
    if (func_00578598(temp_s5) < 0x1.6666660000000p-1f) {
        M2C_FIELD(arg0, s32 *, 0x1C0) = 0;
    }
    temp_s0 = arg0 + 0x1FC;
    func_0036F710(((s8 *)&sp_), 0x1.47ae14p-7f, 0x1.ba5e340000000p-6f, 0x1.47ae14p-7f, 0x1.6872b0p-6f);
    func_0036F710(arg0 + 0x228, 0x1.999998p-4f, func_00578598(temp_s5) * 0x1.3333320000000p-2f, 1.0f, 0x1.47ae14p-7f);
    M2C_FIELD(arg0, f32 *, 0x244) = (f32) (func_0036F778(((s8 *)&sp_), func_00578598(temp_s5)) * 0x1.9999980000000p-1f);
    M2C_FIELD(arg0, f32 *, 0x248) = (f32) (func_0036F778(((s8 *)&sp_), func_00578598(temp_s5)) * 0x1.9999980000000p-1f);
    func_0036F948(temp_s0, 0x1.999998p-4f, 0x1.3333320000000p-2f, 1.0f, 0x1.47ae14p-7f);
    func_0036F968(temp_s0, 0x0.0p+0f);
    func_0036F970(temp_s0, 0x0.0p+0f);
    func_0036F978(temp_s0, 0x1.0000000000000p-1f);
    if (func_00578598(temp_s5) < 0x1.3333320000000p-1f) {
        func_0036F948(temp_s0, 0x1.999998p-4f, func_00578598(temp_s5) * 0x1.3333320000000p-2f, 1.0f, 0x1.47ae14p-7f);
        func_0036F968(temp_s0, (func_00578598(temp_s5) * 0x1.4000000000000p+5f) - 0x1.4000000000000p+4f);
        func_0036F970(temp_s0, (func_00578598(temp_s5) * 0x1.4000000000000p+5f) - 0x1.4000000000000p+4f);
        func_0036F978(temp_s0, (func_00578598(temp_s5) * 0x1.0000000000000p-1f) + 0x1.9999980000000p-3f);
    }
    M2C_FIELD(arg0, f32 *, 0x224) = 0x0.0p+0f;
    if (func_00578598(temp_s5) < 0x1.3333320000000p-3f) {
        M2C_FIELD(arg0, f32 *, 0x224) = (f32) ((func_00578598(temp_s5) * 0x1.9000000000000p+7f) - 0x1.9000000000000p+6f);
    }
    M2C_FIELD(arg0, f32 *, 0x24C) = (f32) ((func_00578598(temp_s5) * 0x1.9999980000000p-3f) + 0x1.0000000000000p-1f);
    M2C_FIELD(arg0, f32 *, 0x250) = (f32) (0x1.0000000000000p+0f - (func_00578598(temp_s5) * 0x1.9999980000000p-3f));
    if (func_00578598(temp_s5) < 0x1.0000000000000p-1f) {
        M2C_FIELD(arg0, f32 *, 0x24C) = 0x1.0000000000000p+0f;
        M2C_FIELD(arg0, f32 *, 0x250) = 0x1.0ccccc0000000p+0f;
    }
    M2C_FIELD(arg0, f32 *, 0x254) = (f32) (func_00578598(temp_s5) - 0x1.0000000000000p-1f);
    if (func_00578598(temp_s5) < 0x1.6666660000000p-1f) {
        M2C_FIELD(arg0, f32 *, 0x254) = 0x1.0000000000000p+0f;
    }
    temp_f0 = func_00578598(temp_s5) * 0x1.4999980000000p+4f;
    M2C_FIELD(arg0, s32 *, 0xE8) = 1;
    M2C_FIELD(arg0, s64 *, 0x168) = (s64) ((M2C_FIELD(arg0, s64 *, 0x168) & (long)(int)0xFF00FFFF) | 0x10000);
    M2C_FIELD(arg0, s32 *, 0x150) = (s32) ((temp_f0 + 0x1.6666660000000p+0f) * 0x1.9000000000000p+6f);
}
