/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef unsigned char u8;
struct Node {
    char pad[8];
    u8 *data;
};
struct Fat {
    char pad0[4];
    void *cache;
    char pad8[0x48];
    u32 f50;
    int f54;
    char pad58[0xC];
    int f64;
    char pad68[0xC];
    int f74;
    void *f78;
    int f7C;
    int f80;
};
struct Src {
    char pad[0xC];
    int f0C;
    int f10;
};
extern char D_00689518[];
extern "C" Node *func_004CA820(void *, int) throw();
extern "C" void func_004CA938(void *, Node *) throw();
extern "C" int func_004CB618(void) throw();

static inline u32 selectEntry(u32 val, int index) {
    if (index & 1) val = (unsigned short)(val >> 4);
    else val &= 0xFFF;
    return val;
}

extern "C" void func_004CD5A0(Fat *self, int a1, int a2, u32 val) {
    u32 s2 = 0;
    int s4 = 0;
    int s5 = 0;
    func_004CB618();
    self->f78 = D_00689518;
    self->f7C = ((Src *)val)->f0C;
    self->f80 = ((Src *)val)->f10;
    self->f74 = 0;
    if (self->f64 > 0) {
        do {
            Node *node = func_004CA820(self->cache, self->f54 + s5);
            if (node == 0) {
                u32 cnt = s2 != 0;
                cnt += (self->f50 * 2) / 3;
                u32 k = 0;
                if ((u32)node < cnt) {
                    do {
                        k++;
                        s4++;
                    } while (k < cnt);
                }
            } else {
                while (s4 < self->f64 && s2 < self->f50) {
                    if (s2 == self->f50 - 1) {
                        Node *n2 = func_004CA820(self->cache, self->f54 + s5 + 1);
                        if (n2 == 0) break;
                        u8 *next = n2->data;
                        val = (next[0] << 8) | node->data[s2];
                        func_004CA938(self->cache, n2);
                    } else {
                        u8 *p = node->data + s2;
                        val = (p[1] << 8) | p[0];
                    }
                    if (s4 & 1) val = (unsigned short)(val >> 4); else val &= 0xFFF;
                    s4++;
                    if (val == 0) self->f74 = self->f74 + 1;
                    s2 = s4 + s4 / 2;
                }
                func_004CA938(self->cache, node);
            }
            s5++;
            s2 = s2 % self->f50;
        } while (s4 < self->f64);
    }
}
