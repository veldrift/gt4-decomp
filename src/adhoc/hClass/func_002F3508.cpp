/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct Node { char pad0[4]; Node *parent; Node *left; Node *right; };
struct Iter { Node *node; char pad[0xC]; };
struct VEnt { s16 delta; s16 pad; s32 (*fn)(void *, s32); };
struct VEnt0 { s16 delta; s16 pad; s32 (*fn)(void *); };
struct Obj { char pad[4]; char *vt; };
struct H { Obj *o; char pad[0xC]; };
struct Self { char pad[0x30]; s16 f30; };

extern "C" s32 func_002F3A28(Self *);
extern "C" s32 func_003065A8(Self *);
extern "C" Node *func_003065D8(Self *);
extern "C" Node *func_003065E8(Self *);
extern "C" void func_00323B48(void *, void *);
extern "C" void func_00323B60(void *, int);

static inline void inc(Iter *i) {
    if (i->node->right != 0) {
        i->node = i->node->right;
        while (i->node->left != 0) {
            i->node = i->node->left;
        }
    } else {
        Node *p = i->node->parent;
        while (i->node == p->right) {
            i->node = p;
            p = p->parent;
        }
        if (i->node->right != p) {
            i->node = p;
        }
    }
}

extern "C" s16 func_002F3508(Self *self) {
    if (self->f30 < 0) {
        s32 p = func_002F3A28(self);
        if (p != 0) {
            self->f30 = func_002F3508((Self *)p);
        } else {
            self->f30 = 0;
        }
        if (func_003065A8(self) != 0) {
            Iter it;
            it.node = func_003065D8(self);
            while (it.node != func_003065E8(self)) {
                H h;
                Iter old;
                H *ph = &h;
                func_00323B48(ph, (char *)it.node + 0x14);
                VEnt0 *e = (VEnt0 *)(ph->o->vt + 0x60);
                if (e->fn((char *)ph->o + e->delta) != 0) {
                    VEnt *e2 = (VEnt *)(ph->o->vt + 0x70);
                    e2->fn((char *)ph->o + e2->delta, self->f30++);
                }
                func_00323B60(ph, 2);
                old.node = it.node;
                inc(&it);
            }
        }
    }
    return self->f30;
}
