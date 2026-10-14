typedef int s32;
typedef float f32;

extern "C" s32 func_00106298(char *arg0);
extern "C" s32 func_001062B8(void *arg0);

extern char D_006184D0[];

extern "C" void mRenderContextPS2__virtual_62(void *arg0, f32 *arg1, f32 *arg2) {
    char *g = D_006184D0;
    f32 sx = (f32)func_00106298(g) / 640.0f;
    f32 sy = (f32)func_001062B8(g) / 480.0f;
    arg1[0] = arg2[0] * sx;
    arg1[1] = arg2[1] * sy;
    arg1[2] = arg2[2] * sx;
    arg1[3] = arg2[3] * sy;
}
