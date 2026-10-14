/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Mat { float m[16]; };
struct Vec3 { float x, y, z; };
struct Vec4 { float x, y, z, w; };

struct Elem {
    Vec3 pos;
    short kind;
    short idx;
};
struct Info {
    char pad[0x48];
    int count;
    Elem *elems;
};
struct Mid {
    char pad[0x10];
    Info *info;
};
struct Self {
    Mid *mid;
    char pad[0x178 - 4];
};

extern "C" {
void func_004515C0(Vec4 *, Elem *) throw();
void func_00451670(void *, Vec4 *, Vec4 *, Vec4 *) throw();
void func_00454110(float *, int);
void func_004A53F8();
void func_004A5400();
void func_004A7454();
void func_004A74B4(void *);
}

extern "C" void func_004517E0(Self *self) {
    Info *info = self->mid->info;
    if (info == 0) return;
    int n = info->count;
    if (n == 0) return;
    if (n > 16) n = 16;
    func_004A53F8();
    int k;
    k = 0;
    if (k < n) {
    int off = 0;
    Mat *tr = (Mat *)((char *)self + 0x178);
    do {
        Vec4 pts[3];
        int mode = 0;
        int cur = 0;
        int j = 0;
        Vec4 *dst = pts;
        unsigned int base = (unsigned int)info->elems + off;
        do {
            Elem *e = (Elem *)(base + j * 16);
            j++;
            if (e->kind == 0) {
                dst->x = e->pos.x;
                dst->y = e->pos.y;
                dst->z = e->pos.z;
            } else {
                if (e->kind != mode || e->idx != cur) {
                    if (e->kind == 1) {
                        mode = 1;
                        func_004A7454();
                        func_00454110((float *)((char *)self + 0x94 + e->idx * 0x38), e->idx & 1);
                    } else {
                        mode = 2;
                        func_004A74B4((char *)self + 0x178 + e->idx * 0x40);
                    }
                    cur = e->idx;
                }
                func_004515C0(dst, e);
            }
            dst++;
        } while (j < 3);
        func_00451670(tr + k, &pts[0], &pts[1], &pts[2]);
        off += 0x38;
        k++;
    } while (k < n);
    }
    func_004A5400();
}
