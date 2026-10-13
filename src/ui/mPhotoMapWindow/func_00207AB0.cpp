typedef int s32;
typedef float f32;

extern "C" s32 func_00206868(s32);
extern "C" void func_0025B498(s32, s32, s32);
extern "C" s32 func_0025C300(s32);
extern "C" s32 func_00265D98(s32);

extern "C" s32 func_00207AB0(s32 arg0, f32 *arg1, f32 *arg2) {
    f32 buf[2];
    s32 count = 0;
    s32 obj = func_00206868(arg0);

    if (obj != 0) {
        do {
            if (func_00265D98(obj) == 0) {
                func_0025B498(obj, (s32)&buf[0], (s32)&buf[1]);

                f32 t = *arg1;
                if (!(buf[0] < t)) {
                    t = buf[0];
                }
                *arg1 = t;

                f32 b1 = buf[1];
                f32 u = *arg2;
                if (!(b1 < u)) {
                    u = b1;
                }
                *arg2 = u;

                count++;
            }
            obj = func_0025C300(obj);
        } while (obj != 0);
    }
    return count;
}
