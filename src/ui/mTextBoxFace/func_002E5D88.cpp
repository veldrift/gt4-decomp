/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Face { char pad[0x12C]; char *text[128]; signed char count[128]; };
struct Layout { char pad[0x34]; float value; };
extern Layout *PDISTD__global_font_manager;
extern char D_0069D1C0[];
extern "C" void func_004909E0(Layout *, const char *);
extern "C" void func_00490760(Layout *);
extern "C" float func_00490830(Layout *);
static inline const char *c_str(char **str) {
    int len = *(int *)(*str - 0x10);
    if (len == 0) return D_0069D1C0;
    (*str)[len] = 0;
    return *str;
}
extern "C" int func_002E5D88(Face *self, int index) {
    float before = PDISTD__global_font_manager->value;
    func_004909E0(PDISTD__global_font_manager, c_str(&self->text[index]));
    func_00490760(PDISTD__global_font_manager);
    float after = PDISTD__global_font_manager->value;
    int n = (int)(((after - before) / func_00490830(PDISTD__global_font_manager)) - 1.0f) + 1;
    int old = self->count[index];
    self->count[index] = n;
    return n - old;
}
