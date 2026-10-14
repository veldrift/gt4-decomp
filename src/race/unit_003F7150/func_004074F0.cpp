typedef int s32;

extern "C" void func_004074F0(s32 *arg0) {
    s32 delta;
    s32 *p1;
    s32 *p2;
    s32 *p3;
    s32 *p4;

    if (arg0 == 0) {
        return;
    }
    if ((s32 *)arg0[0] == arg0) {
        return;
    }
    delta = (s32)arg0 - arg0[0];
    arg0[0] = (s32)arg0;
    p1 = &arg0[1];
    p2 = &arg0[2];
    p3 = &arg0[3];
    p4 = &arg0[4];
    *p1 += delta;
    *p2 += delta;
    *p3 += delta;
    *p4 += delta;
    arg0 += 5;
    *arg0 += delta;
}
