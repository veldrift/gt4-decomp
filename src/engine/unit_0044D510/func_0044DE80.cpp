struct Font { char pad[0x44]; unsigned int color; };
extern Font *PDISTD__global_font_manager;
extern "C" void func_004905B0(Font *,float,float,float,float);
static inline float maxf(float a,float b) { float r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float minf(float a,float b) { float r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
extern "C" void func_0044DE80(void *self, unsigned int color) {
 unsigned int a=(color >>24)&255;
 PDISTD__global_font_manager->color=color;
 float alpha=(float)a*0x1p-7f;
 func_004905B0(PDISTD__global_font_manager,0.0f,0.0f,0.0f,minf(maxf((alpha-0.25f)*0x1.555554p+0f,0.0f),1.0f));
}
