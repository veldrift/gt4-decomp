typedef int s32;
typedef short s16;
typedef unsigned int u32;

struct Blk {
    s32 a;
    s32 b;
};

extern struct Blk D_0068FF08;
extern struct Blk D_0068FF10;
extern struct Blk D_0068FF18;
extern struct Blk D_0068FF20;

void func_005A48D8(void *, s32, u32);               /* extern */

void func_00158A88(void *arg0) {
    switch (*(s16 *)((char *)arg0 + 0xB0)) {        /* irregular */
    case 1:
        *(struct Blk *)((char *)arg0 + 0xD4) = D_0068FF08;
        return;
    case 2:
        *(struct Blk *)((char *)arg0 + 0xD4) = D_0068FF10;
        return;
    case 3:
        *(struct Blk *)((char *)arg0 + 0xD4) = D_0068FF18;
        return;
    case 4:
        *(struct Blk *)((char *)arg0 + 0xD4) = D_0068FF20;
        return;
    default:
        return func_005A48D8((char *)arg0 + 0xD4, 0, 8);
    }
}
