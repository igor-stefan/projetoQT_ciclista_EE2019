# Projeto_Ciclistas

### Organiza os dados de um pelotão em uma tabela e gera estatísticas com base nos dados.
<p align="justify"> Aplicação desenvolvida para facilitar o monitoramento de um pelotão de ciclistas baseado em um percurso realizado (distância e tempo) e algumas informações pessoais (nome, idade e peso). Calcula o gasto energético de cada ciclista, as respectivas velocidades médias e mostra todos os dados em uma tabela. É possível realizar o ordenamento da tabela de acordo com o parâmetro escolhido além de serem exibidas em uma segunda aba, as estatísticas referentes ao pelotão. Também é possível salvar esses dados em um arquivo do tipo .csv, bem como carregar dados salvos anteriormente.</p>


# Manual do Usuário

### Cadastro:
<p align="justify"> O programa possui um interface intuitiva, alguns botôes, alguns campos de texto e uma tabela para exibição dos dados.</p>
<p>O formulário deve ser preenchido de acordo com o parâmetro especificado e ao final, clicar no botão "Adicionar" para fazer o cadastro do ciclista. Os dados do ciclista cadastrado serão exibidos na tabela e as estatísticas calculadas automaticamente. A cada novo cadastro, as estatísticas são recalculadas e o novo ciclista é adicionado na tabela.</p>
<p align="justify"> Caso o mesmo ciclista tente ser cadastrado duas vezes, o programa apagará todos os campos de texto e não cadastrará o ciclista, o mesmo acontece para campos em branco.</p>
<p align="justify"><b>Ou seja, é obrigatorio o preenchimento de todos os campos para realização do cadastro.</b></p>

### Ordenamento
<p align="justify">Os dados podem ser ordenados de sete maneiras diferentes. </p>
<p align="justify"><b>1. Nome:</b> Ordena os cicistas de acordo com o nome por ordem alfabética. Não há diferença entre letras  maiúsculas e minúsculas no ordenamento.</p>
<p align="justify"><b>2. Idade:</b> Ordena os cicistas de acordo com a idade por ordem crescente.</p>
<p align="justify"><b>3. Peso:</b> Ordena os cicistas de acordo com o peso por ordem decrescente.</p>
<p align="justify"><b>4. Dsitância:</b> Ordena os cicistas de acordo com a distância por ordem decrescente.</p>
<p align="justify"><b>5. Tempo:</b> Ordena os cicistas de acordo com o tempo por ordem crescente.</p>
<p align="justify"><b>6. Velocidade média:</b> Ordena os cicistas de acordo com a velocidade média por ordem decrescente.</p>
<p align="justify"><b>7. Gasto energético:</b> Ordena os cicistas de acordo com o gasto energético por ordem decrescente.</p>

### Limpando a Tabela
<p align="justify">O programa possuí um botão no canro inferior direito que tem a função de limpar a tabela. Será apresentada uma caixa de diálogo confirmando a remoção dos dados da tabela. Após a limpeza, todos os dados não salvos serão perdidos.</p>

### Salvar e Carregar
<p align="justify">No canto superior direito o programa possui um menu "Arquivo" que ao ser selecionado apresenta duas opções. Depois de escolhida a opção será aberta uma janela para o usuário indicar o endereço do arquivo a ser salvo ou carregado.</p>
<p align="justify"><b>Salvar:</b> O usuário deve escolher o local para salvar o arquivo, colocar um nome e selecionar "Salvar".</p>
<p align="justify"><b>1.Carregar:</b> O usuário deve procurar o arquivo .csv e selecionar "Abrir" para carregar os dados salvos para o programa.</p>
<p align="justify"><b>Observação: </b>Não é possível unir os ciclistas cadastrados com algum arquivo carregado. Os dados existentes na tabela serão perdidos quando realizado o carregamento de um arquivo.</p>

### Editar dados da Tabela
<p align="justify">Para editar os dados da tabela o usuário deve dar dois cliques na célula que deseja alterar a informação. Uma caixa de dialógo será aberta para confirmar a edição, mediante resposta positiva, outra caixa de diálogo solicitará o novo valor. Feito o procedimento de edição, a tabela e as estatísticas são atualizadas automaticamente.</p>

### Estatísticas
<p align="justify">Na segunda aba são exibidas em três grupos as estatísticas calculadas com base nos dados.</p>
<p align="justify"><b>1. Desvio Padrão:</b> Calculo do desvio padrão das distâncias, dos tempos e das velocidades médias.</p>
<p align="justify"><b>2. Média:</b> Calculo da média das distâncias, dos tempos e das velocidades médias.</p>
<p align="justify"><b>3. Destaques:</b> Mostra o ciclista que obteve a maior distância percorrida, o menor tempo gasto para realizar o percurso e a maior velocidade média, respectivamente.</p>
<p align="justify">A imagem abaixo mostra a aba "estatísticas" no formato padrão.</p>



