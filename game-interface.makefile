C_PROGRAMS += test/game-interface-window

game-interface-tests: test/game-interface-window

test/game-interface-window: LDLIBS += `pkg-config --libs glfw3`
test/game-interface-window: LDLIBS += -ldl
test/game-interface-window: src/game-interface/window.o
test/game-interface-window: src/game-interface/test/window/window.test.o
test/game-interface-window: src/log/log.o
test/game-interface-window: src/glad/glad.o
test/game-interface-window: src/game-interface/input.o
test/game-interface-window: src/game-interface/init.o

tests: game-interface-tests

depend: game-interface-depend
game-interface-depend:
	cdeps src/game-interface > src/game-interface/depends.makefile

run-tests: run-game-interface-tests
run-game-interface-tests:
