## Simulador de Tarefas em C

Este repositório contém a implementação de um programa em linguagem C que simula e exibe a execução de tarefas solicitadas a um processador. As tarefas incluem deletar, gravar em dispositivo externo, gravar em dispositivo interno, imprimir e ler.

### Recursos e Observações:

 - Implementa uma interface intuitiva para facilitar o entendimento da simulação, mostrando a fila de tarefas e o que está sendo executado no momento.
 - As unidades de tempo são usadas para controlar a execução das tarefas.
 - A cada duas unidades de tempo, uma tarefa é solicitada, seguindo uma ordem de prioridade: gravar em dispositivo interno (maior prioridade), gravar em dispositivo externo, deletar, ler e imprimir (menor prioridade).
 - As tarefas executadas são removidas da fila do processador após o tempo determinado.
 - A simulação é finalizada quando o arquivo de texto é totalmente consumido. Ao pressionar a tecla ESC, os dados são armazenados em um arquivo de texto para retomada da simulação.
 - Ao final da execução da simulação, são fornecidos os totais de tarefas executadas por cada processador e o total individual por tipo de tarefa solicitada.

Este projeto é adequado para fins educacionais e de aprendizado de conceitos de programação em C, bem como para demonstrar o funcionamento de sistemas de simulação de tarefas.
