Termux é um aplicativo para Andoid que emula um terminal UNIX.

É possível permitir ao Termux acessar algumas pastas no sistema Android, por exemplo `dcim`, `Downloads`, ...

Dentro do Termux é possível instalar ~~`gcc`~~ um compilador C para compilar programas.

O código-fonte dos programas pode estar espalhado em vários arquivos.

Por conta do rigor nas políticas de segurança do Android (rigor necessário se o dono do celular usa, por exemplo, aplicativos de banco), a versão no Google Play só pode ser instalada em Android 10 ou superior e pode ter problemas com android 12 ou superior (https://wiki.termux.com/wiki/FAQ#Will_Termux_work_on_Android_11).

Em 2025, resolvi testar Termux para IP em um celular com Android 14. Sorte a minha, a versão do Termux no Google Play deve ser instalável nesse celular (https://github.com/termux-play-store.

### Em 2025

Instalar Termux a partir de Google Play é simples. Caso deseje aumentar/diminuir as letras use CTRL-ALT-+ ou CTRL-ALT--. Note que para usar + precisa pressionar o SHIFT.

Depois, instalei o compilador C, abrindo o Termux e executando o comando `pkg install clang`. Depois de instalar, excutar `gcc` resulta em `gcc: error: no input files`.

Para compilar e executar algum programa, é possível digitar um programa com o editor. Para executar o editor use o comando `nano`. Se quiser criar o arquivo e editá-lo use `nano <nome_do_arquivo>`.

No nano o comando para salvar o arquivo é CTRL-S e o comando para sair é CTRL-X. Caso tente-se sair sem salvar o editor pede confirmação.

Compilar um arquivo corresponde a executar o compilador sobre o arquivo editado. Isto é feito pelo comando `gcc <nome_do_arquivo>`. O arquivo executável tem nome `a.out`. Use `gcc --help` para ver maneiras de mudar o nome de `a.out` para o nome que desejar.

Depois de criar alguns arquivos (e perder tempo com a bagunça) fica claro que precisa-se saber alguns comandos para navegar no sistema de arquivos que o Termux acessa.

| comando | descrição | aliases |
| --- | --- | --- |
| ls | lista os arquivos (no diretório corrente) | dir |
| cd | muda de diretório | --- |
| pwd | informa em qual diretório está | --- |
| cp | copia arquivo | --- |
| rm | remove arquivo | --- |
| mv | move (renomeia) arquivo | --- |
| mkdir | cria (sub-)diretório | --- |
| rmdir | remove diretório vazio | --- |

Detalhes sobre como usar os comandos podem ser vistos com o argumento `--help`. Por exemplo `ls --help` mostra os detalhes sobre o comando `ls`.

UNIX padrão (Termux segue o padrão), tem um manual de usuário. No Termux, tanto a ferramenta para acessar o(s) manual(is) quanto o(s) manual(is) precisam ser instalados. Para instalar a ferramenta use o comando `pkg install man`. Para instalar o manual do UNIX use `pkg install linux-man-pages`. Com isto instalado, `man scanf` mostra o manual da função `scanf` da linguagem C.


 
### Em 2024 

Instalei em um telefone com Android 8 usando F-droid (um aplicativo gerenciador de pacotes alternativo ao Google play) (https://f-droid.org/pt_BR/packages/com.termux/). Isto foi feito sem *fazer root*, o que (creio eu) preserva a garantia dos aparelhos. Passos:

1. Baixar o APK (arquivo de instalação no Android do F-droid (https://f-droid.org/pt_BR/) e instalar o F-droid;
2. Executar F-droid, buscar por termux, instalar termux;
3. Executar termux (um terminal com as seguintes mensagens é mostrado);

```
Welcome to Termux!

Docs:       https://termux.dev/docs
Donate:     https://termux.dev/donate
Community:  https://termux.dev/community

Working with packages:

 - Search:  pkg search <query>
 - Install: pkg install <package>
 - Upgrade: pkg upgrade

Subscribing to additional repositories:

 - Root:    pkg install root-repo
 - X11:     pkg install x11-repo

For fixing any repository issues,
try 'termux-change-repo' command.

Report issues at https://termux.dev/issues
~ $
```

4. Instale `gcc` digitando no Termux o comando `pkg install gcc`
5. Execute o editor de texto digitando no Termux `nano`
6. Digite um programa em C, digamos, `ola.c`, e salve (CTRL-S)
7. Feche o editor de texto (CTRL-X)
8. Compile o programa com o comando `gcc ola.c` (ele gera um arquivo a.out)
9. Execute o programa digitando `./a.out`
10. Crie as ligações para as pastas do celular com o comando termux-setup-storage E permitindo o acesso do programa ao armazenamento do dispositivo - ele cria uma pasta de nome *storage*. Nela estão as pastas `dcim`, `Downloads`, ...

```
~ $ termux-setup-storage
~ $ ls
IAA  IP  ssh-key  storage
```
