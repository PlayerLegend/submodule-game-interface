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
	sh makedepend.sh src/game-interface/game-interface.makefile

run-tests: run-game-interface-tests
run-game-interface-tests:

# DO NOT DELETE

src/game-interface/time.o: src/glad/glad.h
src/game-interface/input.o: src/game-interface/input.h
src/game-interface/input.o: src/game-interface/window.h src/keyargs/keyargs.h
src/game-interface/input.o: src/vec/vec.h src/vec/vec2.h
src/game-interface/input.o: src/game-interface/button-id.h src/log/log.h
src/game-interface/input.o: src/glad/glad.h
src/game-interface/init.o: src/glad/glad.h src/game-interface/window.h
src/game-interface/init.o: src/keyargs/keyargs.h src/log/log.h
src/game-interface/test/window/window.test.o: src/game-interface/window.h
src/game-interface/test/window/window.test.o: src/keyargs/keyargs.h
src/game-interface/test/window/window.test.o: src/game-interface/init.h
src/game-interface/window.o: src/game-interface/window.h
src/game-interface/window.o: src/keyargs/keyargs.h src/glad/glad.h
src/game-interface/window.o: src/log/log.h src/vec/vec.h src/vec/vec2.h
src/game-interface/window.o: src/game-interface/button-id.h
src/game-interface/window.o: src/game-interface/input.h
