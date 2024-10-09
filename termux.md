Termux é um aplicativo para Andoid que emula um terminal UNIX.

É possível permitir ao Termux acessar algumas pastas no sistema Android, por exemplo `dcim`, `Downloads`, ...

Dentro do Termux é possível instalar `gcc` para compilar programas.

O código-fonte dos programas pode estar espalhado em vários arquivos.

Por conta do rigor nas políticas de segurança do Android (rigor necessário se o dono do celular usa, por exemplo, aplicativos de banco), a versão no Google Play só pode ser instalada em Android 10 ou superior e pode ter problemas com android 12 ou superior (https://wiki.termux.com/wiki/FAQ#Will_Termux_work_on_Android_11).

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
