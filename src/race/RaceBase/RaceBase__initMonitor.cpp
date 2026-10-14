/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short delta; short index; void *fn; };
struct Obj { char pad[0x64]; Entry *vt; };
struct Monitor { Entry *vt; };
extern "C" float GranTurismo4__OptionMonitorFovy();
extern "C" int GranTurismo4__OptionMonitorMatrix(float *);
extern char *D_00622F4C;
static inline float scale(float k, float x) { return x * k; }
extern "C" void RaceBase__initMonitor(Obj *self) {
    float matrix[16];
    GranTurismo4__OptionMonitorMatrix(matrix);
    char *option = D_00622F4C + 0x38cb0;
    if (*(int *)(option + 0x16b0) == 2) {
        float x = matrix[0];
        float result;
        if (*(int *)(option + 0x14)) result = x * 0x1.ccccccp+0f;
        else result = x * 0x1.599998p+0f;
        matrix[5] = result;
    }
    Entry *e = self->vt + 26;
    Monitor *m = ((Monitor *(*)(void *, int))e->fn)((char *)self + e->delta, 0);
    Entry *f = m->vt + 24;
    char *adjusted = (char *)m + f->delta;
    float fovy = GranTurismo4__OptionMonitorFovy();
    ((void (*)(void *, float *, float))f->fn)(adjusted, matrix, fovy);
}
