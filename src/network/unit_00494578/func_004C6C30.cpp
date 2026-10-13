typedef short s16;
typedef int s32;

struct Node_004C6C30 {
    char pad0[0x11];
    unsigned char lvl;
    s16 key;
    char pad1[8];
    struct Node_004C6C30 *next;
};

extern "C" struct Node_004C6C30 *func_004C6C30(struct Node_004C6C30 *arg0, s16 *arg1, s32 *arg2) {
    struct Node_004C6C30 *n = arg0->next;
    s16 bestKey = arg0->key;
    s32 bestLvl = arg0->lvl;
    while (n != 0) {
        s32 lv = n->lvl;
        s16 k = n->key;
        if (bestLvl < lv || (bestLvl == lv && bestKey < k)) {
            bestKey = k;
            bestLvl = lv;
            arg0 = n;
        }
        n = n->next;
    }
    *arg1 = bestKey;
    *arg2 = bestLvl;
    return arg0;
}
