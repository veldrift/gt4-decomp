typedef int s32;
typedef short s16;
struct S0 { s32 unk0; char pad4[8]; s16 unkC; };
struct Src { char pad[0x9C]; s32 unk9C; };
extern "C" s32 func_0046A050(void *, s32);
extern "C" s32 func_0046A510(void *, s32);
extern "C" void func_0046B0A8(S0 *arg0, Src *arg1) {
    arg0->unk0 = (s32)arg1;
    func_0046A510(arg0, arg1->unk9C);
    arg0->unkC = 1;
    if (func_0046A050(arg0, 3) == 0 || func_0046A050(arg0, 4) == 0) {
        arg0->unkC = 0;
    }
}
