typedef int s32;

typedef struct { char b[32]; } Block32;

void func_00335DD8(void *arg0, s32 arg1) {
    *(s32 *)((char *)arg0 + 0x198) = arg1;
    *(Block32 *)((char *)arg0 + 0x1A0) = *(Block32 *)((char *)arg0 + 0x170);
    *(s32 *)((char *)arg0 + 0x1C0) = *(s32 *)((char *)arg0 + 0x190);
}
