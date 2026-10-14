typedef int s32;
typedef short s16;
typedef unsigned char u8;

struct VA { s16 delta; s16 index; void (*fn)(char *, char *, s32); };
struct VB { s16 delta; s16 index; s32 (*fn)(char *, s32); };
struct VC { s16 delta; s16 index; void (*fn)(char *, char *); };

extern "C" s32 RaceEventQueue__get(char *t, s32 id, s32 *value, s32 remove);
extern "C" s32 RaceEventQueue__check(char *t, s32 key, s32 *out, s32 nth);

extern "C" void RaceResultBase__update(char *arg0, char *arg1) {
    s32 val;
    s32 s2;
    s32 s3;
    s32 r;

    s3 = *(u8 *)(arg1 + 0x901);
    s2 = 0;
    if (s3 != 0) {
        do {
            val = 0;
            r = RaceEventQueue__check(arg1 + 0xF4, 5, &val, s2);
            s2 += 1;
            if (r != 0) {
                VA *a = (VA *)(*(char **)(arg0 + 0xC) + 0x30);
                a->fn(arg0 + a->delta, arg1, val);
                VB *b = (VB *)(*(char **)(arg0 + 0xC) + 0x40);
                if (b->fn(arg0 + b->delta, val) != 0) {
                    if (*(s32 *)arg0 == 0) {
                        VC *c = (VC *)(*(char **)(arg0 + 0xC) + 0x38);
                        c->fn(arg0 + c->delta, arg1);
                    }
                }
            }
        } while (s2 < s3);
    }

    if (*(s32 *)(arg0 + 8) != 0 && RaceEventQueue__get(arg1 + 0xF4, 9, 0, 0) != 0) {
        VA *d = (VA *)(*(char **)(arg0 + 0xC) + 0x30);
        d->fn(arg0 + d->delta, arg1, 0);
        if (*(s32 *)arg0 == 0) {
            VC *f = (VC *)(*(char **)(arg0 + 0xC) + 0x38);
            f->fn(arg0 + f->delta, arg1);
        }
    }
}
