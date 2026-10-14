typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

struct Node {
    u8 *data;
    s32 pad4;
    Node *next;
};
struct Bucket {
    s32 pad0;
    Node *head;
};
struct Table {
    char pad0[0x3C];
    u32 count;
    u32 len;
    char pad44[4];
    Bucket *buckets;
};
struct Cb {
    u32 unk0;
    s32 (*fn)(u8 *, s32, s32);
    s32 unk8;
};
struct Crc {
    u32 v;
    u32 pad;
};

extern Crc D_0064A568[];
extern "C" s32 func_00538B08(u8 **, unsigned long);
extern "C" s32 func_00538C68(u8 **);

extern "C" s32 func_005117F8(Table *t, Cb *cb, u32 *out)
{
    s32 (*fn)(u8 *, s32, s32) = 0;
    u32 i, j, index;
    Node *n;
    if (t == 0 || out == 0) {
        return 1;
    }
    if (cb != 0) {
        fn = cb->fn;
    }
    u32 crc = 0;
    if (cb != 0) {
        u8 *buf = 0;
        func_00538B08(&buf, cb->unk0);
        if (buf == 0) {
            return 2;
        }
        for (i = 0; i < t->count; i++) {
            for (n = t->buckets[i].head; n != 0; n = n->next) {
                j = fn(buf, *(s32 *)n, cb->unk8);
                u8 *p = buf;
                while (j != 0) {
                    index = (crc >> 24) ^ *p++;
                    crc <<= 8;
                    crc ^= D_0064A568[index].v;
                    j--;
                }
            }
        }
        func_00538C68(&buf);
    } else {
        for (i = 0; i < t->count; i++) {
            for (n = t->buckets[i].head; n != 0; n = n->next) {
                u8 *p = n->data;
                for (j = 0; j < t->len; j++) {
                    index = (crc >> 24) ^ *p++;
                    crc <<= 8;
                    crc ^= D_0064A568[index].v;
                }
            }
        }
    }
    *out = crc;
    return 0;
}
