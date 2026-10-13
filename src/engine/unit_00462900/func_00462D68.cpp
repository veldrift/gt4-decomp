typedef int s32;

struct Result { s32 pad[4]; void *p; s32 pad14[3]; };
extern void *D_00623A48;
extern char D_006AB528[];
void func_004AE230(struct Result *, char *, s32);
void func_00498B28(void *);

void func_00462D68(void) {
    void **pg = &D_00623A48;
    if (*pg == 0) {
        struct Result r;
        func_004AE230(&r, D_006AB528, 1);
        *pg = r.p;
    }
}
