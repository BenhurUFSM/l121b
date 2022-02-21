## Exame -- adivinhe a palavra

* * *
   ***Alterações deste texto***
   - 19fev - primeira versão, incompleta
   - 20fev, 12h30 - primeira versão completa
   - 21fev, 0h25 - clarificação sobre o link com as palavras

* * *

Você deve implementar um jogo semelhante ao *wordle*.
Leia atentamente esta descrição, você vai ser avaliado por implementar de acordo com ela.

### Descrição do jogo

Jogue na internet para ter uma ideia de como funciona.
Basicamente, a dinâmica do jogo é:
- o jogo sorteia uma palavra de 5 letras;
- o jogador tenta adivinhar a palavra. Ele tem até seis tentativas. Em cada tentativa:
   - o jogador chuta uma palavra. A palavra só é aceita se estiver entra as palavras conhecidas pelo jogo.
   - o jogo verifica a palavra chutada, e desenha ela de uma forma especial, que diz quais letras dela existem ou não na palavra sorteada, e se as que existem estão na posição correta ou não.
   - se o jogador acertar a palavra, a partida termina (com vitória).
   - se o jogador não acertar em 6 tentativas, a partida também termina (com derrota).
- no término da partida, o programa mostra qual foi a palavra sorteada, e mostra estatísticas de desempenho do jogador.
- no jogo original, o jogo pode ser jogado somente uma vez por dia. Nossa versão não tem essa restrição: ao final de uma partida o programa oferece outra.
- na nossa versão, o jogador poderá desistir da jogada, digitando a palavra "desisto". O jogo se comporta nesse caso da mesma forma que quando o jogador erra a sexta tentativa.

### As palavras

O programa deve conhecer um certo número de palavras para funcionar.
Iremos usar um conjunto de palavras que adaptei da lista disponível em `https://github.com/AlfredoFilho/Palavras_PT-BR`.
Separei as palavras de 5 letras e tratei os acentos.
O resultado está no arquivo [palavras](https://github.com/BenhurUFSM/l121b/blob/main/Assuntos/palavras), no formato descrito mais adiante.

Para cada palavra, teremos duas versões, uma sem acentos e toda em minúsculas, para facilitar a identificação.
O usuário irá digitar somente letras sem acento, e a palavra digitada será comparada com essa versão.
A segunda versão é a palavra original, podendo conter letras maiúsculas e letras acentuadas.
Essa versão será usada para a apresentação das palavras ao usuário com a informação de acerto e erro.

O arquivo `palavras` contém as palavras conhecidas pelo jogo. Ao todo, 16734 palavras. Cada palavra está em uma linha do arquivo, no formato descrito abaixo.

Cada linha do arquivo contém as duas grafias para a palavra e opcionalmente informação sobre se essa palavra já foi usada ou não. A primeira grafia contém exatamente 5 caracteres, todos eles letras minúsculas sem acento. A segunda grafia contém a mesma palavra, mas pode conter letras maiúsculas e pode ter acentos. A terceira informação é opcional, se houver é uma letra 'S', que diz que a palavra já foi usada e não deve ser sorteada. Entre as duas grafias, tem um espaço. Se houver a terceira informação, tem também um espaço antes do 'S'. No final de uma palavra tem um caractere de fim de linha `'\n'`.

Cada letra minúscula sem acento acupa um byte no arquivo, com código entre `'a'` e `'z'`. Os primeiros 5 bytes de uma linha são assim.

O sexto byte de uma linha é um espaço `' '`.

Cada um dos 5 caracteres da segunda grafia pode ser:
  - uma letra minúscula sem acento, representada como acima, ou
  - uma letra maiúscula sem acento, ocupando um byte com código entre `'A'` e `'Z'`, ou
  - uma letra acentuada, ocupando dois bytes, ambos com código diferente de letra maiúscula ou minúscula ou espaço ou final de linha.

A segunda grafia ocupa portanto entre 5 e 10 bytes no arquivo.

O byte seguinte à segunda grafia pode ser um espaço `' '` ou um fim de linha `'\n'`. Se for espaço, obrigatoriamente é seguido por `'S'` e por fim de linha `'\n'`. O caractere de fim de linha representa o final da informação sobre uma palavra, e é seguido pela próxima palavra ou é o último byte do arquivo.

Em memória, uma palavra será armazenada na estrutura abaixo:
```c
   typedef struct {
     char sem_acento[5];
     char com_acento[10];
     bool usada;
   } palavra_t;
```

Você deve implementar a função abaixo, para ler uma palavra do arquivo:
```c
   bool le_palavra(FILE *arquivo, palavra_t *p)
```
Essa função recebe em `arquivo` um descritor de arquivo já aberto para leitura, e em `p` um ponteiro para uma estrutura de armazenamento de uma palavra.
A função deve ler a próxima palavra do arquivo e preencher a estrutura. O campo `com_acento` deve ter seu final completado com caracteres de código 0 caso a palavra tenha menos de 5 letras acentuadas.
O campo `usada` será preenchido com `true` se houver o `S` no final da linha e com `false` caso contrário.
A função deve retornar `true` se a linha foi corretamente lida ou `false` caso contrário (se chegar no final do arquivo ou se a linha não estiver de acordo com o descrito acima).

Você deve também implementar a função `grava_palavra`, que recebe uma estrutura preenchida e grava uma linha no arquivo, no mesmo formato:
```c
   bool grava_palavra(FILE *arquivo, palavra_t palavra)
```

Teste essas duas funções fazendo um programa para copiar o arquivo:
```c
   int main()
   {
     FILE *entrada;
     FILE *saida;
     entrada = fopen("palavras", "r");
     saida = fopen("copia-das-palavras", "w");
     if (entrada == NULL || saida == NULL) {
       printf("Erro no acesso aos arquivos\n");
       exit(1);
     }
     palavra_t palavra;
     while (le_palavra(entrada, &palavra)) {
       if (!grava_palavra(saida, palavra)) {
         printf("problema na gravação\n");
         break;
       }
     }
     fclose(entrada);
     fclose(saida);
     return 0;
   }
```
Os arquivos ficaram iguais?

O programa deverá manter em memória a lista completa de palavras.
Por simplicidade, como conhecemos o número total de palavras, vamos mantê-las em um vetor simples de tamanho fixo:
```c
   #define NUM_PALAVRAS 16734
   palavra_t lista_de_palavras[NUM_PALAVRAS];
```

Faça uma função que recebe o nome de um arquivo e o vetor acima e preenche o vetor com as palavras lidas do arquivo (usando a função de leitura de uma palavra vista acima).
A função deve retornar um `bool` dizendo se a leitura foi bem sucedida (leu todas as NUM_PALAVRAS) ou não.

Faça outra função, que atualiza a lista de palavras no arquivo. Ela recebe o nome do arquivo e a lista de palavras, grava todas as palavras em um arquivo temporário (usando a função de escrita de uma palavra, acima) e, se for bem sucedida, renomeia o arquivo temporário (após fechá-lo) para o nome recebido.
Essa função também deve retornar um `bool` que informa se foi bem sucedida.

### Sorteio da palavra

A cada partida, o jogo deve sortear uma palavra a ser adivinhada pelo jogador.
A palavra sorteada pode ser qualquer uma da lista, que ainda não tenha sido usada.
Faça uma função que recebe a lista de palavras e retorna um inteiro com a posição na lista da palavra sorteada.
A função deve chutar um número aleatório entre `0` e `NUM_PALAVRAS-1`, até que a palavra nessa posição seja uma palavra não usada.

### Avaliação de um chute

Um chute é uma palavra que o usuário digita, para tentar a palavra sorteada.
Um chute deve ser submetido a duas análises: uma para saber se é um chute válido e outra para produzir as dicas sobre esse chute para o usuário.
Vamos usar uma estrutura para armazenar um chute:
```c
   typedef struct {
     char letras[5];    // as letras que o jogador chutou
     palavra_t palavra; // a palavra correspondente ao chute
     char dicas[5];     // a classificação de cada letra do chute
     bool correto;      // true se a palavra corresponde à sorteada
   } chute_t;
```
O campo `letras` tem as 5 letras usadas que compõe o chute, todas minúsculas.
O campo `palavra` contém uma cópia da palavra corresondente ao chute na lista de palavras.
O campo `dicas` tem, para cada letra, a informação se ela pertence à palavra sorteada e está na posição correta (representado por um 'v'), se ela pertence à palavra mas está em posição incorreta (representado por um 'l') ou se ela não pertence à palavra (representado por um 'c').
O campo `correto` é somente para facilitar a verificação de se a palavra é igual a sorteada ou não (vai ser `true` se as 5 dicas forem 'v').

A primeira função recebe um ponteiro para um chute e a lista de palavras, e retorna um bool dizendo se o chute é válido ou não.
O chute é considerado válido se ele é igual a uma das palavras da lista (comparando suas 5 letras com as 5 letras sem acento da palavra).
No caso de o chute ser válido, a função copia a palavra correspondente da lista de palavras para a estrutura do chute.
```c
   bool chute_valido(chute_t *pchute, palavra_t lista[NUM_PALAVRAS])
```

A função que analisa um chute vai receber um ponteiro para o chute e a palavra correta, e vai preencher os campos `dicas` e `correto` do chute.
Uma forma simples de calcular as dicas, que funciona com letras repetidas, é a seguinte:
- inicializa as dicas com 'c';
- para cada uma das 5 posições, se a letra do chute e da palavra nessa posição forem iguais, marca a dica dessa posição com 'v';
- para cada posição, se a dica nessa posição não for 'v', busca a letra que está nessa posição *na palavra*, em uma outra posição *no chute*, que tenha dica igual a 'c' e muda essa dica para 'l'.
- se todas as dicas forem 'v', coloca `correto` em `true`, senão, coloca em `false`.
```c
   void analisa_chute(chute_t *pchute, palavra_t palavra_sorteada)
```

### Vetor de letras usadas

Para auxiliar o jogador, o jogo apresenta para ele o conjunto das 26 letras, classificando cada uma em:
- não usada (ainda não foi usada em nenhum chute)
- não existente (já foi usada em algum chute, mas não existe na palavra sorteada)
- em posição errada (já foi usada em algum chute, mas nunca na posição correta)
- em posição certa (já foi usada na posição correta em algum chute)
Em memória, essa informação vai ser mantida em um vetor de 26 posições (uma para cada letra), com sua situação codificada pelas letras 'n', 'c', 'l' ou 'v', respectivamente à lista acima.
No início de uma partida esse vetor é inicializado com 'n' em todas as posições, e a função abaixo atualiza as posições do vetor após a análise de cada chute:
```c
   void atualiza_letras_usadas(chute_t chute, char letras_usadas[26])
```
Essa função verifica cada letra do chute. Cada letra que for marcada com 'v' no chute deve ser marcada também com 'v' no vetor de letras usadas. As que forem marcadas com 'l' no chute e que não estejam marcadas com 'v' no vetor de letras usadas, devem ser marcadas com 'l' nesse vetor. As que estão marcadas com 'c' no chute e que estejam com 'n' no vetor são marcadas com 'c' no vetor.

### Representação de uma partida em memória

Uma partida é constituída por uma palavra sorteada, pelo conjunto de até seis chutes e pelo vetor de letras usadas.
Em memória, essa partida será implementada pela estrutura abaixo:
```c
typedef struct {
  palavra_t sorteada;     // a palavra que o jogador deve adivinhar
  int nchutes;            // quantos chutes já foram feitos
  chute_t chutes[6];      // aqui estão os chutes
  char letras_usadas[26]; // vetor com o estado de cada letra
} partida_t;
```

### Desenho da tela

Antes de pedir cada chute do usuário, a tela mostrando a situação da partida deve ser desenhada.
O desenho da tela é realizado com as informações constantes na estrutura partida acima.
Devem ser mostrados todos os chutes já realizados e espaço para os não realizados.
Deve ser mostrado também o conjunto de letras.

Cada letra de um chute será desenhado na tela ocupando 3 linhas de 3 caracteres. A cor de fundo desses caracteres será escolhida conforme a dica armazenada para o caractere no chute:
- se a dica for 'c' deverá ser cinza;
- se a dica for 'l' deverá ser laranja;
- se a dica for 'v' deverá ser verde.
Os caracteres são espaços, exceto o do meio, que será o caractere correspondente ao chute.

O desenho de cada chute ocupará 4 linhas na tela:
- a primeira contém, para cada um dos 5 caracteres do chute, 3 espaços com a cor de fundo correspondente ao caracter seguidos por um espaço na cor de fundo normal;
- a segunda contém, para cada um dos 5 caracteres do chute, 1 espaços com a cor de fundo correspondente ao caracter, seguido pelo caractere, seguido por outro espaço ainda com a mesma cor de fundo, seguido por um espaço na cor de fundo normal;
- a terceira é igual à primeira;
- a quarta é em branco.

O desenho dos chutes ainda não realizados será feito da mesma forma, só que tem espaço no lugar do caracter e o fundo é cinza escuro para todos eles.

O conjunto de letras é desenhado após os chutes, seguindo a mesma codificação de cor de fundo (cinza escuro, cinza, laranja e verde para 'n', 'c', 'l' ou 'v').

### Funcionamento Geral do programa

O funcionamento geral do jogo deve ser:
1. o programa lê o arquivo de palavras
2. o programa sorteia uma palavra, marca como usada, atualiza o arquivo de palavras e inicializa a estrutura da partida
3. o programa desenha a tela principal
4. o programa pede um chute ao jogador
5. se o chute for "desisto", continua no passo 11
6. se o chute não for válido, informa o jogador e volta ao passo 2
7. o programa insere o chute na estrutura da partida, analisa ele, atualiza o vetor de letras
8. se o chute for correto, desenha a tela, felicita o jogador, continua no passo 12
9. se foi o último chute (sexto), desenha a tela, infelicita o jogador, continua no passo 11
10. volta para o passo 3
11. informa a palavra sorteada ao jogador
12. pergunta se quer jogar de novo e volta ao passo 2 se for o caso, senão vai para o passo 13
13. termina o programa

Organize isso!

### Extras

Se você quer um desafio maior, ou se está precisando garantias melhores na nota:
- faça a lista de palavras com tamanho não fixo, usando alocação dinâmica de memória.
- implemente a variação `difícil`, em que um chute só é aceito se, além de estar na lista, ela usa as dicas do chute anterior (tem que ter as letras verdes na mesma posição e tem que usar as letras laranja).
- implemente estatísticas: ao final de cada partida, incremente um contador correspondente ao número de tentativas para descobrir a palavra (1 a 6) ou o contador de palavra não descoberta. Apresente esses valores ao usuário. Mantenha esses valores em um arquivo.

Envie mail em caso de dúvidas. Se as dúvidas levarem a uma alteração desta descrição, será colocada uma linha no início informando a alteração.
