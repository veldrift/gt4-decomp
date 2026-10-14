/* compiler: ee-gcc2.96-no-strict-aliasing */
struct W { void *a0; int a4; void *a8; void *ac; char pad[0x100]; float dt; char pad2[8]; int flag; };
extern "C" float func_00385948(void *);
extern "C" float *func_00385D28(void *);
extern "C" int *func_00385FB0(void *);
extern "C" float *func_003864B8(void *);
static inline float random01(unsigned int *seed) {
    *seed = (unsigned long)*seed * 0x0900d309U + 1;
    return (float)*seed * 0x1p-32f;
}
static inline float randomRange(unsigned int *seed, float lo, float hi) {
    return (hi-lo)*random01(seed)+lo;
}
static inline float maximum(float a, float b) {
    __asm__("max.s %0, %1, %2" : "=f"(a) : "f"(a), "f"(b));
    return a;
}
extern "C" void func_00405C68(W *w, int trigger, unsigned int *seed) {
    float speed = 0.0f;
    if (*func_00385FB0(w->ac) == 1 && w->flag != 0) {
        float *p = func_003864B8(w->a8);
        *p = randomRange(seed, 0.5f, 1.0f);
    }
    if (func_00385948(w->a0) == 0.0f) {
        if (trigger) {
            float *out = func_003864B8(w->a8);
            float *p = func_003864B8(w->a8);
            float r = randomRange(seed, 0x1.fae146p-1f, 1.0f);
            *out = maximum(*p, r);
        }
        float *p = func_003864B8(w->a8);
        *p += randomRange(seed, 0.05f, 0.25f)*w->dt;
        if (*func_003864B8(w->a8) > 1.0f) speed = 10.0f;
    } else speed = 10.0f;
    if (speed > 0.0f) {
        if (*func_003864B8(w->a8) > 0.0f) {
            *func_00385D28(w->a0) += speed*w->dt;
            if (func_00385948(w->a0) >= 1.0f) {
                *func_00385D28(w->a0) = 1.0f;
                *func_003864B8(w->a8) = 0.0f;
            }
        } else {
            *func_00385D28(w->a0) -= speed*w->dt;
            if (func_00385948(w->a0) <= 0.0f) {
                *func_00385D28(w->a0) = 0.0f;
                float *p = func_003864B8(w->a8);
                *p = randomRange(seed, 0.0f, 0.75f);
                if (*func_003864B8(w->a8) > 0.6f)
                    *func_003864B8(w->a8) = 0.975f;
            }
        }
    }
}
