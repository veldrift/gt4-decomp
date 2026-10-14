/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Self {
    char pad0[0x18];
    int phase;
    int unused;
    int kind;
    float progress;
};
struct List { int unused; void **begin; void **end; };
struct Scale { float x, y; };
extern "C" void mWidget__setScale(void *, Scale *);
extern "C" void mWidget__setOpacity(void *, float);
extern "C" void mCrossTransition__begin(Self *self, void *arg1, List *list) {
    if (self->kind == 1) {
        int phase = self->phase;
        switch (phase) {
        case 0:
        case 1:
            break;
        case 2: {
            void **end = list->end;
            void **start = list->begin;
            if (end - start != 0) {
                float t = self->progress;
                float scale = t * t + 1.0f;
                if (scale > 2.0f) scale = 2.0f;
                if (scale < 1.0f) scale = 1.0f;
                for (void **it = start; it != end; ++it) {
                    mWidget__setOpacity(*it, 1.0f - self->progress);
                    Scale s;
                    s.x = scale;
                    s.y = scale;
                    mWidget__setScale(*it, &s);
                }
            }
            break;
        }
        default:
            break;
        }
    }
}
