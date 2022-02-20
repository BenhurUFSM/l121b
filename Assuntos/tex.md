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

Será fornecido um arquivo com as palavras conhecidas pelo jogo. Nesse arquivo, cada palavra está em uma linha, e o arquivo tem uma quantidade desconhecida de linhas.

Cada linha do arquivo contém duas grafias para a palavra e opcionalmente informação sobre se essa palavra já foi usada ou não. A primeira grafia contém exatamente 5 caracteres, todos eles letras minúsculas sem acento. A segunda grafia contém a mesma palavra, mas pode conter letras maiúsculas e pode ter acentos. A terceira informação é opcional, se houver é uma letra 'S', que diz que a palavra já foi usada e não deve ser sorteada. Entre as duas grafias, tem um espaço. Se houver a terceira informação, tem também um espaço antes do 'S'. No final de uma palavra tem um caractere de fim de linha `'\n'`.
