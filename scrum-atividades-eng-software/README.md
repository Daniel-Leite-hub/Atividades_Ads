# Scrum na Biblioteca — Atividades Práticas (01 a 12)

> Projeto da disciplina de **Engenharia de Software** que reúne a resolução completa das atividades práticas em trio sobre o framework **Scrum**, acompanhadas de protótipos interativos de tela e testes clicáveis executados diretamente no navegador.

---

## Sobre o trabalho

Ao longo das 12 atividades, o trio evoluiu continuamente o mesmo produto fictício: um **aplicativo de reserva de salas de estudo da biblioteca** (com foco na **Sala 1**).

Em vez de entregar apenas respostas estáticas em texto, cada etapa foi acompanhada de simulações interativas em **HTML, CSS e JavaScript puro** que permitem testar, na prática, o comportamento combinado pelo time — reproduzindo falhas de primeiras versões, ajustes feitos na Reunião Diária, regras de negócio, critérios de aceitação e verificações da Definição de Pronto (DoD).

---

## Integrantes do grupo

| Integrante | Papel nas simulações |
| :--- | :--- |
| **Daniel Alves** | Rodízio entre Product Owner, Scrum Master e Developers |
| **Kaio Costa** | Rodízio entre Scrum Master, Product Owner e Developers |
| **Francisco Breno** | Rodízio entre Developers, Product Owner e Scrum Master |

---

## Atividades incluídas

### Parte 1 — Fundamentos e Papéis ([`index.html`](index.html) · 14 testes)

| Atividade | Tema | Principais entregas |
| :--- | :--- | :--- |
| **01** | Introdução ao Scrum | Consulta da Sala 1 em duas rodadas (falha da tela em branco → mensagem clara) e pilares/valores |
| **02** | Papéis, Artefatos e Eventos | Product Backlog, Sprint Backlog ajustado na Diária, reserva livre/ocupada, Revisão e Retrospectiva |
| **03** | Product Owner | Priorização por valor (5 atrasos vs. 8 reservas sem uso) e fluxo de cancelamento |
| **04** | Scrum Master | Impedimento de acesso ao ambiente de teste, mensagem ao suporte e plano adaptado |
| **05** | Time Scrum | Plano inicial e ajustado após inconsistência entre *"Minhas reservas"* e *"Consultar horários"* |

### Parte 2 — Eventos, Backlog e User Stories ([`pages/atividades-06-a-12.html`](pages/atividades-06-a-12.html) · 12 testes)

| Atividade | Tema | Principais entregas |
| :--- | :--- | :--- |
| **06 a 10** | Eventos do Scrum na prática | Ordem 06 → 07 → 09 → 08 → 10: linha do tempo, Planejamento (5 períodos), Daily com ajuste, Review e Retrospectiva |
| **11** | Product Backlog na prática | Encaminhamento dos relatos `R1`–`R5`, fichas `PB-01`, `PB-F`, `PB-L` e `PB-02`, Sprint Backlog e confirmação com duas datas |
| **12** | User Stories e DoD | Fichas com Três Cs e INVEST, regra dos 30 min no lembrete, 8 cenários *Dado/Quando/Então* e decisão de Pronto |

---

## Estrutura do projeto

```text
scrum-atividades-eng-software/
├── index.html                        # Página principal — Atividades 01 a 05
├── pages/
│   └── atividades-06-a-12.html       # Página secundária — Atividades 06 a 12
├── assets/
│   ├── css/
│   │   └── style.css                 # Layout editorial compartilhado
│   └── js/
│       ├── core.js                   # Utilitários compartilhados (abas, switches e testes)
│       ├── parte1.js                 # Protótipos e 14 testes (Atividades 01 a 05)
│       └── parte2.js                 # Protótipos e 12 testes (Atividades 06 a 12)
├── docs/
│   ├── respostas-01-a-05.md          # Respostas escritas — Atividades 01 a 05
│   └── respostas-06-a-12.md          # Respostas escritas — Atividades 06 a 12
└── README.md                         # Apresentação do trabalho e integrantes
```

---

## Como visualizar

O projeto não utiliza dependências externas nem etapa de build:

1. Abra [`index.html`](index.html) em qualquer navegador moderno para acessar as **Atividades 01 a 05**.
2. Use o link no menu lateral (**Atividades 06–12 →**) ou abra [`pages/atividades-06-a-12.html`](pages/atividades-06-a-12.html) para navegar pela segunda parte.
3. Clique em **Testar** em cada caso ou em **Executar todos** no topo da página para rodar as simulações automaticamente.

## Site publicado

Acesse o site: [Scrum na Biblioteca](https://daniel-leite-hub.github.io/Atividades_Ads/).
