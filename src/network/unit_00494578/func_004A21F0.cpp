/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"
struct Node { Node *next; int id; };
struct Lock { long value; char pad[0x38]; Node *head; };
struct Scratch { char pad[0x50]; Lock lock; };
extern "C" int func_005ADB90();
extern "C" int func_005ADBC0();
extern "C" void func_005ADBF0(int);
extern "C" int func_005B72A8();
extern "C" int func_005B72F8();
extern "C" void func_004A21F0() {
    Lock *p = &((Scratch *)spr_base())->lock;
    Node local;
    int id = func_005ADB90();
    local.id = id;
    func_005B72A8();
    local.next = p->head;
    p->head = &local;
    long old = p->value;
    func_005B72F8();
    while (old == p->value) func_005ADBC0();
    func_005B72A8();
    Node *prev = 0;
    Node *cur = p->head;
    while (cur) {
        if (cur == &local) {
            if (prev) prev->next = local.next;
            else p->head = local.next;
            break;
        }
        prev = cur; cur = prev->next;
    }
    func_005B72F8();
    func_005ADBF0(id);
}
