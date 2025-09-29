dist:

setup:
	cmake -B build

dist:
	make -C build

format:
	find include -type f | xargs -I {} clang-format -i {}
	find src -type f | xargs -I {} clang-format -i {}
