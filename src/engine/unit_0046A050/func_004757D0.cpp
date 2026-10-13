typedef int s32;
typedef unsigned int u32;

struct Str;
struct Param;

struct Node {
    char pad0[0x8C];
    Node *next;
};

struct Obj {
    char pad0[0x24];
    Node *head;
};

extern "C" void func_00475870(Obj *self, Param *p);
extern "C" Str *func_0047DD18(Node *n);
extern "C" u32 func_0057F260(const char *s);
extern "C" s32 func_005FBDD0(Str *self, const char *s, u32 pos, u32 n);

extern "C" void func_004757D0(Obj *self, const char *s)
{
    Node *head = self->head;
    if (head != 0) {
        Node *cur = head;
        if (s != 0) {
            while (cur != 0) {
                Str *t = func_0047DD18(cur);
                u32 n = func_0057F260(s);
                if (func_005FBDD0(t, s, 0, n) == 0) {
                    head = cur;
                    break;
                }
                cur = cur->next;
            }
        }
        func_00475870(self, (Param *)head);
    }
}
