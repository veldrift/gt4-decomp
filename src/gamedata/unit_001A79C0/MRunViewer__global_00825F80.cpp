typedef int s32;

struct RefCounter;

extern s32 D_00622D50;

extern "C" void func_001A7728(void *arg0, int arg1);
extern "C" void func_001A79C0(void *arg0, void *arg1);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);

extern "C" void MRunViewer__global_00825F80(s32 *arg0) {
    s32 buf[4];

    s32 v = D_00622D50;
    if (v != 0) {
        func_001A79C0(buf, (void *)v);
        if (arg0 != buf) {
            s32 s0 = buf[0];
            if (s0 != 0) {
                func_003285A8((RefCounter *)s0);
            }
            s32 temp_v0 = *arg0;
            if (temp_v0 != 0) {
                func_003285F8((RefCounter *)temp_v0);
            }
            *arg0 = s0;
        }
        func_001A7728(buf, 2);
    }
}
