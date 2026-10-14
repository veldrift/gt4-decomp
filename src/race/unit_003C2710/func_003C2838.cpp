/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct VEntry { s16 delta; s16 index; void (*fn)(void *); };
struct Node { Node *next; char *vt; };
struct List { s32 pad0; Node *head; };
struct Res { char pad[0x18]; s32 f18; };
extern Res *D_00621B44;
extern "C" int func_00499728(Res *);
extern "C" void func_0049CC48(s32);
extern "C" void func_004A1638(s32);
extern "C" void func_004A2808(s32, float);
extern "C" void func_004A28B8(s32, s32);
extern "C" void func_004A29A8(s32);
extern "C" void func_004A53F8(void);
extern "C" void func_004A5400(void);
extern "C" void func_004A7454(void);
extern "C" void func_004AB040(s32);

extern "C" void func_003C2838(List *self) {
    if (self->head) {
        if (D_00621B44) {
            func_00499728(D_00621B44);
            func_0049CC48(D_00621B44->f18);
        }
        func_004A1638(5);
        func_004A1638(4);
        func_004A1638(6);
        func_004A1638(2);
        func_004AB040(0xF);
        func_004A29A8(0);
        func_004A28B8(6, 1);
        func_004A2808(0x68, 1.0f);
        for (Node *n = self->head; n; n = n->next) {
            VEntry *e = (VEntry *)(n->vt + 0x18);
            e->fn((char *)n + e->delta);
        }
        func_004A53F8();
        func_004A7454();
        func_004A5400();
        func_004A29A8(1);
        func_004A1638(0xF);
        func_004AB040(2);
    }
}
