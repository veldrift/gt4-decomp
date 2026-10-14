struct Model { char pad[0x2e]; unsigned short n; };
struct Elem { int x; char *loops; char *motions; int z; };
struct Data { char pad[16]; Elem *elems; };
struct Self { Model *model; Data *data; unsigned short *list; };
struct Context { char pad[28]; float x,y,z; void *buffer; int unused; };
struct Entry { int x; int id; };
extern "C" {
void func_00428790(void*,void*,const unsigned short*) throw();
int GT4_Motion__MotionSetPlayer__getSkinningBufferSize(Self*);
void *func_00575E60(int,int);
void free(void*) throw();
void func_0042A868(Context*,Model*,void*,unsigned short*);
void func_0042A8A0(Context*,int);
float func_0042D430(void*,float);
float func_0042A4A8(void*,float);
int func_0042A828(Context*,unsigned short);
float func_0042C300(Elem*,int,float,Context*);
void func_0042C348(Elem*,int,float,float,Context*);
void ModelSet2__begin(Model*,void*);
void ModelSet2__end(Model*);
Entry *ModelSet2__searchModelName(Model*,const char*,int*);
void ModelSet2___render(Model*,int,void*);
void func_004A53F8();
void func_004A7454();
void func_004A7844(float,float,float);
void func_004A7B60(void*,int);
void func_004A5400();
extern char D_006A4BA8[];
void func_00428828(Self *self,int index,int a,int b,void *buffer,void *render,float *out,float time,float blend) {
 Context ctx;
 int count;
 int bones;
 if (self->model) {
  if (!self->data) { func_00428790(self->model,render,self->list); return; }
  void *work=buffer;
  bones=self->model->n;
  if (!work) work=func_00575E60(64,GT4_Motion__MotionSetPlayer__getSkinningBufferSize(self));
  func_0042A868(&ctx,self->model,render,self->list);
  ctx.buffer=work;
  int mode;
  if(a>=0) { b=a; mode=1; }
  else { mode=0; if(b<0) { func_0042A8A0(&ctx,2); return; } }
  Elem *elem=self->data->elems+index;
  if(mode) time=func_0042D430(elem->loops+b*32,time);
  else time=func_0042A4A8(elem->motions+b*32,time);
  if(out) *out=time;
  ModelSet2__begin(self->model,0);
  if(mode) func_0042C300(elem,b,time,&ctx);
  else func_0042C348(elem,b,time,blend,&ctx);
  if(work) {
   Entry *entries=ModelSet2__searchModelName(self->model,D_006A4BA8,&count);
   if(entries) {
    int i=0;
    func_004A53F8(); func_004A7454();
    func_004A7844(ctx.x,ctx.y,ctx.z);
    func_004A7B60(work,bones);
    for(;i<count;i++) {
     int id=entries->id; entries++;
     if(func_0042A828(&ctx,(unsigned short)id)) ModelSet2___render(self->model,id,render);
    }
    func_004A5400();
   }
  }
  ModelSet2__end(self->model);
  if(!buffer) free(work);
  func_0042A8A0(&ctx,2);
 }
}
}
