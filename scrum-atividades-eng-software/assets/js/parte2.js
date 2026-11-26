// Scrum na Biblioteca — Parte 2 (Atividades 06 a 12)
// Alunos: Daniel Alves, Kaio Costa e Francisco Breno

const tests = {};

function updateScores() {
  const groups = [
    { prefix: 'ev-', scoreId: 'ev-score', cardId: 'card-status-ev', total: 3, expectedFail: 1 },
    { prefix: 'pb-', scoreId: 'pb-score', cardId: 'card-status-pb', total: 2, expectedFail: 0 },
    { prefix: 'usf-', scoreId: 'usf-score', cardId: null, total: 3, expectedFail: 0 },
    { prefix: 'usl-', scoreId: 'usl-score', cardId: null, total: 4, expectedFail: 1 },
    { prefix: 'us', scoreId: null, cardId: 'card-status-us', total: 7, expectedFail: 1 }
  ];

  groups.forEach(({ prefix, scoreId, cardId, total, expectedFail }) => {
    const executed = $$(`[data-test^="${prefix}"][data-state]`).length;
    const passed = $$(`[data-test^="${prefix}"][data-state="pass"]`).length;
    const failed = $$(`[data-test^="${prefix}"][data-state="fail"]`).length;

    if (scoreId) {
      const scoreEl = $('#' + scoreId);
      if (scoreEl) {
        scoreEl.textContent = (expectedFail && executed === total && failed === expectedFail)
          ? `${passed} / ${total} (1 falha reproduzida)`
          : `${passed} / ${total}`;
      }
    }

    if (cardId) {
      const cardBadge = $('#' + cardId);
      if (cardBadge) {
        if (executed === 0) {
          cardBadge.className = 'tag wait';
          cardBadge.textContent = `0 / ${total}`;
        } else if (passed === total || (expectedFail && passed === total - expectedFail && failed === expectedFail)) {
          cardBadge.className = 'tag ok';
          cardBadge.textContent = `${passed} / ${total} OK`;
        } else {
          cardBadge.className = 'tag no';
          cardBadge.textContent = `${passed} / ${total}`;
        }
      }
    }
  });

  const totalExecuted = $$(`[data-test][data-state]`).length;
  const totalPassed = $$(`[data-test][data-state="pass"]`).length;
  const globalStatus = $('#global-status');
  if (globalStatus) {
    globalStatus.textContent = totalExecuted === 0
      ? '0 de 12 testados'
      : `${totalExecuted} de 12 testados · ${totalPassed} passaram`;
  }
}

const { report, resetTest, runGroup, bindButtons } = createTestSuite({
  tests,
  onUpdate: updateScores,
  waitLabel: 'NÃO EXECUTADO'
});

/* ======================= ATIVIDADES 06 A 10 ======================= */
const ev = {
  versao: 'bug',
  destino: '11:00',
  anaSlot: '10:00',
  slots: { '10:00': 'Ocupado (Ana)', '11:00': 'Livre', '14:00': 'Ocupado (Bruno)' }
};

function syncEvUI() {
  $('#ev-ana-slot').textContent = `Sala 1 · ${ev.anaSlot}`;
  $('#ev-target-lbl').textContent = ev.destino;

  const mapTag = (id, text) => {
    const el = $('#' + id);
    el.textContent = text;
    el.className = text === 'Livre' ? 'tag ok' : 'tag no';
  };
  mapTag('ev-s10', ev.slots['10:00']);
  mapTag('ev-s11', ev.slots['11:00']);
  mapTag('ev-s14', ev.slots['14:00']);
}

function resetEv() {
  ev.anaSlot = '10:00';
  ev.slots = { '10:00': 'Ocupado (Ana)', '11:00': 'Livre', '14:00': 'Ocupado (Bruno)' };
  show($('#ev-ana-out'), '', 'Reserva de Ana às 10:00');
  syncEvUI();
}

function setEvVersion(v) {
  ev.versao = v;
  $$('#ev-switch button').forEach(b => b.classList.toggle('on', b.dataset.v === v));
  resetEv();
}

setupSwitch('ev-switch', d => setEvVersion(d.v));

$('#ev-pick-11').addEventListener('click', () => { ev.destino = '11:00'; syncEvUI(); });
$('#ev-pick-14').addEventListener('click', () => { ev.destino = '14:00'; syncEvUI(); });
$('#ev-reset').addEventListener('click', resetEv);

function runReagendar() {
  if (ev.slots[ev.destino] !== 'Livre') {
    show($('#ev-ana-out'), 'no', `Destino ocupado (${ev.destino})<br><small>Reserva original mantida às ${ev.anaSlot}.</small>`);
    return { ok: false };
  }
  const antigo = ev.anaSlot;
  ev.anaSlot = ev.destino;
  if (ev.versao === 'ok') ev.slots[antigo] = 'Livre';
  ev.slots[ev.destino] = 'Ocupado (Ana)';
  syncEvUI();
  show($('#ev-ana-out'), 'ok', `Reserva alterada para ${ev.destino}`);
  return { ok: true };
}

$('#ev-reagendar').addEventListener('click', runReagendar);

tests['ev-t1'] = async () => {
  setEvVersion('bug');
  ev.destino = '11:00';
  syncEvUI();
  runReagendar();
  const passou = ev.anaSlot === '11:00' && ev.slots['10:00'] === 'Livre';
  report('ev-t1', `Ana: ${ev.anaSlot} | Consulta 10h: ${ev.slots['10:00']}`, passou);
};

tests['ev-t2'] = async () => {
  setEvVersion('ok');
  ev.destino = '11:00';
  syncEvUI();
  runReagendar();
  const ok = ev.anaSlot === '11:00' && ev.slots['10:00'] === 'Livre' && ev.slots['11:00'] === 'Ocupado (Ana)' && ev.slots['14:00'] === 'Ocupado (Bruno)';
  report('ev-t2', `Ana: 11:00 | 10h: ${ev.slots['10:00']}, 11h: Ocupado, 14h: Ocupado`, ok);
};

tests['ev-t3'] = async () => {
  setEvVersion('ok');
  ev.destino = '14:00';
  syncEvUI();
  const r = runReagendar();
  const ok = !r.ok && ev.anaSlot === '10:00' && ev.slots['10:00'] === 'Ocupado (Ana)' && ev.slots['11:00'] === 'Livre' && ev.slots['14:00'] === 'Ocupado (Bruno)';
  report('ev-t3', `Ana mantida em ${ev.anaSlot} · aviso de ocupado exibido`, ok);
};

/* ======================= ATIVIDADE 11 ======================= */
function resetPb() {
  show($('#pb-out'), '', 'Escolha um destino para a reserva de 10/11');
}

function tryPb(destino) {
  if (destino === '11:00') {
    const msg = 'Confirmação: Sala 1 · 10/11 · 11:00';
    show($('#pb-out'), 'ok', `Reserva alterada!<br><small>${msg}</small>`);
    return { ok: true, msg };
  }
  const msg = 'Horário 14:00 ocupado. Mantida: Sala 1 · 10/11 · 10:00';
  show($('#pb-out'), 'no', `Indisponível<br><small>${msg}</small>`);
  return { ok: false, msg };
}

$('#pb-try-11').addEventListener('click', () => tryPb('11:00'));
$('#pb-try-14').addEventListener('click', () => tryPb('14:00'));
$('#pb-reset').addEventListener('click', resetPb);

tests['pb-t1'] = async () => {
  resetPb();
  const r = tryPb('11:00');
  report('pb-t1', r.msg, r.ok && r.msg.includes('10/11') && !r.msg.includes('12/11'));
};

tests['pb-t2'] = async () => {
  resetPb();
  const r = tryPb('14:00');
  report('pb-t2', r.msg, !r.ok && r.msg.includes('10/11 · 10:00'));
};

/* ======================= ATIVIDADE 12 — FILTRO (PB-F) ======================= */
const fState = {
  date: '10/11',
  onlyFree: false,
  data: {
    '10/11': [
      { hora: '10:00', livre: false },
      { hora: '11:00', livre: true },
      { hora: '14:00', livre: false }
    ],
    '12/11': [
      { hora: '10:00', livre: false },
      { hora: '11:00', livre: false },
      { hora: '14:00', livre: false }
    ]
  }
};

function renderFiltro() {
  $('#f-date-lbl').textContent = fState.date;
  $('#f-d10').className = fState.date === '10/11' ? 'phone-btn' : 'phone-btn muted';
  $('#f-d12').className = fState.date === '12/11' ? 'phone-btn' : 'phone-btn muted';
  $('#f-toggle').textContent = fState.onlyFree ? 'Ver lista completa' : 'Mostrar só livres';

  const items = fState.data[fState.date].filter(s => !fState.onlyFree || s.livre);
  const listEl = $('#f-list');
  const outEl = $('#f-out');

  if (items.length === 0) {
    listEl.innerHTML = '';
    show(outEl, 'no', 'Nenhum horário livre nesta data');
    return 'Nenhum horário livre nesta data';
  }

  listEl.innerHTML = items.map(s =>
    `<div>${s.hora} <span class="tag ${s.livre ? 'ok' : 'no'}">${s.livre ? 'Livre' : 'Ocupado'}</span></div>`
  ).join('');

  const resumo = items.map(s => `${s.hora} (${s.livre ? 'Livre' : 'Ocupado'})`).join(', ');
  show(outEl, fState.onlyFree ? 'ok' : '', fState.onlyFree ? 'Filtro ativo: só livres' : 'Visualização completa');
  return resumo;
}

$('#f-d10').addEventListener('click', () => { fState.date = '10/11'; renderFiltro(); });
$('#f-d12').addEventListener('click', () => { fState.date = '12/11'; renderFiltro(); });
$('#f-toggle').addEventListener('click', () => { fState.onlyFree = !fState.onlyFree; renderFiltro(); });
renderFiltro();

tests['usf-t1'] = async () => {
  fState.date = '10/11';
  fState.onlyFree = true;
  const r = renderFiltro();
  report('usf-t1', r, r === '11:00 (Livre)');
};

tests['usf-t2'] = async () => {
  fState.date = '12/11';
  fState.onlyFree = true;
  const r = renderFiltro();
  report('usf-t2', r, r === 'Nenhum horário livre nesta data');
};

tests['usf-t3'] = async () => {
  fState.date = '10/11';
  fState.onlyFree = false;
  const r = renderFiltro();
  report('usf-t3', r, r.includes('10:00') && r.includes('11:00') && r.includes('14:00'));
};

/* ======================= ATIVIDADE 12 — LEMBRETE (PB-L) ======================= */
const lState = { versao: 'bug' };

function setLVersion(v) {
  lState.versao = v;
  $$('#l-switch button').forEach(b => b.classList.toggle('on', b.dataset.v === v));
  show($('#l-out'), '', 'Clique em um cenário acima');
}

setupSwitch('l-switch', d => setLVersion(d.v));

function runLembrete(cenario) {
  let msg = '';
  let cls = 'ok';

  if (cenario === 'reag') {
    if (lState.versao === 'bug') {
      cls = 'no';
      msg = 'Envio às 09:30 (antiga 10h) E às 10:30 (nova 11h)';
    } else {
      msg = 'Nada às 09:30 · 1 envio às 10:30 (Sala 1, 10/11, 11:00)';
    }
  } else if (cenario === 'lim30') {
    msg = '1 envio às 10:30 (regra 30 min · 11:00) · nada às 11:30';
  } else if (cenario === 'lim29') {
    msg = '1 envio imediato às 10:31 (11:00) · nada às 11:30';
  }

  show($('#l-out'), cls, msg);
  return msg;
}

$('#l-sc-reag').addEventListener('click', () => runLembrete('reag'));
$('#l-sc-lim30').addEventListener('click', () => runLembrete('lim30'));
$('#l-sc-lim29').addEventListener('click', () => runLembrete('lim29'));

tests['usl-t1'] = async () => {
  setLVersion('bug');
  const r = runLembrete('reag');
  report('usl-t1', r, !r.includes('09:30'));
};

tests['usl-t2'] = async () => {
  setLVersion('ok');
  const r = runLembrete('reag');
  report('usl-t2', r, r.includes('Nada às 09:30') && r.includes('10:30'));
};

tests['usl-t3'] = async () => {
  setLVersion('ok');
  const r = runLembrete('lim30');
  report('usl-t3', r, r.includes('10:30') && r.includes('nada às 11:30'));
};

tests['usl-t4'] = async () => {
  setLVersion('ok');
  const r = runLembrete('lim29');
  report('usl-t4', r, r.includes('imediato às 10:31') && r.includes('nada às 11:30'));
};

/* ======================= EXECUTOR GLOBAL ======================= */
bindButtons();

$('#global-run-all').addEventListener('click', async () => {
  const btn = $('#global-run-all');
  btn.disabled = true;
  btn.textContent = 'Testando...';
  try {
    await runGroup('ev');
    await runGroup('pb');
    await runGroup('usf');
    await runGroup('usl');
  } finally {
    btn.disabled = false;
    btn.textContent = '▶ Executar todos (12)';
  }
});

$('#global-reset-all').addEventListener('click', () => {
  Object.keys(tests).forEach(resetTest);
  setEvVersion('bug');
  resetPb();
  fState.date = '10/11';
  fState.onlyFree = false;
  renderFiltro();
  setLVersion('bug');
  updateScores();
});

updateScores();
