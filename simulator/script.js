const DISPLAY_CELL_WIDTH = 5;
const DISPLAY_CELL_HEIGHT = 7;
const DISPLAY_COLUMNS = 8;
const DISPLAY_PIXELS_PER_DOT = 4;
const DISPLAY_CELL_HORIZONTAL_PADDING = 16;

var displayRows = [...document.querySelectorAll(".displayRow")];

displayRows.forEach(function(row) {
    row.width = (DISPLAY_CELL_WIDTH * DISPLAY_COLUMNS * DISPLAY_PIXELS_PER_DOT) + ((DISPLAY_COLUMNS - 1) * DISPLAY_CELL_HORIZONTAL_PADDING);
    row.height = DISPLAY_CELL_HEIGHT * DISPLAY_PIXELS_PER_DOT;
});

function renderDisplayData(data) {
    var rowContexts = displayRows.map((row) => row.getContext("2d"));

    for (var row = 0; row < rowContexts.length; row++) {
        var context = rowContexts[row];

        displayRows[row].width = displayRows[row].width;
        displayRows[row].height = displayRows[row].height;

        for (var column = 0; column < DISPLAY_COLUMNS; column++) {
            for (var cellY = 0; cellY < DISPLAY_CELL_HEIGHT; cellY++) {
                for (var cellX = 0; cellX < DISPLAY_CELL_WIDTH; cellX++) {
                    var cellByte = data[(((row * DISPLAY_COLUMNS) + column) * DISPLAY_CELL_WIDTH) + cellX];

                    context.fillStyle = ((cellByte >> cellY) & 0b1) ? "#00ff00" : "#ffffff22";

                    context.fillRect(
                        (column * DISPLAY_CELL_WIDTH * DISPLAY_PIXELS_PER_DOT) + (column * DISPLAY_CELL_HORIZONTAL_PADDING) + (cellX * DISPLAY_PIXELS_PER_DOT),
                        cellY * DISPLAY_PIXELS_PER_DOT,
                        DISPLAY_PIXELS_PER_DOT - 1,
                        DISPLAY_PIXELS_PER_DOT - 1
                    );
                }
            }
        }
    }

    requestAnimationFrame(function() {
        Module.display_render();
    });
}

Module.onRuntimeInitialized = function() {
    console.log("Runtime initialised");

    Module.display_render();

    document.querySelectorAll("button").forEach(function(button) {
        button.addEventListener("pointerdown", function(event) {
            Module.input_setButtonStatus(Number(button.getAttribute("data-button")));
        });
    });

    document.body.addEventListener("pointerup", function(event) {
        Module.input_setButtonStatus(0);
    });
};