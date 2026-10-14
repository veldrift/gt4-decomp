/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int (*OutFn)(int,int,int);
extern "C" int func_00493628(OutFn out,int *cnt,int ctx,int flags,int width,int prec,signed char sign,const char *str,int len,int base) {
 char prefix[16];
 int i;
 int npre=0;
 int lpad=0;
 int rpad=0;
 if(width<0) width=0;
 if(prec<0) prec=1;
 if(base<11) {
  if(sign!='-') { if(flags&2) sign='+'; }
  if(sign) prefix[npre++]=sign;
 }
 if(flags&16) {
  if(base>=8) prefix[npre++]='0';
  if(base>=16) {
   char *p=prefix+npre++;
   if(base&1) *p='X'; else *p='x';
  }
 }
 int zeros=prec-len;
 if(zeros<0) zeros=0;
 if((len|zeros)==0) {lpad=width;npre=0;}
 else {
  i=width-(npre+len)-zeros;
  if(i<0) { zeros+=i; zeros=(zeros<=0)?(len==0):zeros; }
  else if((flags^1)&1) {
   if(flags&4) zeros+=i;
   else lpad=i;
  } else rpad=i;
 }
 int total=0;
 for(i=0;i<lpad;i++) {
  if(out(' ',*cnt,ctx)) return -1;
  if(*cnt) *cnt=*cnt+1;
  total++;
 }
 for(i=0;i<npre;) {
  if(out(prefix[i++],*cnt,ctx)) return -1;
  if(*cnt) *cnt=*cnt+1;
  total++;
 }
 for(i=0;i<zeros;i++) {
  if(out('0',*cnt,ctx)) return -1;
  if(*cnt) *cnt=*cnt+1;
  total++;
 }
 for(i=0;i<len;) {
  if(out(str[i++],*cnt,ctx)) return -1;
  if(*cnt) *cnt=*cnt+1;
  total++;
 }
 for(i=0;i<rpad;i++) {
  if(out(' ',*cnt,ctx)) return -1;
  if(*cnt) *cnt=*cnt+1;
  total++;
 }
 return total;
}
