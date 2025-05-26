# Análise exploratória da calculadora do Tesouro Direto para título prefixado

Usando como exemplo o título Tesouro Prefixado 2028, o título, em 20 de maio de 2025, tem vencimento em 01/01/2028 e taxa 13,43%aa.

## Introdução

Documentação e código-fonte da calculadora do Tesouro Direto (https://www.tesourodireto.com.br/titulos/calculadora.htm) não foram encontrados, resta analisar a partir dos resultados.

Segue a versão *limpa*, detalhes no *Histórico*.

## Procedimento

### Reproduzir resultado de um cálculo com calculadora do Tesouro Direto

Configurando a calculadora com:

- Titulo: Tesouro Prefixado 2028;
- Data do Investimento 01/01/2027;
- Data do Vencimento: 01/01/2028 (pre-definido pela escolha do título);
- Valor Investido: 10000,00;
- Taxa de Rentabilidade do Investimento: 13,43;
- Taxa de administração do banco/corretora (%a.a.): 0;

Obtém-se Valor bruto dos cupons e do resgate de 11343,01 em 252 dias úteis: [captura de tela calculadora TD 01/01/2027](./images/Captura%20de%20tela%20de%202025-05-25%2010-44-08.png)
<!---    * [captura de tela calculadora TD 03/01/2027](./images/Captura%20de%20tela%20de%202025-05-25%2010-45-25.png)
    * [captura de tela calculadora TD 04/01/2027](./images/Captura%20de%20tela%20de%202025-05-25%2010-46-10.png) --->

### Resultado

O programa `teste-10.c` faz o cálculo do valor diariamente e com 252 dias apresenta resultado de 11343,00. 

### Comentário e conclusão

O erro é menor que 0,9e-6, considerando a representação e precisão de números do tipo double, e a quantidade de cálculos encadeados é possível afirmar que os resultados são iguais.

No programa `teste-10.c` testa-se também a sensibilidade da variação da Data de Investimento. No ano de 2027, os dias 02 e 03 são sábado e domingo, o dia útil seguinte é 04/01/2027. Ajustando a calculadora do Tesouro Direto para Data do Investimento nesse dia, a quantidade de dias úteis é 251, o Valor bruto dos cupons e do resgate passa a ser 11337,35, o valor para 251 dias usando `teste-10.c` é 11337,329210. O erro é menor que 1,9e-6.

Nota-se, também, que 01/01 não é considerado dia útil na calculadora do Tesouro Direto pois a quantidade de dias úteis para Data do Investimento: 31/12/2026 também é 252 [Captura de tela](./images/Captura%20de%20tela%20de%202025-05-25%2012-21-41.png), só aumentando para 253 para Data do Investimento 30/12/2026 [Captura de tela](./images/Captura%20de%20tela%20de%202025-05-25%2012-21-05.png). É possível afirmar que caso o dia escolhido pelo usuário não seja dia útil, a calculadora considera Data do Investimento, o dia útil ANTERIOR. É útil para quem JÁ FEZ o investimento mas um tanto enganoso para quem usa a ferramenta para PLANEJAR um investimento (que ainda não fez).

## Histórico

A simulação (acessada através do botão *simule* na lista de aplicações), configurada com investimento inicial e único de 10 mil, resultou em valor bruto do resultado estimado de 13913,62, conforme captura de tela a seguir. A esta chamarei *Simulação 1*.

![Simulação 1](./Captura%20de%20tela%20de%202025-05-20%2013-53-26.png)

Esse valor está muito longe do que obtive por simulação com funcoesArray no `teste-9.c` onde calculei o rendimento de 2025-06 a 2028-01, ié, 31 meses, a partir da taxa anual de 13,43% trazida a taxa mensal em que um investimento inicial e único de 10 mil resulta em 13703.131652 (cálculo feito no array valorTDPre.

Procurei o código-fonte da calculadora do Tesouro Direto e procurei também documentação, oficial ou não, sobre o funcionamento da calculadora mas não encontrei então decidi analisar o funcionamento através de comparações de simulações.

### Análise de simulações da calculadora do Tesouro Direto

Parece haver uma outra interface para a mesma calculadora em https://www.tesourodireto.com.br/titulos/calculadora.htm. Esta é mais conveniente pois permite escolher a data de início do investimento.

Uma primeira tentativa, usando os mesmos parâmetros da *Simulação 1*, obtive valor bruto dos cupons e do resgate de 13917,30, conforme captura de tela abaixo. A esta chamarei *Simulação 2*.
  
![Simulação 2](./Captura%20de%20tela%20de%202025-05-20%2014-05-17.png)


O que chama atenção neste resultado é a apresentação da quantidade de dias corridos e de dias úteis.

Para facilitar a análise, escolhi testar o cálculo para o período de dois anos completos, iniciando em 01/01/2026 e terminando em 01/01/2028. Com investimento inicial único de 10mil, o valor bruto apresentado pela calculadora foi: 12853,63 MAS considerando o rendimento de dois anos cheios, a raiz quadrada de 1,285363 deveria resultar na rentabilidade anual, mas essa raiz corresponde a 1,133738506 e não a 1,1343! Resultado da calculadora na captura de tela abaixo. A esta chamarei *Simulação 3*.
  
![Simulação 3](./Captura%20de%20tela%20de%202025-05-20%2014-19-34.png)


Tentei simplificar ainda mais a análise. Usei intervalo de 01/01/2027 a 01/01/2028, ié, um ano. O valor bruto de cupons e resgate foi 11343,01 - muito próximo do esperado. Captura de tela abaixo. A esta chamarei *Simulação 4*.
  
![Simulação 4](./Captura%20de%20tela%20de%202025-05-20%2014-24-19.png)


Satisfeito com esse resultado, fui verificar o efeito de variar a quantidade de dias. Usando este caso como referência, de 01/01/2027 a 01/01/2028 a calculadora apresentou 362 dias corridos e 252 dias úteis. Fui aumentando de um em um a data de início do investimento. Para as datas de investimento 02/01/2027 e 03/01/2027 a quantidade de dias úteis não mudou, nem o valor bruto de cupons e resgate. Para 04/01/2027 houve mudança. A quantidade de dias corridos foi para 361 e a quantidade de dias úteis foi para 251. O valor bruto de cupons e regate é 11337,35 - valor semelhante a este já foi visto em simulação anterior. A esta chamarei *Simulação 5*.



[Captura de tela para 02/01/2027](./Captura%20de%20tela%20de%202025-05-20%2014-31-55.png)



[Captura de tela para 03/01/2027](./Captura%20de%20tela%20de%202025-05-20%2014-32-32.png)


![Simulação 5](./Captura%20de%20tela%20de%202025-05-20%2014-33-08.png)

Combinando esses resultados é possível afirmar que o valor bruto de cupons e resgate é calculado com base no retorno diário, considerando somente os dias úteis. Adicionalmente, o período de 01/01/2026 a 01/01/2028 tem dois dias úteis a menos que o dobro do período de 01/01/2027 a 01/01/2028 o que resulta na taxa calculada na *Simulação 3*.

### Conclusão

A calculadora do Tesouro Direto, para o título Tesouro Prefixado 2028, usa juros compostos, diários, considerando somente os dias úteis, para realizar os cálculos de valor bruto de cupons e resgate.

### Comentários

Os outros títulos prefixados devem seguir a mesma forma de cálculo.

Em outras calculadoras, cálculos com erros muito baixos, da ordem do quinto dígito devem ser obtidos se os cálculos forem feitos contando os dias úteis. O cálculo é feito usando juros compostos. 

É possível aproximar os resultados da calculadora do Tesouro Direto usando juros compostos com taxa mensal, como se faz em funcoesArray.

