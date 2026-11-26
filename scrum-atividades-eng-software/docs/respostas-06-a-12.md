# Respostas das Atividades de Scrum (06 a 12)

**Disciplina:** Engenharia de Software  
**Alunos:** Daniel Alves · Kaio Costa · Francisco Breno  
**Produto:** Aplicativo de reserva de salas de estudo da biblioteca (Sala 1)

---

## Parte I — Eventos do Scrum na prática (Atividades 06 a 10)

> **Ordem seguida:** 06 → 07 → 09 → 08 → 10 (a Daily vem antes da Review para usar o plano ajustado na demonstração).  
> **Dados usados em todos os testes (Sala 1):** `10h` Reservada por Ana · `11h` Livre · `14h` Reservada por Bruno.

### 06 · Cerimônias do Scrum
- **Papéis iniciais:** Product Owner: Daniel Alves · Scrum Master: Kaio Costa · Developers (rep.): Francisco Breno. *(Nas etapas com troca temporária, retomamos esses papéis ao encerrar.)*
- **Linha do tempo da Sprint (Segunda a Sexta-feira) e perguntas:**
  1. **Segunda (início) — Planejamento da Sprint:** *"O que queremos permitir que Ana faça até sexta-feira e o que cabe na nossa capacidade de 5 períodos?"*
  2. **Segunda a Sexta (diária; encenada na quarta) — Reunião Diária (Daily Scrum):** *"O que avançou, o que travou nas duas telas e o que precisamos ajustar hoje para preservar a meta?"*
  3. **Sexta (perto do fim) — Review da Sprint:** *"O reagendamento atendeu à necessidade de Ana e o que o estudante sugere melhorar na sequência?"*
  4. **Sexta (encerramento) — Retrospectiva da Sprint:** *"Por que demoramos a notar a falha entre as telas e o que vamos mudar na forma de trabalhar?"*

### 07 · Planejamento da Sprint (capacidade: 5 períodos)
- **Meta da Sprint:** Permitir que Ana troque sua reserva para um horário livre, preservando a reserva original caso o destino já esteja ocupado.
- **Itens selecionados (total: 4 de 5 períodos):**
  1. **A. Reagendamento básico (3 períodos)** — obrigatório para cumprir a meta; os outros itens dependem dele.
  2. **B. Confirmação detalhada (1 período)** — cabe na capacidade restante e evita dúvida após a troca.
  - **Ficou para depois:** **C. Histórico de alterações (2 períodos)** — A + B + C somaria 6 períodos (passaria do limite de 5) e depende de A estar pronto.
- **Plano de trabalho inicial:** desenhar as telas *"Minhas reservas"* (com botão `Reagendar`) e *"Consultar horários"*, definir a regra de troca/bloqueio e executar os testes de troca para horário livre (`11h`) e ocupado (`14h`). O Scrum Master conferiu que o plano cabe nos 5 períodos e cobre os dois testes.

### 09 · Reunião Diária (Quarta) e ajuste do plano
- **Falha descoberta na quarta:** ao trocar `10h → 11h`, *"Minhas reservas"* mostrou `11h`, mas *"Consultar horários"* manteve `10h` como **ocupado**. A correção e novos testes acrescentam **+2 períodos** ao item A (sobe de 3 para **5 períodos**).
- **Encenação da Daily (2 min):** *Troca temporária:* Daniel e Francisco como Developers; Kaio como observador.
  - *O que avançou?* A troca já muda o horário na tela de Ana.
  - *O que a falha impede?* A consulta não libera o horário antigo (`10h`), quebrando a coerência entre as telas.
  - *Que ação agora?* Corrigir a atualização de *"Consultar horários"* e repetir os dois testes. *(Kaio anotou: conversa terminou com próxima ação clara.)*
- **Renegociação pós-Daily (PO Daniel + Dev Francisco):** com o item A exigindo **5 períodos**, **adiamos o item B (Confirmação detalhada)** e mantivemos **C** fora da Sprint para caber no limite de 5 períodos. Primeiro corrigimos a atualização das telas; Francisco e Daniel conferem os dois testes.
- **Resultados dos testes corrigidos:**
  - **Trocar `10h → 11h` (livre):** *Minhas reservas* passou para `11h`; *Consultar horários* mostrou `10h Livre`, `11h Ocupado`, `14h Ocupado`. (**PASSOU**)
  - **Trocar `10h → 14h` (ocupado):** *Minhas reservas* manteve `10h` com aviso de destino ocupado; *Consultar horários* manteve `10h Ocupado`, `11h Livre`, `14h Ocupado`. (**PASSOU**)

### 08 · Review da Sprint
- **Resultado demonstrado e pendências:** Reagendamento básico concluído (os 2 testes passaram). Ficaram pendentes os itens B e C.
- **Feedback do estudante (Kaio encenando temporariamente):** *"Vi que a reserva mudou, mas tive de abrir Minhas reservas de novo para conferir qual ficou sendo o horário. Um lembrete também me ajudaria a não esquecer."*
- **Pergunta do PO (Daniel):** *"Em que momento apareceu a dúvida e por que o lembrete ajuda?"* → **Resposta:** *"Logo após confirmar só apareceu 'Reserva alterada', sem mostrar o horário novo; depois de trocar, às vezes esqueço o horário."* Francisco apontou que a confirmação já tem aviso base (só ajustar o texto no item B), enquanto o lembrete exige trabalho novo.
- **Decisão sobre o Product Backlog:** colocar **Confirmação detalhada (PB-01)** em 1º entre os pendentes (já existe no backlog e foi atualizado com o feedback) e incluir **Lembrete de reserva** no Product Backlog logo a seguir; o **Histórico** continua depois.

### 10 · Retrospectiva da Sprint
- **Dificuldade:** construir a 1ª versão sem conferir juntas as duas telas desde o início.
- **Prática a preservar:** conferir *"Minhas reservas"* e *"Consultar horários"* lado a lado com os dados fixos (`10h`, `11h`, `14h`).
- **Classificação dos assuntos:**
  - *"Mostrar a sala e o novo horário na confirmação de reagendamento"* → **Review da Sprint / Product Backlog** (mudança de produto).
  - *"Conferir as telas em conjunto antes da demonstração"* → **Retrospectiva da Sprint** (forma de trabalhar do time).
- **Melhoria verificável:** *"Vamos **conferir todas as telas afetadas em dupla antes da primeira demonstração**. **Francisco (Developers)** vai combinar a execução até **o início da implementação no próximo Planejamento**. Vamos verificar se ajudou olhando **o registro dos testes conjuntos antes da Daily, sem falhas de sincronização na demonstração**."*

---

## Parte II — Product Backlog na prática (Atividade 11)

**Papéis:** PO: Daniel Alves · SM: Kaio Costa · Developers: Francisco Breno

### 1. Decisão para cada relato (`R1` a `R5`)
| Relato | Problema / Necessidade | Encaminhamento | Justificativa e dúvida/hipótese |
| :--- | :--- | :--- | :--- |
| **R1 Ana** | Após reagendar, não viu sala nem horário confirmados. | Refinar item existente **`PB-01`** | `PB-01` já trata da confirmação. *Hipótese:* verificar se também precisa da data (confirmada no passo 5). |
| **R2 Bruno** | Esqueceu o novo horário após trocar; biblioteca confirmou envio 30 min antes. | Propor item novo **`PB-L`** | Funcionalidade nova de notificação. *Dúvida:* como agir se a troca ocorrer faltando menos de 30 min. |
| **R3 Júlia** | Excesso de horários ocupados dificulta achar vaga na sala. | Propor item novo **`PB-F`** | Nova opção na consulta preservando a lista completa. *Dúvida:* como voltar à lista completa e o que exibir se tudo estiver ocupado. |
| **R4 Equipe** | Conferir telas em dupla antes de demonstrar evita divergência. | Melhoria da forma de trabalhar | Não é recurso de usuário; acompanhar na **Retrospectiva / Definição de Pronto**. |
| **R5 Coordenação** | "A tela precisa ficar mais moderna." | Pedir esclarecimento | *Pergunta:* "Qual dificuldade os estudantes ou a coordenação observaram na tela atual e o que precisa mudar para melhorar o uso?" |

### 2. Product Backlog ordenado e fichas
- **Meta do Produto:** Tornar a consulta e o acompanhamento de reservas mais claros para que o estudante encontre vagas e não perca sua sala.
- **Ordem justificada:** `1º PB-01` (1 período, resolve dúvida imediata após reagendar sem bloqueios) → `2º PB-F` (1 período, agiliza achar vagas livres) → `3º PB-L` (2 períodos, ainda tem dúvida sobre `< 30 min`) → `4º PB-02` (2 períodos, menor urgência).

1. **PB-01 — Exibir sala, data e novo horário na confirmação de reagendamento (1 período)** *(atualizado no passo 5)*
   - **Origem e valor:** R1 (Ana); evita abrir *Minhas reservas* só para conferir qual reserva mudou.
   - **Requisito funcional:** Após reagendar com sucesso, o aplicativo deve exibir a **sala, a data e o novo horário** da reserva alterada.
   - **Critério 1 (atualizado):** Com reservas da Sala 1 às 10h em `10/11` e `12/11`, ao trocar apenas `10/11` para `11h`, a confirmação mostra **`Sala 1 · 10/11 · 11h`**.
   - **Critério 2:** Se o destino (`14h`) estiver ocupado, informa indisponibilidade e mantém `Sala 1 · 10/11 · 10h`, sem mensagem de sucesso.
2. **PB-F — Filtrar horários livres na consulta de salas (1 período)**
   - **Origem e valor:** R3 (Júlia); acelera encontrar salas disponíveis preservando a visão completa.
   - **Requisito funcional:** Na consulta de sala e data, permitir alternar entre visualização completa e "somente horários livres".
   - **Critério 1:** Em `10/11` (`10h` ocupado, `11h` livre, `14h` ocupado), ao ativar o filtro mostra apenas `11h` e permite voltar à lista completa.
   - **Critério 2:** Em `12/11` (todos ocupados), ao ativar o filtro exibe mensagem indicando que não há horários livres na data.
   - **Hipótese:** botão alterna "Mostrar só livres" e "Ver lista completa" (a confirmar na prototipação).
3. **PB-L — Enviar lembrete antes do horário vigente da reserva (2 períodos)**
   - **Origem e valor:** R2 (Bruno); reduz esquecimento após reagendar.
   - **Requisito funcional:** Enviar notificação 30 min antes do horário vigente de uma reserva ativa com sala, data e horário.
   - **Critério 1:** Se a reserva for reagendada com antecedência, envia uma notificação 30 min antes do novo horário e não envia do horário antigo.
   - **Critério 2:** Se a reserva for cancelada antes do envio, nenhuma notificação é enviada.
   - **Dúvida:** o que fazer se a troca acontecer faltando menos de 30 min para o novo horário.
4. **PB-02 — Mostrar ao estudante o histórico de reagendamentos (2 períodos)**
   - *Mantido com a descrição inicial; será detalhado depois.*

### 3. Sprint Backlog (capacidade: 3 períodos) e passo 5
- **Meta da Sprint:** Eliminar a dúvida de quem acabou de reagendar e facilitar a busca de horários livres.
- **Selecionados:** `PB-01` (1 período) + `PB-F` (1 período) = **2 períodos** (cabe nos 3 períodos; deixamos `PB-L` para outra Sprint pela dúvida aberta sobre `< 30 min`, e `PB-02` por menor prioridade).
- **Plano dos Developers:**
  - `PB-01`: ajustar confirmação para buscar sala, **data (incluída no passo 5)** e novo horário da reserva alterada → produz mensagem identificando a reserva exata.
  - `PB-01`: simular troca com reservas em `10/11` e `12/11` e tentativa para `14h` ocupado → produz registro da confirmação correta e preservação da reserva.
  - `PB-F`: criar opção "Mostrar só livres" / "Ver todos" e aviso de dia sem vagas → produz lista filtrada em `10/11` e mensagem em `12/11`.
- **Teste simulado:** Ana troca Sala 1 de `10/11` das `10h` para `11h` (tendo também `12/11` às `10h`). Esperado: `Sala 1 · 10/11 · 11h`. Obtido: `Confirmação: Sala 1 · 10/11 · 11h`. (**PASSOU**)
- **Registro do passo 5:** Como `PB-01` já estava na Sprint e manteve **1 período**, atualizamos o requisito, o Critério 1 e o teste no Sprint Backlog mantendo a Meta da Sprint intacta.

---

## Parte III — User Stories no desenvolvimento de software (Atividade 12)

### 1. Fichas das duas histórias (com INVEST e adaptação)

#### Ficha PB-F — Filtrar horários livres na consulta
- **Narrativa:** Como estudante que consulta uma sala, quero filtrar apenas os horários livres, para encontrar uma vaga sem percorrer horários ocupados.
- **Conversa (Relato de Júlia):**
  - *Pergunta 1 (como voltar):* botão alterna entre "Mostrar só livres" e "Ver lista completa".
  - *Pergunta 2 (tudo ocupado):* exibe mensagem *"Nenhum horário livre nesta data"*.
- **Critérios de aceitação:**
  - **CA-F01:** Na consulta de data com vagas, ativar o filtro exibe apenas os horários livres e oferece retorno imediato à lista completa.
  - **CA-F02:** Na consulta de data sem vagas, ativar o filtro exibe *"Nenhum horário livre nesta data"*.
- **INVEST:** **I** independente de lembrete/histórico · **N** rótulo do botão é negociável · **V** reduz tempo de busca · **E** 1 período · **S** cabe em 1 Sprint · **T** testável em `10/11` e `12/11`. *Melhoria feita após INVEST:* saímos de texto vago ("melhorar consulta") para perfil específico e comportamento explícito quando não há vagas.

#### Ficha PB-L — Enviar lembrete da reserva vigente *(atualizada na Etapa 3)*
- **Narrativa:** Como estudante com reserva ativa, quero receber um lembrete antes do horário vigente, para não perder a sala após reagendar.
- **Conversa e recorte (Relato de Bruno):**
  - *Fora do escopo:* envio por e-mail, preferências individuais e alterações após o lembrete já enviado.
  - *Dependência:* serviço de notificação ligado ao registro vigente da reserva. *Dúvida real:* atraso de entrega/fuso horário.
- **Nova regra (Etapa 3):** mantendo o mesmo ID `PB-L`, se o reagendamento ocorrer faltando **menos de 30 minutos** e ainda não houve envio, o lembrete sai **imediatamente** (1 vez); se faltarem **exatamente 30 minutos**, vale a regra de envio aos 30 min.
- **Critérios de aceitação (atualizados):**
  - **CA-L01:** Reserva ativa sem alteração gera 1 notificação 30 min antes com sala, data e horário.
  - **CA-L02 (atualizado):** Reagendamento sem envio prévio cancela o envio do horário antigo e gera **apenas 1** notificação para o novo horário (aos 30 min se `>= 30 min`, ou imediatamente se `< 30 min`).
  - **CA-L03:** Cancelamento antes do envio não gera nenhuma notificação.
- **INVEST pós-nova regra:** decidimos **manter na mesma história PB-L** porque trata apenas de um limite de tempo do mesmo único lembrete, sem criar nova funcionalidade nem exigir recorte separado.

### 2. Trecho do Sprint Backlog para PB-L (Etapa 3)
- **Meta da Sprint:** Garantir um único lembrete correto do horário vigente, inclusive em trocas com até 30 minutos de antecedência.
- **Tarefas ligadas a PB-L:**
  1. Implementar regra de envio aos 30 min quando faltar `= 30 min` e envio imediato quando faltar `< 30 min` → *Resultado:* notificação única enviada no momento certo com dados do novo horário.
  2. Cancelar agendamento anterior ao confirmar reagendamento ou cancelamento → *Resultado:* nenhum envio disparado no horário antigo (ex.: `9h30` ou `11h30`).
  3. Executar cenários de limite (`CT-L04`, `CT-L05`) e repetir reagendamento (`CT-L02`) e cancelamento (`CT-L03`) → *Resultado:* registro das notificações observadas no horário antigo e no novo.

### 3. Os 8 cenários (Dado · Quando · Então) e tabela de execução da Etapa 4
1. **CT-F01 · PB-F · CA-F01 — Consulta filtrada em 10/11:** Dado Sala 1 em `10/11` (`10h` ocupado, `11h` livre, `14h` ocupado), Quando ativar "Mostrar só livres", Então lista exibe apenas `11h`. → *Etapa 4:* **Passou**.
2. **CT-F02 · PB-F · CA-F02 — Consulta filtrada em 12/11:** Dado Sala 1 em `12/11` (`10h`, `11h`, `14h` ocupados), Quando ativar "Mostrar só livres", Então exibe *"Nenhum horário livre nesta data"*. → *Etapa 4:* **Passou**.
3. **CT-F03 · PB-F · CA-F01 — Retorno à lista completa:** Dado filtro ligado em `10/11`, Quando clicar "Ver lista completa", Então exibe `10h`, `11h` e `14h`. → *Etapa 4:* **Passou**.
   *(Regressão do bloqueio de reserva em horário ocupado também **Passou**.)*
4. **CT-L01 · PB-L · CA-L01 — Reserva sem alteração:** Dado Bruno com Sala 1 em `10/11` às `10h` sem envio prévio, Quando chegar `9h30`, Então sai 1 notificação (`Sala 1, 10/11, 10h`). → *Etapa 4:* **Passou**.
5. **CT-L02 · PB-L · CA-L02 — Reserva reagendada (8h50):** Dado Bruno em `10/11` às `10h` (`11h` livre), Quando às `8h50` confirmar troca para `11h`, Então **não** sai aviso às `9h30` e sai 1 notificação às `10h30` (`Sala 1, 10/11, 11h`). → *Etapa 4:* **Falhou** (enviou às `9h30` para a reserva antiga **e** às `10h30` para a nova — violou `CA-L02`).
6. **CT-L03 · PB-L · CA-L03 — Reserva cancelada (8h50):** Dado Bruno em `10/11` às `10h`, Quando às `8h50` cancelar a reserva, Então nenhuma notificação sai às `9h30`. → *Etapa 4:* **Não executado** (não testado na rodada).
7. **CT-L04 · PB-L · CA-L02 — Limite exato 30 min:** Dado Bruno em `10/11` às `12h` sem envio prévio (`11h` livre), Quando às `10h30` confirmar troca para `11h`, Então sai 1 notificação às `10h30` (regra 30 min, `Sala 1, 10/11, 11h`) e **não** sai nada às `11h30`. → *Etapa 4:* **Não executado**.
8. **CT-L05 · PB-L · CA-L02 — Limite 29 min:** Dado Bruno em `10/11` às `12h` sem envio prévio (`11h` livre), Quando às `10h31` confirmar troca para `11h`, Então sai 1 notificação **imediatamente às `10h31`** (`Sala 1, 10/11, 11h`) e **não** sai nada às `11h30`. → *Etapa 4:* **Não executado**.

### 4. Decisão sobre o Pronto (DoD) e teste de regressão
- **PB-F (Filtro de horários): NÃO PRONTO.** Todos os testes passaram e estão registrados, mas falta a **revisão/conferência por outro integrante** exigida pela DoD. *Ação pendente:* outro membro revisar e registrar a conferência.
- **PB-L (Lembrete): NÃO PRONTO.** Outro integrante revisou a mudança, mas `CT-L02` falhou (envio duplicado às `9h30`) e `CT-L03`, `CT-L04` e `CT-L05` não foram executados.
  - *Ações para conclusão:* corrigir cancelamento do lembrete anterior ao reagendar, executar toda a sequência (`CT-L01` a `CT-L05`) e rodar **teste de regressão em PB-01** (conferir se a confirmação de reagendamento continua exibindo sala, data e horário corretos, pois o envio do lembrete mexe no mesmo evento de troca).
