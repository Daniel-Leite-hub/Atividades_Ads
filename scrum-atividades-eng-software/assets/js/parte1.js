// Scrum na Biblioteca — Parte 1 (Atividades 01 a 05)
// Alunos: Daniel Alves, Kaio Costa e Francisco Breno

const tests = {};

function updateScores() {
  const groups = [
    { id: 'a1', total: 4 },
    { id: 'a2', total: 2 },
    { id: 'a3', total: 2 },
    { id: 'a4', total: 3 },
    { id: 'a5', total: 3 }
  ];

  let totalExecuted = 0;
  let totalPassed = 0;

  groups.forEach(({ id, total }) => {
    const executed = $$(`[data-test^="${id}-"][data-state]`).length;
    const passed = $$(`[data-test^="${id}-"][data-state="pass"]`).length;
    const blocked = $$(`[data-test^="${id}-"][data-state="block"]`).length;
    const failed = $$(`[data-test^="${id}-"][data-state="fail"]`).length;

    totalExecuted += executed;
    totalPassed += passed;

    const scoreEl = $(`#${id}-score`);
    if (scoreEl) {
      if (id === 'a1' && executed === total && failed === 1) {
        scoreEl.textContent = `${passed} / ${total} (1 falha esperada)`;
      } else if (id === 'a5' && executed === total && failed === 1) {
        scoreEl.textContent = `${passed} / ${total} (1 falha reproduzida)`;
      } else if (id === 'a4' && blocked > 0) {
        scoreEl.textContent = `${passed} / ${total} (${blocked} bloqueados)`;
      } else {
        scoreEl.textContent = `${passed} / ${total}`;
      }
    }

    const cardBadge = $(`#card-status-${id}`);
    if (cardBadge) {
      if (executed === 0) {
        cardBadge.className = 'tag wait';
        cardBadge.textContent = `0 / ${total}`;
      } else if (passed === total) {
        cardBadge.className = 'tag ok';
        cardBadge.textContent = `${passed} / ${total} OK`;
      } else if (id === 'a1' && passed === 3 && failed === 1) {
        cardBadge.className = 'tag ok';
        cardBadge.textContent = '3 / 4 OK';
      } else if (id === 'a5' && passed === 2 && failed === 1) {
        cardBadge.className = 'tag ok';
        cardBadge.textContent = '2 / 3 OK';
      } else if (blocked > 0) {
        cardBadge.className = 'tag wait';
        cardBadge.textContent = `${blocked} bloqueados`;
      } else {
        cardBadge.className = 'tag no';
        cardBadge.textContent = `${passed} / ${total}`;
      }
    }
  });

  const globalStatus = $('#global-status');
  if (globalStatus) {
    globalStatus.textContent = totalExecuted === 0
      ? '0 de 14 testados'
      : `${totalExecuted} de 14 testados · ${totalPassed} passaram`;
  }
}

const { report, resetTest, runGroup, bindButtons } = createTestSuite({
  tests,
  onUpdate: updateScores,
  waitLabel: 'BLOQUEADO'
});

/* ======================= ATIVIDADE 01 ======================= */
const a1 = { round: 1, time: '09:00', phone: $('#atv1 .phone'), out: $('#a1-out') };
const SALA1 = { '09:00': 'livre', '10:00': 'ocupada', '11:00': 'livre' };

setupSlots(a1.phone, t => { a1.time = t; show(a1.out, '', 'Toque em Consultar'); });
setupSwitch('a1-switch', d => { a1.round = +d.r; show(a1.out, '', 'Toque em Consultar'); });

function consultar(time, round) {
  if (SALA1[time] === 'livre') {
    show(a1.out, 'ok', 'Livre');
    return 'Livre';
  }
  if (round === 1) {
    show(a1.out, 'blank', '&nbsp;');
    return '';
  }
  show(a1.out, 'no', 'Ocupado — escolha outro horário');
  return 'Ocupado — escolha outro horário';
}

$('#a1-go').addEventListener('click', () => consultar(a1.time, a1.round));
$('#a1-reset').addEventListener('click', () => {
  selectSlot(a1.phone, '09:00');
  a1.time = '09:00';
  show(a1.out, '', 'Escolha um horário e consulte');
});

function runA1(round, time) {
  a1.round = round;
  a1.time = time;
  $$('#a1-switch button').forEach(b => b.classList.toggle('on', +b.dataset.r === round));
  selectSlot(a1.phone, time);
  return consultar(time, round);
}

tests['a1-t1'] = async () => {
  const r = runA1(1, '09:00');
  report('a1-t1', `"${r}"`, r === 'Livre');
};

tests['a1-t2'] = async () => {
  const r = runA1(1, '10:00');
  report('a1-t2', r ? `"${r}"` : 'Resposta em branco (colega achou que travou)', r.includes('Ocupado'));
};

tests['a1-t3'] = async () => {
  const r = runA1(2, '11:00');
  report('a1-t3', `"${r}"`, r === 'Livre');
};

tests['a1-t4'] = async () => {
  const r = runA1(2, '10:00');
  report('a1-t4', `"${r}"`, r.includes('Ocupado'));
};

/* ======================= ATIVIDADE 02 ======================= */
const a2 = { time: '09:00', phone: $('#atv2 .phone'), out: $('#a2-out'), reservas: {} };

setupSlots(a2.phone, t => {
  a2.time = t;
  show(a2.out, '', 'Toque em Confirmar reserva');
});

function syncA2Slots() {
  const tag09 = $('#a2-tag-09');
  if (!tag09) return;
  if (a2.reservas['09:00']) {
    tag09.className = 'tag wait';
    tag09.textContent = 'reservada';
  } else {
    tag09.className = 'tag ok';
    tag09.textContent = 'livre';
  }
}

function resetA2() {
  a2.reservas = {};
  a2.time = '09:00';
  selectSlot(a2.phone, '09:00');
  syncA2Slots();
  show(a2.out, '', 'Escolha um horário');
}

$('#a2-reset').addEventListener('click', resetA2);

function reservar(time) {
  const ocupado = time === '10:00' || a2.reservas[time];
  if (ocupado) {
    show(a2.out, 'no', `Horário ocupado<br><small>Sala 1 já reservada às ${time}.</small>`);
    return { ok: false, msg: 'Horário ocupado (não confirmou)' };
  }
  a2.reservas[time] = true;
  syncA2Slots();
  show(a2.out, 'ok', `Reserva confirmada<br><small>Sala 1 · ${time}</small>`);
  return { ok: true, msg: `Reserva confirmada — Sala 1 às ${time}` };
}

$('#a2-go').addEventListener('click', () => reservar(a2.time));

tests['a2-ta'] = async () => {
  resetA2();
  selectSlot(a2.phone, '09:00');
  const r = reservar('09:00');
  report('a2-ta', r.msg, r.ok);
};

tests['a2-tb'] = async () => {
  selectSlot(a2.phone, '10:00');
  const antes = Object.keys(a2.reservas).length;
  const r = reservar('10:00');
  const criou = Object.keys(a2.reservas).length !== antes;
  report('a2-tb', r.msg, !r.ok && !criou);
};

/* ======================= ATIVIDADE 03 ======================= */
const decisoes = {
  1: {
    who: 'PO: Daniel · SM: Kaio · Dev: Francisco',
    itens: [
      ['A · Enviar lembrete', '5 estudantes chegaram atrasados por esquecer o horário.', 'ok', 'Esta semana'],
      ['B · Cancelar reserva', 'Útil, mas ainda sem registro de salas ociosas.', 'wait', 'Depois'],
      ['C · Personalizar cores', 'Não resolve atrasos nem faltas.', 'wait', 'Depois']
    ],
    why: 'O lembrete vem primeiro porque resolve os 5 atrasos da semana e o app já envia notificações. Personalizar cores pode esperar porque é só visual e não ajuda ninguém a usar a sala.'
  },
  2: {
    who: 'PO: Francisco · SM: Daniel · Dev: Kaio',
    itens: [
      ['B · Cancelar reserva', 'Fato novo: 8 reservas ficaram sem uso e travaram horários.', 'ok', 'Esta semana', true],
      ['A · Enviar lembrete', 'Continua importante para os 5 atrasos.', 'wait', 'Próxima'],
      ['C · Personalizar cores', 'Continua sem impacto no uso das salas.', 'wait', 'Depois']
    ],
    why: 'O cancelamento subiu para 1º lugar por causa do fato novo: 8 reservas ficaram sem uso enquanto outros estudantes encontravam tudo ocupado. Liberar esses horários faz as salas serem realmente usadas, cumprindo a Meta do Produto.'
  }
};

function renderA3(s) {
  const d = decisoes[s];
  $('#a3-who').textContent = d.who;
  $('#a3-list').innerHTML = d.itens.map(([t, sub, c, lbl, moved]) =>
    `<li class="${moved ? 'moved' : ''}"><div><b>${t}</b><small>${sub}</small></div><span class="tag ${c}">${lbl}</span></li>`).join('');
  $('#a3-why').textContent = d.why;
}

setupSwitch('a3-switch', d => renderA3(d.s));
renderA3(1);

const a3 = { reservada: true };

function resetA3() {
  a3.reservada = true;
  $('#a3-card').style.display = '';
  show($('#a3-out'), '', '—');
  const p = $('#a3-peer');
  p.className = 'tag no';
  p.textContent = 'ocupada';
}

function confirmarCancelamento() {
  $('#a3-modal').classList.remove('show');
  a3.reservada = false;
  $('#a3-card').style.display = 'none';
  show($('#a3-out'), 'ok', 'Reserva cancelada<br><small>Sala 1 às 10:00 liberada.</small>');
  const p = $('#a3-peer');
  p.className = 'tag ok';
  p.textContent = 'livre';
}

$('#a3-cancel').addEventListener('click', () => $('#a3-modal').classList.add('show'));
$('#a3-no').addEventListener('click', () => $('#a3-modal').classList.remove('show'));
$('#a3-yes').addEventListener('click', confirmarCancelamento);
$('#a3-reset').addEventListener('click', resetA3);

tests['a3-t1'] = async () => {
  resetA3();
  resetTest('a3-t2');
  $('#a3-modal').classList.add('show');
  await sleep(300);
  confirmarCancelamento();
  report('a3-t1', '"Reserva cancelada"', !a3.reservada);
};

tests['a3-t2'] = async () => {
  if (a3.reservada) {
    report('a3-t2', 'A reserva ainda não foi cancelada (rode C1 antes)', false);
    return;
  }
  const st = $('#a3-peer').textContent;
  report('a3-t2', `Sala 1 · 10:00 está "${st}"`, st === 'livre');
};

/* ======================= ATIVIDADE 04 ======================= */
const a4 = { dia: 'hoje', cancelada: false };
const temAcesso = () => a4.dia === 'amanha';

function syncA4UI() {
  const authTag = $('#a4-auth-tag');
  const slotTag = $('#a4-slot-tag');
  const stateEl = $('#a4-state');

  if (temAcesso()) {
    authTag.className = 'tag ok';
    authTag.textContent = 'Acesso liberado';
    stateEl.textContent = 'resolvido';
  } else {
    authTag.className = 'tag no';
    authTag.textContent = 'Sem acesso';
    stateEl.textContent = 'aberto';
  }

  if (a4.cancelada) {
    slotTag.className = 'tag ok';
    slotTag.textContent = 'livre';
  } else {
    slotTag.className = 'tag no';
    slotTag.textContent = 'ocupada';
  }
}

function resetA4() {
  a4.cancelada = false;
  syncA4UI();
  show($('#a4-out'), '', 'Clique para testar a conta no ambiente');
}

setupSwitch('a4-switch', d => {
  a4.dia = d.d;
  ['a4-t1', 'a4-t2', 'a4-t3'].forEach(resetTest);
  resetA4();
  updateScores();
});

$('#a4-reset').addEventListener('click', resetA4);

$('#a4-try-btn').addEventListener('click', () => {
  if (!temAcesso()) {
    show($('#a4-out'), 'no', 'Sem acesso ao ambiente<br><small>Conta bloqueada aguardando o suporte.</small>');
    return;
  }
  a4.cancelada = true;
  syncA4UI();
  show($('#a4-out'), 'ok', 'Login aceito e reserva cancelada<br><small>Sala 1 às 10:00 voltou para "livre".</small>');
});

tests['a4-t1'] = async () => {
  if (!temAcesso()) return report('a4-t1', 'Conta sem acesso ao ambiente de teste', null);
  syncA4UI();
  show($('#a4-out'), 'ok', 'Login aceito no ambiente de teste');
  report('a4-t1', 'Login aceito', true);
};

tests['a4-t2'] = async () => {
  if (!temAcesso()) return report('a4-t2', 'Bloqueado: falta acesso da conta', null);
  a4.cancelada = true;
  syncA4UI();
  show($('#a4-out'), 'ok', 'Reserva cancelada<br><small>Sala 1 às 10:00 liberada.</small>');
  report('a4-t2', '"Reserva cancelada"', true);
};

tests['a4-t3'] = async () => {
  if (!temAcesso()) return report('a4-t3', 'Bloqueado: falta acesso da conta', null);
  if (!a4.cancelada) return report('a4-t3', 'Rode S2 antes: 10:00 ainda está ocupada', false);
  report('a4-t3', 'Sala 1 · 10:00 aparece como "livre"', true);
};

/* ======================= ATIVIDADE 05 ======================= */
const a5 = { versao: 'bug', ativa: true, salaOcupada: true };

function syncA5UI() {
  const anaTag = $('#a5-ana-tag');
  const startBtn = $('#a5-start-cancel');
  const choiceBox = $('#a5-choice-box');
  const anaOut = $('#a5-ana-out');
  const peerOut = $('#a5-peer-out');

  if (a5.ativa) {
    anaTag.className = 'tag no';
    anaTag.textContent = 'Ativa';
    startBtn.disabled = false;
    show(anaOut, '', 'Reserva de Ana ativa');
  } else {
    anaTag.className = 'tag ok';
    anaTag.textContent = 'Cancelada';
    startBtn.disabled = true;
    choiceBox.style.display = 'none';
    show(anaOut, 'ok', 'Reserva cancelada');
  }

  show(peerOut, a5.salaOcupada ? 'no' : 'ok', a5.salaOcupada ? 'Ocupada' : 'Livre');
}

function resetA5() {
  a5.ativa = true;
  a5.salaOcupada = true;
  $('#a5-choice-box').style.display = 'none';
  syncA5UI();
}

function setA5Version(versao) {
  a5.versao = versao;
  $$('#a5-switch button').forEach(b => b.classList.toggle('on', b.dataset.v === versao));
  resetA5();
}

setupSwitch('a5-switch', d => setA5Version(d.v));

$('#a5-start-cancel').addEventListener('click', () => {
  if (!a5.ativa) return;
  $('#a5-choice-box').style.display = 'block';
});

$('#a5-back-btn').addEventListener('click', () => {
  $('#a5-choice-box').style.display = 'none';
  syncA5UI();
});

$('#a5-confirm-btn').addEventListener('click', () => {
  a5.ativa = false;
  if (a5.versao === 'ok') a5.salaOcupada = false;
  syncA5UI();
});

$('#a5-check-btn').addEventListener('click', () => {
  show($('#a5-peer-out'), a5.salaOcupada ? 'no' : 'ok', a5.salaOcupada ? 'Ocupada' : 'Livre');
});

$('#a5-reset').addEventListener('click', resetA5);

tests['a5-t1'] = async () => {
  setA5Version('bug');
  $('#a5-choice-box').style.display = 'block';
  await sleep(150);
  $('#a5-confirm-btn').click();
  $('#a5-check-btn').click();
  report('a5-t1', `Minhas reservas: ${a5.ativa ? 'Ativa' : 'Cancelada'} | Consulta: ${a5.salaOcupada ? 'Ocupada' : 'Livre'}`, !a5.ativa && !a5.salaOcupada);
};

tests['a5-t2'] = async () => {
  setA5Version('ok');
  $('#a5-choice-box').style.display = 'block';
  await sleep(150);
  $('#a5-confirm-btn').click();
  $('#a5-check-btn').click();
  report('a5-t2', `Minhas reservas: ${a5.ativa ? 'Ativa' : 'Cancelada'} | Consulta: ${a5.salaOcupada ? 'Ocupada' : 'Livre'}`, !a5.ativa && !a5.salaOcupada);
};

tests['a5-t3'] = async () => {
  setA5Version('ok');
  $('#a5-choice-box').style.display = 'block';
  await sleep(150);
  $('#a5-back-btn').click();
  $('#a5-check-btn').click();
  report('a5-t3', `Minhas reservas: ${a5.ativa ? 'Ativa' : 'Cancelada'} | Consulta: ${a5.salaOcupada ? 'Ocupada' : 'Livre'}`, a5.ativa && a5.salaOcupada);
};

/* ======================= EXECUTOR GLOBAL ======================= */
bindButtons();

$('#global-run-all').addEventListener('click', async () => {
  const btn = $('#global-run-all');
  btn.disabled = true;
  btn.textContent = 'Testando...';

  try {
    await runGroup('a1');
    await runGroup('a2');
    await runGroup('a3');

    const amanhaBtn = $('button[data-d="amanha"]', $('#a4-switch'));
    if (amanhaBtn && !amanhaBtn.classList.contains('on')) amanhaBtn.click();
    await runGroup('a4');

    await runGroup('a5');
  } finally {
    btn.disabled = false;
    btn.textContent = '▶ Executar todos (14)';
  }
});

$('#global-reset-all').addEventListener('click', () => {
  Object.keys(tests).forEach(resetTest);
  resetA2();
  resetA3();
  const hojeBtn = $('button[data-d="hoje"]', $('#a4-switch'));
  if (hojeBtn) hojeBtn.click();
  setA5Version('bug');
  updateScores();
});

updateScores();
