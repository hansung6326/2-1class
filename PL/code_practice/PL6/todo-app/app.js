(function () {
  "use strict";

  var STORAGE_KEY = "daily-todo-items";

  var form = document.getElementById("add-form");
  var input = document.getElementById("task-input");
  var deadlineInput = document.getElementById("deadline-input");
  var listPending = document.getElementById("todo-list-pending");
  var listDone = document.getElementById("todo-list-done");
  var board = document.getElementById("todo-board");
  var globalEmpty = document.getElementById("global-empty-hint");
  var emptyPending = document.getElementById("empty-pending");
  var emptyDone = document.getElementById("empty-done");

  var editingId = null;

  function normalizeTodo(t) {
    var d = t.deadline;
    var deadline =
      d && typeof d === "string" && /^\d{4}-\d{2}-\d{2}$/.test(d) ? d : null;
    return {
      id: t.id,
      text: t.text || "",
      done: !!t.done,
      deadline: deadline,
    };
  }

  function loadTodos() {
    try {
      var raw = localStorage.getItem(STORAGE_KEY);
      if (!raw) return [];
      var parsed = JSON.parse(raw);
      if (!Array.isArray(parsed)) return [];
      var out = [];
      for (var i = 0; i < parsed.length; i++) {
        out.push(normalizeTodo(parsed[i]));
      }
      return out;
    } catch (e) {
      return [];
    }
  }

  function saveTodos(todos) {
    localStorage.setItem(STORAGE_KEY, JSON.stringify(todos));
  }

  function nextId(todos) {
    var max = 0;
    for (var i = 0; i < todos.length; i++) {
      if (todos[i].id > max) max = todos[i].id;
    }
    return max + 1;
  }

  function todayYmd() {
    var n = new Date();
    var y = n.getFullYear();
    var m = String(n.getMonth() + 1).padStart(2, "0");
    var d = String(n.getDate()).padStart(2, "0");
    return y + "-" + m + "-" + d;
  }

  function formatDeadlineLabel(iso) {
    var dt = new Date(iso + "T12:00:00");
    if (isNaN(dt.getTime())) return iso;
    return dt.toLocaleDateString("ko-KR", {
      year: "numeric",
      month: "long",
      day: "numeric",
      weekday: "short",
    });
  }

  function isDeadlineOverdue(deadline, done) {
    if (done || !deadline) return false;
    return deadline < todayYmd();
  }

  function updateEmptyMessages(pending, done, total) {
    globalEmpty.classList.toggle("hidden", total > 0);
    emptyPending.classList.toggle("hidden", pending.length > 0);
    emptyDone.classList.toggle("hidden", done.length > 0);
  }

  function closeEdit() {
    editingId = null;
    render(loadTodos());
  }

  function openEdit(id) {
    editingId = id;
    render(loadTodos());
    var inp = board.querySelector(".todo-item.is-editing .todo-edit-text");
    if (inp) {
      inp.focus();
      if (typeof inp.select === "function") inp.select();
    }
  }

  function saveEdit(li) {
    var id = parseInt(li.dataset.id, 10);
    var textInp = li.querySelector(".todo-edit-text");
    var dlInp = li.querySelector(".todo-edit-deadline");
    if (!textInp) return;
    var text = textInp.value.trim();
    if (!text) {
      textInp.focus();
      return;
    }
    var deadlineRaw = dlInp ? dlInp.value.trim() : "";
    var deadline = deadlineRaw || null;

    var todos = loadTodos();
    for (var i = 0; i < todos.length; i++) {
      if (todos[i].id === id) {
        todos[i].text = text;
        todos[i].deadline = deadline;
        break;
      }
    }
    saveTodos(todos);
    editingId = null;
    render(todos);
  }

  function createTodoRow(t) {
    var isEditing = editingId !== null && editingId === t.id;

    var li = document.createElement("li");
    li.className = "todo-item" + (isEditing ? " is-editing" : "");
    li.dataset.id = String(t.id);

    var wrap = document.createElement("div");
    wrap.className = "checkbox-wrap";

    var cb = document.createElement("input");
    cb.type = "checkbox";
    cb.checked = !!t.done;
    if (isEditing) cb.disabled = true;
    cb.setAttribute("aria-label", t.done ? "예정으로 되돌리기" : "완료로 표시");

    var body = document.createElement("div");
    body.className = "todo-body";

    var view = document.createElement("div");
    view.className = "todo-view";

    var span = document.createElement("span");
    span.className = "todo-text" + (t.done ? " done" : "");
    span.textContent = t.text;
    view.appendChild(span);

    if (t.deadline) {
      var dl = document.createElement("span");
      dl.className = "todo-deadline";
      if (isDeadlineOverdue(t.deadline, t.done)) {
        dl.classList.add("overdue");
        dl.textContent =
          "마감: " + formatDeadlineLabel(t.deadline) + " (기한 지남)";
      } else {
        dl.textContent = "마감: " + formatDeadlineLabel(t.deadline);
      }
      view.appendChild(dl);
    }

    var edit = document.createElement("div");
    edit.className = "todo-edit";

    var editText = document.createElement("input");
    editText.type = "text";
    editText.className = "todo-edit-text task-input";
    editText.maxLength = 200;
    editText.setAttribute("aria-label", "할 일 내용 수정");
    editText.value = t.text;

    var dlRow = document.createElement("div");
    dlRow.className = "todo-edit-deadline-row";

    var editDlId = "edit-deadline-" + t.id;
    var editDlLabel = document.createElement("label");
    editDlLabel.className = "todo-edit-deadline-label";
    editDlLabel.setAttribute("for", editDlId);
    editDlLabel.textContent = "마감일";

    var editDl = document.createElement("input");
    editDl.type = "date";
    editDl.id = editDlId;
    editDl.className = "deadline-input todo-edit-deadline";
    editDl.setAttribute("aria-label", "마감일 수정");
    editDl.value = t.deadline || "";

    dlRow.appendChild(editDlLabel);
    dlRow.appendChild(editDl);

    var editBtns = document.createElement("div");
    editBtns.className = "todo-edit-actions";

    var saveBtn = document.createElement("button");
    saveBtn.type = "button";
    saveBtn.className = "btn btn-primary btn-edit-save";
    saveBtn.textContent = "저장";

    var cancelBtn = document.createElement("button");
    cancelBtn.type = "button";
    cancelBtn.className = "btn btn-secondary btn-edit-cancel";
    cancelBtn.textContent = "취소";

    editBtns.appendChild(saveBtn);
    editBtns.appendChild(cancelBtn);

    edit.appendChild(editText);
    edit.appendChild(dlRow);
    edit.appendChild(editBtns);

    body.appendChild(view);
    body.appendChild(edit);

    var actions = document.createElement("div");
    actions.className = "todo-actions";

    var editBtn = document.createElement("button");
    editBtn.type = "button";
    editBtn.className = "btn-edit";
    editBtn.textContent = "수정";

    var del = document.createElement("button");
    del.type = "button";
    del.className = "btn btn-delete";
    del.textContent = "삭제";

    actions.appendChild(editBtn);
    actions.appendChild(del);

    wrap.appendChild(cb);
    li.appendChild(wrap);
    li.appendChild(body);
    li.appendChild(actions);
    return li;
  }

  function render(todos) {
    var pending = [];
    var done = [];
    for (var i = 0; i < todos.length; i++) {
      if (todos[i].done) done.push(todos[i]);
      else pending.push(todos[i]);
    }

    listPending.innerHTML = "";
    listDone.innerHTML = "";

    for (var p = 0; p < pending.length; p++) {
      listPending.appendChild(createTodoRow(pending[p]));
    }
    for (var d = 0; d < done.length; d++) {
      listDone.appendChild(createTodoRow(done[d]));
    }

    updateEmptyMessages(pending, done, todos.length);
  }

  form.addEventListener("submit", function (e) {
    e.preventDefault();
    var text = input.value.trim();
    if (!text) return;

    var deadlineRaw = deadlineInput.value.trim();
    var deadline = deadlineRaw || null;

    var todos = loadTodos();
    todos.push({
      id: nextId(todos),
      text: text,
      done: false,
      deadline: deadline,
    });
    saveTodos(todos);
    editingId = null;
    render(todos);
    input.value = "";
    deadlineInput.value = "";
    input.focus();
  });

  board.addEventListener("change", function (e) {
    if (e.target.type !== "checkbox") return;
    var item = e.target.closest(".todo-item");
    if (!item || item.classList.contains("is-editing")) return;
    var id = parseInt(item.dataset.id, 10);
    var todos = loadTodos();
    for (var i = 0; i < todos.length; i++) {
      if (todos[i].id === id) {
        todos[i].done = e.target.checked;
        break;
      }
    }
    saveTodos(todos);
    render(todos);
  });

  board.addEventListener("click", function (e) {
    if (e.target.closest(".btn-edit-save")) {
      var li = e.target.closest(".todo-item");
      if (li) saveEdit(li);
      return;
    }
    if (e.target.closest(".btn-edit-cancel")) {
      closeEdit();
      return;
    }
    if (e.target.closest(".btn-edit")) {
      var item = e.target.closest(".todo-item");
      if (!item) return;
      openEdit(parseInt(item.dataset.id, 10));
      return;
    }
    if (e.target.closest(".btn-delete")) {
      var delItem = e.target.closest(".todo-item");
      if (!delItem) return;
      var id = parseInt(delItem.dataset.id, 10);
      if (editingId === id) editingId = null;
      var todos = loadTodos().filter(function (t) {
        return t.id !== id;
      });
      saveTodos(todos);
      render(todos);
    }
  });

  board.addEventListener("keydown", function (e) {
    if (e.key !== "Enter" || e.shiftKey) return;
    var textInp = e.target.closest(".todo-edit-text");
    if (!textInp) return;
    e.preventDefault();
    var li = textInp.closest(".todo-item");
    if (li) saveEdit(li);
  });

  document.addEventListener("keydown", function (e) {
    if (e.key !== "Escape" || editingId === null) return;
    closeEdit();
  });

  render(loadTodos());
})();
