// Utilitários compartilhados — Scrum na Biblioteca
// Alunos: Daniel Alves, Kaio Costa e Francisco Breno

const $ = (s, r = document) => r.querySelector(s);
const $$ = (s, r = document) => [...r.querySelectorAll(s)];
const sleep = ms => new Promise(res => setTimeout(res, ms));

function openTab(tabId) {
  let activeBtn = null;
  $$('nav button').forEach(x => {
    const isActive = x.dataset.tab === tabId;
    x.classList.toggle('active', isActive);
    if (isActive) activeBtn = x;
  });
  $$('.panel').forEach(p => p.classList.toggle('active', p.id === tabId));
  if (activeBtn && window.matchMedia('(max-width: 920px)').matches) {
    activeBtn.scrollIntoView({ behavior: 'smooth', inline: 'center', block: 'nearest' });
  }
  window.scrollTo({ top: 0, behavior: 'smooth' });
}

function updateProgressBar(executed, total) {
  const fill = $('#global-progress');
  if (!fill) return;
  const pct = total > 0 ? Math.min(100, Math.round((executed / total) * 100)) : 0;
  fill.style.width = `${pct}%`;
}

function initNavigation() {
  $$('nav button').forEach(b => b.addEventListener('click', () => openTab(b.dataset.tab)));
  document.addEventListener('click', e => {
    const gotoEl = e.target.closest('[data-goto]');
    if (gotoEl) openTab(gotoEl.dataset.goto);
  });
  document.addEventListener('keydown', e => {
    if (e.key !== 'Enter' && e.key !== ' ') return;
    const gotoEl = e.target.closest('[data-goto]');
    if (gotoEl && gotoEl.tagName !== 'BUTTON' && gotoEl.tagName !== 'A') {
      e.preventDefault();
      openTab(gotoEl.dataset.goto);
    }
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
