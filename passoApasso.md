Virtual Box é um gerenciador de máquinas virtuais (hypervisor). Ele emula o funcionamento de um computador que não teve nenhum sistema operacional instalado. Como emula um computador, à vista de quem o usa, é como se houvesse vários computadores diferentes em que poderiam ser instalados vários sistemas operacionais e aplicações dentro desses sistemas operacionais. É como se o computador físico passasse a conter vários computadores virtuais.

Nessa área de máquinas virtuais, o sistema operacional em que o gerenciador é instalado é o *host* e o sistema operacional instalado dentro da máquina virtual é o *guest*. Se você quer instalar Virtual Box dentro do Windows, então baixe a versão em que o *host* é Windows.

A página de download é: https://www.virtualbox.org/wiki/Downloads , a versão que baixei na ocasião é 7.0.18 .

Instalar Virtual Box é (quase) como baixar e instalar outro programa. Acontece que ele depende do pacote redistribuível do Visual C++ (https://learn.microsoft.com/pt-br/cpp/windows/latest-supported-vc-redist?view=msvc-170). É um programa gratuito feito pela Microsoft para dar suporte a programas escritos em Visual C++. Então, antes de instalar Virtual Box, baixe e instale o pacote redistribuível do Visual C++. Em computadores mais recentes (2015 para cá) o pacote X64 deve servir.

Depois de instalar o pacote redistribuível, instala-se o Virtual Box. Ele avisa que o suporte para Python precisará ser instalado manualmente. Este suporte não será usado por enquanto, então pode continuar a instalação.

Iniciando o Virtual Box, não há nenhuma máquina virtual criada. Para criar uma, precisamos antes do arquivo de distribuição do sistema operacional que queremos instalar na máquina virtual que será criada. Geralmente este arquivo tem extensão .ISO . Popularmente, fala-se em *a/o ISO do Linux*. No caso, escolhi Linux Lite pois é uma distribuição baseada em Ubuntu e precisa de poucos recursos (1GB de RAM e 20GB de armazenamento). A página de download (https://www.linuxliteos.com/download.php) é visualmente confusa,  tenha cuidado com o que clicar. Neste exemplo, na seção Download from the Web, clique na caixa de lista "Choose a location near you" e selecione uma localidade. Isso abre uma janela que permite fazer download do arquivo ISO. Especificamente, baixei http://sft.if.usp.br/linuxlite/isos/7.0/linux-lite-7.0-64bit.iso .

Depois de baixar o arquivo ISO, no Virtual Box, escolher no menu Máquina->Novo . Dar um nome (fácil) para a nova máquina e ajustar a caixa de texto "Imagem ISO" para apontar para o arquivo iso baixado. Clicar no botão Próximo. Isto inicia o instalador do sistema operacional dentro da máquina virtual (é como se criasse um computador e instalasse o sistema operacional nele). Siga as instruções do instalador do sistema operacional. Ao final do processo de instalação, haverá uma janela do Windows (o host) executando Linux (o guest) .

Uma funcionalidade conveniente é poder passar arquivos do Windows para o Linux e vice-versa. Isto precisa ser configurado, o Virtual Box não é capaz de configurar o compartilhamento de pastas sozinho. Para isso, é necessário instalar no *guest* o Virtual Box guest additions. Este vem no Virtual Box como se fosse um CD-ROM (ou seja, um arquivo ISO). Vá no menu Dispositivos->Instalar imagem de CD dos Adicionais para Convidado (equivale a colocar um CD no drive). Surgirá um ícone de CD no desktop. Para instalá-lo, no guest (ié dentro da janela que roda a VM, no caso, Linux) clicar no ícone, selecionar o arquivo de instalação compatível com o guest e executar. Para executar no Linux é necessário privilégio de administrador (clicar no ícone monta o CD no sistema de arquivos). Se fizer por um terminal do Linux, depois de clicar no ícone, use o comando `sudo /media/linuxlite/VBox_GAs_7.0.18/VBoxLinuxAdditions.run`. Isto, entre outras coisas, criará o grupo `vboxsf`, o que é importante para compartilhar pastas.

![](./Captura%20de%20tela%202024-06-11%20132710.png)


Para ter acesso às pastas compartilhadas o usuário tem que pertencer ao grupo `vmboxsf`. Para incluir o usuário ativo no grupo usar a linha de comando: `sudo usermod -G vboxsf -a $USER`. Para todas as configurações terem efeito, reiniciar a máquina virtual (comando do terminal: `reboot`).

Para criar uma pasta compartilhada, no menu ir a Dispositivos->Pastas Compartilhadas->Configurações de Pastas Compartilhadas, clicar no botão para adicionar pasta, preencher com o nome da pasta do windows que você quer compartilhar, deixar o ponto de montagem vazio, clicar em tornar permanente e dar ok. A pasta deve aparecer no guest como `/media/sf_<nome>`.

![](./Captura%20de%20tela%202024-06-11%20121037.png)


![](./Captura%20de%20tela%202024-06-11%20121237.png)


Para testar, crie um arquivo texto em um SO e veja ele aparecer na pasta compartilhada no outro SO.

Nota: no linux lite o gcc vem pré-instalado.

Referências:
  
- https://carleton.ca/scs/tech-support/troubleshooting-guides/creating-a-shared-folder-in-virtualbox/
- https://askubuntu.com/questions/161759/how-to-access-a-shared-folder-in-virtualbox
- https://docs.oracle.com/en/virtualization/virtualbox/6.0/user/sharedfolders.html
- https://www.google.com/search?q=linux+list+all+groups&oq=linux+list+all+gr&gs_lcrp=EgZjaHJvbWUqBwgAEAAYgAQyBwgAEAAYgAQyBggBEEUYOTIICAIQABgWGB4yCAgDEAAYFhgeMggIBBAAGBYYHjIICAUQABgWGB4yCAgGEAAYFhgeMggIBxAAGBYYHjIICAgQABgWGB4yCAgJEAAYFhgeqAIAsAIA&sourceid=chrome&ie=UTF-8
- https://www.google.com/search?q=virtualbox+group+vboxsf+does+not+exist&oq=virtualbox+group+&gs_lcrp=EgZjaHJvbWUqCQgBEAAYExiABDIMCAAQRRgTGBYYHhg5MgkIARAAGBMYgAQyCggCEAAYExgWGB4yCggDEAAYExgWGB4yCggEEAAYExgWGB4yCggFEAAYExgWGB4yCggGEAAYExgWGB4yCggHEAAYExgWGB4yCggIEAAYExgWGB4yCggJEAAYExgWGB7SAQkxNTg1NmowajeoAgCwAgA&sourceid=chrome&ie=UTF-8
- https://ubuntuforums.org/showthread.php?t=2478317
- https://askubuntu.com/questions/103069/shared-folder-in-virtualbox-ubuntu-and-windows-7
- https://www.google.com/search?q=virtual+box+install+guest+additions+ubuntu&oq=virtual+box+install+guest+additions+ubuntu&gs_lcrp=EgZjaHJvbWUyBggAEEUYOTILCAEQABgNGBMYgAQyCwgCEAAYDRgTGIAEMgsIAxAAGA0YExiABDIKCAQQABgTGBYYHjIKCAUQABgTGBYYHjIKCAYQABgTGBYYHjIKCAcQABgTGBYYHjIKCAgQABgTGBYYHjIKCAkQABgTGBYYHtIBCTE0NzYwajBqN6gCALACAA&sourceid=chrome&ie=UTF-8
- https://askubuntu.com/questions/22743/how-do-i-install-guest-additions-in-a-virtualbox-vm
- https://www.virtualbox.org/manual/ch04.html
- https://www.google.com/search?q=virtual+box+download&oq=virtual+box+download&gs_lcrp=EgZjaHJvbWUyBggAEEUYOTIJCAEQABgKGIAEMgkIAhAAGAoYgAQyBwgDEAAYgAQyCggEEAAYChgWGB4yCggFEAAYChgWGB4yCggGEAAYChgWGB4yCggHEAAYChgWGB4yCggIEAAYChgWGB4yCggJEAAYChgWGB7SAQg1NjQzajBqN6gCALACAA&sourceid=chrome&ie=UTF-8
- https://www.virtualbox.org/wiki/Downloads
- https://www.virtualbox.org/search?q=guest+additions&wiki=on&changeset=on&ticket=on
- https://www.google.com/search?q=where+can+i+download+virtualbox+guest+additions&oq=where+can+i+get+virtualbox+gu&gs_lcrp=EgZjaHJvbWUqCAgBEAAYFhgeMgYIABBFGDkyCAgBEAAYFhgeMggIAhAAGBYYHjIKCAMQABiABBiiBNIBCTEwMDIyajBqN6gCALACAA&sourceid=chrome&ie=UTF-8
- https://forums.virtualbox.org/viewtopic.php?t=94786
- https://www.google.com/search?q=add+user+to+vboxsf+grouup&oq=add+user+to+vboxsf+grouup&gs_lcrp=EgZjaHJvbWUyBggAEEUYOTILCAEQABgNGBMYgAQyCwgCEAAYDRgTGIAEMgoIAxAAGA0YExgeMgwIBBAAGAUYDRgTGB4yDAgFEAAYBRgNGBMYHjIKCAYQABiABBiiBDIKCAcQABiABBiiBDIKCAgQABiABBiiBDIKCAkQABiABBiiBNIBCTEyNzU0ajBqN6gCALACAA&sourceid=chrome&ie=UTF-8
- https://askubuntu.com/questions/323392/how-to-access-shared-folders-in-ubuntu-vmoracle-virtualbox-and-link-them-to-th
- https://www.linuxliteos.com/download.php
- http://sft.if.usp.br/linuxlite/isos/7.0/

