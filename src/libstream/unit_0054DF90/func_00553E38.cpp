/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blob { long v[24]; };
struct Node { Blob data; char pad[12]; Node *next; };
extern "C" {
void func_00576788(void *);
void func_005767C0(void *);
Node *func_00554070(char *);
void func_00574EE8(void *);
void *memcpy(void *, const void *, unsigned int);
}
static inline void copy(Blob *dst, const Blob *src) { __builtin_memcpy(dst, src, sizeof(Blob)); }
extern "C" void func_00553E38(char *self, Blob *src) {
    void *lock = self + 0x2200;
    func_00576788(lock);
    Node *node = func_00554070(self);
    if (node) {
        copy(&node->data, src);
        ++*(int *)(self + 0x68);
        node->next = 0;
        **(Node ***)(self + 0xE0) = node;
        *(Node ***)(self + 0xE0) = &node->next;
        func_00574EE8(self + 0x2230);
    }
    func_005767C0(lock);
}
