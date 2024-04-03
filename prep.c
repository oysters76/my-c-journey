
#define MAKE_ADD_FUNC(type)       \
type add_##type(type x, type y)   \
{                                 \
    return x + y;                 \
}                                 \

#define GEN_X(type, name) \
type type##_##name(type x, type y) \
{ \
  printf("yoloman"); \
} \

#define GEN_MAX(type) \
type type##_max(type x, type y)\
{ \
 return x > y ? x : y; \
} \

typedef unsigned long ul;
GEN_MAX(ul)