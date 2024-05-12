/* protótipos para conseguir executar a linha: gcc testrand.c rand.c random.c random_r.c rand_r.c
  A compilação desta linha deve permitir gerar números aleatórios iguais aos de rand() do gcc instalado na máquina.
  */
  
long int __random (void); // de random.c
int __random_r (struct random_data *buf, int32_t *result);
int __srandom_r (unsigned int seed, struct random_data *buf);
int __initstate_r (unsigned int seed, char *arg_state, size_t n,
	       struct random_data *buf);
int __setstate_r (char *arg_state, struct random_data *buf);
void __srandom (unsigned int x);

#define srand(a) __srandom(a)   //replace weak_alias (__srandom, srand) in random.c fn



