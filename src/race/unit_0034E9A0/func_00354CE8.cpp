struct State {
    char pad[0x4BD];
    unsigned char state;
    short result;
    float x0, x1, x2;
    char pad2[0x5D0 - 0x4CC];
    float x3;
};

extern char PDISTD__UNIT_MANAGER[];
extern "C" int func_00472AE0(char *a, float b, float c);

extern "C" void func_00354CE8(char *arg0) {
    State *s = (State *)(arg0 + 0x104);
    if (--s->state == 0) {
        int r = func_00472AE0(PDISTD__UNIT_MANAGER, s->x3 - s->x2, s->x0 - s->x1);
        s->result = r;
        s->x2 = s->x3;
        s->x1 = s->x0;
        s->state = 0x1E;
    }
}
