# l121b - Laboratório de Programação I
ELC1065 DLSC/CT/UFSM\
turmas SI1 e CC1, segundo semestre 2021\
professor: Benhur Stein ([benhur+l121b@inf.ufsm.br](mailto:benhur%2bl121b@inf.ufsm.br))\
monitor: ainda nao tem [a.n.tem@inf.ufsm.br]\
terças e quintas, 14h30, no servidor discord da disciplina


## Desenvolvimento da disciplina

Os canais de comunicação entre o professor e os alunos são esta página (<https://github.com/BenhurUFSM/l121b>), o servidor discord da disciplina (<https://discord.gg/EU5GNyDu8X>) e e-mail para [benhur+l121b@inf.ufsm.br](mailto:benhur%2bl121b@inf.ufsm.br).
Outros canais que eventualmente sejam criados serão comunicados aqui.

Antes da primeira aula (programada para 14h30 do dia 14out) os alunos **devem** enviar um e-mail inicial para o professor para confirmar o seu endereço de e-mail, e **devem** se inscrever no servidor discord. Vale nota!

O e-mail pode ser usado para o envio de perguntas, respostas aos exercícios, reclamações, sugestões, críticas e o que mais for, durante todo o período em que durar a disciplina.

Esta página concentrará os assuntos vistos em aula, a descrição de exercícios e trabalhos, avaliações, etc. Ela estará sendo aumentada/atualizada durante todo o semestre. Ela é o canal mais oficial de informações sobre a disciplina. Os alunos devem consultar esta página frequentemente.

A disciplina de laboratório de programação I é bastante prática, e exige que os alunos se dediquem bastante e desenvolvam trabalhos práticos.
O objetivo da disciplina, aprender a programar computadores, envolve conceitos que podem levar um tempo razoável para serem adquiridos.
A prática de programação tem se mostrado essencial nesse aprendizado.
Para realizar essa prática, é necessário que o aluno tenha acesso a um computador e a um ambiente de desenvolvimento de programas.
A universidade dispõe de laboratórios com computadores para acesso aos alunos, com todo o software necessário instalado; consulte o NCC caso necessite (e para saber como estã a disponibilidade em tempos pandêmicos).

Em um computador pessoal, pode-se instalar um ambiente de desenvolvimento localmente ou usar um dos vários que existem gratuitamente online.
O que se necessita como ambiente de desenvolvimento para a disciplina é o mais básico, basta um compilador da linguagem "C".
Durante as aulas, vamos usar um ambiente online, em princípio será o <www.onlinegdb.com> (ou o <replit.com>). Os exercícios e trabalhos da disciplinas podem também ser desenvolvidos nesse ambiente.

Meu ambiente pessoal de trabalho é no sistema linux, e nesse sistema posso auxiliá-los na instalação e uso de um compilador. Não tenho nenhuma experiência pessoal gratificante com windows, não vou poder auxiliá-los com problemas diretamente relacionados ao uso desse ambiente.

Por ser uma disciplina prática, a principal forma de avaliação dos alunos será através de exercícios, principalmente o desenvolvimento de pequenos programas de computador, a serem enviados para o professor. No final do semestre, deve ser desenvolvido um trabalho final um pouco mais complexo.
A descrição desses exercícios e programas, bem como a forma de entrega e avaliação dos mesmos será disponibilizada nesta página.

O distanciamento físico entre todos da turma torna o desenvolvimento da disciplina bem mais desafiante para todos nós.
Todos vamos precisar nos empenhar mais que em um semestre normal.
Eu espero conseguir ajudar o máximo o maior número de vocês.
Eu só consigo identificar os problemas através do que usarmos como canais de comunicação.
Não deixem dúvidas acumularem.
Quanto mais cedo conseguirmos nos comunicar para expor problemas, apontar sugestões etc, melhores serão nossas chances de sucesso.

##  Aulas 

|    N |   data | assunto
| ---: | :----: | :--------
|    1 |  14out | [introdução](https://github.com/BenhurUFSM/l121b/blob/main/Assuntos/01.md)
|    2 |  19out | [meu primeiro programa C](https://github.com/BenhurUFSM/l121b/blob/main/Assuntos/02.md)

<!--
|    2 |  20mai | [primeiro programa C](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/02.p1.c.md)
|    3 |  25mai | [variáveis, entrada de dados](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/03.md)
|    4 |  27mai | [tipos de dados em ponto flutuante](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/04.md)
|    5 |   1jun | [funções](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/05.md)
|    6 |   8jun | [seleção `if`, operadores de comparação](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/06.md)
|    7 |  10jun | [operadores lógicos, seleção múltipla com `if`s aninhados](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/07.md)
|    8 |  15jun | [comando de repetição `for`](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/08.md)
|    9 |  17jun | [comandos de repetição `while` e `do .. while`](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/09.md)
|   10 |  24jun | [comando de seleção `switch`; vetores](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/10.md)
|   11 |  29jun | [vetores, cont](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/11.md)
|   12 |   1jul | [strings](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/12.md)
|   13 |   6jul | [exercícios de string; sscanf, sprintf](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/13.md)
|   14 |   8jul | [passagem de parâmetros por referência](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/14.md)
|   15 |  13jul | [arquivos](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/15.md)
|   16 |  15jul | [exercícios](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/16.md)
|   17 |  20jul | [registros](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/17.md)
|   18 |  22jul | [exercícios](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/18.md)
|   19 |  27jul | [exercícios](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/18.md)
|   20 |  29jul | [alocação dinâmica de memória](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/20.md)

  , organização de computadores (CPU (UC+ULA), Mem, E/S), "tudo é número!"
  [2]   3nov   programa básico em C, *printf*, expressões numéricas
  [3]   5nov   números binários, tipos de dados básicos em C, variáveis, *scanf*
  [4]  10nov   funções
  [5]  12nov   exercícios
  [6]  17nov   correção dos exercícios; operadores de comparação; comando de seleção *if*
  [7]  19nov   correção dos exercícios; *if*s aninhados para seleção múltipla
  [8]  24nov   operadores lógicos; comando de repetição *while*
  [9]  26nov   comandos *break* e *continue* em laços; operadores de atribuição
 [10]  1dez    comandos *for* e *do .. while*
 [11]  3dez    comando *switch*; vetores
       8dez    feriado
 [12]  10dez   matrizes
 [13]  15dez   arquivos
  14   17dez   ?
 [15]  5jan    passagem de argumentos por referência (ponteiros)
 [16]  7jan    funções recursivas
 [17]  12jan   implementação trabalho 3
 [18]  14jan   registros (struct)
 [19]  19jan   exemplo comentado de registros (struct)
 [20]  21jan   alocação dinâmica de memória


-->

## Exercícios, trabalhos e provas

|    id |      prazo | assunto
| ----: | ---------: | :-----------
|    E1 | 14out14h30 | envio de email de confirmação, acesso ao discord
|    E2 | 18out      | ver aula 1 (só deixa de ser 18out quando for 19out)

<!--
|    e2 | 27mai14h30 | ver aula 3
|    e3 | 8jun14h  | ver aula 5
|    t1 | 15jun14h | ver aula 6
|    t2 | 10jul    | ver aula 11 ([exemplo](https://github.com/BenhurUFSM/l121a/blob/main/Complementos/t2.c))
|    t3 | ~~3ago~~ 5ago | ver aula 16 (foi adicionada a parte 2)
|    t4 | ASD | [threes](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/t4.md)
| exame | 9set | Prova online; veja [esquenta](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/ex.md)
-->

## Ementa

Ver [aqui](https://www.ufsm.br/ementario/disciplinas/elc1065/).

## Material Auxiliar

[Apostila de C da UFPR](http://www.inf.ufpr.br/cursos/ci067/Docs/NotasAula.pdf)

[Curso de programação C da UFMG](http://www2.dcc.ufmg.br/disciplinas/pc/source/introducao_c_renatocm_deeufmg.pdf)

[Apostila de programação da UFPR](http://www.inf.ufpr.br/cursos/ci055/apostila.pdf)

Ajude o robozinho a iluminar o mundo (ajuda no desenvolvimento de lógica de programação, fundamental para o conteúdo da disciplina) [lightbot](http://lightbot.com).

Ajude o passarinho a detonar o porco (semelhante ao anterior) [code.org](http://studio.code.org/hoc/1)

O PET oferece tópicos de apoio a disciplinas iniciais.

## Avaliações etc

Veja a [planilha](https://docs.google.com/spreadsheets/d/1-SgO56hzFQxO4gkc4D3xHmZL5XLBkYXJpWwtPgEOTOg/edit?usp=sharing).
