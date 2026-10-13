typedef int s32;

struct Node {
    char pad0[4];
    Node *next;    /* 0x4 */
};

struct Obj {
    char pad0[0x24];
    Node *p24;     /* 0x24 */
    Node *p28;     /* 0x28 */
    Node *p2C;     /* 0x2C */
};

extern "C" s32 func_00511D68(Obj *arg0) {
    s32 r = 1;
    if (arg0 != 0) {
        Node *v1 = arg0->p24;
        if (v1 != 0) {
            v1 = v1->next;
        } else {
            Node *a1 = arg0->p2C;
            if (a1 != 0 || arg0->p28 != 0) {
                arg0->p28 = 0;
                v1 = a1;
                arg0->p2C = 0;
            }
        }
        arg0->p24 = v1;
        r = (v1 != 0) ? 0 : 4;
    }
    return r;
}
