Este repositório contém parte do material que uso nas aulas de IP. Pretendo ajustá-lo frequentemente. Em consequência, a cada ano o repositório pode estar bastante diferente. (Felizmente) Git é um gerenciador de versões com muitas funcionalidades, então posso criar versões e pontos de checkout em função do ano. Por outro lado, pessoas que procurarem checkouts específicos podem procurar no histórico de versões.

A linguagem de programação escolhida para IP é C. O sistema operacional escolhido é Linux. A interface com usuário é o terminal. Há motivos para todas essas escolhas, isto é explicado em aula. Por outro lado, o aluno ingressante, em geral, caso use um notebook ou desktop, está familiarizado com Windows e raramente usou o `cmd`, caso tenha usado somente smartphone ou tablet, está familiarizado com Android ou com IOS. A maneira que acredito ser a mais rápida para ingressantes em geral começar a programar (ié, escrever e executar `olamundo` na primeira aula) é através de um compilador online. Apresentada esta alternativa, tem-se mais tempo para o aluno construir seu *setup* de trabalho na disciplina.

Espera-se que o aluno construa uma maneira de editar e testar programas que esteja adaptada às suas condições. No aspecto da disciplina, Linux é mandatório. Há várias formas de instalar Linux em um computador.

1. Substituir o sistema operacional original do computador por Linux;
2. Instalar Linux em *boot* compartilhado com Windows;
3. Instalar Linux usando Windows Subsystem Linux (WSL);
4. Instalar um gerenciador de máquinas virtuais (hypervisor) como VirtualBox e VMWare Play, dentro desse gerenciador instalar Linux;

Os casos 1, 2 e 3 implicam em ajustes que podem atrapalhar outras pessoas que usem o mesmo computador. Quando teste o caso 3, habilitar WSL fez o monitor ter faixas piscando do lado direito, como se houvesse algum problema com resolução ou taxa de atualização, só consegui sanar esse problema reinstalando Windows a partir da partição de recuperação.
.

No caso 4, instalam-se mais alguns programas dentro do Windows e outros dentro do Linux. Gasta-se uma tarde, mas as alterações para os outros usuários é a presença de alguns programas novos. O passo a passo está [passoApasso.md](./passoApasso.md).


A idéia é que este repositório conterá explicações e código-fonte de IP. No momento contém alguns fragmentos de código e o [plano de atividades que decidi usar](./plano-08-05-2024.md).

## Fragmentos de código

- Ler arquivo [código-fonte](./arquivos);
- `qsort()` da biblioteca padrão [código-fonte](./qsort);
- `clock_gettime()` da biblioteca padrão [código-fonte](./time);
- Gerar números aleatórios e exploração do código-fonte de `glibc` [código-fonte](./rand);
