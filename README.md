Repositório com os códigos utilizados para a elaboração do artigo ANÁLISE DE VIBRAÇÃO DE MOTORES POR REDE NEURAL PERCEPTRON MULTICAMADAS para o curso de especialização em sistemas embarcados pelo Senai Anchieta.

O projeto consiste em medir, salvar e analisar, através de redes neurais, as vibrações do motor de um ventilador de mesa.
Foram coletados dados com o ventilador em condições normais e atípicas (parafuso solto, tampa solta, pá desbalenceada)

Sensor utilizado para medir as vibrações foi o MPU-6050, que possui acelerômetro e giroscópio nos 3 eixos.
Microcontrolador utilizado foi um ESP32. IDE utilizada foi do Arduino. 
Código: **MPU6050-ESP32-2g-pt.ino**

Os dados do sensor podem ser lidos pela porta serial, um código em python salva os dados em formato csv.
Código: **salva dados serial esp32.py**
Este código foi modificado para alterar o nome do arquivo que seria gerado, de acordo com o estado do ventilador.

Com o notebook colab **RNA_analise_limpeza_dos_dados.ipynb** foi feita a analise e tratamento dos dados, quando necessário.
Na coleta dos dados pode ocorrer inconsistências, como letras ao invés de números.
Os dados coletados com o ventilador em estado nok foram incluídos em um único arquivo, esta etapa do código está comentada neste notebook.
Lá também foram incluídos os cabeçalhos. Após a análise os arquivos foram salvos.

O treinamento da rede neural artificial foi feita no notebook **Redes_Neurais_MLP_|_MPU_6050.ipynb**
Foram realizados diversos treinamentos de forma iterativa.
Foram alteradas a arquitetura da rede, incluindo a quantidade de entradas, números de camadas ocultas e de neurônios além da funções de otimização.
As configurações utilizadas são descritas no artigo, além da comparação entre os treinamento realizados.
Na branch "artigo" os códigos dos notebooks foram alterados para contemplar apenas o que foi utilizado na elaboração do artigo. 



