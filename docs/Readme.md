# TUI library

```uml
                    ------------------
                    | TerminalDriver |
                    ------------------
                    | +initialize()  |
                    | +readInput()   |
                    | +writeOutput() |
                    ------------------
                            ▲
                            |
                    -----------------
                    |     Screen    |
                    -----------------
                    | +render()     |
                    | +update()     |
                    -----------------
                          ▲
                          |
              ----------------------------------
              |            EventLoop           |
              ----------------------------------
              | +start()                       |
              | +registerWidget(widget: Widget)|
              | +handleInput()                 |
              | +updateScreen()                |
              ----------------------------------
                          |
               -----------------------------
               |          Widget           |
               -----------------------------
               | +render(screen: Screen)   |
               | +handleInput(event: Event)|
               -----------------------------
```

Explanation:

- TerminalDriver: This class handles the communication with the terminal,
including initialization, reading input, and writing output. It encapsulates
the low-level terminal interactions.
- Screen: This class represents the terminal screen. It is responsible for
rendering the content on the screen and updating it as needed. The render()
method displays the current state of the screen, and update() method modifies
the screen's content.
- EventLoop: This class manages the event loop, which handles user input and
screen updates. It starts the event loop, registers widgets, listens for user
input, and triggers appropriate actions based on the input received.
- Widget: This class represents a UI widget. It provides methods like render()
to display the widget on the screen and handleInput() to handle user input
events specific to the widget.

The relationships in the diagram are as follows:

- TerminalDriver has a dependency on Screen to write output to the terminal
screen and read input from it.
- Screen has a composition relationship with Widget to render and update the
widgets on the screen.
- EventLoop has a dependency on Widget to register and manage the widgets
within the event loop.
- EventLoop has a dependency on Screen to update the screen based on user input
and widget interactions.
