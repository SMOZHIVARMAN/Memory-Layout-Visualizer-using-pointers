let state = {
    mode: "single",
    arr: [],
    ptr1: 0,
    ptr2: 0,
    lastAction: ""
};

const baseAddress = 0x1000;
const sizeOfInt = 4;

/* ================= LOAD ARRAY ================= */

function loadArray() {
    const input = document.getElementById("arrayInput").value.trim();
    if (!input) return;

    state.arr = input.split(" ").map(Number);
    state.ptr1 = 0;
    state.ptr2 = state.arr.length - 1;
    state.lastAction = "load";

    render();
}

/* ================= MODE ================= */

function setMode(mode) {
    state.mode = mode;
    state.lastAction = "modeChange";
    render();
}

/* ================= RENDER ================= */

function render() {
    renderMemory();
    renderDetails();
    renderOperations();
    updateEducationalPanels();
}

/* ================= MEMORY ================= */

function renderMemory() {
    const memoryDiv = document.getElementById("memory");
    memoryDiv.innerHTML = "";

    state.arr.forEach((value, index) => {

        const container = document.createElement("div");
        container.className = "block-container";

        const block = document.createElement("div");
        block.className = "block";

        const addr =
            "0x" + (baseAddress + index * sizeOfInt).toString(16);

        if (state.mode === "single" && index === state.ptr1) {
            block.classList.add("pointer1");
        }

        if (state.mode === "dual") {
            if (index === state.ptr1 && index === state.ptr2)
                block.classList.add("both");
            else if (index === state.ptr1)
                block.classList.add("pointer1");
            else if (index === state.ptr2)
                block.classList.add("pointer2");
        }

        block.innerText = value;

        const addressDiv = document.createElement("div");
        addressDiv.className = "address";
        addressDiv.innerText = addr;

        container.appendChild(block);
        container.appendChild(addressDiv);

        memoryDiv.appendChild(container);
    });
}

/* ================= DETAILS ================= */

function renderDetails() {
    const details = document.getElementById("details");

    if (state.mode === "single") {

        const addr =
            "0x" + (baseAddress + state.ptr1 * sizeOfInt).toString(16);

        details.innerHTML = `
            <strong>Pointer Index:</strong> ${state.ptr1}<br>
            <strong>Value:</strong> ${state.arr[state.ptr1]}<br>
            <strong>Address:</strong> ${addr}
        `;
    }

    else if (state.mode === "dual") {

        const addr1 =
            "0x" + (baseAddress + state.ptr1 * sizeOfInt).toString(16);

        const addr2 =
            "0x" + (baseAddress + state.ptr2 * sizeOfInt).toString(16);

        const elementDiff = state.ptr2 - state.ptr1;
        const byteDiff = elementDiff * sizeOfInt;

        details.innerHTML = `
            <strong>Pointer 1:</strong> Index ${state.ptr1} | ${addr1}<br>
            <strong>Pointer 2:</strong> Index ${state.ptr2} | ${addr2}<br>
            <strong>Element Difference:</strong> ${elementDiff}<br>
            <strong>Byte Difference:</strong> ${byteDiff} bytes
        `;
    }

    else if (state.mode === "analysis") {

        const totalBytes = state.arr.length * sizeOfInt;

        details.innerHTML = `
            <strong>Array Size:</strong> ${state.arr.length}<br>
            <strong>Size of int:</strong> ${sizeOfInt} bytes<br>
            <strong>Total Memory:</strong> ${totalBytes} bytes<br>
            Pointer arithmetic: ptr + 1 moves by ${sizeOfInt} bytes
        `;
    }
}

/* ================= OPERATIONS ================= */

function renderOperations() {
    const operations = document.getElementById("operations");
    operations.innerHTML = "";

    if (state.mode === "single") {
        operations.innerHTML = `
            <button onclick="movePtr1Forward()">Move Forward</button>
            <button onclick="movePtr1Backward()">Move Backward</button>
            <button onclick="jumpOffset()">Jump by Offset</button>
            <button onclick="modifyValue()">Modify Value</button>
        `;
    }

    else if (state.mode === "dual") {
        operations.innerHTML = `
            <button onclick="movePtr1Forward()">Move Pointer 1 Forward</button>
            <button onclick="movePtr1Backward()">Move Pointer 1 Backward</button>
            <button onclick="movePtr2Forward()">Move Pointer 2 Forward</button>
            <button onclick="movePtr2Backward()">Move Pointer 2 Backward</button>
            <button onclick="comparePointers()">Compare Pointers</button>
        `;
    }

    else if (state.mode === "analysis") {
        operations.innerHTML = `
            <button onclick="renderDetails()">Refresh Analysis</button>
        `;
    }
}

/* ================= POINTER OPS ================= */

function movePtr1Forward() {
    if (state.ptr1 < state.arr.length - 1) {
        state.ptr1++;
        state.lastAction = "moveForward";
        render();
    }
}

function movePtr1Backward() {
    if (state.ptr1 > 0) {
        state.ptr1--;
        state.lastAction = "moveBackward";
        render();
    }
}

function jumpOffset() {
    const offset = parseInt(prompt("Enter offset:"));
    if (isNaN(offset)) return;

    const newIndex = state.ptr1 + offset;

    if (newIndex >= 0 && newIndex < state.arr.length) {
        state.ptr1 = newIndex;
        state.lastAction = "jump";
        render();
    }
}

function modifyValue() {
    const newVal = prompt("Enter new value:");
    if (newVal !== null && !isNaN(newVal)) {
        state.arr[state.ptr1] = Number(newVal);
        state.lastAction = "modify";
        render();
    }
}

function movePtr2Forward() {
    if (state.ptr2 < state.arr.length - 1) {
        state.ptr2++;
        state.lastAction = "ptr2Forward";
        render();
    }
}

function movePtr2Backward() {
    if (state.ptr2 > 0) {
        state.ptr2--;
        state.lastAction = "ptr2Backward";
        render();
    }
}

function comparePointers() {
    state.lastAction = "compare";
    render();
}

/* ================= EDUCATIONAL ENGINE ================= */
function updateEducationalPanels() {
    const codePanel = document.getElementById("codePanel");
    const explanationPanel = document.getElementById("explanationPanel");

    let code = "";
    let explanation = "";

    switch (state.lastAction) {

        case "moveForward":
            code = `ptr1++;`;
            explanation = `Pointer 1 moved forward by sizeof(int) = ${sizeOfInt} bytes.`;
            break;

        case "moveBackward":
            code = `ptr1--;`;
            explanation = `Pointer 1 moved backward by ${sizeOfInt} bytes.`;
            break;

        case "ptr2Forward":
            code = `ptr2++;`;
            explanation = `Pointer 2 moved forward by sizeof(int) = ${sizeOfInt} bytes.`;
            break;

        case "ptr2Backward":
            code = `ptr2--;`;
            explanation = `Pointer 2 moved backward by ${sizeOfInt} bytes.`;
            break;

        case "jump":
            code = `ptr = ptr + offset;`;
            explanation = `Pointer jumped by multiple positions with boundary validation.`;
            break;

        case "modify":
            code = `*ptr = newValue;`;
            explanation = `Dereferencing pointer to modify value at current memory location.`;
            break;

        case "compare":
            code = `int diff = ptr2 - ptr1;`;
            explanation = `Pointer subtraction returns element difference (not byte difference).`;
            break;

        case "modeChange":
            code = `// Mode changed`;
            explanation = `Pointer mode switched.`;
            break;

        case "load":
            code = `int *ptr = arr;`;
            explanation = `Pointer initialized to base address of array.`;
            break;

        default:
            code = `int *ptr = arr;`;
            explanation = `Pointer initialized to base address of array.`;
    }

    codePanel.textContent = code;
    explanationPanel.textContent = explanation;
}
