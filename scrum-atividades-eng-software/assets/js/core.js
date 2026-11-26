// Utilitários compartilhados — Scrum na Biblioteca
// Alunos: Daniel Alves, Kaio Costa e Francisco Breno

const $ = (s, r = document) => r.querySelector(s);
const $$ = (s, r = document) => [...r.querySelectorAll(s)];
const sleep = ms => new Promise(res => setTimeout(res, ms));

function openTab(tabId) {
  $$('nav button').forEach(x => x.classList.toggle('active', x.dataset.tab === tabId));
  $$('.panel').forEach(p => p.classList.toggle('active', p.id === tabId));
  window.scrollTo({ top: 0, behavior: 'smooth' });
}

function initNavigation() {
  $$('nav button').forEach(b => b.addEventListener('click', () => openTab(b.dataset.tab)));
  document.addEventListener('click', e => {
    const gotoEl = e.target.closest('[data-goto]');
    if (gotoEl) openTab(gotoEl.dataset.goto);
  });
}

function setupSwitch(id, onChange) {
  const sw = $('#' + id);
  if (!sw) return;
  $$('button', sw).forEach(b => b.addEventListener('click', () => {
    $$('button', sw).forEach(x => x.classList.toggle('on', x === b));
    onChange(b.dataset);
  }));
}

function selectSlot(phone, time) {
  $$('.slot', phone).forEach(s => s.classList.toggle('sel', s.dataset.time === time));
}

function setupSlots(phone, onSelect) {
  $$('.slot', phone).forEach(s => s.addEventListener('click', () => {
    selectSlot(phone, s.dataset.time);
    onSelect(s.dataset.time);
  }));
}

function show(el, cls, html) {
  el.className = 'screen-out' + (cls ? ' ' + cls : '');
  el.innerHTML = html;
}

function createTestSuite({ tests, onUpdate, waitLabel = 'BLOQUEADO' }) {
  function report(testId, got, pass) {
    const card = $(`[data-test="${testId}"]`);
    if (!card) return;
    card.classList.remove('pass', 'fail');
    if (pass === true) card.classList.add('pass');
    if (pass === false) card.classList.add('fail');

    const tag = pass === true ? '<span class="tag ok">PASSOU</span>'
              : pass === false ? '<span class="tag no">FALHOU</span>'
              : `<span class="tag wait">${waitLabel}</span>`;

    const gotEl = $('.got', card);
    const tagSlot = $('.tag-slot', card);
    if (gotEl) gotEl.textContent = got;
    if (tagSlot) tagSlot.innerHTML = tag;

    card.dataset.state = pass === true ? 'pass' : pass === false ? 'fail' : 'block';
    onUpdate();
  }

  function resetTest(testId) {
    const card = $(`[data-test="${testId}"]`);
    if (!card) return;
    card.classList.remove('pass', 'fail');
    delete card.dataset.state;
    const gotEl = $('.got', card);
    const tagSlot = $('.tag-slot', card);
    if (gotEl) gotEl.textContent = '—';
    if (tagSlot) tagSlot.innerHTML = '';
  }

  async function runGroup(groupPrefix, buttonEl, delayMs = 170) {
    if (buttonEl) buttonEl.disabled = true;
    const groupTests = Object.keys(tests).filter(k => k.startsWith(groupPrefix));
    for (const tId of groupTests) {
      await tests[tId]();
      await sleep(delayMs);
    }
    if (buttonEl) buttonEl.disabled = false;
  }

  function bindButtons() {
    $$('.test').forEach(card => {
      const btn = $('.run', card);
      btn.addEventListener('click', async () => {
        btn.disabled = true;
        btn.textContent = '...';
        try {
          await tests[card.dataset.test]();
        } finally {
          btn.disabled = false;
          btn.textContent = 'Testar';
        }
      });
    });

    $$('.run-all-btn[data-group]').forEach(btn => {
      btn.addEventListener('click', () => runGroup(btn.dataset.group, btn));
    });
  }

  return { report, resetTest, runGroup, bindButtons };
}

initNavigation();
