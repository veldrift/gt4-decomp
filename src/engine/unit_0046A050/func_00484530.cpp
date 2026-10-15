/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Val;
struct Str { char *p; };
struct Entry { int type,v,x; };
struct Stack { Entry entries[8]; int top; };
struct Obj { char pad[0x14]; void *node; };
extern "C" int func_00476768(Val *, const Val *);
extern "C" void *func_00476790(Val *, const Val *) throw();
extern "C" void func_004768C0(Val *);
struct Val {
 int type,v;
 Val() { type=1; }
 Val(const Val &o) { func_00476768(this,&o); }
 ~Val() { func_004768C0(this); }
 Val &operator=(const Val &o) { func_00476790(this,&o); return *this; }
 int valid() const { return type ^ 1; }
};
extern "C" Val func_00476698(Str *, char *) throw();
extern "C" Val func_004774F8(void *, Str *);
extern "C" Val func_0047B728(void *, Str *) throw();
extern "C" Val func_00480970(void *, Str *) throw();
extern "C" Val *func_00481230(void *, Str *) throw();
static inline Stack *active(Stack *s) { if (s->top < 0) return 0; return s; }
static inline Val lookup(Stack *stack, Str *name) {
 Val result;
 for (int i=stack->top; i>=0; --i) {
  { Val tmp=func_004774F8(&stack->entries[i],name); result=tmp; }
  if (result.valid()) return result;
 }
 return result;
}
extern "C" Val func_00484530(Obj *self, Str *name, void *table, Stack *stack, char *base) {
 if (active(stack)) {
  Val result=lookup(stack,name);
  if (result.valid()) return result;
 }
 Val *found=func_00481230(table,name);
 if (found) return *found;
 Val result;
 result=func_0047B728(self->node,name);
 if (result.valid()) return result;
 result=func_00480970(self->node,name);
 if (result.valid()) return result;
 return func_00476698(name,base);
}
