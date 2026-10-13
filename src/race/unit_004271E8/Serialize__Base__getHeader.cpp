#define NULL 0

typedef int s32;

typedef struct { char b[16]; } Block16;

void *func_0044D110(void *arg0, void *arg1) {
    *(Block16 *)arg0 = *(Block16 *)arg1;
    return (char *)arg1 + *(s32 *)arg1;
}
