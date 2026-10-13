typedef int s32;
typedef unsigned int u32;

extern "C" {
extern s32 D_00841B80;                           /* extern */
void func_00576788(s32 a0);                      /* extern */
void func_005767C0(s32 a0);                      /* extern */
void func_00323B30(s32 *a0, s32 *a1);            /* extern */
void func_00323B60(s32 *a0, s32 a1);             /* extern */
void func_003285A8(s32 p);                       /* extern */
void func_003285F8(s32 p);                       /* extern */

void func_00325AE8(s32 arg0, u32 arg1, s32 *arg2) {
    s32 buf[4];
    s32 zero;
    s32 *dst;
    s32 newVal;
    s32 oldVal;
    s32 *pa;
    s32 *pb;
    char *temp;
    s32 key;

    func_00576788(arg0);
    key = *arg2;
    temp = (char *)(arg0 + ((((arg1 >> 3) ^ key) & 0x7FF) * 0xC));
    pa = (s32 *)(temp + 0x30);
    if (*pa == (s32)arg1) {
        pb = (s32 *)(temp + 0x34);
        if (*pb == key) {
            *pa = 0;
            if (pb != &D_00841B80) {
                *pb = D_00841B80;
            }
            dst = (s32 *)(temp + 0x38);
            zero = 0;
            func_00323B30(buf, &zero);
            if (dst != buf) {
                newVal = buf[0];
                if (newVal != 0) {
                    func_003285A8(newVal);
                }
                oldVal = *dst;
                if (oldVal != 0) {
                    func_003285F8(oldVal);
                }
                *dst = newVal;
            }
            func_00323B60(buf, 2);
        }
    }
    func_005767C0(arg0);
}
}
