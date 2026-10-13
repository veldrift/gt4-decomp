typedef int s32;
struct VEntry{short delta,index;void*fn;};
struct Scale{float scale;s32 width,height;};
struct Game{char pad[0x39DC4];s32 index;};
struct Owner{char pad[0xF8];s32 invert;};
struct Face{char pad[0x64];VEntry*vt;};
struct Target{VEntry*vt;};
extern Game*D_00622F4C;
extern Scale D_00692380[];
extern "C" void func_003C6FC0(void*,s32,s32,s32,s32,s32,float);
static inline Target* target(Face*f){VEntry*e=(VEntry*)((char*)f->vt+0x4B0);return ((Target*(*)(void*))e->fn)((char*)f+e->delta);}
static inline void scale(Target*t,float x,float y){VEntry*e=(VEntry*)((char*)t->vt+0xC8);((void(*)(void*,float,float))e->fn)((char*)t+e->delta,x,y);}
extern "C" void func_00194308(Owner*self,Face*face){
int invert=self->invert;Scale*entry=D_00692380+D_00622F4C->index;float value=entry->scale;if(invert)value=1.0f/value;scale(target(face),value,1.0f);func_003C6FC0(face,entry->width,entry->height,2,2,32,value);}
