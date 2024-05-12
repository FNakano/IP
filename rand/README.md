A maioria das linguagens de programação têm funções padrão para geração de números "aleatórios" (nota: são números pseudo-aleatórios, resultado de uma conta que pode ser reproduzida). Essas funções estão em bibliotecas de funções (ou o análogo em determinada linguagem de programação). Há linguagens de programação criadas a bem mais que 50 anos (ano de referência 2024). Os desenvolvedores dessas linguagens geralmente preocupam-se com compatibilidade com versões anteriores. Por outro lado, o que se sabe sobre geração de números aleatórios avançou bastante nesses últimos 50 anos e geradores de números aleatórios estão no núcleo dos programas de segurança (criptografia) de dados. *A conjunção de compatibilidade com versões anteriores* e *avanço da conhecimento sobre números aleatórios* geram questões sobre como organizar a infraestrutura (funções dentro das bibliotecas padrão) em linguagens de programação.

Até onde sei, geradores de números aleatórios em C, nas versões iniciais (<1990), eram compostos por uma função de inicialização `srand(unsigned int)` e uma função para geração de números `rand()`. `srand()` inicializava uma variável (global?) `unsigned int seed` e `rand()` executava algo como `return seed=seed*16807`. Era suficiente para jogos (de Atari 2600) com inteiros de 16 bits. Este gerador de números aleatórios tem vários problemas, são assuntos interessantes mas não cabe entrar no detalhe dado o escopo desta explicação.

Em C, o uso básico das funções de geração de números aleatórios continua igual, ou seja, `srand(unsigned int)` inicializa o gerador de números aleatórios e `rand()` gera um número aleatoriamente. Habitualmente usa-se o tempo de relógio como semente para gerar números aleatórios (ié usa-se tempo relógio como fonte de aleatoriedade (ié usa-se o relógio como fonte de entropia)).

Um exemplo de uso do gerador de números aleatórios da biblioteca-padrão da linguagem C (glibc) está no arquivo `usarand.c`.

A fim de aprofundar um pouco essa apresentação, na direção do ensino de linguagens de programação, é possível localizar, modificar e compilar o código-fonte da biblioteca, executar o código-fonte modificado e verificar que a execução desse código modificado leva ao mesmo resultado da execução do código da biblioteca. 

A biblioteca `glibc` é mantida pela Free Software Foundation em: https://www.gnu.org/savannah-checkouts/gnu/libc/ . Tanto a documentação quanto o código-fonte pode ser baixado gratuitamente.

Baixei o arquivo `glibc-2.39.tar.xz` e descompactei com `tar -xf glibc-2.39.tar.xz`.

A implementação atual do gerador de números aleatórios está contida nos arquivos `rand.c`, `random.c`, `random_r.c`. Um teste é fornecido no código-fonte em `testrand.c`. Os arquivos podem ser localizados dentro do diretório usando, por exemplo, `find . -name "rand*"`. O principal arquivo de header associado `stdlib.h`.

Cada um dos três arquivos-fonte é uma camada sobre o outro, sendo `rand.c` a mais próxima do programador de aplicação e `random_r.c` a mais próxima do hardware.

**A meta é compilar esses arquivos e ter uma versão local de `rand()` e de `srand()` que gera números igual à versão da biblioteca.**

Conseguir compilar e executar uma versão local pode ser trabalhoso, já que a biblioteca está instalada no sistema o que torna necessário fazer uso seguro ou contornar os tipos de dados e variáveis globais. Durante as buscas para resolver os erros que ocorriam notei que há mais pessoas que se interessaram nesse assunto e postaram em fóruns públicos. Isto ajuda por haver informação pública, mas atrapalha por haver informação desatualizada e, às vezes, errada (não foi o caso desta vez).

O resultado está na pasta [rand-gcc-from-source](./rand-gcc-from-source). Deve ser compilado com o comando `gcc -Wall testrandseq.c rand.c random.c random_r.c rand_r.c` (ainda não removi as pastas e arquivos-fonte que (acho que) não são necessários - ié todos os outros - porque removê-los tem o potencial (estimo que, baixo) de gerar outros problemas e requerer mais tempo para resolvê-los.

Uma tentativa rápida é criar uma nova pasta e copiar somente os arquivos necessários. Fiz isso e o resultado foi bom. O executável foi criado e sua execução resulta nos mesmos números gerados por `usarand.c`. [rand-gcc-from-source-selected](./rand-gcc-from-source-selected). O comando `gcc -Wall testrandseq.c rand.c random.c random_r.c rand_r.c` compila e gera o teste.

### Registro da criação do código

- Comecei por https://stackoverflow.com/questions/18969783/how-can-i-get-the-sourcecode-for-rand-c . O código apresentado está incompleto. Veja os links em https://scicomp.stackexchange.com/questions/30479/how-good-are-current-implementations-of-rand-in-c para códigos mais completos.
- A documentação do gcc/glibc: https://ftp.gnu.org/old-gnu/Manuals/glibc-2.2.3/html_node/libc_387.html indica que esse gerador é oferecido por compatibilidade com BSD e que não é melhor que o código oferecido por ISO-C. **mas essa versão de glibc é antiga**
- Na página sobre ISO-C rng (https://ftp.gnu.org/old-gnu/Manuals/glibc-2.2.3/html_node/libc_386.html) não é mostrado o código-fonte, mas o texto dá a entender que é algo simples. **mas essa versão de glibc é antiga**
- Nesta postagem: https://scicomp.stackexchange.com/a/30497 dá-se a entender que alguém fez engenharia reversa do RNG.
- Testei a geração de números aleatórios com o programa usarand.c. Os números gerados foram diferentes dos listados na postagem acima. Li com mais cuidado. A pessoa usou um macbook. A implementação do RNG pode ser diferente da usada no GCC.
- Resolvi baixar o código-fonte de glibc (https://www.gnu.org/savannah-checkouts/gnu/libc/index.html#documentation), encontrar o código-fonte de rand(), separar do resto e compilar. A pasta em que farei isso é file:///home/fabio/Anota/Incompleto/IP-2024/rand-gcc-from-source/ e, por enquanto, é uma cópia de file:///home/fabio/glibc-source/glibc-2.39/stdlib/ que, por sua vez, é parte do código-fonte de glibc.
- acho que encontrei: srand é definido por um weak_alias em random.c. Weak alias é uma forma de definir algo na ausência de uma definição forte (https://stackoverflow.com/questions/34892601/what-does-the-weak-alias-function-do-and-where-is-it-defined). Só que eu comentei todos os weak_alias porque requerem incluir mais código-fonte. Fazendo isso, no meu código de teste, a chamada a srand() chama a função da biblioteca padrão, o que não tem reflexo para o rand() que estou codificando localmente. Vou tentar codificar esse alias como um #define
- Eu estava esquecendo de colocar o #include "fnrandom.h" em testrand.c. Isto evitava usar o srand que defini no arquivo de header. Corrigido isso, funcionou. Tanto rand da biblioteca padrão quando rand do programa local funcionam igual, até onde testei. 12.05.2024

Lembro-me que existe uma recomendação de que as aplicações em um sistema devem compartilhar o mesmo gerador de números aleatórios. Isto aumenta a aleatoriedade. Por conta disso, várias aplicações podem usar as mesmas funções e variáveis simultaneamente, o que implica em tentativas concomitantes de uso. Essas tentativas são sincronizadas com o uso de *seções críticas* implementadas com as funções  `libc_lock_define_initialized (static, lock)` , `__libc_lock_lock (lock)` , `__libc_lock_unlock (lock)` . Estas funções são usadas em `random.c`.

`weak_alias` é uma macro (um `#define`) que instrui o compilador a usar determinada função quando outra não tiver sido declarada (https://stackoverflow.com/questions/34892601/what-does-the-weak-alias-function-do-and-where-is-it-defined) . Esta é usada em `random.c` e em random_r.c`.



