
typedef struct Row Row;
typedef struct Elem Elem;
typedef unsigned char u8;
extern float func_003573A8(void *, int, float);
extern u8 *func_00359510(void *);
extern float func_00359830(void *, float);
struct Row
{
  char pad[0x1EC];
};
struct Elem
{
  char pad[0x58];
};
extern void func_00361798(char *self, int mode)
{
  int start = 0;
  int end = 6;
  if (mode == 1)
  {
    end = 3;
  }
  else
  {
    start = (mode ^ 2) ? (0) : (3);
  }
  int i = start;
  if (i < end)
  {
    Row *p = (Row *) ((i * 0x1EC) + ((int) self));
    do
    {
      if ((*((float *) (((char *) p) + 0x410))) != 0.0f)
      {
        int t = i / 3;
        Elem *arr = (Elem *) (self + 0x14);
        int id = func_00359510(self)[t + 0xC];
        float b = ((*((float *) ((self + 0x1040) + (t * 4)))) * 0.5f) + (*((float *) (((char *) (&arr[t])) + 0x330)));
        float r = func_003573A8(self, id, b);
        *((float *) (((char *) p) + 0x410)) = (*((float *) (((char *) p) + 0x410))) * func_00359830(((char *) p) + 0x5BC, r);
      }
      i++;
      p++;
    }
    while (i < end);
  }
  self[0x104A] = 0;
  if ((*((float *) (self + 0x418))) != (*((float *) (self + 0x9DC))))
  {
    self[0x104A] = 1;
  }
}
