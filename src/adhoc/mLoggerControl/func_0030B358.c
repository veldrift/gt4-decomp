/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Pair { unsigned int a,b; };
struct Entry { int *id; struct Pair val; };
extern struct Entry D_00619CA8[];
extern struct Pair D_0069DE80;
struct Pair func_0030B358(const int*x){
 int i;
 for(i=0;i<28;i++){
  if(*x==*D_00619CA8[i].id) return D_00619CA8[i].val;
 }
 return D_0069DE80;
}
