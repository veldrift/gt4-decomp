/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Ent {
    short start;
    short cnt;
};

struct Node {
    char pad[0x40];
    s32 idx;
};

struct Self {
    void *p0;
    char pad4[0xC];
    char sub[0x6B0 - 0x10];
    void *v6B0;
    char pad6B4[0x710 - 0x6B4];
    short ent[20][2];
    short s760;
    char pad762[2];
    Node *nodes[20];
};

struct Mat {
    char d[0x40];
};

extern "C" void func_00418A58(void *, void *);
extern "C" char *func_0041A988(char *, unsigned int);
extern "C" int ModelSet2___render(void *, int, void *);
extern "C" void func_004A53F8(void);
extern "C" void func_004A5400(void);
extern "C" void func_004A7698(void *);

extern "C" void func_003B1070(Self *self, Mat *mats) {
    char *sub=self->sub;
    int i;
    for (i = 0; i < 20; i++) {
        short *cnt=&self->ent[i][1];
        if (cnt[-1] < 0 && self->s760 < 0) continue;
        Node *n = self->nodes[i];
        int idx = i;
        if (n) idx = n->idx;
        Mat *m = mats + idx;
        func_00418A58(func_0041A988(sub, i), m);
        if (*cnt <= 0) continue;
        func_004A53F8();
        func_004A7698(m);
        for (int j = 0; j < self->ent[i][1]; j++)
            ModelSet2___render(self->p0, self->ent[i][0] + j, self->v6B0);
        func_004A5400();
    }
}
