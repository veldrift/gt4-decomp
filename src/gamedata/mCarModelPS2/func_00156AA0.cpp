/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V { short delta, index; void (*fn)(void*,...); };
struct Model { int x; V *vt; };
struct Entry { int x, model, mode, flag; float angle; };
template<class T> struct Vec { int alloc; T *begin,*end,*cap; unsigned size() { return end-begin; } T &operator[](unsigned i) { return begin[i]; } };
struct Obj { int x; V *vt; char pad8[0x60]; Vec<Model*> models; Vec<Entry> entries; int extra; float scale; int active; char pad94[0x210]; int other; char pad2a8[0x5bc]; int data; };
extern "C" {
void func_00156820(int) throw(); void func_00156920(int) throw();
void func_004A53F8(); void func_004A5400(); void func_004A7550(void*); void func_004A7454(); void func_004A7A54(); void func_004A7774(void*);
float func_00364C40(void*,int,float,float); float func_00364D78(void*,int); float func_00364C60(void*,int,float,float);
int func_00364F70(void*,int); int func_00364F80(void*,int);
void func_004A7844(float,float,float); void func_004A79B0(float); void func_004A7890(float,float,float); void func_0021B328(void*,void*);
void func_00156AA0(Obj *self,int enabled) {
 char matrix[64];
 if (!self->active && !self->other) return;
 unsigned count=self->entries.size(), n=self->models.size();
 if (!count && !n) return;
 func_004A53F8();
 if(self->active) {
  func_004A7550(matrix); func_004A7454();
  V *v=self->vt+56; v->fn((char*)self+v->delta);
  func_004A7A54(); func_004A7774(matrix);
 }
 func_00156820(enabled);
 if(count==0) {
  for(unsigned i=0;i<n;i++) { Model *m=self->models[i]; V *v=m->vt+10; v->fn((char*)m+v->delta,enabled); }
 } else {
  float x=func_00364C40(&self->data,0,0.0f,0.0f)-func_00364D78(&self->data,0)*0.5f;
  float y=func_00364C40(&self->data,2,0.0f,0.0f)-func_00364D78(&self->data,2)*0.5f;
  float z=func_00364C60(&self->data,0,0.0f,0.0f);
  float w=func_00364C60(&self->data,2,0.0f,0.0f);
  float mid=(z+w)*0.5f;
  float front=func_00364F70(&self->data,0)*0x1.0624dcp-10f;
  float back=func_00364F80(&self->data,0)*0x1.0624dcp-10f;
  for(unsigned i=0;i<count;i++) {
   Entry *e=&self->entries[i];
   if(e->flag && enabled) continue;
   func_004A53F8();
   Model **m=&self->models[e->model]; float angle=e->angle;
   switch(e->mode) {
    case 0: break;
    case 1: func_004A7844(x,0,z); break;
    case 2: func_004A7844(-x,0,z); angle+=180; break;
    case 3: func_004A7844(y,0,w); break;
    case 4: func_004A7844(-y,0,w); angle+=180; break;
    case 5: func_004A7844(x,0,mid); break;
    case 6: func_004A7844(-x,0,mid); angle+=180; break;
    case 7: func_004A7844(x,0,z+(w-z)*0.75f); break;
    case 8: func_004A7844(-x,0,z+(w-z)*0.75f); angle+=180; break;
    case 10: func_004A7844(0,0,mid+back); angle+=90; break;
    case 9: func_004A7844(0,0,mid-front); angle-=90; break;
   }
   func_004A79B0(angle);
   float sx=self->scale; float sy=0.0f; if (!e->flag) sy=sx;
   func_004A7890(sx,sy,sx);
   func_0021B328(matrix,e);
   Model *p=*m; V *v=p->vt+11; v->fn((char*)p+v->delta,matrix,enabled);
   func_004A5400();
  }
 }
 func_004A5400(); func_00156920(enabled);
}
}
