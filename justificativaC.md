A linguagem C, em sua essência, é sintaticamente simples, tem poucos comandos. O padrão da linguagem é mantido pela ISO (https://www.iso.org/standard/74528.html). Há detalhes do funcionamento da linguagem que não são padronizados então cabe verificar a documentação do compilador (ex.: https://gcc.gnu.org/onlinedocs/gcc-14.2.0/gcc/C-Implementation.html)  As possibilidades de uso são ampliadas com bibliotecas, como em muitas outras linguagens.

A definição dos elementos sintáticos de C permite entender com mais facilidade sua correspondência com instruções em linguagem de máquina e, consequentemente, com o funcionamento do computador (que será visto em disciplinas como OAC).

C é uma linguagem que prioriza velocidade de execução dos programas. Estes geralmente são intensivos em uso do processador, como modelos matemáticos (ex.: as contas para renderizar um cenário em um jogo 3D para ter recobrimentos de objetos e sombras). Programas em C ficam muito longos e complicados, por exemplo, quando implementam interfaces gráficas e interfaces Web.

Um programa escrito em C, para ser executado, precisa, antes, ser compilado. Compilação é, em grandes linhas, a conversão do código-fonte do programa (seus arquivos `.c`) em instruções de máquina. Estas instruções são executadas pelo processador. Uma noção do que se tratam essas instruções pode ser obtida executando `objdump` sobre um programa compilado (mais em OAC-1 e SO).

Em uma primeira abordagem, é possível explicar o processo (fluxo) de desenvolvimento de um programa como um ciclo em que o programador edita o código-fonte do programa, quando satisfeito, compila o programa (o que gera o arquivo executável, geralmente `a.out`, executa o executável, avalia a execução em busca da definição de ajustes, volta a editar o código-fonte para fazer os ajustes. Em IP, usando C, esse processo é bastante rápído (*tight*) e evita questões de contexto de execução (que são frequentes em linguagens interpretadas). O diagrama abaixo ilustra esse processo.

```mermaid
graph LR
A("Editar hello.c")
B("Compilar hello.c (gera a.out)")
C("Executar a.out")
D("Avaliar a execução de a.out")

A --> B
B --> C
C --> D
D --> A

```
