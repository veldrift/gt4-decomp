/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct S { char pad[0xF0]; s32 a; s32 b; char pad2[8]; s32 c; };
extern "C" void mTextFace__virtual_68(S *);
extern "C" s32 func_00231F60(void *, s32);

extern "C" void mScaleBar__virtual_68(S *arg0, void *arg1) {
    arg0->b = 0;
    arg0->a = 0;
    arg0->c = 0;
    mTextFace__virtual_68(arg0);
    func_00231F60(arg1, 0);
}
