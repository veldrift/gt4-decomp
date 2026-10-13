typedef int s32;

struct Node {
    char pad0[8];
    Node *next;    /* 0x8 */
};

struct Obj {
    char pad0[0x24];
    Node *p24;     /* 0x24 */
    Node *p28;     /* 0x28 */
    s32 f2C;       /* 0x2C */
};

extern "C" s32 func_00511C48(struct Obj *arg0) {
    Node *v1 = arg0->p24;

    if (v1 != 0) {
        v1 = v1->next;
    } else {
        Node *a1 = arg0->p28;
        if (a1 != 0 || arg0->f2C != 0) {
            arg0->p28 = 0;
            v1 = a1;
            arg0->f2C = 0;
        }
    }

    arg0->p24 = v1;
    return (v1 != 0) ? 0 : 4;
}
