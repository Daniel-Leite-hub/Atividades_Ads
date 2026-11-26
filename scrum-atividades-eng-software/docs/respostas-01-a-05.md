# Respostas das Atividades de Scrum (01 a 05)

**Disciplina:** Engenharia de Software  
**Alunos:** Daniel Alves · Kaio Costa · Francisco Breno  
**Produto:** Aplicativo de reserva de salas de estudo da biblioteca (Sala 1)

---

## Atividade 01 — Introdução ao Scrum

### Papéis por rodada
- **Rodada 1:** Product Owner: Daniel · Scrum Master: Kaio · Developers: Francisco
- **Rodada 2:** Product Owner: Francisco · Scrum Master: Daniel · Developers: Kaio

### Protótipo e testes (09h livre, 10h ocupada, 11h livre)
- **Rodada 1 (versão inicial):**
  - **09:00:** exibiu **"Livre"**. O colega entendeu na hora.
  - **10:00:** a resposta ficou **em branco**. O colega clicou novamente e perguntou se o aplicativo tinha travado.
- **Rodada 2 (versão melhorada):**
  - **11:00 / 09:00:** exibiu **"Livre"**.
  - **10:00:** exibiu **"Ocupado — escolha outro horário"**. A segunda colega entendeu imediatamente que precisava escolher outro horário.

### Respostas (Atividade 2)
1. **Transparência:** Deixamos visíveis na tela os horários da Sala 1 (09h, 10h e 11h), o botão Consultar e o espaço da resposta, para o colega e o trio verem exatamente a mesma coisa.
2. **Inspeção:** O colega identificou o horário livre às 09h sem dificuldade, mas às 10h a tela em branco causou confusão e ele achou que o app havia travado.
3. **Adaptação:** Trocamos a resposta em branco pela mensagem "Ocupado — escolha outro horário", e no segundo teste a colega entendeu na hora.
4. **Valor do Scrum:** **Abertura** — reconhecemos diante do teste que a primeira tela confundia o usuário e mudamos o protótipo em vez de defender a ideia inicial.

---

## Atividade 02 — Papéis, Artefatos e Eventos do Scrum

### Papéis no trio
- **Product Owner:** Daniel · **Scrum Master:** Kaio · **Developers:** Francisco

### 1. Product Backlog
- **Meta do Produto:** Permitir que estudantes reservem salas de estudo sem conflito de horário.
- **Ordem do Product Backlog:**
  1. **Reservar sala**
  2. **Cancelar reserva**
  3. **Receber lembrete**
- **Por que a reserva vem primeiro:** Porque sem conseguir fazer uma reserva no aplicativo, não existe reserva para cancelar nem para enviar lembrete.

### 2. Planejamento da Sprint e Reunião Diária
- **Meta da Sprint:** O estudante reserva um horário livre da Sala 1 e não consegue reservar um horário ocupado.
- **Sprint Backlog:**
  - Tela de escolha de horários (09:00 livre e 10:00 ocupada)
  - Tela de confirmação de reserva
  - Tela e aviso de horário ocupado *(adicionada na Reunião Diária)*
  - Executar Teste A e Teste B
- **Ajuste na Reunião Diária:** No primeiro rascunho só havia a tela de confirmação. Se alguém escolhesse 10:00, o aplicativo confirmaria uma reserva duplicada e quebraria a Meta da Sprint. Por isso, incluímos no Sprint Backlog a tarefa de bloquear horário ocupado e avisar o usuário.

### 3. Registro dos testes e critério de conclusão
- **Critério de conclusão:** Telas legíveis e os dois testes aprovados.
- **Teste A (09:00 livre):** Esperado confirmar a reserva → Obtido: `"Reserva confirmada — Sala 1 às 09:00"` (**PASSOU**).
- **Teste B (10:00 ocupada):** Esperado avisar que está ocupado sem confirmar → Obtido: `"Horário ocupado"` e nenhuma reserva criada (**PASSOU**).

### 4. Revisão da Sprint e Retrospectiva
- **Revisão da Sprint (produto):** A colega convidada comentou que, ao ver o horário das 10h ocupado, gostaria de já ver qual é o próximo horário livre. O PO incluiu no Product Backlog o item *"sugerir próximo horário livre"* logo após o cancelamento, pois agiliza a escolha de quem encontrou conflito.
- **Retrospectiva (jeito de trabalhar):** Quase esquecemos o aviso de horário ocupado porque desenhamos as telas antes de pensar nos testes. Combinamos que, na próxima Sprint, vamos escrever os casos de teste (inclusive os de erro) antes de desenhar as telas.

---

## Atividade 03 — Product Owner

### Meta do Produto
> Fazer com que as salas reservadas sejam realmente usadas pelos estudantes.

### 1. Primeira decisão (cenário inicial: 5 atrasos na semana)
- **Papéis:** PO: Daniel · SM: Kaio · Developers: Francisco
- **Ordem do Product Backlog:**
  1. **A · Enviar lembrete**
  2. **B · Cancelar reserva**
  3. **C · Personalizar cores**
- **Justificativa:** O envio de lembrete vem primeiro porque resolve os 5 atrasos observados na semana e o aplicativo já consegue enviar notificações. Personalizar as cores pode esperar porque é apenas estético e não ajuda ninguém a usar a sala.

### 2. Segunda decisão (fato novo: 8 reservas ficaram sem uso)
- **Papéis trocados:** PO: Francisco · SM: Daniel · Developers: Kaio
- **Ordem revisada do Product Backlog:**
  1. **B · Cancelar reserva** *(subiu para 1º)*
  2. **A · Enviar lembrete**
  3. **C · Personalizar cores**
- **O que mudou e por quê:** Trocamos o topo da fila para priorizar **Cancelar reserva**. O fato novo mostrou 8 salas paradas e bloqueadas no app enquanto outros estudantes procuravam horário e encontravam tudo ocupado; liberar esses horários aumenta o uso real das salas e atende direto à Meta do Produto.

### 3. Demonstração do comportamento escolhido (Cancelar reserva)
1. O estudante acessa *Minhas reservas*, encontra **Sala 1 · hoje 10:00**, toca em **Cancelar reserva** e confirma.
2. O aplicativo exibe **"Reserva cancelada"** e remove a reserva da lista.
3. Na tela de outro estudante que consulta a Sala 1, o horário das **10:00** volta a aparecer como **"livre"**.

---

## Atividade 04 — Scrum Master

### Cenário e papéis iniciais
- **Meta da Sprint:** O estudante cancela uma reserva e o horário volta a ficar livre.
- **Papéis (Atividade 1):** SM: Kaio · PO: Daniel · Developers: Francisco

### 1. Conversa 1 e encaminhamento do impedimento
- **Pergunta 1 — Kaio (SM):** *"O que ficou bloqueado e como isso afeta a Meta da Sprint?"*
  - **Francisco (Dev):** *"Não consigo testar no ambiente de teste se o horário volta a ficar livre."*
  - **Daniel (PO):** *"Sem esse teste não podemos entregar, porque precisamos garantir que outro estudante veja a sala livre."*
- **Pergunta 2 — Kaio (SM):** *"Quem pode resolver, o que vamos fazer e quando conferimos?"*
  - **Francisco (Dev):** *"Só o suporte pode liberar o acesso. Eu mando o pedido agora e conferimos às 14h."*

- **Registro do impedimento:**
  - **Impedimento:** Conta de teste sem acesso ao ambiente de teste.
  - **Efeito sobre a meta:** Impede testar o cancelamento e a liberação do horário.
  - **Ação combinada:** Enviar pedido ao suporte de TI pedindo o restabelecimento do acesso.
  - **Quem aciona / acompanha:** Francisco envia o pedido; Kaio acompanha.
  - **Quando verificar:** Hoje às 14h e amanhã de manhã.

- **Mensagem curta ao suporte:**
  > Assunto: Acesso da conta de teste – app da biblioteca  
  > Olá! A conta de teste do app da biblioteca perdeu o acesso ao ambiente de teste. Precisamos dela para testar o cancelamento de reservas desta Sprint. Vocês conseguem restabelecer o acesso? Obrigado, Francisco (time do app).

### 2. Conversa 2 e plano ajustado (resposta do suporte: "só amanhã de manhã")
- **Papéis trocados:** SM: Francisco · PO: Kaio · Developers: Daniel
- **Francisco (novo SM):** *"O acesso só volta amanhã. O que podemos adiantar hoje e como vamos conferir quando voltar?"*
- **Kaio (novo PO):** *"Quando o estudante cancelar a Sala 1 às 10h, ela deve aparecer livre para outro colega."*
- **Daniel (novo Dev):** *"Hoje desenhamos o fluxo e escrevemos os testes; amanhã entramos com a conta e executamos no ambiente."*

| Fazemos hoje (sem depender do suporte) | Depende do suporte (amanhã) |
| :--- | :--- |
| 1. Desenhar as telas de cancelamento da Sala 1 às 10h | 1. Tentar entrar com a conta de teste no ambiente |
| 2. Escrever os 3 testes (login, cancelamento e consulta de outro estudante) | 2. Cancelar a Sala 1 às 10h e conferir se outro estudante vê como livre |
| 3. Revisar os textos das mensagens com o PO | |

### 3. Fluxo de cancelamento e verificação do impedimento
- **Fluxo simulado (Sala 1 às 10:00):** Estudante toca em *Cancelar reserva* → confirma → app mostra *"Reserva cancelada"* → outro estudante consulta a Sala 1 e vê **10:00 livre**.
- **Como conferir se o acesso voltou:** Amanhã de manhã o Developer tenta fazer login no ambiente de teste com a conta de teste. Se entrar, o impedimento é fechado e o trio executa em seguida os testes de cancelar a Sala 1 às 10h e consultar o horário em outra conta.

---

## Atividade 05 — Time Scrum

### Cenário e Meta da Sprint
- **Cenário:** O app já consulta horários e reserva salas; o acesso aos testes voltou e o cancelamento foi retomado. A **Sala 1 está reservada por Ana às 10h**.
- **Meta da Sprint:** Permitir que Ana cancele sua reserva e que outro estudante consiga ver o horário liberado na consulta.

### 1. Responsabilidades no Time Scrum
- **Product Owner:** Daniel Alves — Explica que Ana espera cancelar sua reserva (ou voltar se desistir) e que outro estudante precisa ver a Sala 1 às 10h livre assim que ela confirmar.
- **Scrum Master:** Kaio Costa — Conduz uma conversa curta para que todos contribuam e percebam como "Minhas reservas" e "Consultar horários" dependem uma da outra.
- **Representante dos Developers:** Francisco Breno — Propõe a sequência do trabalho (definir comportamento → desenhar as telas → conferir o fluxo) e organiza como o trio prototipa e testa em conjunto.

### 2. Plano inicial da Sprint e protótipo das duas telas
| Ação no plano | Quem conduz | Quem pode ajudar |
| :--- | :--- | :--- |
| 1. Definir o comportamento (estado inicial, Confirmar e Voltar) | Daniel (PO) | Kaio e Francisco |
| 2. Desenhar as duas telas ("Minhas reservas" e "Consultar horários") | Francisco (Dev) | Daniel e Kaio |
| 3. Conferir o fluxo entre as duas telas com testes | Kaio (SM) | Francisco e Daniel |

- **Estado inicial das duas telas:**
  - **Minhas reservas (Ana):** Sala 1 · 10:00 aparece como **Ativa**, com o botão *Cancelar reserva* (que abre *Confirmar* e *Voltar*).
  - **Consultar horários (outro estudante):** Sala 1 · 10:00 aparece como **Ocupada**.
- **Comportamento esperado após a escolha de Ana:**
  - Ao escolher **Confirmar**: "Minhas reservas" exibe **Cancelada** e "Consultar horários" exibe **Livre**.
  - Ao escolher **Voltar**: "Minhas reservas" mantém **Ativa** e "Consultar horários" mantém **Ocupada**.

### 3. Inconsistência na 1ª demonstração e plano ajustado
- **Falha reproduzida:** Ana clicou em *Confirmar*; "Minhas reservas" mostrou a reserva como **Cancelada**, mas "Consultar horários" continuou mostrando a Sala 1 às 10h como **Ocupada**.
- **Conversa do Time Scrum:**
  - **Daniel (PO):** explicou que outro estudante vê a sala ocupada mesmo após o cancelamento, impedindo o uso da sala e quebrando a Meta da Sprint.
  - **Kaio (SM):** perguntou o que precisava mudar entre as telas e como o trio poderia se ajudar na correção.
  - **Francisco (Dev):** ajustou o plano para ligar a confirmação do cancelamento à atualização da consulta.
- **Registro do plano ajustado:**
  - **O que vai mudar:** ao clicar em *Confirmar* em "Minhas reservas", atualizar imediatamente a Sala 1 às 10h para **Livre** em "Consultar horários" (e manter **Ocupada** quando clicar em *Voltar*).
  - **Quem ajuda a corrigir:** Francisco corrige a regra do protótipo com apoio de Daniel na revisão dos textos das duas telas.
  - **Quem confere o resultado:** todo o trio nos dois casos de teste, trocando as funções entre o Caso A e o Caso B.

### 4. Resultados dos testes corrigidos (com troca de funções)
- **Caso A — Confirmar:** *(Ana = Daniel · Outro estudante = Kaio · Aplicativo = Francisco)*
  - Início: reserva de Ana **Ativa** e Sala 1 às 10h **Ocupada**.
  - Resultado obtido: "Minhas reservas" exibiu **Cancelada** e "Consultar horários" exibiu **Livre**. (**PASSOU**)
- **Caso B — Voltar:** *(Ana = Francisco · Outro estudante = Daniel · Aplicativo = Kaio)*
  - Início: reserva de Ana **Ativa** e Sala 1 às 10h **Ocupada**.
  - Resultado obtido: "Minhas reservas" manteve **Ativa** e "Consultar horários" manteve **Ocupada**. (**PASSOU**)
