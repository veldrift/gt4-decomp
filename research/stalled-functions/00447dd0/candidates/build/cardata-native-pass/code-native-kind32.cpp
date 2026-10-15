struct Info { long code; char other[24]; }; extern char D_006235A8[];
extern "C" bool func_00443ED0(void *,long,Info *);
extern "C" long func_00447DD0(long identifier,int kind) {
 int high=identifier>>32;
 long result=high;
 if(high!=0) { Info info; bool found=func_00443ED0(D_006235A8,identifier,&info); result=found==false?0:info.code; }
 return result;
}
