#include <stdio.h>

// Exemplo de implementação do E4 de lab1 2021b -- cálculo do IR

// Vamos por partes...
//
// O exercício pede:
//   "Faça uma função que recebe o salário bruto e calcula o valor do IRRF."
// E diz também que a base de cálculo para o IRRF é o salário bruto subtraído
// da contribuição do INSS.
//
// A função pedida então pode ser estruturada assim:
// float calcula_IRRF(float bruto) // recebe bruto, retorna irrf
// {
//    float base;  // para a base de cálculo
//    float inss;  // para a contribuição do inss
//    float irrf;  // para o valor do irrf
//
//    inss = ...   // calcula a contribuicao do inss
//    base = bruto - inss;
//    irrf = ...   // calcula o irrf a partir da base
//
//    return irrf; // retorna o valor pedido
// }
//
// Vamos transformar os "..." em funções auxiliares, começando pelo cálculo do
//   irrf a partir da base.
// Observando a tabela fornecida, tem 5 possibilidades de cálculo, exclusivas
// entre si (exatamente uma delas deve ser escolhida). Essa situação configura
// uma seleção múltipla. Implementando a seleção múltipla com ifs aninhados,
// temos:
//
//   ...
//   if (condicao 1) {
//     codigo 1
//   } else if (condicao 2) {
//     codigo 2
//   } else if (condicao 3) {
//     codigo 3
//   } else if (condicao 4) {
//     codigo 4
//   } else {
//     codigo 5
//   }
//   ...
// 
// Em uma seleção múltipla estruturada assim, está implícito no teste de cada
// condição que todas as anteriores falharam, e essa informação deve ser usada
// para simplificar o teste.
// Fazendo na ordem da tabela, o primeiro teste seleciona valores até 1903.98,
// o segundo teste não precisa testar outra vez contra esse valor, só precisa
// testar contra 2826.65 e assim por diante. O último caso não precisa de teste
// porque os testes anteriores já eliminaram todas as outras possibilidades.
//
// A tabela faz a escolha da alíquota do imposto e da parcela a deduzir, a
// partir da base de cálculo. Para tornar a tradução mais direta, vamos fazer
// o mesmo.
//
// Uma vez tendo a alíquota e a parcela a deduzir, o cálculo do imposto é feito
// aplicando a alíquota à base de cálculo e subtraindo a dedução.
// A função para calcular o IRRF partindo da base de cálculo pode ser então 
// escrita:

float calcula_irrf_a_partir_da_base(float base)
{
  float aliquota, deducao;
  float irrf;

  if (base <= 1903.98) {
    aliquota =   0.0;
    deducao  =   0.00;
  } else if (base <= 2826.65) {
    aliquota =   7.5;
    deducao  = 142.80;
  } else if (base <= 3751.05) {
    aliquota =  15.0;
    deducao  = 354.80;
  } else if (base <= 4664.68) {
    aliquota =  22.5;
    deducao  = 636.13;
  } else {
    aliquota =  27.5;
    deducao  = 869.36;
  }

  irrf = base * aliquota/100 - deducao;

  return irrf;
}

// Quer treinar um pouco? Refaça a função implementando a tabela de trás pra
// diante (teste primeiro a última linha da tabela, depois a penúltima etc).
// Teste as implementações, elas dão o mesmo valor de retorno para os mesmos
// dados de entrada?
//
// Dependendo de como for interpretada a descrição do exercício, isso seria
// suficiente. Mas queremos fazer um programa completo, então vamos fazer 
// também a função para cálculo do inss a partir do salário bruto. Olhando
// no link referenciado no exercício anterior, também temos 5 casos exclusivos.
// Mas da forma como a tabela é apresentada, os cálculos são mais complicados
// um pouco. Poderíamos usar a tabela simplificada com a "dedução", que está 
// mais adiante na página, e o cálculo seria semelhante ao do IR.
// Para não ficar repetido, vamos implementar com a tabela não simplificada.
// Nesse caso, quando se calcula em uma faixa, deve-se somar o valor máximo de
// todas as faixas anteriores mais o valor da faixa considerada.
// O código pode ser assim:

float calcula_inss(float bruto)
{
  // vamos colocar os limites e aliquotas de cada faixa em variáveis:
  float l1 = 1045.00, l2 = 2089.60, l3 = 3134.40, l4 = 6101.06;
  float a1 = 7.5/100, a2 = 9.0/100, a3 = 12.0/100, a4 = 14.0/100;
  float inss;

  if (bruto <= l1) {
    inss = bruto * a1;
  } else if (bruto <= l2) {
    inss = l1 * a1
         + (bruto - l1) * a2;
  } else if (bruto <= l3) {
    inss = l1 * a1
         + (l2 - l1) * a2
         + (bruto - l2) * a3;
  } else if (bruto <= l4) {
    inss = l1 * a1
         + (l2 - l1) * a2
         + (l3 - l2) * a3
         + (bruto - l3) * a4;
  } else {
    inss = l1 * a1
         + (l2 - l1) * a2
         + (l3 - l2) * a3
         + (l4 - l3) * a4;
  }

  return inss;
}

// Sempre que se faz uma função, é importante certificar-se de que esteja OK
// antes de prosseguir. No caso do INSS, esse teste é fácil de ser feito, 
// usando alguns exemplos da página citada:
// int main()
// {
//   printf("%f\n", calcula_inss(1300));
//   printf("%f\n", calcula_inss(4800));
//   printf("%f\n", calcula_inss(7000));
//   return 0;
// }
//
// Seria importante encontrar exemplos do IRRF também (exercício para o leitor).
//
// Tendo essas duas funções auxiliares implementadas, podemos completar a
// função que calcula o irrf a partir do salario bruto:

float calcula_IRRF(float bruto) // recebe bruto, retorna irrf
{
   float base;  // para a base de cálculo
   float inss;  // para a contribuição do inss
   float irrf;  // para o valor do irrf

   inss = calcula_inss(bruto);
   base = bruto - inss;
   irrf = calcula_irrf_a_partir_da_base(base);

   return irrf; // retorna o valor pedido
}

// E podemos fazer uma função principal, que interage com o usuário:
int main()
{
  double sal_bruto, irrf;
  printf("digite o salario bruto ");
  scanf("%lf", &sal_bruto);
  irrf = calcula_IRRF(sal_bruto);
  printf("IRRF: %.2f\n", irrf);
  return 0;
}

// Dúvidas? Mail!
