all: build test

.PHONY: build test run rm
build:
	cmake -B build/
	cmake --build build/

test:
	cmake --build build/ --target test

run:
	./build/tui

rm:
	cmake --build build/ --target clean
