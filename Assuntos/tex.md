## Exame -- adivinhe a palavra

***Esta descrição está incompleta***

Você deve implementar um jogo semelhante ao *wordle*.
Leia atentamente esta descrição, você vai ser avaliado por implementar de acordo com ela.

### Descrição do jogo

Jogue na internet para ter uma ideia de como funciona.
Basicamente, a dinâmica do jogo é:
- o jogo sorteia uma palavra de 5 letras;
- o jogador tenta adivinhar a palavra. Ele tem até seis tentativas. Em cada tentativa:
   - o jogador chuta uma palavra. A palavra só é aceita se estiver entra as palavras conhecidas pelo jogo.
   - o jogo verifica a palavra chutada, e desenha ela de uma forma especial, que diz quais letras existem ou não na palavra sorteada, e se as que existem estão na posição correta ou não.
   - se o jogador acertar a palavra, a partida termina.
   - se o jogador não acertar em 6 tentativas, a partida também termina.
- no término da partida, o programa mostra qual foi a palavra sorteada, e mostra estatísticas de desempenho do jogador.
- no jogo original, o jogo pode ser jogado somente uma vez por dia. Na nossa versão, não tem essa restrição, ao final de uma partida o programa inicia outra.

### As palavras

O programa deve conhecer um certo número de palavras para funcionar.
Iremos usar um conjunto de palavras que peguei [aqui](https://github.com/AlfredoFilho/Palavras_PT-BR).
Separei as palavras de 5 letras e tratei os acentos.
O resultado está no arquivo `palavras`, no formato descrito mais adiante.


O arquivo `palavras` contém as palavras conhecidas pelo jogo. Nesse arquivo, cada palavra está em uma linha, e o arquivo tem uma quantidade desconhecida de linhas.

Cada linha do arquivo contém duas grafias para a palavra e opcionalmente informação sobre se essa palavra já foi usada ou não. A primeira grafia contém exatamente 5 caracteres, todos eles letras minúsculas sem acento. A segunda grafia contém a mesma palavra, mas pode conter letras maiúsculas e pode ter acentos. A terceira informação é opcional, se houver é uma letra 'S', que diz que a palavra já foi usada e não deve ser sorteada. Entre as duas grafias, tem um espaço. Se houver a terceira informação, tem também um espaço antes do 'S'. No final de uma palavra tem um caractere de fim de linha `'\n'`.

Cada letra minúscula sem acento acupa um byte no arquivo, com código entre `'a'` e `'z'`. Os primeiros 5 bytes de uma linha sõa assim.

O sexto byte de uma linha é um espaço `' '`.

Cada um dos 5 caracteres da segunda grafia pode ser:
  - uma letra minúscula sem acento, representada como acima ou
  - uma letra maiúscula sem acento, ocupando um byte com código entre `'A'` e `'Z'` ou
  - uma letra acentuada, ocupando dois bytes, ambos com código diferente de letra maiúscula ou minúscula ou espaço ou final de linha.

A segunda grafia ocupa portanto entre 5 e 10 bytes no arquivo.

O byte seguinte pode ser um espaço ou um fim de linha. Se for espaço, obrigatoriamente é seguido por 'S' e por fim de linha. O caractere de fim de linha representa o final da informação sobre uma palavra, e é seguido pela próxima palavra ou pelo final do arquivo.

Você deve implementar a função abaixo, para ler uma palavra do arquivo:
```c
   bool le_palavra(FILE *arquivo, char sem_acento[5], char com_acento[10], char *usada)
```
Essa função recebe em `arquivo` um arquivo já aberto para leitura, um vetor onde colocar a primeira grafia da palavra, um vetor onde colocar a segunda grafia da palavra (mais caracteres de código 0 se a palavra tiver menos de 5 letras acentuadas) e um ponteiro onde deve colocar `'S'` se tiver essa informação no arquivo ou `'N'` caso não tenha.
A função deve retornar `true` se a linha foi corretamente lida ou `false` caso contrário (se chegar no final do arquivo ou se a linha não estiver de acordo com o descrito acima).

Você deve também implementar a função `grava_palavra`, que recebe os mesmos argumentos, mas grava a palavra recebida no arquivo, usando o mesmo formato.
```c
   bool le_palavra(FILE *arquivo, char sem_acento[5], char com_acento[10], char usada)
```

Use essas duas funções para copiar o arquivo:
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
     char sa[5];
     char ca[10];
     char usada;
     while (le_palavra(entrada, sa, ca, &usada)) {
       if (!grava_palavra(saida, sa, ca, usada)) {
         printf("problema na gravação\n");
         break;
       }
     }
     fclose(entrada);
     fclose(saida);
     return 0;
   }
```
